<?php
	function	get_token()
	{
		$url = 'https://api.intra.42.fr/oauth/token';
		$client_id = 'a035b02359706ff7d8c792f3f94131bab5e2dbae58c69d3fc49758b1361dcdcf';
		$secret = '3fe4b027b6c3e6bcc787294110751d7e0f455ed38a13ef9a7364b4f802f19213';
		$fields = [
			'grant_type'		=>	'client_credentials',
			'client_id' 		=>	$client_id,
   		 	'client_secret'		=>	$secret
		];
		$fields_string = http_build_query($fields);
		$ch = curl_init();
		curl_setopt($ch,CURLOPT_URL, $url);
		curl_setopt($ch,CURLOPT_POST, count($fields));
		curl_setopt($ch,CURLOPT_POSTFIELDS, $fields_string);
		curl_setopt($ch,CURLOPT_RETURNTRANSFER, true); 
		$result = json_decode(curl_exec($ch));
		return ($result->access_token);
	}

	function	get_data($token, $user)
	{
		$url = 'https://api.intra.42.fr/v2/users/'.$user.'/locations?access_token='.$token;
		echo($url);
		$curl = curl_init();
		curl_setopt_array($curl, [
			CURLOPT_RETURNTRANSFER => 1,
			CURLOPT_URL => $url,
			CURLOPT_USERAGENT => 'Data request'
		]);
		$response = json_decode(curl_exec($curl), true);
		curl_close($curl);
		var_dump($response);
		return ($response);
	}

	function	print_data($data)
	{
		if (isset($data[0]))
		{
			echo ($data[0]);
		}
		else
			echo("Who is that?");
	}

	function	read_file($file_name)
	{
		$token = get_token();
		$fh = fopen($file_name,'r');
		while ($line = fgets($fh))
		{
			print_data(get_data($token, trim($line)));
		}
		fclose($fh);
	}

	function validate_usage($argv)
	{
		if (count($argv) == 2)
			read_file($argv[1]);
		else
			echo("usage: php locate.php filename");
	}
	validate_usage($argv);
?>
