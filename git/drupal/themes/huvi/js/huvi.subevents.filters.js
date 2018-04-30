/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
(function ($) {

  var filter_type;
  var type = [];
  var district = [];
  var date = [];
  var start_date = null;
  var end_date = null;
  var currentDate = new Date();
  var isOnFiltersList = false;
  var dateRangePickerConfig = {
    autoClose: false,
    format: 'DD/MM/YYYY',
    separator: ' - ',
    language: 'et',
    autoClose: false,
    startOfWeek: 'monday',
    alwaysOpen: false,
    startDate: currentDate.getDate() + '/' + (currentDate.getMonth() + 1) + '/' + currentDate.getFullYear(),
    getValue: function ()
    {
      return $(this).val();
    },
  }
  function clearArray(array) {
    while (array.length) {
      array.pop();
    }
  }
  function getWeekday(day) {
    var weekdays = ['Pühapäev', 'Esmaspäev', 'Teisipäev', 'Kolmapäev', 'Neljapäev', 'Reede', 'Laupäev'];
    return weekdays[day];
  }
  function getActiveFilters() {
    clearArray(date);
    clearArray(type);
    clearArray(district);

    $('input:checkbox.filter-checkbox').each(function () {
      if (this.checked) {
        filter_type = $(this).parents('.subevents-filter').attr('id');
        if (filter_type == 'type') {
          type.push($(this).val());
        } else if (filter_type == 'district') {
          district.push($(this).val());

        }
      }
    });
    $('input:radio.filter-radio').each(function () {
      if (this.checked) {

        date.push($(this).val());

      }


    });

  }
  /* function getActiveFiltersOLD() {
   clearArray(date);
   clearArray(type);
   clearArray(district);
   $('ul.subevent-filter-tabs li.active').each(function (index, value) {
   if (!$(this).hasClass('label')) {
   filter_type = $(this).parents('ul.subevent-filter-tabs').attr('id');
   if (filter_type == 'type') {
   type.push($(this).children('a').attr('id'));
   } else if (filter_type == 'district') {
   district.push($(this).children('a').attr('id'));
   } else if (filter_type == 'date') {
   date.push($(this).children('a').attr('id'));
   }
   }
   ;
   });
   }*/
  function updateSubevents(nodeID) {
    $('#modal_loader').show();
    $.ajax({
      type: 'POST',
      url: '/subevents/get/ajax',
      data: {filters: {date, type, district}, nid: nodeID, start_date: start_date, end_date: end_date},
      dataType: "html", // Type of the content we're expecting in the response
      success: function (data) {
        // alert(data.children('.event-group'));
        $('#sub_events').html(data);  // Place AJAX content inside the ajax wrapper div
        $('#modal_loader').hide();
      }
    });
  }
  function subeventsFilterMobileCloseAll() {
    $('ul.subevent-filter-tabs').removeClass('open');
    $('ul.subevent-filter-tabs li').removeClass('mobileOpen');
  }
  function subeventsFilterMobileClick(el) {
    var is_opened = el.hasClass('open');

    subeventsFilterMobileCloseAll();
    if (is_opened == false) {
      el.addClass('open');
      el.find('li').each(function (index, value) {
        if ($(this).hasClass('label') == false) {
          $(this).addClass('mobileOpen');
        }
      });
    } else {
      el.removeClass('open');
    }
  }
  Drupal.behaviors.subevents = {attach: function () {
      $('.subevents-filter-list').mouseenter(function () {
        isOnFiltersList = true;
      });
      
      
      $('.subevents-filter-list').mouseleave(function () {
        isOnFiltersList = false;

      });


      $('.subevents-filter-input input').focus(function () {
        if($(this).attr('id') == 'start_date' || $(this).attr('id') == 'end_date') {
          return;
        }
        filter_id = $(this).parents('.subevents-filter').attr('id');
        $('.subevents-filter').each(function () {
          if ($(this).attr('id') != filter_id) {
            $(this).find('.subevents-filter-list').hide();
          }
        });
        $(this).parent('.subevents-filter-input').find('.subevents-filter-list').show();
      });
      $('.subevents-filter-input').click(function () {
        if ($(this).children('input').is(':focus')) {
          return;
        }
        if($(this).find('.subevents-filter-list').css('display') == 'block' && isOnFiltersList == false) {
          $(this).find('.subevents-filter-list').hide()
        }
        else {
          $(this).find('.subevents-filter-textbox').focus();
      }
        
      });

      $('.check-all-filters-link').click(function (e) {
        e.preventDefault();
        selectList = $(this).parents('.subevents-filter-list');
        selectList.find('.regular-checkbox').prop('checked', true);
        getActiveFilters();
        parent_node_array = $(this).parents('.subevents-block').attr('id').split("-");
        updateSubevents(parent_node_array[1]);
      });
      $('.uncheck-all-filters-link').click(function (e) {
        e.preventDefault();
        selectList = $(this).parents('.subevents-filter-list');
        selectList.find('.regular-checkbox').prop('checked', false);
        getActiveFilters();
        parent_node_array = $(this).parents('.subevents-block').attr('id').split("-");
        updateSubevents(parent_node_array[1]);
      });
      $(window).click(function () {
        if ($(".subevents-filter-input input").is(":focus") || isOnFiltersList) {

        } else {
          $('.subevents-filter-list').hide();
        }
      });

      $('.filter-checkbox').change(function (e) {

        getActiveFilters();
        parent_node_array = $(this).parents('.subevents-block').attr('id').split("-");
        updateSubevents(parent_node_array[1]);
        return false;
      });
      $('#end_date').focus(function () {
        $('#period').click();
      });
      $('#start_date').focus(function () {
        $('#period').click();
      });
      $('.filter-radio').change(function (e) {
       
        if ($(this).val() == 'period')
          return;
        getActiveFilters();
        parent_node_array = $(this).parents('.subevents-block').attr('id').split("-");
        updateSubevents(parent_node_array[1]);
        $('.subevents-filter-list').hide();
        return false;
      });
      if ($('#period').length) {
        $('#period').dateRangePicker(dateRangePickerConfig)
                .bind('datepicker-opened', function (event, obj) {
                  $('#period .filter-radio').prop('checked', true);
                })
                
                .bind('datepicker-apply', function (event, obj) {
                  console.log(obj);
                  if (obj.date2 == 'Invalid Date' || obj.date2 == obj.date1) {
                    obj.date2 = obj.date1;
                    $('#end_date').val('');
                    $('#start_date').val((obj.date1.getDate() < 10 ? '0' + obj.date1.getDate() : obj.date1.getDate()) + '/' + ((obj.date1.getMonth() + 1) < 10 ? '0':'') + (obj.date1.getMonth() + 1) + '/' + obj.date1.getFullYear().toString().substr(2, 2));
                    
                  }
                  else {
                    $('#start_date').val((obj.date1.getDate() < 10 ? '0' + obj.date1.getDate() : obj.date1.getDate()) + '/' + ((obj.date1.getMonth() + 1) < 10 ? '0':'') + (obj.date1.getMonth() + 1) + '/' + obj.date1.getFullYear().toString().substr(2, 2));
                    $('#end_date').val((obj.date2.getDate() < 10 ? '0' + obj.date2.getDate() : obj.date2.getDate()) + '/' + ((obj.date1.getMonth() + 1) < 10 ? '0' : '') + (obj.date2.getMonth() + 1) + '/' + obj.date2.getFullYear().toString().substr(2, 2));
                  }
                  
                  start_date = obj.date1.getDate() + '.' + (obj.date1.getMonth() + 1) + '.' + obj.date1.getFullYear() + ' 00:00:00';
                  end_date = obj.date2.getDate() + '.' + (obj.date2.getMonth() + 1) + '.' + obj.date2.getFullYear() + ' 23:59:59';

                  getActiveFilters();
                  parent_node_array = $(this).parents('.subevents-block').attr('id').split("-");
                  $('#modal_loader').show();
                  $.ajax({
                    type: 'POST',
                    url: '/subevents/get/ajax',
                    data: {filters: {date, type, district}, nid: parent_node_array[1], start_date: start_date, end_date: end_date},
                    dataType: "html", // Type of the content we're expecting in the response
                    success: function (data) {
                      // alert(data.children('.event-group'));
                      $('#sub_events').html(data);  // Place AJAX content inside the ajax wrapper div
                      $('#modal_loader').hide();
                      $('.subevents-filter-list').hide();
                    }
                  });
                })
        /*OLD
         * $('#period').dateRangePicker(dateRangePickerConfig)
         .bind('datepicker-apply', function (event, obj) {
         if (obj.date2 == 'Invalid Date' || obj.date2 == obj.date1) {
         obj.date2 = obj.date1;
         obj.value = (obj.date1.getDate() < 10 ? '0' + obj.date1.getDate() : obj.date1.getDate()) + '.' + ((obj.date1.getMonth() + 1) < 10 ? '0'
         + (obj.date1.getMonth() + 1) : (obj.date1.getMonth() + 1)) + '.' + obj.date1.getFullYear()
         + ' | ' + getWeekday(obj.date1.getDay());
         }
         this.innerHTML = obj.value;
         start_date = obj.date1.getDate() + '.' + (obj.date1.getMonth() + 1) + '.' + obj.date1.getFullYear() + ' 00:00:00';
         end_date = obj.date2.getDate() + '.' + (obj.date2.getMonth() + 1) + '.' + obj.date2.getFullYear() + ' 23:59:59';
         
         getActiveFilters();
         parent_node_array = $(this).parents('.subevents-block').attr('id').split("-");
         $('#modal_loader').show();
         $.ajax({
         type: 'POST',
         url: '/subevents/get/ajax',
         data: {filters: {date, type, district}, nid: parent_node_array[1], start_date: start_date, end_date: end_date},
         dataType: "html", // Type of the content we're expecting in the response
         success: function (data) {
         // alert(data.children('.event-group'));
         $('#sub_events').html(data);  // Place AJAX content inside the ajax wrapper div
         $('#modal_loader').hide();
         }
         });
         })*/

      }
      /*$('a.subevent-filter-tab').click(function (e) {
        e.preventDefault();

        filter_type = $(this).parents('ul.subevent-filter-tabs').attr('id');
        if (filter_type == 'date') {
          $(this).parents('ul.subevent-filter-tabs').children('li').each(function () {
            $(this).removeClass('active')
          });
          if ($(this).attr('id') != 'period') {
            start_date = null;
            end_date = null;
          }
        }

        $(this).parent('li').toggleClass('active');
        if ($(this).attr('id') == 'period')
          return false;


        getActiveFilters();
        parent_node_array = $(this).parents('.subevents-block').attr('id').split("-");
        $('#modal_loader').show();
        $.ajax({
          type: 'POST',
          url: '/subevents/get/ajax',
          data: {filters: {date, type, district}, nid: parent_node_array[1], start_date: start_date, end_date: end_date},
          dataType: "html", // Type of the content we're expecting in the response
          success: function (data) {
            // alert(data.children('.event-group'));
            $('#sub_events').html(data);  // Place AJAX content inside the ajax wrapper div
            $('#modal_loader').hide();
          }
        });
        return false;
      });
      $('ul.subevent-filter-tabs li.label').click(function () {
        subeventsFilterMobileClick($(this).parent());
      })*/
    }
  };
})(jQuery);