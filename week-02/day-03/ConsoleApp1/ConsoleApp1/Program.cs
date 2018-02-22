using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            //  Create a function that takes a number and a list of numbers as a parameter
            //  Returns the indeces of the numbers in the list where the first number is part of
            //  Returns an empty list if the number is not part any of the numbers in the list

            //  Example:
            Console.WriteLine(SubInt(1, new int[] { 1, 11, 34, 52, 61 }));
            //  should print: `[0, 1, 4]`
            Console.WriteLine(SubInt(9, new int[] { 1, 11, 34, 52, 61 }));
            //  should print: '[]'
            Console.ReadLine();

        }

        private static StringBuilder SubInt(int number, int[] list)
        {
            string stringNumber = number.ToString();
            StringBuilder results = new StringBuilder();
            for (int i = 0; i < list.Length; i++)
            {
                if (list[i].ToString().Contains(stringNumber))
                {
                    results.Append(i + ", ");
                }
            }
            return results;

        }
    }
}
