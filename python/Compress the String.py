from itertools import groupby


def f(x):
    return x


s = list(map(int,list(input())))
di = []
for i in groupby(s, f):
    x = list(i[1])
    y = i[0]
    di.append((len(x), y))

print(" ".join(map(str, di)))
