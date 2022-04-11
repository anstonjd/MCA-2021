from django.contrib import admin
from django.urls import path
from .views import index, form_view

urlpatterns = [
    path('', index),
    path('templateform/', form_view),

]
