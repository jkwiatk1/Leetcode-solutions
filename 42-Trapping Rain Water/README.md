# Approach
The approach I used involves iterating through the `height` vector to calculate the maximum height encountered from the left and right sides for each building. I started with initializing two arrays, `left_height` and `right_height`, and then calculated the minimum height between them for each position. By subtracting the current height from this minimum height, I determined the amount of water that could be trapped at that position. If the result was negative, it meant that no water could be trapped at that particular position, so I set it to 0. Finally, I summed up the values in the min vector to calculate the total amount of trapped water.

# Complexity
- Time complexity: **O(n)**, where n is the number of buildings in the input `height` vector. We perform a single pass through the `height` vector to calculate the maximum heights from the left and right sides, and then another pass to calculate the trapped water for each position.

- Space complexity: also **O(n)** because we use additional vectors (`left_height`, `right_height`, and `min`) to store intermediate results, each of which has the same size as the input `height` vector.