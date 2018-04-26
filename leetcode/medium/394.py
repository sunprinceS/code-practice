class Solution:
    
    self.pos = 0
    self.s = ""
    self.len_s = 0
    def decode(self):
        ret = ""
        digits = ""
        while(cur_ch != ']'):
            cur_ch = self.s[self.pos]
            self.pos += 1
            if cur_ch == '[':
                times = int(digits)
                ret += decode()*times
            elif cur_ch.isdigit():
                digits += cur_ch
            else:
                ret += cur_ch
        return ret

    def decodeString(self,s):
        self.s = s
        self.len_s = len(s)

        digits = ""
        ret = ""
        while self.pos < self.len_s:
            cur_ch = self.s[self.pos]
            self.pos += 1
            if cur_ch == '[':
                times = int(digits)
                ret += decode()*times
            elif cur_ch.isdigit():
                digits += cur_ch
            else:
                ret += cur_ch
        return ret

## Need to consider recursive case
# lloc = [pos for pos,char in enumerate(s) if char == '[']
# rloc = [pos+1 for pos,char in enumerate(s) if char == ']']

# ret = ""
# for idx,l in enumerate(lloc):
# r = rloc[idx]
# candidate = s[l+1:r-1]
# if idx == 0:
    # digit = int(s[:l])
# else:
    # digit = int(s[rloc[idx-1]:l])
# ret += candidate * digit
# return ret
