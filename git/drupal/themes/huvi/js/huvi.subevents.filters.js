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
  function updateSubevents(nodeID) {
    $('#modal_loader').show();
    $.ajax({
      type: 'POST',
      url: '/subevents/get/ajax',
      data: {filters: {date, type, district}, nid: nodeID, start_date: start_date, end_date: end_date},
      dataType: "html", // Type of the content we're expecting in the response
      success: function (data) {
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
          return false;
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
        filter_input = $(this).parents('.subevents-filter').find('.subevents-filter-textbox');
        filter_input.val(filter_input.attr('label'));
        selectList = $(this).parents('.subevents-filter-list');
        selectList.find('.regular-checkbox').prop('checked', true);
        getActiveFilters();
        parent_node_array = $(this).parents('.subevents-block').attr('id').split("-");
        updateSubevents(parent_node_array[1]);
      });
      $('.uncheck-all-filters-link').click(function (e) {
        e.preventDefault();

        filter_input = $(this).parents('.subevents-filter').find('.subevents-filter-textbox');
        filter_input.val(filter_input.attr('label'));
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
        var select_values = [];
        select_list = $(this).parents('.subevents-filter');
        checkboxes_count = select_list.find('.subevents-filter-list input').length;
        checked_checkboxes = select_list.find('.subevents-filter-list input:checked').length;
        filter_input = select_list.find('.subevents-filter-textbox');

        if (checkboxes_count == checked_checkboxes ||  checked_checkboxes == 0) {
          filter_input.val(filter_input.attr('label'));
        }
        else{
          select_list.find('input:checkbox.filter-checkbox:checked').each(function () {
            select_values.push($(this).attr('label'));
          });
          filter_input.val(select_values.join(', '));
        }
        checkboxes =  select_list.find('.subevents-filter-list');
        getActiveFilters();
        parent_node_array = $(this).parents('.subevents-block').attr('id').split("-");
        updateSubevents(parent_node_array[1]);
        return false;
      });
      $('.filter-radio').change(function (e) {
        if ($(this).val() == 'period') {
           return;
        }
         filter_input = $(this).parents('.subevents-filter').find('.subevents-filter-textbox');
        filter_input.val($(this).attr('label'));
        getActiveFilters();
        parent_node_array = $(this).parents('.subevents-block').attr('id').split("-");
        updateSubevents(parent_node_array[1]);
        $('.subevents-filter-list').hide();
        $(filter_input).blur();
        return;
      });
      if ($('#period').length) {
        $('#period').dateRangePicker(dateRangePickerConfig)
                .bind('datepicker-opened', function (event, obj) {
                  $('#period .filter-radio').prop('checked', true);
                })

                .bind('datepicker-apply', function (event, obj) {
                  if (obj.date2 == 'Invalid Date' || obj.date2 == obj.date1) {
                    obj.date2 = obj.date1;
                    $('#end_date').val('');
                    $('#start_date').val((obj.date1.getDate() < 10 ? '0' + obj.date1.getDate() : obj.date1.getDate()) + '/' + ((obj.date1.getMonth() + 1) < 10 ? '0':'') + (obj.date1.getMonth() + 1) + '/' + obj.date1.getFullYear().toString().substr(2, 2));
                    obj.value = (obj.date1.getDate() < 10 ? '0' +obj.date1.getDate() : obj.date1.getDate()) + '.' + ((obj.date1.getMonth()+1) < 10 ? '0'
                       + (obj.date1.getMonth()+1) : (obj.date1.getMonth()+1)) + '.' + obj.date1.getFullYear()
                       + ' | ' + getWeekday(obj.date1.getDay());
                            }
                  else {

                    $('#start_date').val((obj.date1.getDate() < 10 ? '0' + obj.date1.getDate() : obj.date1.getDate()) + '/' + ((obj.date1.getMonth() + 1) < 10 ? '0':'') + (obj.date1.getMonth() + 1) + '/' + obj.date1.getFullYear().toString().substr(2, 2));
                    $('#end_date').val((obj.date2.getDate() < 10 ? '0' + obj.date2.getDate() : obj.date2.getDate()) + '/' + ((obj.date1.getMonth() + 1) < 10 ? '0' : '') + (obj.date2.getMonth() + 1) + '/' + obj.date2.getFullYear().toString().substr(2, 2));
                  }

                  start_date = obj.date1.getDate() + '.' + (obj.date1.getMonth() + 1) + '.' + obj.date1.getFullYear() + ' 00:00:00';
                  end_date = obj.date2.getDate() + '.' + (obj.date2.getMonth() + 1) + '.' + obj.date2.getFullYear() + ' 23:59:59';
                  $('#date .subevents-filter-textbox').val(obj.value);
                  getActiveFilters();
                  parent_node_array = $(this).parents('.subevents-block').attr('id').split("-");
                  $('#modal_loader').show();
                  $.ajax({
                    type: 'POST',
                    url: '/subevents/get/ajax',
                    data: {filters: {date, type, district}, nid: parent_node_array[1], start_date: start_date, end_date: end_date},
                    dataType: "html", // Type of the content we're expecting in the response
                    success: function (data) {
                      $('#sub_events').html(data);  // Place AJAX content inside the ajax wrapper div
                      $('#modal_loader').hide();
                      $('.subevents-filter-list').hide();
                    }
                  });
                })
       }
      }
  };
})(jQuery);