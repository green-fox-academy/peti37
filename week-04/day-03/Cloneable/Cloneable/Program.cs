using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cloneable
{
    class Program
    {
        static void Main(string[] args)
        {
            Student Jozsi = new Student();
            var sanyi = (Student)Jozsi.Clone();

            Jozsi.Introduce();
            sanyi.SkipDays(5);
            sanyi.Introduce();

            Console.WriteLine();
            Console.ReadLine();

        }
    }
}
