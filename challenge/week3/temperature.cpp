#include <iostream>
using namespace std;

int main()
{
    double fahrenheit;

    cout << "화씨온도: ";
    cin >> fahrenheit;

    // 화씨온도를 섭씨온도로 변환한다.
    double celsius = (5.0 / 9.0) * (fahrenheit - 32);

    cout << "섭씨온도 = " << celsius << endl;

    return 0;
}