#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N, K; 

struct Node{
    int durity = 0;
    bool robot = false;
};

void Simulate(vector<Node>& beltNodes, int& cnt){
    int len = N*2;

    int startPos = 0; // 로봇 놓는 시작 위치
    int start = 0;  // 유효한 로봇 idx 시작 위치

    vector<int> robotPos;

    int zeroN = 0;
    while(zeroN < K){
        cnt++;

        // 1) Ratate belt
        startPos = startPos > 0 ? startPos-1 : len-1;
        int endPos = (startPos + N-1) % len;
        if(beltNodes[endPos].robot == true){
            start++;
            beltNodes[endPos].robot = false;
        }
        
        // 2) Move robot
        for(int i = start; i < robotPos.size(); i++){
            int curPos = robotPos[i];
            int nextPos = (robotPos[i]+1) % len;

            if(beltNodes[nextPos].robot == false && beltNodes[nextPos].durity >= 1){
                // move robot to nextNode
                beltNodes[curPos].robot = false; 
                beltNodes[nextPos].robot = true;
                beltNodes[nextPos].durity--;
                zeroN += (beltNodes[nextPos].durity == 0);

                if(nextPos == endPos){
                    start++;
                    beltNodes[nextPos].robot = false;
                }
                else{
                    robotPos[i] = nextPos;
                }
            }
        }

        // 3) Place new robot
        if(beltNodes[startPos].durity >= 1){
            beltNodes[startPos].robot = true;
            beltNodes[startPos].durity--;

            zeroN += (beltNodes[startPos].durity == 0);

            robotPos.push_back(startPos);
        }

        // for(auto elem : beltNodes){
        //     cout << elem.durity << ' ';
        // }
        // cout << '\n';
    }

    return;
}

int main(void){
    fastio;
    cin >> N >> K;

    int len = N*2;
    vector<Node> beltNodes(len);
    for(int i = 0; i < len; i++){
        int d; cin >> d;
        beltNodes[i].durity = d;
    }   

    int ans = 0;
    Simulate(beltNodes, ans);

    cout << ans << '\n';

    return 0;
}