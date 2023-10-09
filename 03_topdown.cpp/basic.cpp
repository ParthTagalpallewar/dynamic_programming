#include <bits/stdc++.h>
using namespace std;

// todo : Remaining

int knapsack(vector<int> &weight, vector<int> &value, int W, int wn, vector<vector<int>> &t)
{

    int n = 5;
    int m = 8;

    //filling first row
    for(int i=0; i <= m; i++){
        t[0][i] = 0;
    }

    //filling first col
    for(int i=0; i<=n; i++){
        t[i][0] = 0;
    }

    for(int i=1; i <= n; i++){
        for(int j=1; j <= m; j++){

            
            if (weight[i - 1] <= W)
            {

                
                int choice_1 = value[i - 1] + t[i-1] [j-weight[i-1]];

                
                int choice_2 = t[i - 1][j];

                int ans = max(choice_1, choice_2);

                
                t[i][j] = ans;
            }
            // weight of current item is greater then space in sack
            else
            {
                t[i][j] = t[i - 1][j];
                
            }
        }
    }

    return t[n][m];

   
}

int main()
{
    // todo: step 1 :- declare and initialize ds for memoization
    vector<vector<int>> t(102, vector<int>(1002, -1));

    vector<int> weight = {1, 3, 4, 5};
    vector<int> value = {1, 4, 5, 7};
    int W = 7;
    int n = weight.size();

    int max_profit = knapsack(weight, value, W, n, t);

    cout << "Max Profit is " << max_profit << endl;

    return 0;
}