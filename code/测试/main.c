#include<stdio.h>
#include<bios.h>
#define Key_Up 0x4800    // 向上方向键 　　
#define Key_Down 0x5000  // 向下方向键
#define Key_Right 0x4d00  // 向右方向键
#define Key_Left 0x4b00   // 向左方向键
void main()
{
    int key=bioskey(0); 　　
    switch(key) 　　
    {
     　　case Key_Up : {printf(" 向上方向键被按下"); break;}　　
     　　case Key_Down : {printf(" 向下方向键被按下"); break;}
    　　 case Key_Left : {printf(" 向左方向键被按下"); break;}
    　　 case Key_Right : {printf(" 向右方向键被按下"); break;} 　　
    }
}
