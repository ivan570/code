def isprime(a):
    if a <= 1:
        return False
    if a == 2 or a % 2 == 0 or a % 3 == 0:
        return True
    for i in range(3, int(round(a ** (1/2))) + 1, 2):
        if a % i == 0:
            return False
    return True


def fibo(a, b, limit):
    li = [a, b, a + b]
    if (limit == 1):
        return li[0]

    elif (limit == 2):
        return li

    for i in range(3, limit + 1):
        li.append(li[i - 1] + li[i - 2])

    return li[limit - 1]



def findAllPrint(l, u):
    li = []
    for i in range(l, u + 1):
        if i <= 1:
            continue
        if (isprime(i)):
            li.append(i)
    return list(set(li))


def makeAllCombination(li):
    temp = list(map(str, li))
    ans = []
    for i in range(len(temp)):
        for j in range(len(temp)):
            if i == j:
                continue
            else:
                ans.append(int(temp[i] + temp[j]))
    return ans

l, u = map(int, input().split())
li = findAllPrint(l, u)
li = makeAllCombination(li)
temp_li = list(set(list(filter(isprime, li))))

s = min(temp_li)
l = max(temp_li)
c = len(temp_li)

f = fibo(s, l, c)
print(f)