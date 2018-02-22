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

namespace Everything_goes_to_center
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
            TwoLines(foxDraw, x, y);

            



        }
        private void TwoLines(FoxDraw foxDraw, int x, int y)
        {
            for (int i = 0; i < 20 ; i++)
            {
                foxDraw.StrokeColor(Colors.Green);
                foxDraw.DrawLine(x, y, 200, 200);
                x += 20;
                
            }
            for (int i = 0; i < 20; i++)
            {
                foxDraw.StrokeColor(Colors.Green);
                foxDraw.DrawLine(x, y, 200, 200);
                y += 20;
            }
            x = 400;
            for (int i = 0; i < 20; i++)
            {
                foxDraw.StrokeColor(Colors.Green);
                foxDraw.DrawLine(x, y, 200, 200);
                x -= 20;
            }
            y = 400;
            for (int i = 0; i < 20; i++)
            {
                foxDraw.StrokeColor(Colors.Green);
                foxDraw.DrawLine(x, y, 200, 200);
                y -= 20;
            }



        }

    }

}
