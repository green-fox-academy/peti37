using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;

namespace Wanderer
{
    public abstract class Character
    {
        public int PosX = 0;
        public int PosY = 0;

        public double hp;
        public double sp;
        protected double dp;

        public Character(double hp, double sp, double dp)
        {
            this.hp = hp;
            this.sp = sp;
            this.dp = dp;
        }

        public abstract Point GetPosition(int X, int Y);
        public abstract void Move(Canvas canvas, int number);
        public abstract void DrawMonster(Canvas canvas);
        public abstract string GetStatus();

    }

}
