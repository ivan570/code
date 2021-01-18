
def multiply(a, b):
    return int(a) * int(b)


if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        a, b = input().split()
        print(multiply(a.strip(), b.strip()))
