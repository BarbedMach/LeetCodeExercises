class Solution {
    fun myAtoi(s: String): Int {
        var i = 0
        while (i < s.length && s[i] == ' ') {
            i++
        }

        if (i == s.length) {
            return 0
        }

        var sign = 1
        if (s[i] == '+') {
            i++
        } else if (s[i] == '-') {
            sign = -1
            i++
        }

        var result = 0

        while (i < s.length && s[i] >= '0' && s[i] <= '9') {
            val digit = s[i] - '0'
            if (result > Int.MAX_VALUE / 10 || (result == Int.MAX_VALUE / 10 && digit > 7)) {
                return if (sign == 1) Int.MAX_VALUE else Int.MIN_VALUE
            }
            result = result * 10 + digit
            i++
        }

        return result * sign
    }
}