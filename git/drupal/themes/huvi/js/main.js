(function ($) {
	

	
	
  $(document).ready(function() {

	var last_tab_uri = getCookie("last_tab_uri");
	var last_tab_huvi = getCookie("last_tab_huvi");
	var path = location . href;
	var title = path . substr(path . lastIndexOf("/")+1);//title
	
    if (last_tab_uri != "" && title == "uritused"  ){
		
		$(last_tab_uri) . click();
	}
	if (last_tab_huvi != "" && title == "huvitegevused"  ){
		
		$(last_tab_huvi) . click();
	}
//&& ((document . title=='Üritused | Huvi Tallinn' )||(document . title=='Huvitegevused | Huvi Tallinn' ))

//quictabs-remembered
	$("#quicktabs-tab-event_quicktabs_for_date_range_s-0") . click(function(){
		setCookie("last_tab_uri", "#quicktabs-tab-event_quicktabs_for_date_range_s-0");
	});
	
	$("#quicktabs-tab-event_quicktabs_for_date_range_s-1") . click(function(){
		setCookie("last_tab_uri", "#quicktabs-tab-event_quicktabs_for_date_range_s-1");
	});
	
	$("#quicktabs-tab-event_quicktabs_for_date_range_s-2") . click(function(){
		setCookie("last_tab_uri", "#quicktabs-tab-event_quicktabs_for_date_range_s-2");
	});
		
	$("#quicktabs-tab-event_quicktabs_for_date_range_s-3") . click(function(){
		setCookie("last_tab_uri", "#quicktabs-tab-event_quicktabs_for_date_range_s-3");
	});
	
	$("#quicktabs-tab-event_quicktabs_for_date_range_s-4") . click(function(){
		setCookie("last_tab_uri", "#quicktabs-tab-event_quicktabs_for_date_range_s-4");
	});
	
	$("#quicktabs-tab-event_quicktabs_for_date_range_s-5") . click(function(){
		setCookie("last_tab_uri", "#quicktabs-tab-event_quicktabs_for_date_range_s-5");
	});

	$("#quicktabs-tab-aeg_huvitegevus-0") . click(function(){
		setCookie("last_tab_huvi", "#quicktabs-tab-aeg_huvitegevus-0");
	});
	
	$("#quicktabs-tab-aeg_huvitegevus-1") . click(function(){
		setCookie("last_tab_huvi", "#quicktabs-tab-aeg_huvitegevus-1");
	});
	
	$("#quicktabs-tab-aeg_huvitegevus-2") . click(function(){
		setCookie("last_tab_huvi", "#quicktabs-tab-aeg_huvitegevus-2");
	});
	
	$("#quicktabs-tab-aeg_huvitegevus-3") . click(function(){
		setCookie("last_tab_hivi", "#quicktabs-tab-aeg_huvitegevus-3");
	});
	
	$("#quicktabs-tab-aeg_huvitegevus-4") . click(function(){
		setCookie("last_tab_hivi", "#quicktabs-tab-aeg_huvitegevus-4");
	});
	
	$("#quicktabs-tab-aeg_huvitegevus-5") . click(function(){
		setCookie("last_tab_huvi", "#quicktabs-tab-aeg_huvitegevus-5");
	});
	
	 function setCookie(cname, cvalue) {
		document . cookie = cname + "=" + cvalue;
	}
	
	function getCookie(cname) {
    var name = cname + "=";
    var ca = document.cookie . split(';');
    for(var i = 0; i <ca . length; i++) {
        var c = ca[i];
        while (c . charAt(0)==' ') {
            c = c . substring(1);
        }
        if (c . indexOf(name) == 0) {
            return c . substring(name . length, c . length);
        }
    }
    return "";
}

	
    //datepicker
    /*
    $( "#edit-date-min" ).datepicker({
      dateFormat: "yy-mm-dd"
    });
    $( "#edit-date-max" ).datepicker({
      dateFormat: "yy-mm-dd"
    });
    */
    //searchbox


    //Mobile filtering
    var mTime = $('ul.quicktabs-tabs li');
    var mCat = $('.views-widget-filter-field_categories_event_value_i18n .views-widget');
    var mCity = $('.views-widget-filter-field_schedule_city_id_value .views-widget');
    var mAct = $('.views-widget-filter-field_categories_activity_value_i18n .views-widget');
    //labels
    var mTimeLabel = $('ul.quicktabs-tabs');
    var mCatLabel = $('.views-widget-filter-field_categories_event_value_i18n');
    var mCityLabel = $('.views-widget-filter-field_schedule_city_id_value');
    var mActLabel = $('.views-widget-filter-field_categories_activity_value_i18n');

    function mobileCloseAll() {
      $('ul.quicktabs-tabs').removeClass('mobileOpen');
      mTime.removeClass('mobileOpen');
      mCat.removeClass('mobileOpen');
      mCity.removeClass('mobileOpen');
      mAct.removeClass('mobileOpen');
      mTimeLabel.removeClass('open');
      mCatLabel.removeClass('open');
      mCityLabel.removeClass('open');
      mActLabel.removeClass('open');
    }

    function mobileClick(el) {
      if(el.hasClass('mobileOpen')) {
        el.removeClass('mobileOpen');
        el.parent().removeClass('open');
      }
      else {
        mobileCloseAll();
        el.addClass('mobileOpen');
        el.parent().addClass('open');
      }
    }

    $('ul.quicktabs-tabs').click(function() {
      mobileClick($(this).find('li'));
    });
    $('.views-widget-filter-field_categories_event_value_i18n').click(function() {
      mobileClick($(this).find('.views-widget'));
    });
    $('.views-widget-filter-field_schedule_city_id_value').click(function() {
      mobileClick($(this).find('.views-widget'));
    });
    $('.views-widget-filter-field_categories_activity_value_i18n').click(function() {
      mobileClick($(this).find('.views-widget'));
    });


    //Load map
    if ( $( "#map_canvas" ).length ) {
      loadMap();
    }

    // Toggle buy link
    $(".buy-link").click(function(event) {
      $(this).parent().parent().children('.buymenu').toggle();
      event.preventDefault();
    });
    // Social links
    $(".social-share").click(function(event) {

      var socialUrl = '';
      var socialTitle = '';

      // Facebook share
      if($(this).hasClass('fb-share')) {
        socialUrl = $(this).attr('data-url');
        shareFB(socialUrl);
      }

      // Twitter share
      if($(this).hasClass('twitter-share')) {
        socialUrl = $(this).attr('data-url');
        socialTitle = $(this).attr('data-title');
        shareTwitter(socialUrl, socialTitle);
      }

      // Google Plus share
      if($(this).hasClass('google-share')) {
        socialUrl = $(this).attr('data-url');
        shareGoogle(socialUrl);
      }

      event.preventDefault();
    });
	
	

    // Change free event checkbox text
    if($('#block-views-event-listing-fixed-block #edit-field-isfree-value-wrapper > label').length > 0 && $('.form-item-field-isfree-value label').length > 0) {
      $('.form-item-field-isfree-value label').text($('#block-views-event-listing-fixed-block #edit-field-isfree-value-wrapper > label').text());
    }
    if($('#block-views-event-listing-fixed-block-6 #edit-field-isfree-value-wrapper > label').length > 0 && $('.form-item-field-isfree-value label').length > 0) {
      $('.form-item-field-isfree-value label').text($('#block-views-event-listing-fixed-block-6 #edit-field-isfree-value-wrapper > label').text());
    }

    // refresh the page when resetting filters
    $('.views-exposed-widget.views-reset-button').click(function(event) {
      event.preventDefault();
      location.reload();
    });


    function checkFilters() {
      if($('ul.quicktabs-tabs').hasClass('checking')) {
        // Automatically checking and triggering selected filters for other quicktab views
        $('.quicktabs-tabpage.last-active').removeClass('last-active');
        $('.quicktabs-tabpage.now-active').addClass('last-active').removeClass('now-active');
        $('.quicktabs-tabpage').not('.quicktabs-hide').addClass('now-active');

        var filterIsChecked = false;
        $('.quicktabs-tabpage.last-active .bef-select-as-checkboxes .form-item').each(function() {
          var text = $(this).find('label').text();
          var toChange = $('.quicktabs-tabpage.now-active .bef-select-as-checkboxes .form-item label:contains("' + text + '")');
          if(toChange.length > 0) {
            if($(this).find('input').is(':checked')) {
              toChange.prev().attr('checked', 'checked');
            }
            else {
              toChange.prev().removeAttr('checked');
            }
          }
        });

        $('ul.quicktabs-tabs').removeClass('checking');
        $('.quicktabs-tabpage.now-active').find('.views-submit-button input.form-submit').trigger('click');

        // Bugfix for QuickTabs and view filters to get along
        $('.view-event-listing-fixed .form-type-bef-checkbox label').click(function() {
          //if($(this).closest('.block--views').hasClass('first-click-done')) {
            if($(this).prev().is(':checked')) {
              $(this).prev().removeAttr('checked');
            }
            else {
              $(this).prev().attr('checked', 'checked');
            }
            $(this).closest('.block--views').find('input#edit-submit-event-listing-fixed').trigger('click');
            /*
          }
          else {
            $(this).closest('.block--views').addClass('first-click-done');
          }
          */
        });
        $('ul.quicktabs-tabs').removeClass('checking');
      }
    }

    $('ul.quicktabs-tabs li a').click(function() {
      $('ul.quicktabs-tabs').addClass('checking checking-ajax');
      checkFilters();
    });

    $('.quicktabs-tabpage').addClass('now-active');


    // Bugfix for QuickTabs and view filters to get along
    $('.view-event-listing-fixed .form-type-bef-checkbox label').click(function() {
      //if($(this).closest('.block--views').hasClass('first-click-done')) {
        if($(this).prev().is(':checked')) {
          $(this).prev().removeAttr('checked');
        }
        else {
          $(this).prev().attr('checked', 'checked');
        }
        $(this).closest('.block--views').find('input#edit-submit-event-listing-fixed').trigger('click');
      /*
      }
      else {
        $(this).closest('.block--views').addClass('first-click-done');
      }
      */
    });


    // Disable clicking on filters when automatically submitting searchbox text
    /*
    $('.view-event-listing-fixed .view-filters').before('<div class="empty-filters-overlay"></div>');
    $('.empty-filters-overlay').hide();
    $('.view-event-listing-fixed form .form-item-combine input').keyup(function() {
      $('.empty-filters-overlay').show();
    });
    */

    $('.page-uritused .view-event-listing-fixed form').attr('action', '/uritused');
    $('.page-huvitegevused .view-event-listing-fixed form').attr('action', '/huvitegevused');

    $('.schedule-show-all').click(function() {
      $('.schedule-item').removeClass('schedule-hidden');
      $(this).hide();
    });

  });

  var categoriesOpen;
  var citiesOpen;
  var activityCatOpen;
  $( document ).ajaxStart(function() {
    if($('#edit-field-categories-event-value-i18n-wrapper .views-widget').hasClass('mobileOpen')){
      categoriesOpen = true;
    }else{
      categoriesOpen = false;
    }
    if($('#edit-field-categories-activity-value-i18n-wrapper .views-widget').hasClass('mobileOpen')){
      activityCatOpen = true;
    }
    else{
      activityCatOpen = false;
    }
    if($('#edit-field-schedule-city-id-value-wrapper .views-widget').hasClass('mobileOpen')){
      citiesOpen = true;
    }else{
      citiesOpen = false;
    }
    if($('.quicktabs-tabs li').hasClass('mobileOpen')){
      citiesOpen = false;
      categoriesOpen = false;
      activityCatOpen = false;
    }

    $('#huvi-loader').remove();
    $('#quicktabs-event_quicktabs_for_date_range_s #edit-combine, #quicktabs-aeg_huvitegevus #edit-combine').after('<div id="huvi-loader"></div>');
  });


  $(document).ajaxComplete(function() {
    $('.page-uritused .view-event-listing-fixed form').attr('action', '/uritused');
    $('.page-huvitegevused .view-event-listing-fixed form').attr('action', '/huvitegevused');
    // Disable clicking on filters when automatically submitting searchbox text
    /*
    $('.view-event-listing-fixed .view-filters').before('<div class="empty-filters-overlay"></div>');
    setTimeout(function() {
      $('.empty-filters-overlay').hide();
      var searchInput = $('.view-event-listing-fixed form .form-item-combine input:visible');
      if(searchInput.length > 0) {
        var strLength = searchInput.val().length * 2;
        searchInput.focus();
        searchInput[0].setSelectionRange(strLength, strLength);
      }
    }, 100);
    $('.view-event-listing-fixed form .form-item-combine input').keyup(function() {
      $('.empty-filters-overlay').show();
    });
    */

    //Mobile filtering
    var mTime = $('ul.quicktabs-tabs li');
    var mCat = $('.views-widget-filter-field_categories_event_value_i18n .views-widget');
    var mCity = $('.views-widget-filter-field_schedule_city_id_value .views-widget');
    var mAct = $('.views-widget-filter-field_categories_activity_value_i18n .views-widget');
    //labels
    var mTimeLabel = $('ul.quicktabs-tabs');
    var mCatLabel = $('.views-widget-filter-field_categories_event_value_i18n');
    var mCityLabel = $('.views-widget-filter-field_schedule_city_id_value');
    var mActLabel = $('.views-widget-filter-field_categories_activity_value_i18n');

    function mobileCloseAll() {
      $('ul.quicktabs-tabs').removeClass('mobileOpen');
      mTime.removeClass('mobileOpen');
      mCat.removeClass('mobileOpen');
      mCity.removeClass('mobileOpen');
      mAct.removeClass('mobileOpen');
      mTimeLabel.removeClass('open');
      mCatLabel.removeClass('open');
      mCityLabel.removeClass('open');
      mActLabel.removeClass('open');
      //categoriesOpen = false;
      //citiesOpen = false;
      //categoriesOpen = false;
    }

    if(categoriesOpen){
      $('#edit-field-categories-event-value-i18n-wrapper .views-widget').addClass('mobileOpen');
      $('#edit-field-categories-event-value-i18n-wrapper ').addClass('open');
    }
    if(citiesOpen){
      $('#edit-field-schedule-city-id-value-wrapper .views-widget').addClass('mobileOpen');
      $('#edit-field-schedule-city-id-value-wrapper').addClass('open');
    }
    if(activityCatOpen){
      $('#edit-field-categories-activity-value-i18n-wrapper .views-widget').addClass('mobileOpen');
      $('#edit-field-categories-activity-value-i18n-wrapper').addClass('open');
    }

    function mobileClick(el) {
      if(el.hasClass('mobileOpen')) {
        el.removeClass('mobileOpen');
        el.parent().removeClass('open');
      }
      else {
        mobileCloseAll();
        el.addClass('mobileOpen');
        el.parent().addClass('open');
      }
    }
	

    $('ul.quicktabs-tabs').unbind('click').click(function() {
      mobileClick($(this).find('li'));
    });
    $('.views-widget-filter-field_categories_event_value_i18n').unbind('click').click(function() {
      mobileClick($(this).find('.views-widget'));
    });
    $('.views-widget-filter-field_schedule_city_id_value').unbind('click').click(function() {
      mobileClick($(this).find('.views-widget'));
    });
    $('.views-widget-filter-field_categories_activity_value_i18n').unbind('click').click(function() {
      mobileClick($(this).find('.views-widget'));
    });
	
	


    // Change free event checkbox text
    if($('#block-views-event-listing-fixed-block #edit-field-isfree-value-wrapper > label').length > 0 && $('.form-item-field-isfree-value label').length > 0) {
      $('.form-item-field-isfree-value label').text($('#block-views-event-listing-fixed-block #edit-field-isfree-value-wrapper > label').text());
    }
    if($('#block-views-event-listing-fixed-block-6 #edit-field-isfree-value-wrapper > label').length > 0 && $('.form-item-field-isfree-value label').length > 0) {
      $('.form-item-field-isfree-value label').text($('#block-views-event-listing-fixed-block-6 #edit-field-isfree-value-wrapper > label').text());
    }

    // refresh the page when resetting filters
    $('.view-event-listing-fixed .views-exposed-widget.views-reset-button').click(function(event) {
      event.preventDefault();
      location.reload();
    });


    function checkFilters() {
      if($('ul.quicktabs-tabs').hasClass('checking-ajax')) {
        $('.quicktabs-tabpage.now-active').removeClass('now-active');
        $('.quicktabs-tabpage').not('.quicktabs-hide').addClass('now-active');

        var filterIsChecked = false;
        $('.quicktabs-tabpage.last-active .bef-select-as-checkboxes .form-item').each(function() {
          var text = $(this).find('label').text();
          var toChange = $('.quicktabs-tabpage.now-active .bef-select-as-checkboxes .form-item label:contains("' + text + '")');
          if(toChange.length > 0) {
            if($(this).find('input').is(':checked')) {
              toChange.prev().attr('checked', 'checked');
            }
            else {
              toChange.prev().removeAttr('checked');
            }
          }
        });

        setTimeout(function(){
          $('.quicktabs-tabpage input#edit-combine').attr('value', $('.quicktabs-tabpage.last-active input#edit-combine').val());
        }, 500);

        $('ul.quicktabs-tabs').removeClass('checking-ajax');
        $('.quicktabs-tabpage.now-active').find('.views-submit-button input.form-submit').trigger('click');
      }
    }

    checkFilters();

    // Bugfix for QuickTabs and view filters to get along
    $('.view-event-listing-fixed .form-type-bef-checkbox label').click(function() {
      //if($(this).closest('.block--views').hasClass('first-click-done')) {
        if($(this).prev().is(':checked')) {
          $(this).prev().removeAttr('checked');
        }
        else {
          $(this).prev().attr('checked', 'checked');
        }
        $(this).closest('.block--views').find('.views-submit-button input.form-submit').trigger('click');
      /*
      }
      else {
        $(this).closest('.block--views').addClass('first-click-done');
      }
      */
    });

    $('.openid-ee-button.form-submit').parent().wrap('<form id="openid_ee_custom_login" action="user/login" method="POST"></form>');
    $('#openid_ee_custom_login').appendTo('#modal-content');
    $('#id-card-button').appendTo('#modal-content');
    $('#mobile-id-button').appendTo('#modal-content');

    $('#huvi-loader').remove();

    //$('#modalContent').css('top', '50px');

  });


})(jQuery);




function fbShare(url, title, descr, image, winWidth, winHeight) {
  var winTop = (screen.height / 2) - (winHeight / 2);
  var winLeft = (screen.width / 2) - (winWidth / 2);
  window.open('http://www.facebook.com/sharer.php?s=100&p[title]=' + title + '&p[summary]=' + descr + '&p[url]=' + url + '&p[images][0]=' + image, 'sharer', 'top=' + winTop + ',left=' + winLeft + ',toolbar=0,status=0,width='+winWidth+',height='+winHeight);
}

function shareFB(url) {

  var winWidth = 626;
  var winHeight = 436;

  var winTop = (screen.height / 2) - (winHeight / 2);
  var winLeft = (screen.width / 2) - (winWidth / 2);

  window.open('https://www.facebook.com/sharer/sharer.php?u='+encodeURIComponent(url), 'facebook-share-dialog', 'top=' + winTop + ',left=' + winLeft + ',width='+winWidth+',height='+winHeight+',toolbar=0,status=0');
}


function shareTwitter(url, title) {
  var winWidth = 626;
  var winHeight = 436;

  var winTop = (screen.height / 2) - (winHeight / 2);
  var winLeft = (screen.width / 2) - (winWidth / 2);

  window.open('http://twitter.com/share?url='+encodeURIComponent(url)+'&text='+encodeURIComponent(title), 'twitter-share-dialog', 'top=' + winTop + ',left=' + winLeft + ',width='+winWidth+',height='+winHeight+',toolbar=0,status=0');
}


function shareGoogle(url) {
  var winWidth = 626;
  var winHeight = 436;

  var winTop = (screen.height / 2) - (winHeight / 2);
  var winLeft = (screen.width / 2) - (winWidth / 2);

   window.open('https://plus.google.com/share?url='+encodeURIComponent(url), 'facebook-share-dialog', 'top=' + winTop + ',left=' + winLeft + ',width='+winWidth+',height='+winHeight+',toolbar=0,status=0');
}


function loadMap() {
  // Asynchronously Load the map API
  var script = document.createElement('script');
  script.type = 'text/javascript';
  script.src = "http://maps.googleapis.com/maps/api/js?sensor=false&callback=initialize";
  document.body.appendChild(script);
}


function initialize() {
    var map;

    var markers_attr = jQuery('#map_canvas').attr('data-markers').split(';');
    var markers = [];
    jQuery.each( markers_attr, function( i, val ) {
      //console.log(val);
      markers[i] = val.split(',');

    });

    var bounds = new google.maps.LatLngBounds();
    var mapOptions = {
        mapTypeId: 'roadmap',
        streetViewControl: true,
    };

    // Display a map on the page
    map = new google.maps.Map(document.getElementById("map_canvas"), mapOptions);
    map.setTilt(45);

    // Display multiple markers on a map
    var infoWindow = new google.maps.InfoWindow(), marker, i;

    // Loop through our array of markers & place each one on the map
    for( i = 0; i < markers.length; i++ ) {
        var position = new google.maps.LatLng(markers[i][0], markers[i][1]);
        bounds.extend(position);
        marker = new google.maps.Marker({
            position: position,
            map: map,
            //title: markers[i][0]
        });

        // Allow each marker to have an info window
//        google.maps.event.addListener(marker, 'click', (function(marker, i) {
//            return function() {
//                infoWindow.setContent(infoWindowContent[i][0]);
//                infoWindow.open(map, marker);
//            }
//        })(marker, i));

      // Automatically center the map fitting all markers on the screen
      map.fitBounds(bounds);

    }
    // Override our map zoom level once our fitBounds function runs (Make sure it only runs once)
    var boundsListener = google.maps.event.addListener((map), 'bounds_changed', function(event) {

      if(this.getZoom() > 20){
        this.setZoom(15);
      }
      else {
        this.setZoom(13);
      }

      google.maps.event.removeListener(boundsListener);
    });
	
	

}
