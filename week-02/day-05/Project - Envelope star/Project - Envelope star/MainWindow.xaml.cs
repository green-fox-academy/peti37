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

namespace Project___Envelope_star
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

            int width1 = 200;
            int height1 = 0;
            int width2 = 200;
            int height2 = 200;

            int SecondWidth1 = 200;
            int SecondHeight1 = 0;
            int SecondWidth2 = 200;
            int SecondHeight2 = 200;

            int ThirdWidth1 = 200;
            int ThirdHeight1 = 200;
            int ThirdWidth2 = 200;
            int ThirdHeight2 = 400;

            int FourthWidth1 = 200;
            int FourthHeight1 = 200;
            int FourthWidth2 = 200;
            int FourthHeight2 = 400;

            TwoLines(foxDraw, width2, width1, height2, height1);
            TwoLines2(foxDraw, SecondWidth1, SecondHeight1, SecondWidth2, SecondHeight2);
            TwoLines3(foxDraw, ThirdWidth1, ThirdHeight1, ThirdWidth2, ThirdHeight2);
            TwoLines4(foxDraw, FourthWidth1, FourthHeight1, FourthWidth2, FourthHeight2);
        }

        private void TwoLines4(FoxDraw foxDraw, int fourthWidth1, int fourthHeight1, int fourthWidth2, int fourthHeight2)
        {
            for (int i = 0; i < canvas.Width / 10; i++)
            {
                foxDraw.StrokeColor(Colors.Green);
                foxDraw.DrawLine(fourthWidth1, fourthHeight1, fourthWidth2, fourthHeight2);

                if (i < canvas.Width / 20)
                {
                    fourthHeight2 -= 10;
                    fourthWidth1 += 10;

                }
            }
        }

        private void TwoLines3(FoxDraw foxDraw, int thirdWidth1, int thirdHeight1, int thirdWidth2, int thirdHeight2)
        {
            for (int i = 0; i < canvas.Width / 10; i++)
            {
                foxDraw.StrokeColor(Colors.Green);
                foxDraw.DrawLine(thirdWidth1, thirdHeight1, thirdWidth2, thirdHeight2);

                if (i < canvas.Width / 20)
                {
                    thirdHeight2 -= 10;
                    thirdWidth1 -= 10;

                }
            }
        }

        private void TwoLines2(FoxDraw foxDraw, int secondWidth1, int secondHeight1, int secondWidth2, int secondHeight2)
        {
            for (int i = 0; i < canvas.Width / 10; i++)
            {
                foxDraw.StrokeColor(Colors.Green);
                foxDraw.DrawLine(secondWidth1, secondHeight1, secondWidth2, secondHeight2);


                if (i < canvas.Width / 20)
                {
                    secondHeight1 += 10;
                    secondWidth2 -= 10;

                }
            }
        }

        private void TwoLines(FoxDraw foxDraw, int width2, int width1, int height2, int height1)
        {
            for (int i = 0; i < canvas.Width / 10; i++)
            {
                foxDraw.StrokeColor(Colors.Green);
                foxDraw.DrawLine(width1, height1, width2, height2);


                if (i < canvas.Width / 20)
                {
                    height1 += 10;
                    width2 += 10;

                }
                //else if (i >= 20 && i < 40)
                //{
                //    y += 20;
                //}
                //else if (i >= 40 && i < 60)
                //{
                //    y = 400;
                //    x -= 20;
                //}
                //else if (i > 60 && i < canvas.Width * 4 / 20)
                //{
                //    x = 0;
                //    y -= 20;
                //}
            }

        }
    }

}