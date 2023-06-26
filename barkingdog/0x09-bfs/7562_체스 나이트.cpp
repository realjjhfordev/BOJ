#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair 함에서 first, second를 줄여서 쓰기 위해서 사용

int board[302][302]; // chess board
int tc;
int dx[4]  =  {-2, -1, 1, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1}; 


int main ()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> tc;

  while(tc--)
  {
    int l; // 한 변의 길이

    pair<int,int> departure, destination; // 현재 칸과 목적지칸

    cin >> l >> departure.X >> departure.Y >> destination.X >> destination.Y;

    for(int i = 0; i < l; i++)  // 보드값 -1으로 초기화 시켜주기
      fill(board[i], board[i]+l, -1);

    queue<pair<int, int>> Q;
    Q.push({departure.X, departure.Y});
    board[departure.X][departure.Y] = 0;

    while(!Q.empty()) // bfs start
    {
      auto cur = Q.front(); Q.pop();

      for(int i = 0; i < 4; i++) // png파일 참고
      {
        for(int j = i*2; j <= i*2+1; j++)
        {
          int nx = cur.X + dx[i];
          int ny = cur.Y + dy[j];

          if(nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
          if(board[nx][ny] != -1) continue; // 방문한 적이 있다면 패스

          board[nx][ny] = board[cur.X][cur.Y] + 1;
          Q.push({nx, ny});
        }
      }
    }

    cout << board[destination.X][destination.Y] << '\n'; // 목적지에 저장되어 있는 값이 목적지까지 이동하는 데 걸리는 횟수이다

  } // test case end


}

// 목적지까지 걸리는 시간 bfs로 계산하는 문제