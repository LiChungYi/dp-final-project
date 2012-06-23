<?php 
//$object = $_GET['object'];
//if(strcmp($object,"friend")==0)
//	$object="friends";

$access_token=$argv[1];
$object=$argv[2];
if(strcmp($object, "profile") == 0)
	$object = "";
$person=$argv[3];
$outputFile=$argv[4];
//header("Content-Type:text/html; charset=utf-8");


//$token = trim(file_get_contents("token.txt"));


$url = "https://graph.facebook.com/". $person ."/".$object."?access_token=" . $access_token . "&limit=10000";
$json = file_get_contents($url);
//$decoded_json =  json_decode($json);
//print_r($decoded_json);
$fp = fopen($outputFile,"w");
fprintf($fp,"%s",$json);
fclose($fp);
//chmod ( $object.".json" , 0755);



?>
