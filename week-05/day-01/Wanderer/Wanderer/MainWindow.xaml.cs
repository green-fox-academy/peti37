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
        Monster monster = new Monster();
        Monster monster2 = new Monster();
        Hero hero = new Hero();
        Boss boss = new Boss();
        Random rnd = new Random();
        List<Monster> charList = new List<Monster>();
        List<Monster> charList2 = new List<Monster>();
        public static int keyToggleCounter = 0;




        public MainWindow()
        {
            InitializeComponent();
            var map = new Map();
            Characters.AddToList(monster);
            Characters.AddToList(monster2);
            canvas.Children.Clear();
            map.DrawMap(canvas);
            hero.DrawHeroDown(canvas);
            Characters.DrawAllMonsters(canvas);
        }

        public void Move(object sender, KeyEventArgs e)
        {
            canvas.Children.Clear();
            Map map = new Map();
            map.DrawMap(canvas);
            Characters.MoveMonsters(canvas);
            Characters.Occupied(canvas, monster);

            for (int i = 0; i < Characters.GetList().Count; i++)
            {
                if (Characters.GetList()[i].GetPosition(Characters.GetList()[i].PosX, Characters.GetList()[i].PosY)== hero.GetPosition(hero.PosX, hero.PosY))
                {
                    Characters.GetList().Remove(Characters.GetList()[i]);
                    canvas.Children.Clear();
                    map.DrawMap(canvas);
                    Characters.DrawAllMonsters(canvas);
                }
            }

            if (e.Key == Key.Down)
            {
                hero.Move(canvas, 1);
                hero.keyToggleCounter++;
            }
            else if (e.Key == Key.Up)
            {
                hero.Move(canvas, 4);
                hero.keyToggleCounter++;

            }
            else if (e.Key == Key.Right)
            {
                hero.Move(canvas, 2);
                hero.keyToggleCounter++;
            }
            else if (e.Key == Key.Left)
            {
                hero.Move(canvas, 3);
                hero.keyToggleCounter++;
            }
        }
    }
}
