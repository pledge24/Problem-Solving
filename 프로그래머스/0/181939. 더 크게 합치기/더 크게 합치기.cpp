#include <bits/stdc++.h>

using namespace std;

int MakeInt(int a, int b) { return stoi(to_string(a) + to_string(b));}
int solution(int a, int b) {
    int answer = max(MakeInt(a, b), MakeInt(b, a));
    return answer;
}