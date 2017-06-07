//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated from a template.
//
//     Manual changes to this file may cause unexpected behavior in your application.
//     Manual changes to this file will be overwritten if the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace SportsPro.Models
{
    using System;
    using System.Collections.Generic;
    
    public partial class Incident
    {
        public int IncidentID { get; set; }
        public int CustomerID { get; set; }
        public string ProductCode { get; set; }
        public Nullable<int> TechID { get; set; }
        public System.DateTime DateOpened { get; set; }
        public Nullable<System.DateTime> DateClosed { get; set; }
        public string Title { get; set; }
        public string Description { get; set; }
    
        public virtual Product Product { get; set; }
        public virtual Technician Technician { get; set; }

        public static string CustomerIncidentDisplay(IncidentViewModel IncidentVM)
        {

            return "Incident for product " + IncidentVM.ProductName + " closed " + IncidentVM.DateClosed + " (" + IncidentVM.Description + ")";
        }
    }
}
