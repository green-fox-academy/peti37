using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using FoxClub.Models;

namespace FoxClub.Controllers
{
    public class HomeController : Controller
    {
        static Fox fox = new Fox();
        static List<string> log = new List<string>();
        DateTime localDate = DateTime.Now;

        public IActionResult Index()
        {
            if (fox.name == null)
            {
                return RedirectToAction("login");
            }
            return View(fox);
        }
        [HttpGet("login")]
        public IActionResult Login()
        {
            fox.TricksToLearn();
            fox.BasicFoods();
            fox.BasicDrinks();
            return View(fox);
        }

        [HttpPost("login")]
        public IActionResult GetName(string name)
        {
            fox.GetName(name);
            log.Add($"{localDate.ToString()} - Logged in as {name}.");
            return RedirectToAction("index");
        }

        [HttpGet("nutrition")]
        public IActionResult Nutrition()
        {
            if (fox.name == null)
            {
                return RedirectToAction("login");
            }
            return View(fox);
        }

        [HttpPost("AddFood")]
        public IActionResult AddFood(string food)
        {
            fox.AddFood(food);
            log.Add($"{localDate.ToString()} - Added {food} to the food-list.");
            return RedirectToAction("nutrition");
        }

        [HttpPost("AddDrink")]
        public IActionResult AddDrink(string drink)
        {
            fox.AddDrink(drink);
            log.Add($"{localDate.ToString()} - Added {drink} to the food-list.");
            return RedirectToAction("nutrition");
        }

        [HttpPost("GetFoodNDrink")]
        public IActionResult GetFoodNDrink(string food, string drink)
        {
            fox.drink = drink;
            fox.food = food;
            log.Add($"{localDate.ToString()} - {fox.name} is now eating {food} and drinking {drink}");
            return RedirectToAction("about");
        }

        public IActionResult About()
        {
            if (fox.name == null)
            {
                return RedirectToAction("login");
            }
            return View(fox);
        }
        [HttpGet("trickcenter")]
        public IActionResult TrickCenter()
        {
            return View(fox);
        }

        [HttpPost("GetTrick")]
        public IActionResult GetTrick(string trick)
        {
            fox.Tricks.Add(trick);
            fox.KnownTricks.Remove(trick);
            log.Add($"{localDate.ToString()} - {fox.name} learnt a new trick:{trick}.");
            return RedirectToAction("trickcenter");
        }

        [HttpGet("history")]
        public IActionResult History()
        {
            return View(log);
        }

        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }
    }
}
