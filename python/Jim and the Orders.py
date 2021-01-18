d = {}
for i in range(1, int(input()) + 1):
    x, y = map(int, input().split(" "))
    d[i] = x + y

def keyFunction(d):
    return d[1]

a = sorted(d.items(), key = keyFunction)

ans = [x[0] for x in a]
print(*ans)
