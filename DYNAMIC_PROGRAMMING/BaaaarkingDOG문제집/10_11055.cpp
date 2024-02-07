#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int N; cin >> N;
    vector<int> v1(N+1);

    for(int i=1; i<=N; i++){
        cin >> v1[i];       
    }
    
    vector<int> sum_num(1001);

    for(int i=1; i<=N; i++){
        int cur_num = v1[i];
        sum_num[cur_num] = *max_element(sum_num.begin(), sum_num.begin() + cur_num) + cur_num;   
        //printf("sum_num: %d\n", sum_num[cur_num]);               
    }

    cout << *max_element(sum_num.begin(), sum_num.end()) << '\n';         
}