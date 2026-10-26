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


#include<iostream>
using namespace std;

int main(){
    int count = 0;
    for(int i =0;i<101;i++)
    {
         int a =i/10;
         int b =i%10;
        
         if (a==3 || a==6 || a ==9)
            count++;
        if (b==3 ||b==6| b==9)
             count++;
        if(count==0){
            cout<<i<<endl;
        }
        else{
            for (int j =0;j<count;j++){
               cout<< "짝";
            }
        }
    }
    return 0;
 
}