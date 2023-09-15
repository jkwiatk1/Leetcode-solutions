# Intuition
First do:
1. 1-Two Sum
2. 167-Two Sum II

# Approach
The approach to solving this problem involves sorting the input array and then iterating through it. For each element at index i, we initialize two pointers, `left` and `right`, which represent the remaining elements in the array. We calculate the sum of the current triplet `sum = nums[i] + nums[left] + nums[right]`.

If sum is equal to zero, it means we have found a triplet that meets the criteria. To ensure uniqueness, we check if this triplet is already in our set of `unique_triplets`. If it's not in the set, we add it to both the set and the result vector `triplets`.

Additionally, we skip duplicate elements in the array by advancing the `left` pointer when we find duplicates and continue searching for unique triplets.

We repeat this process for all elements in the array, and at the end, we return the vector `triplets` containing all unique triplets that sum up to zero.

# Complexity
**Time complexity: O(n^2)** - The main loop runs in O(n) time, and for each element, we perform a two-pointer search that also takes O(n) time.
**Space complexity: O(n)** - We use extra space to store the unique triplets in the `unique_triplets` set. In the worst case, when there are many unique triplets, this space complexity is O(n).