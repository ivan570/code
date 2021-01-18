input()
arr = list(map(int, input().split(" ")))
binary = list(map(lambda x: [x, bin(x)[2:]], arr))
l = len(bin(max(arr))[2:])
max_len = list(filter(lambda x: len(x[1]) == l, binary))
else_len = list(filter(lambda x: len(x[1]) != l, binary))

one = []
for i in max_len:
    one.append(i[0])

two = []
for i in else_len:
    two.append(i[0])
one = sorted(one)
two = sorted(two)

ans = []
for i in one:
    ans.append(i)

for i in two:
    ans.append(i)

# print(*ans)

final = []
for i in range(len(ans) - 1):
    final.append(ans[i] ^ ans[i + 1])
print(max(final))