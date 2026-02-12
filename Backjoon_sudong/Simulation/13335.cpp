// n개의 트럭이 지나간다
// w개의 트럭만이 다리 위로 지나갈 수 있다.
// 각 트럭은 하나위 단위 시간에 하나의 단위길이 만큼 이동
// 다리는 L보다 작거나 같은 무게 합을 버틴다.

#include <bits/stdc++.h>

#define fastio cin.tie(nullptr)->sync_with_stdio(false)

using namespace std;

void simulate(queue<int>& Trucks, int& t, int W, int L){
    deque<int> dq(W);
    queue<int> Bridge(dq);

    int curL = 0;
    while(!Trucks.empty()){
        int curW = Trucks.front(); Trucks.pop();

        // 새로운 트럭이 들어올 수 있을때까지 반복
        while(curL + curW - Bridge.front() > L){
            t++;
            curL -= Bridge.front();
            Bridge.pop();
            Bridge.push(0);
            // cout << "curL : " << curL << '\n';
        }

        t++;
        curL -= Bridge.front();
        Bridge.pop();

        curL += curW;
        Bridge.push(curW);
        // cout << "curL : " << curL << '\n';
    }

    while(curL > 0){
        t++;
        curL -= Bridge.front();
        Bridge.pop();
        // cout << "curL : " << curL << '\n';
    }
}

int main(void){
    fastio;
    int N, W, L; cin >> N >> W >> L;

    queue<int> Trucks;
    for(int i = 0; i < N; i++){
        int weight; cin >> weight;
        Trucks.push(weight);
    }

    int t = 0;
    simulate(Trucks, t, W, L);

    cout << t << '\n';

    return 0;
}