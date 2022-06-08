from django.shortcuts import render
from django.http import HttpResponse, HttpResponse
from .models import User
import datetime

def login(request):
    return render(request, 'main/login.html')

def signup(request):
    return render(request, 'main/signup.html')

def useradd(request):
    username = request.POST['username']
    password = request.POST['password']
    name = request.POST['name']
    email = request.POST['email']
    useradd = User(username=username, password=password,name=name, email=email, phone_number=phone_number)
    useradd.set_password(password)
    useradd.save()
    return render(request, 'account/login.html')


def logout(request):
    return HttpResponseRedirect("/")