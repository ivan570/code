n, k = map(int, input().split(" "))
s = list(input())
i = 0
j = n - 1
while i <= j and k > 0:
    if k >= 2 and s[i] != '9' and s[j] != '9':
        s[i] = '9'
        s[j] = '9'
        k -= 2
    elif k >= 1 and s[i] != s[j]:
        s[i] = max(s[i], s[j])
        s[j] = max(s[i], s[j])
        k -= 1
    elif k >= 1 and i == j:
        s[i] = '9'
    i += 1
    j -= 1

i = 0
j = n - 1
while i <= j:
    if s[i] != s[j]:
        print('-1')
        exit()
    i += 1
    j -= 1
print(*s, sep="")
