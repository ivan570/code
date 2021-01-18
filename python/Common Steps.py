arr = [1, 1, 2]


def ans(nums):
    if nums < 3:
        return arr[nums]
    for i in range(3, n + 1):
        arr.append(arr[i - 1] + arr[i - 2] + arr[i - 3])

    return arr[nums]


n = int(input())
print(ans(n))
