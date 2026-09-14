import matplotlib.pyplot as plt
import numpy as np
import math as m
import sys
sys.set_int_max_str_digits(1_000_000)

def make_code(a):
    b=""
    while a!=4:
        if a%2==1 or a==6:
            a-=1
            b="+"+b
        else:
            a/=2
            b="*"+b
    return b
def test_code(b):
    a=4
    for i in b:
        if i=="+":
            a+=1
        elif i=="*":
            a*=2
        else:
            print(f"WTF is {i} doing here??")
    return a
def fib_list(num):
    flist = []
    a = 1
    b = 1
    for i in range(num):
        flist.append(a)
        a ,b = b, a+b
    return flist
def fib(num):
    a = 1
    b = 1
    for i in range(num):
        a ,b = b, a+b
    return (num, m.log2(a))
print(fib(1_000_000))
