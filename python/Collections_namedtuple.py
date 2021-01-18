from collections import namedtuple


def f(a):
    return a != ""


n = int(input())
string = input()
p = namedtuple('demo', string)
ans = 0
for _ in range(n):
    temp = list(input().split(" "))
    a, b, c, d = list(filter(f, temp))

    pt = p(a, b, c, d)
    ans += int(pt.MARKS)
print(ans / n)
