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

namespace Starry_night
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            var foxDraw = new FoxDraw(canvas);
            byte color = 128;


            boxes(foxDraw, color);
        }

        private void boxes(FoxDraw foxDraw, byte color)
        {
            Random randomGen = new Random();
            for (int i = 0; i < 60; i++)
            {
                foxDraw.BackgroundColor(Colors.Black);
                int randomSize = randomGen.Next(5, 12);
                int randomCords = randomGen.Next(1, 380);
                int randomCords2 = randomGen.Next(1, 380);
                int randomGreyColors = randomGen.Next(100, 210);
                foxDraw.FillColor(Color.FromRgb(color, color, color));
                color += 10;
                foxDraw.DrawRectangle(randomCords, randomCords2, randomSize, randomSize);

            }

        }
    }
}
