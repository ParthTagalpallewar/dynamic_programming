#include <bits/stdc++.h>
using namespace std;

//memorization will be apply to values which are changing
//we can call them as states 

//lets say we are given n = 100 and W = 1000 then we can make dp array of dimension 100 * 1000

int knapsack(vector<int> &weight, vector<int> &value, int W, int n, vector<vector<int>> &t)
{

    // base condition
    if (n == 0 || W == 0)
    {
        return 0;
    }

    //todo: step 2 - if found return 
    if(t[n][W] != -1) return t[n][W];

    // code of choice diagram
    if (weight[n - 1] <= W)
    {

        // profit after including current item
        int choice_1 = value[n - 1] + knapsack(weight, value, W - weight[n - 1], n - 1, t);

        // profit after not choosing current item
        int choice_2 = knapsack(weight, value, W, n - 1, t);

        int ans = max(choice_1, choice_2);
        
        //todo: step3 store state with result
        t[n][W] = ans;

        return ans;
    }
    // weight of current item is greater then space in sack
    else
    {

        // choice after not putting current item in sack
        return knapsack(weight, value, W, n - 1, t);
    }
}

int main()
{
    //todo: step 1 :- declare and initialize ds for memoization
    vector<vector<int>> t(102, vector<int>(1002, -1));
    

    vector<int> weight = {1, 3, 4, 5};
    vector<int> value = {1, 4, 5, 7};
    int W = 7;
    int n = weight.size();

    int max_profit = knapsack(weight, value, W, n, t);

    cout << "Max Profit is " << max_profit << endl;

    return 0;
}