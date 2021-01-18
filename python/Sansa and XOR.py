def output(arr):
    if len(arr) % 2 == 0:
        return 0
    ans = 0
    for i in range(0, len(arr), 2):
        ans ^= arr[i]
    return ans


for _ in range(int(input())):
    input()
    ar = list(map(int, input().split(" ")))
    print(output(ar))
