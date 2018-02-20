
            using System;
            using System.Text;
            using System.Collections.Generic;

namespace GreenFox
{
    class Program
    {

        public static void Main(string[] args)
        {
            var List = new List<int> { 1, 2, 3, 4, 5, };
            Console.WriteLine(ContainsSeven(List));
            Console.ReadLine();
            // Write a method that checks if the arrayList contains "7" if it contains return "Hoorray" otherwise return "Noooooo"
            // The output should be: "Noooooo"
            // Do this again with a different solution using different list methods!

        }
        public static string ContainsSeven(List<int> numbers)
        {
            
            if (numbers.Contains(7))
            {
                return "Hoorray";
            }
            else
            {
                return "Noooooo";
            }
            
        }
    }
        
}