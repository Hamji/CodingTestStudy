# https://leetcode.com/problems/longest-palindromic-substring/
class Solution:
    def longestPalindrome(self, s: str) -> str:

        result = ""
        if len(s) <= 1:
            return s

        for i in range(len(s)):
            # pan이 홀 수 일때
            sub = self.check(s, i, i)
            if len(sub) > len(result):
                result = sub

            # pan이 짝수일 때
            sub = self.check(s, i, i + 1)
            if len(sub) > len(result):
                result = sub
        return result

    def check(self, s, left, right):
        if right < len(s) and s[left] == s[right]:
            while left - 1 >= 0 and right + 1 < len(s) and s[left - 1] == s[right + 1]:
                left -= 1
                right += 1
            return s[left:right + 1]
        return s[left]
