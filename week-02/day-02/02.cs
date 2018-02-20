using System;
using System.Text;
using System.Collections.Generic;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {

            string url = "https//www.reddit.com/r/nevertellmethebots";
            //url = url.Replace("bots", "odds");
            // or
            url = url.Insert(38, "odds");
            url = url.Remove(42, 4);


            // Accidentally I got the wrong URL for a funny subreddit. It's probably "odds" and not "bots"
            // Also, the URL is missing a crutial component, find out what it is and insert it too!
            // Try to solve it more than once using different string functions!

            Console.WriteLine(url);
            Console.ReadLine();

        }


    }
}