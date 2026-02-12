#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(1);
    pq.push(2);
    pq.push(3);

    cout << pq.top() << '\n';

    return 0;
}