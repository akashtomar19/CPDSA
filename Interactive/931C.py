
import sys
def solve():
    n, m = map(int,input().split())
    print("? 1 1")
    sys.stdout.flush()
    a = int(input())
    # we will try to reach the two endpoints of the line 
    # where the distance for all the points on that line
    # from 1,1 is a
    x1 = 1 + min(n - 1, a)
    y1 = 1 + max(a - n + 1, 0)

    y2 = 1 + min(m - 1, a)
    x2 = 1 + max(a - m + 1, 0)

    print("? ",x1," ", y1)
    sys.stdout.flush()
    c = int(input())

    print("? ",x2," ", y2)
    sys.stdout.flush()
    d = int(input())
    x1 -= c // 2
    y1 += c // 2
    x2 += d // 2
    y2 -= d // 2
    
    print(f"? {x1} {y1}")
    g = int(input())
    
    if g == 0: # confirm if that distance as a from 1, 1
        print("! ",x1," ", y1)
        sys.stdout.flush()
    else:
        print("! ",x2," ", y2)
        sys.stdout.flush()
    

            

t = int(input())

for i in range(t):
    try:
        solve()
    except Exception as e:
        print(e)