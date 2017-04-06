#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{
        char str[10000];
        wchar_t wstr[] = {0xD2,0xCE,0xAE,0xB0,0xE3,0xC4,0xC7,0xC3};
        setlocale(LC_ALL, "");
        wcstombs(str, wstr, sizeof(str)/sizeof(char));
        printf("%s", str);
        return 0;


}
