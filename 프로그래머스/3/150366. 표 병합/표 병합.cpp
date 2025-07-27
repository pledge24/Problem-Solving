#include <bits/stdc++.h>

#define MAXN 50

using namespace std;
using Pos = pair<int, int>;

// 원래 데이터
// 병합되었는가?
// 병합된 위치
struct Cell{
    string value = "";
    bool isMerged = false;
    Pos mergedPos = make_pair(-1, -1);
    set<Pos> mergedCells;
};

Cell table[MAXN+1][MAXN+1];

Pos getRootPos(int r, int c){
    Pos pos = make_pair(r, c);
    if(table[pos.first][pos.second].isMerged == false)
        return pos;

    Pos nextPos = table[pos.first][pos.second].mergedPos;
    return table[pos.first][pos.second].mergedPos = getRootPos(nextPos.first, nextPos.second);
}

void parse(const string cmd, vector<string>& splitted){
    int idx = 0;
    while(idx < cmd.length()){
        int nextIdx = cmd.find(" ", idx);
        
        if(nextIdx == string::npos)
            nextIdx = cmd.length();
        
        if(nextIdx - idx > 0)
            splitted.push_back(cmd.substr(idx, nextIdx-idx));
        
        idx = nextIdx + 1;
    }
}

void printTable(){
    for(int i = 1; i <= MAXN; i++){
        for(int j = 1; j <= MAXN; j++){
            Pos rootCell = getRootPos(i, j);
            string value = table[rootCell.first][rootCell.second].value;
            if(value.empty())
                value = "X";
            
            cout << value << ' ';
        }
        cout << '\n';
    }
}

void DfsClear(Pos pos){
    set<Pos>& group = table[pos.first][pos.second].mergedCells;
    
    if(group.empty())
        return;
    
    for(Pos mergedCellPos: group){
        DfsClear(mergedCellPos);
        table[mergedCellPos.first][mergedCellPos.second] = Cell{};
    }
    table[pos.first][pos.second] = Cell{};
}

// value는 a~z|1~9로 구성된 문자열
void Execute(vector<string>& answer, const string& cmd){
    vector<string> splitted;
    parse(cmd, splitted);
       
    string cmdType = splitted[0];
    if(cmdType == "UPDATE"){
        /* UPDATE r c value */
        if(splitted.size() == 4){ 
            int r = stoi(splitted[1]);
            int c = stoi(splitted[2]);
            
            Pos cellPos = getRootPos(r, c);
            
            table[cellPos.first][cellPos.second].value = splitted[3];
            
            // cout << "Update, cellPos: " << cellPos.first << " " << cellPos.second << " " << splitted[3] << '\n';
            
        }
        /* UPDATE value1 value2 */
        else{            
            for(int i = 1; i <= MAXN; i++){
                for(int j = 1; j <= MAXN; j++){
                    if(table[i][j].value == splitted[1])
                        table[i][j].value = splitted[2];
                }
            }
        }
    }
    /* MERGE r1 c1 r2 c2 */
    else if(cmdType == "MERGE"){
        int r1 = stoi(splitted[1]);
        int c1 = stoi(splitted[2]);
        int r2 = stoi(splitted[3]);
        int c2 = stoi(splitted[4]);
        
        Pos cellPos1 = getRootPos(r1, c1);
        Pos cellPos2 = getRootPos(r2, c2);

        if(cellPos1 == cellPos2)
            return;
        
        Cell& cell1 = table[cellPos1.first][cellPos1.second];
        Cell& cell2 = table[cellPos2.first][cellPos2.second];
        cell2.isMerged = true;
        cell2.mergedPos = cellPos1;

        // 첫번째 두번째 셀을 넣는다.
        cell1.mergedCells.insert(cellPos2);
        
        // 두 셀 중 한 셀이 값을 가지고 있을 경우, 병합된 셀은 그 값을 가진다.
        // 둘 다 있으면 첫번째 셀 값을 따른다.
        if(cell1.value.empty()){
            cell1.value = cell2.value;
        }
        
        // cout << "cellPos1: " << cellPos1.first << " " << cellPos1.second << '\n';
        // cout << "cellPos2: " << cellPos2.first << " " << cellPos2.second << '\n';
    }
    /* UNMERGE r c */
    else if(cmdType == "UNMERGE"){
        int r = stoi(splitted[1]);
        int c = stoi(splitted[2]);
        
        Pos rootPos = getRootPos(r, c);
        string value = table[rootPos.first][rootPos.second].value;
        // cout << "value: " << value << '\n';
        
        // 같은 집합에 있는 셀들을 재귀적으로 찾아서 밀어버린다.
        DfsClear(rootPos);
       
        if(!value.empty())
            table[r][c].value = value;
        
        // cout << "UNMERGE: " << r << " " << c << '\n';
        // printTable();
        
    }
    /* PRINT r c */
    else if(cmdType == "PRINT"){
        int r = stoi(splitted[1]);
        int c = stoi(splitted[2]);
        
        Pos cellPos = getRootPos(r, c);
       
        // 병합된 셀을 출력.
        string value = table[cellPos.first][cellPos.second].value;
        if(value.empty())
            value = "EMPTY";
        
        answer.push_back(value);
        // cout << value << '\n';
    }
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    for(const string& cmd : commands){
        Execute(answer, cmd);
    }
    
    return answer;
}