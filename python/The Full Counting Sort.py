limit = int(input())
ans = [""] * 11
for i in range(limit):
    x, y = input().split(" ")
    x = int(x)
    if i < limit / 2:
        ans[x] += "- "
    else:
        ans[x] += y + " "
print(*ans, sep="")