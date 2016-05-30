(function ($) {
  Drupal.behaviors.kultuurikava_search = {
    attach: function (context, settings) {
      $('.form-item.form-type-radios.form-item-time').click(function(){
        $(this).toggleClass('open');
      });
      
      
      // Click on time radio button label
      $('#edit-time .form-item-time label').click(function(event) {
        // Get input ID
        var inputID = '#' + $(this).attr('for');
        
        // Check if input is checked
        if($(inputID).is(':checked')) {
          event.preventDefault();
          
          // Uncheck
          $(inputID).removeAttr('checked');
          
          // Autosubmit
          var form_id = '#' + $(this).parents('form:first').attr('id');
          
          setTimeout(function(){
            console.log('click');
            $(form_id, context).once('kultuurikava_search').submit();
          }, 1000);
          
        }
        
        
      });
      
      
      $('.form-item.form-type-checkboxes.form-item-category').click(function(){
        $(this).toggleClass('open');
      });
      $('.form-item.form-type-checkboxes.form-item-region').click(function(){
        $(this).toggleClass('open');
      });
      $('#events_search_form .form-item-region input').each(function(index){
        if($(this).is(':checked')){
          $(this).parent().addClass('active');
          $(this).parents().addClass('open');
          if(index == 0){
            $(this).parents().addClass('active');
          }
        }
      });
      $('#events_search_form .form-item-category input').each(function(index){
        if($(this).is(':checked')){
          $(this).parent().addClass('active');
          $(this).parents().addClass('open');
            if(index == 0){
            $(this).parents().addClass('active');
          }
        }
      });
      $('#events_search_form .form-item-time input').each(function(index){
        if($(this).is(':checked')){
          $(this).parent().addClass('active');
          $(this).parents().addClass('open');
          if(index == 0){
            $(this).parents().addClass('active');
          }
        }
      });
      
      // Auto submit

      var autoSubmit;
      var delay = 800;

      $('#events_search_form .form-item-time input:radio').change(
        function(){
          var form_id = '#' + $(this).parents('form:first').attr('id');
          //$(form_id, context).once('kultuurikava_search').delay(10000).submit();

          clearTimeout(autoSubmit);
          autoSubmit = setTimeout(function(){
            $('body').addClass('wait');
            $(form_id, context).once('kultuurikava_search').submit();
          }, delay);
        }
      );
      
      $('#events_search_form .form-item-region input:checkbox').change(
        function(){
          var form_id = '#' + $(this).parents('form:first').attr('id');
          //$(form_id, context).once('kultuurikava_search').delay(10000).submit();

          clearTimeout(autoSubmit);
          autoSubmit = setTimeout(function(){
            $('body').addClass('wait');
            $(form_id, context).once('kultuurikava_search').submit();
          }, delay);
        }
      );
    
      $('#events_search_form .form-item-free input:checkbox').change(
        function(){
          var form_id = '#' + $(this).parents('form:first').attr('id');
          //$(form_id, context).once('kultuurikava_search').delay(10000).submit();
          
          clearTimeout(autoSubmit);
          autoSubmit = setTimeout(function(){
            $('body').addClass('wait');
            $(form_id, context).once('kultuurikava_search').submit();
          }, delay);
        }
      );
    
      $('#events_search_form .form-item-category input:checkbox').change(
        function(){
          var form_id = '#' + $(this).parents('form:first').attr('id');
          //$(form_id, context).once('kultuurikava_search').delay(10000).submit();

          clearTimeout(autoSubmit);
          autoSubmit = setTimeout(function(){
            $('body').addClass('wait');
            $(form_id, context).once('kultuurikava_search').submit();
          }, delay);
        }
      );
      
    }
  };
}(jQuery));