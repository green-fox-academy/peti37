using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BlogPost
{
    class Program
    {
        static void Main(string[] args)
        {
            BlogPost FirstPost = new BlogPost("John Doe", "Lorem Ipsum", "Lorem ipsum dolor sit amet.", "2000.05.04.");
            BlogPost SecondPost = new BlogPost("Tim Urban", "Wait but why", "A popular long-form, stick-figure-illustrated blog about almost everything.", "2010.10.10.");
            BlogPost ThirdPost = new BlogPost("William Turton", "One Engineer Is Trying to Get IBM to Reckon With Trump", "Daniel Hanley, a cybersecurity engineer at IBM, doesn’t want to be the center of attention. \n When I asked to take his picture outside one of IBM’s New York City offices, he told me that he wasn’t really into the whole organizer profile thing.", "2017.03.28.");

            Console.WriteLine($"{FirstPost.Title} titled by {FirstPost.AuthorName} posted at {FirstPost.PublicationDate} \n\t -{FirstPost.Text}\n");
            Console.WriteLine($"{SecondPost.Title} titled by {SecondPost.AuthorName} posted at {SecondPost.PublicationDate} \n\t -{SecondPost.Text}\n");
            Console.WriteLine($"{ThirdPost.Title} titled by {ThirdPost.AuthorName} posted at {ThirdPost.PublicationDate} \n\t -{ThirdPost.Text}");
            Console.ReadLine();
        }
    }
}
