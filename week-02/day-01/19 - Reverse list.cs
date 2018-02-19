using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] aj = { 3, 4, 5, 6, 7 };
            Array.Reverse(aj);
            foreach (var item in aj)
            {
                Console.WriteLine(item);
            }
            // - Create an array variable named `aj`
            //   with the following content: `[3, 4, 5, 6, 7]`
            // - Reverse the order of the elements in `aj`
            // - Print the elements of the reversed `aj`
            Console.ReadLine();
        }
    }
}