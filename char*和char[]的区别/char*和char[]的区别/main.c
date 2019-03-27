//
//  main.c
//  char*和char[]的区别
//
//  Created by ifuwo on 2018/11/21.
//  Copyright © 2018 ifuwo. All rights reserved.
//


/*
 内存的分布排列如下：
 高地址
 stack : 系统自动管理，用来存储临时变量 read write
 heap : 由程序员分配和释放，用来存储需要长时间存在的变量  read wirte
 global & static(未初始化区域): 定义在全局的变量以及静态变量，read write
 global & static(初始化区域) : 定义在全局的变量以及静态变量，read write
 const : 常量 read
 code ： 代码区 read
 低地址
 */

/*
 
 // 栈区
 b ...528
   ...527 '\n'
   ...526 'c'
   ...525 'b'
 s ...524 'a'
 p2 ...518
 p3 ...510
 
 // global static
 
 p1 ...028
 
 c ... 024
   ... 023 00
   ... 022 00
   ... 021 00
a  ... 020 01

// 总结
 内存填充的时候，采取先填充小地址，在填充大地址的模式，例如 s变量的内容是 ‘abc’， 'a'的地址最小 ‘c’的地址最大
                                                 a变量的内容是 1。  1写入了地址最小的一个字节
 栈区内容分配的时候，从大地址开始分配，
 
 char *m = 'abc'; // m 是stack区指针，‘abc’是常量区常量. 'abc\n'注意\n
 char *m = (char *)malloc(10); // malloc 会开辟heap区内存, 所以 m指针在stack上，内容在heap
 char m[] = "abc"; // m是stack区指针，指向第一个字节a. 开辟3个字节，没有\n
 
 
 */

#include <stdio.h>

int a=1;    //全局初始化区
char *p1;   //全局未初始化区
int main()
{
    int b; //栈
    char s[]="abc";   //栈
    char *p2;         //栈
    char *p3="123456";   //123456\0在常量区，p3在栈上。
    static int c=0;   //全局（静态）初始化区
    p1 = (char*)malloc(10);
    p2 = (char*)malloc(20);   //分配得来得10和20字节的区域就在堆区。
    strcpy(p1,"123456");   //123456\0放在常量区，编译器可能会将它与p3所向"123456"优化成一个地方
    return 0;
}
