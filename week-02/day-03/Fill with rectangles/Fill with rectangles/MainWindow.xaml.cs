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

namespace Fill_with_rectangles
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
            FourRectangles(foxDraw, x, y);


        }

        private void FourRectangles(FoxDraw foxDraw, int x, int y)
        {
            Random rng = new Random();
            int rectangleSize = rng.Next(50);
            for (int i = 0; i < 4; i++)
            {

                foxDraw.DrawRectangle(x, y, rectangleSize, rectangleSize);
                rectangleSize += rectangleSize;
                foxDraw.FillColor(Color.FromRgb(

                (byte)rng.Next(0, 255),

                (byte)rng.Next(0, 255),

                (byte)rng.Next(0, 255)));
                y += 80;
               

            }
        }
    }
}
