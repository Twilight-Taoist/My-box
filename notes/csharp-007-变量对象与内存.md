# C# 007 · 类型、变量与对象（下）—— 变量 / 对象 / 内存 观察笔记

> 日期：2026-10-15 ｜ 来源：跟敲 `C#About007变量_对象_内存` 时的**内存格子追踪表**（原始 `.xlsx` 见本目录）
> 用法：每格是一位（b7→b0），用来观察**变量/对象在内存里的布局**。
> 📄 **纸笔稿（手写原稿）**：`纸笔稿\007-变量对象与内存-2026-10-15-01…04.jpg`（4 张，压缩版 ≈1.1 MB；**原图**在 `桌面\C#笔记\`，且已纳入 U 盘离线备份）

## 一、被标记的地址（只有这些行有内容）

**区块 10000000**

| 地址 | b7 | b6 | b5 | b4 | b3 | b2 | b1 | b0 |
|---|---|---|---|---|---|---|---|---|
| `10000008` | 0 | 0 | 1 | 0 | 0 | 1 | 1 | 0 |
| `10000009` | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| `10000010` | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| `10000011` | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| `10000012` | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| `10000013` | 1 | 1 | 0 | 0 | 0 | 0 | 1 | 1 |
| `10000014` | 1 | 0 | 0 | 1 | 0 | 0 | 1 | 1 |
| `10000015` | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| `10000021` | 1 | 0 | 0 | 0 | 1 | 0 | 1 | 1 |
| `10000022` | 1 | 1 | 0 | 0 | 0 | 0 | 1 | 1 |
| `10000023` | 1 | 0 | 0 | 1 | 0 | 0 | 1 | 1 |
| `10000024` | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |

**区块 30000000**

| 地址 | b7 | b6 | b5 | b4 | b3 | b2 | b1 | b0 |
|---|---|---|---|---|---|---|---|---|
| `30000011` | 0 | 0 | 1 | 0 | 0 | 1 | 1 | 0 |
| `30000012` | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| `30000013` | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| `30000014` | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |

## 二、三行写法（**你来补**，每条 3 行就够）

### 1. 变量在内存里怎么放
- **是什么**：以变量名内存地址为起点，数据类型要求的为长度的一段内存，一般Main中的放在栈上，类中的放在堆上。

- **为什么**：保证空间的合理分配。

- **例子**：

- ```
  int x;
  x = 100;
  
  Student stu;
  stu = new Student();
  stu.ID = 1000;
  stu.Score = 90;
  
  object obj = x;
  int y = (int)obj;
  Console.WriteLine(y);   
  
  class Student
  {
      public uint ID;
      public ushort Score;   
  }
  ```

  

### 2. 对象与引用的区别
- **是什么**：对象需要创建实例，而引用不需要。

- **为什么**：对象只是一个模糊的概念，需要创建一个具体的实例，而引用本身包含的内容已经足够清楚。

- **例子**：

- ```
  Student stu;
  stu = new Student();//需要创建一个实例
  stu.ID = 1000;
  stu.Score = 90;
  double x=caculate(2.0,3.0);//不用创建实例
  
  class Student
  {
      public uint ID;
      public ushort Score;   
  }
  class caculate
  {
      public double Add (double a ,double b )
      {
      return a+b;
      }
  }
  ```

  

  

### 3. 值类型 vs 引用类型（我观察到的）
- **是什么**：具体的值；函数头；

- **为什么**：？

- **例子**：

  ```
  namespace ClassLibraryAboutCalculation
  {
      public class Tool
      {
          public static double Add(double a, double b)/*()内为值类型，如果Main中引用了Tool的Add为引用类型*/
          {
              return a + b;
          }
  
          public static double Sub(double a, double b)
          {
              return a - b;
          }
          public static double MUl(double a, double b)
          {
              return a * b;
          }
          public static double Div(double a, double b)
          {
              if (b == 0)
              {
                  Console.WriteLine("Error : Division by zero is not allowed");
                  return 0;
              }
              else
              {
                  return a / b;
              }
          }
      }
  }
  ```

> ⚠️ 提醒：这三段**必须自己写**（写得糙没关系）—— 抽查时我会从这里抽。
