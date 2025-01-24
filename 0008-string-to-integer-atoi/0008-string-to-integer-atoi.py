class Solution:
    def myAtoi(self, s: str) -> int:
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31
        i = 0
        n = len(s)
        sign = 1
        num = 0
        while i < n and s[i] == ' ':
            i += 1
        if i >= n:
            return 0
        if s[i] == '+':
            sign = 1
            i += 1
        elif s[i] == '-':
            sign = -1
            i += 1
        while i < n and s[i] == '0':
            i += 1
        digits_read = 0
        while i < n and s[i].isdigit():
            num = num * 10 + int(s[i])
            i += 1
            digits_read += 1
            if sign * num >= INT_MAX:
                return INT_MAX
            if sign * num <= INT_MIN:
                return INT_MIN
        if digits_read == 0:
            return 0
        num *= sign
        if num < INT_MIN:
            return INT_MIN
        if num > INT_MAX:
            return INT_MAX
        return num