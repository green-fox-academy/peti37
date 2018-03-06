using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Green_Fox_Organization
{
    class Cohort
    {
        string name;
        List<Student> students;
        List<Mentor> mentors;

        public Cohort(string name)
        {
            this.name = name;
            students = new List<Student>();
            mentors = new List<Mentor>();
        }

        public void AddStudent(Student student)
        {
            students.Add(student);
        }

        public void AddMentor(Mentor mentor)
        {
            mentors.Add(mentor);
        }

        public void Info()
        {
            Console.WriteLine($"The {name} cohort has {students.Count} students and {mentors.Count} mentors.");
        }
    }
}
