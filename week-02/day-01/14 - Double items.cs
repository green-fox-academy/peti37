using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] ag = { 3, 4, 5, 6, 7 };

            for (int i = 0; i < ag.Length; i++)
            {
                ag[i] = ag[i] * 2;
                Console.WriteLine(ag[i]);
            }

            // - Create an array variable named `ag`
            //   with the following content: `[3, 4, 5, 6, 7]`
            // - Double all the values in the array
            Console.ReadLine();
        }
    }
}