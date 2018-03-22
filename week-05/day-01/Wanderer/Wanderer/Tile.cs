using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;

namespace Wanderer
{
    class Tile
    {
        int posX = 0;
        int posY = 0;

        public int PosX { get => posX; set => posX = value; }
        public int PosY { get => posY; set => posY = value; }
        private bool walkable;
        public bool Walkable { get => walkable; set => walkable = value; }

        public Tile(bool walkable)
        {
            Walkable = walkable;
        }

        public Tile()
        {

        }

        public void Floor(Canvas canvas)
        {
            var foxDraw = new FoxDraw(canvas);
            foxDraw.AddImage("img/floor.png", posX, posY);
            Walkable = true;
        }

        public void Wall(Canvas canvas)
        {
            var foxDraw = new FoxDraw(canvas);
            foxDraw.AddImage("img/wall.png", posX, posY);
            Walkable = false;
        }
    }
}
