#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

void applyPosition(vector<int>& v1, int h, int tallerN){
    int n = 0;
    for(int i = 0; i < v1.size(); i++){
        if(n == tallerN && v1[i] == 0){
            v1[i] = h;
            return;
        }

        if(v1[i] == 0)
            n++;
    }

    return;
}

int main(void){
    fastio;
    int N; cin >> N;

    vector<int> v1(N);
    for(int i = 1; i <= N; i++){
        int num; cin >> num;
        applyPosition(v1, i, num);
    }

    for(int elem : v1){
        cout << elem << ' ';
    }
    cout << '\n';
    
    return 0;
}