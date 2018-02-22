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

namespace Project___Triangles
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

            double x = -25;
            int y = 800;
            int z = 50;
            for (int i = 0; i < 20; i++)
            {
                for (int j = 20; j > i; j--)
                {
                    Triangle(foxDraw, x, y, z);
                    x += 50;
                }
                y -= 40;
                x = 75*i;
                if (x >= 75)
                {
                    x -= 50 * i;
                }
            }
        }

        private void Triangle(FoxDraw foxDraw, double x, int y, int z)
        {
            foxDraw.DrawLine((50 + x)/2, (100 + y + z)/2, (100 + x)/2, (100 + y + z)/2);
            foxDraw.DrawLine((50 + x)/2, (100 + y + z)/2, (75 + x)/2, (60 + y + z)/2);
            foxDraw.DrawLine((100 + x)/2, (100 + y + z)/2, (75 + x)/2, (60 + y + z)/2);
        }
       

    }
}
