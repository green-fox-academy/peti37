using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Input;

namespace Wanderer
{
    class Hero : Character
    {
        int posX = 0;
        int posY = 0;

        Hero hero = new Hero();
        int borderPosX = 0;
        int borderPosY = 0;
        public int keyToggleCounter = 0;

        public int PosX { get => posX; set => posX = value; }
        public int PosY { get => posY; set => posY = value; }

        public void DrawHeroDown(Canvas canvas)
        {
            var foxDraw = new FoxDraw(canvas);
            foxDraw.AddImage("img/hero-down.png", PosX, PosY);
        }

        public void DrawHeroRight(Canvas canvas)
        {
            var foxDraw = new FoxDraw(canvas);
            foxDraw.AddImage("img/hero-right.png", PosX, PosY);
        }

        public void DrawHeroLeft(Canvas canvas)
        {
            var foxDraw = new FoxDraw(canvas);
            foxDraw.AddImage("img/hero-Left.png", PosX, PosY);
        }

        public void DrawHeroUp(Canvas canvas)
        {
            var foxDraw = new FoxDraw(canvas);
            foxDraw.AddImage("img/hero-Up.png", PosX, PosY);
        }

        public override void Move(object sender, KeyEventArgs e, Canvas canvas)
        {
            throw new NotImplementedException();
        }
    }
}
