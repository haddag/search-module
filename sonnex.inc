<?php
function sonnex_is_vowel($char) {
  static $VOWELS = array(
	'a', 'â', 'à', 'ä', 'e', 'é', 'è', 'ê', 'ë', 'i', 'î', 'ï', 'o', 'ô',
	'ö', 'u', 'ù', 'û', 'ü', 'y', 'œ'
  );

  return in_array($char, $VOWELS);
}

function sonnex_is_conson($char) {
  static $CONSONS = array(
	'b', 'c', 'ç', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q',
	'r', 's', 't', 'v', 'w', 'x', 'y', 'z'
  );

  return in_array($char, $CONSONS);
}

function sonnex_mb_startswith($string, $start) {
  if(mb_strlen($string) < mb_strlen($start)) return FALSE;
  if(mb_substr($string, 0, mb_strlen($start)) == $start) return TRUE;
  return FALSE;
}

function sonnex_sonx($st) {
  if($st == "") return "";

  $length = mb_strlen($st);
  $head = mb_substr($st, 0, 1);
  $tail = mb_substr($st, 1);

  // Apostroph is ignored/silent
  if($head == "'") return sonnex_sonx($tail);
  if($head == "’") return sonnex_sonx($tail);

  // Starting with 'a'
  if($st == "a") return "a";
  if($st == "aient") return "E";
  if($st == "ain") return "1";
  if(sonnex_mb_startswith($st, "ain")) {
	  $v = mb_substr($st, 3, 1);
	  $cs = mb_substr($st, 4);
	  if(sonnex_is_vowel($v)) return "E".sonnex_sonx($v.$cs);
	  return "1".sonnex_sonx($v.$cs);
  }
  if($st == "ais") return "E";
  if(sonnex_mb_startswith($st, "ais")) {
	  $v = mb_substr($st, 3, 1);
	  $cs = mb_substr($st, 4);
	  if($v == 's') return "Es".sonnex_sonx($cs);
	  if(sonnex_is_vowel($v)) return "Ez".sonnex_sonx($v.$cs);
	  return "Es".sonnex_sonx($v.$cs);
  }
  if($st == "ail") return "ai";
  if(sonnex_mb_startswith($st, "aill")) return "ai".sonnex_sonx(mb_substr($st, 4));
  if(sonnex_mb_startswith($st, "ai")) return 'E'.sonnex_sonx(mb_substr($st, 2));
  if(sonnex_mb_startswith($st, "amm")) return "am".sonnex_sonx(mb_substr($st, 3));
  if(sonnex_mb_startswith($st, "am")) {
	  $c = mb_substr($st, 2, 1);
	  $cs = mb_substr($st, 3);
	  if($c == 'm') return "am".sonnex_sonx($cs);
	  if(sonnex_is_vowel($c)) return "am".sonnex_sonx($c.$cs);
	  return '2'.sonnex_sonx($c.$cs);
  }
  if($st == "an") return "2";
  if(sonnex_mb_startswith($st, "an")) {
	  $c = mb_substr($st, 2, 1);
	  $cs = mb_substr($st, 3);
	  if($c == 'n') return "an".sonnex_sonx($cs);
	  if($c == 't' and $cs=="") return "2";
	  if($c == 'te') return "2t".sonnex_sonx($cs);
	  if(sonnex_is_vowel($c)) return "an".sonnex_sonx($c.$cs);
	  return '2'.sonnex_sonx($c.$cs);
  }
  if($st == "assent") return "as";
  if(sonnex_mb_startswith($st, "as")) {
	  $c = mb_substr($st, 2, 1);
	  $cs = mb_substr($st, 3);
	  if($c == 's') return "as".sonnex_sonx($cs);
	  if(sonnex_is_conson($c)) return "as".sonnex_sonx($c.$cs);
	  return "az".sonnex_sonx($c.$cs);
  }
  if(sonnex_mb_startswith($st, "au")) return 'o'.sonnex_sonx(mb_substr($st, 2));
  if($st == "ay") return "E";
  if($st == "ays") return "E";

  if($head == 'à') return 'a'.sonnex_sonx($tail);
  if($head == 'â') {
	  $c = mb_substr($st, 1, 1);
	  $cs = mb_substr($st, 2);
	  if($c == 't') return 'a'.sonnex_sonx('t'.$cs);
	  return 'a'.sonnex_sonx($c.$cs);
  }

  // Starting with 'b'
  if($st == "b") return "";
  if(sonnex_mb_startswith($st, "bb")) return 'b'.sonnex_sonx(mb_substr($st, 2));

  // Starting with 'c'
  if($st == "c") return "";
  if(sonnex_mb_startswith($st, "ca")) return 'k'.sonnex_sonx('a'.mb_substr($st, 2));
  if(sonnex_mb_startswith($st, "cc")) {
	  $v = mb_substr($st, 2, 1);
	  $cs = mb_substr($st, 3);
	  if($v == 'o') return 'k'.sonnex_sonx('o'.$cs);
	  if($v == 'u') return 'k'.sonnex_sonx('u'.$cs);
	  return "ks".sonnex_sonx($cs);
  }
  if(sonnex_mb_startswith($st, "ce")) return 's'.sonnex_sonx('e'.mb_substr($st, 2));
  if(sonnex_mb_startswith($st, "c'")) return 's'.sonnex_sonx(mb_substr($st, 2));
  if(sonnex_mb_startswith($st, "c’")) return 's'.sonnex_sonx(mb_substr($st, 2));
  if(sonnex_mb_startswith($st, "chao")) return 'k'.sonnex_sonx("ao".mb_substr($st, 4));
  if(sonnex_mb_startswith($st, "chl")) return "kl".sonnex_sonx(mb_substr($st, 3));
  if(sonnex_mb_startswith($st, "choe")) return 'k'.sonnex_sonx("oe".mb_substr($st, 4));
  if(sonnex_mb_startswith($st, "chœ")) return 'k'.sonnex_sonx("oe".mb_substr($st, 3));
  if(sonnex_mb_startswith($st, "chr")) return "kr".sonnex_sonx(mb_substr($st, 3));
  if(sonnex_mb_startswith($st, "ch")) return 'C'.sonnex_sonx(mb_substr($st, 2));
  if(sonnex_mb_startswith($st, "ci")) return 's'.sonnex_sonx('i'.mb_substr($st, 2));
  if(sonnex_mb_startswith($st, "ck")) return 'k'.sonnex_sonx(mb_substr($st, 2));
  if(sonnex_mb_startswith($st, "coeu")) return 'k'.sonnex_sonx ("oeu".mb_substr($st, 4));
  if(sonnex_mb_startswith($st, "compt")) return "k3t".sonnex_sonx(mb_substr($st, 5));
  if(sonnex_mb_startswith($st, "cœu")) return 'k'.sonnex_sonx("œu".mb_substr($st, 3));
  if(sonnex_mb_startswith($st, "co")) return 'k'.sonnex_sonx('o'.mb_substr($st, 2));
  if(sonnex_mb_startswith($st, "cuei")) return "ke".sonnex_sonx('i'.mb_substr($st, 4));
  if(sonnex_mb_startswith($st, "cu")) return 'k'.sonnex_sonx('u'.mb_substr($st, 2));
  if(sonnex_mb_startswith($st, "cy")) return 's'.sonnex_sonx('y'.mb_substr($st, 2));
  if($head == "c") return 'k'.sonnex_sonx($tail);
  if($head == 'ç') return 's'.sonnex_sonx($tail);

  // Starting with 'd'
  if($st == "d") return "";
  if($st == "ds") return "";
  if(sonnex_mb_startswith($st, "dd")) return 'd'.sonnex_sonx(mb_substr($st, 2));

  // Starting with 'e'
  if($st == "e") return "";
  if($st == "ec") return "Ec";
  if($st == "ef") return "Ef";
  if($st == "eaux") return "o";
  if(sonnex_mb_startswith($st, "eann")) return "an".sonnex_sonx(mb_substr($st, 4));
  if(sonnex_mb_startswith($st, "ean")) return '2'.sonnex_sonx(mb_substr($st, 3));
  if(sonnex_mb_startswith($st, "eau")) return 'o'.sonnex_sonx(mb_substr($st, 3));
  if(sonnex_mb_startswith($st, "eff")) return "Ef".sonnex_sonx(mb_substr($st, 3));
  if(sonnex_mb_startswith($st, "egm")) return 'E'.sonnex_sonx("gm".mb_substr($st, 3));
  if($st == "ein") return "1";
  if(sonnex_mb_startswith($st, "ein")) {
	  $c = mb_substr($st, 3, 1);
	  $cs = mb_substr($st, 4);
	  if($c == 'n') return "En".sonnex_sonx($cs);
	  if(sonnex_is_vowel($c)) return "En".sonnex_sonx($c.$cs);
	  return '1'.sonnex_sonx($c.$cs);
  }
  if(sonnex_mb_startswith($st, "ei")) return 'E'.sonnex_sonx(mb_substr($st, 2));
  if(sonnex_mb_startswith($st, "ell")) return "El".sonnex_sonx(mb_substr($st,3));
  if(sonnex_mb_startswith($st, "el")) {
	  $c = mb_substr($st, 2, 1);
	  $cs = mb_substr($st, 3);
	  if(sonnex_is_conson($c)) return 'E'.sonnex_sonx('l'.$c.$cs);
	  return 'e'.sonnex_sonx('l'.$c.$cs);
  }
  if(sonnex_mb_startswith($st, "emm")) return "Em".sonnex_sonx(mb_substr($st,3));
  if(sonnex_mb_startswith($st, "emp")) return '2'.sonnex_sonx(mb_substr($st,3));
  if(sonnex_mb_startswith($st, "enn")) return "En".sonnex_sonx(mb_substr($st,3));
  if($st == "en") return "2";
  if(sonnex_mb_startswith($st, "en")) {
	  $c = mb_substr($st, 2, 1);
	  $cs = mb_substr($st, 3);
	  if(sonnex_is_vowel($c)) return "en".sonnex_sonx($c.$cs);
	  return '2'.sonnex_sonx($c.$cs);
  }
  if($st == "er") return "E";
  if($st == "ert") return "Er";
  if(sonnex_mb_startswith($st, "err")) return "Er".sonnex_sonx(mb_substr($st,3));
  if(sonnex_mb_startswith($st, "erf")) return "Er".sonnex_sonx('f'.mb_substr($st,3));
  if($st == "es") return "";
  if(sonnex_mb_startswith($st, "esch")) return "EC".sonnex_sonx(mb_substr($st,4));
  if($st == "essent") return "Es";
  if(sonnex_mb_startswith($st, "es")) {
	  $c = mb_substr($st, 2, 1);
	  $cs = mb_substr($st, 3);
	  if($c == 'h') return 'E'.sonnex_sonx('h'.$cs);
	  if($c == 'n') return 'E'.sonnex_sonx('n'.$cs);
	  if($c == 's') return "Es".sonnex_sonx($cs);
	  if(sonnex_is_conson($c)) return "Es".sonnex_sonx($c.$cs);
	  return "ez".sonnex_sonx($c.$cs);
  }
  if(sonnex_mb_startswith($st, "és")) {
	  $c = mb_substr($st, 2, 1);
	  $cs = mb_substr($st, 3);
	  if($c == 's') return "Es".sonnex_sonx($cs);
	  if(sonnex_is_conson($c)) return "Es".sonnex_sonx($c.$cs);
	  return "Ez".sonnex_sonx($c.$cs);
  }
  if(sonnex_mb_startswith($st, "ett")) return "Et".sonnex_sonx(mb_substr($st, 4));
  if($st == "et") return "E";
  if(sonnex_mb_startswith($st, "et")) return "et".sonnex_sonx(mb_substr($st, 2));
  if(sonnex_mb_startswith($st, "eun")) {
	  $c = mb_substr($st, 3, 1);
	  $cs = mb_substr($st, 4);
	  if(sonnex_is_vowel($c)) return "en".sonnex_sonx($c.$cs);
	  return '1'.sonnex_sonx($c.$cs);
  }
  if($st == "eux") return "e";
  if(sonnex_mb_startswith($st, "euxi")) return "ez".sonnex_sonx('i'.mb_substr($st, 4));
  if(sonnex_mb_startswith($st, "eu")) return 'e'.sonnex_sonx(mb_substr($st, 2));
  if($st == "ex") return "Eks";
  if(sonnex_mb_startswith($st, "ey")) {
	  $c = mb_substr($st, 2, 1);
	  $cs = mb_substr($st, 3);
	  if(sonnex_is_conson($c)) return 'E'.sonnex_sonx($c.$cs);
	  return 'E'.sonnex_sonx('y'.$c.$cs);
  }
  if($st == "ez") return "E";

  if($head == 'è') return 'E'.sonnex_sonx($tail);
  if($head == 'ê') {
	  $c = mb_substr($st, 1, 1);
	  $cs = mb_substr($st, 2);
	  if($c == 't') return 'E'.sonnex_sonx('t'.$cs);
	  return 'E'.sonnex_sonx($c.$cs);
  }
  if(sonnex_mb_startswith($st, "ël")) return 'E'.sonnex_sonx('l'.mb_substr($st, 2));
  if($st == "é") return "E";
  if($head == 'é') {
	  $c = mb_substr($st, 1, 1);
	  $cs = mb_substr($st, 2);
	  if($c == 't')  return "Et".sonnex_sonx($cs);
	  return 'E'.sonnex_sonx($c.$cs);
  }

  // Starting with 'f'
  if(sonnex_mb_startswith($st, "ff")) return 'f'.sonnex_sonx(mb_substr($st, 2));

  // Starting with 'g'
  if($st == "g") return "";
  if($st == "ge") return 'j';
  if(sonnex_mb_startswith($st, "ge")) return 'j'.sonnex_sonx(mb_substr($st, 2));
  if(sonnex_mb_startswith($st, "gé")) return 'jE'.sonnex_sonx(mb_substr($st, 2));
  if(sonnex_mb_startswith($st, "gi")) return 'ji'.sonnex_sonx(mb_substr($st, 2));
  if(sonnex_mb_startswith($st, "gn")) return 'n'.sonnex_sonx(mb_substr($st, 2));
  if(sonnex_mb_startswith($st, "gy")) return 'j'.sonnex_sonx('y'.mb_substr($st, 2));
  if(sonnex_mb_startswith($st, "guë")) return "gu".sonnex_sonx(mb_substr($st, 2));
  if(sonnex_mb_startswith($st, "gu")) return 'g'.sonnex_sonx(mb_substr($st, 2));
  if(sonnex_mb_startswith($st, "gg")) return 'g'.sonnex_sonx(mb_substr($st, 2));

  // Starting with 'h'
  if($head == 'h') return sonnex_sonx($tail);

  // Starting with 'i'
  if($st == "ic") return "ik";
  if($st == "ics") return "ik";
  if(sonnex_mb_startswith($st, "ienn")) return "iEn".sonnex_sonx(mb_substr($st, 4));
  if(sonnex_mb_startswith($st, "ien")) return "i1".sonnex_sonx(mb_substr($st, 3));
  if($st == "in") return "1";
  if(sonnex_mb_startswith($st, "in")) {
	  $c = mb_substr($st, 2, 1);
	  $cs = mb_substr($st, 3);
	  if($c == 'n') return "in".sonnex_sonx($cs);
	  if(sonnex_is_vowel($c)) return "in".sonnex_sonx($c.$cs);
	  return '1'.sonnex_sonx($c.$cs);
  }
  if($st == "issent") return "is";
  if($st == "is") return "i";
  if(sonnex_mb_startswith($st, "is")) {
	  $c = mb_substr($st, 2, 1);
	  $cs = mb_substr($st, 3);
	  if($c == 's') return "is".sonnex_sonx($cs);
	  if(sonnex_is_conson($c)) return "is".sonnex_sonx($c.$cs);
	  return "iz".sonnex_sonx($c.$cs);
  }
  if(sonnex_mb_startswith($st, "ixi")) return "iz".sonnex_sonx('i'.mb_substr($st, 3));
  if(sonnex_mb_startswith($st, "ill")) return 'i'.sonnex_sonx(mb_substr($st, 3));
  if($head == "i") return 'i'.sonnex_sonx($tail);

  if($head == "ï") return 'i'.sonnex_sonx($tail);

  // Starting with 'l'
  if(sonnex_mb_startswith($st, "ll")) return 'l'.sonnex_sonx(mb_substr($st, 2));

  // Starting with 'm'
  if(sonnex_mb_startswith($st, "mm")) return 'm'.sonnex_sonx(mb_substr($st, 2));

  // Starting with 'n'
  if(sonnex_mb_startswith($st, "nn")) return 'n'.sonnex_sonx(mb_substr($st, 2));

  // Starting with 'o'
  if(sonnex_mb_startswith($st, "occ")) return "ok".sonnex_sonx(mb_substr($st, 3));
  if(sonnex_mb_startswith($st, "oeu")) return 'e'.sonnex_sonx(mb_substr($st, 3));
  if(sonnex_mb_startswith($st, "œu")) return 'e'.sonnex_sonx(mb_substr($st, 2));
  if($head == "œ") return 'e'.sonnex_sonx($tail);
  if($st == "oient") return "Ua";
  if(sonnex_mb_startswith($st, "oin")) return "U1".sonnex_sonx(mb_substr($st, 3));
  if(sonnex_mb_startswith($st, "ois")) return "Ua".sonnex_sonx(mb_substr($st, 3));
  if(sonnex_mb_startswith($st, "omm")) return "om".sonnex_sonx(mb_substr($st, 3));
  if(sonnex_mb_startswith($st, "om")) {
	  $c = mb_substr($st, 2, 1);
	  $cs = mb_substr($st, 3);
	  if(sonnex_is_vowel($c)) return "om".sonnex_sonx($c.$cs);
	  return '3'.sonnex_sonx($c.$cs);
  }
  if(sonnex_mb_startswith($st, "onn")) return "on".sonnex_sonx(mb_substr($st, 3));
  if(sonnex_mb_startswith($st, "on")) {
	  $c = mb_substr($st, 2, 1);
	  $cs = mb_substr($st, 3);
	  if(sonnex_is_vowel($c)) return "on".sonnex_sonx($c.$cs);
	  return "3".sonnex_sonx($c.$cs);
  }
  if($st == "ossent") return "os";
  if(sonnex_mb_startswith($st, "os")) {
	  $c = mb_substr($st, 2, 1);
	  $cs = mb_substr($st, 3);
	  if($c == 's') return "os".sonnex_sonx($cs);
	  if(sonnex_is_conson($c)) return "os".sonnex_sonx($c.$cs);
	  return "oz".sonnex_sonx($c.$cs);
  }
  if(sonnex_mb_startswith($st, "ou")) return 'U'.sonnex_sonx(mb_substr($st, 2));
  if(sonnex_mb_startswith($st, "où")) return 'U'.sonnex_sonx(mb_substr($st, 2));
  if(sonnex_mb_startswith($st, "oû")) return 'U'.sonnex_sonx(mb_substr($st, 2));

  if($head == "ô") return 'o'.sonnex_sonx($tail);
  if($head == "ö") return 'o'.sonnex_sonx($tail);

  // Starting with 'p'
  if($st == "p") return "";
  if($st == "ps") return "";
  if(sonnex_mb_startswith($st, "ph")) return 'f'.sonnex_sonx(mb_substr($st, 2));
  if(sonnex_mb_startswith($st, "pp")) return 'p'.sonnex_sonx(mb_substr($st, 2));
  if(sonnex_mb_startswith($st, "pays")) return "pE".sonnex_sonx ("is".mb_substr($st, 4));

  // Starting with 'q'
  if(sonnex_mb_startswith($st, "qur")) return "ku".sonnex_sonx('r'.mb_substr($st, 3));
  if(sonnex_mb_startswith($st, "qu")) return 'k'.sonnex_sonx(mb_substr($st, 2));
  if($head == 'q') return 'k'.sonnex_sonx($tail);

  // Starting with 'r'
  if(sonnex_mb_startswith($st, "rr")) return 'r'.sonnex_sonx(mb_substr($st, 2));

  // Starting with 's'
  if($st == "s") return "";
  if(sonnex_mb_startswith($st, "ss")) return 's'.sonnex_sonx(mb_substr($st, 2));
  if(sonnex_mb_startswith($st, "st")) return "st".sonnex_sonx(mb_substr($st, 2));
  if(sonnex_mb_startswith($st, "sci")) return 's'.sonnex_sonx('i'.mb_substr($st, 3));

  // Starting with 't'
  if($st == "t") return "";
  if($st == "ts") return "";
  if(sonnex_mb_startswith($st, "tier")) return 't'.sonnex_sonx("ier".mb_substr($st,4));
  if(sonnex_mb_startswith($st, "ti")) {
	  $v = mb_substr($st, 2, 1);
	  $cs = mb_substr($st, 3);
	  if(sonnex_is_vowel($v)) return 's'.sonnex_sonx('i'.$v.$cs);
	  return 't'.sonnex_sonx('i'.$v.$cs);
  }
  if(sonnex_mb_startswith($st, "tt")) return 't'.sonnex_sonx(mb_substr($st, 2));

  // Starting with 'u'
  if($st == "un") return "1";
  if($head == "û") return 'u'.sonnex_sonx($tail);
  if($st == "ussent") return "us";
  if(sonnex_mb_startswith($st, "us")) {
	  $c = mb_substr($st, 2, 1);
	  $cs = mb_substr($st, 3);
	  if($c == 's') return "us".sonnex_sonx($cs);
	  if(sonnex_is_conson($c)) return "us".sonnex_sonx($c.$cs);
	  return "uz".sonnex_sonx($c.$cs);
  }

  // Starting with 'v'
  // 'v' can be handled by the generic case since there is no special thing
  // about this letter, it’s always pronounced 'v' and never doubled.

  // Starting with 'w'
  if($head == "w") return 'v'.sonnex_sonx($tail);

  // Starting with 'x'
  if($st == "x") return "";
  if(sonnex_mb_startswith($st, "x")) {
	  $c = mb_substr($st, 2, 1);
	  $cs = mb_substr($st, 3);
	  if($c == 'c') return "ks".sonnex_sonx($cs);
	  if(sonnex_is_vowel($c)) return "kz".sonnex_sonx($c.$cs);
	  return "ks".sonnex_sonx($c.$cs);
  }

  // Starting with 'y'
  if($head == "y") return 'i'.sonnex_sonx($tail);

  // Starting with 'z'
  if(sonnex_mb_startswith($st, "zz")) return 'z'.sonnex_sonx(mb_substr($st, 2));

  // Copy every other character as is;
  if(sonnex_is_conson($head) or sonnex_is_vowel($head)) {
	  return $head.sonnex_sonx($tail);
  } else {
	  return sonnex_sonx($tail);
  }
}

// Compute a Sonnex code for a french word.
//
// The string must contain only one word.
// Each character should be considered as being vocal, not silent
function sonnex($st) {
  $st = mb_strtolower($st);
  switch($st) {
	case "cerf": return "sEr";
	case "cerfs": return "sEr";
	case "de" : return "de";
	case "est": return "E";
	case "es" : return "E";
	case "huit": return "uit";
	case "les": return "lE";
	case "mer": return "mEr";
	case "mes": return "mE";
	case "ressent": return "res2";
	case "serf": return "sEr";
	case "serfs": return "sEr";
	case "sept": return "sEt";
	case "septième": return "sEtiEm";
	case "ses": return "sE";
	case "tes": return "tE";
	default:
		if(sonnex_mb_startswith($st, "tien"))
			return 't'.sonnex_sonx("ien".mb_substr($st, 4));
		return sonnex_sonx($st);
  }
}

function sonnex_clean_phrase($phrase) {
  return trim(preg_replace('/[ \t_,.;:!-]+/', ' ', $phrase));
}

function sonnex_phrase($phrase) {
  $phrase = sonnex_clean_phrase($phrase);
  $words = explode(' ', $phrase);
  $sonnexs = array();
  foreach($words as $word) {
	  $sonnexs[] = sonnex($word);
  }

  return $sonnexs;
}

function sonnex_libelle($libelle) {
  $libelle = sonnex_clean_phrase($libelle);
  $libelle = preg_replace(
	"/( aux | de la | de l'| des | les | de | du | d')/",
	' ',
	$libelle
  );

  return sonnex_phrase($libelle);
}