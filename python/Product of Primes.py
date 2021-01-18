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


MOD = (10 ** 9) + 7


def final(l, r):
    ans = 1
    for i in range(l, r + 1):
        if isprime(i):
            ans = ans * i
    return ans % MOD


for _ in range(int(input())):
    l, r = map(int, input().rstrip().split())
    print(final(l, r))
