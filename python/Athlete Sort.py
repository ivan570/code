item = []
for i in range(list(map(int, input().split(" ")))[0]):
    item.append(tuple(map(int, input().split(" "))))
k = int(input())


def f(a):
    return a[k]


for i in sorted(item, key = f):
    print(*i)
