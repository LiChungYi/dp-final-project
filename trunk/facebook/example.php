<?php 

if($_GET['object']==NULL)
	$_GET['object'] = 'friends';
$object = $_GET['object'];
if(strcmp($object,"friend")==0)
	$object="friends";




//header("Content-Type:text/html; charset=utf-8");

//$app_id = '237933852991313';
//$app_secret = 
$app_id =  '346899418712471';
$app_secret =  'de58ce8f0e3ca5b288a219b72322ba9f';
$my_url = "http://mslab.csie.ntu.edu.tw/~chungyi/DP/dp-final-project/facebook/example.php?object=".$object;
$scope = "read_friendlists,read_stream,user_status,friends_status,publish_stream,user_birthday,friends_birthday,friends_education_history,user_education_history,friends_location,user_location,friends_relationships,user_relationships,user_online_presence,friends_online_presence";

session_start();
$code = $_REQUEST["code"];


if(empty($code)) {
	$_SESSION['state'] = md5(uniqid(rand(), TRUE)); //CSRF protection
	$dialog_url = "https://www.facebook.com/dialog/oauth?client_id=" 
		. $app_id . "&redirect_uri=" . urlencode($my_url) . "&state="
		. $_SESSION['state'] . "&scope=" .$scope
		;
	
	echo("<script> top.location.href='" . $dialog_url . "'</script>");
}



if($_SESSION['state'] && ($_SESSION['state'] === $_REQUEST['state'])) {
	$token_url = "https://graph.facebook.com/oauth/access_token?"
		. "client_id=" . $app_id . "&redirect_uri=" . urlencode($my_url)
		. "&client_secret=" . $app_secret . "&code=" . $code;

	$response = file_get_contents($token_url);
	$params = null;
	parse_str($response, $params);
	
	echo $params['access_token']."<br><br>";
	file_put_contents("access_token",$params['access_token']);
	
	header("Location: ../interface.php?socialNetwork=FB&dummy=xx");

/*
	$url = "https://graph.facebook.com/me/".$object."?access_token=" . $params['access_token'];	
	$json = file_get_contents($url);
	$decoded_json =  json_decode($json);
	print_r($decoded_json);
	$fp = fopen($object.".json","w");
	fprintf($fp,"%s",$json);
	fclose($fp);
	chmod ( $object.".json" , 0755);
*/
/*	$graph_url = "https://graph.facebook.com/me?access_token=" 
		. $params['access_token'];
	$user = json_decode(file_get_contents($graph_url));
	echo("Hello " . $user->name."<br>");
	print_r($user);


	$friends_url = "https://graph.facebook.com/me/friends?access_token=" 
		. $params['access_token'];
	$friends =  json_decode(file_get_contents($friends_url));
	print_r($friends);


	$status_url = "https://graph.facebook.com/596297874/feed?access_token=" 
		. $params['access_token'];
	$status =  json_decode(file_get_contents($status_url));
	print_r($status);
*/
	
}
else {
	echo("The state does not match. You may be a victim of CSRF.");
}

?>
