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
            int number = 3;
            int powerNumber = 3;
            Console.WriteLine(Power(number, powerNumber));
            Console.ReadLine();
        }

        public static int Power(int n, int p)
        {
            if (p == 0)
            {
                return 1;
            }
            else
            {
                return n * Power(n, p - 1);
            }
        }
    }
}
