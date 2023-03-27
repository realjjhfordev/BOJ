#include <stdio.h>

int main() 
{
    int a,b;
    while(scanf("%d %d", &a, &b)!=EOF) 
    {
        printf("%d\n", a+b);
    }
}
/*


    End-of-file에 대한 이해

    주어진 입력 파일만 갖고 입력을 받을 때 더이상 읽을 수 있는 데이터가 없는 경우 즉, 파일의 끝일 때 이를 EOF(End Of File) 이라고 한다.

    위 문제 입력에서 더이상의 읽을 수 있는 데이터가 존재하지 않을 때 반복문을 종료하라는 것이다. (참고로 우리는 일상적으로 문장의 끝을 Enter로 치지만, Enter(개행) 또한 하나의 '문자'다. Ascii 코드표를 보면 LF가 눈에 보이지는 않지만 개행을 하는 값이다.)

    즉, 입력 스트림이 더이상 읽을 것이 없는 파일의 끝에 도달했을 때를 처리해야한다는 것이다.

    파일의 끝까지 읽었다고 EOF가 되는 것이 아니다. 끝까지 읽고난 뒤 그 다음 파일을 읽으려 할 때 읽을 데이터가 없을 때 EOF가 되는 것이다. (시점을 정확히 파악해야한다.)

 

파일뿐만 아니라 키보드를 통한 입력 시에도 입력의 끝을 알려주는 방법이 필요합니다.

대부분의 유닉스(UNIX) 시스템에서는 라인의 시작 위치에서 Ctrl+D를 누르면 EOF를 발생시킬 수 있습니다.

윈도우 명령창에서는 해당 라인의 어디에서든 Ctrl+Z를 누르고 나서 Enter를 누르면 EOF를 발생시킬 수 있습니다.
*/