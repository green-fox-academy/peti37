using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace The_Garden_Application
{
    class Tree : Plant
    {
        public Tree(string color, double waterAmount, double waterLevel, double absorbLevel) : base(color, 0, 10, 0.4)
        {

        }

        public Tree()
        {
            if (waterAmount < waterLevel)
            {
                Console.WriteLine($"The {color} Tree needs water");
            }
            else
            {
                Console.WriteLine($"The {color} Tree doesn't need water");
            }
        }
    }
}
