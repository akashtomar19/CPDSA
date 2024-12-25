from collections import defaultdict

n = int(input())

a = list(map(int, input().split()))

p = [0] * 26

for i in range(26):

    d = defaultdict(lambda: 0)

    sum = defaultdict(lambda: 0)

    mask = (1 << i)
    
    for j in a:

        cur  = j % (mask)

        comp = (mask - cur) % mask

        d[cur] += 1

        sum[cur] += j

        # if i == 0:
        #     print(cur, d[comp], sum[comp], comp)

        p[i] += d[comp] * j + sum[comp]
        
        # if i == 0:
        #     print(p[0])

        
ans = 0

# print(p, d, sum)

for i in range(25):
    ans += (p[i] - p[i + 1]) // (1 << (i))
    # print(ans)



print(ans)

