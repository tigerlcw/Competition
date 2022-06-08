from django.forms import ModelForm
from .models import *

class UserForm(ModelForm):
	class Meta:
		model = User
		fields = ['Email', 'Passwd', 'Partname', 'Username', 
					'Phonenumber', 'Bdate', 'isCaptain']

class CoffeeForm(ModelForm):
	class Meta:
		model = Coffee
		fields = ['Name', 'Price', 'HotorIce']

class DessertForm(ModelForm):
	class Meta:
		model = Dessert
		fields = ['Name', 'Price']

class TeaForm(ModelForm):
	class Meta:
		model = Tea
		fields = ['Name', 'Price', 'HotorIce']

class BeverageForm(ModelForm):
	class Meta:
		model = Beverage
		fields = ['Name', 'Price']

class OrderForm(ModelForm):
	class Meta:
		model = Order
		fields = ['Email', 'Odate', 'Price', 'Details', 'stats']