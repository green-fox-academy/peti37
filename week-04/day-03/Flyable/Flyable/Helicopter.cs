using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Flyable
{
    class Helicopter : Vehicle, IFlyable
    {
        public Helicopter(string name) :base()
        {
            this.name = name;
            maxSpeed = 300f;
            color = "black";
        }

        public void Fly()
        {
            Console.WriteLine($"The {name} is flying!");
        }

        public void Land()
        {
            Console.WriteLine($"The {name} just landed safely.");
        }

        public void TakeOff()
        {
            Console.WriteLine($"The {name} just TookOff");
        }
    }
}
