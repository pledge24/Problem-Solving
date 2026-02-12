#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAXMove 5
#define DIR 4

using namespace std;
using Matrix = vector<vector<int>>;
using Sequence = vector<int>;

// 최대 5번 이동 -> 4^5 => 2^10 => 1024가지의 경우의 수
// backtracking을 사용한다.(undo 기능을 만들어야함.)
// 또는 sequence를 만들고 simulate 한다.

enum {UP, RIGHT, DOWN, LEFT};

void moveUP(Matrix& tempMatrix){
    int N = tempMatrix.size();
    Matrix resMatrix(N, vector<int>(N));

    for(int c = 0; c < N; c++){
        vector<int> res;
        vector<int> v1;
        // Up to Down
        for(int r = 0; r < N; r++){
            int num = tempMatrix[r][c];
            if(num > 0){
                if(v1.back() == num){
                    v1.pop_back();
                    v1.push_back(num*2);
                }
                else{
                    v1.push_back(num);
                }
            }
        }

        for(int i = 0; i < v1.size(); i++){
            resMatrix[i][c] = v1[i];
        }
    }

    swap(tempMatrix, resMatrix);
}

void moveRight(Matrix& tempMatrix){
    int N = tempMatrix.size();
    Matrix resMatrix(N, vector<int>(N));

    for(int r = 0; r < N; r++){
        vector<int> res;
        vector<int> v1;
        // merge Right Side
        for(int c = 0; c < N; c++){
            int num = tempMatrix[r][c];
            if(num > 0){
                if(v1.back() == num){
                    v1.pop_back();
                    v1.push_back(num*2);
                }
                else{
                    v1.push_back(num);
                }
            }
        }

        for(int i = 0; i < v1.size(); i++){
            resMatrix[i][c] = v1[i];
        }
    }

    swap(tempMatrix, resMatrix);
}
void moveDown(Matrix& tempMatrix){}
void moveLeft(Matrix& tempMatrix){}

void simulate(Matrix& tempMatrix, Sequence& seq){
    for(int dir : seq){
        switch(dir){
            case UP:
                moveUP(tempMatrix);
                break;
            case RIGHT:
                moveRight(tempMatrix);
                break;
            case DOWN:
                moveDown(tempMatrix);
                break;
            case LEFT:
                moveLeft(tempMatrix);
                break;
        }
    }
}

int simulateAndGetMax(Matrix tempMatrix, Sequence& seq){
    simulate(tempMatrix, seq);

    // getMaxNum
    int maxN = 0;
    for(auto row : tempMatrix){
        maxN = max(maxN, *max_element(row.begin(), row.end()));
    }

    return maxN;
}

void generateSeq(vector<Sequence>& sequenceList, Sequence& seq){
    if(seq.size() == MAXMove){
        sequenceList.push_back(seq);
        return;
    }

    for(int d = 0; d < DIR; d++){
        seq.push_back(d);
        generateSeq(sequenceList, seq);
        seq.pop_back();
    }
}

int main(void){
    fastio;
    int N; cin >> N;

    Matrix matrix(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> matrix[i][j];
        }
    }

    vector<Sequence> sequenceList;
    Sequence seq;
    generateSeq(sequenceList, seq); // final sequenceList size is 1024

    int ans = 0;
    for(Sequence curSeq : sequenceList){
        int maxN = simulateAndGetMax(matrix, curSeq);
        ans = max(maxN, ans);
    }

    cout << ans << '\n';

    return 0;
}