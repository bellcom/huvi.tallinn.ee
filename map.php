<?php

$default_coords = '59.439092,24.7482867'; // Just a spot at the center of Tallinn
$markers = (isset($_GET['markers'])) ? $_GET['markers'] : '';
$key = (isset($_GET['key'])) ? $_GET['key'] : '';
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
	<script type="text/javascript" src="//maps.googleapis.com/maps/api/js?b&key="<?php print key ?>></script>
</head>
<body>
<div id="map_area"></div>
<script type="text/javascript">

(function() {

	var markers_str = '<?php echo $markers; ?>';
	var markers_exist = (markers_str !== '');
	var markers_lat_long = markers_str.split('|');
	var coords = markers_lat_long[0].split(',');
	var map_id = 'map_area';

	var loadMap = function() {

		google.maps.event.addDomListener(window, 'load', function() {

			var map_canvas = document.getElementById(map_id);
			var location = (markers_exist)
				? new google.maps.LatLng(coords[0], coords[1])
				: new google.maps.LatLng(<?php echo $default_coords; ?>);

			var map_options = {
				center: location,
				zoom: 15
			};

			var map = new google.maps.Map(map_canvas, map_options);

			if (!markers_exist) return;

			var addMarker = function(lat, long, bounds) {
				var pos = new google.maps.LatLng(lat, long);
				var marker = new google.maps.Marker({
					position: pos,
					map: map
				});

				// Automatically center the map fitting all markers on the screen
				bounds.extend(pos);			
			};

			var bounds = new google.maps.LatLngBounds();
			var markers_len = markers_lat_long.length;
			var tmp_coords;

			for (var i = 0; i < markers_len; i++) {
				tmp_coords = markers_lat_long[i].split(',');
				addMarker(tmp_coords[0], tmp_coords[1], bounds);
				map.initialZoom = true;
				map.fitBounds(bounds);
			}

			google.maps.event.addListener((map), 'zoom_changed', function() {
				var zoomChangeBoundsListener = google.maps.event.addListener((map), 'bounds_changed', function(event) {
					if (this.getZoom() > 20 && this.initialZoom == true) {
						// Change max/min zoom here
						this.setZoom((markers_len == 1) ? 17 : 15);
						this.initialZoom = false;
					}

					google.maps.event.removeListener(zoomChangeBoundsListener);
				});
			});
		});
	};

	if (document.getElementById(map_id)) {
		loadMap();
	}
})();

</script>
</body>
</html>

