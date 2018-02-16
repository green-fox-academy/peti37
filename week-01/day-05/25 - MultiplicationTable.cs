using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Give me a number:");
            string input = Console.ReadLine();
            int number;
            Int32.TryParse(input, out number);

            for (int i = 1; i <= 10; i++)
            {
                Console.WriteLine(i + " * " + number + " = " + i * number );
            }
            Console.ReadLine();
        }
    }
}