<?
/**
 * SOAP_Client
 *
 * kasutusel �henduse pidamiseks SOAP-serveriga ja �henduseks
 * vajalike xml-de genereerimiseks.
 * @copyright	http://pear.php.net/package/SOAP
 */

define('PEAR_PATH', dirname(__FILE__).'/include/_PEAR/'); // Kasutamaks s�steemseid PEARi mooduleid, v��rtusta see ''

//define('PEAR_PATH', '');

require_once PEAR_PATH.'SOAP/Client.php';


/**
 * XML_Unserializer
 *
 * kasutusel SOAP Serveri saadetud xml-vastuste t��tlemiseks
 */
require_once PEAR_PATH.'XML/Unserializer.php';

/**
* PEAR vigade suunamine (globaalne funktsioon)
* tanel
*/
if (function_exists('raise_error'))
	PEAR::setErrorHandling(PEAR_ERROR_CALLBACK, 'raise_error');

/**
 * DigiDocService endpoint URL
 */
define('DDS_ENDPOINT', 'https://www.openxades.org:8443');

/**
 * DigiDocService WSDL
 */
define('DD_WSDL', 'https://www.openxades.org:8443/?wsdl');


# DigiDocService certifcate issuer certificate file
define('DD_SERVER_CA_FILE', dirname(__FILE__).'/service_certs.pem');


/**#@+
 * Serveriga �henduse loomiseks vajalik parameeter
 */
define('DD_PROXY_HOST', '');
define('DD_PROXY_PORT', '');
define('DD_PROXY_USER', '');
define('DD_PROXY_PASS', '');
define('DD_TIMEOUT', '9000');
/**#@-*/

/**
 * WSDL classi lokaalse faili nimi
 *
 * Selles hoitakse WSDL-i alusel genereeritud PHP classi,
 * et ei peaks iga kord seda serverist uuesti p�rima.
 * Kui WSDL faili aadressi muuta, tuleb ka see fail �ra kustutada, kuna
 * selles hoitakse ka serveri aadressi, mis p�rast muutmist enam ei �hti
 * �ige aadressiga!
 */
define('DD_WSDL_FILE', 'wsdl.class.php');

/**
 * Vaikimis kasutatav keel
 * V�imalikud v��rtused: EST / ENG / RUS
 */
define('DD_DEF_LANG', 'EST');

define('LOCAL_FILES', TRUE);

?>
