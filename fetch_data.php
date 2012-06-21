<?php 
//$object = $_GET['object'];
//if(strcmp($object,"friend")==0)
//	$object="friends";

$object=$argv[1];
//header("Content-Type:text/html; charset=utf-8");

$app_id =  '346899418712471';
$app_secret =  'de58ce8f0e3ca5b288a219b72322ba9f';
$my_url = "http://www.csie.ntu.edu.tw/~b96102/facebook/example.php?object=".$object;
$scope = "read_friendlists,read_stream,user_status";


$token = trim(file_get_contents("token.txt"));




$url = "https://graph.facebook.com/me/".$object."?access_token=" . $token;	
$json = file_get_contents($url);
$decoded_json =  json_decode($json);
print_r($decoded_json);
$fp = fopen($object.".json","w");
fprintf($fp,"%s",$json);
fclose($fp);
chmod ( $object.".json" , 0755);



?>
