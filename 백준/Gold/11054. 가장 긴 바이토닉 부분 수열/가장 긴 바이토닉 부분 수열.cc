#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<int> v1; 

int main() {
	fastio;
    int N; cin >> N;

    v1.resize(N+1);
    vector<int> dp(N+1), A(N+1), P(N+1), PN(N+1); 
    
    int num, len = 0;
    for(int i = 1; i <= N; i++){
        cin >> num;
        v1[i] = num;

        auto idx = lower_bound(A.begin()+1, A.begin()+len+1, num);
        *idx = num;
        P[i] = distance(A.begin(), idx);
        if(idx == A.begin()+len+1){
            len++;
        }
    }

    reverse(v1.begin()+1, v1.end());
    A.clear();
    len = 0;
    for(int i = 1; i <= N; i++){
        num = v1[i];

        auto idx = lower_bound(A.begin()+1, A.begin()+len+1, num);
        *idx = num;
        PN[i] = distance(A.begin(), idx);
        if(idx == A.begin()+len+1){
            len++;
        }
    }

    // for(int i = 1; i <= N; i++){
    //     cout << P[i] << ' ';
    // }
    // cout << '\n';

    // for(int i = 1; i <= N; i++){
    //     cout << PN[i] << ' ';
    // }

    // cout << '\n';

    int ans = 0;
    for(int i = 1; i <= N; i++){
        ans = max(ans, P[i] + PN[1 + N-i] - 1);
    }
    
    cout << ans << '\n';
}

