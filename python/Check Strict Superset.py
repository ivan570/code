A = set(map(int, input().split(" ")))
n = int(input())
b = True
for i in range(n):
    B = set(map(int, input().split(" ")))
    if len(A - B) > 0 and len(B - A) == 0:
        pass
    else:
        b = False
        break
print(b)