long long sum(int *a, int n) {
    long long ans = 0;
    
    for(int i = 0; i < n; i++)
    {
        ans = ans + a[i];
    }

    return ans;
}


/*
배열명 역할을 하는 포인터변수

배열명은 주소 → 포인터에 저장 가능

이 경우 포인터 변수명에 연산식이나 대괄호를 사용하여 배열요소를 쉽게 사용할 수 있다.

혼공C 269, 270P 참고
*/