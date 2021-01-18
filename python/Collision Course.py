d = {}
for _ in range(int(input())):
    x, y, speed = map(int, input().split())
    time = (x ** 2 + y ** 2) / speed ** 2
    if d.get(time) is not None:
        d[time] += 1

    else:
        d[time] = 1


ans = 0
for i in d:
    n = d[i]
    ans += (n * (n - 1)) / 2

print(int(ans))
