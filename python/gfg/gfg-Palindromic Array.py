for _ in range(int(input())):
    input()
    arr = list(map(int, input().rstrip().split(" ")))
    i = 0
    past = len(arr)
    j = past - 1
    while i < j:
        if arr[i] == arr[j]:
            i += 1
            j -= 1
            continue
        if arr[i] > arr[j]:
            temp = arr[i] + arr[i + 1]
            t = arr[:i] + [temp] + arr[i + 2:]
            print(t)
            break
