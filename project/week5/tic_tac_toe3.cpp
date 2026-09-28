#include<iostream> 
using namespace std; 
 
int main() 
{ 
    const int numCell =3; 
    char board[numCell][numCell]{}; 
    int x,y; // 사용자에게 입력받는 x,y 좌표를 저장할 변수 
 
    //보드판 초기화 
    for(x=0; x<numCell;x++) 
    { 
        for(y=0;y<numCell;y++) 
           board[x][y]=' '; 
    } 
 
  //게임하는 코드 
  int k =0;//누구 차례인지 체크하기 위한 변수 
  char currentUser ='X';//현재 유저의 돌을 저장하기 위한 문자 변수 
  while(true) 
 {  
    //1.누구 차례인지 출력 
    //3명이 되었기에 k%3 후 나오는 값따라서 case를 0,1,2로 나눈다.
    //0부터 % 계산시 나오는 값이 각각 0,1,2로 3명이 나눠진다.
    switch(k%3){ 
        case 0: 
           cout<<k%3+1<<"번 유저(X)의 차례입니다 ->"; 
           currentUser = 'X'; 
           break; 
        case 1: 
        cout<<k%3+1<<"번 유저(O)의 차례입니다 ->"; 
        currentUser ='O'; 
        break; 
        case 2:
        cout<<k%3+1<<"번 유저(Z)의 차례입니다 ->";
        currentUser ='Z';
        break;
        
    } 
    //2.좌표 입력 받기 
    cout<<"(x,y) 좌표를 입력하세요 : "; 
    cin>>x>>y; 
 
    //3.입력받은 좌표의 유효성 체크 
    if(x>=numCell || y>=numCell){ 
        cout<< x << ","<<y<<":"; 
        cout<<"x 와 y 둘 중 하나가 칸을 벗어납니다."<<endl; 
        continue; 
    } 
    if(board[x][y] != ' '){ 
        cout<<x<<", "<<y<<": 이미 돌이 차있습니다."<<endl; 
        continue; 
    } 
    //4.입력받은 좌표에 현재 유저의 돌 놓기 
    board[x][y] =currentUser; 
 
    //5.현재 보드 판 출력 
    for(int i =0;i<numCell;i++) 
    { 
        cout << "---|---|---"<<endl; 
        for(int j=0;j<numCell;j++) 
        { 
            cout<<board[i][j]; 
            if(j==numCell-1){ 
                break; 
            } 
            cout<<"  |"; 
        } 
        cout<<endl; 
    } 
    cout<<"---|---|---"<<endl; 

    // 6. 빙고 시 승자 출력 후 종료
  bool bingo = false;

  // 가로 확인
    for (int i = 0; i < numCell; i++)
   {
     if (board[i][0] == currentUser &&
        board[i][1] == currentUser &&
        board[i][2] == currentUser)
     {
        cout << "가로에 모두 돌이 놓였습니다!! "
             << k % 3 + 1 << "번 유저(" << currentUser
             << ")의 승리입니다!" << endl;
        bingo = true;
        break;
     }
   }

  // 세로 확인
   if (bingo == false)
   {
    for (int i = 0; i < numCell; i++)
    {
        if (board[0][i] == currentUser &&
            board[1][i] == currentUser &&
            board[2][i] == currentUser)
        {
            cout << "세로에 모두 돌이 놓였습니다!! "
                 << k % 3 + 1 << "번 유저(" << currentUser
                 << ")의 승리입니다!" << endl;
            bingo = true;
            break;
        }
    }
   }

  // 왼쪽 위 -> 오른쪽 아래 대각선
   if (bingo == false &&
    board[0][0] == currentUser &&
    board[1][1] == currentUser &&
    board[2][2] == currentUser)
   {
    cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!! "
         << k % 3 + 1 << "번 유저(" << currentUser
         << ")의 승리입니다!" << endl;
    bingo = true;
   }

  // 오른쪽 위 -> 왼쪽 아래 대각선
   if (bingo == false &&
    board[0][2] == currentUser &&
    board[1][1] == currentUser &&
    board[2][0] == currentUser)
  {
    cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!! "
         << k % 3 + 1 << "번 유저(" << currentUser
         << ")의 승리입니다!" << endl;
    bingo = true;
  }

  // 빙고면 종료
  if (bingo == true)
  {
    cout << "종료합니다" << endl;
    break;
  }
  k++;
  // 모든 칸이 찼을때
  if(k==numCell*numCell)
  {
    cout<<"모든 칸이 다 찼습니다. 게임을 종료합니다."<<endl;
    break;
  }
 
   
  }
  return 0;
}