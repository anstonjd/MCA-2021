from django.db import models


# Create your models here.
class CustomerModel(models.Model):
    Title = models.CharField(max_length=200)
    Description = models.TextField()
    First_Name = models.CharField(max_length=200)
    Middle_Name = models.CharField(max_length=200)
    Last_Name = models.CharField(max_length=200)
    Reg_Number = models.IntegerField(help_text="Enter 7 digit register number")
    password = models.CharField(max_length=200)
    Last_modified = models.DateTimeField(auto_now_add=True)
    img = models.ImageField(upload_to="images/")

    def __str__(self):
        return self.Title


