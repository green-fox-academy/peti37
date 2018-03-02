using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sharpie_set
{
    public class Sharpie
    {
        public string Color;
        public float Width;
        public float InkAmount;

        public Sharpie(string Color, float Width)
        {
            this.Color = Color;
            this.Width = Width;
            InkAmount = 10;
        }
        public void Use()
        {
            InkAmount-=5;
            Console.WriteLine("You used some ink, you have left " + InkAmount + " amounts of ink");
        }

    }
}
