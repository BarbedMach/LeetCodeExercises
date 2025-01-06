/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    let result = 0;
    let sign = x < 0 ? -1 : 1;
    x = Math.abs(x);

    while (x !== 0) {
        let last_digit = x % 10;
        x = Math.floor(x / 10);

        // Check for overflow and underflow before updating the result
        if (result > Math.pow(2, 31) / 10 || (result === Math.pow(2, 31) / 10 && digit > 7)) {
            return 0; // Overflow case
        }
        if (result < Math.pow(-2, 31) / 10 || (result === Math.pow(-2, 31) / 10 && digit < -8)) {
            return 0; // Underflow case
        }

        result = result * 10 + last_digit;
    }

    return result * sign;
};