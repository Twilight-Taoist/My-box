using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp4数组的使用
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Random random = new Random();
            int ran = 0;
            int[] arg = new int[10];
            for (int i = 0; i < arg.Length; i++)
            {
                ran = random.Next(0, 100);
                arg[i] = ran;
            }
            ToolShowArg.ShowArg(arg);
            for (int i = 0, j = arg.Length - 1; i < j; i++, j--)
            {
                int box = arg[i];
                arg[i] = arg[j];
                arg[j] = box;
            }
            ToolShowArg.ShowArg(arg);
            int max = 0;
            int min = 0;
            int sum = 0;
            for (int i = 0; i < arg.Length; i++) 
            {
                min = arg[0];
                if (min > arg[i])
                {
                    min = arg[i];
                }
                else if (max < arg[i]) 
                { 
                    max = arg[i];
                }
                sum+= arg[i];
            }
            Console.WriteLine("Max={0};Min={1};Average={2}", max, min, sum / arg.Length);
        }
        class ToolShowArg
        {
            public static void ShowArg(int[] x)
            {
                for (int i = 0; i < x.Length; i++)
                {
                    Console.Write(x[i] + " ");
                }
                Console.WriteLine(" ");
            }

        }
    }
}
