/*jQuery(document).ready(function(){
    if(jQuery.cookie != undefined) {
        // Check if cookie are enabled
        jQuery.cookie('wpml_browser_redirect_test', '1');
        var cookie_enabled = jQuery.cookie('wpml_browser_redirect_test') == 1;
        jQuery.removeCookie('wpml_browser_redirect_test');
              
        if (cookie_enabled) {
            var cookie_params = wpml_browser_redirect_params.cookie
            var cookie_name = cookie_params.name;
            // Check if we already did a redirect
            
            if (!jQuery.cookie(cookie_name)) {
                // Get page language and browser language
                var pageLanguage = wpml_browser_redirect_params.pageLanguage;
                var browserLanguage = navigator.language? navigator.language : navigator.userLanguage;
                browserLanguage = browserLanguage.substr(0,2); // browser language may have double code (i.e. en-us)
                
                // Build cookie options
                var cookie_options = {
                    expires: cookie_params.expiration / 24,
                    path: cookie_params.path? cookie_params.path : '/',
                    domain: cookie_params.domain? cookie_params.domain : ''
                };
                
                // Set the cookie so that the check is made only on the first visit
                jQuery.cookie(cookie_name, browserLanguage, cookie_options);

                // Compare page language and browser language
                if (pageLanguage != browserLanguage) {
                    var redirectUrl;
                    // First try to find the redirect url from parameters passed to javascript
                    var languageUrls = wpml_browser_redirect_params.languageUrls;
                    if (languageUrls[browserLanguage] != undefined) {
                        redirectUrl = languageUrls[browserLanguage];
                    }
                    // Finally do the redirect
                    if (redirectUrl != undefined) {
                        window.location = redirectUrl;
                    }    
                }
            }
        }
    }
});*/