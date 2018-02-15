using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            string testStr = "I won't cheat on the exam!";
            for (int i = 0; i <= 100; i++)
            {
                Console.WriteLine(i + " " + testStr);
            }

            Console.ReadLine();

        }
    }
}