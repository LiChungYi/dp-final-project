<?
if($_GET['functionId']==NULL)
	$functionId=-1;
else
	$functionId = (int)$_GET['functionId'];
$socialNetwork = $_GET['socialNetwork'];

echo "<hr/>Function Id is".$functionId."<br>";
echo '
</hr>
<ul>
<li>Get Frined List</a></li><hr/>

<li>Search</li>

<form name="input" action="./interface.php" method="get">
<input type="text" name="query" />

<select name="type">
<option value="User">User</option>
<option value="Post">Post</option>
</select>

<select name="month">
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
