from django.db import models

from account.models import User


class Meal(models.Model):
    date = models.CharField(max_length=20)
    time = models.CharField(max_length=10)
    menu = models.CharField(max_length=100)
    image = models.ImageField(upload_to='meal', default='default.jpg')
    kcal = models.IntegerField(default=100)
    favor = models.IntegerField(default=0)
    check = models.BooleanField(default=False)
    def __str__(self):

        return self.date + '-' + self.time


class MealCheck(models.Model):
    user = models.ForeignKey(User, null=True)
    meal = models.ForeignKey(Meal, null=True)
    meal_date = models.CharField(max_length=100, default="2017-01-01")
    def __str__(self):

        return '{0}, {1}'.format(self.meal, self.user)


class Comment(models.Model):
    user = models.ForeignKey(User, null=True)
    meal = models.ForeignKey(Meal, null=True)
    comment = models.TextField()

    def __str__(self):

        return '{0}, {1}'.format(self.meal, self.user)


class MealLike(models.Model):
    user = models.ForeignKey(User, null=True)
    meal = models.ForeignKey(Meal, null=True)

    def __str__(self):

        return '{0}, {1}'.format(self.meal, self.user)


class HonbabGroup(models.Model):
    user = models.ForeignKey(User, null=True)
    meal = models.ForeignKey(Meal, null=True)
    title = models.CharField(max_length=100)

    def __str__(self):

        return self.title


class Food(models.Model):
    name = models.CharField(max_length=20)
    count = models.IntegerField(default=0)

    def __str__(self):

        return self.name