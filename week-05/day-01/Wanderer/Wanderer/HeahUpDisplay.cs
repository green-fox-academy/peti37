using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;

namespace Wanderer
{
    class HeahUpDisplay
    {
        public TextBlock heroStatus = new TextBlock();
        public TextBlock monsterStatus = new TextBlock();

        public HeahUpDisplay(Canvas canvas, string status)
        {
            heroStatus.Text = status;
            monsterStatus.Text = status;


            heroStatus.Foreground = Brushes.Green;
            heroStatus.FontSize = 11;

            monsterStatus.Foreground = Brushes.Red;
            monsterStatus.FontSize = 11;
        }

        public string RefreshStatus(string status)
        {
            return heroStatus.Text = status;
        }

        public string RefreshStatusEnemy(string status)
        {
            return monsterStatus.Text = status;
        }
    }
}
