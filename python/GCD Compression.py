def getDiviser(n):
    i = n - 1
    while i > 1:
        if i % 2 == 1 and n % i == 0:
            return i
        i -= 1
    return -1


def getOutput(n):
    if n == 1:
        print("FastestFinger")
    elif n % 2 == 1:
        print("Ashishgup")
    else:
        t = 1
        while n > 1:
            k = getDiviser(n)
            # print(k)
            if k > 1:
                n = n / k
            else:
                n = n - 1
            if n % 2 == 1:
                break
            t = 1 - t

        if t == 0:
            print("Ashishgup")
        else:
            print("FastestFinger")

t = int(input())
for _ in range(t):
    n = int(input())
    getOutput(n)