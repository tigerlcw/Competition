# -*- coding: utf-8 -*-
# Generated by Django 1.10.5 on 2017-03-19 07:18
from __future__ import unicode_literals

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('myroutine', '0002_auto_20170319_1618'),
    ]

    operations = [
        migrations.RenameField(
            model_name='calender',
            old_name='routine_id',
            new_name='id',
        ),
    ]
