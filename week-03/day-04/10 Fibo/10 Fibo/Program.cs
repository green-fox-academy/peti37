using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _10_Fibo
{
    class Program
    {
        static void Main(string[] args)
        {
            int number = 7;
            Console.WriteLine(nFibo(number));
            Console.ReadLine();
        }
        public static int nFibo(int n)
        {
            if (n == 0)
            {
                return 0;
            }
            else if (n == 1)
            {
                return 1;
            }
            else
            {
                return nFibo(n - 1) + nFibo(n-2);
            }
        }
    }
}
