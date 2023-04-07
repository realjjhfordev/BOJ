#include <bits/stdc++.h>
using namespace std;

int main(void) 
{

int a, b, c;
string res;
int ary[10] = {0, };

cin >> a >> b >> c;
res = to_string(a * b * c); // number to string type

for(int i = 0; i < res.size(); i++)
{
  ary[res[i] - '0']++; // res[i]는 정수가 아니라 문자열 !!
}

for(int j = 0; j < 10; j++)
{
  cout << ary[j] << "\n";
}

}