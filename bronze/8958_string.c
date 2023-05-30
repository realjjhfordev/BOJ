#include <stdio.h>
#include <string.h>
int main()
{
    int tc;
    char ary[81] = {0,};
    scanf("%d", &tc);
    
    for(int i = 0; i < tc; i++)
    {
        scanf("%s", ary);
        int score = 1;
        int sum = 0;
        for(int idx = 0; idx < strlen(ary); idx++)
        {
            if (ary[idx] == 'X')
            {score =1;}
            
            else if(ary[idx]=='O')
            {
                sum = sum + score;
                score++;    
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}

/*
연속된 문자열 출력시 bonus 점수

→ 초기값 1로 설정, 연속시 점수++

연속이 깨지면 1로 다 초기화
*/