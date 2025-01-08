n = int(input())
a = []
a = list(map(int, input().split()))

a.sort()

res = 0
sum = a[0]

for i in range(1, n):
    res += i * a[i] - sum
    sum += a[i]

print(res)

