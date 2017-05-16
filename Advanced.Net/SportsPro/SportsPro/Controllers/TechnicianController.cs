using SportsPro.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace SportsPro.Controllers
{
    public class TechnicianController : Controller
    {
        // GET: Technician
        public ActionResult Index()
        {
            dw_TechSupportDBContext db = new dw_TechSupportDBContext();
            var getCustomerList = db.Customers.OrderBy(x => x.Name).ToList();
            SelectList list = new SelectList(getCustomerList, "CustomerId", "Name");
            ViewBag.Customers = list;
            return View();
        }
    }
}