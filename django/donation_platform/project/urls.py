from django.urls import path
from django.conf import settings
from django.conf.urls.static import static

from . import views

app_name = 'project'

urlpatterns = [
    path('', views.index, name='index'),
    path('<int:id>/', views.detail, name="detail")
]
