#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct pos_data
{
    int start_num;
    int cur_num;
    int cnt;
};

int bfs(vector<vector<int>> &inData, int N){
    vector<bool> visited(N+1);

    int cycle_cnt = 0;

    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            queue<pos_data> q;
            
            visited[i] = true;
            q.push({i, i, 1});

            while(!q.empty()){
                pos_data p = q.front();
                q.pop();

                for(int i = 0; i < inData[p.cur_num].size(); i++){
                    int next_no = inData[p.cur_num][i];
                    if(!visited[next_no]){
                        visited[next_no] = true;
                        q.push({p.start_num, next_no, p.cnt+1});
                    }
                    else if(visited[next_no] && next_no == p.start_num){
                        cycle_cnt += p.cnt;
                    }
                }
            }
        }
    }

    return N - cycle_cnt;
}

void team_proj(){
    int N; cin >> N;

    vector<vector<int>> inData(N+1);

    int in_num;
    for(int i = 1; i <= N; i++){
        cin >> in_num;
        inData[in_num].push_back(i);
    }

    int ans = bfs(inData, N);

    cout << ans << '\n';

}

int main() {
	fastio;
    int T; cin >> T;

    for(int i = 0; i < T; i++){
        team_proj();
    }
    
}