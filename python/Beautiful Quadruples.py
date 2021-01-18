import math
from itertools import combinations as com


def isAContain(arr):
    return arr.count('a') >= 1


input()
letters = input().split(" ")
limit = int(input())

combination = list(com(letters, limit))

a = list(filter(isAContain, combination))
print("{0:.3f}".format(len(a) / len(combination)))