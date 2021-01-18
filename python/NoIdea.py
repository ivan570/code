from pip._vendor.distlib.compat import raw_input
N,M=raw_input().split()
n_set=raw_input().split()
a_m_set=set(raw_input().split())
b_m_set=set(raw_input().split())

# a=b=0
# for i in a_m_set:
#     if i in n_set:
#         a+=1
#         
# for i in b_m_set:
#     if i in n_set:
#         b+=1
        
# print(a-b)
# print(a_m_set)
# print(b_m_set)
# print(n_set)
print([(i in a_m_set)-(i in b_m_set) for i in n_set])
# 
# print(True-False)