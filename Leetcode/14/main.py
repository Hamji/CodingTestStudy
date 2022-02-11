class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        result = ""
        for i in zip(*strs):
            if len(set(i)) == 1:
                result += i[0]
            else:
                break
        
        return result
        
