#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;

    int caseN = 0;
    while(true){
        caseN++;
        int A, B, C; cin >> A >> B >> C;

        if(A + B + C == 0)
            break;

        int unit = C / B;
        int mod = C % B;

        int ans = unit * A + min(mod, A);

        printf("Case %d: %d\n", caseN, ans);
    }
    

    return 0;
}