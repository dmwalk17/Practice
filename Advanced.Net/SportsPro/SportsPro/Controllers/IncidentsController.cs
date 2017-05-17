using SportsPro.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace SportsPro.Controllers
{
    public class IncidentsController : Controller
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

            var selectedCust = new Customer();
 
            ViewData["SelectedItem"] = Request["ddlCustomers"];
            var getCustomerList = db.Customers.OrderBy(x => x.Name).ToList();
            SelectList list = new SelectList(getCustomerList, "CustomerId", "Name", ViewData["SelectedItem"]);
            dw_TechSupportIncidents db2 = new dw_TechSupportIncidents();
            var getIncidentList = db2.Incidents.OrderBy(x => x.DateOpened).ToList();
            


            ViewBag.Customers = list;
            ViewBag.Header1 = "Product/Incident";
            ViewBag.Header2 = "Tech name";
            ViewBag.Header3 = "Opened";
            ViewBag.Header4 = "Closed";
            ViewBag.Incidents = getIncidentList;



            return View();
        }
    }
}