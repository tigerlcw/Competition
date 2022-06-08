from django.db import models

# Create your models here.
from django.utils import timezone

class User(models.Model):
	Email = models.CharField(max_length = 30, primary_key = True)
	Passwd = models.CharField(max_length = 20, null = True)
	Partname = models.CharField(max_length = 1, null = True)
	Username = models.CharField(max_length = 10, null = True)
	Phonenumber = models.CharField(max_length = 20, null = True)
	Bdate = models.DateField(blank = True, null = True)
	isCaptain = models.BooleanField(default = False)
	isAdmin = models.IntegerField(default = 0)

class Coffee(models.Model):
	Name = models.CharField(max_length = 20, primary_key = True)
	Price = models.IntegerField(null = True)
	HotorIce = models.CharField(max_length = 1, null = True)

class Dessert(models.Model):
	Name = models.CharField(max_length = 20, primary_key = True)
	Price = models.IntegerField(null = True)

class Tea(models.Model):
	Name = models.CharField(max_length = 20, primary_key = True)
	Price = models.IntegerField(null =True)
	HotorIce = models.CharField(max_length = 1, null = True)

class Beverage(models.Model):
	Name = models.CharField(max_length = 20, primary_key = True)
	Price = models.IntegerField(null = True)
	HotorIce = models.CharField(max_length = 1, null = True)

class Order(models.Model):
	Mail = models.CharField(max_length = 30, null = True)
	Odate = models.DateField(blank = True, null = True)
	Resdate = models.DateField(blank = True, null = True)
	Restime = models.TimeField(blank = True, null = True)
	Price = models.IntegerField(null = True)
	Details = models.CharField(max_length = 200)
	Stats = models.CharField(max_length = 10)