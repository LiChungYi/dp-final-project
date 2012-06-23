<?php
	require_once('twitteroauth/twitteroauth.php');
	$oauth = new TwitterOAuth('1UvPUPqi6h90qARceGDvA','NNvj1cIRLdI1CGccFH5qjOayFT1GUA4UX2bf8cQVD4');
	$request = $oauth->getRequestToken();
	$requestToken = $request['oauth_token'];
	$requestTokenSecret = $request['oauth_token_secret'];

	file_put_contents('request_token', $requestToken);
	file_put_contents('request_token_secret', $requestTokenSecret);

	$registerURL = $oauth->getAuthorizeURL($request);
	echo '<a href="' . $registerURL . '">Register with Twitter</a>';
 
?>
