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

namespace Colored_box
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
            TwoLines(foxDraw);

        }
        public static void TwoLines(FoxDraw foxDraw)
        {
            foxDraw.StrokeColor(Colors.Green);
            foxDraw.DrawLine(10, 10, 290, 10);

            foxDraw.StrokeColor(Colors.Blue);
            foxDraw.DrawLine(290, 10, 290, 290);

            foxDraw.StrokeColor(Colors.Red);
            foxDraw.DrawLine(290, 290, 10, 290);

            foxDraw.StrokeColor(Colors.Yellow);
            foxDraw.DrawLine(10, 290, 10, 10);

        }

    }

}
