#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Object {
private:
    int value;
    int weight;
public:
    Object (int value, int weight) : value(value), weight(weight) {}
    int getValue() const {
        return value;
    }

    int getWeight() const{
        return weight;
    }
};

class Knapsack {
private:
    vector<Object> obj;
public:
    Knapsack(vector<Object> obj) : obj(obj){}

    int count() const {
        return obj.size();
    }
    // Without DP
    int solve(int weight, const int n) {
        if (n == 0 || weight == 0) {
            return 0;
        }
        if(obj[n-1].getWeight() > weight) {
            return solve(weight, n-1);
        }
        else {
            return max( solve(weight, n-1),
                        obj[n-1].getValue() + solve(weight - obj[n-1].getWeight(), n-1));
        }
    }

    int non_recursive_solve(int weight, const int n) {
        vector<vector<int>> K (n+1, vector<int>(weight+1));
        for (int i = 0 ; i <= n ; i++) {
            for (int w = 0 ; w <= weight; w++) {
                if(i == 0 || w == 0) {
                    K[i][w] = 0;
                }
                else if(obj[i -1].getWeight() <= w) {
                    K[i][w] = max (K[i-1][w], obj[i-1].getValue() + K[i-1][w - obj[i-1].getWeight()]);
                } else {
                    K[i][w] = K[i-1][w];
                }
            }
        }
        cout<<"DP Matrix "<<endl;
        for (auto i : K) {
            for (int j : i) {
                cout<<j<<" ";
            }
            cout<<endl;
        }
        return K[n][weight];
    }

    int non_recursive_solve_space_optimisation(int weight, const int n) {
        vector<vector<int>> K (2, vector<int>(weight+1));
        //    We know we are always using the the current row or
        // the previous row of the array/vector . Thereby we can
        // improve it further by using a 2D array but with only
        // 2 rows i%2 will be giving the index inside the bounds
        // of 2d array K
        for (int i = 0 ; i <= n ; i++) {
            for (int w = 0 ; w <= weight; w++) {
                if(i == 0 || w == 0) {
                    K[i%2][w] = 0;
                }
                else if(obj[i -1].getWeight() <= w) {
                    K[i%2][w] = max (K[(i-1)%2][w], obj[i-1].getValue() + K[(i-1)%2][w - obj[i-1].getWeight()]);
                } else {
                    K[i%2][w] = K[(i-1)%2][w];
                }
            }
        }
        cout<<"DP Matrix with Space Optimisation"<<endl;
        for (auto i : K) {
            for (int j : i) {
                cout<<j<<" ";
            }
            cout<<endl;
        }
        return K[n%2][weight];
    }

    int non_recursive_1D_solve(int weight, int n ) {
        vector<int> dp(weight+1, 0);
        for (int i = 1 ; i <= n ; i++) {
            for (int w=weight; w >= 0; w--) {
                if(obj[i-1].getWeight() <= w) {
                    dp[w] = max(dp[w], obj[i-1].getValue() + dp[w - obj[i-1].getWeight()]);
                }
            }
        }
        for (auto i : dp) {
                cout<<i<<" ";
        }
        cout<<endl;
        return dp[weight];
    }
};

int main() {
    Knapsack k({Object(5,2),
                    Object(1,3), 
                    Object(4,4), 
                    Object(3,2), 
                    Object(3,1)});
    cout<<k.solve(10, k.count())<<endl;
    cout<<k.non_recursive_solve(10, k.count())<<endl;
    cout<<k.non_recursive_solve_space_optimisation(10, k.count())<<endl;
    cout<<k.non_recursive_1D_solve(10, k.count())<<endl;
}