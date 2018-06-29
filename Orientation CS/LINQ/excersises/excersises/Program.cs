using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace excersises
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] n = { 1, 3, -2, -4, -7, -3, -8, 12, 19, 6, 9, 10, 14 };
            var evenNumbers = n.Where(x => x % 2 == 0);
            foreach (var numbers in evenNumbers)
            {
                //Console.WriteLine(numbers);
            }

            int[] r = { 1, 3, -2, -4, -7, -3, -8, 12, 19, 6, 9, 10, 14 };
            var aveOfOddNums = r.Where(x => x % 2 == 1).Average();
            //Console.WriteLine(aveOfOddNums);

            int[] q = { 1, 3, -2, -4, -7, -3, -8, 12, 19, 6, 9, 10, 14 };
            var squaredPosNums = q.Where(x => x > 0).Select(x => x * x);

            foreach (var num in squaredPosNums)
            {
                //Console.Write("{0}, ", num);
            }

            int[] sn = new[] { 3, 9, 2, 8, 6, 5 };

            var squaredBiggerThenTwenty = sn.Select(x => x * x).Where(x => x > 20).Select(x => Math.Sqrt(x));
            foreach (var num in squaredBiggerThenTwenty)
            {
                //Console.Write("{0}, ", num);
            }

            int[] fr = new int[] { 5, 9, 1, 2, 3, 7, 5, 6, 7, 3, 7, 6, 8, 5, 4, 9, 6, 2 };
            var freq = from f in fr
                       group f by f into g
                       select g;

            foreach (var nums in freq)
            {
                //Console.WriteLine("Number {0} appears {1} times", nums.Key, nums.Count());
            }

            string excercise = "Write a LINQ Expression to find the frequency of characters in a given string!";
            var stringFreq = from chars in excercise
                             group chars by chars into c
                             select c;
            foreach (var characters in stringFreq)
            {
                //Console.WriteLine("Char {0} appears {1} times", characters.Key, characters.Count());
            }

            string[] cities = { "ROME", "LONDON", "NAIROBI", "CALIFORNIA", "ZURICH", "NEW DELHI", "AMSTERDAM", "ABU DHABI", "PARIS" };
            var startAEndByI = cities.Where(x => x.StartsWith("A") && x.EndsWith("I"));
            foreach (var city in startAEndByI)
            {
                //Console.WriteLine(city);
            }

            string excer = "Write a LINQ Expression to find the uppercase characters in a string!";
            var upperCaseString = excer.Where(x => x.ToString() == x.ToString().ToUpper()).Select(x => x);
            foreach (var UpperChars in upperCaseString)
            {
                Console.Write(UpperChars);
            }
            Console.WriteLine();

            Fox[] foxes = new[] {
            new Fox("sanyika", "pallida", "green"),
            new Fox("marika", "macrotis", "blue"),
            new Fox("jozsika", "pallida", "green"),
            new Fox("hajnika", "corsac", "green"),
            new Fox("sarika", "pallida", "yellow")
            };

            var greenfoxes = from fox in foxes
                             where fox.type == "pallida"
                             where fox.color == "green"
                             select fox;

            foreach (var fox in greenfoxes)
            {
                Console.WriteLine(fox.name);
            }

            Console.ReadLine();
        }
    }
}
