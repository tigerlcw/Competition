from django.shortcuts import render
from .models import Meal, Comment, MealCheck,MealLike
from account.models import User
from django.http import HttpResponseRedirect, HttpResponse
from django.db.models import Count
import os
import random
import string
import json
import datetime, time
import pyexcel
from django.conf import settings
from django.views.generic.edit import FormView
from .forms import ExcelUploadForm
from .models import Meal, Food


def index(request):
    boolean_meals = Meal.objects.filter(check=False)
    meals = Meal.objects.all()

    for meal in boolean_meals.iterator():

        for menu in meal.menu.split(','):
            menu = menu.strip()

            try:
                food = Food.objects.get(name=menu)

            except:
                food = Food(name=menu)

            food.count += 1
            food.save()

        meal.check = True
        meal.save()

    context = {
        'meals': meals
    }

    return render(request, 'main/index.html', context)

def today(request):
    d=datetime.date.today()
    today = str(d.year)+'-'+str(d.month)+'-'+str(d.day)
    print(today)
    meals = Meal.objects.filter(date=today)
    context = {
        'meals': meals
    }

    return render(request, 'main/index.html', context)

def routine_detail(request, pk):
    meal = Meal.objects.get(pk=pk)
    comments = Comment.objects.filter(meal=meal)
    mealcheck = MealCheck.objects.filter(user=request.user, meal=meal)
    meallike = MealLike.objects.filter(user=request.user, meal=meal)
    context = {
        'meal': meal,
        'comments':comments,
        'mealcheck':mealcheck,
        'meallike':meallike
    }
    return render(request, 'main/routine_detail.html', context)

def exercise_timer(request):
    return render(request, 'main/exercise_timer.html')

def chart(request):
    meal_check=MealCheck.objects.values('meal_date').annotate(count=Count('meal_date'))
    meal_rank = Meal.objects.order_by('-favor')
    meal_myrank = MealCheck.objects.filter(user=request.user)
    print (meal_check)

    context = {
    'meal_check':meal_check,
    'meal_rank_1':meal_rank[0],
    'meal_rank_2':meal_rank[1],
    'meal_rank_3':meal_rank[2],
    'meal_myrank':meal_myrank,
    }
    return render(request, 'main/myroutine.html', context)

def comment_add(request, pk):
    meal = Meal.objects.get(pk=pk)
    comment = Comment.objects.create(
                        user=request.user, meal=meal,
                        comment=request.POST['comment'])
    redirectURL= '/meal_detail/'+str(meal.pk)
    return HttpResponseRedirect(redirectURL)

def meal_check(request, pk):
    meal = Meal.objects.get(pk=pk)
    mealcheck = MealCheck.objects.create(
                        user=request.user, meal=meal, meal_date=meal.date)
    redirectURL= '/meal_detail/'+str(meal.pk)
    return HttpResponseRedirect(redirectURL)

def meal_check_not(request, pk):
    meal = Meal.objects.get(pk=pk)
    meallike = MealCheck.objects.filter(
                        user=request.user, meal=meal).delete()
    redirectURL= '/meal_detail/'+str(meal.pk)
    return HttpResponseRedirect(redirectURL)


def meal_like(request, pk):
    meal = Meal.objects.get(pk=pk)
    mealcheck = MealLike.objects.create(
                        user=request.user, meal=meal)
    meal.favor =meal.favor+1
    meal.save()
    redirectURL= '/meal_detail/'+str(meal.pk)
    return HttpResponseRedirect(redirectURL)

def meal_like_not(request, pk):
    meal = Meal.objects.get(pk=pk)
    meal.favor =meal.favor-1
    meal.save()
    meallike = MealLike.objects.filter(
                        user=request.user, meal=meal).delete()
    redirectURL= '/meal_detail/'+str(meal.pk)
    return HttpResponseRedirect(redirectURL)

def search(request):
    meal_menu = Meal.objects.filter(menu__contains=request.GET['search'])
    meal_date = Meal.objects.filter(date__contains=request.GET['search'])
    context = {
        'meal_menu': meal_menu,
        'meal_date':meal_date,
    }
    return render(request, 'main/people.html', context)

def random_string():
    return ''.join(random.choice(string.ascii_lowercase) for _ in range(10))

class ExcelUploadFormView(FormView):
    form_class = ExcelUploadForm
    template_name = 'main/excel.html'
    success_url = './'

    def form_valid(self, form):
        file = self.request.FILES['file']
        extension = file.name.split('.')[-1]
        pyexcel_list = ['xls', 'xlsx', 'csv']
        if extension in pyexcel_list:
            file_name = '{0}.{1}'.format(random_string(), extension)
            file_path = os.path.join(os.path.join(settings.BASE_DIR, 'swp'), file_name)

            with open(file_path, 'wb') as f:

                for chunk in file.chunks():
                    f.write(chunk)

            records = pyexcel.iget_records(file_name=file_path)

            for record in records:
                data = Meal(
                    date=record['date'],
                    time=record['time'],
                    menu=record['menu'],
                    kcal= record['kcal']
                )

                data.save()

            os.remove(file_path)

        return super().form_valid(form)
