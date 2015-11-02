<?
	$handle = fopen("masklist.txt", "r");
	$sort = array();
	while ($line = fgets($handle))
	{
		$num = split(":",$line)[0];
		array_push($sort, $num."\n");
	}
	sort($sort, 2);
	for ($i = 1; $i < count($sort); $i++)
	{
		$res = ($sort[$i] - $sort[$i - 1]);
		$diff = ($sort[$i] - 1500000000);		
		$fin = $res.":".$sort[$i].":".$diff;
		print($res."\n");
	}
	// print_r(implode("", $sort));

?>