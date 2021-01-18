from sympy import isprime
from itertools import permutations as per
from random import randint


def marge(aList):
    return int("".join(map(str, aList)))


def listOfPrimeNumber(starting, ending):
    ans = []
    for i in range(starting, ending + 1):
        if isprime(i):
            ans.append(i)
    return ans


# start, end = map(int, input().split(" "))
while True:
    start = randint(2, 100)
    if start > 60:
        start -= randint(2, 40)
    end = randint(start, 100)
    if end - start >= 40:
        break

print(start, end)
# start, end = 0, 56
prime = listOfPrimeNumber(start, end)
prime = list(per(prime, 2))
prime = list(map(marge, prime))
prime = list(filter(isprime, prime))
# print(prime)
minimum = min(prime)
maximum = max(prime)
length = len(set(prime))
# print(minimum, maximum, length)
a = minimum
b = maximum
c = a + b
for _ in range(3, length):
    a = b
    b = c
    c = a + b
print(c, end="")

