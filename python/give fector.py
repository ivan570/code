# print all factor of the given number include 1 and number ot self
# constrain :
# 1 <= number <= (10 ** 12)

from math import sqrt, floor

number = int(input())
first = []
second = []
for i in range(1, floor(sqrt(number))):
    if number % i == 0:
        first.append(i)
        second.append(number // i)

if sqrt(number) == floor(sqrt(number)):
    first.append(int(sqrt(number)))

print(*first, end=" ")
print(*reversed(second), end=" ")
