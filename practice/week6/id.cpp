#include <iostream>
#include <string>
using namespace std;

// 주민등록번호를 입력받아 '-'를 제거하고 출력하는 프로그램
int main() {
    string s;
    cout << "주민등록번호를 입력하시오: ";
    cin >> s;

    cout << "-가 제거된 주민등록번호: ";
    for (char c : s) {
        if (c == '-') continue; // '-'는 건너뛰고 출력하지 않음
        cout << c;
    }
    cout << endl;

    return 0;
}
