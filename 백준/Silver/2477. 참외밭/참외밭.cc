#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 5

using namespace std;
using edgeData = pair<int, int>; // dir, len

// 동서남북(idx 0은 안씀)
int dx[DIR] = {0, 0, 0, 1, -1};
int dy[DIR] = {0, 1, -1, 0, 0};

int main(void){
    fastio;
    int unit; cin >> unit;

    const int angleN = 6;

    vector<edgeData> edgeList;
    int maxW = 0;
    int maxH = 0;
    int maxWIdx = -1;
    int maxHIdx = -1;
    for(int i = 0; i < angleN; i++){
        int dir, len; cin >> dir >> len;

        edgeList.push_back(make_pair(dir, len));

        if(dir <= 2 && maxW < len){
            maxW = len;
            maxWIdx = i;
        }
        else if(dir > 2 && maxH < len){
            maxH = len;
            maxHIdx = i;
        }
    }

    int startIdx = abs(maxWIdx-maxHIdx) == 1 ? max(maxWIdx, maxHIdx) : min(maxWIdx, maxHIdx);

    // cout << "startOdx: " << startIdx << '\n';
    int len1 = edgeList[(startIdx+2) % 6].second;
    int len2 = edgeList[(startIdx+3) % 6].second;

    // cout << len1 << " " << len2 << '\n';

    int subArea = len1*len2;

    int totalArea = edgeList[maxWIdx].second * edgeList[maxHIdx].second - subArea;

    cout << totalArea*unit << '\n';

    return 0;
}