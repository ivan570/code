"""
constrains :
    1 <= T <= 1000
    len(p) == 26
    1 <= len(s) <= 100
"""

for _ in range(int(input())):
    p = input()
    s = input()
    ans = []
    for i in s:
        ans.append(p.index(i))
    # ans = sorted(ans)
    print(ans)
    for i in ans:
        print(p[i], end="")

    print()
