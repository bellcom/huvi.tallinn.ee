<?php

function kuhuminna_mobile_id_file() {

ini_set('display_errors', 'stderr');
mb_internal_encoding("UTF-8");
error_reporting(E_ALL);// | E_STRICT

require_once("openid.ee-authentication.php");

/*
header('Content-type: text/html; charset=utf-8');
?>
<html>
<head><title>PHP OpenID näidis</title>
<link rel="stylesheet" href="style.css" type="text/css" /></head>
<body>

<div id="sisu">

<h1>Mobiil-ID ja ID-kaardi kasutamise näidis Apache-PHP keskkonnas</h1>
<p>Näidisrakendus kasutab <a href="https://openid.ee">OpenID.ee</a> teenust ja <a href="https://github.com/openid/php-openid">OpenID PHP teeki</a> (ver. 2.2.2). Selline kooslus võimaldab Eesti ID-kaardi ja Mobiil-ID isikutuvastust kasutada kiirel ja standardsel viisil. Käesolevas näites võetakse lõppkasutaja käest saadud isikuandmed (nimi, sünnipäev, sugu, e-mail) ning salvestatakse need lihtsalt PHP sessioonimuutujasse.</p>

<p>
	<a href="?action=eid-login"><img src="id-kaart.png"></a>
	<a href="?action=mid-login"><img src="mobiil-id.png"></a>
</p>


<h2>Juhised selle rakenduse jooksutamiseks:</h2>
<ul>
	<li>Veendu, et sul on avaliku IP-aadressiga Apache veebiserver koos PHP mooduliga.
	<ul>
		<li>Töötava keskkonna saad käsuga:<ul><li><i>sudo apt-get install apache2 php5 php-openid</i></li>
		<li>Testitud süsteemid: Debian Wheezy, Ubuntu Linux 12.04 (Precise Pangolin), 12.10 (Quantal Quetzal), 13.04 (Raring Ringtail), 13.10 (Saucy Salamander).</li>
		<li>Vanematel süsteemidel ja/või PHP versioonidel võib lisaks olla vajalik "php-xml" pakk.</li>
		</ul></li>
		<li>Muudel platvormidel järgi <a href="http://httpd.apache.org/docs/">Apache</a> ja <a href="http://www.php.net/manual/en/install.php">PHP</a> dokumentatsiooni ning paigalda <a href='https://github.com/openid/php-openid'>OpenID tarkvara</a> käsitsi.</li>
	</ul>
	</li>
	<li>Paki <a href="php-example.zip">näidisprogramm</a> lahti avalikult kättesaadavasse kataloogi. Näidisprogrammis sisaldub minimaalne vajalik, et saada ID-kaardi ja Mobiil-ID tugi enda veebirakendusele. Kohustuslik lugemine:
	<ul>
		<li>OpenID <a href="http://openid.net/specs/openid-provider-authentication-policy-extension-1_0.html">PAPE</a> ja <a href="http://openid.net/specs/openid-simple-registration-extension-1_0.html">SREG</a>-i spetsifikatsioon</li>
		<li>OpenID <a href="https://github.com/openid/php-openid">PHP-teegi</a> dokumentatsioon</li>
	</ul>
	</li>
	<li>Uuri näidisrakendust ning muuda seda vastavalt enda vajadustele. Tunne ennast vabalt seda kasutades, kopeerides või midaiganes-tehes.
	<ul>
		<li>Sessiooni olemasolu kontrollimiseks klõbista <a href="?bla1">seda linki</a> ja <a href="?bla2">seda</a>. Pane tähele, et "sisselogituna" säilib muutuja $_SESSION sisu.</li>
		<li>Sessiooni <a href="?action=logout">lõpetamine</a></li>

	</ul>
	</li>
	<li>Küsimused-ettepanekud saada aadressile <a href="mailto:mart@ideelabor.ee">mart@ideelabor.ee</a></li>
</ul>
<p style="text-align: right;">Viimati uuendatud 4. veebruar 2014</p>

<?php
if(isset($msg)) echo "<div class=\"alert\">$msg</div>";
if(isset($error)) echo "<div class=\"error\">$error</div>";
if(isset($success)) echo "<div class=\"success\">$success</div>";

// Vaatame, mis muutujad olemas on ...
if(!empty($_SESSION)) {
	echo "<h2>Massiivi \$_SESSION sisu:</h2>";
	echo "<div class='alert'>";
	foreach($_SESSION as $k => $v)
		echo "$k = $v <br />";
	echo "</div>";
}

if(isset($_GET["action"]) and $_GET["action"] == "finishAuth"){
	echo "<h2>OpenID teegi töö tulemus:</h2>";
	echo "<div class='alert'>";
	foreach($_GET as $k => $v)
		echo "$k = $v <br />";
	echo "</div>";
}
?>

</div>
</body>
</html>

<?php
*/
}
?>
