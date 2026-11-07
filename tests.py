import matplotlib.pyplot as plt
import numpy as np
import math as m
import sys
import time
sys.set_int_max_str_digits(1_000_000)
def dec_to_bin(n):
    b = ""
    while n!=0:
        b=str(n%2)+b
        n//=2
    return b
def bin_to_dec(n):
    d=0
    for i in range(len(n)):
        if int(n[i]):
            d+=2**(len(n)-i-1)
    return d
def make_code2(a):
    b=""
    while a!=1:
        if a%2==0:# and a>1:
            a/=2
            b="*"+b
        else:
            a-=1
            b="+"+b
    return b
def make_code3(a):
    b=""
    while a!=4:
        if a%3==0 and a>9:
            a/=3
            b="3"+b
        elif a%2==0 and a>6:
            a/=2
            b="2"+b
        else:
            a-=1
            b="1"+b
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
def graph(fun, ran):
    xpoints = np.array(ran)
    ypoints = np.array(list(map(fun, ran)))
    plt.plot(xpoints, ypoints)
    plt.show()

for i in range(1, 17):
    print(f"index: {i}, code: {make_code2(i)}")

