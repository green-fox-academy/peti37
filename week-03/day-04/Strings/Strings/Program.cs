﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Strings
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Give me a word (with lowercases) with an X in it");
            string word = Console.ReadLine();
            Console.WriteLine("I switched the X-s with Y-s: \n" + switchX(word));
            Console.ReadLine();

        }
        public static string switchX(string n)
        {
            if (n.Length == 1)
            {
                if (n == "x")
                {
                    return "y";
                }
                else
                {
                    return n;
                }
            }
            else
            {
                if (n[0] == 'x')
                {
                    return n = "y" + switchX(n.Substring(1));
                }
                else
                {
                    return n = n[0] + switchX(n.Substring(1));
                }
            }
        }
    }
}
