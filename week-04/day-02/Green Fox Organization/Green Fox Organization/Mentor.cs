using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Green_Fox_Organization
{
    class Mentor : Person
    {
        string level;

        public Mentor(string name, int age, string gender, string level) : base(name, age, gender)
        {
            this.level = level;
        }

        public Mentor()
        {

            level = "intermediate";
        }


        public override void GetGoal()
        {
            Console.WriteLine("Educate brilliant junior software developers.");
        }

        public override void Introduce()
        {
            Console.WriteLine($"Hi, I'm {name}, a {age} year old {gender} {level} mentor.");

        }
    }
}
