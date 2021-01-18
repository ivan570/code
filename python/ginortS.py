lower, upper, odd, even = "", "", "", ""
for i in input():
    if i.isdigit():
        if int(i) % 2 == 0:
            even += i
        else:
            odd += i
    elif i.isupper():
        upper += i
    elif i.islower():
        lower += i
print(*sorted(lower), *sorted(upper),
      *sorted(odd), *sorted(even), sep="")
