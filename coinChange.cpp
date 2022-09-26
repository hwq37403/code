#include <iostream>
#include  <vector>
using namespace std;



int coinChange(vector<int>& coins, int amount) {
        // 数组⼤⼩为 amount + 1，初始值也为 amount + 1
        vector<int> dp(amount + 1, amount + 1);
        // base case
        dp[0] = 0;
        
        for (int i = 0; i < dp.size(); i++) {
                        // 内层 for 在求所有⼦问题 + 1 的最⼩值
                for (int coin : coins) {
                    // ⼦问题⽆解，跳过
                        if (i - coin < 0) continue;
                            dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
}



int main(){
    vector<int> coins={1,5,5,6,10,11};
    int amount=11;

    int res=coinChange(coins,amount);

    cout<<res<<endl;
    return 0;
}
