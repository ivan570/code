# minimum number of coin required to make all number from 1 to given number
# total of output not exceed given number
# 1, 2, 5 coin can use
#       1   2   5
# 1 => 1    0   0
# 2 => 2    0   0
# 3 => 1    1   0
# 4 => 2    1   0
# 5 => 1    2   2

number = int(input())
five = (number - 4) // 5
number = number - five * 5
if number % 2 == 0:
    one = 2
else:
    one = 1
number = number - one
two = number // 2
print(five + two + one, five, two, one)
