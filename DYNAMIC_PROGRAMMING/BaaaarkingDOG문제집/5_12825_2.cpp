#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct hop
{
    int size;
    int before;
};

vector<hop> m(1000002);

int main(void) {
	fastio;
    int N; cin >> N;
    //m.resize(N+1);

    m[1].size = 0; m[1].before = -1;
    m[2].size = 1; m[2].before = 1;
    m[3].size = 1; m[3].before = 1;


    for(int i = 4; i <= N; i++){
       
        m[i].size = m[i - 1].size + 1;
        m[i].before = i - 1;

        if (i % 3 == 0 && m[i / 3].size + 1 < m[i].size) {
            m[i].size = m[i / 3].size + 1;
            m[i].before = i / 3;
        }
        if (i % 2 == 0 && m[i / 2].size + 1 < m[i].size) {
            m[i].size = m[i / 2].size + 1;
            m[i].before = i / 2;
        }
    }

    cout << m[N].size << '\n';

    while (N != -1)
    {
        cout << N << ' ';
        N = m[N].before;
    }
    cout << '\n';

    return 0;
}