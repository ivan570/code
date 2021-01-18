def cases():
    size = int(input())
    s = list(input().strip())
    if size != len(s):
        return len(s)
#  ))( with ())
    count = 0
    for i in range(size - 2):
        if s[i] == ')' and s[i + 1] == ')' and s[i + 2] == '(':
            s[i] = '('
            s[i + 1] = ')'
            s[i + 2] = ')'
            count += 1
    if count % 2 == 0:
        return 'Bob'
    else: 
        return 'Alice'


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        print(cases())
