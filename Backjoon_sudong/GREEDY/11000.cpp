#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

bool cmp(vector<int>& a, vector<int>& b){
    return a[0] < b[0];
}

int getMinRooms(vector<vector<int>> meetingTimings){
    sort(meetingTimings.begin(), meetingTimings.end(), [](vector<int>&a, vector<int>&b){
        return a[0] < b[0];
    });
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(meetingTimings[0][1]);

    for(int i = 1; i < meetingTimings.size(); i++){
        if(meetingTimings[i][0] >= minHeap.top()){
            minHeap.pop();
        }

        minHeap.push(meetingTimings[i][1]);
    }

    return minHeap.size();
}

int main() {
	fastio;
    int N; cin >> N;

    vector<vector<int>> meetingTimings(N, vector<int>(2));

    int S, T;
    for(int i = 0; i < N; i++){
        cin >> S >> T;
        meetingTimings[i][0] = S;
        meetingTimings[i][1] = T;
    }

    int ans = getMinRooms(meetingTimings);

    cout << ans << '\n';
}