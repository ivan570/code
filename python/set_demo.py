s = set([1, 2, 3, 4, 5, 6, 7, 8, 9])
print(s)
s.remove(4)
print(s)
s.pop()
print(s)
s.discard(44)
print(s)

n = int(input())
s = set(map(int, input().split()))

m = int(input())
for i in range(m):
    st=input().split()
    if st[0] == 'pop' :
        s.pop()
    else:
        eval('s.'+st[0]+'('+st[1]+')')

print(sum(s))