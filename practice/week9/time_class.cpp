#include<iostream>
using namespace std;

class Time{
public:
    int hour;
    int minute;
    Time(int h=0 ,int m=0){//생성자 중복 정의를 피하기 위해 기본값을 설정(디폴트 매개변수 + 생성자)
        hour =h; 
        minute = m;
    }

    void Print(){
        cout<< hour << " : " << minute << endl;
    }
};

int main(){
    Time a;//기본 생성자 위에 중복 정의 회피를 위해 기본값을 설정했기 때문에 가능
    Time b(10,30); //제일 최신 방법
  
    a.Print();
    b.Print();
 
    return 0;
}