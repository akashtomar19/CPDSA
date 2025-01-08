from decimal import *

getcontext().prec = 25
n = int(input())

hx = [0] * (n + 1)

ans = Decimal(-1e-20)

for i in range(1, n + 1):
    b = list(map(int, input().split()))

    hx[i] = b

    if i >= 2:

        slope = Decimal(Decimal(1.0 *hx[i][1] - hx[i - 1][1]) / Decimal(1.0 * hx[i][0] - hx[i - 1][0]))
        ans = max(ans, Decimal(-slope * hx[i][0] + hx[i][1]))

if ans < 0.0:
    print(-1)
else:
    print(f"{ans:.18f}")