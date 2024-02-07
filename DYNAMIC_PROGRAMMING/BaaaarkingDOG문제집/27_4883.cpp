// 문제를 잘 보자... 알고리즘이 틀린줄 알고 삽질했는데, 원인은 출력이었다...(전체 케이스중 최소 경로만 출력하는 것이 아닌 각 케이스마다 출력이었다ㅋ)
// 2024-02-01

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define COLS 3

using namespace std;

struct nodes
{
    int left;
    int mid;
    int right;
};

int main() {
	fastio;

    int k; cin >> k;

    int case_k = 1;
    while(k != 0){
        // data input
        vector<nodes> v1(k+1);
        for(int i=1; i<=k; i++){
            cin >> v1[i].left >> v1[i].mid >> v1[i].right;
        }

        // initialize
        vector<nodes> v1_accu(k+1);
        v1_accu[1].left = v1[1].left;
        v1_accu[1].mid = v1[1].mid;
        v1_accu[1].right = v1[1].right + v1[1].mid;

        // // output test
        // for(int i = 1; i <= k; i++){            
        //     cout << v1_accu[i].left << "\t" << v1_accu[i].mid << "\t" << v1_accu[i].right << '\n';           
        // }

        v1_accu[2].left = v1[2].left + v1_accu[1].mid;                           
        v1_accu[2].mid = v1[2].mid + min({v1_accu[1].mid, v1_accu[1].right, v1_accu[2].left});
        v1_accu[2].right = v1[2].right + min({v1_accu[1].mid, v1_accu[1].right, v1_accu[2].mid});

        // // output test
        // for(int i = 1; i <= k; i++){            
        //     cout << v1_accu[i].left << "\t" << v1_accu[i].mid << "\t" << v1_accu[i].right << '\n';           
        // }

        // dp
        for(int i=3; i<=k; i++){

            v1_accu[i].left = v1[i].left + min(v1_accu[i-1].left, v1_accu[i-1].mid);
            v1_accu[i].mid = v1[i].mid + min({v1_accu[i-1].left, v1_accu[i-1].mid, v1_accu[i-1].right, v1_accu[i].left});
            v1_accu[i].right = v1[i].right + min({v1_accu[i-1].mid, v1_accu[i-1].right, v1_accu[i].mid});
            
        }
             
        int ans_k = case_k;
        int ans_n = v1_accu[k].mid;
        cout << ans_k << ". " << ans_n << '\n';

        // // output test
        // for(int i = 1; i <= k; i++){            
        //     cout << v1_accu[i].left << "\t" << v1_accu[i].mid << "\t" << v1_accu[i].right << '\n';           
        // }

        case_k++;
        cin >> k;
    }
    
}