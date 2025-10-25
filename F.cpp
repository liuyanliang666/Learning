#include <bits/stdc++.h>
using namespace std;

// int main(){
//     int n;
//     cin >> n;
//     vector<int> v(n);
//     for(int i = 0; i < n; i++){
//         int num;
//         cin >> num;
//         v[i] = num;
//     }
//     if(n == 1){
//         cout << v[0]; 
//         return 0;
//     }
//     vector<int> longest(n, 1);  // longest[i] 表示以v[i]开头的最长上升子序列
//     for(int i = n - 2; i >= 0; i--){
//         int maxVal = 0;
//         for(int j = i + 1; j < n; j++){
//             if(v[j] > v[i]){
//                 maxVal = max(maxVal, longest[j]);
//             }
//         }
//         longest[i] = maxVal + 1; 
//     }
//     int ans = *max_element(longest.begin(), longest.end());
//     cout << ans;
//     return 0;
// }
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v[i] = num;
    }
    if(n == 1){
        cout << v[0]; 
        return 0;
    }
    vector<int> dp; // dp[i] 表示长度为i + 1的递增子序列的末尾元素
    for(int i = 0; i < n; i++){
        if(dp.size() == 0){  // 如果dp现在为空，则直接插入
            dp.emplace_back(v[i]);
        }else{
            auto pos = lower_bound(dp.begin(), dp.end(), v[i]);
            // 如果dp中所有元素都比当前v[i]小，则将v[i]直接加入到dp末尾
            if (pos == dp.end()) {
                dp.push_back(v[i]);
            }
            // 否则，将dp中第一个大于v[i]的元素替换为v[i]
            else {
                *pos = v[i]; // 更新该位置
            }
        }
    }
    cout << dp.size();
    return 0;
}