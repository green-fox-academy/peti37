using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = 115;
            int b = 554;
            Console.WriteLine(sum(a, b));
            Console.ReadLine();

            // - Write a function called `sum` that sum all the numbers
            //   until the given parameter and returns with an integer
        }
        public static int sum(int number1, int number2)
        {
            return number1 + number2;
        }
    }
}