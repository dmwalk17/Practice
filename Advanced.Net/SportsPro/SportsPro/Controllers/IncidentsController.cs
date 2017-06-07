using SportsPro.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace SportsPro.Controllers
{
    [Authorize(Roles = "Technician")]
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


            //April Hauk assisted with the need and location placement by providing a general example of a join in mvc

            List<IncidentViewModel> incidentVMList = (from incident in db2.Incidents
                                                        join technician in db2.Technicians on incident.TechID equals technician.TechID 
                                                        join product in db2.Products on incident.ProductCode equals product.ProductCode 
                                                        select new IncidentViewModel
                                                        {
                                                            CustomerID = incident.CustomerID,
                                                            ProductCode = incident.ProductCode,
                                                            ProductName = incident.Product.Name,
                                                            TechID = incident.TechID,
                                                            TechnicianName = incident.Technician.Name,
                                                            DateOpened = incident.DateOpened,
                                                            DateClosed = incident.DateClosed,
                                                            Description = incident.Description
                                                        }).ToList();

            return View(incidentVMList);


        }


    }
}