#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using Matrix = vector<vector<char>>;

bool startTest(const string& str){
    Matrix matrix(3, vector<char>(3));

    int cntO = 0;
    int cntX = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            char c = str[i*3 + j];
            matrix[i][j] = c;

            if(c == 'O')
                cntO++;
            else if(c == 'X')
                cntX++;
        }
    }

    int rows_O = 0;
    int cols_O = 0;
    int dias_O = 0;

    int rows_X = 0;
    int cols_X = 0;
    int dias_X = 0;

    // count rows
    for(int r = 0; r < 3; r++){
        vector<char>& row = matrix[r];
        rows_O += count(row.begin(), row.end(), 'O') == 3;
        rows_X += count(row.begin(), row.end(), 'X') == 3;
    }

    // count cols
    for(int c = 0; c < 3; c++){
        cols_O += (matrix[0][c] & matrix[1][c] & matrix[2][c]) == 'O';
        cols_X += (matrix[0][c] & matrix[1][c] & matrix[2][c]) == 'X';
    }

    // count dias
    dias_O += (matrix[0][0] & matrix[1][1] & matrix[2][2]) == 'O';
    dias_O += (matrix[2][0] & matrix[1][1] & matrix[0][2]) == 'O';
    dias_X += (matrix[0][0] & matrix[1][1] & matrix[2][2]) == 'X';
    dias_X += (matrix[2][0] & matrix[1][1] & matrix[0][2]) == 'X';

    int rows = rows_O + rows_X;
    int cols = cols_O + cols_X;
    int dias = dias_O + dias_X;

    // cout << "rows_O: " << rows_O << '\n';
    // cout << "cols_O: " << cols_O << '\n';
    // cout << "dias_O: " << dias_O << '\n';
    // cout << "rows_X: " << rows_X << '\n';
    // cout << "cols_X: " << cols_X << '\n';
    // cout << "dias_X: " << dias_X << '\n';

    // 검증 시작

    // 1) O가 X보다 많음 + 한 문자만 비정상적으로 많음
    if(cntO > cntX || abs(cntO - cntX) > 1)
        return false;
    
    // 2) 2개의 가로, 2개의 세로가 존재함
    if(rows >= 2 || cols >= 2)
        return false;
 
    // 3) 승부가 안났는데 자리가 남은 상황
    if((rows + cols + dias) == 0 && (cntO + cntX) < 9)
        return false;

    // 4) O가 이겼는데 X가 더 많은 상황
    bool Owin = (rows_O + cols_O + dias_O) > 0;
    if((cntO < cntX) && Owin)
        return false;

    // 5) X가 이겼는데 개수가 O == X인 상황
    if(Owin == false && cntO == cntX)
        return false;
    
    return true;
}

int main(void){
    fastio;

    while(true){
        string str; cin >> str;
        if(str == "end")
            break;

        bool valid = startTest(str);
        
        string ans = valid ? "valid" : "invalid";

        cout << ans << '\n';
    }


    return 0;
}