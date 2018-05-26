from django.shortcuts import render

# Create your views here.
from django.shortcuts import redirect
from django.core.exceptions import ObjectDoesNotExist
from django.views.decorators.csrf import csrf_exempt
import datetime
from .forms import *

def home(request):	
	if request.method == 'GET':
		return render(request, 'CHaddMenu.html')

def login(request):
#	Login
	if request.method == 'GET':
		return render(request, 'CHlogin.html')
	else:
		email = request.POST.get('email', False)
		pw = request.POST.get('password', False)
		try:
			u1 = User.objects.get(Email = email)
			if u1.Passwd == pw:
				if u1.isAdmin == 0:
					request.session['isAdmin'] = 0
				else:
					request.session['isAdmin'] = 1
				request.session['isLogin'] = 2
				return render(request, 'CHuserList.html')
			else:
				return redirect('/')
		except ObjectDoesNotExist:
			return render(request, 'CHlogin.html')

def adminUserList(request):
#	User inquiry
	if request.method == 'GET':
		res = []
		for s in User.objects.all():
			res += [s]
		return render(request, 'CHuserList.html', {'res': res})
	else:
		return redirect('/Admin/Signup')

def adminSignup(request):
# Admin Add User
	if request.method == 'GET':
		return render(request, 'CHadminSignup.html')
	else:
		mail = request.POST.get('email', False)
		pw = request.POST.get('password', False)
		name = request.POST.get('name', False)
		bdate = request.POST.get('bdate', False)
		pnumber = request.POST.get('pnumber', False)
		isCap = request.POST['divideTeam']
		pname = request.POST.get('pname', False)
		isAuth = request.POST.get('auth', False)

		if isAuth == "employee" or pname == "employee":
			isAuth = 1
			pname = 'employee'
			isCap = False
			u1 = User(Email = mail, Passwd = pw, Partname = pname, 
					Username = name, Phonenumber = pnumber, Bdate = bdate, isCaptain = isCap, isAdmin = isAuth)			
			try:
				u2 = User.objects.get(Email = mail)
				return render(request, 'CHadminSignup.html')
			except ObjectDoesNotExist:
				u1.save()
				res = []
				for s in User.objects.all():
					res += [s]
				return render(request, 'test.html', {'res': res})
		else:
			isAuth = 0
			u1 = User(Email = mail, Passwd = pw, Partname = pname, 
					Username = name, Phonenumber = pnumber, Bdate = bdate, isCaptain = isCap, isAdmin = isAuth)			
			try:
				u2 = User.objects.get(Email = mail)
				return render(request, 'CHSignup.html')
			except ObjectDoesNotExist:
				u1.save()
				res = []
				for s in User.objects.all():
					res += [s]
				return render(request, 'test.html', {'res': res})

def adminMenuList(request):
	if request.method == 'GET':
		res1 = []
		res2 = []
		res3 = []
		res4 = []
		for s in Coffee.objects.all():
			res1 += [s]
		for s in Tea.objects.all():
			res2 += [s]
		for s in Beverage.objects.all():
			res3 += [s]
		for s in Dessert.objects.all():
			res4 += [s]
		return render(request, 'CHmenuList.html', {'res1': res1, 'res2':res2, 'res3':res3, 'res4': res4})
	else:
		return redirect('/Admin/Addmenu')

def addMenu(request):
	if request.method == 'GET':
		return render(request, 'CHaddMenu.html')
	else:
		Bk = request.POST.get('bigKind', False)
		if Bk == 'dessert':
			name = request.POST.get('name', False)
			price = request.POST.get('price', False)
			new_d = Dessert(Name = name, Price = price)
			try:
				d1 = Dessert.objects.get(Name = name)
				return render(request, 'CHaddMenu.html')
			except ObjectDoesNotExist:
				new_d.save()
		else:
			name = request.POST.get('name', False)
			price = request.POST.get('price', False)
			hOi = request.POST['group1']
			if hOi == 'hot':
				hOi = 'I'
			else:
				hOi = 'H'

			if Bk == 'coffee':
				new_c = Coffee(Name = name, Price = price, HotorIce = hOi)
				try:
					c1 = Coffee.objects.get(Name = name)
					return render(request, 'CHaddMenu.html')
				except ObjectDoesNotExist:	
					new_c.save()
			if Bk == 'tea':
				new_t = Tea(Name = name, Price = price, HotorIce = hOi)
				try:
					t1 = Coffee.objects.get(Name = name)
					return render(request, 'CHaddMenu.html')
				except ObjectDoesNotExist:	
					new_t.save()
			if Bk == 'beverage':
				new_b = Coffee(Name = name, Price = price, HotorIce = hOi)
				try:
					b1 = Coffee.objects.get(Name = name)
					return render(request, 'CHaddMenu.html')
				except ObjectDoesNotExist:	
					new_b.save()							
		res1 = []
		res2 = []
		res3 = []
		res4 = []
		for s in Coffee.objects.all():
			res1 += [s]
		for s in Tea.objects.all():
			res2 += [s]
		for s in Beverage.objects.all():
			res3 += [s]
		for s in Dessert.objects.all():
			res4 += [s]
		return render(request, 'CHmenuList.html', {'res1': res1, 'res2':res2, 'res3':res3, 'res4': res4})

def signup(request):
	# User SignUp
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
					Username = name, Phonenumber = pnumber, Bdate = bdate, isCaptain = isCap, isAdmin = 0)
		try:
			u2 = User.objects.get(Email = mail)
			return render(request, 'CHSignup.html')
		except ObjectDoesNotExist:
			u1.save()
			res = []
			for s in User.objects.all():
				res += [s]
			return render(request, 'test.html', {'res': res})

def Order(request):
	if request.method == 'GET':
		res11 = []
		res12 = []
		res21 = []
		res22 = []
		res31 = []
		res32 = []
		res4 = []
		for s in Coffee.objects.all().filter(HotorIce = 'I'):
			res11 += [s]
		for s in Coffee.objects.all().filter(HotorIce = 'H'):
			res12 += [s]
		for s in Tea.objects.all().filter(HotorIce = 'I'):
			res21 += [s]
		for s in Tea.objects.all().filter(HotorIce = 'H'):
			res22 += [s]
		for s in Beverage.objects.all().filter(HotorIce = 'I'):
			res31 += [s]
		for s in Beverage.objects.all().filter(HotorIce = 'H'):
			res32 += [s]
		for s in Dessert.objects.all():
			res4 += [s]
		return render(request, 'CHorder.html', {'res11': res11, 'res21':res21, 'res31':res31, 'res4': res4
												,'res12': res12, 'res22':res22, 'res32':res32 })
	else:
		str = ""
		temp_name = ""
		total_price = int(0)
		iceCoffeeNum = request.POST.get('iceCoffeeNum', False)
		hotCoffeeNum = request.POST.get('hotCoffeeNum', False)
		iceTeaNum = request.POST.get('iceTeaNum', False)
		hotTeaNum = request.POST.get('hotTeaNum', False)
		iceBeverageNum = request.POST.get('iceBeverageNum', False)
		hotBeverageNum = request.POST.get('hotBeverageNum', False)
		dessertNum = request.POST.get('dessertNum', False)
		temp = int(iceCoffeeNum) + int(hotCoffeeNum) + int(iceTeaNum) + int(hotTeaNum) + int(iceBeverageNum) + int(hotBeverageNum) + int(dessertNum)
	
		if temp == 0:
			return redirect('/Order')
		else:
			if 	iceCoffeeNum != '0':
				iceCoffee = request.POST.get('iceCoffee', False)
				str = str + iceCoffee + iceCoffeeNum + "개 "
				temp_name = Coffee.objects.get(Name = iceCoffee)
				total_price = total_price + int(temp_name.Price) * int(iceCoffeeNum)

			if 	hotCoffeeNum != '0':
				hotCoffee = request.POST.get('hotCoffee', False)
				str = str + hotCoffee + hotCoffeeNum + "개 " 		
				temp_name = Coffee.objects.get(Name = hotCoffee)
				total_price = total_price + int(temp_name.Price) * int(hotCoffeeNum)

			if 	iceTeaNum != '0':
				iceTea = request.POST.get('iceTea', False)
				str = str + iceTea + iceTeaNum + "개 "	
				temp_name = Tea.objects.get(Name = iceTea)
				total_price = total_price + int(temp_name.Price) * int(iceTeaNum)		

			if  hotTeaNum != '0':
				hotTea = request.POST.get('hotTea', False)
				str = str + hotTea + hotTeaNum + "개 "
				temp_name = Tea.objects.get(Name = hotTea)
				total_price = total_price + int(temp_name.Price) * int(hotTeaNum)

			if 	iceBeverageNum != '0':
				iceBeverage = request.POST.get('iceBeverage', False)
				str = str + iceBeverage + iceBeverageNum + "개 "		
				temp_name = Beverage.objects.get(Name = iceBeverage)
				total_price = total_price + int(temp_name.Price) * int(iceBeverageNum)

			if 	hotBeverageNum != '0':
				hotBeverage = request.POST.get('hotBeverage', False)
				str = str + hotBeverage + hotBeverageNum + "개 "											
				temp_name = Beverage.objects.get(Name = hotBeverage)
				total_price = total_price + int(temp_name.Price) * int(hotBeverageNum)

			if 	dessertNum != '0':
				dessert = request.POST.get('dessert', False)
				str = str + dessert + dessertNum + "개 "				
				temp_name = Dessert.objects.get(Name = dessert)
				total_price = total_price + int(temp_name.Price) * int(dessertNum)	

			now_date = datetime.datetime.now()
			odate = now_date.strftime('%Y-%m-%d')
			resdate = request.POST.get('Rdate', False)
			restime = request.POST.get('Rtime', False)
			details = str
			stats = "승인대기"

			mail = 'guysuh123@naver.com'
			Or1 = Order(Mail = mail, Odate = odate, Resdate = resdate,
						Restime = restime, Details = details, Stats = stats)
			Or1.save()
		res = []
		for s in Order.object.all():
			res += [s]

		return render(request, 'test.html', {'res': res})