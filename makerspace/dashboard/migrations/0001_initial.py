# Generated by Django 3.2.3 on 2021-07-19 09:45

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Patient',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.CharField(max_length=100)),
                ('spo2', models.IntegerField()),
                ('temp', models.IntegerField()),
                ('pulse', models.IntegerField()),
            ],
        ),
    ]
