def makeStr(a):
    return "".join(a)


from itertools import permutations

string, k = input().split(" ")
k = int(k)
permutation = list(permutations(string, k))
for i in list(map(makeStr, sorted(permutation))):
    print(i)
