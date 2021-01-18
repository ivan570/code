from collections import Counter as c

_ = input()
out = c(input().split(" "))
for i in list(out.items()):
    if i[1] == 1:
        print(i[0])
        break
