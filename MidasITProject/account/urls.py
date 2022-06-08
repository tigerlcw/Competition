from django.conf.urls import include, url
from . import views
from django.contrib.auth import views as auth_views  # 이 줄 추가.

urlpatterns = [
    url(
        r'^login/',
        auth_views.login,
        name='login',
        kwargs={
            'template_name': 'main/login.html'
        }
    ),
    url(
        r'^logout/',
        auth_views.logout,
        name='logout',
    ),
]
