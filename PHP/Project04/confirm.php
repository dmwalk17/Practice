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
            text-align: center;


        }


        p{
            padding-left: 4em;
            padding: 240px;
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

    </style>
</head>
<body>
  <?php
    echo "<p>";
    if (!empty($_POST["name"])) {
      echo "Your name is: " . $_POST["name"] . "<br/>";
    } else {echo "You did not provide a name.<br/>";}

    if (!empty($_POST["userName"])) {
      echo "Your user name is: " . $_POST["userName"] . "<br/>";
    } else {echo "No user name was provided.<br/>";}

    if (!empty($_POST["email"])) {
        echo "Your email is: " . $_POST["email"] . "<br/>";
    } else {echo "You did not provide an email. <br/>";}

    if (!empty($_POST["browserPreference"])) {
      echo "Your selected browser is: " . $_POST["browserPreference"] . "<br/>";
    } else { echo "No browser preference."; }
    echo "</p>"
?>
</body>
</html>