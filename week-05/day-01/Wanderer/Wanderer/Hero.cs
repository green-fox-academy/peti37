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
        int heroPosX = 0;
        int heroPosY = 0;
        public int keyToggleCounter = 0;
        public int HeroPosX { get => heroPosX; set => heroPosX = value; }
        public int HeroPosY { get => heroPosY; set => heroPosY = value; }

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

            if (number == 1 && heroPosY < 9 && map.content[heroPosY + 1][heroPosX] == '0')
            {
                PosY += 50;
                heroPosY++;
                DrawHeroDown(canvas);
            }
            else if (number == 2 && heroPosX < 9 && map.content[heroPosY][heroPosX + 1] == '0')
            {
                PosX += 50;
                heroPosX++;
                DrawHeroRight(canvas);
            }
            else if (number == 3 && heroPosX > 0 && map.content[heroPosY][heroPosX - 1] == '0')
            {
                PosX -= 50;
                heroPosX--;
                DrawHeroLeft(canvas);
            }
            else if (number == 4 && heroPosY > 0 && map.content[heroPosY - 1][heroPosX] == '0')
            {
                PosY -= 50;
                heroPosY--;
                DrawHeroUp(canvas);
            }
            else
            {
                DrawHeroDown(canvas);
            }
            keyToggleCounter++;
        }
        public int StepCounter()
        {
            return keyToggleCounter;
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
