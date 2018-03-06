using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Green_Fox_Organization
{
    class Sponsor : Person
    {
        string company;
        int hiredStudents;

        public Sponsor(string name, int age, string gender, string company, int hiredStudents = 0) : base(name, age, gender)
        {
            this.company = company;
            this.hiredStudents = hiredStudents;
        }

        public Sponsor()
        {

            company = "Google";
            hiredStudents = 0;
        }

        public override void GetGoal()
        {
            Console.WriteLine("Hire brilliant junior software developers.");
        }

        public override void Introduce()
        {
            Console.WriteLine($"Hi, I'm {name}, a {age} year old {gender} who represents {company} and hired {hiredStudents} students so far.");

        }

        public void Hire()
        {
            hiredStudents++;
        }
    }
}
