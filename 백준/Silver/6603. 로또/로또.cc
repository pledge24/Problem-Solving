#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<int> sequence;

void Backtracking(vector<int>& v1, int idx){
    if(sequence.size() == 6){
        for(int elem : sequence)
            cout << elem << ' ';
        cout << '\n';

        return;
    }

    for(int i = idx; i < v1.size(); i++){
        sequence.push_back(v1[i]);
        Backtracking(v1, i+1);
        sequence.pop_back();
    }
}

bool startTest(){
    int N; cin >> N;

    if(N == 0) return false;

    vector<int> v1(N);
    for(int i = 0; i < N; i++){
        cin >> v1[i];
    }

    sort(v1.begin(), v1.end());
  
    Backtracking(v1, 0);
    cout << '\n';

    sequence.clear();

    return true;
}

int main(void){
    // fastio;

    while(startTest()){}

    return 0;
}