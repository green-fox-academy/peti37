using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] abc = { "first", "second", "third" };
            string temp = abc[0];
            abc[0] = abc[2];
            abc[2] = temp;

            for (int i = 0; i < abc.Length; i++)
            {

                Console.WriteLine(abc[i]);
            }
            Console.ReadLine();
        }
    }
}