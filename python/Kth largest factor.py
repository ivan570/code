def find_factor(number):
    i = 1
    first = []
    second = []
    while i ** 2 < number:
        if number % i == 0:
            first.append(i)
            second.append(number // i)
        i += 1
    if i ** 2 == number:
        first.append(i)
    return second + list(reversed(first))


array = find_factor(int(input()))
k = int(input())
if k < len(array):
    print(array[k - 1])
else:
    print(1)
# print(array)
