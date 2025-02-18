#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct NumOfType
{
    int neg = 0;
    int zero = 0;
    int pos = 0;
};

NumOfType dnc(vector<vector<int>>& matrix, int x, int y, int N){
    vector<NumOfType> numOfTypes;
    NumOfType cur;

    // 종료 조건
    if(N == 1){
        if(matrix[x][y] > 0) cur.pos = 1;
        else if(matrix[x][y] < 0) cur.neg = 1;
        else cur.zero = 1;

        return cur;
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int nx = x + (N/3)*i;
            int ny = y + (N/3)*j;

            numOfTypes.push_back(dnc(matrix, nx, ny, N/3));
        }
    }

    for(NumOfType numOftype : numOfTypes){
        cur.neg += numOftype.neg;
        cur.zero += numOftype.zero;
        cur.pos += numOftype.pos;
    }

    if(cur.neg > 0 && cur.zero == 0 && cur.pos == 0){
        cur.neg = 1;
    }
    else if(cur.zero > 0 && cur.neg == 0 && cur.pos == 0){
        cur.zero = 1;
    }
    else if(cur.pos > 0 && cur.neg == 0 && cur.zero == 0){
        cur.pos = 1;
    }

    return cur;
}

int main() {
	fastio;

    int N; cin >> N;
    vector<vector<int>> matrix;
    matrix.resize(N, vector<int>(N));

    // input data
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> matrix[i][j];
        }
    }

    NumOfType ans = dnc(matrix, 0, 0, N);

    cout << ans.neg << '\n';
    cout << ans.zero << '\n';
    cout << ans.pos << '\n';

}