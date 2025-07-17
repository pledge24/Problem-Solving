#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int getMostFrequentNum(vector<int>& eratos, int s, int e){
    int MostFrequent = 0;
    int64 MostNum = 0;
    
    // s~e 사이의 수 중, 가장 약수의 개수가 많은 수를 찾는다.
    for(int num = s; num <= e; num++){
        if(MostFrequent < eratos[num]){
            MostFrequent = eratos[num];
            MostNum = num;
        }
    }
      
    return MostNum;
}

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    
    vector<int> eratos(e+1, 1);
    for(int i = 2; i <= e; i++){
        for(int n = 1; i*n <= e; n++){
            eratos[i*n]++;
        }
    }
    
    vector<int> MostFrequentNum(e+1);
    int MostFrequent = 0;
    int64 MostNum = 0;
    for(int num = e; num >= 1; num--){
        if(MostFrequent <= eratos[num]){
            MostFrequent = eratos[num];
            MostNum = num;
        }
        
        MostFrequentNum[num] = MostNum;
    }
    
    for(int s : starts){
        answer.push_back(MostFrequentNum[s]);
    }
    return answer;
}