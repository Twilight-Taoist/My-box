int x;
x = 100;

Student stu;
stu = new Student();
stu.ID = 1000;
stu.Score = 90;

object obj = x;
int y = (int)obj;
Console.WriteLine(y);   

class Student
{
    public uint ID;
    public ushort Score;   
}