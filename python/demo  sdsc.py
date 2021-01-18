n = int(input())
l = list(map(int, input().split()))
s = []
for i in range(n):
    if len(str(l[i])) == 3:
        x = (int(max(list(str(l[i])))) * 11) + (int(min(list(str(l[i])))) * 7)
        if len(str(x)) > 2:
            x = x % 100
            if len(str(x)) == 1:
                x = "{0:0=2d}".format(x)
            s.append(int(x))
        else:
            s.append(int(x))
sig = [0] * 10
i = 0
pa = 0
for i in range(1, len(s), 2):
    msb = s[i] // 10
    for j in range(i + 2, len(s), 2):
        if msb == s[j] // 10:
            if sig[msb] < 2:
                sig[msb] += 1

for i in range(0, len(s), 2):
    msb = s[i] // 10
    for j in range(i + 2, len(s), 2):
        if msb == s[j] // 10:
            if sig[msb] < 2:
                sig[msb] += 1

for i in range(len(sig)):
    pa = pa + sig[i]
print(pa, s)
