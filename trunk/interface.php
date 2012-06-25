<?
header("Content-Type:text/html; charset=utf-8");
//echo '<body bgcolor=#B03060>'; 
echo '<body bgcolor=#000000>'; 
//echo '<img src="https://graph.facebook.com/starrywinter/picture"/>';
echo "<font size='10' color='#00EE00' >Design Pattern Social Search</font>";


if($_GET['functionId']==NULL)
	$functionId=-1;
else
	$functionId = (int)$_GET['functionId'];
$socialNetwork = $_GET['socialNetwork'];

//------get access token
$accessToken ="";
$accessTokenSecret ="";
if(strcmp($socialNetwork,"TW")==0){
	$accessToken =trim(file_get_contents("./twitter/access_token"));	
	$accessTokenSecret =trim(file_get_contents("./twitter/access_token_secret"));
}else{
	$accessToken =trim(file_get_contents("./facebook/access_token"));	
}

//------get friend list
if(file_exists($socialNetwork.$accessToken.'_friend')==false){
	system('./main_dumpFriendToFile '. $socialNetwork.$accessToken.'_friend '.$socialNetwork.' '.$accessToken.' '.$accessTokenSecret);
}
$friends = file($socialNetwork.$accessToken.'_friend');
$friends_select = '<select name="uid">';
for($i=0;$i<count($friends);$i++){
	$friends[$i]=explode("\t",$friends[$i],2);
	$friends_select = $friends_select.'<option value="'.$friends[$i][0].'">'.$friends[$i][1].'</option>';
}
$friends_select = $friends_select.'</select>';

//-----time 
$from_year_select = '<select name ="fromYear"><option value="0000">null</option>';
$to_year_select = '<select name ="toYear"><option value="9999">null</option>';
for($i=2012;$i>1900;$i--){
	$from_year_select = $from_year_select.'<option value="'.$i.'">'.$i.'</option>';
	$to_year_select = $to_year_select.'<option value="'.$i.'">'.$i.'</option>';
}
$from_year_select = $from_year_select.'</select>';
$to_year_select = $to_year_select.'</select>';

//echo "<hr/><font color='#fffff'>Tools</font>";
echo '
</hr>
<ul>

<li><font color="#FFFFFF">Post Search</font></li>

	<form name="input" action="./interface.php" method="get">
	<input type="text" name="query" value="生日"/>

	'.$friends_select.'From:'.$from_year_select.'


	<select name="fromMonth">
	<option value="00">null</option>
	<option value="01">01</option><option value="02">02</option><option value="03">03</option><option value="04">04</option>
	<option value="05">05</option><option value="06">06</option><option value="07">07</option><option value="08">08</option>
	<option value="09">09</option><option value="10">10</option><option value="11">11</option><option value="12">12</option>
	</select> - To:

	'.$to_year_select.'
	<select name="toMonth">
	<option value="99">null</option>
	<option value="01">01</option><option value="02">02</option><option value="03">03</option><option value="04">04</option>
	<option value="05">05</option><option value="06">06</option><option value="07">07</option><option value="08">08</option>
	<option value="09">09</option><option value="10">10</option><option value="11">11</option><option value="12">12</option>
	</select>

	<input type="hidden" name="functionId" value="1" />
	<input type="hidden" name="socialNetwork" value="'.$socialNetwork.'" />
	<input type="hidden" name="type" value="Post" />
	<input type="submit" value="Submit" />
	</form> 

<hr/>
<li><font color="#FFFFFF">Find Your Guy/Girl</font></li>
	<form name="input" action="./interface.php" method="get">
	
	<select name="Status">
	<option value="In a relationship">In a relationship</option>
	<option value="It\'s complicated">It\'s complicated</option>
	<option value="Single">Single</option>
	<option value="Married">Married</option>
	</select> 
	<select name="Gender">
	<option value="male">male</option>
	<option value="female">female</option>
	</select> 
	
	<input type="hidden" name="functionId" value="2" />
	<input type="hidden" name="socialNetwork" value="'.$socialNetwork.'" />
	<input type="hidden" name="type" value="User" />
	<input type="submit" value="Submit" />
	</form> 
<hr/>


</ul>
'
;

if($functionId > 0){
	$token = trim(file_get_contents("token.txt"));
	switch($functionId){
		case 1:
			//system('./main '.$token, $returnval);
			
			$type = $_GET['type'];
			$query = trim($_GET['query']);

			$uid = $_GET['uid']; //type ==POST
			$from_time = $_GET['fromYear']."-".$_GET['fromMonth']."-00";
			$to_time = $_GET['toYear']."-".$_GET['toMonth']."-99";
			//$socialNetwork;
			//$accessToken ;
			//$accessTokenSecret ;
			$input_file_name = $type.$query.$uid.$from_time.$to_time.$socialNetwork.$accessToken.$accessTokenSecret;
			$output_file_name = $input_file_name."_output.html";
			$input_file_name = str_replace(" ","_",$input_file_name);
			$output_file_name = str_replace(" ","_",$output_file_name);

			$query_cmd = "PostTimeFilter\t".$from_time."\t".$to_time."\n";
			$and_query = explode("AND",$query);
			for($i=0;$i<count($and_query);$i++){
				if(strlen(trim($and_query[$i]))==0)
					continue;
				$query_cmd = $query_cmd."and\n";
				$or_query = explode("OR",$and_query[$i]);	
				$or_first = 0;
				for($j=0;$j<count($or_query);$j++){
					if(strlen(trim($or_query[$j]))==0)
						continue;
					if($or_first==0){
						$or_first++;
						$query_cmd = $query_cmd."PostContentFilter\t".trim($or_query[$j])."\n";
					}
					else{
						$query_cmd = $query_cmd."or\nPostContentFilter\t".trim($or_query[$j])."\n"."and\nPostTimeFilter\t".$from_time."\t".$to_time."\n";
					}
				}
			}
			echo $query_cmd;
			if(file_exists($output_file_name)==false ){//!!!!!!!!!!

				if(strcmp($socialNetwork,"TW")==0){
					$cmd =  $output_file_name."\n".
						$socialNetwork."\t".$accessToken."\t".$accessTokenSecret."\n".
						$type."\t".$uid."\n".
						$query_cmd;
				}else{	
					$cmd =  $output_file_name."\n".
						$socialNetwork."\t".$accessToken."\n".
						$type."\t".$uid."\n".
						$query_cmd;
				}
				file_put_contents($input_file_name,$cmd);
				system('./main_searchEngine '.$input_file_name);
			}
			break;
		case 2:
			$status = $_GET['Status'];
			$Gender = $_GET['Gender'];
			$input_file_name = $type.$status.$Gender.$socialNetwork.$accessToken.$accessTokenSecret;
			$output_file_name = $input_file_name."_output.html";
			$input_file_name = str_replace(" ","_",$input_file_name);
			$output_file_name = str_replace(" ","_",$output_file_name);
			if(file_exists($output_file_name)==false ){//!!!!!!!!!!

				if(strcmp($socialNetwork,"TW")==0){
					$cmd =  $output_file_name."\n".
						$socialNetwork."\t".$accessToken."\t".$accessTokenSecret."\n".
						$type."\n".
						"UserStatusRelationshiopFilter\t".$status."\n".
						"and"."\n".
						"UserGenderFilter\t".$Gender."\n";
				}else{	
					$cmd =  $output_file_name."\n".
						$socialNetwork."\t".$accessToken."\n".
						$type."\n".
						"UserRelationshipStatusFilter\t".$status."\n".
						"and"."\n".
						"UserGenderFilter\t".$Gender."\n";
				}
				file_put_contents($input_file_name,$cmd);
				system('./main_searchEngine '.$input_file_name);
			}

			break;
	}
	echo "<script>window.open('".$output_file_name."','','width=750,height=450');</script>";
}

echo '</body>'; 



?>
