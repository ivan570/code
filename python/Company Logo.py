from collections import Counter


def fun(a):
    print(a[1], ord('a') + ord(a[0]), a[0])
    return (a[1], ord('a') - ord(a[0]))


s = input()
l = dict(Counter(s))
tu = [(i, l[i]) for i in l]
so = sorted(tu, key=fun, reverse=True)
print(so)
so = so[:3]
for i in so:
    print(i[0], i[1])
