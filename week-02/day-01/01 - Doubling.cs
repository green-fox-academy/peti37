using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            int ak = 123;
            doubling(ak);
            Console.WriteLine(doubling(ak));
            Console.ReadLine();
        }
        static int doubling(int doubledNumber)
        {
            return doubledNumber = doubledNumber * 2;
        }
    }
}
