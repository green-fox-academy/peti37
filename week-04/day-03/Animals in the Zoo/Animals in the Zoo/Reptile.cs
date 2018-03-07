using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Animals_in_the_Zoo
{
    class Reptile : Animal
    {
        public Reptile(string name) : base("")
        {
            this.name = name;
        }

        public Reptile(string name, int age, int legs, string gender) : base(name)
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
            Console.WriteLine("SsssSSsss!");
        }

        public override string WantChild()
        {
            if (name == "Frog")
            {
                return $"{name}, want a child in a special way :O";
            }
            else
            {
                return $"{name}, want a child from an egg";
            }
        }
    }
}
