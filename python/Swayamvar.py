n = int(input())
brides = list(input())
grooms = list(input())
ans = 0
while len(grooms) != 0:
    br = brides.pop(0)
    temp = []
    while len(grooms) > 0 and grooms[0] != br:
        temp.append(grooms.pop(0))
    if len(grooms) == 0:
        ans = len(brides) + 1
#        print(ans)
        break
    else:
        grooms.pop(0)
        grooms += temp
print(ans, end="")
