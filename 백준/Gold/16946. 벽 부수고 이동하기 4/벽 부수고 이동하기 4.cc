#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIR 4
#define AREAN 1'000'000
using namespace std;

int N, M;
int dx[DIR] = {1, 0, -1, 0};
int dy[DIR] = {0, 1, 0, -1};

map<int, int> areas_cnt;
vector<vector<int>> matrix;

bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
}

void bfs(int area_num, int x, int y){

    queue<pair<int, int>> q;
    int cnt = 0;

    matrix[x][y] = area_num;
    q.push({x, y}); cnt++;

    while(!q.empty()){
        pair<int, int> p = q.front(); q.pop();

        for(int i = 0; i < DIR; i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];

            if(inRange(nx, ny) && matrix[nx][ny] == 0){
                matrix[nx][ny] = area_num;
                q.push({nx, ny}); cnt++;
            }
        }
    }

    areas_cnt[area_num] = cnt;

    return;
}

int main()
{
    fastio;
    
    cin >> N >> M;
   
    matrix.resize(N, vector<int>(M));

    string str;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for (int j = 0; j < M; j++)
        {
            matrix[i][j] = str[j] - '0';
        }
    }

    int area_num = AREAN;
    vector<pair<int,int>> wallList;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(matrix[i][j] == 0){
                bfs(area_num++, i, j);
            }
            else if(matrix[i][j] == 1){
                wallList.push_back({i, j});
            }
        }
    }

    // for(auto it = areas_cnt.begin(); it != areas_cnt.end(); it++){
    //     cout << "areas_cnt: " << it->first << " " << it->second << '\n';
    // }

    // 찾아라~ 갈 수 있는 곳~
    for(pair<int, int> p : wallList){
        int x = p.first;
        int y = p.second;

        set<int> s;

        for(int i = 0; i < DIR; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(inRange(nx, ny) && matrix[nx][ny] >= AREAN){
                s.insert(matrix[nx][ny]);
            }
        }

        for(auto it = s.begin(); it != s.end(); it++){
            matrix[x][y] += areas_cnt[*it]; 
        }

        matrix[x][y] %= 10;
    }

    // 출력
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < str.size(); j++)
        {
            if(matrix[i][j] >= AREAN) matrix[i][j] = 0;
            cout << matrix[i][j];
        }
        cout << '\n';
    }
}