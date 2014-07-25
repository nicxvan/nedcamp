/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - http://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

	$(document).ready(function() {
		
		//Remove no-js class from body
		if($('body').hasClass('no-js')){$('body').removeClass('no-js');}
		
		// Cross-Browser/Cross-Platform CSS classes
		function css_browser_selector(u){var ua=u.toLowerCase(),is=function(t){return ua.indexOf(t)>-1},g='gecko',w='webkit',s='safari',o='opera',m='mobile',h=document.documentElement,b=[(!(/opera|webtv/i.test(ua))&&/msie\s(\d+)/.test(ua))?('ie ie'+RegExp.$1):is('firefox/2')?g+' ff2':is('firefox/3.5')?g+' ff3 ff3_5':is('firefox/3.6')?g+' ff3 ff3_6':is('firefox/3')?g+' ff3':is('gecko/')?g:is('opera')?o+(/version\/(\d+)/.test(ua)?' '+o+RegExp.$1:(/opera(\s|\/)(\d+)/.test(ua)?' '+o+RegExp.$2:'')):is('konqueror')?'konqueror':is('blackberry')?m+' blackberry':is('android')?m+' android':is('chrome')?w+' chrome':is('iron')?w+' iron':is('applewebkit/')?w+' '+s+(/version\/(\d+)/.test(ua)?' '+s+RegExp.$1:''):is('mozilla/')?g:'',is('j2me')?m+' j2me':is('iphone')?m+' iphone':is('ipod')?m+' ipod':is('ipad')?m+' ipad':is('mac')?'mac':is('darwin')?'mac':is('webtv')?'webtv':is('win')?'win'+(is('windows nt 6.0')?' vista':''):is('freebsd')?'freebsd':(is('x11')||is('linux'))?'linux':'','js']; c = b.join(' '); h.className += ' '+c; return c;}; css_browser_selector(navigator.userAgent);

		// Pop to new window
		$('a[rel="external"]').click(function(){$(this).attr('target','_blank');});

		// Responsive Navigation
    $('#skip-link a').click(function(event){
      event.preventDefault();
      $('body').toggleClass('active-menu');
    });
    $('#main-menu-inner').prepend('<span class="close">X</span>');
    $('#main-menu-inner .close').on( "click", function() {
      $('body').toggleClass('active-menu');
    });
    if(window.innerWidth < 600){
      $('#main-menu .links').prepend('<li id="menu-item-home" class="menu-home"><a href="/">Home</a></li>');
		}


		// Placeholder attribute adjust
		if(document.createElement("input").placeholder == undefined) {
			$('#header #edit-search-block-form--2').attr('value','Search');
			$('#header #edit-search-block-form--2').each(function() {
				this.value = $(this).attr('placeholder');
				var default_value = this.value;
				$(this).focus(function(){if(this.value == default_value) {this.value = '';}})
							 .blur(function(){if(this.value == ''){this.value = default_value;}});
			});
		}

		// IE7 Pseudo Elements
		if($('html').hasClass('lt-ie8')){
			$('.view-display-id-product_listing ul li,.view-display-id-product_menu .product-list li').prepend('<span class="pseudo-bullet"></span>');
			$('#block-system-main-menu .menu,#main_content_wrapper,#page-title,ul.tabs-primary,.action-links,#content-wrapper,.region-sidebar-second,.banner_style_image-text-link,.banner_style_image-title-text-link,.banner_style_title-image,.banner_style_title-image-text,.banner_style_title-image-text-link,.listing-block .views-row,.node-blog .views-row,.node-events .views-row,.node-products .views-row,block-search-form,#view-display-id-events_upcoming .event,.view-display-id-homepage_blog_listing .article,.view-display-id-product_listing .product-list,.view-display-id-footer_follow_us .views-row').append('<span class="pseudo-clear"></span>');
		}
		
		$(window).resize(function() {
      if(window.innerWidth < 600){
        if($('#menu-item-home').length == 0){
          $('#main-menu .links').prepend('<li id="menu-item-home" class="menu-home"><a href="/">Home</a></li>');
        }
      }
      else {
        if($('#menu-item-home').length > 0){
          $('#menu-item-home').remove();
        }
      }
    });
	});

})(jQuery, Drupal, this, this.document);
