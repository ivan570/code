for _ in range(int(input())):
    input()
    ans = 0
    arr = list(map(int, input().rstrip().split(" ")))
    for i in range(len(arr) - 1):
        for j in range(i + 1, len(arr)):
            x = arr[i] ^ arr[j]
            x = list(bin(x)[2:])
            x = list(filter(lambda k: k == '1', x))
            ans += len(x)
    print(2 * ans)
