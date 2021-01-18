a, b = map(int, input().split(" "))
item = []
for i in range(b):
    item.append(map(float, input().split(" ")))
for i in list(zip(*item)):
    print(sum(i) / len(i))