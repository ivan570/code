from collections import OrderedDict as odd

n = int(input())
o = odd()

for _ in range(n):
    li = input().split(" ")
    r = " ".join(li[:len(li) - 1])
    k = li[len(li) - 1]
    k = int(k)
    if r in o:
        o[r] += k
    else:
        o[r] = k

for i in o:
    print(i, o[i])
