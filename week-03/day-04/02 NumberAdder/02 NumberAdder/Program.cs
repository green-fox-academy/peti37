using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _02_NumberAdder
{
    class Program
    {
        static void Main(string[] args)
        {
            int number = 135;
            Console.WriteLine(adder(number));
            Console.ReadLine();
        }
        public static int adder(int n)
        {
            if (n == 1)
            {
                return n;
            }
            else
            {
                return n + adder(n - 1);
            }
        }
    }
}
