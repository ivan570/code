p, d = map(int, input().split(" "))
arr = []
for _ in range(d):
    arr.append(list(map(int, input().split(" "))))

i = 0
row = 0
ans = []
while i < p:
    s = 888888888888
    ji = row
    for j in range(row, len(arr)):
        t = sum(arr[j][i:])
        if t < s:
            s = t
            ji = j
    row = ji
    ans.append(arr[ji][i])
    i += 1


print(sum(ans), ans)
