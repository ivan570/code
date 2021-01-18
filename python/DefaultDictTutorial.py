from collections import defaultdict
d = defaultdict(list)
n, m = map(int, input().split(" "))
p = 1
for i in range(n):
    temp = input()
    d[temp].append(p)
    p += 1

for j in range(m):
    temp = input()
    if temp in d:
        print(" ".join(map(str, d[temp])))
    else:
        print("-1")

