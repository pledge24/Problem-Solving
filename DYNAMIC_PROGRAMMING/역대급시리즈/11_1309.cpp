#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIV 9901
using namespace std;

int main() {
	fastio;
    int N; cin >> N;
    vector<int> up(N+1);        // i번째에서 위에 사자를 넣은 경우
    vector<int> down(N+1);      // i번째에서 아래에 사자를 넣은 경우
    vector<int> nothing(N+1);   // i번째에서 사자를 넣지 않는 경우

    nothing[1] = up[1] = down[1] = 1;
    for(int i = 2; i <= N; i++){
        up[i] = (nothing[i-1] + down[i-1]) % DIV;
        down[i] = (nothing[i-1] + up[i-1]) % DIV;
        nothing[i] = (up[i-1] + down[i-1] + nothing[i-1]) % DIV;
    }

    int ans = (up[N] + down[N] + nothing[N])%DIV;

    cout << ans << '\n';
}