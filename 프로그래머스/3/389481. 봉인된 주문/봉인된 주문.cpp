#include <bits/stdc++.h>

#define ALPHA_N 26

using namespace std;
using int64 = long long;

int64 str2num(const string& str){
    int64 res = 0;
    
    int64 multiply = 1;
    for(int i = str.length() - 1; i >= 0; i--){
        res += (str[i] - 'a' + 1) * multiply;
        multiply *= ALPHA_N;
    }
    
    return res;
}

string num2str(int64 num){
    string str = "";
    while(num > 0){
        int idx = num % ALPHA_N; // id: 0 -> 'z', idx: 1 -> 'a'
        idx = (idx - 1 + ALPHA_N) % ALPHA_N; // id: 25 -> 'z', idx: 0 -> 'a'
        
        str += 'a' + idx; 
        
        num /= ALPHA_N;
        if(idx == 25)
            num--;
    }
    
    reverse(str.begin(), str.end());
    
    return str;
}

string solution(long long n, vector<string> bans) {
    vector<int64> v1;
    for(const string& str : bans){
        v1.push_back(str2num(str));
    }
        
    sort(v1.begin(), v1.end());
    
//     for(auto elem : v1){
//         cout << elem << ' ';
//     }
//     cout << '\n';
    
    // 1) 
    int64 start = 0;
    do{
        int64 offset = upper_bound(v1.begin() + start, v1.end(), n) - (v1.begin() + start);
        
        if(offset == 0)
            break;
        
        start += offset;
        n += offset;
        // cout << "n: " << n << '\n';
    } while(true);
    
    // cout << "num: " << n << '\n';
    string answer = num2str(n);
    
    return answer;
}