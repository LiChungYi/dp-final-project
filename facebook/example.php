<?php 

if($_GET['object']==NULL)
	$_GET['object'] = 'friends';
$object = $_GET['object'];
if(strcmp($object,"friend")==0)
	$object="friends";




header("Content-Type:text/html; charset=utf-8");

$app_id =  '346899418712471';
$app_secret =  'de58ce8f0e3ca5b288a219b72322ba9f';
$my_url = "http://www.csie.ntu.edu.tw/~b96102/facebook/example.php?object=".$object;
$scope = "read_friendlists,read_stream,user_status";

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
	$token_fp = fopen('token.txt',"w");
	fprintf($token_fp,"%s",$params['access_token']);
	fclose($token_fp);
	chmod ( "token.txt" , 0755);


	$url = "https://graph.facebook.com/me/".$object."?access_token=" . $params['access_token'];	
	$json = file_get_contents($url);
	$decoded_json =  json_decode($json);
	print_r($decoded_json);
	$fp = fopen($object.".json","w");
	fprintf($fp,"%s",$json);
	fclose($fp);
	chmod ( $object.".json" , 0755);

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
