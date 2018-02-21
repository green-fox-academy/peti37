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

namespace Purple_steps
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

            int width = 0;
            int height = 0;
            for (int i = 0; i < 20; i++)
            {
                foxDraw.FillColor(Colors.Purple);
                foxDraw.StrokeColor(Colors.Black);
                foxDraw.DrawRectangle(width, height, 15, 15);
                width += 15;
                height += 15;
                
            }
        }

        private void boxes(FoxDraw foxDraw, int size)
        {
            for (int i = 0; i < 3; i++)
            {
                foxDraw.DrawRectangle(canvas.Width / 2 - size / 2, canvas.Height / 2 - size / 2, size, size);
                size -= 20;
            }

        }
    }
}