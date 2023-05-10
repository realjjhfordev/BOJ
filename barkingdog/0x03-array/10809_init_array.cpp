#include <bits/stdc++.h>
using namespace std;


int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  int alphabet[26];
  string s;

  for(int k = 0; k < 26; k++)     // 배열 초기화할 땐 for문 돌리거나 fill함수
  {
   alphabet[k] = -1;
  }

  cin >> s;

  for(int i = 0; i < s.size(); i++)
  {
    if(alphabet[s[i]-'a'] == -1)
      alphabet[s[i]-'a'] = i;
    
  }

  for(int j = 0; j < 26; j++)
  {
   cout << alphabet[j] << " ";
  }
  
}
