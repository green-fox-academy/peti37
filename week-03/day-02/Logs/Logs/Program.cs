using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Logs
{
    class Program
    {
        static void Main(string[] args)
        {
            string log = "log.txt";
            UniqueIp(log);
            getAndPost(log);
            Console.ReadLine();
        }

        private static void UniqueIp(string log)
        {
            string[] content = File.ReadAllLines(log);
            string[] splitedLines = new string[3];
            var ipList = new List<string>();

            foreach (var item in content)
            {

                splitedLines = item.Split("   ");
                ipList.Add(splitedLines[1]);
            }

            string[] uniqContent = ipList.Distinct().ToArray();
            for (int i = 0; i < uniqContent.Length; i++)
            {
                Console.WriteLine(uniqContent[i]);
            }


        }
        private static void getAndPost(string log)
        {
            string[] content = File.ReadAllLines(log);
            string[] splitedLines = new string[3];
            var ipList = new List<string>();
            int sumOfGets = 0;
            int sumOfPosts = 0;

            foreach (var item in content)
            {

                splitedLines = item.Split("   ");
                ipList.Add(splitedLines[2]);
            }
            
            for (int i = 0; i < ipList.Count; i++)
            {

                if (ipList[i] == @"GET /")
                {
                    sumOfGets++;
                }
                else
                {
                    sumOfPosts++;
                }
            }
            Console.WriteLine("Gets:" + sumOfGets + " Posts:" + sumOfPosts);
        }
    }
}
