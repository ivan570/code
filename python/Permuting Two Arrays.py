def twoArrays(first, second, key_val):
    second = sorted(second)
    for k in range(len(first)):
        temp = first[k]
        for j in range(len(second)):
            if temp + second[j] >= key_val:
                second[j] = -1
                break
        else:
            return "NO"
    return "YES"


if __name__ == '__main__':
    for _ in range(int(input())):
        n, key = map(int, input().split(" "))
        one = list(map(int, input().split(" ")))
        two = list(map(int, input().split(" ")))
        print(twoArrays(one, two, key))
