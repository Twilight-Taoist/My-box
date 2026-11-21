using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp5算数运算符
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int myNowAge = 0;
            Console.WriteLine("输入你的年龄");
            myNowAge = int.Parse(Console.ReadLine());
            myNowAge += 10;
            Console.WriteLine("十年后你" + myNowAge + "岁");

            int day = 0;
            int hour = 0;
            int minute = 0;
            int s = 0;
            Console.WriteLine("输入总秒数");
            int total = int.Parse(Console.ReadLine());
            day = total / (3600 * 24);
            hour = (total % (3600 * 24)) / 3600;
            int i = (total % (3600 * 24)) % 3600;
            minute = i / 60;
            s = i % 60;
            Console.WriteLine("已经过去了" + day + " " + hour + " " + minute + " " + s);
        }
    }
}
