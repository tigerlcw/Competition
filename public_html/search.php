<?php
$search_hobby = $_GET["hobby"];
$search_addr = $_GET["addr"];
$search_score = intval($_GET["score"]) ;

$dblink = mysqli_connect("127.0.0.1","root","autoset","highjinrodb") or die("Error " . mysqli_error($dblink)); 
$sql = "SELECT `idx`,`SchoolName`,`Score_MAX`,`Addr`,`hobby`,(`Score_MAX` - ".$search_score.") AS score_diff FROM `highjinrodb`
 WHERE `hobby` LIKE '%".$search_hobby."%' HAVING score_diff >= 0 ORDER BY score_diff ASC limit 0,3";
$dbresult = @mysqli_query($dblink, $sql);
echo "<center>"; 

?><!DOCTYPE html>
<html>

<head>
 
<meta name="viewport" content="width=device-width, initial-scale=1, minimum-scale=1,
 maximum-scale=1, user-scalable=yes, target-densitydpi=medium-dpi" />

</head>
<body background="q2.png">
<h3><li>결과의 순서</li></h3>
<h4><font color="#FFFF00"> [순번]　[학교이름]　[내신]　[학교주소]　[관심분야]</h4>


<table>
<?php


if($dbresult===false){
echo "찾을수 없습니다.<br />";
}else{

while($result = mysqli_fetch_row($dbresult))
{
?><tr>
<td><?php echo $result[0]; ?></td><td><?php echo $result[1]; ?></td><td><?php echo $result[2]; ?></td><td><?php echo $result[3]; ?></td><td><?php echo $result[4]; ?></td>
</tr>
<?php
}
}
mysqli_close($dblink);
?>
</body>
</html>