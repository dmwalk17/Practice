using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using SportsPro.Models;

namespace SportsPro.Controllers
{
    [Authorize(Roles = "Administrator")]
    public class AdministrationController : Controller
    {

        // GET: Administration
        public ActionResult Index()
        {

            var selectedCust = new Customer();

            dw_TechSupportDBContext db = new dw_TechSupportDBContext();
            ViewData["SelectedItem"] = Request["ddlCustomers"];
            var getCustomerList = db.Customers.OrderBy(x => x.Name).ToList();
            SelectList list = new SelectList(getCustomerList, "CustomerId", "Name");
            foreach (var cust in getCustomerList)
            {
                if (cust.IsSelected == true)
                {
                    ViewBag.Address = cust.Address;
                    ViewBag.City = cust.City;
                    ViewBag.State = cust.State;
                    ViewBag.Zip = cust.ZipCode;
                    ViewBag.Phone = cust.Phone;
                    ViewBag.Email = cust.Email;
                }


            }
            Session["myValue"] = 8;
            ViewBag.MyValue = Session["myValue"];
            ViewBag.Customers = list;
            return View();
        }
        [HttpPost]
        public ActionResult Index(string dummy)
        {

            var selectedCust = new Customer();
            dw_TechSupportDBContext db = new dw_TechSupportDBContext();
            ViewData["SelectedItem"] = Request["ddlCustomers"];
            var getCustomerList = db.Customers.OrderBy(x => x.Name).ToList();
            SelectList list = new SelectList(getCustomerList, "CustomerId", "Name", ViewData["SelectedItem"]);
            foreach (var cust in getCustomerList)
            {
                if (cust.CustomerID == Convert.ToInt32(ViewData["SelectedItem"]))
                {
                    ViewBag.Address = cust.Address;
                    ViewBag.City = cust.City;
                    ViewBag.State = cust.State;
                    ViewBag.Zip = cust.ZipCode;
                    ViewBag.Phone = cust.Phone;
                    ViewBag.Email = cust.Email;
                }
            }
            ViewBag.Customers = list;
            Customer CurrentCustomer = new Customer();
            CurrentCustomer.CustomerID = Convert.ToInt32(ViewData["SelectedItem"]);
            CurrentCustomer.Address = ViewBag.Address;
            CurrentCustomer.City = ViewBag.City;
            CurrentCustomer.State = ViewBag.State;
            CurrentCustomer.ZipCode = ViewBag.Zip;
            CurrentCustomer.Phone = ViewBag.Phone;
            CurrentCustomer.Email = ViewBag.Email;
            TempData["CurrentCustomer"] = CurrentCustomer;
            return View();
        }

        public void AddContact()
        {
            CustomerList MyCustomers = new CustomerList();
            try
            {
                if (CustomerList.GetCustomers() != null)
                {
                    MyCustomers = CustomerList.GetCustomers();
                    Customer CurrentCustomer = (Customer)TempData["CurrentCustomer"];
                    MyCustomers.AddItem(CurrentCustomer);
                }
                    RedirectToAction("Index","Administration");
            }
            catch
            {
                RedirectToAction("Index", "Administration");
            }

        }

        public PartialViewResult DeleteContact()
        {
            return PartialView("_ContactView");
        }

        public PartialViewResult UpdateContact()
        {
            dw_TechSupportDBContext db = new dw_TechSupportDBContext();
            List<Customer> model = db.Customers.ToList();
            return PartialView("_ContactView", model);
        }
        public ActionResult ContactList()
        {
            dw_TechSupportDBContext db = new dw_TechSupportDBContext();
            List<SelectListItem> selectListItems = new List<SelectListItem>();
            foreach (Customer customer in db.Customers.OrderBy(x => x.Name))
            {
                SelectListItem selectListItem = new SelectListItem
                {
                    Text = customer.Name,
                    Value = customer.CustomerID.ToString(),
                    Selected = customer.IsSelected ?? false
                };
                selectListItems.Add(selectListItem);
            }


            return View(selectListItems);


        }

        // GET: Customer/Details/5
        public ActionResult Details(int id)
        {
            return View();
        }

        // GET: Customer/Create
        [HttpGet]
        public ActionResult Create()
        {
            return View();
        }

        // POST: Customer/Create
        [HttpPost]
        public ActionResult Create(Customer customer)
        {
            try
            {
                // TODO: Add insert logic here

                BusinessLayerCustomer customerBusinessLayer = new BusinessLayerCustomer();
                customerBusinessLayer.AddCustomer(customer);

                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }

        // GET: Customer/Edit/5
        public ActionResult Edit(int id)
        {
            return View();
        }

        // POST: Customer/Edit/5
        [HttpPost]
        public ActionResult Edit(int id, FormCollection collection)
        {
            try
            {
                // TODO: Add update logic here

                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }

        // GET: Customer/Delete/5
        public ActionResult Delete(int id)
        {
            return View();
        }

        // POST: Customer/Delete/5
        [HttpPost]
        public ActionResult Delete(int id, FormCollection collection)
        {
            try
            {
                // TODO: Add delete logic here

                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }
    }
}