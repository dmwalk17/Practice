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
            SelectList list = new SelectList(getCustomerList, "CustomerId", "Name","--Select A Customer --");
            ViewBag.Customers = list;
            ViewBag.Header1 = "Product/Incident";
            ViewBag.Header2 = "Tech name";
            ViewBag.Header3 = "Opened";
            ViewBag.Header4 = "Closed";


            return View();
        }

        [HttpPost]
        public ActionResult Index(string dummy)
        {
            dw_TechSupportDBContext db = new dw_TechSupportDBContext();
            dw_TechSupportTechIncident db2 = new dw_TechSupportTechIncident();
            var getCustomerList = db.Customers.OrderBy(x => x.Name).ToList();
            SelectList list = new SelectList(getCustomerList, "CustomerId", "Name");

            ViewBag.Customers = list;
            ViewBag.Header1 = "Product/Incident";
            ViewBag.Header2 = "Tech name";
            ViewBag.Header3 = "Opened";
            ViewBag.Header4 = "Closed";



            return View();
        }
    }
}