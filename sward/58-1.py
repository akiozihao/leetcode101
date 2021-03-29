class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip()
        strs = s.split()
        strs.reverse()
        return ' '.join(strs)
