int x;
x = 10;
Console.WriteLine(x);

Console.WriteLine("##############");

Calculator a = new Calculator();
int result = a.Add(5, 8);
Console.WriteLine(result);

string today = a.GetToday();
Console.WriteLine(today);

a.PrintSum(7, 8);

Console.WriteLine("##############");

a.Print1ToX_V1(4);
a.Print1ToX_V2(4);
int sum1 = a.PrintSum1ToX_V1(100);
int sum2 = a.PrintSum1ToX_V2(100);
int sum3 = a.PrintSum1ToX_V3(100);
Console.WriteLine("Sum1: {0}, Sum2: {1}, Sum3: {2}", sum1, sum2, sum3);

class Calculator
{
    public int Add ( int a, int b)
    {
        return a + b;
    }
    public string GetToday()
    {
        int day = DateTime.Now.Day;
        return day.ToString();
    }
    public void PrintSum (int a, int b)
    {
        int sum = a + b;
        Console.WriteLine("{0} + {1} = {2}", a, b, sum);
    }

     public void  Print1ToX_V1 ( int x)
    {
        for (int i = 0; i < x; i++)
        {
            Console.WriteLine(i);
        }   
    }

     public void Print1ToX_V2(int x)
    {
        if (x == 1)
        {
            Console.WriteLine(1);
        }
        else
        {
            Print1ToX_V2(x - 1);
            Console.WriteLine(x);
        }
    }

    public int PrintSum1ToX_V1(int x)
    {
        int sum = (1+ x) * x / 2;
        return sum;
    }

    public int PrintSum1ToX_V2(int x)
    { 
        if (x == 1)
        {
            return 1;
        }
        return x + PrintSum1ToX_V2(x - 1);
    }

    public int PrintSum1ToX_V3(int x)
    {
        int i;
        int sum = 0;

        for (i = 1; i <= x; i++)
        {
            sum += i;
        }
        return sum;
    }

}  