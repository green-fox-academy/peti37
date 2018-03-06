using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace The_Garden_Application
{
    class Flower : Plant
    {
        public Flower(string color, double waterAmount, double waterLevel, double absorbLevel) : base(color, 0, 5, 0.75)
        {

        }

        public Flower()
        {

            if (waterAmount < waterLevel)
            {
                Console.WriteLine($"The {color} Flower needs water");
            }
            else
            {
                Console.WriteLine($"The {color} Flower doesn't need water");
            }
        }

    }
}
