def isAll9(s):
    for i in s:
        if i != '9':
            return False
    return True


def separateNumbers(s):
    if len(s) < 2:
        print("NO")
        return
    f = 1
    for l in range(1, (len(s) // 2) + 1):
        f = 1
        first = s[:l]
        i = l
        t_l = l
        while i <= len(s) - l:
            if isAll9(first):
                t_l += 1
            second = s[i: i + t_l]
            print(first, second, s[i + t_l:], i, t_l, l, len(s) - l)
            if int(first) + 1 != int(second) or first[0] == '0' or second[0] == '0':
                f = 0
                break
            first = second
            i += t_l
        if f > 0 and len(s[i:]) == 0:
            print("YES", s[:l])
            return
    print("NO")


if __name__ == '__main__':
    q = int(input())

    for q_itr in range(q):
        s = input()

        separateNumbers(s)
