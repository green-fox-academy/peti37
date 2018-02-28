using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Counter
{
    class Program
    {
        static void Main(string[] args)
        {
            Counter First = new Counter(37);
            Console.WriteLine(First.start);
            First.Add(2);
            Console.WriteLine(First.start);
            First.Reset();
            Console.WriteLine(First.start);
            First.Add();
            Console.WriteLine(First.start);
            First.Get();
            Console.WriteLine(First.start);

            Console.ReadLine();
        }
    }
}
