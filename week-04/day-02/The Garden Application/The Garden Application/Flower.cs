using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace The_Garden_Application
{
    class Flower : Plant
    {
        public Flower(string color) : base(color)
        {
            waterLevel = 5;
            absorbLevel = 0.75;
            name = "flower";
        }

    }
}
