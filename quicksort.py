# -*- coding: utf-8 -*-
"""
Created on Tue Jun 30 16:18:39 2020

@author: Zmix
"""



def swap(a, b):
    #print(a,b)
    a=a+b
    b=a-b
    #a=a-b
    print(a,b)
def quicksort(x):
    if len(x) == 1 or len(x) == 0:
        return x
    else:
        pivot = x[0]
        i = 0
        for j in range(len(x)-1):
            if x[j+1] < pivot:
                x[j+1],x[i+1] = x[i+1], x[j+1]
                i += 1
        x[0],x[i] = x[i],x[0]
        first_part = quicksort(x[:i])
        second_part = quicksort(x[i+1:])
        first_part.append(x[i])
        return first_part + second_part
        
alist = [54,26,93,17,77,31,44,55,20]
alist=quicksort(alist)
print(alist)
def main():
    print("Hello")
def binarySearch(a,key):
    left=0
    right=len(a)-1
    while left < right:
        middle = (left + right ) // 2
        if key == a[middle]:
            return middle
        elif key < a[middle]:
            right = middle - 1
        else:
            left = middle + 1
    return -1
def binaryRec(a,key,left,right):
    middle=(left+right)//2
    if key < a[middle]:
        return binaryRec(a, key, left, middle-1 )
    if key > a[middle]:
        return binaryRec(a, key, middle+1, right)
    if key == a[middle]:
        return middle
    return -1
def linearSearch(a,key):
    for i in range(len(a)):
        if a[i]==key:
            return i
    return -1
if(__name__=='main'):
    main()