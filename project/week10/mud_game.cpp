

#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;

// 함수 선언
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapY], int user_x, int user_y);
bool checkGoal(int map[][mapY], int user_x, int user_y);
void checkState(int map[][mapY], int user_x, int user_y, int& hp);

// 메인 함수
int main() {
    // 0: 빈 공간, 1: 아이템, 2: 적, 3: 포션, 4: 목적지
    int map[mapX][mapY] = {
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2}
    };

    // 사용자의 위치 및 체력
    int user_x = 0;
    int user_y = 0;
    int hp = 20;

    // 게임 시작
    while (true) {
        string user_input = "";

        cout << "현재 HP: " << hp << " ";
        cout << "명령어를 입력하세요 (상,하,좌,우,지도,종료): ";

        if (!(cin >> user_input)) {
            cout << "입력이 종료되어 게임을 종료합니다." << endl;
            break;
        }

        // 정상 이동 여부
        bool moved = false;

        if (user_input == "상") {
            user_y -= 1;
            bool inMap = checkXY(user_x, mapX, user_y, mapY);

            if (inMap == false) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_y += 1;
            }
            else {
                cout << "위로 한 칸 올라갑니다." << endl;
                moved = true;
            }
        }
        else if (user_input == "하") {
            user_y += 1;
            bool inMap = checkXY(user_x, mapX, user_y, mapY);

            if (inMap == false) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_y -= 1;
            }
            else {
                cout << "아래로 한 칸 내려갑니다." << endl;
                moved = true;
            }
        }
        else if (user_input == "좌") {
            user_x -= 1;
            bool inMap = checkXY(user_x, mapX, user_y, mapY);

            if (inMap == false) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_x += 1;
            }
            else {
                cout << "왼쪽으로 이동합니다." << endl;
                moved = true;
            }
        }
        else if (user_input == "우") {
            user_x += 1;
            bool inMap = checkXY(user_x, mapX, user_y, mapY);

            if (inMap == false) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_x -= 1;
            }
            else {
                cout << "오른쪽으로 이동합니다." << endl;
                moved = true;
            }
        }
        else if (user_input == "지도") {
            displayMap(map, user_x, user_y);
            continue;
        }
        else if (user_input == "종료") {
            cout << "게임을 종료합니다." << endl;
            break;
        }
        else {
            cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
            continue;
        }

        // 지도 밖으로 이동한 경우 HP 감소 없음
        if (moved == false) {
            continue;
        }

        // 정상 이동 시 HP 1 감소
        hp -= 1;

        // 현재 위치의 상태 확인
        if (hp > 0) {
            checkState(map, user_x, user_y, hp);
        }

        // 이동 후 지도 출력
        displayMap(map, user_x, user_y);

        // HP가 0 이하이면 실패
        if (hp <= 0) {
            cout << "HP가 0 이하가 되었습니다. 실패했습니다." << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }

        // 목적지 도착 여부 확인
        bool finish = checkGoal(map, user_x, user_y);

        if (finish == true) {
            cout << "목적지에 도착했습니다! 성공! 축하합니다!" << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }
    }

    return 0;
}

// 지도와 사용자 위치를 출력하는 함수
void displayMap(int map[][mapY], int user_x, int user_y) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == user_y && j == user_x) {
                cout << " USER |";
            }
            else {
                int posState = map[j][i];

                switch (posState) {
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
                }
            }
        }
        cout << endl;
        cout << " -------------------------------- " << endl;
    }
}

// 이동하려는 좌표가 유효한지 확인하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
    bool checkFlag = false;

    if (user_x >= 0 && user_x < mapX &&
        user_y >= 0 && user_y < mapY) {
        checkFlag = true;
    }

    return checkFlag;
}

// 사용자가 목적지에 도착했는지 확인하는 함수
bool checkGoal(int map[][mapY], int user_x, int user_y) {
    if (map[user_x][user_y] == 4) {
        return true;
    }

    return false;
}

// 무기, 갑옷, 적, 포션을 확인하는 함수
void checkState(int map[][mapY], int user_x, int user_y, int& hp) {
    int posState = map[user_x][user_y];

    switch (posState) {
    case 1:
        if (user_x == 1 && user_y == 0) {
            cout << "무기가 있습니다." << endl;
        }
        else if (user_x == 0 && user_y == 1) {
            cout << "갑옷이 있습니다." << endl;
        }
        else {
            cout << "아이템이 있습니다." << endl;
        }
        break;

    case 2:
        cout << "적이 있습니다." << endl;
        hp -= 2;
        cout << "적을 만나 HP가 2 감소했습니다." << endl;
        break;

    case 3:
        cout << "포션이 있습니다." << endl;
        hp += 2;
        cout << "포션을 만나 HP가 2 증가했습니다." << endl;
        break;

    default:
        break;
    }
}
