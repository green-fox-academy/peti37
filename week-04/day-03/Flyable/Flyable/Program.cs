using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Animals_in_the_Zoo;

namespace Flyable
{
    class Program
    {
        static void Main(string[] args)
        {
            var bird = new Bird("Csirkusz");
            var helicopter = new Helicopter("FeketeRotor");
            bird.TakeOff();
            bird.Fly();
            bird.Land();
            Console.WriteLine();
            helicopter.TakeOff();
            helicopter.Fly();
            helicopter.Land();

            Console.ReadLine();
        }
    }
}
