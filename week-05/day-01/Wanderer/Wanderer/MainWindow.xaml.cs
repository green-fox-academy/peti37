using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Wanderer
{
    public partial class MainWindow : Window, IMove
    {
        Hero hero = new Hero();
        Skeleton skeleton = new Skeleton();
        Random rnd = new Random();



        public MainWindow()
        {
            InitializeComponent();
            var map = new Map();
            map.DrawMap(canvas);
            hero.DrawHeroDown(canvas);
            skeleton.DrawSkeleton(canvas);
        }

        public void Move(object sender, KeyEventArgs e)
        {
            canvas.Children.Clear();
            Map map = new Map();
            map.DrawMap(canvas);



            if (hero.keyToggleCounter % 2 == 1)
            {
                skeleton.Move(canvas, rnd.Next(1, 5));
            }
            if (hero.keyToggleCounter % 2 == 1 || hero.keyToggleCounter % 2 == 0)
            {
                skeleton.DrawSkeleton(canvas);
            }
            if (e.Key == Key.Down)
            {
                hero.Move(canvas, 0, 1);
                hero.keyToggleCounter++;
            }
            else if (e.Key == Key.Up)
            {
                hero.Move(canvas, 0, -1);
                hero.keyToggleCounter++;

            }
            else if (e.Key == Key.Right)
            {
                hero.Move(canvas, 1, 0);
                hero.keyToggleCounter++;
            }
            else if (e.Key == Key.Left)
            {
                hero.Move(canvas, -1, 0);
                hero.keyToggleCounter++;
            }
        }
    }
}
