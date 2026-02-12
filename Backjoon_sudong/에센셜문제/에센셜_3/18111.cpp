#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio

using namespace std;

int main(void){
    fastio;
    int N, M, B; cin >> N >> M >> B;

    const int MAXHEIGHT = 256;
    vector<int> heights(MAXHEIGHT+1);
    for(int i = 0; i < N*M; i++){
        int h; cin >> h;
        heights[h]++;
    }

    // 내려가며 체크하는 방식을 채택

    // 각 높이마다 존재하는 블록의 개수
    int lowHBlocks = N*M;
    int existBlocks = 0;
    int totalBlocks = 0;    // 이미 설치된 블록
    vector<int> blocks(MAXHEIGHT+1);
    for(int i = MAXHEIGHT; i >= 0; i--){
        int curHBlocks = heights[i];

        existBlocks += curHBlocks;
        blocks[i] = existBlocks; 

        totalBlocks += existBlocks;
    }


    int removedBlocks = 0;
    int neededBlocks = N*M*(MAXHEIGHT+1) - totalBlocks;
    int minCost = INT32_MAX;
    int maxHeight = -1;
    for(int i = MAXHEIGHT; i >= 0; i--){
        int haveBlocks = B + removedBlocks;

        // 가지고 있는 블록이 충분한 경우, 비용을 계산
        if(haveBlocks >= neededBlocks){
            int cost = neededBlocks + removedBlocks*2;
            if(cost < minCost){
                minCost = cost;
                maxHeight = i;
            }
        }

        // 다음 높이에서 제거한 블록과 필요한 블록 갱신
        removedBlocks += blocks[i];
        neededBlocks -= N*M - blocks[i];
    }

    cout << minCost << " " << maxHeight << '\n';

    return 0;
}