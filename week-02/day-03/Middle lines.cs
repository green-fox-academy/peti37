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

namespace WpfApp5
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
            foxDraw.StrokeColor(Colors.Blue);
            foxDraw.DrawLine(0, 200, 400, 200);

            foxDraw.StrokeColor(Colors.Blue);
            foxDraw.DrawLine(50, 100, 400, 100);

            foxDraw.StrokeColor(Colors.Blue);
            var startPoint = new Point(200, 0);
            var endPoint = new Point(200, 400);
            foxDraw.DrawLine(startPoint, endPoint);


        }

    }

}
