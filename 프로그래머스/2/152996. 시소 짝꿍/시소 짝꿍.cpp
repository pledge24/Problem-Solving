#include <string>
#include <vector>
#include <bits/stdc++.h>

#define MAXW 1000

using namespace std;

long long solution(vector<int> weights) {
    
    long long answer = 0;
    int same_w_cnt = 0; 
    int prev_w = 0; 

    sort(weights.begin(), weights.end());

    vector<int> v1(MAXW*4 + 1);
    
    for (int w : weights) {
        
        v1[w * 2]++; v1[w * 3]++; v1[w * 4]++;

        if (prev_w == w) {
            same_w_cnt++;
            answer -= same_w_cnt * 2; 
        } else {
            prev_w = w;
            same_w_cnt = 0;
        }
    }

    for (long long elem : v1) {
        //if(elem > 0) cout << elem << ' ';
        
        if (elem > 1) {
            answer += elem * (elem - 1) / 2;
        }
    }

    return answer;
}