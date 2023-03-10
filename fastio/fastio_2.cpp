#include <cstdio>

void printi(int num, char end)
{
    int i = num;
    int t;
    char cx;
    int a = 0;
    char temp[3];
    while (i != 0)
    {
        t = i % 10;
        i = i / 10;
        temp[a] = t + '0';
        a++;
    }
    for (i = a - 1; i >= 0; i--)
    {
        cx = temp[i];
        putchar(cx);
    }
    putchar(end);
}

int geti()
{
    int i = 0;
    char c;
    while ((c = getchar()) != ' ' && c != '\n')
    {
        i = i * 10 + c - '0';
    }
    return i;
}

int main()
{
    return 0;
}