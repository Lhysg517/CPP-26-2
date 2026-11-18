
#ifndef WEEK12_MUD3_USER_H
#define WEEK12_MUD3_USER_H

#include <iostream>

using namespace std;

// 부모 클래스
class User
{
private:
    int hp;
    int itemCnt;

public:
    User();
    virtual ~User() = default;

    void IncreaseHP(int inc_hp);
    void DecreaseHP(int dec_hp);
    int GetHP() const;

    void IncreaseItemCnt(int cnt);
    int GetItemCnt() const;

    // 가상 함수
    virtual void doAttack();

    // 프렌드 출력 연산자
    friend ostream& operator<<(ostream& os, const User& user);
};

// 마법사 클래스
class Magician : public User
{
public:
    void doAttack() override;
};

// 전사 클래스
class Warrior : public User
{
public:
    void doAttack() override;
};

#endif
