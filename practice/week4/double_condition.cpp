#include<stdio.h>

int main()
{
    int number1, number2;
    scanf_s("%d %d", &number1, &number2);

    if (number1 > 0)
    {
        if (number2 >0)
        {
            printf("%d %d 두 숫자 모두 함수입니다.\n",number1 ,number2);
        }
        else
        {
            printf("%d 만 양수입니다 .\n", number1);
        }
    }
    else
    {
        printf("%d 는 0이거나 음수입니다 .\n", number1);
    }
    return 0;
}