using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Input;

namespace Wanderer
{
    abstract class Character
    {
        public abstract void Move(object sender, KeyEventArgs e, Canvas canvas);
    }
    
}
