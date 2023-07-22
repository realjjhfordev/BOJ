#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair 함에서 first, second를 줄여서 쓰기 위해서 사용
char board[1002][1002];
int fire[1002][1002];
int man[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;

  while(tc--)
  { 
    
    queue<pair<int, int>> Qfire; // 반복문 for의 함정, https://treeroad.tistory.com/entry/반복-for-의-함정  
    queue<pair<int, int>> Qman;  // 반복문이 한차례 돌면 이 변수들은 초기화됨

    bool escape_success = false;

    int w, h; // h행 w열
    cin >> w >> h;

    // 초기세팅

    for(int i = 0; i < h; i++) // 문자열 입력받기
      cin >> board[i];


    for(int i = 0; i < h; i++) // -1로 초기화 for bfs
    { 
      fill(fire[i], fire[i] + w, -1);
      fill(man[i], man[i] + w, -1);
    }

    
     for(int i = 0; i < h; i++) // 행
     {
      for(int j = 0; j < w; j++) // 열
       {
        if(board[i][j] == '@') // man
          {
            Qman.push({i,j});
            man[i][j] = 0;
          }

        if(board[i][j] == '*') // fire
          {
            Qfire.push({i,j});
            fire[i][j] = 0;
          }
        }
     }

    while(!Qfire.empty())                        // fire bfs
    {
      auto cur = Qfire.front(); Qfire.pop();
      for(int dir = 0; dir < 4; dir++)
      {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];

        if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue; // 범위 이탈
        if(fire[nx][ny] != -1 || board[nx][ny] == '#') continue; // 벽이 아닌(사람, 빈공간) 위치이면서 방문한 적이 없는 경우 // 벽이거나 방문한 적이 있거나
        
        fire[nx][ny] = fire[cur.X][cur.Y] + 1;
        Qfire.push({nx,ny});
      }
    }



    while(!Qman.empty() && escape_success == false)        // man bfs
    {
      auto cur = Qman.front(); Qman.pop();
      for(int dir = 0; dir < 4; dir++)
      {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];

        if(nx < 0 || ny < 0 || nx >= h || ny >= w) // 성공
        {
          escape_success = true;
          cout << man[cur.X][cur.Y] + 1 << '\n';
          break;
        }

        if(man[nx][ny] != -1 || board[nx][ny] == '#') continue; // 벽이 아닌(사람, 빈공간) 위치이면서 방문한 적이 없는 위치를 탐색하고자 함 // 벽이거나 방문한 적이 있거나 -> 패스
        if(man[cur.X][cur.Y] + 1 >= fire[nx][ny] && fire[nx][ny] != -1) 
        {
          man[nx][ny] = 0; // pass 대상, 의미없는 재방문 방지를 위해 방문표시만 남기고 패스함
          continue; // 이미 가고자하는 경로(nx, ny)에 불길이 번진 경우 패스, fire가 -1인 경우는 그 장소에 불이 안붙는 것 (nx,ny 위치에 저장된 값 == (cur.x, cur.y) + 1 값)
        }
        man[nx][ny] = man[cur.X][cur.Y] + 1;

        Qman.push({nx,ny});
      } // for loop
    } // while(bfs) end

    if(escape_success == false) cout << "IMPOSSIBLE" << '\n';

}

// Diffrence break with continue https://ponyozzang.tistory.com/673

// C++ 큐 초기화 하기 https://unluckyjung.github.io/cpp/2020/04/14/Queue_clear/

}