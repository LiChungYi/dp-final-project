<?php 

$inputFile=$argv[1];
$outputFile=$argv[2];

$url=file_get_contents($inputFile);

file_put_contents('php://stderr', 'getting url\n');
$json = file_get_contents($url);
file_put_contents('php://stderr', 'finished getting url\n');
$fp = fopen($outputFile,"w");
fprintf($fp,"%s",$json);
fclose($fp);
?>
