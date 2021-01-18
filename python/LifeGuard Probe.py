from math import sqrt, floor

x1 = float(input())
y1 = int(input())
x2 = int(input())
y2 = int(input())
f = float(input())

increase = 0.1
time = 8888888888888
temp = x1
if temp <= x2:
    while floor(temp) <= x2:
        t = temp - x1
        t = sqrt((y1 ** 2) + (t ** 2))
        t_time = t / f
        t = (x2 - temp)
        t = sqrt((y2 ** 2) + (t ** 2))
        t_time += t
        if t_time < time:
            time = t_time
        else:
            temp -= increase
            t_increase = 0.0000001
            while temp <= x2:
                t = temp - x1
                t = sqrt((y1 ** 2) + (t ** 2))
                t_time = t / f
                t = (x2 - temp)
                t = sqrt((y2 ** 2) + (t ** 2))
                t_time += t
                if t_time < time:
                    time = t_time
                else:
                    f = 1
                    break
                temp += t_increase
            break
        temp += increase
    print("{0:.6f}".format(temp))

else:
    # while temp > x2:
    #     t = x1 - temp
    #     t = sqrt((y1 ** 2) + (t ** 2))
    #     t_time = t / f
    #     t = temp - x2
    #     t = sqrt((y2 ** 2) + (t ** 2))
    #     t_time += t
    #     if t_time < time:
    #         time = t_time
    #     else:
    #         break
    #     temp += increase
    # print("{0:.6f}".format(temp))
    while floor(temp) <= x2:
        t = x1 - temp
        t = sqrt((y1 ** 2) + (t ** 2))
        t_time = t / f
        t = temp - x2
        t = sqrt((y2 ** 2) + (t ** 2))
        t_time += t
        if t_time < time:
            time = t_time
        else:
            temp -= increase
            t_increase = 0.0000001
            while temp <= x2:
                t = x1 - temp
                t = sqrt((y1 ** 2) + (t ** 2))
                t_time = t / f
                t = temp - x2
                t = sqrt((y2 ** 2) + (t ** 2))
                t_time += t
                if t_time < time:
                    time = t_time
                else:
                    f = 1
                    break
                temp += t_increase
            break
        temp += increase
    print("{0:.6f}".format(temp))