using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            Double timeSpent = 17 * 5 * 6;
            Double percantage = 17 * 52;
            Console.WriteLine("hours is spent with coding: " + timeSpent + "hours" );
            Console.WriteLine("the percentage of the coding hours in the semester: " + timeSpent / percantage * 100 + " % ");

            Console.ReadLine();
        }
    }
}