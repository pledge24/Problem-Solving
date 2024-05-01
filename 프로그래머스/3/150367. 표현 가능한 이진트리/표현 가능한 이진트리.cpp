#include <bits/stdc++.h>

using namespace std;

string getBinary(long long num){
    string str_num = "";
    while(num > 0){
        str_num += (num % 2) + '0';
        num /= 2;
    }
    
    return str_num;
}

// str_num: 현재 문자열, idx: 서브 트리의 루트 위치, len: 현재 서브 트리의 한 쪽 길이
bool divAndConq(string str_num, int idx, int len){
    
    int left_idx = idx - len/2 - 1;
    int right_idx = idx + len/2 + 1;
    
       
    //printf("left_idx: %d, right_idx: %d idx: %d len: %d\n", left_idx, right_idx, idx, len);
    if(str_num[idx] == '0' && (str_num[left_idx] - '0' || str_num[right_idx] - '0')){
        
        //printf("str_num: %s, idx: %d (%d %d %d)\n", str_num.c_str(), idx, str_num[idx]-'0', str_num[left_idx]-'0', str_num[right_idx]-'0');
        return false;
    }
    
    if(len <= 1) return true;
    
    return divAndConq(str_num, left_idx, (len-1)/2) && divAndConq(str_num, right_idx, (len-1)/2);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(long long num : numbers){
        string str_num = getBinary(num);
        reverse(str_num.begin(), str_num.end());
        
        //cout << str_num << '\n';
        int len = str_num.length();
        bool ans = false;
        string dummies = "";
        vector<int> v1 = {1, 3, 7, 15, 31, 63, 127, 255};
        for(int i = 0; i < v1.size(); i++){   
            
            dummies = "";
            
            if(len > v1[i]) continue;   
            else if(len < v1[i]){
                dummies.append(v1[i] - len, '0');
            }
            
            
            string cur_str_num = dummies + str_num;
            
            int cur_len = cur_str_num.length();
            //cout << cur_str_num << '\n';
            //cout << "len: " << cur_str_num.length() << '\n';
            if(divAndConq(cur_str_num, (cur_len-1)/2, (cur_len-1)/2)){
                //cout << num << " "<< i << '\n';
                if(num == 12 || num == 13){
                    cout << cur_len << " " << num << '\n';
                }
                ans = true;
                break;
            }
            // dummies += "0";
        }
        // if(len % 2){
        //     ans = divAndConq(str_num, len/2, len/2);
        // }
        // else{
        //     ans = divAndConq(str_num + "0", len/2, len/2) || divAndConq("0" + str_num, len/2, len/2);
        //     //cout << divAndConq("0" + str_num, len/2, len/2) << '\n';
        // }
        
         answer.push_back(ans);
        
        
    }
    // cout << "[";
    //     for(int elem : answer){
    //         cout << elem << ", ";
    //     }
    //     cout << "]\n";
    return answer;
}