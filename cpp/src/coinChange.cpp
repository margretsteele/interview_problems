#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Coin Change: given coin denominations and a target amount,
// find the fewest coins needed. Return -1 if impossible.
// Write your solution here:

int coinChange(vector<int> const& validCoins, int const& target) {
   vector<int> change(target + 1, target + 1);
   if(target == 0 || validCoins.size() == 0) return -1;
   change[0] = 0;

   // create cost list for every value 1 -> target, using previously calcuated
   // values to prevent duplicate calculations
   for(int i = 1; i <= target; i++) {
       for(int j = 0; j < validCoins.size(); j++) {
           int currentCost = validCoins[j];
           if(currentCost <= i) {
               int newCost = 1 + change[i - currentCost];
               if(newCost < change[i]) {
                   change[i] = newCost;
               }
           }
       }
   }

   // return target
   if(change[target] == target + 1) return -1;
   return change[target];
}


int main() {
    vector<int> coins1 = {1, 5, 10, 25};
    cout << "Coins [1,5,10,25] amount 30: " << coinChange(coins1, 30) << endl;
    // Expected: 2  (25 + 5)

    vector<int> coins2 = {2};
    cout << "Coins [2] amount 3: " << coinChange(coins2, 3) << endl;
    // Expected: -1  (impossible)

    vector<int> coins3 = {1, 3, 4};
    cout << "Coins [1,3,4] amount 6: " << coinChange(coins3, 6) << endl;
    // Expected: 2  (3 + 3)

    return 0;
}
