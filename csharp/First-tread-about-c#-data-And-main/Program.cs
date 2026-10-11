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
}