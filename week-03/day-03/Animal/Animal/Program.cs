using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Animal
{
    class Program
    {
        static void Main(string[] args)
        {
            Animal Duck = new Animal();
            Duck.drink();
            Duck.eat();
            Duck.play();



            Console.ReadLine();
        }
    }
}
