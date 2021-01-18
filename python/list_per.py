li=[]
n=int(input())
for i in range(n):
    s=input().split()
    cmd=s[0].lower()
    other=s[1:]
    if cmd!='print':
        cmd += "("+ ",".join(other) +")"
        eval("li."+cmd)
    else:
        print(li)