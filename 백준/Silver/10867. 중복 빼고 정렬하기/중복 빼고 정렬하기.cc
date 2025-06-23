#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N; cin >> N;

    set<int> s1;
    for(int i = 0; i < N; i++){
        int num; cin >> num;

        s1.insert(num);
    }

    for(auto elem : s1){
        cout << elem << ' ';
    }
    cout << '\n';

    return 0;
}