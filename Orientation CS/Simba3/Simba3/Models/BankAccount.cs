using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;

namespace Simba3.Models
{
    public class BankAccount
    {
        public string Name { get; set; }
        [DisplayFormat(ApplyFormatInEditMode = true, DataFormatString = "{0:N")]
        public decimal Balance { get; set; }
        public string AnimalType { get; set; }
        public bool IsKing { get; set; }

        public void GetCash()
        {
            if (IsKing)
            {
                Balance += 100;
            }
            Balance += 10;
        }
    }
}
