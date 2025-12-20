#include <vector>

using namespace std;

// n: 원판 개수, from: 시작 기둥, to: 목적 기둥, bypass: 거쳐가는 기둥
void hanoi(int n, int from, int to, int bypass, vector<vector<int>>& answer) {
    if (n == 1) {
        answer.push_back({from, to});
        return;
    }

    // 1. 가장 큰 원판을 제외한 n-1개를 bypass 기둥으로 옮김
    hanoi(n - 1, from, bypass, to, answer);
    
    // 2. 가장 큰 원판을 목적지로 옮김
    answer.push_back({from, to});
    
    // 3. bypass에 있던 n-1개를 다시 목적지로 옮김
    hanoi(n - 1, bypass, to, from, answer);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(n, 1, 3, 2, answer);
    return answer;
}