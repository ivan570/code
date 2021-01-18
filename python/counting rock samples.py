from collections import Counter


S, R = map(int, input().split())
sample = list(map(int, input().rstrip().split()))
p = dict(Counter(sample))

for _ in range(R):
    start, end = map(int, input().split())
    c = 0
    for i in range(start, end + 1):
        if p.get(i) is not None:
            c += p.get(i)
    print(c)

