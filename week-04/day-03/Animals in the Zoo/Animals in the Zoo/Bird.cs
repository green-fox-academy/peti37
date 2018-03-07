using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Animals_in_the_Zoo
{
    class Bird : Animal
    {
        public Bird(string name) : base("")
        {
            this.name = name;
        }

        public Bird(string name, int age, int legs, string gender) : base(name)
        {
            this.name = name;
            this.age = age;
            this.legs = legs;
            this.gender = gender;
        }

        public override string GetName()
        {
            return name;
        }

        public override void Greet()
        {
            Console.WriteLine("Csirip!");
        }

        public override string WantChild()
        {
            return $"{name}, want a child from an egg";
        }
    }
}
