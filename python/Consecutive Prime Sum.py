def isPrime(number):
    if number == 2:
        return True
    if number < 2 or number % 2 == 0:
        return False

    i = 3
    while (i ** 2) <= number:
        if number % i == 0:
            return False
        i += 2
    return True


def allPrime(number):
    if number < 2:
        return []
    if number == 2:
        return [2]
    if number == 3:
        return [2, 3]
    arr = [2]
    for i in range(3, number + 1, 2):
        if isPrime(i):
            arr.append(i)
    return arr


x = int(input())
k = allPrime(x)
ans = []
for i in range(2, len(k) + 1):
    tx = sum(k[:i])
    if tx > x:
        break
    if isPrime(tx):
        ans.append(tx)
print(len(ans))
