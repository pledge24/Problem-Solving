#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N, M; cin >> N >> M;

    vector<int> v1(N);
    vector<int> v2(M);
    for(int i = 0; i < N; i++){
        cin >> v1[i];
    }

    for(int i = 0; i < M; i++){
        cin >> v2[i];
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    vector<int> ans;
    for(int i = 0; i < N; i++){
        if(!binary_search(v2.begin(), v2.end(), v1[i])){
            // cout << "Pass: " << v1[i] << '\n';
            ans.push_back(v1[i]);
        }
    }

    cout << ans.size() << '\n';

    if(!ans.empty())
        sort(ans.begin(), ans.end());

    for(int elem : ans)
        cout << elem << ' ';
    cout << '\n';



    return 0;
}