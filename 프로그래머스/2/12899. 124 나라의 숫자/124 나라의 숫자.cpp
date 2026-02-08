#include <bits/stdc++.h>

using namespace std;

int mappings[3] = {1, 2, 4};

string solution(int n) {
    string answer = "";
    int rem;

    while (n > 0) {
        rem = n % 3; // 3으로 나눈 나머지
        n = n / 3;   // 다음 몫

        if (rem == 0) {
            answer = "4" + answer;
            n -= 1; // 나머지가 0일 때 몫에서 1을 빼주는 것이 핵심!
        } else if (rem == 1) {
            answer = "1" + answer;
        } else if (rem == 2) {
            answer = "2" + answer;
        }
    }
    
    return answer;
}