using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace SportsPro.Models
{
    public class CustomerList
    {
        
        private List<Customer> customerList;

        public static CustomerList myCustomerList
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
 
            if (System.Web.HttpContext.Current.Session["CustomerList"] != null)
            {

               myCustomerList = (CustomerList)HttpContext.Current.Session["CustomerList"];
            }
            else
            {
               //HttpContext.Session["CustomerList"] = new 
               
            }

            return null;
        }

        //Adds a customer to the list of customers
        public void AddItem(Customer customer)
        {

        }

        //Removes the customer at the specified index from the list of customers
        public void RemoveAt(int index)
        {

        }

        //Clears the list of customers
        public void Clear()
        {
            //HttpContext.Session["ContactList"] = null;
        }

    }
}