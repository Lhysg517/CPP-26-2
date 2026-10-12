#include <iostream>
#include <string>
using namespace std;

// Circle 클래스 선언부: 멤버 함수는 선언만 하고(인터페이스), 구현은 클래스 외부에 둠
class Circle {
public:
    double calcArea(); // 멤버 함수 선언만 존재 (구현 분리)

    int radius;    // 반지름
    string color;  // 색상
};

// 클래스 외부에서 멤버 함수 정의 (Circle::을 붙여 어느 클래스 소속인지 명시)
double Circle::calcArea() {
    return 3.14 * radius * radius;
}

int main() {
    Circle c;
    c.radius = 10;
    cout << c.calcArea() << endl; // 314

    return 0;
}
