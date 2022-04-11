from django.http import HttpResponse
from django.shortcuts import render
# from .forms import Inputform

from .forms import CustomerForm


def index(request):
    return HttpResponse("hello welcome to my app")


def form_view(request):
    form = CustomerForm()
    return render(request, "home.html", {'form': form})
