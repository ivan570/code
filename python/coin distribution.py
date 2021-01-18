number = int(input())
t = number - 4
five = t // 5
number = number - five * 5
if number % 2 == 1:
    one = 1
else:
    one = 2
number = number - one
two = number // 2
print(five + one + two, five, two, one)
