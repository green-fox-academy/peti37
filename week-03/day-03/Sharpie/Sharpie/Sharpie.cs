﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sharpie
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
            InkAmount = 100;
        }
        public void Use()
        {
            InkAmount--;
            Console.WriteLine("You used some ink, you have left " + InkAmount + " amounts of ink");
        }

    }

}
