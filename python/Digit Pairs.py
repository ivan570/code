n = input()
arr = list(map(int, input().split()))
n = int(n)
pair = []
for i in arr:
    t = list(str(i))
    t = int(min(t)) * 7 + int(max(t)) * 11
    t = str(t)
    pair.append(t[-2:])
# print(*pair)
digit = [0] * 10
for i in range(1, len(pair), 2):
    first = str(pair[i])[0]
    for j in range(i + 2, len(pair), 2):
        if  str(pair[j])[0] == first:
            if digit[int(first)] < 2:
                digit[int(first)] += 1

for i in range(0, len(pair), 2):
    first = str(pair[i])[0]
    for j in range(i + 2, len(pair), 2):
        if  str(pair[j])[0] == first:
            if digit[int(first)] < 2:
                digit[int(first)] += 1

print(sum(digit), end="")

