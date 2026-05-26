#include <bits/stdc++.h>

using namespace std;

string solution(string bin1, string bin2) {
    string answer = "";
    
    std::reverse(bin1.begin(), bin1.end());
    std::reverse(bin2.begin(), bin2.end());
    
    if(bin1.length() > bin2.length())
    {
        bin1.swap(bin2);
    }
    
    string total = "";
    int carry = 0;
    for(int i = 0; i < bin2.length(); i++)
    {
        int a = i < bin1.length() ? bin1[i] - '0' : 0;
        int b = bin2[i] - '0';
        
        int sum = a + b + carry;
        
        total += (sum % 2) + '0';
        carry = sum / 2;
    }
    
    if(carry > 0)
        total += "1";
    
    std::reverse(total.begin(), total.end());
    answer = total;
    
    return answer;
}