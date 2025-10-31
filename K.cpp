#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
int main(){
    int n, capacity;
    cin >> n >> capacity;
    vector<int> v(n);  // 用于记录每个物体的体积
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<int> dp(capacity + 1, 0); // dp[i] 表示恰好装满容量为i的背包的方案数
    dp[0] = 1;  // 装满容量为0的背包方案数是1
    for(int i = 0; i < n; i++){
        int cur_v = v[i];  // 当前物体的体积
        for(int j = capacity; j >= cur_v; j--){
            dp[j] = (dp[j] + dp[j - cur_v]) % MOD; // 放或不放第i个物体的方案数加起来：dp[j]对应考虑前i-1个物体，装满容量为j的背包的方案数，dp[j - cur_v]对应如果确定把第i个物体放进去，则前i-1个物体装满容量为j- cur_v的背包的方案数
        }
    }
    cout << dp[capacity];
}