_, friend = map(int, input().split(" "))
price = list(sorted(map(int, input().split(" ")), reverse=True))
ans = []
i = 0
while i < len(price) // friend + 1:
    temp = []
    for j in range(i*friend, i*friend + friend):
        try:
            temp.append(price[j])
        except:
            break
    ans.append(temp)
    i += 1

value = 0
for i in range(len(ans)):
    value += (sum(ans[i]) * (i + 1))

print(value)
