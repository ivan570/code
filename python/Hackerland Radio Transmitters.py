n, k = map(int, input().split(" "))
arr = list(map(int, input().split(" " )))
arr = sorted(arr)
i = 0
ans = list()
while i < n:
    if len(ans) == 0:
        j = i
        it = arr[i]
        while j < len(arr) and it + k >= arr[j]:
            j += 1
        j -= 1
        ans.append(j)
    else:
        ij = ans[-1]
        iarr = arr[ij]

