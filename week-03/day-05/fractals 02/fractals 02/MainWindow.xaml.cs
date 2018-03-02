using fractals_02;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Timers;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace fractals_02
{

    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            var foxDraw = new FoxDraw(canvas);

            foxDraw.FillColor(Colors.Transparent);
            int layer = 6;
            double width = 800;
            double height = 800;
            double pozX = 0;
            double pozY = 0;

            var asd = new List<Color>() { Colors.Violet, Colors.Red };
            asd[1]

            //Point topPoint = new Point(canvas.Width / 2, canvas.Height);
            //Point leftPoint = new Point(0, 0);
            //Point rightPoint = new Point(canvas.Width, 0);

            //Point[] point = new Point[3] { topPoint, leftPoint, rightPoint };





            TriangleForce(foxDraw, layer, pozX, pozY, width, height);
        }
        public void TriangleForce(FoxDraw foxDraw, int layer, double pozX, double pozY, double width, double height)
        {

            if (layer == 0)
            {
                foxDraw.FillColor(Colors.Transparent);
                foxDraw.DrawEllipse(pozX, pozY, width, height);

            }
            else
            {
                //Point leftMid = new Point(
                //                (topPoint.X + leftPoint.X) / 2.0,
                //                (topPoint.Y + leftPoint.Y) / 2.0);
                //Point rightMid = new Point(
                //                (topPoint.X + rightPoint.X) / 2.0,
                //                (topPoint.Y + rightPoint.Y) / 2.0);
                //Point bottomMid = new Point(
                //                (leftPoint.X + rightPoint.X) / 2.0,
                //                (leftPoint.Y + rightPoint.Y) / 2.0);

                double pozX1 = pozX *= 2.0;
               double pozY1 = pozY *= 2.0;
               double width1 = width /= 2.0;
               double height1 = height /= 2.0;
                foxDraw.DrawEllipse(pozX1, pozY1, width1, height1);

                TriangleForce(foxDraw, layer - 1, pozX1, pozY1, width1, height1);
                //TriangleForce(foxDraw, layer - 1, leftMid, leftPoint, bottomMid);
                //TriangleForce(foxDraw, layer - 1, rightMid, bottomMid, rightPoint);

            }
        }
    }
}
