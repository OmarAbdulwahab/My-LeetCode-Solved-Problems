class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        ans = []
        count = defaultdict(int)
        # O(n * l * l)
        for w in words:
            for i in range(len(w)):
                count[w[:i+1]] += 1
                
        for w in words:
            score = 0
            for i in range(len(w)):
                score += count[w[:i+1]]
            ans.append(score)
            
        return ans