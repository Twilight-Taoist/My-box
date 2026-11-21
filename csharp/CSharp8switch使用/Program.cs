using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp8switch使用
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int money = 10;
            Console.WriteLine("请输入你要的款式（数字1/2/3）");
            try
            {
                int kuanShi=int.Parse(Console.ReadLine());
                switch (kuanShi)
                {
                    case 1:
                        money -= 5;
                        if (money >= 0)
                        {
                            Console.WriteLine("Ok Your money now is {0} ", money);
                        }
                        else { Console.WriteLine("You don`t has enjioy money"); }
                        break;
                    case 2:
                        money -= 7;
                        if (money >= 0)
                        {
                            Console.WriteLine("Ok Your money now is {0} ", money);
                        }
                        else { Console.WriteLine("You don`t has enjioy money"); }
                        break;
                    case 3:
                        money -= 11;
                        if (money >= 0)
                        {
                            Console.WriteLine("Ok Your money now is {0} ", money);
                        }
                        else { Console.WriteLine("You don`t have enjioy money"); }
                        break;
                    default:
                        Console.WriteLine("Not have");
                        break;
                }
            }
            catch
            {
                Console.WriteLine("请正确输入数字");
            }
            
        }
    }
}
