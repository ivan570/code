x=int(input("enter x"))
y=int(input("enter y"))
 
while x>0:
    print(x)
    x-=1
     
for i in range(y,-1,-1):
    print(i)

list=[*range(y,-1,-1)]
print(list)
