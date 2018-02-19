using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("give me a number:");
            string askednumber = Console.ReadLine();
            int number;
            int.TryParse(askednumber, out number);
            int a = 5;

            Console.WriteLine("The number's factorial is " + factorio(number));
            Console.ReadLine();

        }
        public static int factorio(int number)
        {
            int factorial;
            int i;
            factorial = number;
            for (i = number - 1; i >= 1; i--)
            {
                factorial = factorial * i;
            }
            return factorial;
        }
    }
}