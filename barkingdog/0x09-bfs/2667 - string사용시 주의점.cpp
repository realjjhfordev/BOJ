#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair 함에서 first, second를 줄여서 쓰기 위해서 사용

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
string housemap[27];
int sqsize; // 정사각형의 한 변의 길이

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> sqsize;

  int danzi = 0; // 단지의 갯수
  vector<int> danzi_house; // 단지별 세대수를 저장하는 벡터
  queue<pair<int, int>> Q;

  for(int i = 0; i < sqsize; i++) // 지도 데이터 입력
  {
    cin >> housemap[i];
  }


  for(int i = 0; i < sqsize; i++) // 시작점 찾기
  {
    for(int j = 0; j < sqsize; j++)
    { 
      int housecount = 0; // 세대수

      if(housemap[i][j] != '1') continue; // 조건에 해당하는 경우에 대해 이리저리 진행하는 것이 아닌 조건에 안맞는 경우를 continue 하는 게 더 편함
      housemap[i][j] = '2'; // 방문체크
      Q.push({i, j});
      danzi++;
      

      while(!Q.empty()) // 찾은 시작점에 대해서 bfs를 진행
      { 
        housecount++;
        auto cur = Q.front(); Q.pop();

        for(int dir = 0; dir < 4; dir++)
        {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];

          if(nx < 0 || ny < 0 || nx >= sqsize || ny >= sqsize) continue;
          if(housemap[nx][ny] != '1') continue;

          housemap[nx][ny] = '2'; // 방문체크
          Q.push({nx,ny});
        }
      }

      danzi_house.push_back(housecount); // 세대수 기록

    }
  }

  sort(danzi_house.begin(), danzi_house.end());

  cout << danzi << '\n';

  for(auto i : danzi_house)
    cout << i << '\n';


}



// string 배열이므로 ' '를 사용하여 체크해주자 !!!
// string 배열이므로 ' '를 사용하여 체크해주자 !!!
// string 배열이므로 ' '를 사용하여 체크해주자 !!!