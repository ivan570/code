from math import floor, sqrt


def isprime(num):
    if num == 2 or num == 3:
        return True
    elif num < 2 or num % 2 == 0 or num % 3 == 0:
        return False
    for i in range(3, floor(sqrt(num)) + 1, 2):
        if num % i == 0:
            return False
    return True


for _ in range(int(input())):
    x = int(input())
    for i in reversed(range(x)):
        t = x - i
        if isprime(i) and isprime(t):
            print(t, i)
            break
