
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> scores;
    int score;
    int sum = 0;

    while (true) {
        cout << "성적을 입력하시오(종료는 -1) : ";
        cin >> score;

        if (score == -1) {
            break;
        }

        scores.push_back(score);
    }

    for (int i = 0; i < scores.size(); i++) {
        sum += scores[i];
    }

    if (scores.size() > 0) {
        int average = sum / scores.size();
        cout << "성적 평균=" << average << endl;
    }
    else {
        cout << "입력된 성적이 없습니다." << endl;
    }

    return 0;
}
