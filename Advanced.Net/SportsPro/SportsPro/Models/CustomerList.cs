using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace SportsPro.Models
{
    public class CustomerList
    {
        private List<Customer> contactList;

        public Customer this[int index] {
            get
            {
                return this.contactList[index];
            }
            set
            {
                this.contactList[index] = value;
            }
        }
            
        //public Customer this[string name] { }
          

        public int Count
        {
            get
            {
                return contactList.Count();
            }

        }

        public CustomerList()
        {
            CustomerList newList = new CustomerList();

        }

    }
}