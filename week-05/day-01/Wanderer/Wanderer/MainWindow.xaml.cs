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
    public partial class MainWindow : Window
    {
        Hero hero = new Hero();
        Skeleton skeleton = new Skeleton();

        int borderPosX = 0;
        int borderPosY = 0;
        int skeletonPosX = 0;
        int skeletonPosY = 0;
        int keyToggleCounter = 0;

        public MainWindow()
        {
            InitializeComponent();
            var foxDraw = new FoxDraw(canvas);
            var map = new Map();
            var hero = new Hero();
            map.DrawMap(canvas);
            hero.DrawHeroDown(canvas);
        }

        private void WindowKeyDown(object sender, KeyEventArgs e)
        {
            canvas.Children.Clear();
            var tile = new Tile();
            var map = new Map();
            map.DrawMap(canvas);
            map.Read();

            if (keyToggleCounter % 2 == 0 && map.content[skeletonPosY + 1][skeletonPosX] == '0')
            {
                skeletonPosY++;
                skeleton.PosY += 50;
                skeleton.DrawSkeleton(canvas);
            }
            if (keyToggleCounter % 2 == 1 || keyToggleCounter % 2 == 0)
            {
                skeleton.DrawSkeleton(canvas);
            }
            if (e.Key == Key.Down && borderPosY < 9 && map.content[borderPosY + 1][borderPosX] == '0')
            {
                hero.PosY += 50;
                borderPosY++;
                hero.DrawHeroDown(canvas);
                keyToggleCounter++;
            }
            else if (e.Key == Key.Right && borderPosX < 9 && map.content[borderPosY][borderPosX + 1] == '0')
            {
                hero.PosX += 50;
                borderPosX++;
                hero.DrawHeroRight(canvas);
                keyToggleCounter++;
            }
            else if (e.Key == Key.Left && borderPosX > 0 && map.content[borderPosY][borderPosX - 1] == '0')
            {
                hero.PosX -= 50;
                borderPosX--;
                hero.DrawHeroLeft(canvas);
                keyToggleCounter++;
            }
            else if (e.Key == Key.Up && borderPosY > 0 && map.content[borderPosY - 1][borderPosX] == '0')
            {
                hero.PosY -= 50;
                borderPosY--;
                hero.DrawHeroUp(canvas);
                keyToggleCounter++;
            }
            else
            {
                hero.DrawHeroDown(canvas);
            }

        }
    }
}
