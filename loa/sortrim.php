<?php
	$handle = fopen("6542.txt", "r");
	$sort = array();
	while ($line = fgets($handle))
	{
		$num = split(",", $line)[0];
		array_push($sort, $num.",\n");
	}
	foreach ($sort as $s)
		print_r($s);
?>