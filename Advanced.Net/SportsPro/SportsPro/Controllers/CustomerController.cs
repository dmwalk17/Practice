﻿using SportsPro.Models;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Web;
using System.Web.Mvc;

namespace SportsPro.Controllers
{
    [Authorize(Roles = "Customer")]
    public class CustomerController : Controller
    {


        public ActionResult NewSurvey()
        {

            return View();
        }

        [HttpPost]
        public ActionResult NewSurvey(string dummy)
        {
            ViewBag.CustomerID = Convert.ToInt32(Request["txtCustomerNumber"]);
            dw_TechSupportIncidentTechProd db2 = new dw_TechSupportIncidentTechProd();
            IncidentViewModel incidentVM = new IncidentViewModel();




            List<IncidentViewModel> IncidentVMList = (from incident in db2.Incidents
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

            //var IncidentItems = IncidentVMList.ToSelectList(d => "Incident for product + d.ProductName +
            //                                    " closed " + d.DateClosed + "(" + d.Description + ")",
            //                                    d => d.Id.ToString(),
            //                                    " - ");

            if (ViewBag.CustomerId != null)
            {
                foreach (var item in IncidentVMList)
                {
                    if (item.DateClosed != null && item.CustomerID == ViewBag.CustomerId)
                    {
                        //IncidentList.Add("Incident for product" + item.ProductName + "closed" + item.DateClosed + "(" + item.Description + ")");


                        
                    }

                }
            }
            return View(IncidentVMList);
        }

            public ActionResult ProcessSurvey()
            {


                return View();
            }

            public void ExportToCSV()
            {
                //StringBuilder has Append option.
                StringBuilder sb = new StringBuilder();
                sb.AppendLine("\"Customer ID\",\"Incident ID\",\"Response Time\",\"Tech Efficiency\",\"Resolution\",\"Comments\",\"Contact By\"");

                Response.ClearContent();
                Response.AddHeader("Refresh", "3; url=index.html");
                Response.AddHeader("content-disposition", "attachment;filename=ExportSurveyToFile.csv");
                Response.ContentType = "text/csv";

                //var surveys = Survey.GenerateSurveyList();

                //foreach (var survey in surveys)
                //{
                //    sb.AppendLine(string.Format("\"{0}\",\"{1}\",\"{2}\",\"{3}\",\"{4}\",\"{5}\",\"{6}\"",
                //        survey.CustomerID,
                //        survey.IncidentID,
                //        survey.ResponseTime,
                //        survey.TechEfficiency,
                //        survey.Resolution,
                //        survey.Comments,
                //        survey.ContactBy));

                //    Response.Write(sb.ToString());

                //}
                Response.AppendHeader("ProcessSurvey", "Customer");
                Response.Flush();
                Response.End();


            }

            public PartialViewResult GetIncidents()
        {

            return PartialView("_GetIncidents");
        }
        }
    }



