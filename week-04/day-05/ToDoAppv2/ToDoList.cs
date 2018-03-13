using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace TodoAppv2
{
    class TodoList
    {
        string path;
        List<string> content;
        string unDone = "[ ]";

        public List<string> Content { get => content; set => content = value; }

        public TodoList()
        {
            path = @"theList.txt";
        }
        private void Read()
        {
            content = File.ReadAllLines(path).ToList();
        }

        public void ListAllTask()
        {
            if (content == null)
            {
                Read();
            }
            for (int i = 0; i < content.Count; i++)
            {
                
                Console.WriteLine($"{i + 1}. {content[i]}");
            }
        }

        public void AddTask(string task)
        {
            Read();
            content.Add(task);
            File.WriteAllLines(path, content);
        }

        public void RemoveTask(string number)
        {
            Read();
            for (int i = 1; i < content.Count+1; i++)
            {
                if (i == int.Parse(number))
                {
                    content.Remove(content[i-1]);
                }
            }
            File.WriteAllLines(path, content);
        }

        public void CompleteTask(int number)
        {
            Read();
            for (int i = 1; i < Content.Count+1; i++)
            {
                if (i == number)
                {
                    content[i-1] += " - DONE";
                }
            }
            File.WriteAllLines(path, content);
        }

        public void UnCompleteTask(int number)
        {
            Read();
            for (int i = 1; i < Content.Count + 1; i++)
            {
                if (i == number)
                {
                   Content[i-1] = Content[i-1].Replace(" - DONE", "");
                }
            }
            File.WriteAllLines(path, content);
        }
    }
}


