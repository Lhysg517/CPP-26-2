#include<iostream>
using namespace std;

class Time{
int hour;
int minute;
public:
//int hour; 
//int minute;
    Time(int h, int m);     
    void IncHour();
    void Print();

    int GetHour() {
        return hour;
    }
    int GetMinute(){
        return minute;
    }
    void SetHour(int h){
        hour = h;
    }
    void SetMinute(int m){
        minute = m;
    }
};

Time::Time(int h , int m){
    hour =h;
    minute =m;
}
void Time::IncHour(){//외부 작성
    ++hour;
    if(hour>23){
        hour =0;
    }
}
void Time::Print(){
    cout<<hour<<":"<<minute<<endl;
}

int main(){
    Time a(0,0);
    //a.hour = 10;  //private 멤버이므로 접근 불가 class 내에서만 사용 가능
    //public에 멤버로 넣던가 아니면 SetHour()를 만들어서 접근해야함
    a.SetHour(10); // private 멤버로 접근후 출력
    a.SetHour(6);
    a.SetMinute(30);

    a.Print();
    return 0;
}