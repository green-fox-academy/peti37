using System;
using System.Text;
using System.Collections.Generic;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {


            var far = new List<string> { "kuty", "macsk", "kacs", "rók", "halacsk" };

            // Create a method called AppendA() that adds "a" to every string in the far list.
            // The parameter should be a list.
            
            Console.WriteLine(AppendA(far));
            Console.ReadLine();
            // Expected output: "kutya", "macska", "kacsa", "róka", "halacska"
        }
        public static string AppendA(List<string> animals)
        {
            for (int i = 0; i < animals.Count; i++)
            {
                animals[i] = animals[i] + "a";
            }
            string JoinedString = string.Join(", ", animals.ToArray());
            return JoinedString;
        }
    }
}