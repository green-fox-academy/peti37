using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] p1 = { 1, 2, 3, };
            int[] p2 = { 4, 5 };

            if (p2.Length > p1.Length)
            {
                foreach (var element in p2)
                {
                    Console.WriteLine(element);
                }
            }
            else
            {
                Console.WriteLine("p2 doesnt have more elements then p1");
            }
            Console.ReadLine();
       
        }
    }
}