# Approach
The approach to solving this problem is to use two pointers, `i` and `j`, to represent the current window of characters in the string `s`. We maintain two frequency maps, `freqS` and `freqT`, to keep track of the characters in the current window and the characters in string `t`, respectively.

1. Initialize the variables:
   - `best_i` and `best_j` to keep track of the best window.
   - `minLen` to store the minimum window length.
   - `freqS_size` to keep track of the number of unique characters in the current window.
   - Initialize the frequency map `freqT` for characters `t`, respectively.

2. Iterate through string `s` using the two pointers `i` and `j`:
   - Increment the frequency of `s[j]` in `freqS`.
   - Check if `s[j]` is in `freqT` and if its frequency in `freqS` is equal to its frequency in `freqT`. If both conditions are met, increment `freqS_size`.

3. While `freqS_size` is equal to the size of `freqT` (meaning all necessary characters are in the current window):
   - Update the best window if the current window is shorter.
   - Decrement the frequency of `s[i]` in `freqS`.
   - Check if `s[i]` is in `freqT` and if its frequency in `freqS` is less than its frequency in `freqT`. If both conditions are met, decrement `freqS_size`.
   - Increment `i` to move the left pointer of the window.

4. Continue to increment `j` to expand the window and repeat steps 2 and 3 until `j` reaches the end of `s`.

5. If `minLen` is still equal to `INT_MAX`, return an empty string as no valid window was found. Otherwise, return the substring of `s` from `best_i` to `best_j`.


# Complexity
- **Time complexity**: The two-pointer approach runs in O(N) time, where N is the length of string `s`.
- **Space complexity**: The space complexity is O(K), where K is the number of unique characters in string `t`. This is due to the space required for the frequency maps `freqS` and `freqT`.