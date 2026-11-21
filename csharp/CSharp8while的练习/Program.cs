using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp9while的练习
{
    internal class Program
    {
        static void Main(string[] args)
        {
            bool shuRuZhengQue=true;
            while(shuRuZhengQue)
            {
                Console.WriteLine("请输入用户名");
                string name=Console.ReadLine();
                Console.WriteLine("请输入密码");
                string miMa=Console.ReadLine();
                if( name =="admin" && miMa == "8888")
                {
                    shuRuZhengQue = false;
                }
                else
                {
                    Console.WriteLine("用户名或密码错误");
                }

            }


            int i = 0;
            int sum = 0;
            while(i < 100)
            {
                ++i;
                if ( i % 7 == 0 )
                {
                    continue;
                }
                sum += i;
            }
            Console.WriteLine(sum);

            int n = 0;
            int n1 = 1;
            int n2 = 1;
            int result = 0;
            while (n < 20)
            {
                ++n;
                if ( n <3)
                {
                    result = 1;
                }
                else
                {
                    result = n1 + n2;
                    n1 = n2;
                    n2 = result;
                }
                Console.WriteLine(result);
            }

        }
    }
}
