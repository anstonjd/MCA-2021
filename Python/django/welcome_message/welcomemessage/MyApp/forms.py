from django import forms
from .models import CustomerModel


# class Inputform(forms.Form):
#     First_Name = forms.CharField(label='first name', max_length=200)
#     Middle_Name = forms.CharField(max_length=200)
#     Last_Name = forms.CharField(max_length=200)
#     Reg_Number = forms.IntegerField(help_text="Enter 7 digit register number")
#     password = forms.CharField(widget=forms.PasswordInput())


class CustomerForm(forms.ModelForm):
    class Meta:
        model = CustomerModel
        fields = "__all__"
        widgets = {
            'password': forms.PasswordInput()
        }
