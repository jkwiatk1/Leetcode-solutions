#include <vector>
#include <iostream>


class Solution {
public:
    int totalFruit(std::vector<int>& fruits) {
        int basketTemp = 0;
        int basketMax = 0;
        int newFruitTypeIndex = 0;
        int tempFruit1 = 0;
        int tempFruit2 = 0;
        int h = 0;
        int beforeFruit = 0;

        for(int i = 0; i < fruits.size(); i++){
            if(i == 0){beforeFruit = tempFruit1 = fruits[i]; }

            if((tempFruit1 != fruits[i] && tempFruit2 != fruits[i] && h == 0)){
                tempFruit2 = fruits[i];
                newFruitTypeIndex = i; 
                basketTemp++;
                h++;
            }
            else if(tempFruit1 == fruits[i] || tempFruit2 == fruits[i]){
                basketTemp++;
                if(beforeFruit != fruits[i]){
                    newFruitTypeIndex = i; 
                    h++;
                }
            }

            if(tempFruit1 != fruits[i] && tempFruit2 != fruits[i] && h >= 1){
                tempFruit1 = fruits[i];
                i = newFruitTypeIndex - 1;
                basketTemp = 0;
                h = 0;
            }

            if(basketMax < basketTemp){basketMax = basketTemp;}
            beforeFruit = fruits[i];
        }
        return basketMax;
    }
};

int main(){
    std::vector<int> FruitTrees{3,3,3,1,2,1,1,2,3,3,4};
    int BasketMax2 = 0;

    Solution solution;
    BasketMax2 = solution.totalFruit(FruitTrees);
    std::cout << "\n" << BasketMax2;

    return 0;
}