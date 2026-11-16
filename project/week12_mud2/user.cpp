
#include "user.h"

// 생성자
User::User()
{
    hp = 20;
    itemCnt = 0;
}

// HP 증가
void User::IncreaseHP(int inc_hp)
{
    hp += inc_hp;
}

// HP 감소
void User::DecreaseHP(int dec_hp)
{
    hp -= dec_hp;
}

// 현재 HP 반환
int User::GetHP() const
{
    return hp;
}

// 아이템 개수 증가
void User::IncreaseItemCnt(int cnt)
{
    itemCnt += cnt;
}

// 현재 아이템 개수 반환
int User::GetItemCnt() const
{
    return itemCnt;
}

// 출력 연산자 오버로딩
ostream& operator<<(ostream& os, const User& user)
{
    os << "현재 HP는 " << user.hp
       << "이고, 먹은 아이템은 "
       << user.itemCnt << "개 입니다.";

    return os;
}
