using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _11_Refactorio
{
    class Program
    {
        static void Main(string[] args)
        {
            int number = 5;
            Console.WriteLine(FactorialWithRecursion(number));
            Console.ReadLine();
        }
        public static int FactorialWithRecursion(int n)
        {
            if (n == 1)
            {
                return 1;
            }
            else
            {
                return n * FactorialWithRecursion(n - 1);
            }
        }
    }
}
