s=input()
k=int(input())
st=''
length=0
for i in s:
    length+=1
    if i not in st:
        st += i
    if length == k:
        st=st.rjust(k," ")
        print(st)
        st=''
        length=0