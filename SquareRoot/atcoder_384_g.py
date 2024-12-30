from atcoder.fenwicktree import FenwickTree

n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
K = int(input())
queries = []



for i in range(K):
    q = list(map(int, input().split()))
    queries.append(q)
    queries[-1].append(i)

queries.sort(key=lambda x: (x[0] // 1000, x[1]))

C = A + B
s = set(C)
sz = len(s)
ind = 0
a = {}
for val in sorted(s):
    a[val] = ind
    ind += 1

a0 = FenwickTree(sz)
a1 = FenwickTree(sz)
b0 = FenwickTree(sz)
b1 = FenwickTree(sz)

x = 0 
y = 0
now = 0
bsum = 0
asum = 0


res = [-1] * K



for q in queries:
    xi = q[0]
    yi = q[1]
    ind = q[2]
    

    while x < xi:
        c = b0._sum(a[A[x]])
        s = b1._sum(a[A[x]])
        now += y * A[x] + bsum - 2 * ((y - c) * A[x] + s)
        a0.add(a[A[x]], 1)
        a1.add(a[A[x]], A[x])
        asum += A[x]
        x += 1
    
    while x > xi:
        x -= 1
        c = b0._sum(a[A[x]])
        s = b1._sum(a[A[x]])
        now -= y * A[x] + bsum - 2 * ((y - c) * A[x] + s)
        a0.add(a[A[x]], -1)
        a1.add(a[A[x]], -A[x])
        asum -= A[x]
        

    
    while y < yi:
        c = a0._sum(a[B[y]])
        s = a1._sum(a[B[y]])
        now += x * B[y] + asum - 2 * ((x - c) * B[y] + s)
        
        b0.add(a[B[y]], 1)
        b1.add(a[B[y]], B[y])
        bsum += B[y]
        y += 1
    
    while y > yi:
        y -= 1
        # print(y, B)
        c = a0._sum(a[B[y]])
        s = a1._sum(a[B[y]])
        now -= x * B[y] + asum - 2 * ((x - c) * B[y] + s)
        b0.add(a[B[y]], -1)
        b1.add(a[B[y]], -B[y])
        bsum -= B[y]
        

    # print(now)
    res[ind] = now

print(*res)

    
    
