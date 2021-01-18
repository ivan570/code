import re
s1 = input()
s2 = input()
s2 = re.compile(s2)
r = s2.search(s1)
if not r:
    print((-1, -1))
else:
    while r:
        print((r.start(), r.end() - 1))
        r = s2.search(s1, pos=r.start() + 1)
