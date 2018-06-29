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
            Console.Write(numberAdder(5));
            Console.Read();
        }

        public static int numberAdder(int n)
        {
            Console.Write(n);
            if (n == 1)
            {
                Console.Write(" = ");
                return 1;
            }
            else
            {
                Console.Write(" + ");
                return n + numberAdder(n - 1);
            }
        }
    }
}
