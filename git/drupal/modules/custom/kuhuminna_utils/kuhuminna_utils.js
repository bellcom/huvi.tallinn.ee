(function ($) {

  $(document).ready(function() {
    //console.log('jquery_loaded');
    // Show only either event or activity category
    $('.field-name-field-categories-event').hide();
    $('.field-name-field-categories-activity').hide();
    change_event_type($('.field-name-field-type input').filter(':checked').val());
    $('.field-name-field-type input').change(function() {
      change_event_type($(this).filter(':checked').val());
    });

    function change_event_type(type) {
      if(type == 'uritus') {
        $('.field-name-field-categories-activity').hide();
        $('.field-name-field-categories-event').show();
      }
      if(type == 'huvitegevus') {
        $('.field-name-field-categories-event').hide();
        $('.field-name-field-categories-activity').show();
      }
    }

    function mapLocationOpener() {
      $('.geolocation-address').show().click(function() {
        $(this).siblings().css({'position': 'relative', 'left': '0px'});
        //$(this).parent().parent().siblings('.field-name-field-schedule-city-id').show();
      });
      var msg = $('.field-name-field-schedule .messages.error.messages-inline').parent().parent();
      //msg.find('.field-name-field-schedule-city-id').show();
      msg.find('.field-name-field-schedule-location > div > div').siblings().css({'position': 'relative', 'left': '0px'});
    }

    function checkRepeating() {
      $('.field-name-field-schedule-date .fieldset-wrapper > .date-clear').each(function() {
        if($(this).find('.form-item input[type="checkbox"]').prop('checked')) {
          $(this).next('.form-item').show();
        }
        else {
          $(this).next('.form-item').hide();
        }
      });
      $('.field-name-field-schedule-date .fieldset-wrapper > .date-clear').click(function() {
        if($(this).find('.form-item input[type="checkbox"]').prop('checked')) {
          $(this).next('.form-item').show();
        }
        else {
          $(this).next('.form-item').hide();
        }
      });
    }

    function addHelpBubble() {
      //$('<div class="infobubble"></div>').insertBefore('.node-event-form .description');
      $('.node-event-form .description').wrap('<div class="infobubble"></div>');
      $('.infobubble').hover(
        function() {
          $( this ).find('.description').show();
        }, function() {
          $( this ).find('.description').hide();
        }
      );
    }

    var delay = (function(){
      var timer = 0;
      return function(callback, ms){
        clearTimeout (timer);
        timer = setTimeout(callback, ms);
      };
    })();

    if($('body.page-node-edit.node-type-event, body.page-node-add-event').length > 0) {
      // Change the map location with the marker
     // if($('#edit-field-schedule-und-0-field-schedule-location.field-name-field-schedule-location .geolocation-lat-item-value').text() == '') {
      //  var location = 'Tallinn';
      //  $('#edit-field-schedule-und-0-field-schedule-location.field-name-field-schedule-location .geolocation-address input').val(location);
       // $('#edit-field-schedule-und-0-field-schedule-location.field-name-field-schedule-location .geolocation-address-geocode').trigger('click');
        // We have to re-set the address, because the map refreshes the address after getting the location
       // setTimeout(function(){
       //   $('#edit-field-schedule-und-0-field-schedule-location.field-name-field-schedule-location .geolocation-address input').attr('value', location);
       // }, 1000);
       // setTimeout(function(){
       ///   $('#edit-field-schedule-und-0-field-schedule-location.field-name-field-schedule-location .geolocation-address input').attr('value', location);
       // }, 3000);
     // }

      // Editing info tooltip
      /*
      $('form.node-event-form > div > div').each(function() {
        if($(this).find('.description').length > 0) {
          $(this).hover(
            function() {
              $(this).find('.description').show();
            },
            function () {
              $(this).find('.description').hide();
            }
          );
        }
      });
      */

      // Form submit location alter
      var fa = $('form.node-event-form').attr('action');
      fa = fa.split('?')[0];
      $('form.node-event-form').attr('action', fa);

      // Check not published checkbox and save event
    /*  
	$('#edit-actions #edit-preview').click(function(event) {
        event.preventDefault();
        $('.field-name-field-unpublish input').attr('checked', 'checked');
        $('#edit-actions #edit-submit').trigger('click');
      });
*/
      $('#edit-actions #edit-submit').click(function(event) {
        $('.date-clear.form-text[maxlength="30"]').each(function() {
          if($(this).val().length > 0) {
            if($(this).parent().siblings().find('.date-clear.form-text').val().length < 1) {
              console.log('no_value');
              $(this).parent().siblings().find('.date-clear.form-text').val('23:55');
            }
            else {
              console.log('has_value');
            }
          }
        });
      });

      $('.geolocation-address input').keyup(function() {
        var th = $(this);
        delay(function(){
          th.parent().parent().find('.geolocation-address-geocode').trigger('click');
        }, 1000 );
      });

      mapLocationOpener();
      checkRepeating();
      addHelpBubble();

    }

    // Role explanations for manager and admin role
    $('#edit-account .form-item-roles .form-item-roles-2 label')
      .text('Sisseloginud kasutaja - (Tavakasutaja, kes saab üritusi lisada.)');
    $('#edit-account .form-item-roles .form-item-roles-3 label')
      .text('Administrator - (Boss, saab absoluutselt kõike saidil muuta. Parem ära määra seda kellelegi.)');
    $('#edit-account .form-item-roles .form-item-roles-4 label')
      .text('Manager - (Saab hallata kõik kasutajaid ja üritusi ning teha põhilisi muudatusi lehel. Kasutada ainult organisatsiooni siseselt.)');

    // Banner management full banner showing on hover
    $('.views-form-banner-listing-page td.views-field-field-adv-image').hover(
      function() {
        $('th.views-field-field-adv-image-1').show();
        $(this).siblings('.views-field-field-adv-image-1').show();
      }, function() {
        $('th.views-field-field-adv-image-1').hide();
        $(this).siblings('.views-field-field-adv-image-1').hide();
      }
    );

  });


  $(document).ajaxComplete(function() {

    // Show only either event or activity category
    $('.field-name-field-categories-event').hide();
    $('.field-name-field-categories-activity').hide();
    change_event_type($('.field-name-field-type input').filter(':checked').val());
    $('.field-name-field-type input').change(function() {
      change_event_type($(this).filter(':checked').val());
    });

    function change_event_type(type) {
      if(type == 'uritus') {
        $('.field-name-field-categories-activity').hide();
        $('.field-name-field-categories-event').show();
      }
      if(type == 'huvitegevus') {
        $('.field-name-field-categories-event').hide();
        $('.field-name-field-categories-activity').show();
      }
    }

    // Copy the previous map location when adding a new Schedule field on the event editing page
    function copyMapLocation() {
      // Change city region
      var cityRegion = $('.form-item-field-schedule-und-0-field-schedule-city-id-und select').val();
      $('.ajax-new-content .field-name-field-schedule-city-id select option[value="' + cityRegion + '"]').attr('selected', 'selected');

      // Change the map location with the marker
      var location = $('#edit-field-schedule .field-multiple-table > tbody > tr').eq(-2).find('.field-name-field-schedule-location .geolocation-address input').attr('value');
      if(location == undefined) {
        var location = 'Tallinn';
      }
      $('.ajax-new-content .field-name-field-schedule-location .geolocation-address input').val(location);
      $('.ajax-new-content .field-name-field-schedule-location .geolocation-address-geocode').trigger('click');
      // We have to re-set the address, because the map refreshes the address after getting the location
      setTimeout(function(){
        var location = $('#edit-field-schedule .field-multiple-table > tbody > tr').eq(-2).find('.field-name-field-schedule-location .geolocation-address input').attr('value');
        if(location == undefined) {
          var location = 'Tallinn';
        }
        $('.ajax-new-content .field-name-field-schedule-location .geolocation-address input').attr('value', location);
      }, 1000);
      setTimeout(function(){
        var location = $('#edit-field-schedule .field-multiple-table > tbody > tr').eq(-2).find('.field-name-field-schedule-location .geolocation-address input').attr('value');
        if(location == undefined) {
          var location = 'Tallinn';
        }
        $('.ajax-new-content .field-name-field-schedule-location .geolocation-address input').attr('value', location);
      }, 2000);
    }

    function mapLocationOpener() {
      $('.geolocation-address').show().click(function() {
        $(this).siblings().css({'position': 'relative', 'left': '0px'});
        //$(this).parent().parent().siblings('.field-name-field-schedule-city-id').show();
      });
      var msg = $('.field-name-field-schedule .messages.error.messages-inline').parent().parent();
      //msg.find('.field-name-field-schedule-city-id').show();
      msg.find('.field-name-field-schedule-location > div > div').siblings().css({'position': 'relative', 'left': '0px'});
    }

    function checkRepeating() {
      $('.field-name-field-schedule-date .fieldset-wrapper > .date-clear').each(function() {
        if($(this).find('.form-item input[type="checkbox"]').prop('checked')) {
          $(this).next('.form-item').show();
        }
        else {
          $(this).next('.form-item').hide();
        }
      });
      $('.field-name-field-schedule-date .fieldset-wrapper > .date-clear').unbind('click').click(function() {
        if($(this).find('.form-item input[type="checkbox"]').prop('checked')) {
          $(this).next('.form-item').show();
        }
        else {
          $(this).next('.form-item').hide();
        }
      });
    }

    var delay = (function(){
      var timer = 0;
      return function(callback, ms){
        clearTimeout (timer);
        timer = setTimeout(callback, ms);
      };
    })();

    // Initialize functions
    if($('body.page-node-edit.node-type-event, body.page-node-add-event').length > 0) {
      copyMapLocation();
      mapLocationOpener();
      checkRepeating();

      $('.geolocation-address input').keyup(function() {
        var th = $(this);
        delay(function(){
          th.parent().parent().find('.geolocation-address-geocode').trigger('click');
        }, 1000 );
      });
    }

  });

})(jQuery);
