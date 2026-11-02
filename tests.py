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
    while a!=4:
        if a%2==0 and a>6:
            a/=2
            b="2"+b
        else:
            a-=1
            b="1"+b
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

# m = 0
# a = 0
# code = ""
# for i in range(5, 70): #range(8388608, 16777216)
#     if len(make_code(i)) > m:
#         code = make_code(i)
#         m = len(code)
#         a = i
# print(f"len: {m}, code: {code}, i: {a}")

# for i in range(5,20):
#     code = make_code(i)
#     print(f"len: {code}, code: {code}")

# for i in range(5, 70):
#     print(f"i: {str(i).zfill(2)}, bin: {dec_to_bin(i).zfill(7)}, dec code: {bin_to_dec(make_code(i))}, code: {make_code(i)}")
def a(b):
    return(make_code(b))
# graph(a, range(5, 100_000))
# print(list(map(a, range(5, 1000))))
y3 = []
y2 = []
x = range(5, 100_000)
for i in x:
    y3.append(len(make_code3(i)))
    y2.append(len(make_code2(i)))
plt.plot(x, y2, alpha=1, label = "code2")
plt.plot(x, y3, alpha=0.5, label = "code3")
plt.legend()
plt.show()
# print(i, make_code3(i).zfill(9), make_code(i))
