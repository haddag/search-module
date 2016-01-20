<?php

function _sonnex_is_vowel($char) {
  static $VOWELS = array(
  'a', 'â', 'à', 'ä', 'e', 'é', 'è', 'ê', 'ë', 'i', 'î', 'ï', 'o', 'ô',
  'ö', 'u', 'ù', 'û', 'ü', 'y', 'œ'
  );

  return in_array($char, $VOWELS);
}

function _sonnex_is_conson($char) {
  static $CONSONS = array(
  'b', 'c', 'ç', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q',
  'r', 's', 't', 'v', 'w', 'x', 'y', 'z'
  );

  return in_array($char, $CONSONS);
}

function _sonnex_mb_startswith($string, $start) {
  if(mb_strlen($string) < mb_strlen($start)) return FALSE;
  if(mb_substr($string, 0, mb_strlen($start)) == $start) return TRUE;
  return FALSE;
}

function _sonnex_sonx($st) {
  
  if($st == "") return "";

  $length = mb_strlen($st);
  $head = mb_substr($st, 0, 1);
  $tail = mb_substr($st, 1);

  // Apostroph is ignored/silent
  if($head == "'") return _sonnex_sonx($tail);
  if($head == "’") return _sonnex_sonx($tail);

  // Starting with 'a'
  if($st == "a") return "a";
  if($st == "aient") return "E";
  if($st == "ain") return "1";
  if(_sonnex_mb_startswith($st, "ain")) {
    $v = mb_substr($st, 3, 1);
    $cs = mb_substr($st, 4);
    if(_sonnex_is_vowel($v)) return "E"._sonnex_sonx($v.$cs);
    return "1"._sonnex_sonx($v.$cs);
  }
  if($st == "ais") return "E";
  if(_sonnex_mb_startswith($st, "ais")) {
    $v = mb_substr($st, 3, 1);
    $cs = mb_substr($st, 4);
    if($v == 's') return "Es"._sonnex_sonx($cs);
    if(_sonnex_is_vowel($v)) return "Ez"._sonnex_sonx($v.$cs);
    return "Es"._sonnex_sonx($v.$cs);
  }
  if($st == "ail") return "ai";
  if(_sonnex_mb_startswith($st, "aill")) return "ai"._sonnex_sonx(mb_substr($st, 4));
  if(_sonnex_mb_startswith($st, "ai")) return 'E'._sonnex_sonx(mb_substr($st, 2));
  if(_sonnex_mb_startswith($st, "amm")) return "am"._sonnex_sonx(mb_substr($st, 3));
  if(_sonnex_mb_startswith($st, "am")) {
    $c = mb_substr($st, 2, 1);
    $cs = mb_substr($st, 3);
    if($c == 'm') return "am"._sonnex_sonx($cs);
    if(_sonnex_is_vowel($c)) return "am"._sonnex_sonx($c.$cs);
    return '2'._sonnex_sonx($c.$cs);
  }
  if($st == "an") return "2";
  if(_sonnex_mb_startswith($st, "an")) {
    $c = mb_substr($st, 2, 1);
    $cs = mb_substr($st, 3);
    if($c == 'n') return "an"._sonnex_sonx($cs);
    if($c == 't' and $cs=="") return "2";
    if($c == 'te') return "2t"._sonnex_sonx($cs);
    if(_sonnex_is_vowel($c)) return "an"._sonnex_sonx($c.$cs);
    return '2'._sonnex_sonx($c.$cs);
  }
  if($st == "assent") return "as";
  if(_sonnex_mb_startswith($st, "as")) {
    $c = mb_substr($st, 2, 1);
    $cs = mb_substr($st, 3);
    if($c == 's') return "as"._sonnex_sonx($cs);
    if(_sonnex_is_conson($c)) return "as"._sonnex_sonx($c.$cs);
    return "az"._sonnex_sonx($c.$cs);
  }
  if(_sonnex_mb_startswith($st, "au")) return 'o'._sonnex_sonx(mb_substr($st, 2));
  if($st == "ay") return "E";
  if($st == "ays") return "E";

  if($head == 'à') return 'a'._sonnex_sonx($tail);
  if($head == 'â') {
    $c = mb_substr($st, 1, 1);
    $cs = mb_substr($st, 2);
    if($c == 't') return 'a'._sonnex_sonx('t'.$cs);
    return 'a'._sonnex_sonx($c.$cs);
  }

  // Starting with 'b'
  if($st == "b") return "";
  if(_sonnex_mb_startswith($st, "bb")) return 'b'._sonnex_sonx(mb_substr($st, 2));

  // Starting with 'c'
  if($st == "c") return "";
  if(_sonnex_mb_startswith($st, "ca")) return 'k'._sonnex_sonx('a'.mb_substr($st, 2));
  if(_sonnex_mb_startswith($st, "cc")) {
    $v = mb_substr($st, 2, 1);
    $cs = mb_substr($st, 3);
    if($v == 'o') return 'k'._sonnex_sonx('o'.$cs);
    if($v == 'u') return 'k'._sonnex_sonx('u'.$cs);
    return "ks"._sonnex_sonx($cs);
  }
  if(_sonnex_mb_startswith($st, "ce")) return 's'._sonnex_sonx('e'.mb_substr($st, 2));
  if(_sonnex_mb_startswith($st, "c'")) return 's'._sonnex_sonx(mb_substr($st, 2));
  if(_sonnex_mb_startswith($st, "c’")) return 's'._sonnex_sonx(mb_substr($st, 2));
  if(_sonnex_mb_startswith($st, "chao")) return 'k'._sonnex_sonx("ao".mb_substr($st, 4));
  if(_sonnex_mb_startswith($st, "chl")) return "kl"._sonnex_sonx(mb_substr($st, 3));
  if(_sonnex_mb_startswith($st, "choe")) return 'k'._sonnex_sonx("oe".mb_substr($st, 4));
  if(_sonnex_mb_startswith($st, "chœ")) return 'k'._sonnex_sonx("oe".mb_substr($st, 3));
  if(_sonnex_mb_startswith($st, "chr")) return "kr"._sonnex_sonx(mb_substr($st, 3));
  if(_sonnex_mb_startswith($st, "ch")) return 'C'._sonnex_sonx(mb_substr($st, 2));
  if(_sonnex_mb_startswith($st, "ci")) return 's'._sonnex_sonx('i'.mb_substr($st, 2));
  if(_sonnex_mb_startswith($st, "ck")) return 'k'._sonnex_sonx(mb_substr($st, 2));
  if(_sonnex_mb_startswith($st, "coeu")) return 'k'._sonnex_sonx ("oeu".mb_substr($st, 4));
  if(_sonnex_mb_startswith($st, "compt")) return "k3t"._sonnex_sonx(mb_substr($st, 5));
  if(_sonnex_mb_startswith($st, "cœu")) return 'k'._sonnex_sonx("œu".mb_substr($st, 3));
  if(_sonnex_mb_startswith($st, "co")) return 'k'._sonnex_sonx('o'.mb_substr($st, 2));
  if(_sonnex_mb_startswith($st, "cuei")) return "ke"._sonnex_sonx('i'.mb_substr($st, 4));
  if(_sonnex_mb_startswith($st, "cu")) return 'k'._sonnex_sonx('u'.mb_substr($st, 2));
  if(_sonnex_mb_startswith($st, "cy")) return 's'._sonnex_sonx('y'.mb_substr($st, 2));
  if($head == "c") return 'k'._sonnex_sonx($tail);
  if($head == 'ç') return 's'._sonnex_sonx($tail);

  // Starting with 'd'
  if($st == "d") return "";
  if($st == "ds") return "";
  if(_sonnex_mb_startswith($st, "dd")) return 'd'._sonnex_sonx(mb_substr($st, 2));

  // Starting with 'e'
  if($st == "e") return "";
  if($st == "ec") return "Ec";
  if($st == "ef") return "Ef";
  if($st == "eaux") return "o";
  if(_sonnex_mb_startswith($st, "eann")) return "an"._sonnex_sonx(mb_substr($st, 4));
  if(_sonnex_mb_startswith($st, "ean")) return '2'._sonnex_sonx(mb_substr($st, 3));
  if(_sonnex_mb_startswith($st, "eau")) return 'o'._sonnex_sonx(mb_substr($st, 3));
  if(_sonnex_mb_startswith($st, "eff")) return "Ef"._sonnex_sonx(mb_substr($st, 3));
  if(_sonnex_mb_startswith($st, "egm")) return 'E'._sonnex_sonx("gm".mb_substr($st, 3));
  if($st == "ein") return "1";
  if(_sonnex_mb_startswith($st, "ein")) {
    $c = mb_substr($st, 3, 1);
    $cs = mb_substr($st, 4);
    if($c == 'n') return "En"._sonnex_sonx($cs);
    if(_sonnex_is_vowel($c)) return "En"._sonnex_sonx($c.$cs);
    return '1'._sonnex_sonx($c.$cs);
  }
  if(_sonnex_mb_startswith($st, "ei")) return 'E'._sonnex_sonx(mb_substr($st, 2));
  if(_sonnex_mb_startswith($st, "ell")) return "El"._sonnex_sonx(mb_substr($st,3));
  if(_sonnex_mb_startswith($st, "el")) {
    $c = mb_substr($st, 2, 1);
    $cs = mb_substr($st, 3);
    if(_sonnex_is_conson($c)) return 'E'._sonnex_sonx('l'.$c.$cs);
    return 'e'._sonnex_sonx('l'.$c.$cs);
  }
  if(_sonnex_mb_startswith($st, "emm")) return "Em"._sonnex_sonx(mb_substr($st,3));
  if(_sonnex_mb_startswith($st, "emp")) return '2'._sonnex_sonx(mb_substr($st,3));
  if(_sonnex_mb_startswith($st, "enn")) return "En"._sonnex_sonx(mb_substr($st,3));
  if($st == "en") return "2";
  if(_sonnex_mb_startswith($st, "en")) {
    $c = mb_substr($st, 2, 1);
    $cs = mb_substr($st, 3);
    if(_sonnex_is_vowel($c)) return "en"._sonnex_sonx($c.$cs);
    return '2'._sonnex_sonx($c.$cs);
  }
  if($st == "er") return "E";
  if($st == "ert") return "Er";
  if(_sonnex_mb_startswith($st, "err")) return "Er"._sonnex_sonx(mb_substr($st,3));
  if(_sonnex_mb_startswith($st, "erf")) return "Er"._sonnex_sonx('f'.mb_substr($st,3));
  if($st == "es") return "";
  if(_sonnex_mb_startswith($st, "esch")) return "EC"._sonnex_sonx(mb_substr($st,4));
  if($st == "essent") return "Es";
  if(_sonnex_mb_startswith($st, "es")) {
    $c = mb_substr($st, 2, 1);
    $cs = mb_substr($st, 3);
    if($c == 'h') return 'E'._sonnex_sonx('h'.$cs);
    if($c == 'n') return 'E'._sonnex_sonx('n'.$cs);
    if($c == 's') return "Es"._sonnex_sonx($cs);
    if(_sonnex_is_conson($c)) return "Es"._sonnex_sonx($c.$cs);
    return "ez"._sonnex_sonx($c.$cs);
  }
  if(_sonnex_mb_startswith($st, "és")) {
    $c = mb_substr($st, 2, 1);
    $cs = mb_substr($st, 3);
    if($c == 's') return "Es"._sonnex_sonx($cs);
    if(_sonnex_is_conson($c)) return "Es"._sonnex_sonx($c.$cs);
    return "Ez"._sonnex_sonx($c.$cs);
  }
  if(_sonnex_mb_startswith($st, "ett")) return "Et"._sonnex_sonx(mb_substr($st, 4));
  if($st == "et") return "E";
  if(_sonnex_mb_startswith($st, "et")) return "et"._sonnex_sonx(mb_substr($st, 2));
  if(_sonnex_mb_startswith($st, "eun")) {
    $c = mb_substr($st, 3, 1);
    $cs = mb_substr($st, 4);
    if(_sonnex_is_vowel($c)) return "en"._sonnex_sonx($c.$cs);
    return '1'._sonnex_sonx($c.$cs);
  }
  if($st == "eux") return "e";
  if(_sonnex_mb_startswith($st, "euxi")) return "ez"._sonnex_sonx('i'.mb_substr($st, 4));
  if(_sonnex_mb_startswith($st, "eu")) return 'e'._sonnex_sonx(mb_substr($st, 2));
  if($st == "ex") return "Eks";
  if(_sonnex_mb_startswith($st, "ey")) {
    $c = mb_substr($st, 2, 1);
    $cs = mb_substr($st, 3);
    if(_sonnex_is_conson($c)) return 'E'._sonnex_sonx($c.$cs);
    return 'E'._sonnex_sonx('y'.$c.$cs);
  }
  if($st == "ez") return "E";

  if($head == 'è') return 'E'._sonnex_sonx($tail);
  if($head == 'ê') {
    $c = mb_substr($st, 1, 1);
    $cs = mb_substr($st, 2);
    if($c == 't') return 'E'._sonnex_sonx('t'.$cs);
    return 'E'._sonnex_sonx($c.$cs);
  }
  if(_sonnex_mb_startswith($st, "ël")) return 'E'._sonnex_sonx('l'.mb_substr($st, 2));
  if($st == "é") return "E";
  if($head == 'é') {
    $c = mb_substr($st, 1, 1);
    $cs = mb_substr($st, 2);
    if($c == 't')  return "Et"._sonnex_sonx($cs);
    return 'E'._sonnex_sonx($c.$cs);
  }

  // Starting with 'f'
  if(_sonnex_mb_startswith($st, "ff")) return 'f'._sonnex_sonx(mb_substr($st, 2));

  // Starting with 'g'
  if($st == "g") return "";
  if($st == "ge") return 'j';
  if(_sonnex_mb_startswith($st, "ge")) return 'j'._sonnex_sonx(mb_substr($st, 2));
  if(_sonnex_mb_startswith($st, "gé")) return 'jE'._sonnex_sonx(mb_substr($st, 2));
  if(_sonnex_mb_startswith($st, "gi")) return 'ji'._sonnex_sonx(mb_substr($st, 2));
  if(_sonnex_mb_startswith($st, "gn")) return 'n'._sonnex_sonx(mb_substr($st, 2));
  if(_sonnex_mb_startswith($st, "gy")) return 'j'._sonnex_sonx('y'.mb_substr($st, 2));
  if(_sonnex_mb_startswith($st, "guë")) return "gu"._sonnex_sonx(mb_substr($st, 2));
  if(_sonnex_mb_startswith($st, "gu")) return 'g'._sonnex_sonx(mb_substr($st, 2));
  if(_sonnex_mb_startswith($st, "gg")) return 'g'._sonnex_sonx(mb_substr($st, 2));

  // Starting with 'h'
  if($head == 'h') return _sonnex_sonx($tail);

  // Starting with 'i'
  if($st == "ic") return "ik";
  if($st == "ics") return "ik";
  if(_sonnex_mb_startswith($st, "ienn")) return "iEn"._sonnex_sonx(mb_substr($st, 4));
  if(_sonnex_mb_startswith($st, "ien")) return "i1"._sonnex_sonx(mb_substr($st, 3));
  if($st == "in") return "1";
  if(_sonnex_mb_startswith($st, "in")) {
    $c = mb_substr($st, 2, 1);
    $cs = mb_substr($st, 3);
    if($c == 'n') return "in"._sonnex_sonx($cs);
    if(_sonnex_is_vowel($c)) return "in"._sonnex_sonx($c.$cs);
    return '1'._sonnex_sonx($c.$cs);
  }
  if($st == "issent") return "is";
  if($st == "is") return "i";
  if(_sonnex_mb_startswith($st, "is")) {
    $c = mb_substr($st, 2, 1);
    $cs = mb_substr($st, 3);
    if($c == 's') return "is"._sonnex_sonx($cs);
    if(_sonnex_is_conson($c)) return "is"._sonnex_sonx($c.$cs);
    return "iz"._sonnex_sonx($c.$cs);
  }
  if(_sonnex_mb_startswith($st, "ixi")) return "iz"._sonnex_sonx('i'.mb_substr($st, 3));
  if(_sonnex_mb_startswith($st, "ill")) return 'i'._sonnex_sonx(mb_substr($st, 3));
  if($head == "i") return 'i'._sonnex_sonx($tail);

  if($head == "ï") return 'i'._sonnex_sonx($tail);

  // Starting with 'l'
  if(_sonnex_mb_startswith($st, "ll")) return 'l'._sonnex_sonx(mb_substr($st, 2));

  // Starting with 'm'
  if(_sonnex_mb_startswith($st, "mm")) return 'm'._sonnex_sonx(mb_substr($st, 2));

  // Starting with 'n'
  if(_sonnex_mb_startswith($st, "nn")) return 'n'._sonnex_sonx(mb_substr($st, 2));

  // Starting with 'o'
  if(_sonnex_mb_startswith($st, "occ")) return "ok"._sonnex_sonx(mb_substr($st, 3));
  if(_sonnex_mb_startswith($st, "oeu")) return 'e'._sonnex_sonx(mb_substr($st, 3));
  if(_sonnex_mb_startswith($st, "œu")) return 'e'._sonnex_sonx(mb_substr($st, 2));
  if($head == "œ") return 'e'._sonnex_sonx($tail);
  if($st == "oient") return "Ua";
  if(_sonnex_mb_startswith($st, "oin")) return "U1"._sonnex_sonx(mb_substr($st, 3));
  if(_sonnex_mb_startswith($st, "ois")) return "Ua"._sonnex_sonx(mb_substr($st, 3));
  if(_sonnex_mb_startswith($st, "omm")) return "om"._sonnex_sonx(mb_substr($st, 3));
  if(_sonnex_mb_startswith($st, "om")) {
    $c = mb_substr($st, 2, 1);
    $cs = mb_substr($st, 3);
    if(_sonnex_is_vowel($c)) return "om"._sonnex_sonx($c.$cs);
    return '3'._sonnex_sonx($c.$cs);
  }
  if(_sonnex_mb_startswith($st, "onn")) return "on"._sonnex_sonx(mb_substr($st, 3));
  if(_sonnex_mb_startswith($st, "on")) {
    $c = mb_substr($st, 2, 1);
    $cs = mb_substr($st, 3);
    if(_sonnex_is_vowel($c)) return "on"._sonnex_sonx($c.$cs);
    return "3"._sonnex_sonx($c.$cs);
  }
  if($st == "ossent") return "os";
  if(_sonnex_mb_startswith($st, "os")) {
    $c = mb_substr($st, 2, 1);
    $cs = mb_substr($st, 3);
    if($c == 's') return "os"._sonnex_sonx($cs);
    if(_sonnex_is_conson($c)) return "os"._sonnex_sonx($c.$cs);
    return "oz"._sonnex_sonx($c.$cs);
  }
  if(_sonnex_mb_startswith($st, "ou")) return 'U'._sonnex_sonx(mb_substr($st, 2));
  if(_sonnex_mb_startswith($st, "où")) return 'U'._sonnex_sonx(mb_substr($st, 2));
  if(_sonnex_mb_startswith($st, "oû")) return 'U'._sonnex_sonx(mb_substr($st, 2));

  if($head == "ô") return 'o'._sonnex_sonx($tail);
  if($head == "ö") return 'o'._sonnex_sonx($tail);

  // Starting with 'p'
  if($st == "p") return "";
  if($st == "ps") return "";
  if(_sonnex_mb_startswith($st, "ph")) return 'f'._sonnex_sonx(mb_substr($st, 2));
  if(_sonnex_mb_startswith($st, "pp")) return 'p'._sonnex_sonx(mb_substr($st, 2));
  if(_sonnex_mb_startswith($st, "pays")) return "pE"._sonnex_sonx ("is".mb_substr($st, 4));

  // Starting with 'q'
  if(_sonnex_mb_startswith($st, "qur")) return "ku"._sonnex_sonx('r'.mb_substr($st, 3));
  if(_sonnex_mb_startswith($st, "qu")) return 'k'._sonnex_sonx(mb_substr($st, 2));
  if($head == 'q') return 'k'._sonnex_sonx($tail);

  // Starting with 'r'
  if(_sonnex_mb_startswith($st, "rr")) return 'r'._sonnex_sonx(mb_substr($st, 2));

  // Starting with 's'
  if($st == "s") return "";
  if(_sonnex_mb_startswith($st, "ss")) return 's'._sonnex_sonx(mb_substr($st, 2));
  if(_sonnex_mb_startswith($st, "st")) return "st"._sonnex_sonx(mb_substr($st, 2));
  if(_sonnex_mb_startswith($st, "sci")) return 's'._sonnex_sonx('i'.mb_substr($st, 3));

  // Starting with 't'
  if($st == "t") return "";
  if($st == "ts") return "";
  if(_sonnex_mb_startswith($st, "tier")) return 't'._sonnex_sonx("ier".mb_substr($st,4));
  if(_sonnex_mb_startswith($st, "ti")) {
    $v = mb_substr($st, 2, 1);
    $cs = mb_substr($st, 3);
    if(_sonnex_is_vowel($v)) return 's'._sonnex_sonx('i'.$v.$cs);
    return 't'._sonnex_sonx('i'.$v.$cs);
  }
  if(_sonnex_mb_startswith($st, "tt")) return 't'._sonnex_sonx(mb_substr($st, 2));

  // Starting with 'u'
  if($st == "un") return "1";
  if($head == "û") return 'u'._sonnex_sonx($tail);
  if($st == "ussent") return "us";
  if(_sonnex_mb_startswith($st, "us")) {
    $c = mb_substr($st, 2, 1);
    $cs = mb_substr($st, 3);
    if($c == 's') return "us"._sonnex_sonx($cs);
    if(_sonnex_is_conson($c)) return "us"._sonnex_sonx($c.$cs);
    return "uz"._sonnex_sonx($c.$cs);
  }

  // Starting with 'v'
  // 'v' can be handled by the generic case since there is no special thing
  // about this letter, it’s always pronounced 'v' and never doubled.

  // Starting with 'w'
  if($head == "w") return 'v'._sonnex_sonx($tail);

  // Starting with 'x'
  if($st == "x") return "";
  if(_sonnex_mb_startswith($st, "x")) {
    $c = mb_substr($st, 2, 1);
    $cs = mb_substr($st, 3);
    if($c == 'c') return "ks"._sonnex_sonx($cs);
    if(_sonnex_is_vowel($c)) return "kz"._sonnex_sonx($c.$cs);
    return "ks"._sonnex_sonx($c.$cs);
  }

  // Starting with 'y'
  if($head == "y") return 'i'._sonnex_sonx($tail);

  // Starting with 'z'
  if(_sonnex_mb_startswith($st, "zz")) return 'z'._sonnex_sonx(mb_substr($st, 2));

  // Copy every other character as is;
  if(_sonnex_is_conson($head) or _sonnex_is_vowel($head)) {
    return $head._sonnex_sonx($tail);
  } else {
    return _sonnex_sonx($tail);
  }
}

// Compute a Sonnex code for a french word.
//
// The string must contain only one word".
// Each character should be considered as being vocal, not silent
function sonnex_sonnex($st) {
  static $cache = array();

  if(isset($cache[$st])) {
    return $cache[$st];  
  }

  $st = mb_strtolower($st);
  switch($st) {
    case "cerf": $st2 = "sEr"; break;
    case "cerfs": $st2 = "sEr"; break;
    case "de" : $st2 = "de"; break;
    case "est": $st2 = "E"; break;
    case "es" : $st2 = "E"; break;
    case "huit": $st2 = "uit"; break;
    case "les": $st2 = "lE"; break;
    case "mer": $st2 = "mEr"; break;
    case "mes": $st2 = "mE"; break;
    case "ressent": $st2 = "res2"; break;
    case "serf": $st2 = "sEr"; break;
    case "serfs": $st2 = "sEr"; break;
    case "sept": $st2 = "sEt"; break;
    case "septième": $st2 = "sEtiEm"; break;
    case "ses": $st2 = "sE"; break;
    case "tes": $st2 = "tE"; break;
    default:
      if(_sonnex_mb_startswith($st, "tien"))
        return 't'._sonnex_sonx("ien".mb_substr($st, 4));
  
  $cache =$st;
  
  return _sonnex_sonx($st);
  }
  
}