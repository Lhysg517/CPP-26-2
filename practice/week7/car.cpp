#include <iostream>
#include <string>
using namespace std;

// Car 클래스: 자동차의 상태(속성)와 동작(메서드)을 표현
class Car {
public:
    // 멤버 변수 (상태)
    int speed;      // 속도
    int gear;       // 기어
    string color;   // 색상

    // 멤버 함수 (동작)
    void SpeedUp() {   // 속도를 10 증가시키는 함수
        speed += 10;
    }

    void SpeedDown() { // 속도를 10 감소시키는 함수
        speed -= 10;
    }
};

int main() {
    Car myCar;

    // 객체의 초기 상태 설정
    myCar.speed = 100;
    myCar.gear = 3;
    myCar.color = "red";

    cout << "1st speed: " << myCar.speed << endl;

    myCar.SpeedUp();   // 속도 증가 메서드 호출
    cout << "2nd speed: " << myCar.speed << endl;

    myCar.SpeedDown(); // 속도 감소 메서드 호출
    cout << "3rd speed: " << myCar.speed << endl;

    return 0;
}
