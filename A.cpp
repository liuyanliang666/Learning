/* 总体思路：如果直接暴力枚举的话，时间复杂度会达到O(n²)，会超时，所以考虑用分置合并的策略
   降低时间复杂度。考虑在归并排序时合并的同时统计逆序对的个数，将左右两个数组合并的时候如果
   发现v[l] > v[r]，则说明这里有逆序对，并且个数为 mid - l + 1，这样归并排序完成后，也就
   自然完成了逆序对的统计。
*/
#include<bits/stdc++.h>
using namespace std;

unsigned long long cnt = 0;

// 将两个有序区间:[left,mid]和[mid + 1, right]合并起来,并且在合并的时候统计逆序对的数目
void merge(vector<int>& v, int left, int mid, int right){
    int l = left;
    int r = mid + 1;
    vector<int> tmp;  // 用来临时存储合并后的有序数组
    while(l <= mid && r <= right){
        if(v[l] <= v[r]){
            tmp.emplace_back(v[l++]);
        }else{
            // 此时对应逆序对的情况
            cnt += (mid - l + 1);
            tmp.emplace_back(v[r++]);
        }
    }
    while(l <= mid) tmp.emplace_back(v[l++]);
    while(r <= right) tmp.emplace_back(v[r++]);
    // 将原数字写回原数组
    for(int i = 0; i < tmp.size(); i++){
        v[left + i] = tmp[i];
    }
}

void merge_sort(vector<int>& v, int left , int right){
    if(left >= right) return;
    int mid = (left + right) / 2;
    merge_sort(v, left, mid);
    merge_sort(v, mid + 1, right);
    merge(v, left, mid, right);
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    merge_sort(v, 0, n - 1);
    cout << cnt;
    return 0;
}