
Student stu = new Student();
Console.WriteLine($"Student Name: {stu.Name}, Student ID: {stu.ID}");
Console.WriteLine("--------------------------------------------------");
Student stu2 = new Student("John Doe", 12345);
Console.WriteLine($"Student Name: {stu2.Name}, Student ID: {stu2.ID}");

int result1 = Calculate.Add2(10, 5);
int result2 = Calculate.Sub2(10, 5);
Calculate cal = new Calculate();
int result3 = cal.Add1(20, 10);
int result4 = cal.Sub1(20, 10);

Console.WriteLine("--------------------------------------------------");
Console.WriteLine($"Result 1: {result1}");
Console.WriteLine($"Result 2: {result2}");
Console.WriteLine("--------------------------------------------------");
Console.WriteLine($"Result 3: {result3}");
Console.WriteLine($"Result 4: {result4}");

class Student
{
    public Student() 
    {
        this.Name = "Default Name";
        this.ID = 0;
    }
    public Student(string name, int id)
    {
        this.Name = name;
        this.ID = id;
    }
    public string Name;
    public int ID;
}
class Calculate
{
    public int Add1(int a, int b)
    {
        return a + b;
    }
    public int Sub1(int a, int b)
    {
        return a - b;
    }
    public static int Add2(int a, int b)
    {
        return a + b;
    }
    public static int Sub2(int a, int b)
    {
        return a - b;
    }
}