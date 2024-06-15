#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<int> s;

enum class Instruction {
    Push, Pop, Size, Empty, Top, None // None 추가
};

void stack_func(Instruction choice) {
    int num;

    switch (choice)
    {
    case Instruction::Push:
        cin >> num;
        s.push(num);
        break;
    case Instruction::Pop:
        if (!s.empty()) {
            cout << s.top() << '\n';
            s.pop();
            return;
        }
        cout << -1 << '\n';
        break;
    case Instruction::Size:
        cout << s.size() << '\n';
        break;
    case Instruction::Empty:
        num = s.empty() ? 1 : 0;
        cout << num << '\n';
        break;
    case Instruction::Top:
        if (!s.empty()) {
            cout << s.top() << '\n';
            return;
        }
        cout << -1 << '\n';
        break;
    default:
        // choice가 초기화되지 않았거나 예상치 못한 값이 전달된 경우
        cout << "Invalid instruction" << '\n';
        break;
    }
}

int main() {
    int N;
    cin >> N;

    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;

        Instruction choice = Instruction::None; // 초기화
        if (str == "push") choice = Instruction::Push;
        else if (str == "pop") choice = Instruction::Pop;
        else if (str == "size") choice = Instruction::Size;
        else if (str == "empty") choice = Instruction::Empty;
        else if (str == "top") choice = Instruction::Top;

        stack_func(choice);
    }

    return 0;
}
