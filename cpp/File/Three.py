ball = ['Cosco-Small-58-Red',
        'KC-Medium-95-Red',
        'Stag-Big-156-Redc',
        'KC-Medium-95-Red',
        'KC-Big-155-Red',
        'YSI-Small-52-Red',
        'Cosco-Medium-58-Green',
        'Cosco-Small-58-Green',
        'KC-Big-155-Green',
        'YSI-Small-52-Green',
        'Cosco-Small-58-White',
        'KC-Medium-95-White',
        'Cosco-Small-58-white',
        'YSI-Big-152-white',
        'KC-Big-155-White',
        'Cosco-Small-58-White',
        'YSI-Big-152-White',
        'KC-Big-155-White',
        'YSI-Small-52-White'
        ]

print("Please enter any of the following classification")
print("criteria for the balls")
print('Brand')
print('Size')
print('Weight')
print('Color')

temp = input()
f = 0
newli = []
for item in ball:
    newli.append(list(item.split("-")))

# print(newli)
d = {}
templi = []
if temp == "Brand":
    def fun(li):
        return li[0]
    templi = sorted(newli, key=fun)

elif temp == "Size":
    def fun(li):
        return li[1]
    templi = sorted(newli, key=fun)
elif temp == "Weight":
    def fun(li):
        return li[2]
    templi = sorted(newli, key=fun)
elif temp == "Color":
    def fun(li):
        # print("li ", li)
        return li[3]
    templi = sorted(newli, key=fun)
else:
    print("INVALID INPUT")

for item in templi:
    if d.get(item[0]) == None:
        d[item[0]] = list()
        d[item[0]].append(item)
    else:
        d[item[0]].append(item)

for item in d:
    print(item)
    for string in d[item]:
        print("-".join(string))
