using System;

namespace GreenFox
{
    class Program
    {
        public static void GreetingFunction(String greet)
        {
            Console.WriteLine("Greetings dear " + greet);
        }

        static void Main(string[] args)
        {
            String al = "GreenFox";

            GreetingFunction(al);
            Console.ReadLine();
        }
    }
}