#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct posData_2170
{
    int beginPos;
    int endPos;
};

bool cmp(const posData_2170& p1, const posData_2170& p2){
    return p1.beginPos < p2.beginPos;
}

int main() {
	fastio;
    int N; cin >> N;

    vector<posData_2170> v1;

    int s, t;
    for(int i = 0; i < N; i++){
        cin >> s >> t;

        v1.push_back({s, t});
    }

    sort(v1.begin(), v1.end(), cmp);
    
    // for(posData_2170 pd : v1){
    //     cout << "posData: " << pd.beginPos << " " << pd.endPos << '\n';
    // }

    int cur_s = v1[0].beginPos, cur_t = v1[0].endPos;
    int holeNum = 0;
    for(int i = 1; i < v1.size(); i++){

        if(cur_t < v1[i].beginPos) holeNum += v1[i].beginPos - cur_t;
        cur_s = min(cur_s, v1[i].beginPos);
        cur_t = max(cur_t, v1[i].endPos);
    }

    //cout << cur_t << " " << cur_s << '\n';
    int ans = cur_t - cur_s;

    cout << ans - holeNum << '\n';
}