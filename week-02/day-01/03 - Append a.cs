using System;

namespace GreenFox
{
    class Program
    {
        public static string appendA(string word)
        {
            return word + "a";
        }

        static void Main(string[] args)
        {
            String am = "kuty";

            Console.WriteLine(appendA(am));
            Console.ReadLine();

        }
    }
}