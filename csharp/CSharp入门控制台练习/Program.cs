using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp入门控制台练习
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.SetWindowSize(50, 45);
            Console.SetBufferSize(100, 100);
            Console.BackgroundColor= ConsoleColor.Red;
            Console.Clear();
            Console.CursorVisible = false;
            int x = 0;
            int y = 0;
            while (true)
            {
                //Console.Clear();
                Console.SetCursorPosition(x, y);
                Console.ForegroundColor = ConsoleColor.Yellow;
                Console.Write("■");
                char i=Console.ReadKey(true).KeyChar;
                Console.SetCursorPosition(x, y);
                Console.Write(" ");
                switch (i)
                {
                    case 'a':
                        if ((x -= 1) >= 0)
                        { 
                        }
                        else
                        {
                            ++x;
                        }
                        break;
                    case 'w':
                        if ((y -= 1) >= 0 )
                        {                  
                        }
                        else
                        {
                            ++y;
                        }
                        break;
                    case 'd':
                        if ((x += 1) <= 50)
                        {                         
                        }
                        else
                        {
                            --x;
                        }
                        break;
                    case 's':
                        if ((y += 1) <= 45)
                        { 
                        }
                        else
                        {
                            --y;
                        }
                        break;
                }
            }

            


        }
    }
}
