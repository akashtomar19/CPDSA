class Solution:
    def lengthAfterTransformations(self, s: str, t: int, nums: List[int]) -> int:

        # print(chr(ord('a') + 0 + 1))
        mod = int(1e9) + 7
        
        
        def mul(A, B):
            
            r1, c1 = len(A), len(A[0])
            r2, c2 = len(B), len(B[0])

            if c1 != r2:
                return None
            
            res = [[0] * c2 for _ in range(r1)]

            for i in range(r1):
                for j in range(c1):
                    for k in range(c2):
                        res[i][k] += A[i][j] * B[j][k]
                        res[i][k] %= mod
            
            return res


        sec = [[0] * 26]

        first = [[0] * 26 for _ in range(26)]

        freq = defaultdict(int)

        for i in range(len(s)):
            freq[ord(s[i]) - ord('a')] += 1
        
            
        
        for i in range(26):
            cnt = nums[i]
            j = (i + 1) % 26
            sec[0][i] = freq[i]
            while cnt:
                first[i][j] = 1
                j += 1
                j %= 26
                cnt -= 1

        expo = t
        ans = sec
        A = first
        # print(type(ans), type(A))
        # print(ans, 900)
        # print(A)
        
        while expo:
            if expo & 1:
                ans = mul(ans, A)
            # print(A)
            A = mul(A, A)
            # print(A)
            # break
            expo >>= 1
        
        return (sum(*ans) % mod)
        return 0




        