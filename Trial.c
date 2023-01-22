#include <stdio.h>
void callByValue(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    return;
}
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    callByValue(a, b);
    return 0;
}