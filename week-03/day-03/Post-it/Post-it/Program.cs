using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Post_it
{
    class Program
    {
        public struct PostIt
        {
            public string BackGroundColor;
            public string text;
            public string textcolor;
            public PostIt(string p1, string p2, string p3)
            {
                BackGroundColor = p1;
                text = p2;
                textcolor = p3;

              
            }
        }
        static void Main(string[] args)
        {
            PostIt First = new PostIt("orange", "blue", "Idea 1");
            PostIt Second = new PostIt("pink", "black", "Awesome");
            PostIt Third = new PostIt("yellow", "green", "suberb");
        }
    }
}
