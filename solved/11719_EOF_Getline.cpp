#include <bits/stdc++.h>
using namespace std;


int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  string s;

  while(getline(cin, s))
  {
    cout << s << '\n';
  }

  
}

/*


  string 라이브러리 속에 있는 getline 함수를 사용하여 문자열의 입력이 주어지면 string 객체에 저장한 뒤 출력하기로 하였다. 

+) istream 속 getline함수는 C언어 방식의 문자열을 처리하는 함수이다. 

 

● istream& getline(istream& is, string& str); 

● istream& getline(istream& is, string& str, char delim);

▷ param

- is : 입력스트림 오브젝트 ex) cin

- str : 입력 받은 문자열을 저장할 string 객체

- delim : 제한자로 이 문자에 도달시 추출이 중단된다. 이떄 이 문자는 string 객체에 기록되지 않는다. 

▷ description

- str이라는 string 객체에 is라는 입력스트림을 통해 문자열을 입력 받는다. (단, delim을 통해 입력받는 문자열에 제한을 둘 수 있음)

▷ return

- eof가 입력되면 0이 반환된다.
- getline 함수는 eof가 입력되면 0이 반환된다.

https://animoto1.tistory.com/entry/%EB%B0%B1%EC%A4%80-11718-%EA%B7%B8%EB%8C%80%EB%A1%9C-%EC%B6%9C%EB%A0%A5%ED%95%98%EA%B8%B0-C








문제에서 한 줄에 최대 100자가 들어온다는 말은 100자 이하가 들어온다는 것이 보장된다는 말이므로 
"100자를 넘어서 입력이 들어올 때 받지 말아야 하나?"와 같은 걱정은 하지 않아도 됩니다. (예외처리 안해도 됨)





/*

    End-of-file에 대한 이해 - 파일의 끝과 키보드를 통한 입력의 끝은 eof로 표현한다

    주어진 입력 파일만 갖고 입력을 받을 때 더이상 읽을 수 있는 데이터가 없는 경우 즉, 파일의 끝일 때 이를 EOF(End Of File) 이라고 한다.

    위 문제 입력에서 더이상의 읽을 수 있는 데이터가 존재하지 않을 때(더이상 키보드로 입력할 게 없을 때) 반복문을 종료하라는 것이다. (참고로 우리는 일상적으로 문장의 끝을 Enter로 치지만, Enter(개행) 또한 하나의 '문자'다. Ascii 코드표를 보면 LF(Line Feed, \n)가 눈에 보이지는 않지만 개행을 하는 값이다.)

    즉, 입력 스트림이 더이상 읽을 것이 없는 파일의 끝에 도달했을 때를 처리해야한다는 것이다.

    파일의 끝까지 읽었다고 EOF가 되는 것이 아니다. 끝까지 읽고난 뒤 그 다음 파일을 읽으려 할 때 읽을 데이터가 없을 때 EOF가 되는 것이다. (시점을 정확히 파악해야한다.)

 

파일뿐만 아니라 키보드를 통한 입력 시에도 입력이 끝났다는 것을 알려주는 방법이 필요합니다 -> 'EOF'

대부분의 유닉스(UNIX) 시스템에서는 라인의 시작 위치에서 Ctrl+D를 누르면 EOF를 발생시킬 수 있습니다.

윈도우 명령창에서는 해당 라인의 어디에서든 Ctrl+Z를 누르고 나서 Enter를 누르면 EOF를 발생시킬 수 있습니다.


이 문제의 목적은 문자열을 올바르게 입력받고 파일의 끝(EOF)을 올바르게 판단하는 법을 연습하는 것입니다.
총 몇 줄이 주어진다 등의 정보는 절대 입력으로 주지 않습니다. 
또한 단순히 키보드로 입력 내용만 적고 프로그램이 종료되지 않은 상태까지만 봐서는 EOF를 제대로 처리했는지 알 수 없습니다. 
더 이상 읽을 게 없을 때 프로그램을 종료하는 법을 알아야 합니다. 그 방법은 언어마다 다르고 사용하는 함수마다 다르니, 구글에 "C언어 EOF" 와 같이 검색해서 그 방법을 알아보세요. 

주로 파일 입출력으로 설명되어 있겠지만, 입력 스트림도 파일 입력이기 때문에 결국 동일합니다. 
자바의 경우 Scanner와 BufferedReader에서 해야 하는 처리가 서로 다릅니다. 언어를 불문하고, 레퍼런스를 참고해서 사용법을 정확하게 숙지하는 습관을 들이세요.

        (C/C++) scanf는 EOF를 반환하지, 변수에 저장해주지 않습니다.
        (Java) Scanner의 메서드들은 NoSuchElementException을 던집니다.
        (Java) BufferedReader.readLine()은 null을 반환합니다.
        (Python) input()은 EOFError를 발생시킵니다.
        (Python) sys.stdin.readline()은 빈 문자열을 반환합니다. 

이 문제에 대한 프로그램을 직접 테스트 해보려면 입력 내용을 파일에 저장해 놓고 freopen 등을 이용해서 프로그램에 표준 입력으로 보내주거나, 터미널에서 파이프로 넘겨주나, 또는 직접 키보드로 치다가 컨트롤 Z (윈도우즈), 컨트롤 D (맥, 리눅스) 를 눌러주는 방법이 있습니다. 이상하게도, 윈도우즈의 경우 컨트롤 Z를 여러 번 입력해줘야 인식되는 경우가 있는 것 같습니다.

    입력받은 내용을 모조리 저장해 놓고 나중에 몰아서 출력할 필요가 없습니다. 입력 스트림과 출력 스트림은 별개이므로, 입력받자마자 바로 출력해도 됩니다. 한 글자 단위로도 상관 없고, 한 줄 단위로도 상관 없습니다.

    불필요한 것들을 출력하면 틀립니다. 대표적으로, 매 줄마다 무조건 100글자를 출력하는 프로그램은 무조건 틀립니다. 입력받은 내용이 아닌 부분은 절대 출력하려 해서는 안 됩니다. 특히 널 문자는 일부 환경에서 공백과 비슷하게 출력되어 눈치채지 못하는 경우가 많은데, 널 문자도 엄연히 하나의 문자이며 이를 출력했을 경우 무조건 오답이 됩니다.

    100글자가 있는 한 줄을 통째로 입력받으려면 최소한 101칸이 있어야 됩니다. 마지막에 널 문자를 끼워넣어주기 때문입니다. 또한 fgets처럼 개행 문자까지 넣어주는 함수의 경우, 최소 102칸이 필요합니다. fgets에 넘겨주는 읽어들일 글자의 수 역시 최소 102여야 합니다.
    입력으로 들어오는 총 문자의 수는 최대 101(100+개행) * 100 = 10100자입니다.


*/
