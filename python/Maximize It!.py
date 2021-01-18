from itertools import product


def f(value):
    return value ** 2


K, M = map(int, input().split(" "))
item = []
for _ in range(K):
    item.append(list(map(int, input().split(" ")))[1:])

p = list(product(*item))

results = [ sum(map(f, i)) % M for i in p]
print(results)
print(max(results))
