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
 
            ViewBag.SelectedItem = Request["ddlCustomers"];
            var getCustomerList = db.Customers.OrderBy(x => x.Name).ToList();
            SelectList list = new SelectList(getCustomerList, "CustomerId", "Name", ViewBag.SelectedItem);
            ViewBag.Customers = list;
            ViewBag.Header1 = "Product/Incident";
            ViewBag.Header2 = "Tech name";
            ViewBag.Header3 = "Opened";
            ViewBag.Header4 = "Closed";
            dw_TechSupportIncidentTechProd db2 = new dw_TechSupportIncidentTechProd();

            List<Incident> incidentList = db2.Incidents.ToList();
            
            //List<Incident> custIncident = (List<Incident>)(db2.Incidents.Where(x=>x.CustomerID == Convert.ToInt32(Request["ddlCustomer"])));
            IncidentViewModel incidentVM = new IncidentViewModel();

            //List<IncidentViewModel> incidentVMList = incidentList.Select(x=> new IncidentViewModel
            //{ CustomerID = x.CustomerID,
            //  ProductCode = x.ProductCode,
            //  ProductName =x.Product.Name,
            //  TechID = x.TechID,
            //  TechnicianName = x.Technician.Name,
            //  DateOpened = x.DateOpened,
            //  DateClosed = x.DateClosed,
            //  Description = x.Description}).ToList();
            




            



            return View(incidentList);
        }

        public PartialViewResult _Index()
        {
            dw_TechSupportIncidentTechProd db2 = new dw_TechSupportIncidentTechProd();
            Incident incident = db2.Incidents.SingleOrDefault(x=>x.CustomerID==12001);
            IncidentViewModel incidentVM = new IncidentViewModel();

            incidentVM.CustomerID = incident.CustomerID;
            incidentVM.ProductCode = incident.ProductCode;
            incidentVM.TechID = incident.TechID;
            incidentVM.DateOpened = incident.DateOpened;
            incidentVM.DateClosed = incident.DateClosed;
            incidentVM.Description = incident.Description;

           
            return PartialView(incidentVM);
        }
    }
}