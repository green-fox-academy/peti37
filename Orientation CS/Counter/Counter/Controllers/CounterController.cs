using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Counter.Services;
using Microsoft.AspNetCore.Mvc;

namespace Counter.Controllers
{
    public class CounterController : Controller
    {
        private ICounter jozsi;

        public CounterController(ICounter jozsi)
        {
            this.jozsi = jozsi;
        }

        [HttpGet]
        [Route("/")]
        public IActionResult Index()
        {
            return View(jozsi.GetName());
        }

        [HttpPost("/")]
        public IActionResult AddOneNumber()
        {
            jozsi.Increase();
            return RedirectToAction("Index");
        }
    }
}