import re
pattern = '^[+-]?\d*\.\d+$'
x = re.compile(pattern)
for _ in range(int(input())):
    # try:
    #     s = input()
    #     f = float(s)
    #     if s[-1] == '.' or s.find('.') == -1:
    #         print("False")
    #     else:
    #         print("True")
    # except:
    #     print("False")
    s = input()
    print(re.match(pattern, s))
