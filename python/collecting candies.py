from bisect import insort


def minTime(array):
    ans = 0
    while len(array) > 1:
        first = array[0]
        second = array[1]
        array = array[2:]
        ans += first + second
        insort(array, first + second)
    return ans


limit = int(input())
for LIMIT in range(limit):
    box = input()
    temp = list(map(int, input().split(" ")))
    arr = []
    for i in temp:
        insort(arr, i)

    print(minTime(arr), end="")
    if LIMIT < limit - 1:
        print()
