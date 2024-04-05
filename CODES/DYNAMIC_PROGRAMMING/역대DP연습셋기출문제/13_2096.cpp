#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define LEFT 0
#define MID 1
#define RIGHT 2
using namespace std;

int main() {
	fastio;
    int N; cin >> N;

    vector<int> num_list(3);
    
    vector<int>prev_max(3);
    vector<int>curr_max(3);

    vector<int>prev_min(3);
    vector<int>curr_min(3);

    // initialization
    cin >> num_list[LEFT] >> num_list[MID] >> num_list[RIGHT];
    for(int i = 0; i < 3; i++){
        prev_max[i] = num_list[i];
        prev_min[i] = num_list[i];
    } 

    for(int i=2; i<=N; i++){
        cin >> num_list[LEFT] >> num_list[MID] >> num_list[RIGHT];

        curr_max[LEFT] = max(prev_max[LEFT], prev_max[MID]) + num_list[LEFT];
        curr_max[MID] = max({prev_max[LEFT], prev_max[MID], prev_max[RIGHT]}) + num_list[MID];
        curr_max[RIGHT] = max(prev_max[RIGHT], prev_max[MID]) + num_list[RIGHT];

        prev_max = curr_max;

        curr_min[LEFT] = min(prev_min[LEFT], prev_min[MID]) + num_list[LEFT];
        curr_min[MID] = min({prev_min[LEFT], prev_min[MID], prev_min[RIGHT]}) + num_list[MID];
        curr_min[RIGHT] = min(prev_min[RIGHT], prev_min[MID]) + num_list[RIGHT];

        prev_min = curr_min;
    }

    int ans_max =(N != 1) ? *max_element(curr_max.begin(), curr_max.end()) : *max_element(prev_max.begin(), prev_max.end());
    int ans_min = (N != 1) ? *min_element(curr_min.begin(), curr_min.end()) : *min_element(prev_min.begin(), prev_min.end()); 

    cout << ans_max << " " << ans_min << '\n';
}