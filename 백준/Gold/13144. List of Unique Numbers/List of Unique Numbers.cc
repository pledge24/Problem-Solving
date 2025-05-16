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

    long long cnt = 0;

    set<int> s1;
    int end = 0; 
    for(int start = 0; start <= end; start++){
        while(end < v1.size() && s1.find(v1[end]) == s1.end()){
            s1.insert(v1[end]);
            end++;
        }

        cnt += s1.size();

        // for(auto elem : s1)
        //     cout << elem << ' ';
        // cout << '\n';

        s1.erase(v1[start]);
    }

    cout << cnt << '\n';

    return 0;
}