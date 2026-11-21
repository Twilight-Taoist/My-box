using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp6三目运算符
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //基本用法：bool类型值 ？结果1 ：结果2；
            //要求，要有变量接，结果是什么类型接的变量就是什么类型；
            try
            {
                Console.WriteLine("请输入两个数字，每输完一个数字请按回车");
                int a = int.Parse(Console.ReadLine());
                int b = int.Parse(Console.ReadLine());
                int max = a > b ? a : b;
                Console.WriteLine("max==" + max);
            }
            catch
            {
                Console.WriteLine("请按照要求输入");
            }


            try 
            { 
            Console.WriteLine("请先后输入C#与unity的成绩，每输完一个数字请按回车");
                int c = int.Parse(Console.ReadLine());
                int u = int.Parse(Console.ReadLine());
                Console.WriteLine(c > 90 && u > 90 ? "Goog" : "NO");
            }
            catch
            {
                Console.WriteLine("请按照要求输入");
            }


            try
            { 

                Console.WriteLine("请输入年份");
                int year = int.Parse(Console.ReadLine());
                Console.WriteLine(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0) ? "Run" : "NO run");
            }
            catch
            {
                Console.WriteLine("请按照要求输入");
            }


        }
    }
}
