using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp随机数相关练习
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Random r=new Random();
            int bossXue = 20;
            int bossFang = 10;
            while (bossXue != 0)
            {
                int shuChu = r.Next(8,13);
                Console.WriteLine("这次你的输出为："+shuChu);
                if (shuChu < bossFang)
                {
                    Console.WriteLine("被全部防住了哟~");
                    Console.WriteLine();
                }
                else
                {
                    bossXue -= (shuChu - bossFang);
                    Console.WriteLine("这次攻击怪物掉了 {0} 血,还有 {1} 血",shuChu-bossFang,bossXue);
                    Console.WriteLine();
                }
            }
        }
    }
}
