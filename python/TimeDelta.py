from datetime import datetime
fmt = '%a %d %b %Y %H:%M:%S %z'
testCase = int(input())

for _ in range(testCase):
    i = abs(datetime.strptime(input(), fmt) -
            datetime.strptime(input(), fmt))
    print(int(i.total_seconds()))
