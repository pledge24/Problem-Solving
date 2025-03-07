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

    sort(v1.begin(), v1.end());

    int M; cin >> M;
    for(int i = 0; i < M; i++){
        int num; cin >> num;

        int res = binary_search(v1.begin(), v1.end(), num);
        cout << res << ' ';
    }
    cout << '\n';
    
    return 0;
}