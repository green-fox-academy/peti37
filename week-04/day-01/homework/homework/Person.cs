using System;
using System.Collections.Generic;
using System.Text;

namespace homework
{
    class Person
    {
        public string name;
        public int age;
        string gender;

        public Person(string name, int age, string gender)
        {
            this.name = name;
            this.age = age;
            this.gender = gender;
        }

        public Person()
        {
            this.name = "Jane Doe";
            this.age = 30;
            this.gender = "female";
        }

        public void Introduce()
        {
            Console.WriteLine($"Hi, I'm {name}, a {age} year old {gender}.");
        }

        public void GetGoal()
        {
            Console.WriteLine("My goal is: Live for the moment!");
        }

    }
}