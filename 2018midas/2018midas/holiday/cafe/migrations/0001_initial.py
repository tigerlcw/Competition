# Generated by Django 2.0.5 on 2018-05-26 03:45

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='User',
            fields=[
                ('Email', models.CharField(max_length=30, primary_key=True, serialize=False)),
                ('Passwd', models.CharField(max_length=20)),
            ],
        ),
    ]
