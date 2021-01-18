import bisect

item = []
for _ in range(int(input())):
    value = int(input())
    if len(item) == 0:
        item.append(value)
    elif len(item) == 1:
        if item[0] > value:
            item = [value, item[0]]
        else:
            item.append(value)
    else:
        bisect.insort(item, value)
    # print(item)
    if len(item) % 2 == 1:
        print("{0:.1f}".format(item[len(item) // 2]))
    else:
        print("{0:.1f}".format((item[len(item) // 2]
                               + item[len(item) // 2 - 1]) / 2))


