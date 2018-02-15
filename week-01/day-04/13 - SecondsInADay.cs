using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            int currentHours = 14;
            int currentMinutes = 34;
            int currentSeconds = 42;

            int SecondsOfADay = 24 * 60 * 60;
            int SpentSeconds = currentHours * 60 + currentMinutes * 60 + currentSeconds;

            Console.WriteLine(SecondsOfADay - SpentSeconds);
            Console.ReadLine();


            // Write a program that prints the remaining seconds (as an integer) from a
            // day if the current time is represented by the variables
        }
    }
}