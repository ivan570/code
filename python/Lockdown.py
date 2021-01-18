num = int(input())
RO = int(input())
RG = int(input())
OR = int(input())
OG = int(input())
GR = int(input())
GO = int(input())

def is_valid(s):
    tro = RO
    trg = RG
    tor = OR
    tog = OG
    tgr = GR
    tgo = GO
    for k in range(len(s) - 1):
        if s[k] == s[k + 1]:
            continue
        if s[k] == 'R' and s[k + 1] == 'O':
            tro -= 1
        elif s[k] == 'R' and s[k + 1] == 'G':
            trg -= 1
        elif s[k] == 'O' and s[k + 1] == 'R':
            tor -= 1
        elif s[k] == 'O' and s[k + 1] == 'G':
            tog -= 1
        elif s[k] == 'G' and s[k + 1] == 'R':
            tgr -= 1
        elif s[k] == 'G' and s[k + 1] == 'O':
            tgo -= 1
        if tor < 0 or tog < 0 or trg < 0 or tro < 0 or tgr < 0 or tgo < 0:
            return False
    return True



all_same = []
ans = []
for i in 'ROG':
    t = i*num
    all_same.append(t)
    ans.append(t)

for i in all_same:
    t = list(i)
    for k in reversed(range(len(t))):


print(len(ans))
