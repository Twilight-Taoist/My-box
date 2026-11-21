using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp5字符串拼接
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //方式1，直接使用+号拼接；
            string str1 = "Hello";
            str1 +="World";
            Console.WriteLine(str1);
            Console.WriteLine("_____________________");

            //注意：如果拼接的字符串中有数字，则要看数字前有无子字符串，若有+号会把数字当作字符串处理，
            //而不是进行数学运算，若希望进行数学运算，则要把数字放在前面，或者使用括号；
            str1 = 1 + 2 + "Hello" + 3 + 4;
            Console.WriteLine(str1);
            str1 = "Hello" + 1 + 2 + 3 + 4;
            Console.WriteLine(str1);
            str1 = 1 + 2 + "Hello" + (3 + 4);
            Console.WriteLine(str1);
            Console.WriteLine("_____________________");


            //方式2，使用string.Format()方法拼接；
            string str2 = string.Format("Hello {0}", "World");
            Console.WriteLine(str2);
            //方式3，使用$符号拼接；
            string str3 = $"Hello { "World" }";
            Console.WriteLine(str3);
            //控制台输出；（可多不可少）；
            Console.WriteLine("Hello {0}", "World");

            //练习；
            Console.WriteLine("请输入你的名字");
            string name = Console.ReadLine();
            Console.WriteLine("请输入你的年龄");
            int age = int.Parse(Console.ReadLine());
            Console.WriteLine("请输入你的性别");
            string sex = Console.ReadLine();
            Console.WriteLine("你的名字是：{0}，年龄是：{1}，性别是：{2}", name, age, sex);

        }
    }
}
