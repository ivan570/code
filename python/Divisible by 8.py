from itertools import permutations as per


def ans(a):
    p = list(per(a))
    for i in p:
        st = "".join(i)
        if (int(st) % 8 == 0):
            return "Yes"
    return "No"


for _ in range(int(input())):
    a = list(input())
    print(ans(a))
