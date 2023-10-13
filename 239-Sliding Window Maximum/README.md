# Approach
We use a deque (double-ended queue) to maintain a list of indices within the current sliding window.
As we iterate through the input vector `nums`, we perform the following steps:
1. Remove elements from the front of the deque that are out of the current sliding window (`i - k + 1` is the start of the current window).
2. Remove smaller elements from the back of the deque, ensuring that the front of the deque always contains the index of the maximum element in the current window.
3. Add the current index `i` to the back of the deque.
4. Start adding the maximum value to the `result` vector once the window size is reached.

# Complexity
- **Time complexity**: is **O(n)**, where n is the size of the input vector. The algorithm iterates through the `nums` vector once, performing constant-time operations for each element. 
- **Space complexity**: is **O(n)** as it grows with the size of the input vector. The deque and the `result` vector both use extra space. 
