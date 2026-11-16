

#include <iostream>
#include <string>
#include <vector>
#include "user.h"
using namespace std;

const int mapX = 5;
const int mapY = 5;

// 함수 선언
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(const vector<vector<int>>& map, int user_x, int user_y);
bool checkGoal(const vector<vector<int>>& map, int user_x, int user_y);
bool CheckUser(const User& user);

void checkState(const vector<vector<int>>& map, int user_x, int user_y,
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

    // 사용자 초기 위치
    int user_x = 0;
    int user_y = 0;

    // User 객체 생성
    User user;

    // 장비 보유 여부
    bool hasWeapon = false;
    bool hasArmor = false;

    cout << "MUD 게임을 시작합니다." << endl;
    cout << "목적지까지 이동하세요." << endl;

    while (true)
    {
        string user_input = "";

        cout << endl;
        cout << "현재 HP: " << user.GetHP() << endl;
        cout << "현재 위치: (" << user_x << ", " << user_y << ")" << endl;

        cout << "무기: ";
        if (hasWeapon)
        {
            cout << "보유";
        }
        else
        {
            cout << "없음";
        }

        cout << " / 갑옷: ";
        if (hasArmor)
        {
            cout << "보유";
        }
        else
        {
            cout << "없음";
        }
        cout << endl;

        cout << "명령어를 입력하세요 (상,하,좌,우,지도,정보,종료): ";

        if (!(cin >> user_input))
        {
            cout << "입력이 종료되어 게임을 종료합니다." << endl;
            break;
        }

        // 이동할 좌표
        int next_x = user_x;
        int next_y = user_y;

        // 명령어 처리
        if (user_input == "상")
        {
            next_y -= 1;
        }
        else if (user_input == "하")
        {
            next_y += 1;
        }
        else if (user_input == "좌")
        {
            next_x -= 1;
        }
        else if (user_input == "우")
        {
            next_x += 1;
        }
        else if (user_input == "지도")
        {
            displayMap(map, user_x, user_y);
            continue;
        }
        else if (user_input == "정보")
        {
            cout << user << endl;
            continue;
        }
        else if (user_input == "종료")
        {
            cout << "게임을 종료합니다." << endl;
            break;
        }
        else
        {
            cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
            continue;
        }

        // 지도 밖 이동 확인
        bool inMap = checkXY(next_x, mapX, next_y, mapY);

        if (inMap == false)
        {
            cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
            continue;
        }

        // 정상 이동
        user_x = next_x;
        user_y = next_y;

        cout << "이동했습니다. ";
        cout << "현재 위치: (" << user_x << ", " << user_y << ")" << endl;

        // 이동할 때마다 HP 1 감소
        user.DecreaseHP(1);

        // 이동으로 HP가 0이 된 경우
        if (CheckUser(user) == false)
        {
            displayMap(map, user_x, user_y);

            cout << "HP가 0 이하가 되었습니다." << endl;
            cout << "실패했습니다." << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }

        // 현재 위치의 아이템, 적, 포션 확인
        checkState(map, user_x, user_y,
                   user, hasWeapon, hasArmor);

        // 이동 후 지도 출력
        displayMap(map, user_x, user_y);

        // HP 확인
        if (CheckUser(user) == false)
        {
            cout << "HP가 0 이하가 되었습니다." << endl;
            cout << "실패했습니다." << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }

        // 목적지 도착 여부 확인
        bool finish = checkGoal(map, user_x, user_y);

        if (finish == true)
        {
            cout << "목적지에 도착했습니다!" << endl;
            cout << "성공! 축하합니다!" << endl;
            cout << "게임을 종료합니다." << endl;
            break;
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
                int posState = map[i][j];

                switch (posState)
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


// 좌표 확인 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY)
{
    bool checkFlag = false;

    if (user_x >= 0 && user_x < mapX &&
        user_y >= 0 && user_y < mapY)
    {
        checkFlag = true;
    }

    return checkFlag;
}


// 목적지 확인 함수
bool checkGoal(const vector<vector<int>>& map, int user_x, int user_y)
{
    if (map[user_y][user_x] == 4)
    {
        return true;
    }

    return false;
}


// HP 확인 함수
bool CheckUser(const User& user)
{
    if (user.GetHP() > 0)
    {
        return true;
    }

    return false;
}


// 아이템, 적, 포션 확인 함수
void checkState(const vector<vector<int>>& map, int user_x, int user_y,
                User& user, bool& hasWeapon, bool& hasArmor)
{
    int posState = map[user_y][user_x];

    switch (posState)
    {
    case 0:
        // 빈 공간
        break;

    case 1:
        // 아이템 위치에 도착할 때마다 개수 증가
        user.IncreaseItemCnt(1);

        // 첫 번째 아이템: 무기
        if (user_x == 1 && user_y == 0)
        {
            cout << "무기가 있습니다." << endl;

            if (hasWeapon == false)
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

        // 두 번째 아이템: 갑옷
        else if (user_x == 0 && user_y == 1)
        {
            cout << "갑옷이 있습니다." << endl;

            if (hasArmor == false)
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

        // 무기를 보유한 경우
        if (hasWeapon == true)
        {
            cout << "무기를 사용하여 적을 처치했습니다!" << endl;
            cout << "적에게 추가 피해를 받지 않았습니다." << endl;
        }
        else if (hasArmor == true)
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
