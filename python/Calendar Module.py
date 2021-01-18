import calendar

m, d, y = map(int, input().split(" "))

cal = calendar.weekday(y,m,d)
print(list(calendar.day_name)[cal].upper())