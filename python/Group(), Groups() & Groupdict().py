import re

pattern = r'([a-zA-Z0-9])\1+'
m = re.search(pattern, input())

print(m.group(1) if m else -1)
