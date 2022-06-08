from django.contrib import admin

# Register your models here.
from .models import User
from .models import Coffee
from .models import Dessert
from .models import Tea
from .models import Beverage
from .models import Order

admin.site.register(User),
admin.site.register(Coffee),
admin.site.register(Dessert),
admin.site.register(Tea),
admin.site.register(Beverage),
admin.site.register(Order),