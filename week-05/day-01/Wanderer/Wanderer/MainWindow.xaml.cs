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

    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window, IMove
    {
        Hero hero = new Hero();

        public MainWindow()
        {
            InitializeComponent();
            var map = new Map();
            var skeleton = new Skeleton();
            skeleton.Move(canvas, skeleton);
            map.DrawMap(canvas);
            hero.DrawHeroDown(canvas);
        }

        public void Move(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Down)
            {
                hero.Move(canvas, 0, 1);
            }
            else if (e.Key == Key.Up)
            {
                hero.Move(canvas, 0, -1);
            }
            else if (e.Key == Key.Right)
            {
                hero.Move(canvas, 1, 0);
            }
            else if (e.Key == Key.Left)
            {
                hero.Move(canvas, -1, 0);
            }
        }
    }
}
