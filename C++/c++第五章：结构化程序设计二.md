一个c++程序可以包含很多个函数，源代码可能会很长，可以将这些函数分散保存在不同的源文件中，以**多文件结构**的形式来组织和管理源代码。

程序员可以在c++源程序中插入一些特殊指令，其作用是告诉编译器该如何编译本程序，正式编译源程序之前，编译器将预先处理这些特殊指令，因此它们被称为**编译预处理指令**。

本章将介绍c++语言中几种特殊形式的函数，以及由c++编译系统为程序员提供的一些常用函数，这些函数被统称为**系统函数**。

程序设计可能会面临比较复杂的数据，这时程序员需要基于基本数据类型来自己定义新的数据类型，这就是自定义数据类型。数组就是一种自定义数据类型，本章讲讲解几种常用的自定义数据类型

# 一、c++源文件的多文件结构

一个c++程序可以包含很多个函数，源代码可能会很长，可以将这些函数分散保存在不同的源文件中，以**多文件结构**的形式来组织和管理源代码。

结构化程序设计，将一个复杂任务分解成多个模块，编码时，讲每个模块定义成一个函数，基于团队协作开发程序时，可以将不同模块的程序设计和编码任务交由不同的程序员去完成，程序员各自独立编程，将所编写的源程序代码保存在自己的源文件中，这样可以互不干扰，基于团队协模式开发的c++程序会自然形成多文件结构

**工程：**一个程序开发项目又称为工程，一个工程通常包含多个源程序文件，c++语言的源程序文件名为.cpp。一个源程序文件可以包括多个函数，一个函数只能集中放在一个源程序文件中，不能将函数定义分开存放在不同文件中，一个程序工程中可以包括很多个函数，但是只有一个主函数，函数名必须为main()

**编译器：**使用编译器将c++语言翻译成机器语言，编译时，同一源程序文件中的所有函数，被统一编译，因此一个源程序文件被称为一个编译单元，每个源程序编译后都生成一个目标程序，目标程序的扩展名通常为.obj，目标程序是机器语言的程序，机器语言与cpu相关，相同的c++源程序，可以被不同编译器编译，生成不同机器语言的目标程序，从而运行于不同类型的cpu之上，

**连接器**：每个源程序文件编译后都生成一个目标程序文件，使用连接器，将多个目标程序连接在一起，最终生成一个可执行程序文件。在windows操作系统上，可执行操作文件的扩展名通常为.exe，**可执行程序**是最终的程序，可以被计算机硬件执行。软件产品销售的是可执行程序，而源程序则是软件厂家的机密。可执行程序文件可以复制、分发安装并执行，但很难被阅读修改。

**多文件结构：**在多文件程序中，一个文件定义的函数，可以被其他文件函数调用。可以被其他文件调用的函数称为**外部函数**，一个文件中定义的全局变量，也可以被其他文件中的函数访问，可以被其他文件访问的全局变量，被称为**外部全局变量**。换句话说，一个文件中的函数，可以调用其他文件中的外部函数， 也可以访问其他文件中的外部全局变量，调用外部函数时，需要先申明再调用，访问外部全局变量时，也需要现声明再访问，**声明的作用，是将外部函数或外部全局变量的作用域，延申到本程序文件中来**。下面以养鱼池造价测试程序进行拆分说明，多文件结构的具体语法和规则：

**源程序文件1.cpp：**内容包括全局变量和主函数的定义，假设由程序员甲所编写。

```c++
#include <iostream>
using namespace std;

void RectCost();
double CircleCost(double r);

double length,width; //? 全局变量：分别保存长方形养鱼池的长宽
double r1,r2; //? 全局变量：分别保存圆形清水池和污水池的半径
double totalCost = 0; //? 全局变量：用于保存最终结果，即总造价

int main()
{
    /*下来语句将使用键盘输入原始数据，保存到对应的原始变量中*/
    cout <<"请输入长方形的长宽：";
    cin>>length>>width;
    cout<<"请输入清水池和污水池的半径：";
    cin>>r1>>r2;
    RectCost();//调用函数RectCost计算长方形言语此造价
    totalCost += CircleCost(r1);//调用CircleCost计算清水池造价
    totalCost += CircleCost(r2);//再次调用CircleCost
    cout<<"工程总造价为："<<totalCost<<endl;
    return 0;
}
```

**源程序2.cpp：**包括两个用于计算的子函数，由程序员乙编写

```c++
extern double length,width;//声明外部全局变量：分别保存长方形养鱼池的长宽
extern double totalCost;//声明外部全局变量：用于保存最终计算结果，即总造价

void RectCost()
{
    double cost;
    cost = length*width*10; //直接读取全局变量length和width中的数据
    totalCost+=cost;//将计算结果直接累加到全局变量totalCost中。
}

double CircleCost(double r)
{
    double cost;
    cost = 3.14*r*r*10;
    return cost;
}
```

## 1.1 声明外部函数原型和外部全局变量的语法细则

- 声明外部函数原型

  声明外部函数原型，使用extern关键字，声明 外部函数时，extern关键字也可以省略。

  ```c++
  extern void RectCost();//声明RectCost函数
  void RectCost(); //extern关键字可以省略。
  ```

  使用extern关键字的作用是更明确的指出，所声明的函数是一个外部函数，

- 声明外部全局变量

  声明外部全局变量时，**必须加上extern关键字，不能初始化**。否则就变成了另外一条全局变量定义语句。连接时，会出现和其他文件定义的全局变量重名的错误。

  ```c++
  extern double totalCost; //声明外部全局变量totalCost
  double totalCost; //语法错误，不能省略extern关键字
  extern double totalCost = 0; //语法错误，外部全局变量不能初始化
  ```

- 外部函数可以只声明不调用，外部全局变量可以只声明不访问，也就是说，只声明不使用不会引起语法错误。

## 1.2  多文件结构

1. 源程序文件所定义的函数默认都是外部函数，可以被其他文件中的函数调用；所定义的全局变量默认都是外部全局变量，也可以被其他文件中的函数访问。
2. 外部函数和外部全局变量被多文件结构中的所有文件共享，其他文件只要经过声明都可以使用这些函数和全局变量
3. 多文件结构中，所有的外部函数不能重名，所有的外部全局变量不能重名，所有的外部函数和外部全局变量之间也不能重名

某些情况下，一个文件中定义的某些函数或全局变量只供文件内部的其他函数使用，c++语言可以将这些函数或全局变量定义成静态的，即**静态函数**或**静态全局变量**，另外c++语言还可以定义**静态局部变量**。

**静态函数与静态变量：**

1. **静态函数**

   定义函数时，再函数头前加**static**关键字，该函数就被定义为静态函数。静态函数只能被本文件内部的其他函数调用，其他文件不能调用，即使经过声明也不行。

   ```c++
   static void RectRoct()
   { ... ... }
   ```

   static关键字，将所定义的函数作用域，限制在本文件范围内，禁止延申到其他文件，合理定义静态函数，可以防止其他文件对该函数的误调用。**不同文件中的静态函数可以重名**

2. **静态全局变量**

   全局变量具有文件作用域，静态和非静态指的是他们能否被其他文件中的函数访问。

   定义全局变量时，在语句前加static关键字，该变量就被定义为静态全局变量，静态全局变量只能被本文将内的函数访问，其他文件不能访问，即使经过声明也不行。

   ```c++
   static double r1,r2;
   ```

   static关键字，将所定义的全局变量作用域，限制在本文件范围内，禁止延申到其他文件，合理定义静态全局变量，可以防止其他文件对该全局变量的误操作。**不同文件中的静态全局变量可以重名**

3. **静态局部变量**

   局部变量只具有块作用域，只能在本函数内部使用、访问，任何时候都不能被其他函数访问，更别说其他文件中的函数，c++语言中，局部变量有静态和非静态之分，但含义与全局变量相比较，是不一样的。

   **定义方法：**在函数体或复合语句中定义的变量就是局部变量，在函数体或复合语句中定义局部变量时，在语句前加“static”关键字，该变量就被定义为静态局部变量。

   **作用域：**在源程序中具有块作用域（与普通局部变量相同）

   **内存分配：**普通的局部变量在执行时，是自动分配内存的，而静态局部变量是静态分配内存，就是程序执行时立即分配内存，一直到程序执行结束才释放；存放在静态储存区（与全局变量相同）。

   综上所述，静态局部变量其作用域与局部变量相同，程序执行时，其内存生存期和存放位置与全局变量一样。也就是说，静态局部变量是一种居于全局变量和局部变量之间的一种折中变量。

   **演示程序：**对比静态和非静态局部变量

   ```c++
   #include <iostream>
   using namespace std;
   
   void func()
   {
       int x=0; //定义普通局部变量（非静态）x，初始化为0
       static int y=0;//定义静态局部变量y，初始化为0
       x++; y++; //对x，y同样做加1操作。
       cout<<x<<"and"<<y<<endl;
   }
   
   int main()
   {   
       /*
       x在动态储存区，计算机执行到其定义语句时，才分配内存，函数调用结束，其内存即被释放，第一次运行func结束时，x的值就被丢失了。再次调用时，从新赋值。
       y储存在静态内存区，程序加载时即分配内存，并初始化为0，其内存释放要等到源程序结束。因此第一次调用结束释放func的栈帧，不会影响到y的值。
       */
       func(); //调用函数func，函数中显示x=1，y=1，
       func(); //再次调用func，函数中显示x=1，y=2，
       return 0;
   }
   ```

   c++语言中的static关键字，是一个多义词，使用这个关键字定义局部变量和全局变量时，其含义是不一样的，程序员应该根据上下文来推断它的含义。

## 1.3 头文件

团队协作开发时，加上某个程序员编写了一个c++程序文件（假设为1.cpp），其中定义了一组函数，也定义了若干全局变量。其他程序员需要访问1.cpp中的函数或全局变量，就需要对这些函数或全局变量进行声明，访问多少个外部函数或全局变量，就需要写多少条声明语句。对于项目组的所有程序员，只要访问1.cpp中的函数或全局变量，就都需要在自己的程序文件中编写声明语句。编写这些声明语句时重复而枯燥的工作，为此c++语言引入了头文件（header）的概念。

程序员甲在编写好1.cpp源程序文件后，另外再编写一个头文件，其中包含1.cpp所有外部函数和全局变量的声明语句。习惯上将这个头文件命名为1.h（或1.hpp），即与源文件同名，扩展名为.h或.hpp，项目组的其他程序员需要访问1.cpp中的函数或全局变量，只要再自己的程序文件增加语句：**#include "1.h"**，该语句的作用就是将头文件1.h中的所有声明语句自动插入到该语句位置，这就消除了以往一条一条手工编写声明语句的繁琐。

```c++
#include <iostream>
using namespace std;

#include "2.h" //用于替代下方的函数声明语句。
// void RectCost();
// double CircleCost(double r);

double length,width; //? 全局变量：分别保存长方形养鱼池的长宽
double r1,r2; //? 全局变量：分别保存圆形清水池和污水池的半径
double totalCost = 0; //? 全局变量：用于保存最终结果，即总造价

int main()
{
    /*下来语句将使用键盘输入原始数据，保存到对应的原始变量中*/
    cout <<"请输入长方形的长宽：";
    cin>>length>>width;
    cout<<"请输入清水池和污水池的半径：";
    cin>>r1>>r2;
    RectCost();//调用函数RectCost计算长方形言语此造价
    totalCost += CircleCost(r1);//调用CircleCost计算清水池造价
    totalCost += CircleCost(r2);//再次调用CircleCost
    cout<<"工程总造价为："<<totalCost<<endl;
    return 0;
}
```

```c++
/* "2.h"头文件声明 */
void RectCost();
double CircleCost(double r);
```

头文件的内容主要包含，外部函数的申明，外部全局变量的申明，还包含一些共用的符号常量定义等等。插入头所使用的**include**指令是一种特殊指令，被称为编译预处理指令。

# 二、编译预处理指令

程序员可以再c++源程序中插入一些特殊指令，其作用时告诉编译器如何编译本程序。正式编译源程序之前，编译器预先处理这些特殊指令，他们被称为**编译预处理指令**，例如插入文件头所使用的"**#include**"指令

编译预处理指令，不属于c++语言的主体，是其附属组成部分，其作用时方便程序员使用c++语言编程，常用的编译预处理指令有：

1. 文件包含指令
2. 宏定义指令
3. 条件编译指令

在c++源程序中，编译预处理指令可以写在代码的任意位置，每条指令单独写一行，必须以井号"#"开头，不加分号";"结束符。

## 2.1 文件包含指令：**#include**

编写c++源程序时，程序员可以使用文件包含指令（#include）将某个指定文件的内容插入到程序代码的任意位置，通常是用于将某个头文件（.h）插入到源程序文件（.cpp）中。

编译一个c++源程序时，c++编译器会首先进行预处理，预处理时，编译器将指定文件的内容插入该代码位置，详细语法如下：

```c++
//编译预处理指令语法：文件报告指令
#include <文件名> //缺省路径时，编译器将到标准目录下搜索指定的文件。
#include "文件名" //缺省路径时，编译器将首先在当前目录下搜索，如果找不到指定文件，编译器将到标准目录下搜索指定的文件。
```

- **文件名**：通常不写完整的全路径文件名，而使用缺省值路径，只写头文件名，通常头文件被集中存放在2个目录下，一是c++编译器安装目录下的"include"子目录，该目录称为**标准目录**，二是源程序文件所在的目录，称为**当前目录**
- **#include <文件名>**：缺省路径时，编译器将到标准目录下搜索指定的文件。
- **#include "文件名"**：缺省路径时，编译器将首先在当前目录下搜索，如果找不到指定文件，编译器将到标准目录下搜索指定的文件。
- 文件必须以井号**"#"**开头，不加分号";"结束符。

## 2.2 宏定义指令：#define

用一个标识符来表示一段代码文本，这就称为一个**宏**（macro），其中的标识符称为**宏名**，所表示的代码文本称为**宏文本**，宏需要先定义再使用，习惯上，宏名用大写字母来命名。程序员编写指令时，使用宏定义指令#define来定义一个新的宏，这样凡是再后续代码中，需要用到宏代码的地方都可以用宏名来代替。宏可以使代码更加简洁，易于阅读。

宏定义指令是一个编译预处理指令，预处理时，编译器将源程序中所有的宏名自动替换回原来的宏文本，这称为宏替换或宏展开。c++语言有3种形式的宏：

1. 无参宏
2. 有参宏
3. 空宏

已经定义的宏，可以用宏**删除指令（#undef）**删除。

**实例代码：**定义无参宏

```c++
#define 宏名 宏文本
#define PI 3.14   //将常量3.14定义为符号常量PI
```

- 宏名需复合标识符的命名规则
- 宏文本指定宏名所表示的字符串，可以由任意字符组成，不需要加引号。

无参宏主要用于定义符号常量。

```c++
#include <iostream>
using namespace std;

#define PI 3.14  //将常量3.14定义为符号常量PI

int main()
{
    double r;
    cout<<"请输入圆的半径：";
    cin>>r;
    cout<<"圆的面积是："<<PI*r*r<<endl; //用符号常量PI代替3.14
    cout<<"圆的周长是："<<PI*2*r<<endl; //用符号常量PI代替3.14
    rerurn 0;
}
```

**实例代码：**有参宏

```c++
#define 宏名(参数列表) 宏文本
#define AREA(x) 3.14159*x*x 
```

- **宏名**：复合标识符的命名规则
- **参数列表**：指定若干可被替换的参数，参数间用逗号","隔开，
- **宏文本**：指定宏名所表示的字符串，可以由任意字符组成，不需要加引号，字符串通常是包含参数的表达式

利用有参宏，可以实现简单的函数功能。通过实例代码，可以写出一个计算圆面积程序。

```c++
#include <iostream>
using namespace std;

#define AREA(x) 3.14159*x*x 
int main()
{
    int r=5;
    cout<<"圆的面积为："<<3.14159*r*r<<endl;
    cout<<"圆的面积为："<<AREA(r)<<endl; //使用宏进行简写。
    return 0;
}
```

使用有参宏的实参可以是表达式，例如：

```c++
AREA(3+4) //执行预处理时，会展开为3.14159*3+4*3+4，这显然时不对的， 这是应为定义有参宏时的没有考虑到运算符计算的优先级问题。
    
/*从新定义AREA有参宏*/
#define AREA(x) 3.14159*(x)*(x)
AREA(3+4) //执行预处理时展开为3.14159*(3+4)*(3+4)
```

**实例代码：**空宏

```
#define 宏名 
```

- 宏名需要符合标识符命名规范，无宏文本。

定义空宏是为了配合条件编译指令使用。下面将做介绍，已经定义的有参宏、无参宏、空宏，都是用宏**删除指令（#undef）**删除。

```c++
#undef 宏明
//宏名就是指定将被删除的宏
```

删除宏以后，宏就不能再继续使用了。但可以再次被定义

## 2.3 条件编译指令

程序开发过程中，源程序可能有多个版本，例如不同语种的版本，或者是调试版本和发行版本，如果用不同的程序文件存放不同版本的源代码，文件数量将迅速增加，也容易导致代码修改时的不一致问题，条件编译指令运行程序员将不同版本的源代码写在同一程序文件中，便于管理维护修改，条件编译指令，有2种格式。

**编译预处理指令语法：**条件编译指令（格式1）

```c++
#ifdef 空宏名
	代码段1
#else
    代码段2
#endif
```

- 编译器在编译这段代码时，如果指定的空宏已定义，则编译代码段1，否则编译代码段2
- 如果没有代码段2，则可以省略**#else**

```c++
#include <iostream>
using namespace std;

#define PI 3.14159 //为pi定义一个符号常量
#define ENGLISH_VERSION //定义一个空宏ENGLISH_VERSION，将这条语句注释调，此程序就会编译成一个中文版程序。

int main()
{
#ifdef ENGLISH_VERSION //如果定义了ENGLISH_VERSION，则编译以下代码
    cout<<"Please input a radius";
#else //否则编译以下代码
    cout<<"请输入圆的半径";
#endif
	/* 以下2条指令是中英文版公用的指令，故无需指定条件编译*/
    double r;
    cin >>r;

#ifdef ENGLISH_VERSION
    cout<<"Area:"<<PI*r*r<<endl;
    cout<<"perimeter"<<PI*2*r<<endl;
#else
    cout<<"面积为："<<PI*r*r<<endl;
    cout<<"周长为"<<PI*2*r<<endl;
#endif

    return 0;
}
```

**编译预处理指令语法：**条件编译指令（格式2）

```
#ifdef 常量表达式
	代码段1
#else
    代码段2
#endif
```

- 编译器在编译这段代码时，如果指定的**常量表达式**结果不为0，则编译**代码段1**，否则编译**代码段2**，常量表达式只能包含常量或符号常量
- 如果没有代码段2，则可以省略**#else**

```c++
#include <iostream>
using namespace std;

#define PI 3.14159 //为pi定义一个符号常量
#define ENGLISH_VERSION 1 //定义一个符号常量ENGLISH_VERSION，值为1，则编译为英文版，当值设为0，将编译中文版。

int main()
{
#ifdef ENGLISH_VERSION //如果ENGLISH_VERSION的值不为0，则编译以下代码
    cout<<"Please input a radius";
#else //否则编译以下代码
    cout<<"请输入圆的半径";
#endif
	/* 以下2条指令是中英文版公用的指令，故无需指定条件编译*/
    double r;
    cin >>r;

#ifdef ENGLISH_VERSION
    cout<<"Area:"<<PI*r*r<<endl;
    cout<<"perimeter"<<PI*2*r<<endl;
#else
    cout<<"面积为："<<PI*r*r<<endl;
    cout<<"周长为"<<PI*2*r<<endl;
#endif

    return 0;
}
```

# 三、几种特殊形式的函数

## 3.1 带默认形参的函数

- 定义函数或声明函数原型时可以指定形式参数的默认值，这就是带默认形参值的函数
- 调用带默认形参值得函数时，如果给出实参值，则将实参值赋给形参变量，如果没有，则将默认值赋给形参变量。

**例子：**人民币汇率转换表（2015年6月19日）

| 外币（数量：1） | 人民币（单位：元） |
| --------------- | ------------------ |
| 美元            | 6.1104             |
| 欧元            | 6.9698             |
| 英镑            | 9.7347             |
| 港币            | 0.78817            |

```c++
#include <iostream>
using namespace std;

double Exchange(double amount=100,double rate=6.1104) //给定汇率默认形参值为美元的汇率
{
    return amount/rate;
}

int main()
{
    int x;
    cout <<"请输入人民数量，单位元：";
    cin >> x;
    cout<<x<<"元人民币="<<Exchange(x)<<"美元"<<endl; //人民币>>美元，计算美元时，不需要传递汇率
    cout<<x<<"元人民币="<<Exchange(x,6.9698)<<"欧元"<<endl; //人民币>>欧元
    cout<<x<<"元人民币="<<Exchange(x,9.7347)<<"英镑"<<endl; //人民币>>英镑
    cout<<x<<"元人民币="<<Exchange(x,0.78817)<<"港币"<<endl; //人民币>>港币
    return 0;
}
```

**带默认形参值函数的语法细则：**

- **带默认值的形参：**调用时如果给出实参值，则将实参值赋值给形参变量，如果没有，则将默认值赋值给形参变量，不带默认值的形参在调用时必须给出实参，否则属于语法错误。
- **在函数原型声明中指定默认值：**如果函数定义在调用语句之后，应该在调用语句之前对函数原型进行声明。可以在声明语句中指定形式参数的默认值，此时函数定义中不能再指定默认值。函数具有文件作用域，同一函数在相同的作用域中只能指定一次默认值。
- 如果函数定义在其他文件中，应该在调用语句之前声明外部函数的原型，可以在声明语句中指定形式参数在本文件中的默认值，并且可以与原函数定义中的默认值不同。
- 同一函数在不同的作用域中可以指定不同的默认值。如果多个默认值同时有效，调用函数时根据局部优先原则选择默认值。

**演示程序：**在不同作用域为函数形参指定默认值

```c++
#include <iostream>
using namespace std;

void fun(int p=10);//在申明函数fun时，指定文件作用域的形参p的默认值为10

int main()
{
	fun(); //使用文件作用域的默认值，函数fun的显示结果为10
	{
		void fun(int p=20);//再次申明函数fun，将具有块作用域的形参p的默认值为20
		fun(); //使用块作用域（局部优先），fun的显示结果为20
	}
	return 0;
}

void fun(int p) //在申明函数时，已经指定了p的默认值，此时不能再指定
{
	cout<<p<<endl; //显示形参p接收到的实参值
}
```

**带默认值的形参，必须定义在形参列表的后面**，形参列表中，可能有的形参带默认值，有的不带，定义函数或声明函数原型时，必须把带默认值的形参放在不带默认值的形参的后面。

## 3.2 重载函数

调用函数时通过函数名指定调用哪个函数，函数名是函数的标识，通常，同一文件之中的函数不能重名，不文件中的非静态函数（外部函数）之间也不能重名，

c++语言规定，如果两个函数的形参个数不同或数据类型不同，那么这两个函数就可以重名，重名的函数被称为重载函数。

将两个或两个以上函数定义为重载函数的原因，是这些函数的**功能相同或相近，**使用相同的名字方便码农记忆，也不用绞尽脑子去想如何起不同的名字

```c++
#include <iostream>
using namespace std;
// Max为重载函数名，功能是求最大值。
int Max(int x,int y){return ((x>y)?x:y);}
//double型浮点类型，为64位宽度，float型为32位宽度
double Max(double x,double y){return ((x>y)?x:y);}
int Max(int x, int y, int z)
{
    int m;
    m = (x>y)?x:y;
    m = (x>z)?m:z;
    return m;
}

cout<<Max(9,5); //自动调用：int Max(int x,int y)
cout<<Max(9.0,5.0); //自动调用：double Max(double x,double y)
cout<<Max(9,5,17); //自动调用：int Max(int x, int y, int z)
```

C++在编译语言时，由编译器根据调用语句中实参的个数和类型，来自动调用形参最匹配的那个重载函数，简而言之就是通过形参和实参的匹配原则来调用重载函数。

**注意：**在应用重载函数时，如果两个函数仅仅是返回值类型不同或形参名不同，那么不能讲这两个函数命名为重载函数，否则会出现语法错误。也不能将两个功能差异很大的函数命名为重载函数，虽然没有语法错误，但是会在运用中给程序员造成混淆。

## 3.3 内联函数

**调用函数：**函数跳转和数据传递需要执行一些额外的操作，实现相同的功能，单一主函数程序比主函数+子函数程序执行速度更快，及函数跳转会降低程序的执行效率，但函数是团队分工协作和代码重用的基础，函数能够提高程序的开发效率。

**内联函数：**内联函数是一种特殊的函数，它在保障程序开发效率的同时，不会减低程序的执行效率。

**其原理是：**编译源程序时将函数代码直接嵌入到每一个调用语句处，而在执行时不再进行函数跳转和数据传递。

```c++
#include <iostream>
using namespace std;

//使用inline关键字申明内联函数
inline double Exchange(double amount,double rate=6.1104)
{ return amount / rate; }


int main()
{
    int x;
    cout <<"请输入人民数量，单位元：";
    cin >> x;
    cout<<x<<"元人民币="<<Exchange(x)<<"美元"<<endl; //人民币>>美元
    cout<<x<<"元人民币="<<Exchange(x,6.9698)<<"欧元"<<endl; //人民币>>欧元
    cout<<x<<"元人民币="<<Exchange(x,9.7347)<<"英镑"<<endl; //人民币>>英镑
    cout<<x<<"元人民币="<<Exchange(x,0.78817)<<"港币"<<endl; //人民币>>港币
    return 0;
}
```

内联函数需要在被调用的函数前加上**inline**关键值进行申明。

**内联函数需要是简单的函数**，编译器不能保证程序员所定义或申明的内联函数最终都能按照内联的方式进行编译，如果该函数的函数体比较复杂，比如有循环语句，那么编译器将自动按照非内联函数的方式进行编译。

内联函数只有被多次调用，其执行效率才能体现出来，因此一般只是将频繁调用的简单函数，定义为内联函数。

## 3.4 带形参和返回值的主函数

计算机系统包括硬件和软件2部分，操作系统是计算机中最基础最重要的软件，操作系统直接运行于硬件之上，启动计算机后，计算机自动加载执行，只有在操作系统运行之后，其他软件才能运行，用户执行某个程序，其实是向操作系统下达了一个执行程序的指令。在命令行操作系统中，如果要执行某个程序，就可以下达类似于：test.exe或test指令，然后回车，操作系统接收该指令，然后将程序文件读入内存，找到该程序的主函数main，从主函的第一条指令开始执行，程序执行结束后，从主函数main返回操作系统。

可以将操作系统执行某个程序的过程，理解成操作系统调用该程序主函数main 的过程。

用户在向操作系统下的程序执行指令的同时，可以传递某些原始数据。也就是说，一个程序的主函数main可以定义形参，接收数据，可以定义返回值，将自己的运行状态返回给操作系统。

**c++程序中的主函数main()的语法细则：**

- 一个c++程序必须有并取只有1个名为main的主函数。
- 主函数是程序执行的起点
- 主函数不能被重载
- 主函数的类型应该为int型，需要返回一个int型整数
- 主函数可以
  1. 定义形参来接收实参数据
  2. 也可以省略形参（此时操作系统所传递过来的实参数据将被忽略）

定义有形参的主函数main：

```c++
int main(int argc, char*argv[])
{
    /*
    此处定义代码语句
    */
    return 0;
}
```

语法说明：

- argc标识所接收到的参数个数；
- argv是一个char型指针数组，数组元素分别为argv[0]~arbv[argc-1]。参数以字符串形式传递，其中argc[0]所指向的字符数组存放的是该文件程序的文件名，argc[1]所指向的字符数组存放的是第1个实参数据，......;
- 采用无参形式时，操作系统所传递过来的实参数据将被忽略
- 主函数通过返回值将自己的运转状态返回给操作系统，通常0表示正常，用-1表示异常。

代码示例：带形参和返回值的主函数定义格式

```c++
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    for(int n=0; n<argc; n++) //接收用户输入的参数，使用循环语句
        cout<<argv[n]<<endl; //显示用户输入的参数。    
    return 0;
}     
```

**Microsoft c++编译器对主函数语法处理的差异**

美国微软公司开发的c++编译器，在对c++语法的处理上有一定的差异，主要提现在visual c++ 6.0和visual studio系列这两个集成开发环境的使用上。

- visual c++ 6.0中，主函数可以没有返回值，也就是主函数可以定义为void，例如：

  ```c++
  #include <iostream>
  using namespace std;
  
  void main()
  {
      //此处定义函数体代码
      return; //如果该语句是最后一条语句，则可以省略
  }
  ```

- visual studio 系列集成开发环境

  该环境在主函数的定义上，于其他环境有所区别，该系列可以使用应用程序向导来新建开发项目，例如：假设我们新建win32控制台应用程序，该环境将自动创建一个c++源文件，该文件的文件头和主函数如下：

  ```c++
  #include "stdafx.h" //包含visualstudio集成开发环境所必须的一些信息。
  int _tmain(int argc, _TCHAR *argv[]) 
  {
      system("pause");//添加该语句，暂停程序执行，以便程序员检查运行结果。
      return 0;
  }
  ```

  这是因为visual studio集成开发环境同时支持ANSI编码和Unicode编码的程序开发，使用**_tmain()**命名主函数，可以很方便的在两种字符代码之间切换。

  初学者使用visual studio时，可以选择空项目，然后自己添加新建源程序文件，在return语句之前，记得加入一个system("pause");添加该语句，暂停程序执行，以便程序员检查运行结果。

- 使用Windows图形界面程序时

  需要将主函数定义为WinMain()或_tWinMain()，这个时windows运用程序执行的起点。这两个名字是微软公司为Windows图形界面的主函数所指定的函数名。并不是c++标准指定的。

## 3.6递归函数

假设要求一个数N的阶乘，也就是求N!

**1、递推法：**

递推法利用已知条件（0！= 1）和地推公式：

n！= n x（n-1）

逐步递推求出1！、2！、... ...、直到求出N！

```c++
#include <iostream>
using namespace std;

int Factorial(int N)
{
    int result = 1; //已知：0！=1
    for(int n = 1; n<=N;n++)
        result = n*result; //递推公式：n！= n*（n-1）
    return result;    
}

int main()
{
    int N;
    cout<<"请输入原始值N：";
    cin>>N;
    cout<<Factorial(N);
    return 0;
}
```

递推法求解问题的基本思想是从已知条件出发，根据地推公司由简到繁，逐步逼近，最终求出问题的解，这种方式也称为正向递推。正向递推的每一步骤都是已知问题n-1的解，递推求解问题n的解，这些递推步骤是在重复计算递推公式，可使用循环结构来描述递推算法。

**2、递归法：**

递归法是程序设计中一种基于**“函数嵌套调用”**原理求解问题的方法。递归法求解问题的过程分2步完成：

1. **第一步**

   按照递推公式由繁到简，将求问题n的解降阶成求问题n-1的解，直到满足已知条件（称为递归终结条件）不能降阶为止，这个过程称为逆向递推；

2. **第二步**

   函数逐级返回结果，最终求出问题的解，这个过程称为回归。

```c++
#include <iostream>
using namespace std;

int Factorial(int N)
{
    int result; //用于保存结果
    if(N==0)
        result=0;
    else if(N==1)
        result = 1; 
    else
        result = N*Factorial(N-1); //调用自身，参数降阶为N-1    
    return result;   
}

int main()
{
    int N;
    cout<<"请输入原始值N：";
    cin>>N;
    cout<<Factorial(N);
    return 0;
}
```

c++语言将直接或间接调用自身的函数，称为**递归函数**。

与前面所讲解的重载函数，带默认形参值、内联函数的函数不同的是，递归函数不仅仅是一个语法概念，其背后还暗含了递归法求解问题的算法设计思想。

**递归函数的定义和调用：**

```c++
函数类型 函数名(形式参数列表)
{
    ... ...
    if(递归终结条件) //条件一
        取得已知结果 //条件二
    else
        按照递归公式调用自身 //条件三
    ... ...
}
```

递归函数的执行过程：

1. 计算机在执行函数调用语句跳转到被调函数时，为其形参及函数体中定义的局部变量分配内存，建立被调函数的**栈帧**
2. 函数可以**嵌套调用**，每增加一级函数调用，栈帧就增加一个，每退出一级函数调用，栈帧就减少一个
3. 计算机执行**递归函数**的过程就是递归函数**不断嵌套调用自身**、**不断建立新栈帧的过程**，即**逆向递推**的过程。
4. 当**递归终结条件**成立时停止调用，开始**逐级返回**结果，退出递归函数并依次释放栈帧，这就是**回归**的过程。

递归的函数嵌套调用，次数必须是有限的，无线调用，会不停建立新的栈帧，最终超出程序的内存占用，会导致栈溢出的错误。

1. 递归法比递推法速度慢。

   递推算法使用循环算法来实现，速度块，递归算法，使用函数调用，需要额外的操作， 因此速度慢

2. 递归法比递推法适用范围广

   能用递推求解的算法，一定可以使用递归来求解，反之则不然。

**汉诺塔问题：**

```c++
#include <iostream>
using namespace std;

void hanoi(int N,char source, char relay, char destination)
{
    if(N==1)
        cout<<source<<"-->>"<<destination<<endl;
    else
    {
        /*hanoi(N-1,source=a,destination=b,relay=c)把a上的N-1个盘中移到b*/
        hanoi(N-1, source, destination, relay); 
        cout<<source<<"-->>"<<destination<<endl;// a-->>b
        /*hanoi(N-1,relay=a, source=b, destination=c)把b上的N-1个移动到c*/
        hanoi(N-1, relay, source, destination);
    }
}

int main()
{
    int N;
    cout<<"请输入要移动的圆盘数量N：";
    cin>>N;
    cout<<"移动"<<N<<"个盘子的步骤"<<endl;
    hanoi(N,'a','b','c');
    return 0;
}
```

# 四、系统函数

程序员编写的函数可以在下个项目中继续使用，这就是重用函数的代码，随着时间的推移，程序员将积累越来越多的函数，重用这些函数，可以显著的提高开发效率

c++也预先编写了很多常用的函数，提供给广大程序员使用，这些函数统称为**系统函数**

c++语言是在C语言基础上发展而来的，C语言是机构化程序设计语言，系统函数是其重要的附属组成部分。C语言函数的源代码，被编译成机器语言，以库文件的形式，随编译器系统提供。库文件的名称，通常为”.lib“，库文件通常存在编译器安装文件目录中的lib子目录中，这些库文件被称为**标准C库**。

调用标准C库中的系统函数，都需要先声明其函数原型，为了方便程序员，C语言预先编写好这些系统函数的原型声明语句，并按功能分别保存在若干个不同的头文件中。程序员只要用#include指令，包含相应的头文件，就可以调用这些系统函数。程序链接时，被调用的系统函数代码将被连接到可执行程序文件之中。

c++语言全盘继承了C语言的标准C库，另外又增加了一些新的库，新库中包括了新增的系统函数，但更对的是新增了面向对象的系统类库，这些新库，就被称为**c++标准库**。c++标准库引入了**命名空间**的概念，所有的新增的系统函数和系统类库，都定义在命名空间**std**当中。

## 4.1 C语言系统函数

系统函数极大的扩展了C语言的功能，程序员能够站在更高的起点上开发程序，程序员在调用系统函数前，需阅读系统提供的手册，学习各系统函数的功能及调用语法，并用#include指令包含相应的头文件。标准C库的头文件的扩展名都是“**.h**”

### 1 、输入输出函数

C语言本身没有输入输出语句，而是通过输入输出函数来实现输入和输出，下面介绍两个标准的输入函数以及2个标准的输出函数。使用这些输入输出函数，需要使用**#include**指令包含头文件**<stdio.h>**

**格式化输入函数：**scanf

```c++
int scanf(char *format, 变量地址列表);
```

- 参数format是格式控制字符串，其中包括格式符和分隔符，格式符是以**”%“**开头的字符串，用于指定输入数据的类型或格式，参见表6-2
- 变量地址列表指定保存输入数据的变量地址，一次可为多个变量输入数据，此时应为每个变量指定一个格式符，格式符应与变量的数据类型一致，多个变量地址之间用逗号**”，“**隔开，多个格式符之间通常用空格或逗号隔开，输入数据时相应地也用空格或逗号隔开，以回车结束。
- 返回值是int型，返回输入数据的个数。
- 调用函数时，程序暂停执行，等待用户从键盘输入数据，以回车结束。

```c++
#include <stdio.h>

int x; scanf("%d",&x); //输入十进制整数，保存到int型变量x中
float y; scanf("%f",&y ); //输入十进制实数，保存到float型变量y中
double z; scanf("%lf",&z);//输入十进制实数，保存到double型变量z中
char ch; scanf("%c",&ch);//输入一个字符，保存在char型变量ch中
char str[20]; scanf("%s",str)//输入一个字符串，保存到char型数组str中
scanf("%d %f %lf %c %s",&x,&y,&z,&ch,&str)//一次性输入5个不同类型的数据
```

**表6-2：**

| 整数 | %d   | 十进制数       |
| ---- | ---- | -------------- |
| 整数 | %o   | 八进制数       |
| 整数 | %x   | 十六进制数     |
| 实数 | %f   | float型浮点数  |
| 实数 | %lf  | double型浮点数 |
| -    | %c   | 单个字符       |
| -    | %s   | 字符串         |

**格式化输出函数printf：**

```c++
int printf(char*format,表达式列表);
```

- 参数format是格式化控制字符串，其中包括格式符和非格式符，格式符是以**“%”**开头，用于指定输出数据的类型或格式，参见表6-2，非格式符原样输出
- printf中的格式符可以指定输出数据的域宽（即显示时的占位宽度），实际数据达不到域宽时补空格，输出实数时还可以指定输出的精度（即输出几位小数）
- 表达式列表指定需要输出的常量、变量表达式，一次性可以输出多个表达式，此时应为每个表达式指定一个格式符，格式符应与表达式结果的数据类型一致，多个表达式之间用逗号**“,”**隔开
- 返回值是int型，返回输出数据的个数
- 调用该函数时将从右到左的顺序计算各表达式，然后按从左至右的顺序显示各表达式的结果。

举例：

```c++
int x=10; printf("x+5=%d",x+5); //输出x+5=15
float y=5.5; printf("y+1=%f",y+1);//输出y+1=6.5
double z=5.5; printf("z=%lf",z);//输出z=5.5
char ch='A';printf("ch=%c",ch);//输出ch=A
char str[20]="china";printf("%s",str);//输出china
printf("%5d, %5.2f, %5.2lf, %5c, %5s",x, y, z, ch, str);//一次显示5各不同类型的数据
//格式花每个数据的输出宽度为5，输出实数时保留2位小数。
```

**单字符输入函数getchar**

语法说明：

```c++
int getchar();
```

- 调用该函数时，程序暂停执行，等待用户从键盘输入一个字符串，以回车结束
- 返回值是int型，返回所输入字符的ASCII编码值

```c++
char ch; ch = getchar();//输入一个字符，保存到变量ch中
```

**单字符输出函数putchar**

```c
int putchar(int c);
```

- 调用该函数将变量c中的字符输出到显示器上，实际上，变量c中保存的式字符的ASCII码值，
- 返回值是int型，返回所输出的字符的ASCII码值

```c++
putchar('A');//显示字符A
putchar('A'+32);//显示字符A
```

## 4.2 数学函数：#include <math.h>

求一元二次方程根$ax^2+bx+c=0$的演示程序

首先要判断$\Delta = b^2-4ac\geq0$，则$ x = \frac{-b\pm\sqrt{b^2-4ac}}{2a}$，否则x无实数根

```c++
#include <stdio.h>
#include <math.h>
#include <iostream>

int main()
{
    double a, b, c; //一元二次方程的实数部分。
    scanf("%lf %lf %lf",&a,&b,&c); //输入这三个实数

    double d = b * b - 4 * a * c; //计算Δ的值
    if (d < 0) printf("无实数根\n");
    else
    {
        double x1, x2;
        x1 = (-b + sqrt(d)) / (2 * a); x2 = (-b - sqrt(d)) / (2 * a);
        printf("x1=%.10lf,x2=%.10lf\n", x1, x2);
    }
    system("pause");
    return 0;
}
```

## 4.3 字符串处理函数

```c++
#include <stdio.h>
#include <string.h>
#include <iostream>

int main()
{
    char str1[20]="hello",str2[10];

    printf("%d\n",strlen(str1));// 函数strlen求字符数组str1中字符串的长度，结果为5
    strcpy(str2,",world!");//函数strcpy将字符串“,world!"拷贝到字符数组str2中
    strcat(str1,str2);//函数strcat将str2中的字符串连接到str1中字符串的后面
    printf("%s\n",str1);//显示连接后的str1字符串，结果为hello world！
    printf("%d\n",strlen(str1));//显示连接后str1中新字符串的长度，结果为13
    system("pause");
    return 0;
}
```

## 4.4动态内存分配函数

```
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main()
{
    int *p;
    /* 函数malloc返回所分配内存的首地址，且必须制定分配的内存单元的大小，返回值其类型为“void”，需转为“int*”,而10*sizeof(int)可以计算出，1个int型变量所占用的字节数。 */
    p = (int *)malloc(10*sizeof(int));//动态分配一个含有10个元素的int型数组

    for(int n=0;n<10;n++)
    {
        *(p+n) = n*n;
        printf("%d\n",p[n]);
    }
    free(p);
    system("pause");
    return 0;
}
```

## 4.5 命名空间

我们在编写程序时，可以使用各种渠道得到的函数，但是C语言和C++都规定，所有的外部函数不能重名，但我们在使用外来函数时，不同的机构不同的程序员开发的函数难免会重名，比如山东的德州和美国的德州，单独看德州两个字，这两个地方重名了，但是如果加上国度，这两个地方就能够准确的区分开来，这个国度就是命名空间的概念。

C++引入了命名空间的概念，不同的程序员在各自的命名空间内定义外部函数和全局变量，就可以消除重名的问题。

### 1、定义方式

在命名空间中定义函数和全局变量，使用namespace关键值进行申明。然后将函数和全局变量定义在其后的一对大括号{}之中。例子如下：

```c++
namespace Tom // 通过namespace进行申明一个名叫Tom的命名空间
{
    int x,y;
    void fun1(){......}
    void fun2(){......}
}
```

### 2、访问方式

访问命名空间中的函数和全局变量

#### 1、直接访问

通过命名空间名称+双冒号::+全局变量标识符/函数名的方式进行访问：

```c++
Tom::x=10; Tom::y=20; //访问全局变量
Tom::fun1(); Tom::fun2(); //调用命名空间Tom里的函数
```

双冒号（::）称之为作用域运算符

#### 2、使用关键字using先申明各个标识符的命名空间

也可以先声明各个标识符的命名空间，使用关键字using，如果事先声明了要访问的各个标识符，再访问的时候，可以省略命名空间名。

```c++
using Tom::x; //先声明各标识符的命名空间
using Tom::y;
using Tom::fun1();
using Tom::fun2();
x = 10; y = 20; //再通过标识符访问，访问时可以省略命名空间
fun1(); fun2();
```

#### 3、统以申明命名空间的所有标识符

也可以先统一声明命名空间里的所有标识符，再通过标识符直接访问。

```c++
using namespace Tom; //先统一声明命名空间Tom里的所有标识符

x = 10; y = 20; //再通过标识符访问，访问时可以省略命名空间
fun1(); fun2();
```

通过这种方式访问方式是最简单直接的。

## 4.6 匿名命名空间

using 和 namespace都是C++语言保留的关键字，C++语言还有个默认的匿名的命名空间，如果程序员编写函数或全局变量，定义时没有定义在任何命名空间里，则默认就属于该匿名命名空间，C++标准库就引入了命名空间的概念，所有函数实体，例如外部函数、全局变量或对象等，都定义再命名空间std当中，使用这些函数实体，除了需要使用#include指令包含相应的头文件之外，还需要声明其命名空间，例如需要使用cin>>和cout<<对象输入输出数据，则除了需要用#include指令包含头文件<iostream>之外，还需要声明其命名空间std，就是using namespace std;的由来。

## 4.7 c++中的系统函数

c++语言全盘继承了c语言的语法规则，同时也全盘继承了C语言的标准C库。c++标准库新增了一些系统函数，更多是新增了面向对象程序设计的系统类库

### 1、c++语言系统类库

经常使用的cin，cout输入输出语句，实际上就是c++标准库预先定义好的对象，cin是c++标准库定义的一个标准输入流对象，而cout则是一个标准输出流对象，使用cin和cout对象使用#include指令包含相应的文件头“iostream”，还需要声明其命名空间“std”

```c++
#include <iostream>
using namespace std;
```

c++语言是在c语言基础上发展而来的，可以在很大程度上替代c语言，例如

1. 用cin，cout输入/输出流对象，代替原来的输入输出函数
2. 用字符串类string，代替原来的字符数组和字符串处理函数
3. 用new和delete这2个运算符，代替原来的动态内存分配函数：malloc和free

C语言是机构化设计语言，它使用函数来提很多常使用的功能，c++语言继承了这些机构化程序设计方法，但又新增了面向对象程序设计方法，就是使用类和对象来实现程序功能。

## 4.8 多文件结构下程序员与函数的关系

1. **为别人提供函数的程序员**
   - 将常用功能或算法定义成函数，保存到源文件（扩展名为.cpp）；将源程序文件编译成目标代码文件（扩展名为.obj）；通常还会进一步将目标代码打包成一个函数库文件（扩展名通常为.lib）
   - 为函数库中的函数编写声明语句，集中保存在一个头文件中（扩展名为.h）
   - 发布或小数函数库产品，其中包含库文件和头文件，库文件为目标代码（即机器语言），其他程序员只能调用，无法阅读修改，而头文件是函数声明语句的源码，其它程序员可以阅读，以了解函数的功能与调用接口
2. **使用别人函数的程序员**
   - 可以使用系统函数，也可以获得（比如购买）第三方开发的函数库
   - 编写程序时调用别人函数库中的函数，以实现某种特定的功能，调用前需要用#include指令包含相应的文件头
   - 连接时，连接器将函数库中被调函数代码与自己的程序连接到一起，形成最终语句。

# 五、结构化程序设计回顾

运用结构化程序设计，可以将一个大型功能，分解成多个模块，分而治之，c++语言以函数的形式来描述各个模块，这就是函数的定义。然后再通过调用，将各个算法模块组装起来，最终形成一个完整的算法流程。

一个编写好的c++函数可以备同一项目的多个程序员调用，也可以在今后的项目中继续使用，这就是函数代码的重用。

市场上还要很多厂家为程序员提供编写好的，可以实习的各种不同功能得函数库，本章将以Windows图形用户界面GUI程序，win32 AP1函数库进行讲解如何开发一个windows图形界面程序

**Windows图形用户界面程序编程原理**

1. 使用图形界面设计器设计图形界面窗口，设计好的窗口备称为**资源**。
2. 编写主函数，创建并显示窗口。
3. Windows系统负责监控鼠标并捕获用户操作，如果用户对窗口进行了操作（例如点击了某个按钮），那么Windows操作系统自动调用该窗口对应的处理函数（被称为**窗口过程**）
4. 调用时会以消息的形式传递参数，消息参数用于区分用户进行了何种操作，消息参数以整数来标记用户所做的不同操作，为了方便程序员，win32 API将这些编号定义成易于记忆的符号常量，例如WM_COMMAND（表示点击了某个按钮或菜单）、WM_CLOSED（点击了关闭窗口的x号）等。

windows操作系统调用某个窗口过程，并传递消息参数，这边称为向该窗口过程发送消息；窗口过程接收消息，然后进行处理，这被称为对消息的响应。

**Windows图形用户界面运行方式：**

1. 用户启动程序

   主函数负责创建程序窗口，主函数是由程序员编写语句定义的

2. 用户操作界面

   Windows将捕捉鼠标操作，调用**窗口过程函数**，并传递**WM_COMMAND**消息，窗口过程不是程序员在主函数中编写函数调用语句来调用的，而是由Windows操作系统自动调用的。像窗口过程这样由Windows操作系统调用的函数，称为回调函数。

3. 窗口过程函数，根据接收到的消息参数，可以判断出用户进行了何种操作，并按照程序功能执行相应的算法并显示结果。因此程序员需要在窗口操作过程中编写功能实现的语句。

**项目创建方法：**

1. 新建一个win32 Application工程
2. 使用图形界面设计器来设计窗口界面
3. 新建一个c++源程序文件，在其中编写对应的完整的c++程序代码。

# 六、自定义数据类型

c++语言提供了比较完善的基本数据类型，其中包括整型(int、short、long)、浮点型（float、double）、字符型（char）和布尔类型（bool）等4大类

程序员可以根据需要为这些基本数据类型重新命名一个别名，或基于这些基本数据定义新的复杂数据类型，这些类型被统称为**自定义数据类型**，可以使用自定义数据类型来定义变量。

本节将介绍“typedef”类型定义语句，以及枚举、结构体、联合体等常用自定义数据类型的定义和使用方法。

## 6.1 类型定义typedef

可以使用typedef关键字为基本数据类型，命名一个别名，或者为指针，数组定义新的数据类型

**为基本数据类型命名一个别名：**

```c++
typedef unsigned char AGE;
AGE X; //等价于unsigned char x；
```

**指针类型：**

```c++
typedef int* IPointer; //为整型指针int* 起一个别名，IPointer
IPointer p1; //等价于：int*p1
```

**定义数组类型：**

```c++
typedef char NAME[10]; //定义一个字符型数组类型，命名为NAME,共计10个元素。
NAME name; //等价于：char name[10];
```

通过typedef统一数组类型的使用，也能简化代码，是程序易于阅读。也可以将类型定义与编译预处理指令搭配使用。

```c++
#include <iostream>
using namespace std;

#define _UNICODE
#ifdef _UNICODE;
	typedef wchar_t TCHAR;
#else
	typedef char TCHAR;
#endif

int main()
{
    TCAR ch;
    /*
    代码段
    */
    return 0;
}
```

## 6.2 枚举类型

布尔类型的一个主要特征是其值域只有2个取值，即真和假，分别用关键字true和false表示，实际的程序处理任务也会碰到和bool类型相似的数据类型，他们的值是有限的，我们称他们的值域是可枚举的。例如一个星期只有星期一到星期日，这个值域就是可枚举的值域。

c++语言可以将值域可枚举的数据定义成新的数据类型，这些数据类型被统称为枚举类型，值域中的每个取值称之为一个枚举元素。

```c++
enum 枚举类型名 {枚举常量1，枚举常量2，... ...,枚举常量n};//n是有限的
```

- enum是定义枚举类型的关键字
- 枚举类型名需要符合标识符命名规则，
- 枚举常量是表示各个枚举元素的名称，须符合标识符的命名规则，相当于是一个符号常量
- 计算机内部储存枚举型数据时，用整数表示每个枚举常量，默认情况下，枚举常量1=0，枚举常量2=1，... ...，枚举常量n=n-1，可以定义时为枚举常量另行指定其他的值。

```c++
enum WeekDay{sun,mon,tur,thu,fri,sat};//默认取值。sun=0，mon=1，......
enum WeekDay{sun=7,mon=1,tur=2,wed=3,thu=4,fri=5,sat=6};//指定元素取值
enum WeekDay{sun=7,mon=1,tur,wed,thu,fri,sat};//等价上一条语句
```

演示程序：

```c++
#include <iostream>
using namespace std;

enum WeekDay{sun,mon,tur,thu,fri,sat};

int main()
{
    enum WeekDay x;//定义1个WeekDay类型的枚举变量x
    x=mon;//为x赋值，mon是枚举常量，内部数值是1
    cout<<x<<endl;//显示枚举类型对应的数值，结果为1
    return 0;
}    
```

注：枚举变量不能直接用整数赋值，因为两者数据类型不同。

## 6.3 联合体类型和结构体类型

c++语言可以将多个变量组合在一起形成一个逻辑上的整体，使变量成为整体的一个成员，变量成员的类型可以相同，也可以不同，将多个变量成员组成的整体定义成新的数据类型，这种数据类型能够描述程序涉及所面临的复杂数据。

- **联合体类型**

  如果多个变量成员不会同时使用，那就可以将它们定义成联合体类型，联合体类型的特点是变量成员共用同一内存单元，同一时刻只能保存一个成员的数据。定义联合体的目的是节约内存。

  语法：

  ```c++
  union 联合体类型名
  {
      数据类型1 变量成员名1;
      数据类型2 变量成员名2;
      ... ...
      数据类型n 变量成员名n;
  };
  ```

  - union是定义联合体类型的关键字
  - 联合体类型名需符合标识符的命名规则
  - 变量成员之间的数据类型可以相同，也可以不同，但变量名不能相同。

  代码实例：

  ```c++
  /*定义联合体变量数据类型 UType*/
  union UType
  {
      char ch;
      int x;
      double y;
  };
  /*
  使用联合体类型可以定义联合体变量，定义时需要union关键字，联合体变量定义好后，可以访问其中的成员，访问联合体成员的语法形式是：
  联合体变量名.成员名
  其中圆点"."称为成员运算符
  */
  union UType a; //定义联合体变量a
  a.ch; a.x; a.y; //访问联合体变量成员
  ```

  联合体类型也称为共用体类型，每个联合体变量所占用的字节数，等于其最大成员的字节数。因为联合变量的成员是共用同一内存单元，故联合体变量同一时刻只能保持一个成员的数据。应当准确理解联合体类型的这个特点，否则会造成数据丢失。

- **结构体类型**

  如果多个变量成员同时使用，那就将他们定义成结构体类型，结构体类型的特点是个变量成员单独分配内存单元，分别保存各自的数据。定义结构体数据的目的是存储复杂数据。

  c++语言可以将多个变量组合在一起形成逻辑上的整体，使变量称为整体的一个成员，变量成员的类型可以相同，也可以不同，如果多个变量成员需要同时使用，那就可以将它们定义成结构体类型。

  演示实例：

  ```c++
  int main()
  {
      char ID[11],Name[9];//保存学号和姓名
      int Age;//保存年龄
      double Source;//保存成绩
      
      strcpy(ID,"1510078620");
      strcpy(Name,"李若溪");
      Age=19;
      Score=90;
      /*在上述代码种，学生的学号，姓名，成绩，年龄都存在关联关系可以将其看作一个整体。它们都是某个学生个人信息的一部分。学生信息需要同时包含这些部分，否则信息就不完整了。所以可以将学生信息定义成结构体类型*/
  }
  ```

  **定义结构体类型语法：**

  ```c++
  struct 结构体类型名
  {
      数量类型1 变量成员名1;
      数量类型2 变量成员名2;
      ... ...;
      数据类型n 变量成员名n;
  };
  ```

  - struct是定义结构体类型的关键字；
  - 结构体类型名需符合标识符的命名规则
  - 变量成员之间的数据类型可以相同，也可以不同，但变量名不能相同。

  演示代码：

  ```c++
  /*定义结构体类型Student*/
  struct Student
  {
      char ID[11],Name[9];
      int Age;
      double Score;
  };
  
  struct Student a; //定义结构体变量a
  a.ID; a.Name; a.Age; a.Score; //访问各个成员
  ```

  与联合体变量不同的是，结构体数据类型的各个成员，单独分配内存单元，分别保存各自的数据，每个结构体变量占用的字节数，等于其所有成员占用字节数的总和。

  **结构体类型的指针变量**

  我们也可以定义结构体的指针变量来保存某个结构体的内存地址。然后通过指针变量间接访问结构体变量及其成员，实例：

  ```c++
  struct Student a;
  struct Student *p; //定义**结构体类型的指针变量**
  p = &a; //获取结构体变量a的内存地址
  (*p).ID;(*p).Name;(*p).Age;(*p).Score; //通过指针间接访问内部成员。
  p->ID; p->Name; p->Age; p->Score;//通过指向运算符，间接访问。
  ```

  由于通过(*p)的方式访问结构体成员比较繁琐，c++语言引入了一种新的更加直观的运算符，就是指向运算符：”->“，

  







