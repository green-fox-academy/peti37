using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;

namespace Wanderer
{
    class Monster : Character
    {

        static int randomX = Randomizer.Rander();
        static int randomY = Randomizer.Rander();
        int posX = randomX * 50;
        int posY = randomY * 50;
        public int monsterPosX = randomX;
        public int monsterPosY = randomY;
        public int PosX { get => posX; set => posX = value; }
        public int PosY { get => posY; set => posY = value; }

        public void DrawMonster(Canvas canvas)
        {
            Map map = new Map();
            map.Read();
            var foxDraw = new FoxDraw(canvas);
            Random sss = new Random();
            while ('0' != map.content[monsterPosY][monsterPosX])
            {
                monsterPosY = sss.Next(0, 10);
                monsterPosX = sss.Next(0, 10);
            }
            foxDraw.AddImage("img/skeleton.png", monsterPosX*50, monsterPosY*50);  
        }
        public void Move(Canvas canvas, int number)
        {
            Map map = new Map();
            map.Read();

            if (number == 1 && monsterPosY < 9 && map.content[monsterPosY + 1][monsterPosX] == '0')
            {
                monsterPosY++;
                PosY += 50;
                DrawMonster(canvas);
            }
            if (number == 2 && monsterPosX < 9 && map.content[monsterPosY][monsterPosX + 1] == '0')
            {
                monsterPosX++;
                PosX += 50;
                DrawMonster(canvas);
            }
            if (number == 3 && monsterPosY > 0 && map.content[monsterPosY - 1][monsterPosX] == '0')
            {
                monsterPosY--;
                PosY -= 50;
                DrawMonster(canvas);
            }
            if (number == 4 && monsterPosX > 0 && map.content[monsterPosY][monsterPosX - 1] == '0')
            {
                monsterPosX--;
                PosX -= 50;
                DrawMonster(canvas);
            }
        }
    }
}
