l, k = map(int, input().split(" "))
arr = list(map(int, input().split(" ")))

if k > l/2:
    arr = sorted(arr)[::-1]
else:
    i = 0
    while i < k:
        f = arr.index(max(arr[i:]))
        if i == f and k <= l/2:
            k += 1
        arr[i], arr[f] = arr[f], arr[i]
        i += 1
print(" ".join(map(str, arr)))
