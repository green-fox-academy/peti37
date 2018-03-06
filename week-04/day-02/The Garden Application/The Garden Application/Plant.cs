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
        public double waterAmount { get; set; }
        protected double waterLevel;
        public double absorbLevel;
        

        public Plant(string color, double waterAmount, double waterLevel, double absorbLevel)
        {
            this.absorbLevel = absorbLevel;
            this.waterLevel = waterLevel;
            this.color = color;
            waterAmount = 0;
        }

        public Plant()
        {

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
