def closestNumbers(arr):
    arr.sort()
    # print(arr)
    i = 0
    m = 852074196325874
    while i < len(arr) - 1:
        j = i + 1
        d = arr[j] - arr[i]
        # print(m, arr[j], arr[i])
        if d < m:
            m = d
        i += 1
    ans = ""
    # print(m)
    i = 0
    while i < len(arr) - 1:
        j = i + 1
        d = arr[j] - arr[i]
        # print(d)
        if d == m:
            ans += str(arr[i]) + " " + str(arr[j]) + " "
        i += 1
    print(ans)


if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().rstrip().split()))
    closestNumbers(arr)
