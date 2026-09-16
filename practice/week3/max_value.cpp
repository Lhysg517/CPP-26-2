#include<iostream>
using namespace std;

int main()
{
    char secret_code ='h';

    cout << "비밀코드를 입력하시오 : ";
    char code;
    cin >> code;
    if(code<secret_code)
    {
        cout << code << "뒤에 있음." << endl;
    }
    else if(code>secret_code)
    {
        cout << code << "앞에 있음." << endl;
    }
    else
    {
        cout << "비밀코드가 맞습니다." << endl;
    }
    return 0;
}