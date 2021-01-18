M=int(input())
M_set=set(map(int,input().split()))
N=int(input())
N_set=set(map(int,input().split()))
li=[]
for i in M_set:
    if i not in N_set:
        li.append(i)

for i in N_set:
    if i not in M_set:
        li.append(i)
        
for i in sorted(li):
    print(i)