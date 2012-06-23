<?php 
//$object = $_GET['object'];
//if(strcmp($object,"friend")==0)
//	$object="friends";

$object=$argv[1];
$outputFile=$argv[2];

$token = trim(file_get_contents("token.txt"));


$url = "https://graph.facebook.com/me/".$object."?access_token=" . $token;	
$json = file_get_contents($url);
$decoded_json =  json_decode($json);
//print_r($decoded_json);
$fp = fopen($outputFile,"w");
fprintf($fp,"%s",$json);
fclose($fp);
//chmod ( $object.".json" , 0755);



?>
