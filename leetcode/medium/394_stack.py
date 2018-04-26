class Solution(object):
    def decodeString(self, s):
        stack = []
        cur_digit = ''
        cur_str = ''

        for c in s:
            if c == '[':
                stack.append((cur_str,int(cur_digit))
                cur_str = ''
                cur_digit = ''
            elif c == ']':
                prev_str,num = stack.pop()
                cur_str = prev_str + num * cur_str
            elif c.isdigit():
                cur_digit += c
            else:
                cur_str += c

        return cur_str
