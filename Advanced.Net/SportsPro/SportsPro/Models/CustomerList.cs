using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace SportsPro.Models
{
    public class CustomerList
    {
        private List<Customer> contactList;

        //Gets/sets the customer at the specified index;
        public Customer this[int index]
        {
            get
            {
                return this.contactList[index];
            }
            set
            {
                this.contactList[index] = value;
            }
        }

        //Gets the customer with the specified name
        public Customer this[string name]
        {
            get
            {
                foreach (Customer cus in contactList)
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
                return contactList.Count();
            }

        }
        //Creates a new List<Customer> object and stores it in the private field
        public CustomerList()
        {
            if (contactList.Count < 1)
            {
                contactList = new List<Customer>();

            }

        }
        /*Gets the list of customers from session state. 
        Creates a new session state item if one does not already exist */
        public static CustomerList GetCustomers()
        {
           

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

        }

    }
}