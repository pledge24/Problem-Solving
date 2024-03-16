#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;

    vector<int> v1(9);
    for(int i = 1; i <= 8; i++){
        cin >> v1[i];  
    }

    int asc_cnt = 0;
    int desc_cnt = 0;
    for(int i = 2; i <= 8; i++){
        if(v1[i] - v1[i-1] == 1) asc_cnt++;
        else if(v1[i] - v1[i-1] == -1) desc_cnt++;
    }

    if(asc_cnt == 7){
        cout << "ascending" << '\n';
    }
    else if(desc_cnt == 7){
        cout << "descending" << '\n';
    }
    else{
        cout << "mixed" << '\n';
    }
}