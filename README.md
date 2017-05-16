# Practice
School/Side Projects

I've included some of my school projects, but I am currently working on
converting an ASP.Net assignment into an MVC implementation.

I will include the original project description in the project. I will be doing
part of this project for a grade this month, so general guidance would be
appreciated, but place don't include exact how-to help. Figuring out is
where the fun is after all.

Thanks for visiting!

5/7/2017

Now to start, I am trying to figure out how to simulate a ListView in MVC. This
ListView is supposed to add Customer information on button click. This "ListView"
should also be able to delete contact names and clear the contact list (both on
button click).

Only administrators should be able to have a contact list. (Not customers or
  technicians). Administrators should be logged in to access their contact
  information. Contacts are added through the Customer/Index controller.

I am hoping to do this using a model, a partial view with a border, and buttons
linked to Crud operations.

5/9/2017
Made progress on creating the code for CustomerList to store Contacts, but will need to use session state. Need to research using session state with MVC. Also need to figure out how to properly implement navbar-invert with a footer in current bootstrap. Currently goes black, but color stays black. Also still working on properly implementing a partial view. Space depicts it exists, but the partial view is not rendering (text, outline).

5/16/2017
While I am still stalled out a bit trying to figure out how to make the "coding hints" of the assignment work in MVC, specifically how to declare a static CustomerList into session state if it doesn't already exist. I know. I've listened to videos saying over and over not to use session state, but it is part of the assignment. Not debatable....

I have side stepped and started completing the Customer Survey page and only need a few more lines of code to complete the view for this (my second of three page requirements, one for each login type).

I have three types of logon roles~ Customer, Administrator, and Technicians. Now, if you are not logged in, the main menu will only allow you to access the Index and Contact Us page. If you are logged in as a Administrator, you can view the Administrator menu, same for technician and customer. I did this with an @if conditional in the _Layout masterpage. The login and roles assignment pages do work, but the Roles controller is not currently attached to anything and is only accessible through the use of Friendly URLs in the browser. The delete roles function is having issues with type and is breaking when used. Add roles and display roles works perfectly. I have completed my three roles, so I don't really need this anymore for the purposes of this assignment, but will probably revisit it after the 31st.

I have also started my final page. This one is for the Technician. It is called the Customer Incident Display page. I was able to reuse my code from the Customer Display page to create the dropdown list. I am currently trying to figure out the best way to join three tables to simulate a "DataList" control that gets pulled based on the selection of the dropdownlist control. I will be joining the Incidents, Technicians and Products table to get the data I need to complete the display for the DataList.

Oh, the navbar and buttons finally resolved themselves once the debugger references cleared. They are displaying fine with no additional work on my part.

Time to get back to work.....
