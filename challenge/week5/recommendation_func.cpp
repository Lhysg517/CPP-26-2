#include <iostream>
using namespace std;

// 사용자 수와 항목 수를 상수로 정의
const int NUM_USERS = 3;
const int NUM_ITEMS = 3;

// 사용자 선호도를 입력받는 함수
// 배열은 참조로 전달되므로, 함수 안에서 값을 채우면 main의 배열에도 반영된다
void initializePreferences(int preferences[NUM_USERS][NUM_ITEMS]) {
    for (int i = 0; i < NUM_USERS; i++) {
        cout << "사용자 " << i + 1 << "의 선호도를 입력하세요 ("
             << NUM_ITEMS << "개의 항목에 대해): ";
        for (int j = 0; j < NUM_ITEMS; j++) {
            cin >> preferences[i][j];   // i번 사용자의 j번 항목 선호도 입력
        }
    }
}

// 사용자별 추천 항목을 찾고 출력하는 함수
// 값을 수정하지 않으므로 const로 전달한다
void findRecommendedItems(const int preferences[NUM_USERS][NUM_ITEMS]) {
    for (int i = 0; i < NUM_USERS; i++) {
        int maxPref = preferences[i][0];  // 최대 선호도 (첫 번째 항목으로 초기화)
        int recommended = 0;              // 추천 항목의 인덱스

        for (int j = 1; j < NUM_ITEMS; j++) {
            // 엄격한 부등호(>)를 쓰면 동점일 때 먼저 나온 항목이 유지된다
            if (preferences[i][j] > maxPref) {
                maxPref = preferences[i][j];
                recommended = j;
            }
        }

        // 인덱스는 0부터 시작하므로 출력 시 +1
        cout << "사용자 " << i + 1 << "에게 추천하는 항목: "
             << recommended + 1 << endl;
    }
}

int main() {
    // 선호도를 저장할 2차원 배열 선언
    // 슬라이드의 "userPreferences가 어디갔을까?"에 대한 답: main에서 선언해야 한다
    int userPreferences[NUM_USERS][NUM_ITEMS];

    // 선호도를 초기화하고 사용자에게 추천할 항목 찾기
    initializePreferences(userPreferences);
    findRecommendedItems(userPreferences);

    return 0;
}
