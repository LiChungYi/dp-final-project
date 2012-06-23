<?php
$accessToken = $argv[1];
$accessTokenSecret = $argv[2];
$object=$argv[3];
$person=$argv[4];
$outputFile=$argv[5];


$accessToken = file_get_contents("./twitter/access_token");
$accessTokenSecret = file_get_contents("./twitter/access_token_secret");
// Create our twitter API object
require_once("./twitter/twitteroauth/twitteroauth.php");
$oauth = new TwitterOAuth('1UvPUPqi6h90qARceGDvA','NNvj1cIRLdI1CGccFH5qjOayFT1GUA4UX2bf8cQVD4', $accessToken, $accessTokenSecret);
$oauth->format = 'json';
if((int)$person<0)
	$decodeJson = $oauth->get($object);
else{
	$para = array();
	$para['user_id'] = $person;
	$para['count'] = 200;
	$decodeJson = $oauth->get($object,$para);
}
file_put_contents($argv[5], json_encode($decodeJson));
?>

