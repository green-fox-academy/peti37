using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Teacher_Student
{
    class Program
    {
        static void Main(string[] args)
        {
            Teacher teacher = new Teacher();
            Student me = new Student();

            me.Question(teacher);
            teacher.Answer(me);
            


            Console.ReadLine();
        }
    }
}
