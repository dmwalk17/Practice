<?Php
//  Donna Walker
//  Web 2603 WW1
//  Description: Provides current date in four different formats. 
//  Required formats are in the echo statements.
$shortToday = date("m/d/y");
echo 'Current Date in "MM/DD/YY" format: ' . $shortToday . "<br/>";
$dayAndWrittenOutToday = date("l, F d, Y");
echo 'Current Date in "Monday, December 25, 2016" format: '  . $dayAndWrittenOutToday . "<br/>";
$dateMonthYear = date("d F Y");
echo 'Current Date in "25 November 2016" format: '  . $dateMonthYear . "<br/>";
$dateISO = date("c");
echo 'Current Date in "ISO 8601" format: '  . $dateISO . "<br/>";

?>