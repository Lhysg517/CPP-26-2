#include <iostream>
using namespace std;

// Circle 클래스: 원을 표현하는 클래스
class Circle {
public:
    int radius;     // 반지름 (멤버 변수/속성)
    string color;   // 색상 (멤버 변수/속성)

    // 원의 면적을 계산하는 멤버 함수
    double CalcArea() {
        return 3.14 * radius * radius;
    }
};

int main() {
    // 두 개의 Circle 객체(피자1, 피자2)를 생성
    Circle pizza1, pizza2;

    // pizza1 객체의 멤버 변수 설정
    pizza1.radius = 100;
    pizza1.color = "yellow";
    cout << "피자의 면적=" << pizza1.CalcArea() << "\n";

    // pizza2 객체의 멤버 변수 설정 (pizza1과 독립적인 값)
    pizza2.radius = 200;
    pizza2.color = "white";
    cout << "피자의 면적=" << pizza2.CalcArea() << "\n";

    return 0;
}
