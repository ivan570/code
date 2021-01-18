def isPower(string):
    if len(string) >= 2:
        for i in range(1, len(string)):
            if string[i] != '0':
                return False
        return True
    return False


def counterGame(n):
    bi = bin(n)[2:]
    ans = 1
    while bi != '1':
        if isPower(bi):
            bi = '1' + bi[2:]
        else:
            for j in range(1, len(bi)):
                if bi[j] == '0':
                    continue
                else:
                    break
            bi = bi[j:]
        ans += 1
    if ans % 2 == 1:
        return "Richard"
    else:
        return "Louise"


if __name__ == '__main__':
    for _ in range(int(input())):
        print(counterGame(int(input())))
