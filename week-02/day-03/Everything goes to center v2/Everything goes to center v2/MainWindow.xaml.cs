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

namespace Everything_goes_to_center_v2
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
            for (int i = 0; i <= canvas.Width *4 /20; i++)
            {
                foxDraw.StrokeColor(Colors.Green);
                foxDraw.DrawLine(x, y, 200, 200);
                
                if (i < 20)
                {
                    x += 20;
                }
                else if (i >= 20 && i < 40)
                {
                    y += 20;
                }
                else if (i >= 40 && i < 60)
                {
                    y = 400;
                    x -= 20;
                }
                else if (i > 60 && i < canvas.Width * 4 / 20)
                {
                    x = 0;
                    y -= 20;
                }
            }
            



        }

    }

}
