<?
if($_GET['functionId']==NULL)
	$functionId=-1;
else
	$functionId = (int)$_GET['functionId'];

echo '<hr/><a href="./interface.php?functionId=0">Get Frined List</a>';
echo '<hr/><a href="./interface.php?functionId=1">Get XXX</a>';
echo "<hr/>Function Id is".$functionId."<br>";

if($functionId > 0){
	$token = trim(file_get_contents("token.txt"));
	switch($functionId){
		case 0:
			system('./main '.$token, $returnval)
			break;
		case 1:
			break;
	}
}

//$last_line = system('ls', $retval);



?>
