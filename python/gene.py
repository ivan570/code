from math import floor, ceil

n,d = map(int, input().split(" "))
arr = input().split(" ")
arr = list(map(int, arr))
number = [0] * 201
for i in arr[:d]:
    number[i] += 1

ans = 0
for i in range(d, len(arr)):
    acc = 0
    for k in range(201):
        acc += number[k]
        if 2 * acc >= d:
            break
    if d % 2 == 1 or 2 * acc > d:
        dub = 2 * k
    else :
        dub = k + next(y for y in range(k + 1, 201) if number[y])

    if arr[i] >= dub :
        ans += 1
    number[arr[i - d]] -= 1
    number[arr[i]] += 1
print(ans)

