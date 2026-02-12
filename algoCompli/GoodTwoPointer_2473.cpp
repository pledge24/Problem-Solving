#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

pair<int, int> calcMinGap(vector<int>& liquids, int idx){
    pair<int, int> minCombi = make_pair(-1, -1);
    int offset = liquids[idx];
    int minGap = INT32_MAX;

    // start ----> 
    int start = 0;
    int end = liquids.size() - 1;

    start += (start == idx);
    end -= (end == idx);

    while(start < end){
        // 갱신 조건.
        int gap = liquids[start] + liquids[end] + liquids[idx];
        if(abs(gap) < minGap){
            minGap = abs(gap);
            minCombi = make_pair(start, end);
        }

        // 시작을 옮기면 값은 커진다.
        // 끝을 옮기면 값은 작아진다.
        // => 값이 컸다면 끝을 옮기고, 작았다면 시작을 옮긴다.
        if(gap > 0)
            end -= 1 + (end-1 == idx);
        else if(gap < 0)
            start += 1 + (start+1 == idx);
        else
            break;

    }

    // printf("idx: (%d %d %d) => (%d %d %d) = %d\n", 
    //     idx, minCombi.first, minCombi.second, 
    //     liquids[idx], liquids[minCombi.first], liquids[minCombi.second], 
    //     minGap
    // );

    return minCombi;
}

int main(void){
    fastio;
    int N; cin >> N;
    vector<int> liquids(N);
    for(int i = 0; i < N; i++){
        cin >> liquids[i];
    }

    sort(liquids.begin(), liquids.end());

    int minGap = INT32_MAX;
    vector<int> ans;
    for(int i = 0; i < N; i++){
        pair<int, int> p1 = calcMinGap(liquids, i);
        
        int gap = abs(liquids[i] + liquids[p1.first] + liquids[p1.second]);
        if(gap < minGap){
            minGap = gap;
            ans = {liquids[i], liquids[p1.first], liquids[p1.second]};
        }
    }

    sort(ans.begin(), ans.end());
    for(int elem : ans)
        cout << elem << ' ';
    cout << '\n';

    return 0;
}