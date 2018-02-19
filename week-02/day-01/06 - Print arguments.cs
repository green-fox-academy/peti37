using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            printer("kecske", "lo", "szorny");


            // - Create a function called `printer`
            //   which prints the input String parameters
            // - It can have any number of parameters

            // Examples
            // printer("first")
            // printer("first", "second")
            // printer("first", "second", "third", "fourh")
            // ...
            Console.ReadLine();
        }
        public static void printer(params string[] printThisString)
        {
            foreach (var word in printThisString)
            {
                Console.WriteLine(word);
            }
        }
    }
}