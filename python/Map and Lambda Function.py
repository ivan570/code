cube = lambda x: x ** 3


def fibonacci(number):
    l = [0, 1]
    if number <= 2:
        return l[:number]
    for x in range(2, number):
        l.append(l[x - 1] + l[x - 2])
    return l


if __name__ == '__main__':
    n = int(input())
    print(list(map(cube, fibonacci(n))))
