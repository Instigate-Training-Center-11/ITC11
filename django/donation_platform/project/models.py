from django.db import models

# Create your models here.


class Project(models.Model):
    title = models.CharField(max_length=255)
    description = models.CharField(max_length=255, default='')
    content = models.TextField(default='')

    def __str__(self):
        return self.title
