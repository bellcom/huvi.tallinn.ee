/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

(function ($) {
  Drupal.behaviors.rssFeeds = {
    attach: function (context, settings) {

      $("#feed_url").click(function (event) {
        event.preventDefault();
        var emailLink = document.querySelector('.feed-link');
        var range = document.createRange();
        range.selectNode(emailLink);
        window.getSelection().addRange(range);

        try {
          // Now that we've selected the anchor text, execute the copy command  
          var successful = document.execCommand('copy');
          var msg = successful ? 'successful' : 'unsuccessful';
          console.log('Copy email command was ' + msg);
        } catch (err) {
          console.log('Oops, unable to copy');
        }

        // Remove the selections - NOTE: Should use
        // removeRange(range) when it is supported  
        window.getSelection().removeAllRanges();
        return false;
      })

    }
  }
})(jQuery);
