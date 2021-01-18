import re
pattern = r'[,\.]'
print(*(re.split(pattern, input())))