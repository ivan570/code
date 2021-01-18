from collections import deque
d = deque()
n = int(input())
for _ in range(n):
    l = input().split(" ")
    try:
        s = "d." + l[0] + "(" + l[1] + ")"
    except:
        s = "d." + l[0] + "()"
    eval(s)

print(" ".join(map(str, list(d))))
