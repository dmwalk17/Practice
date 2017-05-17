using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data.SqlClient;
using System.Linq;
using System.Web;

namespace SportsPro.Models
{
    public class BusinessLayerCustomer
    {
        public IEnumerable<Customer> Customers
        {
            get;         
                
        }
        public List<Incident> Incidents { get; set; }

        public void AddCustomer(Customer customer)
        {
            string connectionString = ConfigurationManager.ConnectionStrings["dw_TechSupportDBContext"].ConnectionString;
            
            using (SqlConnection con = new SqlConnection(connectionString))
            {
                SqlCommand cmd = new SqlCommand("spAddCustomer", con)
                {
                    CommandType = System.Data.CommandType.StoredProcedure
                };
                SqlParameter paramName = new SqlParameter()
                {
                    ParameterName = "@Name",
                    Value = customer.Name
                };
                cmd.Parameters.Add(paramName);

                SqlParameter paramAddress = new SqlParameter()
                {
                    ParameterName = "@Address",
                    Value = customer.Address
                };
                cmd.Parameters.Add(paramAddress);

                SqlParameter paramCity = new SqlParameter()
                {
                    ParameterName = "@City",
                    Value = customer.City
                };
                cmd.Parameters.Add(paramCity);

                SqlParameter paramState = new SqlParameter()
                {
                    ParameterName = "@State",
                    Value = customer.State
                };
                cmd.Parameters.Add(paramState);

                SqlParameter paramZipCode = new SqlParameter()
                {
                    ParameterName = "@ZipCode",
                    Value = customer.ZipCode
                };
                cmd.Parameters.Add(paramZipCode);

                SqlParameter paramEmail = new SqlParameter()
                {
                    ParameterName = "@Email",
                    Value = customer.Email
                };
                cmd.Parameters.Add(paramEmail);

                con.Open();
                cmd.ExecuteNonQuery();
            }
        }
    }
}