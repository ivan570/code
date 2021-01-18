arr = []
for _ in range(int(input())):
    arr.append(int(input()))

ans = [0] * len(arr)
ans[0] = 1
try:
    if arr[1] < arr[0]:
        i = 0
        while arr[i + 1] < arr[i]:
            ans[0] += 1
            i += 1
except :
    pass
print("ans[0]", ans[0])
for i in range(len(arr)):
    if i == 0:
        continue
    if arr[i] > arr[i - 1]:
        ans[i] = ans[i - 1] + 1
    else:
        ans[i] = 1
        j = i
        try:
            while arr[j] > arr[j + 1]:
                ans[i] += 1
                j += 1
        except:
            pass
        if arr[i] < arr[i - 1] and ans[i - 1] <= ans[i]:
            ans[i - 1] = ans[i] + 1

print(arr)
print(ans)
print(sum(ans))
