#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 2001
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M, K;
int MAP[MAX][MAX];
bool Banned[MAX][MAX];
bool visited[MAX][MAX];
pair<int, int> Start;
queue<pair<pair<int, int>, int> > Q1;
int MoveY[4] = { -1,0,1,0 };
int MoveX[4] = { 0,-1,0,1 };

void input() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> MAP[i][j];
            if (MAP[i][j] == 3) {
                Banned[i][j] = true;
                Q1.push(make_pair(make_pair(i, j), K));
            }
            else if (MAP[i][j] == 4) {
                MAP[i][j] = 0;
                Start = make_pair(i, j);
            }
        }
    }
}

void settings() {
    while (!Q1.empty()) {
        int NowY = Q1.front().first.first;
        int NowX = Q1.front().first.second;
        int NowT = Q1.front().second;
        Q1.pop();

        if (NowT == 0) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int NextY = NowY + MoveY[i];
            int NextX = NowX + MoveX[i];
            if ((NextY >= 0) && (NextY < N) && (NextX >= 0) && (NextX < M) && !Banned[NextY][NextX]) {
                Banned[NextY][NextX] = true;
                Q1.push(make_pair(make_pair(NextY, NextX), NowT - 1));
            }
        }
    };
    Banned[Start.first][Start.second] = false;
}

int BFS() {
    queue<pair<pair<int, int>, int> > Q;
    visited[Start.first][Start.second] = true;
    Q.push(make_pair(make_pair(Start.first, Start.second), 0));

    while (!Q.empty()) {
        int NowY = Q.front().first.first;
        int NowX = Q.front().first.second;
        int NowT = Q.front().second;
        Q.pop();

        if (MAP[NowY][NowX] == 2) {
            return NowT;
        }

        for (int i = 0; i < 4; i++) {
            int NextY = NowY + MoveY[i];
            int NextX = NowX + MoveX[i];
            if ((NextY >= 0) && (NextY < N) && (NextX >= 0) && (NextX < M)) {
                if ((MAP[NextY][NextX] == 0) || (MAP[NextY][NextX] == 2)) {
                    if (!Banned[NextY][NextX]) {
                        if (!visited[NextY][NextX]) {
                            visited[NextY][NextX] = true;
                            Q.push(make_pair(make_pair(NextY, NextX), NowT + 1));
                        }
                    }
                }
            }
        }
    };

    return -1;
}

void find_Answer() {
    cout << BFS() << "\n";
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}