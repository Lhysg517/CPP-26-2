#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1 = "사과";
    string s2;

    // s2 = s1 + " " + 10 + "개";
    // 문자열에 정수형 int 값인 10을 직접 더할 수 없기 때문에 에러가 발생한다.

    s2 = s1 + " " + to_string(10) + "개";

    cout << s2 << endl;

    return 0;
}