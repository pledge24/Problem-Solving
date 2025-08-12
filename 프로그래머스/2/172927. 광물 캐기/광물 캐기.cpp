#include <bits/stdc++.h>

#define INF 100'000'000

using namespace std;

// 1. 곡괭이는 5번을 사용하면 더 이상 사용할 수 없다. (곡괭이의 종류는 [다이아, 철, 돌]만 있다. 각각 "최대 5개")
// 2. 한 번 사용한 곡괭이는 5번을 연달아 사용해야한다.
// 3. 광물은 순서대로만 캘 수 있다.
// 4. 모든 광물을 캐거나, 모든 곡괭이를 사용할때까지 반복한다.
// -> 최소 피로도는?

// 광물의 최대 개수 "50" -> 최대 10개의 곡괭이 사용 가능 3^10 = 약 81,000

map<string, int> nameMappings = {make_pair("diamond", 0), make_pair("iron", 1), make_pair("stone", 2)};

int fatigueTable[3][3] = {
    {1, 1, 1},
    {5, 1, 1},
    {25, 5, 1},    
};

void DfsUtil(vector<int>& picks, vector<string>& minerals, vector<int>& sequence, int pickAxeN, int& answer){
    // 종료 조건.
    if(sequence.size() == pickAxeN){
        
        // DEBUG: print
        // for(auto elem : sequence){
        //     cout << elem << " ";
        // }
        // cout << '\n';
        
        int fatigue = 0;
        for(int i = 0; i < minerals.size(); i++){
            if(i / 5 >= pickAxeN)
                break;
            int pickAxeId = sequence[i / 5];
            int mineralId = nameMappings[minerals[i]];
            
            fatigue += fatigueTable[pickAxeId][mineralId];
        }
        
        // cout << "fatigue: " << fatigue << '\n';
        answer = min(answer, fatigue);
        
        return;
    }
    
    for(int i = 0; i < picks.size(); i++){
        if(picks[i] <= 0)
            continue;
        
        picks[i]--;
        sequence.push_back(i);
        
        DfsUtil(picks, minerals, sequence, pickAxeN, answer);
        
        picks[i]++;
        sequence.pop_back();
    }
}

// 곡괭이를 사용한 순서가 중요.
void Dfs(vector<int>& picks, vector<string>& minerals, int& answer){
    int pickAxeN = 0;
    for(auto elem : picks)
        pickAxeN += elem;
    
    vector<int> sequence;
    DfsUtil(picks, minerals, sequence, pickAxeN, answer);
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = INF;
    
    Dfs(picks, minerals, answer);
    
    return answer;
}