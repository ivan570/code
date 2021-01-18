ans = 0
l = []
x, k = map(int, input().split(" "))
for _ in range(x):
    a, b = map(int, input().split(" "))
    if b == 1:
        l.append(a)
    else:
        ans += a

l = sorted(l)[::-1]
if k < len(l):
    for i in range(k):
        ans += l[i]
    for i in range(k, len(l)):
        ans -= l[i]

else:
    ans += sum(l)
print(ans)
