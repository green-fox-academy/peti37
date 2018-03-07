using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace The_Garden_Application
{
    class Plant
    {
        public string color;
        public double waterAmount { get; protected set; }
        public double waterLevel;
        public double absorbLevel;
        public string name;
        

        public Plant(string color)
        {
            this.color = color;
            waterAmount = 0;
        }

        public bool ReadyForWatering()
        {
            return waterAmount <= waterLevel;
        }

        public void Watering(int water)
        {
            waterAmount += water;
        }


    }
}
