#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using Graph = vector<vector<int>>;

int bfs(const Graph& graph, int start, int N){
    int cnt = 0;
    vector<int> score(N+1, -1);
    queue<int> q;

    score[start] = 0;
    q.push(start);

    while(!q.empty()){
        int cur = q.front(); q.pop();

        for(int adj : graph[cur]){
            if(score[adj] == -1){
                q.push(adj);
                score[adj] = score[cur] + 1;
                cnt = max(cnt, score[cur] + 1);
            }
        }
    }

    return cnt;
}

int main(void){
    fastio;
    int N; cin >> N;

    Graph graph(N+1);
    int A, B;
    while(true){
        cin >> A >> B;
        if(make_pair(A, B) == make_pair(-1, -1))
            break;

        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    vector<pair<int, int>> scores;
    for(int i = 1; i <= N; i++){
        int cnt = bfs(graph, i, N);
        scores.push_back(make_pair(cnt, i));
    }

    sort(scores.begin(), scores.end());

    int minScore = scores[0].first;
    // int candidateN = count_if(scores.begin(), scores.end(), [minScore](auto elem){return elem.first == minScore;});
    int candidateN = upper_bound(scores.begin(), scores.end(), make_pair(minScore, N+1)) - scores.begin();
    // for(auto it : scores){
    //     if(it.first > minScore)
    //         break;
    //     candidateN++;
    // }

    cout << scores[0].first << ' ' << candidateN << '\n';
    for(int i = 0; i < candidateN; i++){
        cout << scores[i].second << ' ';
    }
    cout << '\n';

    return 0;
}