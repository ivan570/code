T = int(input())
for _ in range(T):
    try:
        x, y = map(int, input().split(" "))
        print(x // y)
    except Exception as e:
        print("Error Code:", e)