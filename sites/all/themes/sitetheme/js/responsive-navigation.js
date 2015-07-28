/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * http://stackoverflow.com/questions/9550866/how-to-create-custom-jquery-function-and-how-to-use-it
 * http://learn.jquery.com/plugins/basic-plugin-creation/
 */


(function($){
    $.fn.extend({ 

        responsiveNavigation: function(options) {

          //Settings list and the default values
          var defaults = $.extend({
                navExpanding: false,
                navExposing: true,
                navTrigger: '#skip-link a',
                navWrapper: '#main-menu',
                navList: '#main-menu .links',
                navListItem: '#main-menu .links > li',
                navListAnchor: '#main-menu .links a',
                navStaticHeight: 55,
                useCSSTransitions: true,
                hasCSSTransitions: 'csstransitions',
                notCSSTransitions: 'no-csstransitions',
                bodyActiveClass: 'expanded-navigation',
          }, options ),
              html = $('html'),
              body = $('body');


          //Check if Modernizr is being used
          if(typeof Modernizr != "undefined") {

            console.log('Modernizr exists');
            //If we are using Modernizr, does it include CSS Transitions
            if(Modernizr.csstransitions == undefined) {
              ////Modernizr DOES NOT contain csstransitions
              console.log('Modernizr DOES NOT csstransitions');
            }
            else {
              console.log('Modernizr has csstransitions');
            }

          }
          else {
            console.log('Modernizr DOES NOT exist');
            // Modernizr does not exist. Lets add the classes we need
            // CSS Transitions
            if( 'WebkitTransition' in document.body.style ||
                'MozTransition' in document.body.style ||
                'OTransition' in document.body.style ||
                'transition' in document.body.style
            ) {
              console.log('Adding csstransition class');
              body.addClass(options.hasCSSTransitions);
            }
            else {
              console.log('Adding notcsstransition class');
              body.addClass(options.notCSSTransitions);
            }
          }

          return this.each(function() {

            body.toggleClass(options.bodyActiveClass);

            $(navTrigger).click(function(){
              if(options.navExpanding){
                // this is incomplete
                if(html.hasClass(options.hasCSSTransitions)){
                  if(body.hasClass(options.bodyActiveClass)){
                    navWrapper.css({'height':options.staticHeight});
                  } else {
                    navWrapper.css({'height':options.staticHeight});
                  }
                } else {
                  if(body.hasClass(options.bodyActiveClass)){
                    navWrapper.animate({height:options.staticHeight}, 1500);
                  } else {
                    navWrapper.animate({height: options.staticHeight}, 1500);
                  }
                }
              }
              if(options.navExposing){
                if(body.hasClass(options.bodyActiveClass)){
                  body.removeClass(options.bodyActiveClass);
                } else {
                  body.addClass(options.bodyActiveClass);
                }
              }
            });

          });
        }
    });
})(jQuery);
