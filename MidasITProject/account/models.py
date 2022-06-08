from django.contrib.auth.models import AbstractBaseUser, PermissionsMixin, UserManager
from django.db import models
from django.utils import timezone

def get_upload_path(instance, filename):
    currently = time.strftime("%y%m%d%H%M%S")
    return os.path.join(
      "profile" , "{}_{}.jpg".format(currently, instance.username)
    )
class User(AbstractBaseUser, PermissionsMixin):
    objects = UserManager()
    username = models.CharField(max_length=50, unique=True)
    name = models.CharField(max_length=50)
    email = models.CharField(max_length = 40)
    is_active = models.BooleanField(default=True)
    is_staff= models.BooleanField(default=True)
    date_joined =models.BooleanField(default=True)
    SEX_CHOICES = (
        ("man", "man"),
        ("girl", "girl"),
    )
    sex = models.CharField(max_length=10, help_text="성별", choices=SEX_CHOICES, null=True)
    age = models.IntegerField(default=10)
    profile = models.ImageField(upload_to="profile", default="defalutProfileImg.jpg")
    USERNAME_FIELD = 'username'
    REQUIRED_FIELDS = ['name', 'email']
    follow = models.ManyToManyField("self", related_name = 'follows', symmetrical=False)

    def __str__(self):
        return '%s' % self.name
    def get_full_name(self):
        return self.name

    def get_short_name(self):
        return self.name
