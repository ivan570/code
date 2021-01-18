def Emi(loanAmount, monthlyInterestRate, numberOfYears):
    q = 1 - (1 / ((1 + monthlyInterestRate) ** (numberOfYears * 12)))
    p = loanAmount * monthlyInterestRate
    return p / q


P = int(input())
T = int(input())
ans = [0, 0]
for index in range(2):
    N = int(input())
    for i in range(N):
        rate, year = map(float, input().split(" "))
        ans[index] += Emi(P, rate, year)

print(ans)
if ans[0] < ans[1]:
    print("Bank A")
else:
    print("Bank B")
