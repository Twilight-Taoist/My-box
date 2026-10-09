namespace ClassLibraryAboutCalculation
{
    public class Tool
    {
        public static double Add(double a, double b)
        {
            return a + b;
        }

        public static double Sub(double a, double b)
        {
            return a - b;
        }
        public static double MUl(double a, double b)
        {
            return a * b;
        }
        public static double Div(double a, double b)
        {
            if (b == 0)
            {
                Console.WriteLine("Error : Division by zero is not allowed");
                return 0;
            }
            else
            {
                return a / b;
            }
        }
    }
}
