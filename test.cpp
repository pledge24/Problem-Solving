#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    
    queue<int> q1({1, 2, 3, 4, 5, 6});
    queue<int> q2;

    q1.push(1);

    cout << (q1 == q2) << '\n';
    cout << q1.size() << '\n';

    q1 = queue<int>();

    cout << q1.size() << '\n';
    
   
}