#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    sort(d.begin(), d.end());
    
    int accuCost = 0;
    for(int cost : d){
        if(accuCost + cost > budget)
            break;
        
        accuCost += cost;
        answer++;
    }
    
    return answer;
}