# Approach
1. First, we create two merging lists: `linkedList` and `linkedList2`, representing two sorted lists with different values.
2. Next, we create a dummy node `dummyNode`, which will facilitate the list merging.
3. We initialize the `tail` pointer as the `dummyNode`, which will point to the last node in our merged list.
4. In a `while` loop, we iterate through both `list1` and `list2`. We choose the smaller of the two nodes from `list1` and `list2` and append it to our merged list using the `tail` pointer.
5. We move the `tail` pointer, pointing to the last node in our merged list.
6. We continue the process until at least one of the lists is exhausted.
7. After merging the remaining nodes from one of the lists, we return the beginning of the merged list, which is in `dummyNode->next`.

# Complexity
- **Time complexity**: It is **O(m + n)**, where `m` and `n` are the number of nodes in lists `list1` and `list2`. We need to traverse both lists to merge them.
- **Space complexity**: It is **O(1)** because we only use a constant amount of additional memory for pointers and auxiliary variables.