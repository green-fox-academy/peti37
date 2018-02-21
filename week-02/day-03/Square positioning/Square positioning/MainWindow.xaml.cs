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

namespace Square_positioning
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
            int x = 0;
            int y = 0;
            ThreeSquare(foxDraw, x, y);
        }

        private void ThreeSquare(FoxDraw foxDraw, int x, int y)
        {
            for (int i = 0; i < 3; i++)
            {
                foxDraw.DrawRectangle(x, y, 50, 50);
                y += 70;


            }
        }
    }

}
