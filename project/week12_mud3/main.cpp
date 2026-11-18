

#include <iostream>
#include <string>
#include <vector>
#include "./user.h"
using namespace std;

const int mapX = 5;
const int mapY = 5;

// 캐릭터별 위치와 장비 상태
struct PlayerState
{
    int x = 0;
    int y = 0;
    bool hasWeapon = false;
    bool hasArmor = false;
    bool finished = false;
};

// 함수 선언
bool checkXY(int user_x, int user_y);
void displayMap(const vector<vector<int>>& map, int user_x, int user_y);
bool checkGoal(const vector<vector<int>>& map, int user_x, int user_y);
bool CheckUser(const User& user);

void checkState(const vector<vector<int>>& map,
                int user_x, int user_y,
                User& user, bool& hasWeapon, bool& hasArmor);

int main()
{
    // 0: 빈 공간, 1: 아이템, 2: 적, 3: 포션, 4: 목적지
    vector<vector<int>> map = {
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2}
    };

    // 자식 클래스 객체 생성
    Magician magician;
    Warrior warrior;

    // 부모 클래스 포인터로 자식 객체 관리
    User* users[2] = {&magician, &warrior};

    string names[2] = {"Magician", "Warrior"};

    PlayerState states[2];

    int turn = 0;

    cout << "MUD 게임을 시작합니다." << endl;
    cout << "Magician과 Warrior가 번갈아 게임을 진행합니다." << endl;

    while (true)
    {
        // 두 캐릭터 모두 종료되면 게임 종료
        if (states[0].finished && states[1].finished)
        {
            cout << "모든 캐릭터의 게임이 종료되었습니다." << endl;
            break;
        }

        int current = turn % 2;
        turn++;

        // 종료된 캐릭터는 건너뛰기
        if (states[current].finished)
        {
            continue;
        }

        User& user = *users[current];
        PlayerState& state = states[current];

        cout << endl;
        cout << "========== " << names[current]
             << " 차례 ==========" << endl;

        cout << "현재 HP: " << user.GetHP() << endl;
        cout << "현재 위치: (" << state.x
             << ", " << state.y << ")" << endl;

        cout << "무기: "
             << (state.hasWeapon ? "보유" : "없음");

        cout << " / 갑옷: "
             << (state.hasArmor ? "보유" : "없음") << endl;

        cout << "명령어를 입력하세요 "
             << "(상,하,좌,우,지도,정보,종료): ";

        string user_input;

        if (!(cin >> user_input))
        {
            cout << "입력이 종료되어 게임을 종료합니다." << endl;
            break;
        }

        int next_x = state.x;
        int next_y = state.y;

        // 명령어 처리
        if (user_input == "상")
        {
            next_y--;
        }
        else if (user_input == "하")
        {
            next_y++;
        }
        else if (user_input == "좌")
        {
            next_x--;
        }
        else if (user_input == "우")
        {
            next_x++;
        }
        else if (user_input == "지도")
        {
            displayMap(map, state.x, state.y);
            continue;
        }
        else if (user_input == "정보")
        {
            cout << names[current] << ": "
                 << user << endl;
            continue;
        }
        else if (user_input == "종료")
        {
            cout << names[current]
                 << "의 게임을 종료합니다." << endl;

            state.finished = true;
            continue;
        }
        else
        {
            cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
            continue;
        }

        // 지도 범위 확인
        if (!checkXY(next_x, next_y))
        {
            cout << "맵을 벗어났습니다. 다시 입력하세요." << endl;
            continue;
        }

        // 정상 이동
        state.x = next_x;
        state.y = next_y;

        cout << "이동했습니다. 현재 위치: ("
             << state.x << ", " << state.y << ")" << endl;

        // 이동 시 HP 감소
        user.DecreaseHP(1);

        if (!CheckUser(user))
        {
            displayMap(map, state.x, state.y);

            cout << names[current]
                 << "의 HP가 0 이하가 되었습니다." << endl;
            cout << "실패했습니다." << endl;

            state.finished = true;
            continue;
        }

        // 아이템, 적, 포션 처리
        checkState(map, state.x, state.y,
                   user, state.hasWeapon, state.hasArmor);

        // 지도 출력
        displayMap(map, state.x, state.y);

        // HP 확인
        if (!CheckUser(user))
        {
            cout << names[current]
                 << "의 HP가 0 이하가 되었습니다." << endl;
            cout << "실패했습니다." << endl;

            state.finished = true;
            continue;
        }

        // 목적지 도착 확인
        if (checkGoal(map, state.x, state.y))
        {
            cout << names[current]
                 << "이(가) 목적지에 도착했습니다!" << endl;
            cout << "성공! 축하합니다!" << endl;

            state.finished = true;
        }
    }

    return 0;
}


// 지도 출력 함수
void displayMap(const vector<vector<int>>& map, int user_x, int user_y)
{
    cout << endl;
    cout << "========== 전체 지도 ==========" << endl;

    for (int i = 0; i < mapY; i++)
    {
        for (int j = 0; j < mapX; j++)
        {
            if (i == user_y && j == user_x)
            {
                cout << " USER |";
            }
            else
            {
                switch (map[i][j])
                {
                case 0:
                    cout << "      |";
                    break;

                case 1:
                    cout << "아이템|";
                    break;

                case 2:
                    cout << "  적  |";
                    break;

                case 3:
                    cout << " 포션 |";
                    break;

                case 4:
                    cout << "목적지|";
                    break;

                default:
                    cout << "      |";
                    break;
                }
            }
        }

        cout << endl;
        cout << " -------------------------------- " << endl;
    }
}


// 지도 범위 확인 함수
bool checkXY(int user_x, int user_y)
{
    return user_x >= 0 && user_x < mapX &&
           user_y >= 0 && user_y < mapY;
}


// 목적지 확인 함수
bool checkGoal(const vector<vector<int>>& map, int user_x, int user_y)
{
    return map[user_y][user_x] == 4;
}


// HP 확인 함수
bool CheckUser(const User& user)
{
    return user.GetHP() > 0;
}


// 아이템, 적, 포션 확인 함수
void checkState(const vector<vector<int>>& map,
                int user_x, int user_y,
                User& user, bool& hasWeapon, bool& hasArmor)
{
    int posState = map[user_y][user_x];

    switch (posState)
    {
    case 0:
        break;

    case 1:
        // 아이템 위치 방문 시 개수 증가
        user.IncreaseItemCnt(1);

        // 무기 획득
        if (user_x == 1 && user_y == 0)
        {
            cout << "무기가 있습니다." << endl;

            if (!hasWeapon)
            {
                hasWeapon = true;
                cout << "무기를 획득했습니다!" << endl;
                cout << "이제 적을 만나면 처치할 수 있습니다." << endl;
            }
            else
            {
                cout << "이미 무기를 보유하고 있습니다." << endl;
            }
        }

        // 갑옷 획득
        else if (user_x == 0 && user_y == 1)
        {
            cout << "갑옷이 있습니다." << endl;

            if (!hasArmor)
            {
                hasArmor = true;
                cout << "갑옷을 획득했습니다!" << endl;
                cout << "적에게 받는 피해가 감소합니다." << endl;
            }
            else
            {
                cout << "이미 갑옷을 보유하고 있습니다." << endl;
            }
        }

        break;

    case 2:
        cout << "적이 있습니다." << endl;

        // 가상 함수를 통한 캐릭터별 공격
        user.doAttack();

        if (hasWeapon)
        {
            cout << "무기를 사용하여 적을 처치했습니다!" << endl;
            cout << "적에게 추가 피해를 받지 않았습니다." << endl;
        }
        else if (hasArmor)
        {
            user.DecreaseHP(1);

            cout << "갑옷으로 적의 공격을 방어했습니다." << endl;
            cout << "HP가 1 감소했습니다." << endl;
        }
        else
        {
            user.DecreaseHP(2);

            cout << "적에게 공격받았습니다." << endl;
            cout << "HP가 2 감소했습니다." << endl;
        }

        break;

    case 3:
        cout << "포션이 있습니다." << endl;

        user.IncreaseHP(2);

        cout << "포션을 사용하여 HP가 2 증가했습니다." << endl;
        break;

    case 4:
        // 목적지는 checkGoal()에서 처리
        break;

    default:
        break;
    }
}
