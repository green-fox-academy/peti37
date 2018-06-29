using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _05_Bunnies
{
    class Program
    {
        static void Main(string[] args)
        {
            int bunnies = 10;
            Console.WriteLine(BunnyEars(bunnies));
            Console.ReadLine();
        }

        public static int BunnyEars(int n)
        {
            if (n == 0)
            {
                return 0;
            }
            else
            { 
                return BunnyEars(n - 1) + 2;
            }
        }
    }
}
