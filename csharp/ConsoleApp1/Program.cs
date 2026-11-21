using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("请输入今天学习时长（单位为分钟，整数）");
            try
            {
                int studyTime=int.Parse(Console.ReadLine());
                if (studyTime > 60) 
                {
                    Console.WriteLine("Today,you study {0} min ,Good!",studyTime);
                }
            }
            catch
            {
                Console.WriteLine("请按要求输入");
            }

            Console.WriteLine("请依次输入你的语文，数学，英语成绩(整数)，每次输入完成后按回车再输入");
            try
            {
                int yuWen=int.Parse(Console.ReadLine());
                int shuXue=int.Parse(Console.ReadLine());
                int yinYu=int.Parse(Console.ReadLine());

                if (yuWen > 70 && shuXue > 80 && yinYu > 90 || (yuWen == 100 || shuXue == 100 || yinYu == 100))
                {
                    Console.WriteLine("Good");
                }
                else
                {
                    Console.WriteLine("jia you");
                }
            }
            catch
            {
                Console.WriteLine("请按要求输入");
            }

            Console.WriteLine("请输入你的年龄");
            try
            {
                int age = int.Parse(Console.ReadLine());
                if (age > 18)
                {
                    Console.WriteLine("可以查看");
                }
                else if (age < 13)
                {
                    Console.WriteLine("禁止查看");
                }
                else
                {
                    Console.WriteLine("是否查看，请输入，是/否");
                    try
                    {
                        string yesOrNo=Console.ReadLine();
                        if (yesOrNo == "是")
                        {
                            Console.WriteLine("请进");
                        }
                        else
                        {
                            Console.WriteLine("退出");
                        }
                    }
                    catch
                    {
                        Console.WriteLine("请只输入是或否");
                    }
                }
            }
            catch
            {
                Console.WriteLine("请按要求输入");
            }
        }
    }
}
