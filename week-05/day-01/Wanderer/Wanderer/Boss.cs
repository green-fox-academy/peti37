using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;

namespace Wanderer
{
    class Boss : Monster
    {
        //static Random rand = new Random();
        //static int randomX = rand.Next(0, 10);
        //static int randomY = rand.Next(0, 10);
        //int posX = randomX * 50;
        //int posY = randomY * 50;
        //public int monsterPosX = randomX;
        //public int monsterPosY = randomY;
        //public int PosX { get => posX; set => posX = value; }
        //public int PosY { get => posY; set => posY = value; }
        //public int RandomX { get => randomX; set => randomX = value; }
        //public int RandomY { get => randomY; set => randomY = value; }

        //public void DrawBoss(Canvas canvas)
        //{
        //    var foxDraw = new FoxDraw(canvas);
        //    foxDraw.AddImage("img/boss.png", PosX, PosY);
        //}

        //public void Move(Canvas canvas, int number)
        //{
        //    Map map = new Map();

        //    map.Read();

        //    if (number == 1 && monsterPosY < 9 && map.content[monsterPosY + 1][monsterPosX] == '0')
        //    {
        //        monsterPosY++;
        //        PosY += 50;
        //        DrawBoss(canvas);
        //    }
        //    if (number == 2 && monsterPosX < 9 && map.content[monsterPosY][monsterPosX + 1] == '0')
        //    {
        //        monsterPosX++;
        //        PosX += 50;
        //        DrawBoss(canvas);
        //    }
        //    if (number == 3 && monsterPosY > 0 && map.content[monsterPosY - 1][monsterPosX] == '0')
        //    {
        //        monsterPosY--;
        //        PosY -= 50;
        //        DrawBoss(canvas);
        //    }
        //    if (number == 4 && monsterPosX > 0 && map.content[monsterPosY][monsterPosX - 1] == '0')
        //    {
        //        monsterPosX--;
        //        PosX -= 50;
        //        DrawBoss(canvas);
        //    }
        //}
    }
}
