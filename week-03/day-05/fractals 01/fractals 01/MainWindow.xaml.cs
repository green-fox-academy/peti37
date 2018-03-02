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

namespace fractals_01
{

    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            var foxDraw = new FoxDraw(canvas);

            foxDraw.FillColor(Colors.Black);
            int layer = 6;
            Point topPoint = new Point(canvas.Width / 2, canvas.Height);
            Point leftPoint = new Point(0, 0);
            Point rightPoint = new Point(canvas.Width, 0);

            Point[] point = new Point[3] { topPoint, leftPoint, rightPoint };





            TriangleForce(foxDraw, layer, topPoint, leftPoint, rightPoint);
        }
        public void TriangleForce(FoxDraw foxDraw, int layer, Point topPoint, Point leftPoint, Point rightPoint)
        {

            if (layer == 0)
            {
                Point[] points = { topPoint, leftPoint, rightPoint };
                foxDraw.FillColor(Colors.Indigo);
                foxDraw.DrawPolygon(points);

            }
            else
            {
                Point leftMid = new Point(
                                (topPoint.X + leftPoint.X) / 2.0,
                                (topPoint.Y + leftPoint.Y) / 2.0);
                Point rightMid = new Point(
                                (topPoint.X + rightPoint.X) / 2.0,
                                (topPoint.Y + rightPoint.Y) / 2.0);
                Point bottomMid = new Point(
                                (leftPoint.X + rightPoint.X) / 2.0,
                                (leftPoint.Y + rightPoint.Y) / 2.0);
                TriangleForce(foxDraw, layer - 1, topPoint, leftMid, rightMid);
                TriangleForce(foxDraw, layer - 1, leftMid, leftPoint, bottomMid);
                TriangleForce(foxDraw, layer - 1, rightMid, bottomMid, rightPoint);
            }
        }
    }
}
