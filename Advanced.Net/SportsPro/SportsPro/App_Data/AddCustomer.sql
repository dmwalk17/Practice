Create procedure spAddCustomer
  @Name varchar(50),
  @Address varchar(50),
  @City varchar(20),
  @State char(2),
  @ZipCode varchar(9),
  @Phone varchar(20),
  @Email varchar(50)
  as
  Begin
    Insert into Customer (Name, Address, City, State, ZipCode, Email)
	Values (@Name, @Address, @City, @State, @ZipCode, @Email)
  End