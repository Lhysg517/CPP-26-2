#include <iostream>
#include <string>
using namespace std;

// PrintData 클래스: 같은 이름의 함수를 매개변수 타입/개수에 따라 다르게 정의 (오버로딩)
class PrintData {
public:
    void print(int i) { cout << i << endl; }                 // int 출력
    void print(double f) { cout << f << endl; }               // double 출력
    void print(string s = "No Data!") { cout << s << endl; }  // string 출력 (기본값 있음)
};

int main() {
    PrintData obj;

    obj.print(1);               // int 버전 호출 -> 1
    obj.print(3.14);            // double 버전 호출 -> 3.14
    obj.print("C++14 is cool."); // string 버전 호출 -> C++14 is cool.
    obj.print();                // 인자 없음 -> 기본값 "No Data!" 출력

    return 0;
}
