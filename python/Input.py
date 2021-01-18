a, b = map(int, input().split(" "))
s = input().replace('x', str(a))
ans = eval(s)
print(ans == b)