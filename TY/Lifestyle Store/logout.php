<?php
require 'includes/common.php';
$con = mysqli_connect("localhost","root","","store")or die(mysqli_error($con));
if(!$_SESSION['email'])
{
header("Location: index.html");
}
session_destroy();
header("Location: index.html");
?>