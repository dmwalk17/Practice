using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace SportsPro.Models
{
    public class Survey
    {
        [Required]
        [Display(Name = "Customer ID")]
        public int CustomerID { get; set; }

        [Required]
        [Display(Name = "Incident ID")]
        public int IncidentID { get; set; }

        [Required]
        [Display(Name ="Response Time")]
        public int ResponseTime { get; set; }

        [Required]
        [Display(Name = "Tech Efficiency")]
        public int TechEfficiency { get; set; }

        [Required]
        [Display(Name = "Resolution")]
        public int Resolution { get; set; }

        [Display(Name = "Comments")]
        public string Comments { get; set; }

        [Display(Name = "Contact By")]
        public string ContactBy { get; set; }

        public static List<Survey> GenerateSurveyList()
        {
            List<Survey> surveys = new List<Survey>
            {
                new Survey{IncidentID = 1, ResponseTime = 2, TechEfficiency = 2, Resolution = 2, Comments = "", ContactBy = ""}
            };
            return surveys;
        }
    }
}