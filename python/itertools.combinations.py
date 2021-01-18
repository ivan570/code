from itertools import combinations as com
a, b = input().split(" ")
a = sorted(a)
a = "".join(a)
b = int(b)
for i in range(1, b + 1):
    a_list = sorted(list(com(a, i)))
    for k in a_list:
        print("".join(k))
