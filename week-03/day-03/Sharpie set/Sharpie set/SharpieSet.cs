using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sharpie_set
{
    public class SharpieSet
    {
        public List<Sharpie> SharpieList = new List<Sharpie>();



        public void AddSharpie(Sharpie sharpie)
        {
            SharpieList.Add(sharpie);
        }

        public void UseSharpie(Sharpie sharpie)
        {
            sharpie.Use();
        }

        public int CountUsable()
        {
            int numberOfUsableSharpies = 0;
            foreach (var sharp in SharpieList)
            {
                if (sharp.InkAmount != 0)
                {
                  numberOfUsableSharpies++;
                }
            }
            return numberOfUsableSharpies;
        }

        public void RemoveSharpie()
        {
            foreach (var sharp in SharpieList)
            {
                if (sharp.InkAmount == 0)
                {
                    SharpieList.Remove(sharp);
                }
            }
        }

        public void HowMany()
        {
            for (int i = 0; i < SharpieList.Count; i++)
            {
                Console.WriteLine(i);
            }
        }

        

    }
}
