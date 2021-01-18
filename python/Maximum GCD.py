def GDP(a, b):
    i = min(a, b)
    while i >= 1:
        if a % i == 0 and b % i == 0:
            return i
        i -= 1


t = int(input())
for _ in range(t):
    n = int(input())
    if n % 2 == 0:
        g = GDP(n, n/2)
    else:
        g = GDP(n - 1, (n - 1) / 2)
    print(int(g))
