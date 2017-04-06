#include <fstream>
#include <stdio.h>
#include <cstring>
#define SIX_TIMES 10

using namespace std;

string current_six = "";

int main()
{

         ofstream output_file;
        int six_time;
         for (six_time = 0; six_time < SIX_TIMES; six_time++)
         {

                   current_six =  current_six +"6";
                   output_file.open("six.txt",  ios::out | ios::app );
                   /*
                   该死的网上代码，半吊子水平，连文件基本的打开方式都不对，
                   经过修改，变成在文件结尾输出，就可以了。


                   */

                   output_file << current_six.c_str() << endl;
                    output_file.close();
         }

    return 0;

}
