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

namespace Centered_boxes
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

            int jozsi = 100;

            boxes(foxDraw, jozsi);
        }

        private void boxes(FoxDraw foxDraw, int jozsi)
        {
            for (int i = 0; i < 3; i++)
            {
                 foxDraw.DrawRectangle(canvas.Width / 2 - jozsi/2, canvas.Height / 2 - jozsi / 2, jozsi, jozsi);
                jozsi -= 20;
            }

        }
    }
}
