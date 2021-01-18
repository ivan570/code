for _ in range(int(input())):
    input()
    a = set(map(int, input().rstrip().split()))
    b = set(map(int, input().rstrip().split()))

    if b.issubset(a):
        print("Yes")
    else:
        print("No")
