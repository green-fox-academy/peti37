using System;

namespace GreenFox
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            {
                for (int i = 1; i <= 4; i++)
                {
                    for (int a = 1; a <= 8; a++)
                    {
                        Console.Write("■ ");
                    }
                    Console.WriteLine();
                    for (int a = 1; a <= 8; a++)
                    {
                        Console.Write(" ■");
                    }
                    Console.WriteLine();

                }
                Console.ReadLine();
            }
        }
    }
}
