using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _03_sum_of_digits
{
    class Program
    {
        static void Main(string[] args)
        {
            int number = 5565;
            Console.WriteLine(SumDig(number));
            Console.ReadLine();
        }
        public static int SumDig(int n)
        {
            if (n != 0)
            {
                return n % 10 + SumDig(n / 10);
            }
            else
            {
                return 0;
            }
        }
    }
}
