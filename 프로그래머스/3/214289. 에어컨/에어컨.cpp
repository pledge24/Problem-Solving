#include <bits/stdc++.h>

#define MAX_TEMPERATURE 40
#define MIN_TEMPERATURE -10

using namespace std;

// 실내공조 제어 시스템
// 1) 희망온도 설정 O
// 1-1) 실내온도와 희망온도가 다르다면, "1분 뒤 실내온도와 가까워지는 방향으로 1도 상승" => a만큼 전력소모
// 1-2) 실내온도와 희망온도가 같다면, 실내온도는 변하지 않는다. => b만큼 전력소모
// 2) 희망온도 설정 X
// 2-1) 0만큼 전력소모 (1분 뒤 "실외온도"와 가까워지는 방향으로 1도 상승)
// => 승객이 탑승 중일때 t1~t2도 사이를 유지할때 드는 최소 소비전력은?

bool inRange(int x, int t1, int t2){
    return t1 <= x && x <= t2;
}

bool isValid(int t, int onboard, int t1, int t2){
    // 올바른 범위에 해당하는 온도인가?
    if(!inRange(t, MIN_TEMPERATURE, MAX_TEMPERATURE)){
        return false;
    }
    
    // onboard에 해당하는 온도인가?
    if(onboard == 1 && !inRange(t, t1, t2)){
        return false;
    }
        
    return true;
}

// +) 처음 실외온도는 실내온도와 같다.
// +) 0초(onboard[0])에는 승객이 탑승하지 않는다.
int solution(int temperature/*실외 온도*/, int t1, int t2, int a, int b, vector<int> onboard) {
    int answer = 0;
    int t = onboard.size();
    
    vector<map<int, int>> DP(t+1); // <temp, minCost>
    // init
    DP[0].insert(make_pair(temperature, 0));
    for(int i = 0; i < t; i++){
        map<int, int>& m1 = DP[i];
        
        for(auto elem : m1){
            int curTemp = elem.first;
            int curCost = elem.second;
            
            // 현재 <온도, 비용>에 선택할 수 있는 네 가지 경우
            // 1. 에어컨을 틀어서 1도 올린다. + a 만큼 전력 소모
            if(isValid(curTemp+1, onboard[i], t1, t2)){
                if(DP[i+1].find(curTemp+1) == DP[i+1].end())
                    DP[i+1][curTemp+1] = curCost + a;
                else
                    DP[i+1][curTemp+1] = min(DP[i+1][curTemp+1], curCost + a);
            }
            
            
            // 2. 에어컨을 틀어서 1도 내린다. + a 만큼 전력 소모
            if(isValid(curTemp-1, onboard[i], t1, t2)){
                if(DP[i+1].find(curTemp-1) == DP[i+1].end())
                    DP[i+1][curTemp-1] = curCost + a;
                else
                    DP[i+1][curTemp-1] = min(DP[i+1][curTemp-1], curCost + a);
            }
            
            
            // 3. 에어컨을 틀어서 1도 유지한다. + b 만큼 전력 소모
            if(isValid(curTemp, onboard[i], t1, t2)){
                int nextTemp = curTemp;
                if(DP[i+1].find(nextTemp) == DP[i+1].end())
                    DP[i+1][nextTemp] = curCost + b;
                else
                    DP[i+1][nextTemp] = min(DP[i+1][nextTemp], curCost + b);
            }
            
            
            // 4. 에어컨을 끈다. + 0 만큼 전력 소모
            int nextTemp;
            if(curTemp < temperature)
                nextTemp = curTemp + 1;
            else if(curTemp > temperature)
                nextTemp = curTemp - 1;
            else
                nextTemp = curTemp;
            
            if(isValid(nextTemp, onboard[i], t1, t2)){
                if(DP[i+1].find(nextTemp) == DP[i+1].end())
                    DP[i+1][nextTemp] = curCost;
                else
                    DP[i+1][nextTemp] = min(DP[i+1][nextTemp], curCost);
            }
            

        }
        
        // for(auto elem : DP[i])
        //     cout << elem.first << " " << elem.second << '\n';
        // cout << '\n';
    }
    
//     for(auto elem : DP[t])
//         cout << elem.first << " " << elem.second << '\n';
//     cout << '\n';
    
    pair<int, int> minP = *min_element(DP[t].begin(), DP[t].end(), [](const pair<int, int> p1, const pair<int, int> p2){
        return p1.second < p2.second;
    });
    
    answer = minP.second;
    
    return answer;
}