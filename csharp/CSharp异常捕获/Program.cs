using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp异常捕获
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("请输入姓名");
            string userName=Console.ReadLine();
            //基本结构
            try
            {
                Console.WriteLine("请输入语文成绩");
                int yuwen = int.Parse(Console.ReadLine());
                Console.WriteLine("你的语文成绩为：" + yuwen);
            }
            catch
            {
                Console.WriteLine("请输入合法的数字");
            }

        }
    }
}
