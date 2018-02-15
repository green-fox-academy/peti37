using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("How many km-s did you walk today?");
            string distance = Console.ReadLine();
            Console.WriteLine("That's is " + (Convert.ToInt32(distance)) * 1.6 + " miles!");
            Console.ReadLine();
        }
    }
}