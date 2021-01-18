li = []

for i in range(20):
    temp = input()
    if len(temp) > 0:
        li.append(int(temp))
    else:
        break

sum = 0
for age in li:
    if age <= 0:
        sum = "INVLID INPUT"
        break
    if age < 17:
        sum += 200
    elif age >= 17 and age < 40:
        sum += 400
    elif age >= 40:
        sum += 300

if (sum != "INVLID INPUT")
print("Income", sum, "INR")
else:
    print(sum)
