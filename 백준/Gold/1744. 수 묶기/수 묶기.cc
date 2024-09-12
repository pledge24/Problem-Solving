#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int N; cin >> N;

    vector<int> positive_vec;
    vector<int> negative_vec;
    int zero_cnt = 0;

    int num;
    for(int i = 0; i < N; i++){
        cin >> num;

        if(num > 0) positive_vec.push_back(num);
        else if(num < 0) negative_vec.push_back(num);
        else zero_cnt++;
    }

    sort(positive_vec.begin(), positive_vec.end(), greater<int>());
    sort(negative_vec.begin(), negative_vec.end(), less<int>());

    int ans = 0;
    int temp = 0;
    for(int i = 0; i < positive_vec.size(); i++){
        if(i % 2) {
            if(temp == 1 || positive_vec[i] == 1){
                ans += temp + positive_vec[i];
            }
            else ans += temp * positive_vec[i];
            
            temp = 0;
        }
        else temp = positive_vec[i];
    }
    ans += temp;

    temp = 0;
    for(int i = 0; i < negative_vec.size(); i++){
        if(i % 2) {
            ans += temp * negative_vec[i];
            temp = 0;
        }
        else temp = negative_vec[i];
    }
    ans += !zero_cnt * temp;

    cout << ans << '\n';
}