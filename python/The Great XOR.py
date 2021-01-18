def theGreatXor(x):
    bi = bin(x)[2:]
    t = 0
    for i in range(1, len(bi)):
        if bi[i] == '1':
            continue
        else:
            t = i
            break
    temp = bi[t:]
    ans = 0
    for i in range(len(temp)):
        if temp[i] == '0':
            x = len(temp) - i - 1
            ans += (2 ** x)
    return ans


for _ in range(int(input())):
    print(theGreatXor(int(input())))
