def countChar(string):
    d = [0] * 26
    a = ord('a')
    for i in string:
        int_i = ord(i)
        d[int_i - a] += 1
    return d


def findMax(char_array):
    m = 0
    ans = -1
    for i in range(len(char_array)):
        if char_array[i] > m:
            m = char_array[i]
            ans = i
    return ans


def makestr(st, first, second):
    ans = ""
    for i in range(len(st)):
        temp = ord(st[i])
        temp -= ord('a')
        if temp == first or temp == second:
            ans += st[i]
    if isValid(ans):
        return ans
    else:
        return ""


def isValid(st):
    for i in range(1, len(st) - 1):
        if st[i] == st[i - 1] or st[i] == st[i + 1]:
            return False
    if len(st) == 2:
        if st[0] == st[1]:
            return False
    if len(st) < 2:
        return False
    return True

__ = input()
st = input()
totalChar = countChar(st)
stTotal = len(set(st))
i = 0
l = 0
while i < stTotal:
    i += 1
    first = findMax(totalChar)
    totalChar[first] = 0;
    second = findMax(totalChar)
    t = makestr(st, first, second)
    print(t)
    if l < len(t) :
        l = len(t)
print(l)