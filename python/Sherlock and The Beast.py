
def decentNumber(n):
    x = 0
    y = 0
    ans = ""
    # for i in range(n + 1, 0, -1):
    for i in range(n, -1, -1):
        if (i % 3) == 0 and ((n - i) % 5) == 0:
            x = i
            y = n - i
            break
    if x == 0 and y == 0:
        ans = "-1"
    else:
        ans = "5" * x + "3" * y

    return ans


x = int(input())
for _ in range(x):
    print(decentNumber(int(input())))
