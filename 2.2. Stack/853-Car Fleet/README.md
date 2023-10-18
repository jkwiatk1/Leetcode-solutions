# Approach
1. Create a vector of pairs (position, time) for each car.
2. Calculate the time needed for each car to reach the target.
3. Sort the cars in decreasing order of their positions.
4. Initialize fleets to 0 and current_time to 0.
5. Iterate through the sorted cars:
    - If the time to reach the target is greater than the current_time:
        - Increment fleets by 1 (a new fleet is formed).
        - Update current_time with the car's time.
6. Return the total number of fleets.


# Complexity
- **Time complexity**: **O(n * log(n))**, where n is the number of cars. The most time-consuming step is the sorting of cars.
- **Space complexity**: **O(n)** for storing the vector of pairs (`position`, `time`) and other variables.