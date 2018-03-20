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

        public void Move(Canvas canvas, int numberX, int numberY)
        {
            Map map = new Map();
            //map.DrawMap(canvas);
            map.Read();

            if (numberX == 0 && numberY == 1 && borderPosY < 9 && map.content[borderPosY + 1][borderPosX] == '0')
            {
                PosY += 50;
                borderPosY++;
                DrawHeroDown(canvas);
                //keyToggleCounter++;
            }
            else if (numberX == 1 && numberY == 0 && borderPosX < 9 && map.content[borderPosY][borderPosX + 1] == '0')
            {
                PosX += 50;
                borderPosX++;
                DrawHeroRight(canvas);
                //keyToggleCounter++;
            }
            else if (numberX == -1 && numberY == 0 && borderPosX > 0 && map.content[borderPosY][borderPosX - 1] == '0')
            {
                PosX -= 50;
                borderPosX--;
                DrawHeroLeft(canvas);
                //keyToggleCounter++;
            }
            else if (numberX == 0 && numberY == -1 && borderPosY > 0 && map.content[borderPosY - 1][borderPosX] == '0')
            {
                PosY -= 50;
                borderPosY--;
                DrawHeroUp(canvas);
                //keyToggleCounter++;
            }
            else
            {
                DrawHeroDown(canvas);
            }
        }
        public int StepCounter()
        {
            return keyToggleCounter;
        }
    }
}
