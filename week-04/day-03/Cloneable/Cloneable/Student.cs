using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cloneable
{
    class Student : Person, ICloneable
    {
        string previousOrganization;
        int skippedDays;

        public Student(string name, int age, string gender, string previousOrganization) : base(name, age, gender)
        {

            this.previousOrganization = previousOrganization;
            skippedDays = 0;
        }

        public Student()
        {
            name = "Jane Doe";
            age = 30;
            gender = "female";
            previousOrganization = "The School of Life";
            skippedDays = 0;
        }


        public override void GetGoal()
        {
            Console.WriteLine("Be a junior software developer.");
        }

        public override void Introduce()
        {
            Console.WriteLine($"Hi, I'm {name}, a {age} year old gender from {previousOrganization} who skipped {skippedDays} days from the course already.");

        }
        public void SkipDays(int numberOfDays)
        {
            skippedDays += numberOfDays;
        }

        public object Clone()
        {
            return new Student("Sanyi", 0, "male", "Mars");
        }
    }
}
