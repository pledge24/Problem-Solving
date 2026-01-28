#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using int64 = long long;

vector<int64> v1;
vector<string> tree;

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

void Build(int64 node, int64 start, int64 end)
{
    if(start == end)
    {
        tree[node] = to_string(v1[start]);
        return;
    }

    int64 mid = (start + end) / 2;
    Build(2*node, start, mid);
    Build(2*node + 1, mid+1, end);

    tree[node] = AddBigNum(tree[2*node], tree[2*node + 1]);
}

string Query(int64 node, int64 start, int64 end, int64 left, int64 right) 
{
    // 범위를 완전히 벗어난 경우
    if (left > end || right < start) 
        return "0"; 

    // 범위에 완전히 포함된 경우
    if (left <= start && end <= right) 
        return tree[node]; 

    // 일부 범위만 포함된 경우
    int64 mid = (start + end) / 2;
    string leftSum = Query(node*2, start, mid, left, right);
    string rightSum = Query(node*2 + 1, mid + 1, end, left, right);

    // cout << leftSum << " " << rightSum << '\n';

    return AddBigNum(leftSum, rightSum);
}

void Update(int64 node, int64 start, int64 end, int64 idx, int64 val)
{
    // 범위를 벗어난 경우
    if (idx < start || idx > end) 
        return; 

    if (start == end) {
        tree[node] = to_string(val); // 리프 노드를 찾아 값 갱신
        v1[idx] = val;

        return;
    }

    int64 mid = (start + end) / 2;
    Update(node*2, start, mid, idx, val);
    Update(node*2 + 1, mid + 1, end, idx, val);
    
    // 자식이 바뀌었으므로 부모 값도 갱신
    tree[node] = AddBigNum(tree[node*2], tree[node*2 + 1]);
}

int main(void)
{
    fastio;

    int N, M, K; cin >> N >> M >> K;
    v1.resize(N+1);
    for(int i = 1; i <= N; i++)
    {
        cin >> v1[i];
    }

    tree.resize(4*N, to_string(0));
    Build(1, 1, N);

    for(int i = 0; i < M + K; i++)
    {
        int64 a, b, c; cin >> a >> b >> c;

        if(a == 1)
            Update(1, 1, N, b, c);
        else if(a == 2)
            cout << Query(1, 1, N, b, c) << '\n';
    }

    return 0;
}