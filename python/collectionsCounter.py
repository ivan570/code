from collections import Counter
_ = int(input())

li = list(map(int, input().split(" ")))
d = Counter(li)

n = int(input())
ans = 0
for i in range(n):
    first, second = map(int, input().split(" "))
    if d[first] > 0 :
        ans += second
        d[first] -= 1
print(ans)