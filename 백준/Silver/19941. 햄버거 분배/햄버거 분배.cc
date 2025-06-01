#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N, K; 

bool eatHam(vector<bool>& ham, int idx){
    int start = max(idx-K, 0);
    int end = min(idx+K, N-1);

    for(int i = start; i <= end; i++){
        if(i == idx)
            continue;
        if(ham[i] == true)
        {
            ham[i] = false;
            return true;
        }
    }

    return false;
}

int main(void){
    fastio;
    cin >> N >> K;

    vector<bool> ham(N);
    vector<int> people;
    for(int i = 0; i < N; i++){
        char c; cin >> c;
        if(c == 'H')
            ham[i] = true;
        else
            people.push_back(i);
    }

    int cnt = 0;
    for(int p : people){
        if(eatHam(ham, p))
            cnt++;
    }

    cout << cnt << '\n';

    return 0;
}