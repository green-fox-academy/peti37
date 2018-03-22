using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace Wanderer
{
    class Hero : Character
    {

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

        public override void Move(Canvas canvas, int number)
        {
            Map map = new Map();
            map.Read();

            if (number == 1 && PosY/50 < 9 && map.content[PosY/50 + 1][PosX/50] == '0')
            {
                PosY += 50;
                DrawHeroDown(canvas);
            }
            else if (number == 2 && PosX/50 < 9 && map.content[PosY/50][PosX/50 + 1] == '0')
            {
                PosX += 50;
                DrawHeroRight(canvas);
            }
            else if (number == 3 && PosX/50 > 0 && map.content[PosY/50][PosX/50 - 1] == '0')
            {
                PosX -= 50;
                DrawHeroLeft(canvas);
            }
            else if (number == 4 && PosY/50 > 0 && map.content[PosY/50 - 1][PosX/50] == '0')
            {
                PosY -= 50;
                DrawHeroUp(canvas);
            }
            else if (number == 0)
            {
                PosX -= 0;
                PosY -= 0;
                DrawHeroDown(canvas);
            }
            else
            {
                DrawHeroDown(canvas);
            }
        }

        public override Point GetPosition(int X, int Y)
        {
            return new Point(X, Y);
        }

        public override void DrawMonster(Canvas canvas)
        {
            throw new NotImplementedException();
        }
    }
}
