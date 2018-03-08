using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Summa
{
    public class Summ
    {


        public int? SumMyNumbersBitch(List<int> intList)
        {
            if (intList == null)
            {
                return null;
            }
            return intList.Sum();
        }
    }
}
