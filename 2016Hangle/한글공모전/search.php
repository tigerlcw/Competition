<?php
$search_change = $_GET["change"];
$dblink = mysqli_connect("127.0.0.1","root","autoset","linkerdb") or die("Error " . mysqli_error($dblink)); 
$sql = "SELECT * FROM `linkerdb`  WHERE `change` LIKE '%".$search_change."%'";
$dbresult = @mysqli_query($dblink, $sql);
echo "<center>";
?><!DOCTYPE html>
<html>

<head>
 
<meta name="viewport" content="width=device-width, initial-scale=1, minimum-scale=1,
 maximum-scale=1, user-scalable=yes, target-densitydpi=medium-dpi" />

</head>
<body background="q1.png">
<h3><li>결과의 순서</li></h3>
<h4><font color="#FFFFFF">[No.] [변경 전] [변경 후]</h4>
<?php
if($dbresult===false){
echo "찾을 수 없습니다.<br />";
}else{

while($result = mysqli_fetch_array($dbresult))
{
?><table border=2px bgcolor="#e4e38b"><tr align="center" height="40">
<td align="center"><?php echo $result[0]; ?><td width="300" align="center"><?php echo $result[1]; ?><td width="300" align="center"><?php echo $result[2]; ?></td>
</tr>
</table>
<?php
}
}
mysqli_close($dblink);
?>
</body>
</html>