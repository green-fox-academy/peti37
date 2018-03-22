using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
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
        Characters chars = new Characters();
        Monster monster = new Monster();
        Monster monster2 = new Monster();
        Hero hero = new Hero();
        Boss boss = new Boss();
        Random rnd = new Random();
        public static int keyToggleCounter = 0;

        public MainWindow()
        {
            InitializeComponent();
            var map = new Map();
            chars.AddToList(monster);
            chars.AddToList(monster2);
            canvas.Children.Clear();
            map.DrawMap(canvas);
            hero.DrawHeroDown(canvas);
            chars.DrawAllMonsters(canvas);
        }

        public void Move(object sender, KeyEventArgs e)
        {
            canvas.Children.Clear();
            Map map = new Map();
            map.DrawMap(canvas);
            if (keyToggleCounter % 2 == 0)
            {
                chars.MoveMonsters(canvas);
                chars.DrawAllMonsters(canvas);
            }
            else
            {
                chars.StayMonsters(canvas);
            }
            chars.Occupied(canvas, monster);

            if (e.Key == Key.Down)
            {
                hero.Move(canvas, 1);
                keyToggleCounter++;
            }
            else if (e.Key == Key.Up)
            {
                hero.Move(canvas, 4);
                keyToggleCounter++;

            }
            else if (e.Key == Key.Right)
            {
                hero.Move(canvas, 2);
                keyToggleCounter++;
            }
            else if (e.Key == Key.Left)
            {
                hero.Move(canvas, 3);
                keyToggleCounter++;
            }

            for (int i = 0; i < chars.GetList().Count; i++)
            {
                if (chars.GetList()[i].GetPosition(chars.GetList()[i].PosX, chars.GetList()[i].PosY) == hero.GetPosition(hero.PosX, hero.PosY))
                {
                    chars.RemoveFromList(chars.GetList()[i]);
                }
            }
        }
    }
}
