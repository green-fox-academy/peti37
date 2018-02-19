using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] af = { 4, 5, 6, 7 };
            foreach (var number in af)
            {
                Console.WriteLine(number);
            }
            // - Create an array variable named `af`
            //   with the following content: `[4, 5, 6, 7]`
            // - Print all the elements of `af`
            Console.ReadLine();
        }
    }
}