using SportsPro.Models;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Web;
using System.Web.Mvc;

namespace SportsPro.Controllers
{
    public class CustomerController : Controller
    {


        public ActionResult NewSurvey()
        {

            return View();
        }

        [HttpPost]
        public ActionResult NewSurvey(string dummy)
        {
            return View();
        }

        public ActionResult ProcessSurvey()
        {
            

            return View();
        }

        public void ExportToCSV()
        {
            //StringBuilder has Append option.
            StringBuilder sb = new StringBuilder();
            sb.AppendLine ("\"Customer ID\",\"Incident ID\",\"Response Time\",\"Tech Efficiency\",\"Resolution\",\"Comments\",\"Contact By\"");

            Response.ClearContent();
            Response.AddHeader("content-disposition", "attachment;filename=ExportSurveyToFile.csv");
            Response.ContentType = "text/csv";

            var surveys = Survey.GenerateSurveyList();

            foreach (var survey in surveys)
            {
                sb.AppendLine(string.Format("\"{0}\",\"{1}\",\"{2}\",\"{3}\",\"{4}\",\"{5}\",\"{6}\"",
                    survey.CustomerID,
                    survey.IncidentID,
                    survey.ResponseTime,
                    survey.TechEfficiency,
                    survey.Resolution,
                    survey.Comments,
                    survey.ContactBy));

                Response.Write(sb.ToString());
                Response.End();
            }
            
            RedirectToAction("ProcessSurvey");
        }


    }
}
