using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _09_Strings_again_and_again
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Give me a word");
            string word = Console.ReadLine();
            Console.WriteLine("I put stars between the chars: \n" + switchX(word));
            Console.ReadLine();

        }
        public static string switchX(string n)
        {
            if (n.Length == 1)
            {
                return n;
            }
            else
            {
                
               
                    return n = n[0] + "*" + switchX(n.Substring(1));
            }
        }
    }
}
