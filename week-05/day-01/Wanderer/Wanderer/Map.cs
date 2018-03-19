using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;

namespace Wanderer
{
    public class Map : Window
    {
        public string[] content;
        public void Read()
        {
            content = File.ReadAllLines(@"C:\Users\Peti\Documents\greenfox\peti37\week-05\day-01\Wanderer\Wanderer\MapBluePrint.txt");
        }

        public void DrawMap(Canvas canvas)
        {
            Read();
            var tile = new Tile();
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (content[i][j] == '0')
                    {
                        tile.Floor(canvas);
                    }
                    else
                    {
                        tile.Wall(canvas);
                    }
                    tile.PosX += 50;
                }
                tile.PosX -= 500;
                tile.PosY += 50;
            }
        }
    }
}
