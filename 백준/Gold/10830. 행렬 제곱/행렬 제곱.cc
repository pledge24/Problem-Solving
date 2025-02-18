#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using Grid = vector<vector<long long>>;

long long calcCV(const Grid &temp1, const Grid &temp2, long long N, long long r, long long c){
    long long num = 0;
    const long long DIV = 1000;
    for(long long i = 0; i < N; i++){
        num += (temp1[r][i] * temp2[i][c]) % DIV;
    }

    return num % DIV;
}

Grid multiplyMatrix(Grid &res1, Grid &res2){
    const Grid temp1 = res1;
    const Grid temp2 = res2;

    long long N = res1.size();
    Grid multiplyRes(N, vector<long long>(N));

    for(long long i = 0; i < N; i++){
        for(long long j = 0; j < N; j++){
            multiplyRes[i][j] = calcCV(temp1, temp2, N, i, j);
        }
    }

    return multiplyRes;
}

int main(void){
    fastio;
    long long N, B; cin >> N >> B;
    Grid matrix(N, vector<long long>(N));
    for(long long i = 0; i < N; i++){
        for(long long j = 0; j < N; j++){
            cin >> matrix[i][j];
        }
    } 

    vector<Grid> matrixList;
    matrixList.push_back(matrix);
    Grid prevRes = matrix;
    const long long MAXEXP = log2(B);
    for(long long i = 1; i <= MAXEXP; i++){
        prevRes = multiplyMatrix(prevRes, prevRes);
        matrixList.push_back(prevRes);
    }

    // prlong long Matrix
    // for(Grid mx : matrixList){
    //     for(long long i = 0; i < N; i++){
    //         for(long long j = 0; j < N; j++){
    //             cout << mx[i][j] << ' ';
    //         }
    //         cout << '\n';
    //     } 
    // }
    
    Grid ans;
    long long leftB = B;
    for(long long i = MAXEXP; i >= 0; i--){

        if(leftB < (long long)pow(2, i))
            continue;
        
        ans = ans.empty() ? matrixList[i] : multiplyMatrix(ans, matrixList[i]);
        leftB -= (long long)pow(2, i);
    }

    // prlong long ans
    for(long long i = 0; i < N; i++){
        for(long long j = 0; j < N; j++){
            cout << ans[i][j] % 1000 << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}