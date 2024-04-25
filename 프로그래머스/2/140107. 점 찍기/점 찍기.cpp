#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

double getHeight(long long distance, long long w){
    if(w == distance) return 0;
    
    return sqrt(distance*distance - w*w);
}

long long solution(int k, int d) {
    long long answer = 0;
    
    for(int w = 0; w <= d; w+=k){
        long long height = floor(getHeight(d, w));
        //cout << height << '\n';
        answer += height / k + 1;
        //cout << height / k + 1 << '\n';
    }
    return answer;
}