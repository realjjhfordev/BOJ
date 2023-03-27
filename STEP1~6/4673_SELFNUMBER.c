#include <stdio.h>

int ary[10001]; // ** 이 부분에서 배열의 모든 요소는 0으로 초기화가 됩니다 !! **

int selfnumber (int n)
{   
    int sum = n;

    while(n > 0)
    {
         sum = sum + (n%10);            
         n = n/10;
    } 
    return sum;
}

int main ()
{

    int temp;

    for (int i = 1; i<10001; i++)
    {
        temp = selfnumber(i); // 생성자에 의해 만들어진 수 temp

        if (temp<10001) {ary[temp] = 1;} // not a selfnumber 설정
    }


    for(int j = 1; j<10001; j++)
    {
        if (ary[j] != 1)
        {
            printf("%d\n", j);
        }
    }
    return 0;
}   


/*해당하는 case가 상당히 많은 경우, 여집합 개념으로 접근

→ 셀프넘버는 굉장히 많으므로, 전체 범위에서 셀프넘버가 아닌 숫자를 제외시키고 출력시켰음.

*전역변수 선언시 유저가 따로 초기화를 해주지 않으면 0으로 초기회됨*



각 자릿수 덧셈 알고리즘
while(n > 0)
{
sum = sum + (n%10);
n = n/10;
}
return sum;
*/