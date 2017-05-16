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
                SqlCommand cmd = new SqlCommand("spAddCustomer", con);
                cmd.CommandType = System.Data.CommandType.StoredProcedure;

                SqlParameter paramName = new SqlParameter();
                paramName.ParameterName = "@Name";
                paramName.Value = customer.Name;
                cmd.Parameters.Add(paramName);

                SqlParameter paramAddress = new SqlParameter();
                paramAddress.ParameterName = "@Address";
                paramAddress.Value = customer.Address;
                cmd.Parameters.Add(paramAddress);

                SqlParameter paramCity = new SqlParameter();
                paramCity.ParameterName = "@City";
                paramCity.Value = customer.City;
                cmd.Parameters.Add(paramCity);

                SqlParameter paramState = new SqlParameter();
                paramState.ParameterName = "@State";
                paramState.Value = customer.State;
                cmd.Parameters.Add(paramState);

                SqlParameter paramZipCode = new SqlParameter();
                paramZipCode.ParameterName = "@ZipCode";
                paramZipCode.Value = customer.ZipCode;
                cmd.Parameters.Add(paramZipCode);

                SqlParameter paramEmail = new SqlParameter();
                paramEmail.ParameterName = "@Email";
                paramEmail.Value = customer.Email;
                cmd.Parameters.Add(paramEmail);

                con.Open();
                cmd.ExecuteNonQuery();
            }
        }
    }
}