n, K = map(int, input().split(" "))
bi = input()
l = len(bi) - (K - 1)
ans = list('1' + 'x' * (l - 1))
# print(ans)

for i in range(1, len(ans)):
    t = int(bi[i])
    for k in range(K):
        b = i - k - 1
        if b < 0:
            bb = 0
        else:
            bb = int(ans[b])

        print(t, bb)
        t ^= bb
    ans[i] = str(t)

print(*ans, sep="")

