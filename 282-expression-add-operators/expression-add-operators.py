class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        result = []
        n = len(num)
        
        def backtrack(index: int, prev_op: int, curr_val: int, path: List[str]):
            if index == n:
                if curr_val == target:
                    result.append("".join(path))
                return
                
            for j in range(index, n):
                if j > index and num[index] == '0':
                    break
                    
                sub_str = num[index:j+1]
                val = int(sub_str)
                
                if index == 0:
                    path.append(sub_str)
                    backtrack(j + 1, val, val, path)
                    path.pop()
                else:
                    path.append('+')
                    path.append(sub_str)
                    backtrack(j + 1, val, curr_val + val, path)
                    path.pop()
                    path.pop()
                    
                    path.append('-')
                    path.append(sub_str)
                    backtrack(j + 1, -val, curr_val - val, path)
                    path.pop()
                    path.pop()
                    
                    path.append('*')
                    path.append(sub_str)
                    backtrack(j + 1, prev_op * val, (curr_val - prev_op) + (prev_op * val), path)
                    path.pop()
                    path.pop()
                    
        backtrack(0, 0, 0, [])
        return result
