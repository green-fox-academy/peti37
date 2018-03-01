using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _04_Power
{
    class Program
    {
        static void Main(string[] args)
        {
            int number = 5;
            int powerNumber = 3;
            Console.WriteLine(Power(number, powerNumber));
            Console.ReadLine();
        }
        public static int Power(int n, int p)
        {
            if (p == 0)
            {
                return n;
            }
            else if (p == 1)
            {
                return n;
            }
            else
            {
                return p * Power(n, p-1);
            }
        }
    }
}
