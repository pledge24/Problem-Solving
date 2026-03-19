#include <bits/stdc++.h>

using namespace std;

struct Node {
    int prev, next;
};

string solution(int n, int k, vector<string> cmd) {
    // 1. 연결 리스트 초기화
    vector<Node> nodes(n);
    for (int i = 0; i < n; i++) {
        nodes[i] = {i - 1, i + 1};
    }
    nodes[n - 1].next = -1; // 마지막 노드

    stack<int> deleted;
    int cursor = k;

    for (string& s : cmd) {
        if (s[0] == 'U') {
            int x = stoi(s.substr(2));
            while (x--) cursor = nodes[cursor].prev;
        } 
        else if (s[0] == 'D') {
            int x = stoi(s.substr(2));
            while (x--) cursor = nodes[cursor].next;
        } 
        else if (s[0] == 'C') {
            deleted.push(cursor);
            int p = nodes[cursor].prev;
            int nxt = nodes[cursor].next;

            if (p != -1) nodes[p].next = nxt;
            if (nxt != -1) nodes[nxt].prev = p;

            // 다음 커서 설정: 마지막 행이면 이전 행으로, 아니면 다음 행으로
            cursor = (nxt == -1) ? p : nxt;
        } 
        else if (s[0] == 'Z') {
            int target = deleted.top();
            deleted.pop();
            int p = nodes[target].prev;
            int nxt = nodes[target].next;

            if (p != -1) nodes[p].next = target;
            if (nxt != -1) nodes[nxt].prev = target;
        }
    }

    // 2. 결과 문자열 생성
    string answer(n, 'O');
    while (!deleted.empty()) {
        answer[deleted.top()] = 'X';
        deleted.pop();
    }

    return answer;
}