
#include <stdio.h>
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  double x=2, z=2;
  int a=1, b=3;
  while(z>1e-15)
  {
    z = z*a/b;
    x += z;
    a++;
    b+=2;
  }
  Memo1->Text = AnsiString().sprintf("Pi=%.13f", x);
}
void __fastcall TForm1::Button2Click(TObject *Sender)
{
  const ARRSIZE=1010, DISPCNT=1000; //定义数组大小，显示位数
  char x[ARRSIZE], z[ARRSIZE]; //x[0] x[1] . x[2] x[3] x[4] .... x[ARRSIZE-1]
  int a=1, b=3, c, d, Run=1, Cnt=0;

  memset(x,0,ARRSIZE);
  memset(z,0,ARRSIZE);

  x[1] = 2;
  z[1] = 2;

  while(Run && (++Cnt<200000000))
  {
    //z*=a;
    d = 0;
    for(int i=ARRSIZE-1; i>0; i--)
    {
      c = z[i]*a + d;
      z[i] = c % 10;
      d = c / 10;
    }
    //z/=b;
    d = 0;
    for(int i=0; i<ARRSIZE; i++)
    {
      c = z[i]+d*10;
      z[i] = c / b;
      d = c % b;
    }
    //x+=z;
    Run = 0;
    for(int i=ARRSIZE-1; i>0; i--)
    {
      c = x[i] + z[i];
      x[i] = c%10;
      x[i-1] += c/10;
      Run |= z[i];
    }
    a++;
    b+=2;
  }
  Memo1->Text = AnsiString().sprintf("计算了 %d 次\r\n",Cnt);
  Memo1->Text = Memo1->Text + AnsiString().sprintf("Pi=%d%d.\r\n", x[0],x[1]);
  for(int i=0; i<DISPCNT; i++)
  {
    if(i && ((i%100)==0))
    Memo1->Text = Memo1->Text + "\r\n";
    Memo1->Text = Memo1->Text + (int)x[i+2];
  }
}
