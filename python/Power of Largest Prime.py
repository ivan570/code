from math import sqrt, floor


def isprime(n):
    s = floor(sqrt(n))

    if n == 2 or n == 3:
        return True

    if n % 2 == 0 or n < 2 or n % 3 == 0:
        return False

    for i in range(3, s + 1, 2):
        if n % i == 0:
            return False
    return True


def largest(n):
    s = floor(sqrt(n))
    large = 0
    ans = -1
    for i in range(2, s + 1):
        if n % i == 0 and isprime(i):
            large = i
        if n % i == 0:
            k = n / i
            if isprime(k):
                ans = k
                break
    if ans != -1:
        return n % (ans ** 2) == 0
    else:
        if large != 0:
            return n % (large ** 2) == 0
        else:
            return False


for _ in range(int(input())):
    n = int(input())
    if largest(n):
        print("YES")
    else:
        print("NO")
