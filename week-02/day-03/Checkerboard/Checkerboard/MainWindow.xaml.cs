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

namespace Checkerboard
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

            double width = 0;
            double height = 0;
            int rule;
            for (int i = 0; i < 8; i++)
            {
                if (i % 2 == 0)
                {
                    rule = 0;
                }
                else
                {
                    rule = 1;
                }
                for (int j = 0; j < 8; j++)
                {
                    if (j % 2 == rule)
                    {
                        foxDraw.FillColor(Colors.Black);
                        foxDraw.StrokeColor(Colors.Black);
                        foxDraw.DrawRectangle(width, height, canvas.Width / 8, canvas.Width / 8);
                        width += canvas.Width / 8;
                    }
                    else
                    {
                        foxDraw.FillColor(Colors.White);
                        foxDraw.StrokeColor(Colors.Black);
                        foxDraw.DrawRectangle(width, height, canvas.Width / 8, canvas.Width / 8);
                        width += canvas.Width / 8;
                    }

                }
             height += canvas.Width / 8;
             width -= canvas.Height;

            }
        }

        
    }
}