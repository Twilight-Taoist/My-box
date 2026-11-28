using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp枚举练习 
{ 


enum E_QQstate
{
    Online=1,
    lieve,
    Busy,
}

enum E_Gender
    {
        Man,
        Woman,
    }
enum E_Profession
    {
        zhanShi=1,
        lieRen,
        faShi,
    }


    internal class Program
    {
        static void Main(string[] args)
    {
            Console.WriteLine("请选择你的QQ的状态，1：在线；2，离开；3忙碌");
            int choice = int.Parse(Console.ReadLine());
            E_QQstate player =(E_QQstate) choice;
            switch (player)
            {
                case E_QQstate.Online:
                     Console.WriteLine("你选择了在线状态");
                     break;
                case E_QQstate.lieve:
                     Console.WriteLine("你选择了离开状态");
                     break;
                case E_QQstate.Busy:
                     Console.WriteLine("你选择了忙碌状态");
                     break;
                default:
                     Console.WriteLine("你输入的状态有误，请重新输入");
                     break;
            }

            int gonJiLi = 0;
            int fangYuLi = 0;
            string jiNeng = "";

            Console.WriteLine("请选择你的性别，1：男；2：女");

            int genderChoice = int.Parse(Console.ReadLine());
            E_Gender gender = (E_Gender) genderChoice;
            switch (gender)
            {
                case E_Gender.Man:
                    Console.Write("你选择了男性");
                    gonJiLi += 50;
                    fangYuLi += 100;
                   
                    break;
                case E_Gender.Woman:
                    Console.Write("你选择了女性");
                    gonJiLi += 150;
                    fangYuLi += 20;
                    break;
                default:
                    Console.WriteLine("你输入的性别有误，请重新输入");
                    break;
            }
            Console.WriteLine("请选择你的职业，1：战士；2：猎人；3：法师");
            int professionChoice = int.Parse(Console.ReadLine());
            E_Profession profession = (E_Profession) professionChoice;
            switch (profession)
            {
                case E_Profession.zhanShi:

                    gonJiLi += 20;
                    fangYuLi += 100;
                    jiNeng = "冲锋";
                    break;
                case E_Profession.lieRen:
                    gonJiLi += 120;
                    fangYuLi += 30;
                    jiNeng = "假死";
                    break;
                case E_Profession.faShi:
                    gonJiLi += 200;
                    fangYuLi += 10;
                    jiNeng = "奥术冲击";
                    break;
                default:
                    Console.WriteLine("你输入的职业有误，请重新输入");
                    break;
            }
            Console.WriteLine("你选择了“{0}{1}”，攻击力：{2}，防御力：{3}，技能：{4}", gender, profession, gonJiLi, fangYuLi, jiNeng);

        }

        
    }
}
