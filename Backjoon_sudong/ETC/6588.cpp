#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

void startTest(vector<int>& oddPrimeList, vector<bool>& isPrimeList, int num){

    for(int elem : oddPrimeList){
        if(elem * 2 > num)
            break;

        if((num - elem) % 2 && isPrimeList[num - elem] == true){
            cout << num << " = " << elem << " + " << num - elem << '\n';
            return;
        }
    }

    cout << "Goldbach's conjecture is wrong." << '\n';

    return;
}

bool isPrime(int num){
    for(int n = 2; n <= sqrt(num); n++){
        if(num % n == 0)
            return false;
    }

    return true;
}

void eratos(vector<int>& oddPrimeList, vector<bool>& isPrimeList){

    for(int i = 2; i < isPrimeList.size(); i++){
        if(isPrimeList[i] == false)
            continue;

        if(isPrime(i)){
            if(i % 2 == 1) 
                oddPrimeList.push_back(i);
            
            for(int n = 2; i*n < isPrimeList.size(); n++)
                isPrimeList[i*n] = false;
        }
    }

}

int main(void){
    fastio;

    vector<int> oddPrimeList;
    vector<bool> isPrimeList(1000001, true);
    eratos(oddPrimeList, isPrimeList);

    int num; cin >> num;
    while(num != 0){
        startTest(oddPrimeList, isPrimeList, num);
        cin >> num;
    }
        
    
    return 0;
}