#include <string>
#include <vector>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    int num3 = numer1 * denom2 + numer2 * denom1;
    int denom3 = denom1 * denom2;
    
    auto GetGdc = [](int a, int b){
        while(a > 0 && b > 0)
        {
            if(a < b)
                swap(a, b);
            
            a %= b;
        }
        
        return max(a, b);
    };
    
    int gdc = GetGdc(num3, denom3);
    answer = {num3/gdc, denom3/gdc};
    
    return answer;
}