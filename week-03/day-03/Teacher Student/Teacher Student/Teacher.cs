using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Teacher_Student
{
    public class Teacher
    {
        public void Teach()
        {
            Console.WriteLine("Teacher teached something new for the student \n");
        }
        public void Answer(Student student)
        {
            Console.WriteLine("This is a quite good answer for the question.");
            student.Learn();
            
        }
        public void Punish(Student student)
        {
            Console.WriteLine("The student was punished by the teacher, because the student did something 'bad'.");
        }

    }
}
