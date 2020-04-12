<?php
require 'includes/common.php';
$con = mysqli_connect("localhost","root","","store")or die(mysqli_error($con));
$password=$_POST['op'];
$email = $_SESSION['email'];
if(!$_SESSION['email'])
{
	header("Location: index.php");
}
$query = "select passwd from users where email='$email';";
$res = mysqli_query($con,$query)  or die("failed ".mysqli_error($con));
$array = mysqli_fetch_array($res);
if($password == $array['passwd'])
{
	$np = $_POST['np'];
	echo $np;
	$q = "update passwd from users set passwd='$np' where email='$email';";
$res = mysqli_query($con,$q)  or die("failed ".mysqli_error($con));
}
else
{
	header("Location: setting.php");
	echo "<br><br><br><br><h1>Old Password incorrect !</h1>";
}
?>