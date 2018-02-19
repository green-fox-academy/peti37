using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] ai = { 3, 4, 5, 6, 7 };
            int sum = 0;
            foreach (var item in ai)
            {
                sum += item;
            }
            Console.WriteLine(sum);

            Console.ReadLine();
        }
    }
}