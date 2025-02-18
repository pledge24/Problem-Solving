#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

void startTest(){
    int money; cin >> money;
    
    vector<int> v1(4);
    vector<int> moneyList = {25, 10, 5, 1};

    for(int i = 0; i < 4; i++){
        while(money >= moneyList[i]){
            v1[i]++;
            money -= moneyList[i];
        }
    }

    for(int elem : v1){
        cout << elem << ' ';
    }
    cout << '\n';
}

int main() {
	fastio;
    int T; cin >> T;

    for(int i = 0; i < T; i++){
        startTest();
    }

    return 0;
}