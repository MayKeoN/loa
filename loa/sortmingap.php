<?php
	$handle = fopen("sormindump.txt", "r");
	$sort = array();
	while ($line = fgets($handle))
	{
		$gap = split("GAP:", $line)[1];
		$num = split("FINAL", $line)[0];
		array_push($sort, $gap."\t".$num."\n");
	}
	sort($sort, 2);
	// for ($i = 1; $i < count($sort); $i++)
	// {
	// 	$min = 
	// 	print($res."\n");
	// }
	foreach ($sort as $gap)
		if (abs($gap) < 10000)
			print($gap);
?>