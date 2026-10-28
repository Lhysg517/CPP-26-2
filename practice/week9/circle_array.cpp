#include<iostream>
using namespace std;

class Circle
{
    public:
    int x,y;
    int radius;
    Circle(){
        x=0;
        y=0;
        radius =0;
    }
    Circle(int x, int y ,int r){
        this->x =x;
        this->y=y;
        this->radius = r;
    }
    void Print(){
        cout<<"반지름: "<<radius << "@("<<x<<","<<y<<")"<<endl;
    }
};

int main(void){
    Circle objArray[10];

    for (Circle& c: objArray){// 참조자를 사용하지 않으면 배열의 원본 객체가 아닌 복사본의 값만 변경된다.
// 따라서 원본 배열의 객체들은 기본 생성자로 초기화된 0을 유지하므로 모두 0이 출력된다.
        c.x = rand()%500;
        c.y = rand()%300;
        c.radius = rand()%100;
    }
    for (Circle c: objArray){
        c.Print();
    }
    return 0;
}