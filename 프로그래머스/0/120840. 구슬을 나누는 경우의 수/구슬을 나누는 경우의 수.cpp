#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int solution(int balls, int share) {
    int64 result = 1;

    for (int i = 1; i <= share; i++) {
        result *= balls--;  
        result /= i;        
    }

    return result;
}