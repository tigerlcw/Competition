# Generated by Django 2.0.5 on 2018-05-26 07:11

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('cafe', '0004_auto_20180526_1544'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='beverage',
            name='Kind',
        ),
        migrations.RemoveField(
            model_name='coffee',
            name='Kind',
        ),
        migrations.RemoveField(
            model_name='dessert',
            name='Kind',
        ),
        migrations.RemoveField(
            model_name='tea',
            name='Kind',
        ),
    ]
