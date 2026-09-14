#include <iostream>
using namespace std;

int main()
{
    int money;
    int candy_price;

    cout << "현재 가지고 있는 돈: ";
    cin >> money;

    cout << "캔디의 가격 : ";
    cin >> candy_price;

    // 나눗셈의 몫으로 살 수 있는 최대 캔디 개수를 구한다.
    int candy_count = money / candy_price;

    // 나머지 연산으로 캔디 구입 후 남은 돈을 구한다.
    int remain_money = money % candy_price;

    cout << "최대로 살 수 있는 캔디 = " << candy_count << endl;
    cout << "캔디 구입 후 남은 돈 = " << remain_money << endl;

    return 0;
}