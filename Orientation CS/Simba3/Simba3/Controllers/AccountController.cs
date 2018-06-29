using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Simba3.Models;

namespace Simba3.Controllers
{
    public class AccountController : Controller
    {
        static List<BankAccount> accounts = new List<BankAccount>();


        public IActionResult Index()
        {
            var simba = new BankAccount() { Name = "Simba", Balance = 2000, AnimalType = "Lion", IsKing = true };
            //accounts.Add(simba);
            return View(accounts);
        }

        [HttpPost("AddAccount")]
        public IActionResult AddAccount(BankAccount bankAccount)
        {
            accounts.Add(bankAccount);
            return RedirectToAction("Index");
        }

        public IActionResult Simba()
        {
            var simba = new BankAccount() { Name = "Simba", Balance = 2000, AnimalType = "Lion" };
            accounts.Add(simba);
            return View(simba);
        }

        [HttpPost("PlusCash")]
        public IActionResult PlusCash(int index)
        {
            accounts[index].GetCash();
            return RedirectToAction("Index");
        }
    }
}