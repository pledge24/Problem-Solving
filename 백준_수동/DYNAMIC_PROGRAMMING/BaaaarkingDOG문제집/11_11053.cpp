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
    
    vector<int> cnt_num(1001);

    for(int i=1; i<=N; i++){
        int cur_num = v1[i];
        cnt_num[cur_num] = *max_element(cnt_num.begin(), cnt_num.begin() + cur_num) + 1;   
        //printf("cur_num: %d, cnt: %d\n", cur_num, cnt_num[cur_num]);               
    }

    cout << *max_element(cnt_num.begin(), cnt_num.end()) << '\n';         
}