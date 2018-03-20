﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Input;

namespace Wanderer
{
    abstract class Monster : Character
    {
        abstract public void Move(Canvas canvas, Monster monster);
    }
}
