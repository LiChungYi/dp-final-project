<?php
// Read in our saved access token/secret
$accessToken = file_get_contents("access_token");
$accessTokenSecret = file_get_contents("access_token_secret");
// Create our twitter API object
require_once("twitteroauth/twitteroauth.php");
$oauth = new TwitterOAuth('1UvPUPqi6h90qARceGDvA','NNvj1cIRLdI1CGccFH5qjOayFT1GUA4UX2bf8cQVD4', $accessToken, $accessTokenSecret);
// Send an API request to verify credentials
$credentials = $oauth->get("account/verify_credentials");
//print_r($credentials);
echo "Connected as @" . $credentials->screen_name;
// Post our new "hello world" status
$oauth->post('statuses/update', array('status' => "test post"));
$friend = $oauth->get('friends/ids');
print_r($friend);
?>

