class Solution:
    def nearestPalindromic(self, n: str) -> str:
        INF = 10 ** 20
        N = len(n)
        first_half = n[:N//2]
        
        candidates = []
        if N % 2 == 0:
            for delta in [-1, 0, 1]:
                first_half_with_delta = str(int(first_half)+delta)
                candidates.append(first_half_with_delta + first_half_with_delta[::-1])
                
        else:
            middle = n[N//2]
            for delta in [-1, 0, 1]:
                if int(middle) + delta >= 0:
                    middle_with_delta = str(int(middle) + delta)
                    candidates.append(first_half + middle_with_delta + first_half[::-1]) 
                    
                    
        candidates.append("9" * N)
        if N-1 > 0: candidates.append("9" * (N-1))
        candidates.append("1" + "0"*(N-2) + "1")
        candidates.append("1" + "0"*(N-1) + "1")
        
        n_int = int(n)
        best = INF
        best_candidate = None
        for candidate in candidates:
            if abs(int(candidate) - n_int) < best and int(candidate) != n_int:
                best = abs(int(candidate) - n_int)
                best_candidate = candidate
            
            if abs(int(candidate) - n_int) == best and int(candidate) != n_int and int(candidate) < int(best_candidate):
                best = abs(int(candidate) - n_int)
                best_candidate = candidate
                
                
        return str(best_candidate)

        
            