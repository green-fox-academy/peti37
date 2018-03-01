using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _06_bunnies_again
{
    class Program
    {
        static void Main(string[] args)
        {
            int bunnies = 6;
            Console.WriteLine(BunnyEars(bunnies));
            Console.ReadLine();
        }
        public static int BunnyEars(int n)
        {
            
            if (n == 0)
            {
                return 0;
            }
            else if (n % 2 == 1)
            {
                return BunnyEars(n - 1) + 2;
            }
            else 
            {
                return BunnyEars(n - 1) + 3;
            }
        }
    }
}
