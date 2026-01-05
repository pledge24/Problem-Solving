#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> board) {
    int answer = -1;
    
    int OCnt = 0;
    int XCnt = 0;
    // count O and X
    for(const string& rowStr : board)
    {
        for(char c : rowStr)
        {
            if(c == 'O')
                OCnt++;
            else if(c == 'X')
                XCnt++;
        }
    }
    // cout << OCnt << " " << XCnt << '\n';
    
    // count bingo
    int rowOBingo = 0;
    int rowXBingo = 0;
    int colOBingo = 0;
    int colXBingo = 0;
    int diaOBingo = 0;
    int diaXBingo = 0;
    for(int i = 0; i < 3; i++)
    {
        const string& rowStr = board[i];
        if(rowStr == "OOO")
            rowOBingo++;
        else if(rowStr == "XXX")
            rowXBingo++;
        
        string colStr = {board[0][i], board[1][i], board[2][i]};
        
        if(colStr == "OOO")
            colOBingo++;
        else if(colStr == "XXX")
            colXBingo++;
    }
    
    const string diaStr1 = {board[0][0], board[1][1], board[2][2]};
    const string diaStr2 = {board[0][2], board[1][1], board[2][0]};
    
    if(diaStr1 == "OOO")
        diaOBingo++;
    else if(diaStr1 == "XXX")
        diaXBingo++;
    
    if(diaStr2 == "OOO")
        diaOBingo++;
    else if(diaStr2 == "XXX")
        diaXBingo++;
        
    // cout << rowOBingo << " " << rowXBingo << '\n';
    // cout << colOBingo << " " << colXBingo << '\n';
    
    answer = 0;
    int OBingos = rowOBingo + colOBingo + diaOBingo;
    int XBingos = rowXBingo + colXBingo + diaXBingo;
    if(OCnt == XCnt+1)
    {
        if(XBingos == 0)
            answer = 1;
    }
    
    if(OCnt == XCnt)
    {
        if(OBingos == 0)
            answer = 1;
    }
    
    return answer;
}