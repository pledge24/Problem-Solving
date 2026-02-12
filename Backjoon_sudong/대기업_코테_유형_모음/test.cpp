#include <iostream>

struct MyStruct {
    int x;
};

int main() {
    MyStruct* p = new MyStruct();
    p->x = 123456;  // 명시적으로 값 저장
    delete p;

    MyStruct* q = new MyStruct();  // 같은 메모리 주소일 가능성 높음
    std::cout << q->x << std::endl;  // 123456이 그대로 나올 수도 있음
    // delete q;
}
