from django.shortcuts import render, get_list_or_404, get_object_or_404
from django.template import loader
from django.http import HttpResponse, Http404

from .models import Project
# Create your views here.


def index(request):
    projects = get_list_or_404(Project)
    template = loader.get_template('index.html')
    context = {
        'projects': projects,
    }
    return HttpResponse(template.render(context, request))


def detail(request, id):
    project = get_object_or_404(Project, pk=id)
    template = loader.get_template('detail.html')
    return HttpResponse(template.render({'project': project}, request))
