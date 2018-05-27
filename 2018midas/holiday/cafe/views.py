from django.shortcuts import render

# Create your views here.
from django.shortcuts import redirect
from django.core.exceptions import ObjectDoesNotExist
from django.contrib import messages
from django.views.decorators.csrf import csrf_exempt
import json
from .forms import *

def home(request):
	User.objects.all().delete()
	if request.method == 'POST':
		form = UserForm(request.POST)
		if form.is_valid():
			form.save()
			return redirect('/result')	
		else:
			print("error")
			return render(request, 'login.html', {'form': form})
	else:
		form = UserForm()
		return render(request, 'login.html', {'form': form})

def signup(request):
	if request.method == 'GET':
		return render(request, 'CHSignup.html')
	else :
		mail = request.POST.get('email', False)
		pw = request.POST.get('password', False)
		name = request.POST.get('name', False)
		bdate = request.POST.get('bdate', False)
		pnumber = request.POST.get('pnumber', False)
		isCap = request.POST['divideTeam']
		pname = request.POST.get('pname', False)

		if isCap == "leader":
			isCap = True
		else : isCap = False

		u1 = User(Email = mail, Passwd = pw, Partname = pname, 
					Username = name, Phonenumber = pnumber, Bdate = bdate, isCaptain = isCap)
		try:
			u2 = User.objects.get(Email = mail)
			return render(request, 'CHSignup.html')
		except ObjectDoesNotExist:
			u1.save()
			res = []
			for s in User.objects.all():
				res += [s]
			return render(request, 'test.html', {'res': res})

@csrf_exempt
def MakeOrder(request):
	if request.method == 'GET':
		return render(request, 'CHorder.html')
	if request.method == 'POST':
		return redirect('/')