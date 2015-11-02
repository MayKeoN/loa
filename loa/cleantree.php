<?php
	$handle = fopen($argv[1], "r");
	$sort = array();
	while ($line = fgets($handle))
	{
		// $num = split("\: ", $line);
		array_push($sort, $line);
	}
	sort($sort, 2);
	foreach ($sort as $branch)
		print($branch);
		// print(implode(' ', $branch));
?>