<?php
$con = mysqli_connect("i37t42387837831.db.42387837.cec.hostedresource.net","i37t42387837831","U3MW{@3e8","members")or die(mysqli_error($con));
$email=$_POST['email'];
if($con)
{
	
	echo "connected";
}
else {
	
	echo "fucked up";
}
$password=$_POST['password'];
$query = "select * from users where emailid='$email' and passwd='$password'";
$res = mysqli_query($con,$query)  or die("failed ".mysqli_error($con));
$array = mysqli_fetch_array($res);
if( $password == $array['passwd'] && $email == $array['email'])
{
	session_start();
	$_SESSION['email'] = $email;
	$_SESSION['id'] = $array['id'];
	echo "coool..!";
	
}
else
{
	echo "<h2>No user Found</h2>";
}
?>
