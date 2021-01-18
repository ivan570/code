"""
equation is = (6-M)^2 + |D-15|
input format
[room]
[with tv] [without tv]
[target]
20
1500 1000
7000000
"""
from random import randint


def equation(M, D):
    return (6 - M) ** 2 + abs(D - 15)


def listOfYear():
    patients_month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    patients_year = []
    for i in range(12):
        patientsInMonth = []
        for k in range(patients_month[i]):
            patientsInMonth.append(equation(i + 1, k + 1))
        patients_year.append(patientsInMonth)
    return patients_year


"""
rooms = int(input())
tv, wtv = map(int, input().split(" "))
target = int(input())
"""
rooms = randint(5, 100)
wtv = randint(500, 5000)
tv = randint(wtv, 5000)
target = randint(0, 40000000)
print(rooms)
print(tv, wtv)
print(target)
year = listOfYear()
month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

for tv_room in range(0, rooms + 1):
    cost_year = 0
    for mon in range(12):
        cost_mon = 0
        for day in range(month[mon]):
            patients = year[mon][day]
            wtv_room = rooms - tv_room
            if patients > wtv_room:
                cost_mon += wtv_room * wtv + min(tv_room, patients - wtv_room) * tv
            else:
                cost_mon += patients * wtv
        cost_year += cost_mon

    if cost_year >= target:
        print(tv_room)
        break
else:
    print(rooms)
