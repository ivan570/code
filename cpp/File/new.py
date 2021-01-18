m = 10
ty = []
sy = []
for i in range(m):
    temp = input()
    if temp[:2] == "TY":
        ty.append(temp[2:])
    if temp[:2] == "SY":
        sy.append(temp[2:])

# print(ty, sy)
ty = sorted(ty)
sy = sorted(sy)

for i in range(max(len(ty), len(sy))):
    if i >= len(ty):
        print("[ABSENT]", end="")
    else:
        print("[TY{}]".format(ty[i]), end="")
    if i >= len(sy):
        print("[ABSENT]", end="")
    else:
        print("[SY{}]".format(sy[i]), end="")
    print()
