using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C_GameAbout
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //基本的输出
            Console.WriteLine("Hello,");
            Console.WriteLine("World");
            //上面会自动空行
            
            Console.Write("你好，");
            Console.Write("世界");
            //上面不会自动空行

            Console.ReadLine();
            //一直读取到回车键才会结束程序
            Console.WriteLine("用户输入完毕");

            Console.ReadKey();
            //读取任意操作就会结束程序
            Console.WriteLine("用户输入完毕");
        }
    }
}
