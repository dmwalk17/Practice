<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8">
    <title>Assignment 4</title>
	<!--Name: Donna Walker
		Class: Web 2603 - WW1
		Assignment: Project04 - 3
		Description: Create a form. -->
	<style>
	 body{
         color: white;

         background-image: url("images/grey_texture.jpg");
		 width: 400px;
		 height: 400px;
     }


	 p{
		 padding-left: 4em;
		 text-align: left;
		 line-height: 1.4em;
         font-size: 24pt;
         white-space: nowrap;
	 }
	 .short{
		 margin-left: 3em;
		 height: 1.4em;
	 }
	 .long{
		 margin-left: 7em;
		 height: 1.4em;
	 }
	 .button{
		 font-size: 18px;
		 font-weight: bold;
		 padding: 8px 20px 8px 20px;
		 border: 2px solid;
		 border-radius: 25px;
	 }
     select{
         width: 160px;
         bottom-padding: 4em;
     }
	 .button:hover {
    background-color: black;
    color: white;
}
	</style>
  </head>
  <body>

	<form action="confirm.php" method="post">
	  <div>
	  <h1>User Registration Form</h1><br/>
          <p>
		  <label for="name">Name:  </label>
	      <input id="name" type="text" name="name" class="long" /><br/><br/>
		  <label for="userName">Username:  </label>
          <input id="name" type="text" name="userName" class="short"  /><br/><br/>
		  <label for="email">Email:  </label>
	      <input id="name" type="text" name="email" class="long"/><br/><br/>


	  <?php
      require_once("class/select.inc");
      $browsers = array("Firefox", "Chrome", "Internet Explorer", "Safari", "Opera",
      "Konqurer", "Other");
        $browserPreference = new select($browsers);
	    echo "<br/><br/>";
	  ?>
      <input type="submit" name="submit" value="Submit" class="button"></p>
	  </div>
	</form>
  </body>
</html>  