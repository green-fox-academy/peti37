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

namespace Connect_the_dots
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
            List<Point> pointsOfList = new List<Point> { new Point(10, 10), new Point(290, 10), new Point(290, 290), new Point(10, 290) };

            List<Point> pointsOfList2 = new List<Point> {new Point(50, 100), new Point(70, 70), new Point(80, 90), new Point(90, 90), new Point(100, 70),
             new Point(120, 100), new Point(85, 130), new Point(50, 100)};

            ConnectPoints(foxDraw,pointsOfList2);
           
        }

        private void ConnectPoints(FoxDraw foxDraw, List<Point> inputList)
        {
            foxDraw.StrokeColor(Colors.Green);
            foxDraw.DrawPolygon(inputList);
        }
    }
}
