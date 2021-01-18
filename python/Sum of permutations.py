
from itertools import permutations as per
MOD = 10**9+7


def m(a):
    s = ''
    for i in a:
        s += str(i)
    return int(s)


def getSum(n, arr):
    a = list(per(arr))
    l = list(map(m, a))

    return sum(l) % MOD


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        print(getSum(n, arr))
