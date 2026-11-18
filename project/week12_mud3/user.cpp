
#include "user.h"

using namespace std;

// User 생성자
User::User()
{
    hp = 10;
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

// 부모 클래스 공격 함수
void User::doAttack()
{
    cout << "공격합니다" << endl;
}

// Magician 공격 함수 재정의
void Magician::doAttack()
{
    cout << "마법 사용" << endl;
}

// Warrior 공격 함수 재정의
void Warrior::doAttack()
{
    cout << "베기 사용" << endl;
}

// 출력 연산자 중복
ostream& operator<<(ostream& os, const User& user)
{
    os << "현재 HP는 " << user.hp
       << "이고, 먹은 아이템은 "
       << user.itemCnt << "개 입니다.";

    return os;
}
