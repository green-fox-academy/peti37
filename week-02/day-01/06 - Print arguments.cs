using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            string a = "kacsa ";
            string b = "ding dong knock knock";
            printer(a + b);

            
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
        public static string printer(string printThisString)
        {
            Console.WriteLine(printThisString);
            return printThisString;
        }
    }
}