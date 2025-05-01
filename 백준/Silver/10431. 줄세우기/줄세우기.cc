#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

void startTest(){
    const int childN = 20;
    int testN; cin >> testN;

    vector<int> order;
    int totalMove = 0;
    for(int i = 0; i < childN; i++){
        int height; cin >> height;
        auto it = lower_bound(order.begin(), order.end(), height);
        if(it == order.end()){
            order.push_back(height);
            continue;
        }

        int pos = it - order.begin();
        totalMove += order.size() - pos;
        order.insert(it, height);
    }

    cout << testN << " " << totalMove << '\n';

}

int main(void){
    fastio;
    int P; cin >> P;

    for(int i = 0; i < P; i++){
        startTest();
    }

    return 0;
}