for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().rstrip().split(" ")))
d = {}
i = 0
j = n - 1
while i <= j:
    if i == 0:
        d[i] = n
        d[j] = n
    else:
        dl = len(d)
        rm = n - dl
        temp = d[i - 1] + rm
        d[i] = temp
        d[j] = temp
    i += 1
    j -= 1


ans = 0
for i in d:
    ans += (arr[i] * d[i])

print(d)

print(ans)
