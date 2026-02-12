#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct median_pq{
    bool isOdd = false;     // 홀수개: red, 짝수개: black 의미.
    int median;
    priority_queue<int, vector<int>, greater<int>> pq_higher;
    priority_queue<int, vector<int>, less<int>> pq_lower;
};

median_pq mid_pq;

void setMedian(int num){
    if(mid_pq.isOdd){
        if(mid_pq.median <= num){
            mid_pq.pq_higher.push(num);
        }
        else{
            mid_pq.pq_lower.push(num);
            mid_pq.pq_higher.push(mid_pq.median);

            mid_pq.median = mid_pq.pq_lower.top();
            mid_pq.pq_lower.pop();
        }
    }
    else{
        if(mid_pq.median >= num){
            mid_pq.pq_lower.push(num);
        }
        else{
            mid_pq.pq_lower.push(mid_pq.median);
            mid_pq.pq_higher.push(num);

            mid_pq.median = mid_pq.pq_higher.top();
            mid_pq.pq_higher.pop();
        }
    }

    mid_pq.isOdd = !mid_pq.isOdd;

    return;
}

int main() {
	fastio;
    int N; cin >> N;
    
   

    int num;
    for(int i = 0; i < N; i++){
        cin >> num;

        if(i == 0){
            mid_pq.isOdd = !mid_pq.isOdd;
            mid_pq.median = num;
        }
        else{
            setMedian(num);
        }

        cout << mid_pq.median << '\n';

        //printf("lower: %d, median_v: %d, higher: %d\n", mid_pq.pq_lower.size(), mid_pq.median, mid_pq.pq_higher.size());
    }
}