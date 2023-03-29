#include <stdio.h>
#include <string.h>

int main()
{

    char a[4];
    char b[4];
    char temp;

    scanf("%s %s", a, b);

    temp = a[0];
    a[0] = a[2];
    a[2] = temp;

    temp = b[0];
    b[0] = b[2];
    b[2] = temp;

    // strcmp(a,b) 
    // a가 크면 양수, b가 크면 음수, 같으면 0을 반환

  if (strcmp(a, b) > 0) 
    {
        printf("%s\n", a);
    }

    else if (strcmp(a, b) < 0)
    {
        printf("%s", b);
    }

    return 0;
}