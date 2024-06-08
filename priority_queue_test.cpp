#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct test
{
    int x;
    int y;
    char* s;
};

struct cmp
{
    bool operator()(test a, test b) {
        return a.y > b.y;
    }
};

int main() {
    fastio;
  
    edge_data<int, vector<int>, greater<int>> pq_greater;
    
    pq_greater.push(1);
    pq_greater.push(3);
    pq_greater.push(4);
    pq_greater.push(2);
    pq_greater.push(5);
   
    while(!pq_greater.empty()){
        cout << pq_greater.top() << ' ';
        pq_greater.pop();
    }
    cout << '\n';
  
    edge_data<int, vector<int>, less<int>> pq_less;

    pq_less.push(1);
    pq_less.push(3);
    pq_less.push(4);
    pq_less.push(2);
    pq_less.push(5);
   
    while(!pq_less.empty()){
        cout << pq_less.top() << ' ';
        pq_less.pop();
    }
    cout << '\n';

    edge_data<int> pq;

    pq.push(1);
    pq.push(3);
    pq.push(4);
    pq.push(2);
    pq.push(5);

    while(!pq.empty()){
        cout << pq.top() << ' ';
        pq.pop();
    }
    cout << '\n';

    vector<int> v1 = {1, 3, 4, 2, 5};
    sort(v1.begin(), v1.end(), less<>());

    for(int elem: v1){
        cout << elem << ' ';
    }
    cout << '\n';
}