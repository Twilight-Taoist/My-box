using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp隐式转换与4种显式转化
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //隐式转换遵循大装小类型一致的基本原则；
            int in1 = 1;
            long lon1 = 0;
            sbyte sb1 = 2;
            in1 = sb1;
            lon1 = in1;
            //都是可以的，但小到大不行；

            //显示转换1，（）强制转换，需要转换后的值在接收的范围内，浮点数会丢失精度，字符串会转换为对应编码；
            int in2 = 0;
            long lon2 = 0;
            char a= 'a';
            in2 = a;
            Console.WriteLine(in2);
            in2 = (int)lon2;
            //显示转换2，Parse
            string st1 = "1234";
            in2 = int.Parse(st1);
            //显示转换3，Convers
            in2 = Convert.ToInt32(12.7);
            Console.WriteLine(in2);
            in2 = Convert.ToInt32(12.3);
            Console.WriteLine(in2);
            //四舍五入，精度更高。
            double db1 = Convert.ToDouble("3.247896");
            //显示转换4，.Tostring
            string st2=123.ToString();
            string st3="badkiw".ToString();
        }
    }
}
