#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N; cin >> N;

    vector<int> v1(N);
    for(int i = 0; i < N; i++){
        cin >> v1[i];
    }

    stack<int> s;
    int nextNum = 1;
    vector<char> ans;
    for(int target : v1){
        // In Stack
        if(target < nextNum){
            // 불가능한 경우.
            if(s.top() != target){
                cout << "NO" << '\n';
                return 0;
            }

            s.pop();
            ans.push_back('-');
        }
        // not In Stack
        else{
            while(target >= nextNum){
                s.push(nextNum);
                ans.push_back('+');
                nextNum++;
            }

            s.pop();
            ans.push_back('-');
        }

    }

    for(char c : ans){
        cout << c << '\n';
    }

    return 0;
}