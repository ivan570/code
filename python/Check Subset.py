testCase = int(input())
for i in range(testCase):
    _ = input()
    a = set(input().split(" "))
    _ = input()
    b = set(input().split(" "))
    print(a.issubset(b))
