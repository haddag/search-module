(function ($) {
  NOCHANGING      = 0;
  CHANGING        = 1;
  CHANGINGPENDING = 2;

  function patchInput(input, output) {
    input.data('autoState', NOCHANGING);
    input.data('autoPending', '');
    input.data('autoOutput', output);
  }

  /*
   * 
   */
  function displayResult(jnode, results) {
    jnode.empty();    

    // No result  
    if(results == null || results.length == 0) {
      jnode.text('Aucun résultat');
      return;
    }

    // Some results
    var node = $("<ol></ol>");

    for(var i = 0; i < results.length; i++) {
      var li         = $('<li></li>')
          suggestion = results[i].suggestion;
					gmurl      ="/test/search";
          link       = $('<a target="_blank" href="' + gmurl + '">'+suggestion'</a>');
					link.bind("click", function() {		
						onclick_suggestion(jnode, suggestion);
					});
          li.append(link);

          node.append(li);
    }
 
    	jnode.append(node);			
  }

  function onclick_suggestion(jnode, suggestion) {
	  
		$('#autocomplete').value = suggestion;
		$('#autocomplete').focus;
		jnode.empty();
		
		return $('#autocomplete');
	}

  function autocompleteOnChange(input) {
    switch(input.data('autoState')) {
      case NOCHANGING:
        input.data('autoState', CHANGING);
        askServer(input, input.val(), autocompleteOnAnswer);
        break;

      case CHANGING:
        input.data('autoState', CHANGINGPENDING);
        input.data('autoPending', input.val());
        break;

      case CHANGINGPENDING:
        // State does not change !
        input.data('autoPending', input.val());
        break;
    }
  }
	
  function autocompleteOnAnswer(input, result) {
    switch(input.data('autoState')) {
      case NOCHANGING:
        // Should not happen !
        break;

      case CHANGING:
        input.data('autoState', NOCHANGING);
        displayResult(input.data('autoOutput'), result);
        break;

      case CHANGINGPENDING:
        input.data('autoState', CHANGING);
        displayResult(input.data('autoOutput'), result);
        askServer(input, input.data('autoPending'), autocompleteOnAnswer);
        break;
    }
  }

  function askServer(input, value, onAnswer) {
		if (mb_strlen(input) >= 3) {
    	$.ajax({
      	type: 'GET',
      	timeout: 3000,
      	url: '/haddagsearch/suggestion/'+value,
      	contentType: 'application/json',
      	xhrFields: { withCredentials: false },
      	success: function(data, status, jqXHR) {
        	var result = JSON.parse(data);
        	autocompleteOnAnswer(input, result);
      	},
      	error: function() {
        	autocompleteOnAnswer(input, 'No result !');
      	}
    	});
		}
 	}

  patchInput($('#autocomplete'), $('#outputbox'));
  $('#autocomplete').bind('input', function() {
    autocompleteOnChange($(this));
  });
}) (jQuery);
