<?
if($_GET['functionId']==NULL)
	$functionId=-1;
else
	$functionId = (int)$_GET['functionId'];
$socialNetwork = $_GET['socialNetwork'];

$accessToken ="";
$accessTokenSecret ="";
if(strcmp($_GET['socialNetwork'],"TW")==0){
	$accessToken =file_get_contents("./twitter/access_token");	
	$accessToeknSecret =file_get_contents("./twitter/access_token_secret");	
}
else{
	$accessToken =file_get_contents("./facebook/access_token");	
}

system('./main_dumpFriendToFile '.$accessToken.' '.$accessTokenSecret);
//echo './main_dumpFriendToFile '.$accessToken.' '.$accessTokenSecret;

$friends = file("friendList.txt");
$friends_select = '<select name="uid">';
for($i=0;$i<count($friends);$i++){
	$friends[$i]=explode(" ",$friends[$i],2);
	$friends_select = $friends_select.'<option value="'.$friends[$i][0].'">'.$friends[$i][1].'</option>';
}
$friends_select = $friends_select.'</select>';

$from_year_select = '<select name ="fromYear">';
$to_year_select = '<select name ="toYear">';
for($i=2012;$i>1900;$i--){
	$from_year_select = $from_year_select.'<option value="'.$i.'">'.$i.'</option>';
	$to_year_select = $to_year_select.'<option value="'.$i.'">'.$i.'</option>';
}
$from_year_select = $from_year_select.'</select>';
$to_year_select = $to_year_select.'</select>';

echo "<hr/>Function Id is".$functionId."<br>";
echo '
</hr>
<ul>
<li>Get Frined List</a></li><hr/>

<li>Search</li>

<form name="input" action="./interface.php" method="get">
<input type="text" name="query" />

<select name="type">
<option value="Post">Post</option>
<option value="User">User</option>
</select>

'.$friends_select.'From:'.$from_year_select.'


<select name="fromMonth">
<option value="01">01</option><option value="02">02</option><option value="03">03</option><option value="04">04</option>
<option value="05">05</option><option value="06">06</option><option value="07">07</option><option value="08">08</option>
<option value="09">09</option><option value="10">10</option><option value="11">11</option><option value="12">12</option>
</select> - To:

'.$to_year_select.'
<select name="toMonth">
<option value="01">01</option><option value="02">02</option><option value="03">03</option><option value="04">04</option>
<option value="05">05</option><option value="06">06</option><option value="07">07</option><option value="08">08</option>
<option value="09">09</option><option value="10">10</option><option value="11">11</option><option value="12">12</option>
</select>

<input type="hidden" name="functionId" value="1" />
<input type="hidden" name="socialNetwork" value="'.$socialNetwork.'" />
<input type="submit" value="Submit" />
</form> 
<hr/>

<li> function 3</li><hr/>

<li> function 4</li><hr/>

</ul>
'
;

if($functionId > 0){
	$token = trim(file_get_contents("token.txt"));
	switch($functionId){
		case 0:
			//system('./main '.$token, $returnval);
			break;
		case 1:
			break;
	}
}

//$last_line = system('ls', $retval);



?>
