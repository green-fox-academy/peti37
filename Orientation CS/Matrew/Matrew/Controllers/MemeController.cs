using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Matrew.Models;
using Matrew.ViewModels;
using Microsoft.AspNetCore.Mvc;

namespace Matrew.Controllers
{
    public class MemeController : Controller
    {

        static List<Meme> memeList = new List<Meme>();


        public IActionResult Index()
        {
            return View(memeList);
        }

        [HttpPost("AddMeme")]
        public IActionResult AddMeme(Meme meme)
        {
            memeList.Add(meme);
            return RedirectToAction("Index");
        }
    }
}