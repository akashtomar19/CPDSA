
#   https://math.stackexchange.com/questions/2869495/number-of-solutions-to-a-linear-congruence-equation
#   https://cp-algorithms.com/algebra/linear-diophantine-equation.html
#   solved the below problem using linear congruence and 
#   it can be solved using extended euclidean algo also
#   https://math.stackexchange.com/questions/20717/how-to-find-solutions-of-linear-diophantine-ax-by-c
 

import sys
import random
import math

def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)

def main():
    t = 1
    while t > 0:
        t -= 1
        
        a, b = map(int, input().split())

        g = gcd(a, b)

        if abs(g) > abs(2):
            print(-1)
            continue


        a = a // g
        c = 2 // g
        MOD = a
        b = b // g

        if a == 0: # Only one solution
            print(c // b, 0)
            continue
            

        if b == 0: # Only one solution
            print(0, c // a)
            continue
        
        fx0 = pow(b, -1, a) * c

    
        ty0 = (b * fx0 - c) // MOD

        # if (b * fx0 - ty0 * a) != c:
        #     print("breaking .. ")
        #     print(aa, bb)
        #     sys.exit(0)

        print(fx0, ty0)

if __name__ == "__main__":
    main()
