a = []
for i in range(1, 10):
    a.append(str(i))


def limit(listValue):
    return listValue[:len(a)]


def fun(aList, b):
    li = []
    for i in range(len(aList)):
        for j in range(i, len(b)):
            li.append(aList[i] + b[j])
    return li


t = fun(a, a)
t = fun(t, t)
t = fun(t, t)
t = sorted(set(map(limit, t)))
for i in t:
    if i > "200000":
        break
    print(i)