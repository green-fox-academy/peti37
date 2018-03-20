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
        Hero hero = new Hero();
        Map map = new Map();
        public int PosX { get => posX; set => posX = value; }
        public int PosY { get => posY; set => posY = value; }

        public void DrawSkeleton(Canvas canvas)
        {
            var foxDraw = new FoxDraw(canvas);
            foxDraw.AddImage("img/skeleton.png", PosX, PosY);
        }

        public override void Move(Canvas canvas, Monster monster)
        {
            int monsterPosX = 0;
            int monsterPosY = 0;
            map.Read();
            if (hero.keyToggleCounter % 2 == 0 && map.content[monsterPosY + 1][monsterPosX] == '0')
            {
                monsterPosY++;
                PosY += 50;
                DrawSkeleton(canvas);
            }
            if (hero.keyToggleCounter % 2 == 1 || hero.keyToggleCounter % 2 == 0)
            {
                DrawSkeleton(canvas);
            }
        }
    }
}
