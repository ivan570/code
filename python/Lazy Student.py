from fractions import Fraction
from sympy import mod_inverse as mi
from math import factorial
from random import randint


def C(N, R):
    c_ans = 1
    for j in range(R):
        c_ans *= (N - j)
    return c_ans / factorial(R)


T = int(input())
for _ in range(T):
    total, asked, known = map(int, input().split(" "))

    q = C(total, asked)
    p = 0
    for i in range(1, known + 1):
        temp = C(known, i) * C(total - i, asked - i)
        p += temp
        if i == asked:
            break
    ans = Fraction(int(p), int(q))
    p = ans.numerator
    q = ans.denominator
    modulo = mi(q, 1000000007)
    print((p * modulo) % 1000000007)
