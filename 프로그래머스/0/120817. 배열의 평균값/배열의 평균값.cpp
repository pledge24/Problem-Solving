#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

double solution(vector<int> numbers) {
    double answer = accumulate(numbers.begin(), numbers.end(), 0.0) / numbers.size();
    return answer;
}