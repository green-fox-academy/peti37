using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace The_Garden_Application
{
    class Tree : Plant
    {
        public Tree(string color) : base(color)
        {
            this.color = color;
            waterLevel = 10;
            absorbLevel = 0.75;
            name = "tree";
        }

       
    }
   
}
