string = input()
l = [string[i:j] for i in range(len(string)) for j in range(i + 1, len(string) + 1)]
l = list(map(int, l))
print(sum(l) % (10 ** 9 + 7))