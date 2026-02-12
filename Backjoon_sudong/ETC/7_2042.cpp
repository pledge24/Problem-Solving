#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

string get_sum(string prev_sum, long long num){
    string upper_num, lower_num;
    
    stoll(prev_sum.substr(1, 19)) + num;
    int carry
    lower_num = 
    return upper_num + lower_num;
}

int main() {
	fastio;
    // int N, M, K; cin >> N >> M >> K;

    // vector<long long> v1(N+1);

    // // input data
    // for(int i = 1; i <= N; i++){
    //     cin >> v1[i];
    // }

    //vector<string> accumulate(N);
    // vector<string> accu_v1(N);
    // for(int i = 1; i <= N; i++){
    //     if(i % 10000 == 1){
    //         accu_v1[i] = to_string(v1[i]);
    //         continue;
    //     }

    //     accu_v1[i] = get_sum(accu_v1[i-1], v1[i]);
    // }
    string s = to_string(LLONG_MAX);
    cout << s << '\n';
    cout << s.substr(1, 18) << '\n';
    cout << s.length() << '\n';
}