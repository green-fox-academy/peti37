using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Give me a number:");
            string scan = Console.ReadLine();
            int number;
            int.TryParse(scan, out number);
            for (int i = 1; i <= number; i++)
            {
                for (int h = 1; h < i * 2; h++)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
            }
            
        Console.ReadLine();
            
        }
    }
}