using System;
using System.IO;

namespace TodoAppv2
{
    class Program
    {
        private static string ADD = "-a";
        private static string LIST = "-l";
        private static string DONE = "-d";
        private static string UNDONE = "-ud";
        private static string REMOVE = "-r";


        static void Main(string[] args)
        {
            try
            {
                string command = args[0];
                if (command.Equals(LIST))
                {
                    TodoList readTheFile = new TodoList();

                    readTheFile.ListAllTask();
                    return;
                }
                else if (command.Equals(ADD))
                {
                    TodoList readTheFile = new TodoList();

                    string input = Console.ReadLine();
                    readTheFile.AddTask(input);

                }
                else if (command.Equals(REMOVE))
                {
                    TodoList readTheFile = new TodoList();

                    string input = Console.ReadLine();
                    readTheFile.RemoveTask(input);

                }
                else if (command.Equals(DONE))
                {
                    TodoList readTheFile = new TodoList();

                    int inputIndex = int.Parse(Console.ReadLine());
                    readTheFile.CompleteTask(inputIndex);
                }
                else if (command.Equals(UNDONE))
                {
                    TodoList readTheFile = new TodoList();

                    int inputIndex = int.Parse(Console.ReadLine());
                    readTheFile.UnCompleteTask(inputIndex);
                }
                else
                {
                    Console.WriteLine("Unsupported operation.");
                }
            }
            catch (IndexOutOfRangeException)
            {
                Console.WriteLine("Command Line Todo application\n\n" +
                        "=============================\n\n" +
                        "Command line arguments:\n" +
                        " -l   Lists all the tasks\n" +
                        " -a   Adds a new task\n" +
                        " -r   Removes a task\n" +
                        " -d   Completes a task\n" +
                        " -ud  Uncompletes a task");
            }
            catch (FileNotFoundException)
            {
                Console.WriteLine("file not found"); 
            }
        }
    }
}
