class Solution:
    def longestIncreasingPath(self, matrix: list[list[int]]) -> int:
        if not matrix or not matrix[0]:
            return 0
            
        ROWS, COLS = len(matrix), len(matrix[0])
        memo = [[0] * COLS for _ in range(ROWS)]
        
        def dfs(r, c):
            if memo[r][c] != 0:
                return memo[r][c]
                
            max_path = 1
            for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < ROWS and 0 <= nc < COLS and matrix[nr][nc] > matrix[r][c]:
                    max_path = max(max_path, 1 + dfs(nr, nc))
                    
            memo[r][c] = max_path
            return max_path
            
        ans = 0
        for r in range(ROWS):
            for c in range(COLS):
                ans = max(ans, dfs(r, c))
                
        return ans
