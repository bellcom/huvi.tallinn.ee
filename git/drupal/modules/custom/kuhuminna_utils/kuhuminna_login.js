(function ($) {
  $(document).ajaxComplete(function() {
    $("#modalContent").on("click", "#logi_sisse", function(){
      //forbid second click
      if($('#modalContent #div_logi_sisse').is(':visible')) {
       return false;
      }

      $('#modalContent').height($('#modalContent').height() + $("#div_logi_sisse").height());
      $('#modalContent #div_logi_sisse').toggle();
    });
  });
  $(document).ready(function() {
    $("#user-login").on("click", "#logi_sisse", function(){
      //forbid second click
      if($("#user-login #div_logi_sisse").is(':visible')) {
       return false;
      }
      $("#user-login #div_logi_sisse").toggle();
    });
  });
})(jQuery);
