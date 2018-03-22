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
        HeahUpDisplay hud;
        HeahUpDisplay hud2;
        Characters chars = new Characters();
        Monster monster = new Monster();
        Monster monster2 = new Monster();
        Monster monster3 = new Monster();
        Hero hero = new Hero();
        Boss boss = new Boss();
        Random rnd = new Random();
        public static int keyToggleCounter = 0;

        public MainWindow()
        {
            hud = new HeahUpDisplay(canvas, hero.GetStatus());
            hud2 = new HeahUpDisplay(canvas, monster.GetStatus());
            InitializeComponent();
            var map = new Map();
            chars.AddToList(monster);
            chars.AddToList(monster2);
            chars.AddToList(monster3);
            canvas.Children.Clear();
            map.DrawMap(canvas);
            hero.DrawHeroDown(canvas);
            chars.DrawAllMonsters(canvas);
            HUD.Children.Add(hud.heroStatus);
        }

        public void Move(object sender, KeyEventArgs e)
        {
            canvas.Children.Clear();
            Map map = new Map();
            map.DrawMap(canvas);
            if (e.Key == Key.Space)
            {
                hero.stepCounter = 1;
                hero.Move(canvas, 0);
                for (int i = 0; i < chars.GetList().Count; i++)
                {
                    if (chars.GetList()[i].GetPosition(chars.GetList()[i].PosX, chars.GetList()[i].PosY) == hero.GetPosition(hero.PosX, hero.PosY))
                    {
                        EnemyHUD.Children.Remove(hud2.monsterStatus);
                        EnemyHUD.Children.Add(hud2.monsterStatus);
                        chars.GetList()[i].hp -= hero.sp;
                        hero.hp -= chars.GetList()[i].sp;
                        hud2.RefreshStatusEnemy(chars.GetList()[i].GetStatus());
                        if (chars.GetList()[i].hp <= 0)
                        {
                            chars.RemoveFromList(chars.GetList()[i]);
                            hero.LevelUp();
                            hero.KillCount();
                            EnemyHUD.Children.Remove(hud2.monsterStatus);
                        }
                        if (hero.hp <= 0)
                        {
                            hero.hp += 1000;
                        }
                    }
                }
            }
            hud.RefreshStatus(hero.GetStatus());
            chars.MoveMonsters(canvas, hero);
            chars.DrawAllMonsters(canvas);
            chars.Occupied(canvas, monster);
            chars.Occupied(canvas, monster2);
            chars.Occupied(canvas, monster3);


            if (e.Key == Key.Down)
            {
                hero.Move(canvas, 1);
                hero.StepCounter();
            }
            else if (e.Key == Key.Up)
            {
                hero.Move(canvas, 4);
                hero.StepCounter();

            }
            else if (e.Key == Key.Right)
            {
                hero.Move(canvas, 2);
                hero.StepCounter();
            }
            else if (e.Key == Key.Left)
            {
                hero.Move(canvas, 3);
                hero.StepCounter();
            }

        }
    }
}
