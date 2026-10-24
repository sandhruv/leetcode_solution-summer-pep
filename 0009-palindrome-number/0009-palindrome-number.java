class Solution {
    public boolean isPalindrome(int x) {
        // Negative numbers are not palindromes (e.g., -121 -> 121-)
        // Numbers ending in 0 (except 0 itself) are not palindromes (e.g., 10 -> 01)
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedNumber = 0;
        // Reverse only half of the number to prevent integer overflow
        while (x > reversedNumber) {
            reversedNumber = reversedNumber * 10 + x % 10;
            x /= 10;
        }

        // When the length is odd, we can get rid of the middle digit by reversedNumber / 10
        // e.g., for 12321, at the end of the loop x = 12, reversedNumber = 123,
        // so reversedNumber / 10 == 12 == x
        return x == reversedNumber || x == reversedNumber / 10;
    }
}