from django.contrib import admin
from .models import Meal, MealCheck, MealLike, Comment, Food


class MealAdmin(admin.ModelAdmin):
    exclude = ('check', )

admin.site.register(Meal, MealAdmin)
admin.site.register(MealCheck)
admin.site.register(MealLike)
admin.site.register(Comment)
admin.site.register(Food)
