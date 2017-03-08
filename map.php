<?php

$markers = (isset($_GET['markers'])) ? $_GET['markers'] : '59.439092,24.7482867';

?>
<!doctype html>
<html>
<head>
	<title>:: :: ::</title>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	<style type="text/css">
	body, html {
		height:100%;
		width:100%;
	}

	body {
		margin:0;
		padding:0;
	}

	#map_area {
		height:100%;
		width:100%;
	}
	</style>
	<script type="text/javascript" src="http://maps.googleapis.com/maps/api/js?sensor=false&key=AIzaSyBIsA6lIhz327eRIfBxZAS2PTnxds7IpsY"></script>
</head>
<body>
<div id="map_area"></div>
<script type="text/javascript">

(function() {

	var markers_str = '<?php echo $markers; ?>';
	var markers_lat_long = markers_str.split('|');
	var coords = markers_lat_long[0].split(',');

	var map_id = 'map_area';
	var loadMap = function() {

		google.maps.event.addDomListener(window, 'load', function() {

			var map_canvas = document.getElementById(map_id);
			var location = new google.maps.LatLng(coords[0], coords[1]);

			var map_options = {
				center: location,
				zoom: 16
			};

			var map = new google.maps.Map(map_canvas, map_options);

			var addMarker = function(lat, long) {
				var marker = new google.maps.Marker({
					position: new google.maps.LatLng(lat, long),
					map: map,
				});				
			};

			var markers_len = markers_lat_long.length;
			var tmp_coords;

			for (var i = 0; i < markers_len; i++) {
				tmp_coords = markers_lat_long[i].split(',');
				addMarker(tmp_coords[0], tmp_coords[1]);
			}
		});
	};

	if (document.getElementById(map_id)) {
		loadMap();
	}
})();

</script>
</body>
</html>

