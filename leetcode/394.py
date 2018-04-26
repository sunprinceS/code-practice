class Solution:
    def decodeString(self,s):

        ## Need to consider recursive case
        lloc = [pos for pos,char in enumerate(s) if char == '[']
        rloc = [pos+1 for pos,char in enumerate(s) if char == ']']

        ret = ""
        for idx,l in enumerate(lloc):
            r = rloc[idx]
            candidate = s[l+1:r-1]
            if idx == 0:
                digit = int(s[:l])
            else:
                digit = int(s[rloc[idx-1]:l])
            ret += candidate * digit
        return ret
