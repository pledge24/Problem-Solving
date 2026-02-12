#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 양수끼리의 덧셈
string Add(string num1, string num2)
{
    string result = "";
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    int carry = 0;  // 올림수

    while(i >= 0 || j >= 0 || carry)
    {
        // num1[i--]는 num[i]를 반환한 후, i를 1 감소시킴.
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;

        int sum = digit1 + digit2 + carry;

        result += char(sum % 10 + '0');
        carry = sum / 10;
    }
    
    std::reverse(result.begin(), result.end());

    return result;
}

bool IsLess(const string& num1, const string& num2)
{
    int len1 = num1.length();
    int len2 = num2.length();

    if(len1 < len2)
        return true;
    else if(len1 > len2)
        return false;

    // Same Len -> 사전순 비교 사용
    return num1 < num2;
}

// 양수끼리의 뺄셈
string Subtract(string num1, string num2)
{
    // set num1 >= num2
    bool negative = false;
    if(IsLess(num1, num2))
    {
        negative = true;
        std::swap(num1, num2);
    }

    string result = "";
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    int borrow = 0;  // 차용수

    while(i >= 0)
    {
        int digit1 = num1[i--] - '0';
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;

        int sub = (digit1 - borrow) - digit2;
        
        if(sub < 0)
        {
            borrow = 1;
            sub += 10;
        }
        else
        {
            borrow = 0;
        }

        result += char(sub + '0');
    }

    std::reverse(result.begin(), result.end());

    // 앞에 0 제거
    int pos = result.find_first_not_of('0');
    if(pos == string::npos) 
        return "0";

    if(negative)
        return "-" + result.substr(pos);

    return result.substr(pos);
}

string AddBigNum(string num1, string num2)
{
    bool negative1 = num1[0] == '-';
    bool negative2 = num2[0] == '-';

    if(negative1)
        num1 = num1.substr(1);
    if(negative2)
        num2 = num2.substr(1);
    
    if(!negative1 && !negative2)
        return Add(num1, num2);             // a + b
    else if(!negative1 && negative2)    
        return Subtract(num1, num2);        // a - b
    else if(negative1 && !negative2)
        return Subtract(num2, num1);        // -a + b
    else
        return "-" + Add(num1, num2);       // -a + -b
}

int main(void)
{
     cout << "=== 큰 정수 덧셈 테스트 ===" << endl << endl;
    
    string a = "99999999999999999999999999";
    string b = "88888888888888888888888888";
    cout << "테스트 1: 큰 양수 + 큰 양수" << endl;
    cout << a << endl;
    cout << "+ " << b << endl;
    cout << "= " << AddBigNum(a, b) << endl << endl;
    
    a = "-12345678901234567890";
    b = "-98765432109876543210";
    cout << "테스트 2: 음수 + 음수" << endl;
    cout << a << endl;
    cout << "+ " << b << endl;
    cout << "= " << AddBigNum(a, b) << endl << endl;
    
    a = "100000000000000000000";
    b = "-50000000000000000000";
    cout << "테스트 3: 양수 + 음수" << endl;
    cout << a << endl;
    cout << "+ " << b << endl;
    cout << "= " << AddBigNum(a, b) << endl << endl;
    
    a = "-75000000000000000000";
    b = "25000000000000000000";
    cout << "테스트 4: 음수 + 양수" << endl;
    cout << a << endl;
    cout << "+ " << b << endl;
    cout << "= " << AddBigNum(a, b) << endl << endl;
    
    a = "123456789012345678901234567890";
    b = "987654321098765432109876543210";
    cout << "테스트 5: 매우 큰 수 (30자리)" << endl;
    cout << a << endl;
    cout << "+ " << b << endl;
    cout << "= " << AddBigNum(a, b) << endl << endl;
    
    // long long 범위 확인
    cout << "참고: long long 최대값 = 9223372036854775807 (19자리)" << endl;
    cout << "위 테스트는 이 범위를 훨씬 넘어섭니다!" << endl;

    return 0;
}