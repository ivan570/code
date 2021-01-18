def getPositionValue(value):
    if value < 0:
        return 0
    a_value = value % 4
    if a_value == 0:
        return value
    elif a_value == 1:
        return 1
    elif a_value == 3:
        return 0
    elif a_value == 2:
        return value + 1


for _ in range(int(input())):
    start, end = map(int, input().split(" "))
    ans = 0
    f = 0
    temp = start
    while temp % 8 != 7:
        ans ^= getPositionValue(temp)
        print(getPositionValue(temp), temp)
        if temp == end:
            f = 1
            break
        temp += 1
    temp = end
    while temp % 8 != 7 and f != 1:
        ans ^= getPositionValue(temp)
        print(getPositionValue(temp), temp)
        if temp == start:
            break
        temp -= 1
    print(ans)