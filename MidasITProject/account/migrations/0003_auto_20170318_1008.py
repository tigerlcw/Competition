# -*- coding: utf-8 -*-
# Generated by Django 1.10.5 on 2017-03-18 01:08
from __future__ import unicode_literals

import account.models
from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('account', '0002_auto_20170314_1023'),
    ]

    operations = [
        migrations.AddField(
            model_name='user',
            name='age',
            field=models.IntegerField(default=10),
        ),
        migrations.AddField(
            model_name='user',
            name='profile',
            field=models.ImageField(default='defalutProfileImg.jpg', upload_to=account.models.get_upload_path),
        ),
        migrations.AddField(
            model_name='user',
            name='sex',
            field=models.CharField(choices=[('man', 'man'), ('girl', 'girl')], help_text='성별', max_length=10, null=True),
        ),
    ]