<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8">
    <title>Assignment 4a</title>
	<!--Name: Donna Walker
		Class: Web 2603 - WW1
		Assignment: Project04 - 4A
		Description: Create an array of specified browsers as part of an 
		  Object Oriented Program exercise. -->
	<style>
	 body{
		 font-size: 24px;
         font-family: Sans-serif, Arial;
         font-weight: bold;
         color: white;
	     background-color: #848482;
	     text-align: center;
	 }	
     
	 div{
		 height: 400px;
	 }
	</style>
  </head>
  <body>
	<div></div>
    <?php
      //Create function with name greeting to echo Hello, World!
  $browsers = array('0->Firefox', 'Chrome', 'Internet Explorer', 'Safari', 'Opera',
                     'Konqurer', 'Other');
    

    foreach ($browsers as $browser) {
        echo $browser . ; // displays objects in array
    } 

    ?>
	
    </body>
  <html>	

