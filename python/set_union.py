n=input()
n_list=input().split()
m=input()
m_list=input().split()

ans=set()
ans=set(n_list) | set(m_list)
print(len(ans))