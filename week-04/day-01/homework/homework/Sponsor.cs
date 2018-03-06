using System;
using System.Collections.Generic;
using System.Text;

namespace homework
{
    class Sponsor
    {
        string name;
        int age;
        string gender;
        string company;
        int hiredStudents;

        public Sponsor(string name, int age, string gender, string company)
        {
            this.name = name;
            this.age = age;
            this.gender = gender;
            this.company = company;
        }

        public Sponsor()
        {
            name = "Jane Doe";
            age = 30;
            gender = "female";
            company = "Google";
            hiredStudents = 0;
        }

        public void Introduce()
        {
            Console.WriteLine($"Hi, I'm {name}, a {age} year old gender who represents {company} and hired {hiredStudents} students so far.");
        }

        public void GetGoal()
        {
            Console.WriteLine("Hire brilliant junior software developers.");
        }

        public void Hire()
        {
            hiredStudents++;
        }


    }
}