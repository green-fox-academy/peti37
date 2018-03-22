using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;

namespace Wanderer
{
    public class Monster : Character
    {

        static Random rand = new Random();


        public override void DrawMonster(Canvas canvas)
        {
            Map map = new Map();
            map.Read();
            var foxDraw = new FoxDraw(canvas);
            while ('0' != map.content[PosY / 50][PosX / 50] || PosX == 0 && PosY == 0)
            {
                PosY = rand.Next(0, 10) * 50;
                PosX = rand.Next(0, 10) * 50;
            }
            foxDraw.AddImage("img/skeleton.png", PosX, PosY);
        }

        public override Point GetPosition(int X, int Y)
        {
            return new Point(X, Y);
        }

        public override void Move(Canvas canvas, int number)
        {
            Map map = new Map();
            map.Read();
            if (number == 1 && PosY / 50 < 9 && map.content[PosY / 50 + 1][PosX / 50] == '0')
            {
                PosY += 50;
            }
            if (number == 2 && PosX / 50 < 9 && map.content[PosY / 50][PosX / 50 + 1] == '0' )
            {
                PosX += 50;
            }
            if (number == 3 && PosY / 50 > 0 && map.content[PosY / 50 - 1][PosX / 50] == '0' )
            {
                PosY -= 50;
            }
            if (number == 4 && PosX / 50 > 0 && map.content[PosY / 50][PosX / 50 - 1] == '0' )
            {
                PosX -= 50;
            }
            FoxDraw foxDraw = new FoxDraw(canvas);
            foxDraw.AddImage("img/skeleton.png", PosX, PosY);
        }

    }
}
