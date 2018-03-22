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
    class Boss : Monster
    {
        static Random rand = new Random();
        public new int PosX = rand.Next(0, 10) * 50;
        public new int PosY = rand.Next(0, 10) * 50;

        public Boss()
        {

        }

        public override void DrawMonster(Canvas canvas)
        {
            Map map = new Map();
            map.Read();
            var foxDraw = new FoxDraw(canvas);
            Tile tile = new Tile();
            Monster monster = new Monster();
            Hero hero = new Hero();
            while ('0' != map.content[PosY / 50][PosX / 50] || hero.GetPosition(hero.PosX, hero.PosY) == GetPosition(PosX, PosY))
            {
                Random sss = new Random();
                PosY = sss.Next(0, 10)*50;
                PosX = sss.Next(0, 10)*50;
            }
            foxDraw.AddImage("img/boss.png", PosX, PosY);
        }

        public override void Move(Canvas canvas, int number)
        {
            Map map = new Map();
            map.Read();
            Tile tile = new Tile();
            if (number == 1 && PosY / 50 < 9 && map.content[PosY / 50 + 1][PosX / 50] == '0')
            {
                PosY += 50;
                DrawMonster(canvas);
            }
            if (number == 2 && PosX / 50 < 9 && map.content[PosY / 50][PosX / 50 + 1] == '0')
            {
                PosX += 50;
                DrawMonster(canvas);
            }
            if (number == 3 && PosY / 50 > 0 && map.content[PosY / 50 - 1][PosX / 50] == '0')
            {
                PosY -= 50;
                DrawMonster(canvas);
            }
            if (number == 4 && PosX / 50 > 0 && map.content[PosY / 50][PosX / 50 - 1] == '0')
            {
                PosX -= 50;
                DrawMonster(canvas);
            }
        }


    }
}
