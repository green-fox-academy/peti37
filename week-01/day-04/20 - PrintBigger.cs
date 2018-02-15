using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Write a number:");
            string input = Console.ReadLine();
            Console.WriteLine("Write another number:");
            string input2 = Console.ReadLine();
            int number;
            int number2;
            Int32.TryParse(input, out number);
            Int32.TryParse(input2, out number2);


            if (number < number2 )
            {
                Console.WriteLine(number2 +  " is bigger");
            }
            else
            {
                Console.WriteLine(number +  " is bigger");
            }
            Console.ReadLine();

        }
    }
}