# https://leetcode.com/problems/valid-parentheses/description/
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        open_brackets = "({["
        for c in s:
            if c in open_brackets:
                stack.append(c)
                continue
            
            valid = False
            if c == ')' and len(stack) > 0 and stack[-1] == '(':
                valid = True
            elif c == '}' and len(stack) > 0 and stack[-1] == '{':
                valid = True
            elif c == ']' and len(stack) > 0 and stack[-1] == '[':
                valid = True
            
            if not valid:
                return False
            
            stack.pop()
        
        return len(stack) == 0
