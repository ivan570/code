from itertools import product as pro

for _ in range(int(input())):
    s = input().split()[-1]
    s = int(s)
    a = set(map(int, input().rstrip().split()))
    b = set(map(int, input().rstrip().split()))
    p = sorted(list(pro(a, b)))
    ans = ""
    for k in range(len(p)):
        if sum(p[k]) == s:
            ans += " ".join(map(str, p[k])) + ", "
    if ans != "":
        print(ans[:-2])
    else:
        print("-1")
