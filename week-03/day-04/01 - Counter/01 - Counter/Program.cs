using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _01___Counter
{
    class Program
    {
        static void Main(string[] args)
        {
            int number = 50;
            counter(number);
            Console.ReadLine();

        }
        static int counter(int remaining)
        {
            if (remaining == 0)
            {
                return 0;
            }
            else
            {
                Console.WriteLine(remaining);
                return counter(remaining - 1);
            }
        }
    }
    
}
