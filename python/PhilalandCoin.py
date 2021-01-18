def output(coin):
    if coin <= 2:
        return coin
    temp = coin
    ans = 0
    while temp >= 1:
        temp /= 2
        ans += 1
    return ans


for _ in range(int(input())):
    n = int(input())
    print(output(n))

