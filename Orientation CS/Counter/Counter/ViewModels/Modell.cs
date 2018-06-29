using Counter.Services;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Counter.ViewModels
{
    public class Modell
    {
        private ICounter jozsi;

        public Modell(ICounter MyModel)
        {
            jozsi = MyModel;
        }
    }
}
