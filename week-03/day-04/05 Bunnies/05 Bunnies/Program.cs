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
            int bunnies = 5;
            Console.WriteLine(BunnyEars(bunnies));
            Console.ReadLine();
        }
        public static int BunnyEars(int n)
        {
            if (n == 1)
            {
                return 1;
            }
            else
            {
                BunnyEars(n - 1);
                return n * 2;
            }
        }
    }
}
