using SportsPro.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace SportsPro.Controllers
{
    public class CustomerController : Controller
    {


        public ActionResult Survey()
        {

            return View();
        }

        [HttpPost]
        public ActionResult Survey(string dummy)
        {
            return View();
        }

        public ActionResult ProcessSurvey()
        {
            return View();
        }


    }
}
