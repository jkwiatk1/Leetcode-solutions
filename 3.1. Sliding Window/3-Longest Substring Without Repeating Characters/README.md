# Approach
The approach used in this code involves iterating through the input string `s` while maintaining a sliding window of unique characters using a `std::set`. The `left_pointer` represents the start of the current substring, and as we move the `right_pointer`, we continuously check for uniqueness. If a character is already in the set, we increment the `left_pointer` to shrink the window until it's unique again. The length of the current unique substring is calculated for each iteration, and the maximum length encountered is stored as the `longest_substring_length`.

# Complexity
- **Time complexity**: is **O(n)**

- **Space complexity**: is **O(n)**