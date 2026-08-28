class Solution:
    def numSquares(self, n: int) -> int:
        def isSquare(x: int) -> bool:
            sq = int(x**0.5)
            return sq * sq == x

        if isSquare(n):
            return 1

        temp = n
        while temp % 4 == 0:
            temp //= 4
        if temp % 8 == 7:
            return 4

        for i in range(1, int(n**0.5) + 1):
            if isSquare(n - i * i):
                return 2

        return 3
