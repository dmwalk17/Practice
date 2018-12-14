using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Web;

namespace SportsPro.Models
{
    public class CustomerList
    {

        private List<Customer> customerList;


        public static CustomerList MyCustomerList
        {
            get;


            set;
        }

        //Gets/sets the customer at the specified index;
        public Customer this[int index]
        {
            get
            {
                return this.customerList[index];
            }
            set
            {
                this.customerList[index] = value;
            }
        }

        //Gets the customer with the specified name
        public Customer this[string name]
        {
            get
            {
                foreach (Customer cus in customerList)
                {
                    if (cus.Name == name)
                    {
                        return cus;
                    }
                }
                return null;
            }
        }

        //Returns a count of the number of customers in the list.
        public int Count
        {
            get
            {
                return customerList.Count();
            }

        }
        //Creates a new List<Customer> object and stores it in the private field
        public CustomerList()
        {
            if (customerList.Count < 1)
            {
                customerList = new List<Customer>();

            }

        }
        /*Gets the list of customers from session state. 
        Creates a new session state item if one does not already exist */
        public static CustomerList GetCustomers()
        {

            if (HttpContext.Current.Session["CustomerList"] != null)
            {

                MyCustomerList = (CustomerList)HttpContext.Current.Session["CustomerList"];
            }
            else if (File.Exists(@"C:\Download\myCustomerList.txt"))
            {
                string filePath = @"C:\Download\myCustomerList.txt";
                List<string> lines = File.ReadAllLines(filePath).ToList();
                foreach (var line in lines)
                {
                    string[] entries = line.Split(',');
                    Customer newCustomer = new Customer()
                    {
                        CustomerID = Convert.ToInt32(entries[0]),
                        Name = entries[1],
                        Phone = entries[2],
                        Email = entries[3]
                    };
                    MyCustomerList.AddItem(newCustomer);
                }
            }
        
            else
                MyCustomerList = null;

            return MyCustomerList;
        }

    //Adds a customer to the list of customers
    public void AddItem(Customer customer)
    {
        customerList.Add(customer);
    }

    //Removes the customer at the specified index from the list of customers
    public void RemoveAt(int index)
    {
        customerList.RemoveAt(index);
    }

    //Clears the list of customers
    public void Clear()
    {
        HttpContext.Current.Session["CustomerList"] = null;
    }

}
}