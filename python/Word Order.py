from collections import OrderedDict as Od

d = Od()
n = int(input())
for i in range(n):
    s = input()
    try:
        d[s] += 1
    except Exception:
        d[s] = 1

print(len(d))
print(" ".join(map(str, d.values())))