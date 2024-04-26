#include <algorithm>
#include <bits/stdc++.h>

using namespace std;


long long getShared_n(long long w, long long h){
  
    while (h != 0) {
        long long temp = h;
        h = w % h;
        w = temp;
    }
    
        
    return w;
}

long long solution(int w, int h) {
    
    long long answer = -1;
    
    long long max_shared_n = getShared_n(w, h);
    long long long_w = w;
    long long long_h = h;
    
    long long unit_rip = long_w / max_shared_n + long_h / max_shared_n -1;
    
    answer = long_w * long_h - max_shared_n * unit_rip;
    
    return answer;
}