import re

testCase = int(input())
for i in range(testCase):
    s = input()
    try:
        re.compile(s)
        print("yes")
    except :
        print("No")
