# -*- coding: utf-8 -*-
"""
Created on Tue Jun 30 15:32:19 2020

@author: Zmix
"""


def merge(a):
    if len(a)>1:
        print(a)
        left=a[:len(a)//2]
        right=a[len(a)//2:]
        print(left)
        print(right)
        merge(left)
        merge(right)
        i=0
        j=0
        k=i+j
        while i<len(left) and j<len(right):
           if left[i]>right[j]:
            a[k]=right[j]
            j+=1
            k+=1
           else:
            a[k]=left[i]
            i+=1
            k+=1
        if i<len(left):
          while(i<len(left)):
           a[k]=left[i]
           i+=1
           k+=1
        else:
         while(j<len(right)):
            a[k]=right[j]
            j+=1
            k+=1
    else:
        return
a=[14,15,-147,162,147]
merge(a)
print(a)
