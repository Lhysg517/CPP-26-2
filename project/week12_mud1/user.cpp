
#include "user.h"

// 생성자: 초기 HP를 20으로 설정
User::User() {
    hp = 20;
}

// HP 증가
void User::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

// HP 감소
void User::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
}

// 현재 HP 반환
int User::GetHP(){
    return hp;
}