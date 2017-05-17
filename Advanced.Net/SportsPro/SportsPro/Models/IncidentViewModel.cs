using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;


namespace SportsPro.Models
{
    public class IncidentViewModel
    {
        public int IncidentID { get; set; }
        public int CustomerID { get; set; }
        public string ProductCode { get; set; }
        public Nullable<int> TechID { get; set; }
        public System.DateTime DateOpened { get; set; }
        public Nullable<System.DateTime> DateClosed { get; set; }
        public string Title { get; set; }
        public string Description { get; set; }

    }
}