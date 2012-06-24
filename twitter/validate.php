<?php
if($_GET["pin"]==NULL){
echo '<hr/>';
echo '
	<form name="input" action="./validate.php" method="get">
	 please submit your pin number: <input type="text" name="pin" />
	 <input type="submit" value="Submit" />
	 </form> 
';


}
else{
	$requestToken = file_get_contents("request_token");
	$requestTokenSecret = file_get_contents("request_token_secret");

	require_once("twitteroauth/twitteroauth.php");
	$oauth = new TwitterOAuth('consumer_key', 'consumer_secret', $requestToken, $requestTokenSecret);

	// Generate access token by providing PIN for Twitter
	$request = $oauth->getAccessToken(NULL, $_GET["pin"]);
	$accessToken = $request['oauth_token'];
	$accessTokenSecret = $request['oauth_token_secret'];
	// Save our access token/secret
	file_put_contents("access_token", $accessToken);
	file_put_contents("access_token_secret", $accessTokenSecret);
	header("Location: ../interface.php?socialNetwork=TW");

}
?>
