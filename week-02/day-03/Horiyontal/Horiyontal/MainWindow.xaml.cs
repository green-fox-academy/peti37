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

namespace Horiyontal
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
            double canvasW = canvas.Width;
            double canvasH = canvas.Height;
            int x = 50;
            int y = 100;
            TwoLines(foxDraw, x, y);


            


        }
        public static void TwoLines(FoxDraw foxDraw, int x, int y)
        {
            for (int i = 0; i < 3; i++)
            {

                foxDraw.StrokeColor(Colors.Green);
                foxDraw.DrawLine(x, y, x+50, y);
                y += 50;
                
            }






        }
    }
}
