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

        public abstract Point GetPosition(int X, int Y);
        public abstract void Move(Canvas canvas, int number);
        public abstract void DrawMonster(Canvas canvas);

    }

}
