#include <bits/stdc++.h>

using namespace std;

struct rgb{
    int r;
    int g;
    int b;
};

int main(void){
    int N;
    cin >> N;

    vector<rgb> v1(N);

    for(int i=0; i<N; i++){
        cin >> v1[i].r >> v1[i].g >> v1[i].b;
    }

    int r_min = v1[0].r, g_min = v1[0].g, b_min = v1[0].b;

    int a, b, c;
    for(int i=1; i<N; i++){
       a = min(g_min, b_min) + v1[i].r;
       b = min(r_min, b_min) + v1[i].g;
       c = min(r_min, g_min) + v1[i].b;

       r_min = a, g_min = b, b_min = c;
    }

    //printf("%d %d %d\n", r_min, g_min, b_min);
    cout << min({r_min, g_min, b_min}) << '\n';

    return 0;
}