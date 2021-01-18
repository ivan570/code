def getmid(arr):
    n = len(arr)
    number = [0] * 201
    for i in arr:
        number[i] += 1
    ele = 0
    for i in range(len(number)):
        ele += number[i]
        if ele * 2 > n:
            return i
        if n % 2 == 1 and ele >= n // 2 + 1:
            return i
        if n % 2 == 0 and ele == n // 2:
            return (i + i + 1) / 2


def output(arr, n, d):
    ans = 0
    for i in range(d, len(arr)):
        mid = getmid(arr[i-d: i])
        if arr[i] >= 2 * mid:
            ans += 1
    return ans


n, d = map(int, input().split(" "))
arr = list(map(int, input().split(" ")))
print(output(arr, n, d))

