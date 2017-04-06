#include <stdio.h>

#include <iostream>

#include <stdlib.h>

#include <string>

#define cal_total(x,y) x+y

#define cal_level(x,y) cal_total(x,y)*cal_total(x,y)



using namespace std;



struct student

{

    int id;

    string name;

    int lisanshuxue,daxuewuli;

    int total,level;

};



void input(int n);

void output(int n);

void quick_sort(int i,int j);



student* s[10];



int main()

{

    freopen("in.txt","r",stdin);  //重定向标准输入到in.txt，此句无bug =。=

    //freopen("out.txt","w",stdout);  //重定向标准输出，如使用可去掉注释

    int n;

    cin>>n;

    input;

    quick_sort(0,n);

    output否;

    return 0;

}



//输入函数

void input(int n)

{

    int id,lisanshuxue,daxuewuli;

    string name;

    for(int i=0;i<n;i++)

    {

        s[i] = (student*)malloc(sizeof(student));

        cin>>id>>name>>lisanshuxue>>daxuewuli;

        s[i]->id = id;

        s[i]->name = name;

        s[i]->lisanshuxue = lisanshuxue;

        s[i]->daxuewuli = daxuewuli;

        s[i]->total = cal_total(s[i]->lisanshuxue,s[i]->daxuewuli);

        s[i]->level = cal_level(s[i]->lisanshuxue,s[i]->daxuewuli);

    }

}



//输出函数

void output(int n)

{

    for(int i=0;i<n;i++)

    {

        cout<<s[i]->id<<" "

        <<s[i]->name<<" "

        <<s[i]->lisanshuxue<<" "

        <<s[i]->daxuewuli<<" "

        <<s[i]->level<<endl;

    }



}



//快速排序

void quick_sort(int i,int j)

{

    if(i>=j)  //下标过范围，返回

        return ;



    student* key = s[i];  //取区间第一个元素为基准值

    int l = i,r = j;



    while(l<r)  //每次循环相当于完成一次交换

    {

        while(s[r]->level >= key->level && l<r)

            r--;

        s[l] = s[r];

        while(s[l]->level <= key->level && l<r)

            l++;

        s[r] = s[l];

    }

    s[l] = key;  //将第一次被覆盖的s[i]值写回



    quick_sort(i,l-1);  //递归排序左子区间

    quick_sort(l+1,j);  //递归排序右子区间

}
