using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Teacher_Student
{
    public class Student
    {
        public void Learn()
        {
            
            Console.WriteLine("The student learnt something new");
        }
        public void Question(Teacher teacher)
        {
            Console.WriteLine("The student asked something.");
            teacher.Teach();
            

        }
    }
}
