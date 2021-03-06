#### C编译过程
- 预处理
- 编译 - 转汇编
- 汇编
- 链接

#### 用#define定义一个常数，表明1年中有多少秒
\#define SECONDS_PER_YEAR (60 * 60 * 24 * 365)UL

#### 用变量a给出下面的定义
- 一个整型数 # int a;
- 一个指向整型数的指针 # int \*a;
- 一个指向指针的指针，它指向的指针是指向一个整型数 # int \*\*a;
- 一个有10个整型数的数组 # int a[10];
- 一个有10个指针的数组，该指针是指向一个整型数的 # int \*a[10];
- 一个指向有10个整型数数组的指针 # int (\*a)[10];
- 一个指向函数的指针，该函数有一个整型参数并返回一个整型数 # int (\*a) (int);
- 一个有10个指针的数组，该指针指向一个函数，该函数有一个整型参数并返回一个整型数 # int (\*a[10])(int);

#### static关键字的作用
- 修饰局部变量，在调用过程中每次进来的值都是上一次指行完毕的值。
- 修饰全局变量，不能被模块外面的函数访问，只能被模块内的函数访问。
- 修饰函数，该函数只能被模块内的函数访问。

#### const关键字的含义
const修饰的内容是只读的

- const int a; 常整型数
- int const a; 与上面一样，常整型数
- const int \*a; 指向常整型数的指针，指针指向的数不能改，但指针可以指向其它的。
- int\* const a; 指向整型数的常指针，指针指向的内容可以改，但是这个指针不能指向其它的。
- int const \*a const; 指针和指向的数都不能改。

#### volatile关键字
一个定义为volatile的变量说明这个变量可能会被意想不到地修改，需要每次都去内存里读，而不是直接读寄存器里的备份。一般会用在多线程的情况。

#### C中的内存分块
- BSS段，存放未初始化的全局变量和静态变量
- Data段，存放已经初始化的全局变量和静态变量
- 代码段，存放代码
- 堆，存放由程序员分配的内存
- 栈，函数的入参，局部变量

#### 堆栈溢出一般是由上面原因导致的
- 没有回收垃圾资源
- 层次太深的递归调用
- 巨大的数组

#### const与#define相比的优点
const是由数据类型的，编译的时候就会检查，而宏定义只是简单的替换，并不会检查。

#### sizeof(指针)的大小
有系统决定，32位系统是4 Byte，64位系统是8 Byte

#### 如何判断一个系统是大端还是小端系统
定义一个int型的数，用char指针一位一位地输出。

#### 如何用二进制表示一个负数
正数按位取反后 + 1

#### padding，通知编译器在编译的时候不要添加额外的对齐
```c
struct __attribute__((__packed__)) mystruct_A {
    char a;
    int b;
    char c;
};
```

#### 当main()函数执行的时候，发生了什么
- 由shell进程fork()一个子进程
- 调用exec()
- 调用ld-linux动态链接器创建内存映像
- 将可执行ELF文件的内存段load到内存映像中
- 将动态链接的ELF文件的内存段load到内存映像中
- 立刻就重定位或者等到跑到这段需要动态链接的代码的时候再重定位
- 关闭文件描述符
- 将控制权交给程序

#### malloc, calloc, zalloc区别
```c
void* malloc(numElements * sizeofElements); //不会初始化，需要通过memset初始化
void* calloc(numElements, sizeofElements); //初始化为0，指针不会被初始化为NULL
void* zalloc(numElements * sizeofElements); //分配的内存都填了0
```

#### inline关键字的作用
- 被inline关键字修饰的函数，在编译的时候会被编译器展开copy到引用的地方
- 是否copy是由编译器自己判断的，如果函数太长，编译器也有可能不展开copy
- 必须在.h文件里加上定义，因为在函数展开后函数名就没有了，每个include这个头文件的调用都需要知道它的函数名
- 优点：
  - 减少调用时入栈出栈的开销
  - 函数调用有可能引起缺页，降低页置换的概率
- 缺点：
  - 在每个调用的地方都有一份copy，代码冗余

#### union用法
```c
union var{
	char ch;
	int num1;
	double num2;
};
```
union中每个成员共用一段空间，类似于一个变量的不同表现形式

#### gdb
- gcc -g -o xxx.o xxx.c 打开gdb的开关
- gdb -p ./xxx.o
- list main
- bt 列出函数调用顺序
- frame N 进到某个函数栈里
- info args
- info locals
- info frame
- info variables
- break
- next
- run
- print
- disassemble func
- x/ 查看内存


