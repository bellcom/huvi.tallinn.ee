(function ($) {
  $(document).ready(function() {
    $("#modalContent").on("click", "#logi_sisse", function(){
      //forbid second click
      if($("#div_logi_sisse").is(':visible')) {
       return false;
      }

      $('#modalContent').height($('#modalContent').height() + $("#div_logi_sisse").height());
      $("#div_logi_sisse").toggle('slow');
    });
  });
})(jQuery);
