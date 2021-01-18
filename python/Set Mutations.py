_ = input()
mainSet = set(map(int, input().split(" ")))
testCase = int(input())
for T in range(testCase):
    todo = input().split(" ")[0]
    todoSet = set(map(int, input().split(" ")))
    ansStr = "mainSet." + todo + "(todoSet)";
    eval(ansStr)

print(sum(mainSet))