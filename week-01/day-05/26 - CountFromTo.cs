using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Give me a number:");
            string input = Console.ReadLine();
            Console.WriteLine("Give me another one aswell:");
            string input2 = Console.ReadLine();
            int number;
            int number2;
            Int32.TryParse(input, out number);
            Int32.TryParse(input2, out number2);
            if (number > number2)
            {
                Console.WriteLine("The second number should be bigger");
            }
            else if (number < number2)
            {
                for (int i = number; i <= number2; i++)
                {
                    Console.WriteLine(i);
                }
            }
            
            Console.ReadLine();
        }
    }
}