#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    pair<int, int> _wallet = make_pair(max(wallet[0], wallet[1]), min(wallet[0], wallet[1]));
    pair<int, int> _bill = make_pair(max(bill[0], bill[1]), min(bill[0], bill[1]));
    
    bool okay = false;
    while(okay == false){
        if(_bill.first <= _wallet.first && _bill.second <= _wallet.second){
            okay = true;
            continue;
        }
        
        answer++;
        _bill.first /= 2;
        _bill = make_pair(max(_bill.first, _bill.second), min(_bill.first, _bill.second));
    }
                                                  
    return answer;
}