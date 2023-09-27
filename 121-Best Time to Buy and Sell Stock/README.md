# Approach
The approach involves using two pointers, `left` and `right`, initially set to the first and second days, respectively. We also initialize a variable `max_result` to store the maximum profit found so far.

We iterate through the prices from left to right, and for each pair of prices (prices[left] and prices[right]), we calculate the potential profit (`result`) if we buy at `prices[left]` and sell at `prices[right]`. If `result` is greater than the current `max_result`, we update `max_result` with the new maximum profit.

If `prices[right]` is less than `prices[left]`, it means the stock price has decreased, so we update `left` to `right`, indicating a new potential buying day.

We continue this process until `right` reaches the end of the price array, considering different buying and selling days to maximize the profit.

Finally, we return `max_result` as the maximum profit that can be obtained.

# Complexity
- **Time complexity**: is **O(n)**, where `n` is the number of days or the size of the `prices` vector. We iterate through the prices once from left to right, and the loop runs in linear time.

- **Space complexity**: is **O(1)**, which means it uses a constant amount of extra space regardless of the size of the input. We only use a few integer variables (`left`, `right`, `max_result`, and `result`) to keep track of indices and values, and no additional data structures are created. 