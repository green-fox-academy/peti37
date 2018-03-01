using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sharpie_set
{
    public class SharpieSet
    {
        public List<Sharpie> SharpieList;

        public void AddSharpie(Sharpie sharpie)
        {
            SharpieList.Add(sharpie);
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

        

    }
}
