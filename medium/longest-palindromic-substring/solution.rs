use std::cmp;

impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        fn expand_around_center(s: &Vec<char>, left: usize, right: usize) -> usize {
            let mut l = left as i32;
            let mut r = right as i32;
            while l >= 0 && r < s.len() as i32 && s[l as usize] == s[r as usize] {
                l -= 1;
                r += 1;
            }
            (r - l - 1) as usize
        }

        let s: Vec<char> = s.chars().collect();
        let mut start = 0;
        let mut end = 0;

        for i in 0..s.len() {
            let len1 = expand_around_center(&s, i, i);
            let len2 = expand_around_center(&s, i, i + 1);

            let len = cmp::max(len1, len2);

            
            if len > end - start { // length of the palindrome is greater than the current palindrome -> update the start and end
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        s[start..=end].iter().collect()
    }
}