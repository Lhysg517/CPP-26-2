
#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User
{
private:
    int hp;
    int itemCnt;

public:
    // 생성자
    User();

    // HP 관련 함수
    void IncreaseHP(int inc_hp);
    void DecreaseHP(int dec_hp);
    int GetHP() const;

    // 아이템 개수 관련 함수
    void IncreaseItemCnt(int cnt);
    int GetItemCnt() const;

    // 출력 연산자 오버로딩
    friend ostream& operator<<(ostream& os, const User& user);
};

#endif
