(function ($) {
  Drupal.behaviors.huviEvents = {
    attach: function (context, settings) {
      // Aeg tabs behavior.
      $('ul.quicktabs-tabs li a', context).once('huviEvents').click(function (event) {
        event.preventDefault();
        var current_tab = $(this).attr('id');
        $('ul.quicktabs-tabs li.active').removeClass('active');
        $(this).parent('li').addClass('active');
        checkDateFilters(current_tab);
        url_path = createUrl();
        window.history.pushState({urlPath: url_path}, "", url_path);
      });
      // Mobile event search.
      $('ul.quicktabs-tabs', context).once('huviEvents').click(function (event) {
        if ($(event.target).closest('li').length == 0) {
          mobileClick($(this).find('li'));
        }
      });

      // Event filters tabs.
      $('.view-event-listing-fixed .views-widget .form-type-bef-checkbox label').once('huviEvents').click(function (event) {
        if ($(this).prev().is(':checked')) {
          $(this).prev().prop('checked', false)
        } else {
          $(this).prev().prop('checked', true);
        }
        $(this).closest('.block--views').find('.views-submit-button input.form-submit').trigger('click');
        url_path = createUrl();
        window.history.pushState({urlPath: url_path}, "", url_path);
      });
      $('.views-widget-filter-field_categories_event_value_i18n', context).once('huviEvents').click(function (event) {
        mobileClick($(this).find('.views-widget'));
      });
      $('.views-widget-filter-field_schedule_city_id_value', context).once('huviEvents').click(function (event) {
         mobileClick($(this).find('.views-widget'));
      });
      $('.views-widget-filter-field_categories_activity_value_i18n', context).once('huviEvents').click(function (event) {
        mobileClick($(this).find('.views-widget'));
      });
      $('.form-item-field-wo-cinema-value .bef-select-as-checkboxes').once('huviEvents').click(function (event) {
        //Find all category elements
        var cinemaTab = null,
            categoryTabs = 0;
            categorySelectedTabs = 0;
        $('#edit-field-categories-event-value-i18n-wrapper .form-item').each(function(indx){
          if($(this).find('input').val() == 5) cinemaTab = $(this); //Find Cinema tab
          if($(this).find('input').prop('checked') === true) categorySelectedTabs++; //Count selected categories
          categoryTabs++; //Count total categories
        });

        // Cinema deactivation
        var isCinemaSelected = cinemaTab.find('input').prop('checked');
        var checkboxExcludeCinema = $('.form-item-field-wo-cinema-value .bef-select-as-checkboxes input');
        if(checkboxExcludeCinema.prop('checked') === true) {
          if(categorySelectedTabs === 0 || (categorySelectedTabs === 1 && isCinemaSelected === true)){
            // HUVI-123:
            // 1. No category selected: clicking on the checkbox -> all categories selected except cinema
            // or
            // 4. Only cinema category selected: clicking on the checkbox -> all categories selected except cinema
            $('#edit-field-categories-event-value-i18n-wrapper .form-item input').click();
            if(categorySelectedTabs === 1 && isCinemaSelected === true) cinemaTab.find('input').click();
            cinemaTab.find('label').click();
          } else if(categorySelectedTabs > 1 && isCinemaSelected === true) {
            // HUVI-123: 2. Some categories selected including cinema: clicking on the checkbox -> deselect cinema category
            cinemaTab.find('label').click();
          }
        } else if (categorySelectedTabs > 0 && isCinemaSelected === false) {
          // HUVI-123: 3. Some categories selected except cinema: clicking on the checkbox -> select cinema category
          if(categoryTabs - 1 === categorySelectedTabs){
            $('#edit-field-categories-event-value-i18n-wrapper .form-item input').click();
          }
          cinemaTab.find('label').click();
        }
      });

      if (categoriesOpen ) {
          $('#edit-field-categories-event-value-i18n-wrapper .views-widget').addClass('mobileOpen');
          $('#edit-field-categories-event-value-i18n-wrapper ').addClass('open');
      }
      if (citiesOpen) {
          $('#edit-field-schedule-city-id-value-wrapper .views-widget').addClass('mobileOpen');
          $('#edit-field-schedule-city-id-value-wrapper').addClass('open');
      }
      if (activityCatOpen) {
          $('#edit-field-categories-activity-value-i18n-wrapper .views-widget').addClass('mobileOpen');
          $('#edit-field-categories-activity-value-i18n-wrapper').addClass('open');
      }

      // Toggle "Show all" button on event page.
      $('.schedule-show-all', context).once('huviEvents').click(function () {
        $('.schedule-item').removeClass('schedule-hidden');
        $(this).hide();
      });

      // Toggle buy link
      $(".buy-link", context).once('huviEvents').click(function (event) {
        $(this).parent().parent().children('.buymenu').toggle();
        event.preventDefault();
      });
      // Social links
      $(".social-share", context).once('huviEvents').click(function (event) {

        var socialUrl = '';
        var socialTitle = '';

        // Facebook share
        if ($(this).hasClass('fb-share')) {
          socialUrl = $(this).attr('data-url');
          shareFB(socialUrl);
        }

        // Twitter share
        if ($(this).hasClass('twitter-share')) {
          socialUrl = $(this).attr('data-url');
          socialTitle = $(this).attr('data-title');
          shareTwitter(socialUrl, socialTitle);
        }

        // Google Plus share
        if ($(this).hasClass('google-share')) {
          socialUrl = $(this).attr('data-url');
          shareGoogle(socialUrl);
        }

        event.preventDefault();
      });
      // Reset button
      $('.view-event-listing-fixed .views-exposed-widget.views-reset-button').unbind('click');
      $('.view-event-listing-fixed .views-exposed-widget.views-reset-button').click(clearSelectedFilters);

      // Change free event checkbox text
      if ($('#block-views-event-listing-fixed-events #edit-field-isfree-value-wrapper > label').length > 0 && $('.form-item-field-isfree-value label').length > 0) {
        $('.form-item-field-isfree-value label').text($('#block-views-event-listing-fixed-events #edit-field-isfree-value-wrapper > label').text());
      }
      if ($('#block-views-event-listing-fixed-activities #edit-field-isfree-value-wrapper > label').length > 0 && $('.form-item-field-isfree-value label').length > 0) {
        $('.form-item-field-isfree-value label').text($('#block-views-event-listing-fixed-activities #edit-field-isfree-value-wrapper > label').text());
      }

      showUserLoginPopupBehavior();
      $(window).bind('load resize', function () {
        if (typeof $.fn.colorbox !== 'undefined' &&
                ($(window).width() < 900 || $(window).height() < 600)) {

          $.colorbox.resize({
            height: '95%',
            width: '95%'
          });
        }
      });

    // Google Maps functionallity.
    if ($('#map_canvas').length ) {
    var markers = ($('#map_canvas').attr('data-markers')).split(';').join('|');
    var gmaps_url = Drupal.settings.basePath + 'map.php?markers=' + markers + '&key=' + Drupal.settings.geolocation_googlemaps.geolocation_googlemaps_api_key;

    $('#map_wrapper', context).once('huviEvents').prepend(
            '<a class="map_overlay_button" href="' + gmaps_url +
            '">Näita kaardil</a>'
            );

    if (typeof $.fn.colorbox !== 'undefined') {
      $('.map_overlay_button')
              .addClass('colorbox')
              .addClass('init-colorbox-processed')
              .addClass('cboxElement');

      $('.map_overlay_button').colorbox({
        iframe: true,
        width: '900px',
        height: '600px',
        maxWidth: '95%',
        maxHeight: '95%'
      });
    }

      loadMap();

  }
   if ($(window).width() < 700) {
      $('.normal-top').hide();
    };
  $('.view-advertisement').hover( function() {$('.view-advertisement .views-slideshow-controls-bottom').show()},function() {$('.view-advertisement .views-slideshow-controls-bottom').hide()});
  }
  }

  var currentDate = new Date();
  var dateRangePickerConfig = {
    utoClose: false,
    format: 'DD.MM.YYYY',
    separator: ' - ',
    language: 'et',
    autoClose: false,
    startOfWeek: 'monday',
    alwaysOpen: false,
    startDate: currentDate.getDate() + '.' + (currentDate.getMonth() + 1) + '.' + currentDate.getFullYear(),
    getValue: function ()
    {
      return $(this).val();
    },
    setValue: function (s, s1, s2) {
      if ((s1 == "" && s2 == "") || (typeof s1 === 'undefined' && typeof s2 == 'undefined'))
        this.innerHTML = 'Vali ajavahemik';
      if (s2 == s1) {
        var parts = s1.split(".");
        date = new Date(parts[2], parts[1] - 1, parts[0]);
        this.innerHTML = s1 + ' | ' + getWeekday(date.getDay());
      } else
        this.innerHTML = s;
    },
  };
  var events_date_tabs = {
    "tana": "tana",
    "homme": "homme",
    "reede-kuni-puhapaev": "reede-kuni-puhapaev",
    "sel-kuul": "sel-kuul",
  };

  var events_categoria_tabs = {
    "uritused": {
      "0": "muusika",
      "1": "etendused",
      "2": "naitus-muuseum",
      "3": "mess-laat",
      "4": "sport",
      "5": "kino",
      "6": "ooklubi-pidu",
      "7": "lapsele",
      "8": "varia"
    },
    "huvitegevused": {
      "0": "muusika",
      "1": "kunst-kasitoo",
      "2": "tantsimine",
      "3": "sport-liikumine",
      "4": "tehnika",
      "5": "keeleope",
      "6": "koolitused",
      "8": "varia",
      "7": "lapsele",
      "9": "naitlemine",
      "10": "filmikunst",
      "11": "loodus",
      "12": "robootika",
      "13": "kokandus",
    }
  };
  var events_district_tabs = {
    "2944187": "haabersti",
    "2944191": "kesklinn",
    "2944189": "kristiine",
    "2944190": "lasnamae",
    "2944193": "mustamae",
    "2944194": "nomme",
    "2920234": "pirita",
    "2944195": "pohja-tallinn",
    "2244888": "mujal-eestis"
  };


  /*
   *
   * Check date filters.
   */
  function checkDateFilters(date_tab) {
    switch (date_tab) {
      case "all":
        $('#edit-field-schedule-date-value-min-value-date').val('');
        $('#edit-field-schedule-date-value-max-value-date').val('');
        $('.view-event-listing-fixed').find('.views-submit-button input.form-submit').trigger('click')

        break;
      case "tana":
        var date = new Date();
        $('#edit-field-schedule-date-value-min-value-date').val(formatDate(date));
        $('#edit-field-schedule-date-value-max-value-date').val(formatDate(date));
        $('.view-event-listing-fixed').find('.views-submit-button input.form-submit').trigger('click')
        break;
      case "homme":
        var tomorrow = new Date();
        tomorrow.setDate(tomorrow.getDate() + 1);
        $('#edit-field-schedule-date-value-min-value-date').val(formatDate(tomorrow));
        $('#edit-field-schedule-date-value-max-value-date').val(formatDate(tomorrow));
        $('.view-event-listing-fixed').find('.views-submit-button input.form-submit').trigger('click')
        break;
      case "reede-kuni-puhapaev":
        var date_min = new Date();
        var firstday = date_min.getDate() - (date_min.getDay() - 1) + 4;
        friday = new Date(date_min.setDate(firstday));

        var date_max = new Date();
        var lastday = date_max.getDate() - (date_max.getDay() - 1) + 6;
        var sunday = new Date(date_max.setDate(lastday));
        $('#edit-field-schedule-date-value-min-value-date').val(formatDate(friday));
        $('#edit-field-schedule-date-value-max-value-date').val(formatDate(sunday));
        $('.view-event-listing-fixed').find('.views-submit-button input.form-submit').trigger('click')
        break;
      case "sel-kuul":
        var date = new Date(), y = date.getFullYear(), m = date.getMonth();
        var firstDay = new Date(y, m, 1);
        var lastDay = new Date(y, m + 1, 0);
        $('#edit-field-schedule-date-value-min-value-date').val(formatDate(firstDay));
        $('#edit-field-schedule-date-value-max-value-date').val(formatDate(lastDay));
        $('.view-event-listing-fixed').find('.views-submit-button input.form-submit').trigger('click')

        break;
      default:
        break;
    }
  }

  function formatDate(date) {
    var month = date.getMonth() + 1;
    var day = date.getDate();
    return (day < 10 ? '0' : '') + day + '.' +
            (month < 10 ? '0' : '') + month + '.'
            + date.getFullYear();
  }
  /*
   * Function parse URL and return array with filters tabs
   * @returns {Array}
   */
  function parsePath() {
    var selected_tabs = [];
    var url_parts = getPathParts();
    if (url_parts[0] == "uritused" || url_parts[0] == "huvitegevused") {
      $.each(url_parts, function (key, item) {
        if (item == "uritused" || item == "huvitegevused") {
          selected_tabs = {
            'type': item
          };
        } else if (item in events_date_tabs) {
          selected_tabs['date_tab'] = events_date_tabs[item];
        } else if (item.match(/\d{2}.\d{2}.\d{4}-\d{2}.\d{2}.\d{4}/g)) {
          dates = item.split('-');
          selected_tabs['period'] = {
            'date1': dates[0],
            'date2': dates[1],
          };
        } else if (item.match(/\d{2}.\d{2}.\d{4}/g)) {
          selected_tabs['period'] = {
            'date1': item,
            'date2': item,
          };
        }
      });
      return selected_tabs;
    } else {
      return false;
    }
  }

  /*
   * return URL based on selected filtres
   * @param {type} date_part_url
   * @returns {String}
   */
  function createUrl(date_part_url) {
    var url;
    var url_parts = getPathParts();
    url = '/' + url_parts[0];
    if (typeof date_part_url == 'undefined') {
      date_part_url = $('.quicktabs-tabs').find('li.active a').attr('id');
      if (date_part_url == 'date-period') {
        date1 = $('#edit-field-schedule-date-value-min-value-date').val();
        date2 = $('#edit-field-schedule-date-value-max-value-date').val()
        if (date1 == date2) {
          date_part_url = date1;
        } else {
          date_part_url = date1 + '-' + date2;
        }
      }
      if (date_part_url == 'all') {
        date_part_url = "";
      }
    }
    if (date_part_url != undefined && date_part_url.length > 0) {
      url = url + '/' + date_part_url;
    }
    var districts = [];
    ;
    categoria_field = 'form-item-field-categories-event-value-i18n';
    exposed_form_id = 'views-exposed-form-event-listing-fixed-events';

    if (url_parts[0] == 'huvitegevused') {
      categoria_field = 'form-item-field-categories-activity-value-i18n';
      exposed_form_id = 'views-exposed-form-event-listing-fixed-activities';
    }
    $('#' + exposed_form_id + ' .form-item-field-schedule-city-id-value .bef-select-as-checkboxes .form-item').each(function () {
      if ($(this).find('input').is(':checked')) {
        value = $(this).find('input').val();
        districts.push(events_district_tabs[value]);
      }
    });
    if (districts.length > 0) {
      url = url + '/' + districts.join('_');
    }

    var categories = [];
   $('#' + exposed_form_id + ' .' + categoria_field + ' .bef-select-as-checkboxes .form-item').each(function () {
      if ($(this).find('input').is(':checked')) {
        value = $(this).find('input').val();
        categories.push(events_categoria_tabs[url_parts[0]][value]);
      }
    });
    if (url_parts[0] == 'huvitegevused') {
      $('#' + exposed_form_id + ' .form-item-field-categories-activity-value-i18n-muu .bef-select-as-checkboxes .form-item').each(function () {
        if ($(this).find('input').is(':checked')) {
          value = $(this).find('input').val();
          categories.push(events_categoria_tabs[url_parts[0]][value]);
        }
      });
    }
    if (categories.length > 0)
      url = url + '/' + categories.join('_');
    return url;
  }

  function showUserLoginPopupBehavior() {
    $('.openid-ee-button.form-submit').parent().wrap('<form id="openid_ee_custom_login" action="user/login" method="POST"></form>');
    $('#openid_ee_custom_login').appendTo('#modal-content');
    $('#id-card-button').appendTo('#modal-content');
    $('#mobile-id-button').appendTo('#modal-content');

    if ($(".messages--error").length) {
      $(".messages--error").insertBefore($("#modalContent #div_logi_sisse .form-actions"));
      $("#modalContent #div_logi_sisse").show();
    }
    if ($("#modalContent #div_logi_sisse").is(':hidden'))
      $('#modalContent').height($('#modalContent').height() - $("#modalContent #div_logi_sisse").height() + $("p.info").height());
    $('#huvi-loader').remove();
  }

  function mobileCloseAll() {
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
    if ($(window).width() < 704) {
      if (el.hasClass('mobileOpen')) {
        el.removeClass('mobileOpen');
        el.parent().removeClass('open');
      } else {
        mobileCloseAll();
        el.addClass('mobileOpen');
        el.parent().addClass('open');
      }
    }
  }

  $(document).ready(function () {
    if ($("#date-period").length) {
      addDateRangePicker("#date-period");
    }
    var url_parts = parsePath();
    // Apply date filters
    if (url_parts) {
      if (typeof url_parts['date_tab'] !== 'undefined') {
        $('ul.quicktabs-tabs li.active').removeClass('active');
        $('#' + url_parts['date_tab']).parent('li').addClass('active');
        switch (url_parts['date_tab']) {

          case "tana":
            var date = new Date();
            $('#edit-field-schedule-date-value-min-value-date').val(formatDate(date));
            $('#edit-field-schedule-date-value-max-value-date').val(formatDate(date));
            break;
          case "homme":
            var tomorrow = new Date();
            tomorrow.setDate(tomorrow.getDate() + 1);
            $('#edit-field-schedule-date-value-min-value-date').val(formatDate(tomorrow));
            $('#edit-field-schedule-date-value-max-value-date').val(formatDate(tomorrow));
            break;
          case "reede-kuni-puhapaev":
            var date_min = new Date();
            var firstday = date_min.getDate() - (date_min.getDay() - 1) + 4;
            friday = new Date(date_min.setDate(firstday));

            var date_max = new Date();
            var lastday = date_max.getDate() - (date_max.getDay() - 1) + 6;
            var sunday = new Date(date_max.setDate(lastday));
            $('#edit-field-schedule-date-value-min-value-date').val(formatDate(friday));
            $('#edit-field-schedule-date-value-max-value-date').val(formatDate(sunday));
            break;
          case "sel-kuul":
            var date = new Date(), y = date.getFullYear(), m = date.getMonth();
            var firstDay = new Date(y, m, 1);
            var lastDay = new Date(y, m + 1, 0);
            $('#edit-field-schedule-date-value-min-value-date').val(formatDate(firstDay));
            $('#edit-field-schedule-date-value-max-value-date').val(formatDate(lastDay));

            break;
        }
      }
      if (typeof url_parts['period'] !== 'undefined') {
        $('#date-period').data('dateRangePicker').setDateRange(url_parts['period']['date1'], url_parts['period']['date2']);
        $('#edit-field-schedule-date-value-max-value-date').attr('value', url_parts['period']['date2']);
        $('#edit-field-schedule-date-value-min-value-date').attr('value', url_parts['period']['date1']);
        $('ul.quicktabs-tabs li.active').removeClass('active');
        $('#date-period').parent('li').addClass('active');
      }
    }
  });

  var categoriesOpen;
  var citiesOpen;
  var activityCatOpen;
  $(document).ajaxStart(function () {
    if ($('#edit-field-categories-event-value-i18n-wrapper .views-widget').hasClass('mobileOpen')) {
      categoriesOpen = true;
    } else {
      categoriesOpen = false;
    }
    if ($('#edit-field-categories-activity-value-i18n-wrapper .views-widget').hasClass('mobileOpen')) {
      activityCatOpen = true;
    } else {
      activityCatOpen = false;
    }
    if ($('#edit-field-schedule-city-id-value-wrapper .views-widget').hasClass('mobileOpen')) {
      citiesOpen = true;
    } else {
      citiesOpen = false;
    }
    if ($('.quicktabs-tabs li').hasClass('mobileOpen')) {
      citiesOpen = false;
      categoriesOpen = false;
      activityCatOpen = false;
    }
    $('#huvi-loader').remove();
    $('.view-event-listing-fixed .views-exposed-form input[name="combine"]').after('<div id="huvi-loader"></div>');
  });

  function clearSelectedFilters(event) {
    event.preventDefault(event);
    setCookie("last_tab_huvi", "");
    setCookie("last_tab_uri", "");
    $('.form-item input:checked').each(function () {
      $(this).prop('checked', false);
    });

    $('#edit-field-schedule-date-value-min-value-date').val("");
    $('#edit-field-schedule-date-value-max-value-date').val("");
    $('ul.quicktabs-tabs li.active').removeClass('active');
    $("#all").parent('li').addClass('active');
    url_path = createUrl();
    window.history.pushState({urlPath: url_path}, "", url_path);
    $.ajax({
      type: 'POST',
      url: Drupal.settings.basePath + 'ajax/events_filters_reset',
      success: function () {
        location.reload();
      }
    });
  }
  function addDateRangePicker(el) {
    $(el).dateRangePicker(dateRangePickerConfig)
            .bind('datepicker-apply', function (event, obj) {
              var url_parts = getPathParts();
              if (obj.date2 == 'Invalid Date' || obj.date2 == obj.date1) {
                obj.date2 = obj.date1;
                url_date_part = (obj.date1.getDate() < 10 ? '0' + obj.date1.getDate() : obj.date1.getDate()) + '.' + ((obj.date1.getMonth() + 1) < 10 ? '0'
                        + (obj.date1.getMonth() + 1) : (obj.date1.getMonth() + 1)) + '.' + obj.date1.getFullYear();
                obj.value = (obj.date1.getDate() < 10 ? '0' + obj.date1.getDate() : obj.date1.getDate()) + '.' + ((obj.date1.getMonth() + 1) < 10 ? '0'
                        + (obj.date1.getMonth() + 1) : (obj.date1.getMonth() + 1)) + '.' + obj.date1.getFullYear()
                        + ' | ' + getWeekday(obj.date1.getDay());

              } else {
                url_date_part = (obj.date1.getDate() < 10 ? '0' + obj.date1.getDate() : obj.date1.getDate()) + '.' + ((obj.date1.getMonth() + 1) < 10 ? '0'
                        + (obj.date1.getMonth() + 1) : (obj.date1.getMonth() + 1)) + '.' + obj.date1.getFullYear()
                        + '-' + (obj.date2.getDate() < 10 ? '0' + obj.date2.getDate() : obj.date2.getDate()) + '.' + ((obj.date2.getMonth() + 1) < 10 ? '0'
                        + (obj.date2.getMonth() + 1) : (obj.date2.getMonth() + 1)) + '.' + obj.date2.getFullYear()
              }

              $('#edit-field-schedule-date-value-max-value-date').val(obj.date2.getDate() + '.' + (obj.date2.getMonth() + 1) + '.' + obj.date2.getFullYear());
              $('#edit-field-schedule-date-value-min-value-date').val(obj.date1.getDate() + '.' + (obj.date1.getMonth() + 1) + '.' + obj.date1.getFullYear());
              this.innerHTML = obj.value;
              $('.view-event-listing-fixed').find('.views-submit-button input.form-submit').trigger('click');
              url_path = createUrl(url_date_part);
              window.history.pushState({urlPath: url_path}, "", url_path);
            })
            .bind('datepicker-first-date-selected', function (event, obj) {
              var button = $('.apply-btn');
              button.addClass('enabled');
              obj.value = (obj.date1.getDate() < 10 ? '0' + obj.date1.getDate() : obj.date1.getDate()) + '.' + ((obj.date1.getMonth() + 1) < 10 ? '0'
                      + (obj.date1.getMonth() + 1) : (obj.date1.getMonth() + 1)) + '.' + obj.date1.getFullYear()
                      + ' | ' + getWeekday(obj.date1.getDay());
              this.innerHTML = obj.value;
            })
  }

  function getWeekday(day) {
    var weekdays = ['Pühapäev', 'Esmaspäev', 'Teisipäev', 'Kolmapäev', 'Neljapäev', 'Reede', 'Laupäev'];
    return weekdays[day];
  }

  (function () {
    window.addEventListener("resize", actualResizeHandler, false);
    function actualResizeHandler() {
      if ($(window).width() < 704) {
        if ($('.quicktabs-tabpage.now-active #edit-field-categories-activity-value-i18n-muu-wrapper fieldset').hasClass('collapsed')) {
          $('.quicktabs-tabpage.now-active #edit-field-categories-activity-value-i18n-wrapper .views-widget').removeClass('mobileOpen');
          $('.quicktabs-tabpage.now-active #edit-field-categories-activity-value-i18n-wrapper').removeClass('open');
        } else {
          $('.quicktabs-tabpage.now-active #edit-field-categories-activity-value-i18n-wrapper .views-widget').addClass('mobileOpen');
        }
      } else {
        if ($('#quicktabs-aeg_huvitegevus ul.quicktabs-tabs').hasClass('open')) {
          $('#quicktabs-aeg_huvitegevus ul.quicktabs-tabs').removeClass('open');
          $('#quicktabs-aeg_huvitegevus ul.quicktabs-tabs li').removeClass('mobileOpen');
        }
        if ($('#quicktabs-event_quicktabs_for_date_range_s ul.quicktabs-tabs').hasClass('open')) {
          $('#quicktabs-event_quicktabs_for_date_range_s ul.quicktabs-tabs').removeClass('open');
          $('#quicktabs-event_quicktabs_for_date_range_s ul.quicktabs-tabs li').removeClass('mobileOpen');
        }
      }
    }
  }());

  function initWoCinemaCheckboxState(){
    //Find all category elements
    var cinemaTab = null,
    categorySelectedTabs = 0;
    $('#edit-field-categories-event-value-i18n-wrapper .form-item').each(function(indx){
      if($(this).find('input').val() == 5) cinemaTab = $(this); //Find Cinema tab
      if($(this).find('input').prop('checked') === true) categorySelectedTabs++; //Count selected categories
    });

    var isCinemaSelected = cinemaTab.find('input').prop('checked');
    var checkboxExcludeCinema = $('.form-item-field-wo-cinema-value .bef-select-as-checkboxes input');
    // HUVI-123
    if (categorySelectedTabs === 0 || isCinemaSelected) {
      checkboxExcludeCinema.prop('checked', false);
    } else if(categorySelectedTabs > 0 && !isCinemaSelected) {
      console.log(categorySelectedTabs, isCinemaSelected);
      checkboxExcludeCinema.prop('checked', true);
    }
  }

  function changeWoCinemaCheckboxParent() {
    const woCinemaValueCheckBox = document.querySelector(".form-item-field-wo-cinema-value")
    const editFieldIsfreeValueWrapper = document.querySelector("#edit-field-isfree-value-wrapper")

    if(woCinemaValueCheckBox && editFieldIsfreeValueWrapper) {
      editFieldIsfreeValueWrapper.appendChild(woCinemaValueCheckBox);
    }
  }

  window.addEventListener('DOMContentLoaded', (event) => {
    changeWoCinemaCheckboxParent();
    initWoCinemaCheckboxState();
  });

  $(window).ajaxComplete(function() {
    changeWoCinemaCheckboxParent();
    initWoCinemaCheckboxState();
  });

})(jQuery);

function fbShare(url, title, descr, image, winWidth, winHeight) {
  var winTop = (screen.height / 2) - (winHeight / 2);
  var winLeft = (screen.width / 2) - (winWidth / 2);
  window.open('//www.facebook.com/sharer.php?s=100&p[title]=' + title + '&p[summary]=' + descr + '&p[url]=' + url + '&p[images][0]=' + image, 'sharer', 'top=' + winTop + ',left=' + winLeft + ',toolbar=0,status=0,width=' + winWidth + ',height=' + winHeight);
}

function shareFB(url) {

  var winWidth = 626;
  var winHeight = 436;

  var winTop = (screen.height / 2) - (winHeight / 2);
  var winLeft = (screen.width / 2) - (winWidth / 2);

  window.open('//www.facebook.com/sharer/sharer.php?u=' + encodeURIComponent(url), 'facebook-share-dialog', 'top=' + winTop + ',left=' + winLeft + ',width=' + winWidth + ',height=' + winHeight + ',toolbar=0,status=0');
}


function shareTwitter(url, title) {
  var winWidth = 626;
  var winHeight = 436;

  var winTop = (screen.height / 2) - (winHeight / 2);
  var winLeft = (screen.width / 2) - (winWidth / 2);

  window.open('//twitter.com/share?url=' + encodeURIComponent(url) + '&text=' + encodeURIComponent(title), 'twitter-share-dialog', 'top=' + winTop + ',left=' + winLeft + ',width=' + winWidth + ',height=' + winHeight + ',toolbar=0,status=0');
}


function shareGoogle(url) {
  var winWidth = 626;
  var winHeight = 436;

  var winTop = (screen.height / 2) - (winHeight / 2);
  var winLeft = (screen.width / 2) - (winWidth / 2);

  window.open('//plus.google.com/share?url=' + encodeURIComponent(url), 'facebook-share-dialog', 'top=' + winTop + ',left=' + winLeft + ',width=' + winWidth + ',height=' + winHeight + ',toolbar=0,status=0');
}


function loadMap() {
  // Asynchronously Load the map API
  var script = document.createElement('script');
  var geolocation_googlemaps_api_key = Drupal.settings.geolocation_googlemaps.geolocation_googlemaps_api_key;
  script.type = 'text/javascript';
  script.src = "//maps.googleapis.com/maps/api/js?sensor=false&key=" + geolocation_googlemaps_api_key + "&callback=initialize";
  document.body.appendChild(script);
}


function initialize() {
  var map;

  var markers_attr = jQuery('#map_canvas').attr('data-markers').split(';');
  var markers = [];
  jQuery.each(markers_attr, function (i, val) {
    markers[i] = val.split(',');

  });

  var bounds = new google.maps.LatLngBounds();
  var mapOptions = {
    mapTypeId: 'roadmap',
    streetViewControl: true,
    zoom: 15
  };

  // Display a map on the page
  map = new google.maps.Map(document.getElementById("map_canvas"), mapOptions);
  map.setTilt(45);

  // Display multiple markers on a map
  var infoWindow = new google.maps.InfoWindow(), marker, i;

  // Loop through our array of markers & place each one on the map
  for (i = 0; i < markers.length; i++) {
    var position = new google.maps.LatLng(markers[i][0], markers[i][1]);
    bounds.extend(position);
    marker = new google.maps.Marker({
      position: position,
      map: map
    });

    map.initialZoom = true;

    // Automatically center the map fitting all markers on the screen
    map.fitBounds(bounds);
  }


  google.maps.event.addListener((map), 'zoom_changed', function () {
    var zoomChangeBoundsListener = google.maps.event.addListener((map), 'bounds_changed', function (event) {
      if (this.getZoom() > 20 && this.initialZoom == true) {
        // Change max/min zoom here
        this.setZoom((markers.length == 1) ? 17 : 15);
        this.initialZoom = false;
      }

      google.maps.event.removeListener(zoomChangeBoundsListener);
    });
  });
}

function setCookie(cname, cvalue) {
  document.cookie = cname + "=" + cvalue;
}

function getCookie(cname) {
  var name = cname + "=";
  var ca = document.cookie.split(';');
  for (var i = 0; i < ca.length; i++) {
    var c = ca[i];
    while (c.charAt(0) == ' ') {
      c = c.substring(1);
    }
    if (c.indexOf(name) == 0) {
      return c.substring(name.length, c.length);
    }
  }
  return "";
}

function remapBackButton(url) {
  if (window.history && window.history.pushState) {
    window.history.pushState('forward', null, '');
    window.addEventListener('popstate', function () {
      window.location.href = url;
    });
  }
}

function getPathParts() {
  var pathname = location.pathname;
  pathname = pathname.substring(1, pathname.length);
  return pathname.split('/');
}
