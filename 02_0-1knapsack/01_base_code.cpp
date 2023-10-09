#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &weight, vector<int> &value, int W, int n){

   //base condition
   if(n == 0 || W == 0){
      return 0;
   }

   //code of choice diagram
   if(weight[n-1] <= W){

      //profit after including current item
      int choice_1 = value[n-1] + knapsack(weight, value, W-weight[n-1], n-1);

      //profit after not choosing current item 
      int choice_2 = knapsack(weight, value, W, n-1);

      return max(choice_1, choice_2);

   }
   //weight of current item is greater then space in sack
   else{

      //choice after not putting current item in sack
      return knapsack(weight, value, W, n - 1);

   }

}

int main(){

   vector<int> weight = {1, 3, 4, 5};
   vector<int> value = {1, 4, 5, 7};
   int W = 7;
   int n = weight.size();

   int max_profit = knapsack(weight, value, W, n);

   cout << "Max Profit is " << max_profit << endl;

   return 0;
}