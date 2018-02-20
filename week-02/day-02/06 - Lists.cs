
using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;

namespace GreenFox
{
    class Program
    {

        public static void Main(string[] args)
        {
            var list = new List<int> { 2, 4, 6, 8, 10, 12, 14, 16 };

            // Check if list contains all of the following elements: 4,8,12,16
            // Create a method that accepts list as an input
            // it should return "true" if it contains all, otherwise "false"
            Console.WriteLine(CheckNums(list));
            Console.ReadLine();

        }
        public static bool CheckNums(List<int> numbers)
        {
            var ContainsList = new List<int> { 4, 8, 12, 16 };
            if (numbers.Intersect(ContainsList).Any())
                {
                return true;
            }
            else
            {
                return false;
            }

        }
    }

}