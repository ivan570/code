def output(maxValue):
    if maxValue <= 3:
        return maxValue
    if maxValue <= 5:
        return 3

    count = 0
    while maxValue >= 1:
        maxValue //= 2
        count += 1
    return count

t = int(input())
for _ in range(t):
    maxValue = int(input())
    print(output(maxValue))