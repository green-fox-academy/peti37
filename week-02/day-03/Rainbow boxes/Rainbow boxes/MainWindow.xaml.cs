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

namespace Rainbow_boxes
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
            byte color = 200;
            int bela = 200;


            boxes(foxDraw, bela, color);
        }

        private void boxes(FoxDraw foxDraw, int bela, byte color)
        {
            for (int i = 0; i < 4; i++)
            {
                foxDraw.DrawRectangle(canvas.Width / 2 - bela / 2, canvas.Height / 2 - bela / 2, bela, bela);
                foxDraw.FillColor(Color.FromArgb(color, color, color, 0));
                color += color;
                bela -= 50;

            }

        }
    }
}
