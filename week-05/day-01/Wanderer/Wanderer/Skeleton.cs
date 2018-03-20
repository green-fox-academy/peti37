using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;

namespace Wanderer
{
    class Skeleton : Monster
    {
        int posX = 0;
        int posY = 0;

        public int PosX { get => posX; set => posX = value; }
        public int PosY { get => posY; set => posY = value; }

        public void DrawSkeleton(Canvas canvas)
        {
            var foxDraw = new FoxDraw(canvas);
            foxDraw.AddImage("img/skeleton.png", PosX, PosY);
        }
    }
}
