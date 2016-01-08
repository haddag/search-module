<?php
function isVowel($char) {
    static $VOWELS = array(
        'a', 'â', 'à', 'ä', 'e', 'é', 'è', 'ê', 'ë', 'i', 'î', 'ï', 'o', 'ô',
        'ö', 'u', 'ù', 'û', 'ü', 'y', 'œ'
    );

    return in_array($char, $VOWELS);
}

function isConson($char) {
    static $CONSONS = array(
        'b', 'c', 'ç', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q',
        'r', 's', 't', 'v', 'w', 'x', 'y', 'z'
    );

    return in_array($char, $CONSONS);
}

function mb_startswith($string, $start) {
    if(mb_strlen($string) < mb_strlen($start)) return FALSE;
    if(mb_substr($string, 0, mb_strlen($start)) == $start) return TRUE;
    return FALSE;
}

function sonx($st) {
    if($st == "") return "";

    $length = mb_strlen($st);
    $head = mb_substr($st, 0, 1);
    $tail = mb_substr($st, 1);

    // Apostroph is ignored/silent
    if($head == "'") return sonx($tail);
    if($head == "’") return sonx($tail);

    // Starting with 'a'
    if($st == "a") return "a";
    if($st == "aient") return "E";
    if($st == "ain") return "1";
    if(mb_startswith($st, "ain")) {
        $v = mb_substr($st, 3, 1);
        $cs = mb_substr($st, 4);
        if(isVowel($v)) return "E".sonx($v.$cs);
        return "1".sonx($v.$cs);
    }
    if($st == "ais") return "E";
    if(mb_startswith($st, "ais")) {
        $v = mb_substr($st, 3, 1);
        $cs = mb_substr($st, 4);
        if($v == 's') return "Es".sonx($cs);
        if(isVowel($v)) return "Ez".sonx($v.$cs);
        return "Es".sonx($v.$cs);
    }
    if($st == "ail") return "ai";
    if(mb_startswith($st, "aill")) return "ai".sonx(mb_substr($st, 4));
    if(mb_startswith($st, "ai")) return 'E'.sonx(mb_substr($st, 2));
    if(mb_startswith($st, "amm")) return "am".sonx(mb_substr($st, 3));
    if(mb_startswith($st, "am")) {
        $c = mb_substr($st, 2, 1);
        $cs = mb_substr($st, 3);
        if($c == 'm') return "am".sonx($cs);
        if(isVowel($c)) return "am".sonx($c.$cs);
        return '2'.sonx($c.$cs);
    }
    if($st == "an") return "2";
    if(mb_startswith($st, "an")) {
        $c = mb_substr($st, 2, 1);
        $cs = mb_substr($st, 3);
        if($c == 'n') return "an".sonx($cs);
        if($c == 't') return "2t".sonx($cs);
        if(isVowel($c)) return "an".sonx($c.$cs);
        return '2'.sonx($c.$cs);
    }
    if($st == "assent") return "as";
    if(mb_startswith($st, "as")) {
        $c = mb_substr($st, 2, 1);
        $cs = mb_substr($st, 3);
        if($c == 's') return "as".sonx($cs);
        if(isConson($c)) return "as".sonx($c.$cs);
        return "az".sonx($c.$cs);
    }
    if(mb_startswith($st, "au")) return 'o'.sonx(mb_substr($st, 2));
    if($st == "ay") return "E";
    if($st == "ays") return "E";

    if($head == 'à') return 'a'.sonx($tail);
    if($head == 'â') {
        $c = mb_substr($st, 1, 1);
        $cs = mb_substr($st, 2);
        if($c == 't') return 'a'.sonx('t'.$cs);
        return 'a'.sonx($c.$cs);
    }

    // Starting with 'b'
    if($st == "b") return "";
    if(mb_startswith($st, "bb")) return 'b'.sonx(mb_substr($st, 2));

    // Starting with 'c'
    if($st == "c") return "";
    if(mb_startswith($st, "ca")) return 'k'.sonx('a'.mb_substr($st, 2));
    if(mb_startswith($st, "cc")) {
        $v = mb_substr($st, 2, 1);
        $cs = mb_substr($st, 3);
        if($v == 'o') return 'k'.sonx('o'.$cs);
        if($v == 'u') return 'k'.sonx('u'.$cs);
        return "ks".sonx($cs);
    }
    if(mb_startswith($st, "ce")) return 's'.sonx('e'.mb_substr($st, 2));
    if(mb_startswith($st, "c'")) return 's'.sonx(mb_substr($st, 2));
    if(mb_startswith($st, "c’")) return 's'.sonx(mb_substr($st, 2));
    if(mb_startswith($st, "chao")) return 'k'.sonx("ao".mb_substr($st, 4));
    if(mb_startswith($st, "chl")) return "kl".sonx(mb_substr($st, 3));
    if(mb_startswith($st, "choe")) return 'k'.sonx("oe".mb_substr($st, 4));
    if(mb_startswith($st, "chœ")) return 'k'.sonx("oe".mb_substr($st, 3));
    if(mb_startswith($st, "chr")) return "kr".sonx(mb_substr($st, 3));
    if(mb_startswith($st, "ch")) return 'C'.sonx(mb_substr($st, 2));
    if(mb_startswith($st, "ci")) return 's'.sonx('i'.mb_substr($st, 2));
    if(mb_startswith($st, "ck")) return 'k'.sonx(mb_substr($st, 2));
    if(mb_startswith($st, "coeu")) return 'k'.sonx ("oeu".mb_substr($st, 4));
    if(mb_startswith($st, "compt")) return "k3t".sonx(mb_substr($st, 5));
    if(mb_startswith($st, "cœu")) return 'k'.sonx("œu".mb_substr($st, 3));
    if(mb_startswith($st, "co")) return 'k'.sonx('o'.mb_substr($st, 2));
    if(mb_startswith($st, "cuei")) return "ke".sonx('i'.mb_substr($st, 4));
    if(mb_startswith($st, "cu")) return 'k'.sonx('u'.mb_substr($st, 2));
    if(mb_startswith($st, "cy")) return 's'.sonx('y'.mb_substr($st, 2));
    if($head == "c") return 'k'.sonx($tail);
    if($head == 'ç') return 's'.sonx($tail);

    // Starting with 'd'
    if($st == "d") return "";
    if($st == "ds") return "";
    if(mb_startswith($st, "dd")) return 'd'.sonx(mb_substr($st, 2));

    // Starting with 'e'
    if($st == "e") return "";
    if($st == "ec") return "Ec";
    if($st == "ef") return "Ef";
    if($st == "eaux") return "o";
    if(mb_startswith($st, "eann")) return "an".sonx(mb_substr($st, 4));
    if(mb_startswith($st, "ean")) return '2'.sonx(mb_substr($st, 3));
    if(mb_startswith($st, "eau")) return 'o'.sonx(mb_substr($st, 3));
    if(mb_startswith($st, "eff")) return "Ef".sonx(mb_substr($st, 3));
    if(mb_startswith($st, "egm")) return 'E'.sonx("gm".mb_substr($st, 3));
    if($st == "ein") return "1";
    if(mb_startswith($st, "ein")) {
        $c = mb_substr($st, 3, 1);
        $cs = mb_substr($st, 4);
        if($c == 'n') return "En".sonx($cs);
        if(isVowel($c)) return "En".sonx($c.$cs);
        return '1'.sonx($c.$cs);
    }
    if(mb_startswith($st, "ei")) return 'E'.sonx(mb_substr($st, 2));
    if(mb_startswith($st, "ell")) return "El".sonx(mb_substr($st,3));
    if(mb_startswith($st, "el")) {
        $c = mb_substr($st, 2, 1);
        $cs = mb_substr($st, 3);
        if(isConson($c)) return 'E'.sonx('l'.$c.$cs);
        return 'e'.sonx('l'.$c.$cs);
    }
    if(mb_startswith($st, "emm")) return "Em".sonx(mb_substr($st,3));
    if(mb_startswith($st, "emp")) return '2'.sonx(mb_substr($st,3));
    if(mb_startswith($st, "enn")) return "En".sonx(mb_substr($st,3));
    if($st == "en") return "2";
    if(mb_startswith($st, "en")) {
        $c = mb_substr($st, 2, 1);
        $cs = mb_substr($st, 3);
        if(isVowel($c)) return "en".sonx($c.$cs);
        return '2'.sonx($c.$cs);
    }
    if($st == "er") return "E";
    if($st == "ert") return "Er";
    if(mb_startswith($st, "err")) return "Er".sonx(mb_substr($st,3));
    if(mb_startswith($st, "erf")) return "Er".sonx('f'.mb_substr($st,3));
    if($st == "es") return "";
    if(mb_startswith($st, "esch")) return "EC".sonx(mb_substr($st,4));
    if($st == "essent") return "Es";
    if(mb_startswith($st, "es")) {
        $c = mb_substr($st, 2, 1);
        $cs = mb_substr($st, 3);
        if($c == 'h') return 'E'.sonx('h'.$cs);
        if($c == 'n') return 'E'.sonx('n'.$cs);
        if($c == 's') return "Es".sonx($cs);
        if(isConson($c)) return "Es".sonx($c.$cs);
        return "ez".sonx($c.$cs);
    }
    if(mb_startswith($st, "és")) {
        $c = mb_substr($st, 2, 1);
        $cs = mb_substr($st, 3);
        if($c == 's') return "Es".sonx($cs);
        if(isConson($c)) return "Es".sonx($c.$cs);
        return "Ez".sonx($c.$cs);
    }
    if(mb_startswith($st, "ett")) return "Et".sonx(mb_substr($st, 4));
    if($st == "et") return "E";
    if(mb_startswith($st, "et")) return "et".sonx(mb_substr($st, 2));
    if(mb_startswith($st, "eun")) {
        $c = mb_substr($st, 3, 1);
        $cs = mb_substr($st, 4);
        if(isVowel($c)) return "en".sonx($c.$cs);
        return '1'.sonx($c.$cs);
    }
    if($st == "eux") return "e";
    if(mb_startswith($st, "euxi")) return "ez".sonx('i'.mb_substr($st, 4));
    if(mb_startswith($st, "eu")) return 'e'.sonx(mb_substr($st, 2));
    if($st == "ex") return "Eks";
    if(mb_startswith($st, "ey")) {
        $c = mb_substr($st, 2, 1);
        $cs = mb_substr($st, 3);
        if(isConson($c)) return 'E'.sonx($c.$cs);
        return 'E'.sonx('y'.$c.$cs);
    }
    if($st == "ez") return "E";

    if($head == 'è') return 'E'.sonx($tail);
    if($head == 'ê') {
        $c = mb_substr($st, 1, 1);
        $cs = mb_substr($st, 2);
        if($c == 't') return 'E'.sonx('t'.$cs);
        return 'E'.sonx($c.$cs);
    }
    if(mb_startswith($st, "ël")) return 'E'.sonx('l'.mb_substr($st, 2));
    if($st == "é") return "E";
    if($head == 'é') {
        $c = mb_substr($st, 1, 1);
        $cs = mb_substr($st, 2);
        if($c == 't')  return "Et".sonx($cs);
        return 'E'.sonx($c.$cs);
    }

    // Starting with 'f'
    if(mb_startswith($st, "ff")) return 'f'.sonx(mb_substr($st, 2));

    // Starting with 'g'
    if($st == "g") return "";
    if($st == "ge") return 'j';
    if(mb_startswith($st, "ge")) return 'j'.sonx(mb_substr($st, 2));
    if(mb_startswith($st, "gé")) return 'jE'.sonx(mb_substr($st, 2));
    if(mb_startswith($st, "gi")) return 'ji'.sonx(mb_substr($st, 2));
    if(mb_startswith($st, "gn")) return 'n'.sonx(mb_substr($st, 2));
    if(mb_startswith($st, "gy")) return 'j'.sonx('y'.mb_substr($st, 2));
    if(mb_startswith($st, "guë")) return "gu".sonx(mb_substr($st, 2));
    if(mb_startswith($st, "gu")) return 'g'.sonx(mb_substr($st, 2));
    if(mb_startswith($st, "gg")) return 'g'.sonx(mb_substr($st, 2));

    // Starting with 'h'
    if($head == 'h') return sonx($tail);

    // Starting with 'i'
    if($st == "ic") return "ik";
    if($st == "ics") return "ik";
    if(mb_startswith($st, "ienn")) return "iEn".sonx(mb_substr($st, 4));
    if(mb_startswith($st, "ien")) return "i1".sonx(mb_substr($st, 3));
    if($st == "in") return "1";
    if(mb_startswith($st, "in")) {
        $c = mb_substr($st, 2, 1);
        $cs = mb_substr($st, 3);
        if($c == 'n') return "in".sonx($cs);
        if(isVowel($c)) return "in".sonx($c.$cs);
        return '1'.sonx($c.$cs);
    }
    if($st == "issent") return "is";
    if($st == "is") return "i";
    if(mb_startswith($st, "is")) {
        $c = mb_substr($st, 2, 1);
        $cs = mb_substr($st, 3);
        if($c == 's') return "is".sonx($cs);
        if(isConson($c)) return "is".sonx($c.$cs);
        return "iz".sonx($c.$cs);
    }
    if(mb_startswith($st, "ixi")) return "iz".sonx('i'.mb_substr($st, 3));
    if(mb_startswith($st, "ill")) return 'i'.sonx(mb_substr($st, 3));
    if($head == "i") return 'i'.sonx($tail);

    if($head == "ï") return 'i'.sonx($tail);

    // Starting with 'l'
    if(mb_startswith($st, "ll")) return 'l'.sonx(mb_substr($st, 2));

    // Starting with 'm'
    if(mb_startswith($st, "mm")) return 'm'.sonx(mb_substr($st, 2));

    // Starting with 'n'
    if(mb_startswith($st, "nn")) return 'n'.sonx(mb_substr($st, 2));

    // Starting with 'o'
    if(mb_startswith($st, "occ")) return "ok".sonx(mb_substr($st, 3));
    if(mb_startswith($st, "oeu")) return 'e'.sonx(mb_substr($st, 3));
    if(mb_startswith($st, "œu")) return 'e'.sonx(mb_substr($st, 2));
    if($head == "œ") return 'e'.sonx($tail);
    if($st == "oient") return "Ua";
    if(mb_startswith($st, "oin")) return "U1".sonx(mb_substr($st, 3));
    if(mb_startswith($st, "ois")) return "Ua".sonx(mb_substr($st, 3));
    if(mb_startswith($st, "omm")) return "om".sonx(mb_substr($st, 3));
    if(mb_startswith($st, "om")) {
        $c = mb_substr($st, 2, 1);
        $cs = mb_substr($st, 3);
        if(isVowel($c)) return "om".sonx($c.$cs);
        return '3'.sonx($c.$cs);
    }
    if(mb_startswith($st, "onn")) return "on".sonx(mb_substr($st, 3));
    if(mb_startswith($st, "on")) {
        $c = mb_substr($st, 2, 1);
        $cs = mb_substr($st, 3);
        if(isVowel($c)) return "on".sonx($c.$cs);
        return "3".sonx($c.$cs);
    }
    if($st == "ossent") return "os";
    if(mb_startswith($st, "os")) {
        $c = mb_substr($st, 2, 1);
        $cs = mb_substr($st, 3);
        if($c == 's') return "os".sonx($cs);
        if(isConson($c)) return "os".sonx($c.$cs);
        return "oz".sonx($c.$cs);
    }
    if(mb_startswith($st, "ou")) return 'U'.sonx(mb_substr($st, 2));
    if(mb_startswith($st, "où")) return 'U'.sonx(mb_substr($st, 2));
    if(mb_startswith($st, "oû")) return 'U'.sonx(mb_substr($st, 2));

    if($head == "ô") return 'o'.sonx($tail);
    if($head == "ö") return 'o'.sonx($tail);

    // Starting with 'p'
    if($st == "p") return "";
    if($st == "ps") return "";
    if(mb_startswith($st, "ph")) return 'f'.sonx(mb_substr($st, 2));
    if(mb_startswith($st, "pp")) return 'p'.sonx(mb_substr($st, 2));
    if(mb_startswith($st, "pays")) return "pE".sonx ("is".mb_substr($st, 4));

    // Starting with 'q'
    if(mb_startswith($st, "qur")) return "ku".sonx('r'.mb_substr($st, 3));
    if(mb_startswith($st, "qu")) return 'k'.sonx(mb_substr($st, 2));
    if($head == 'q') return 'k'.sonx($tail);

    // Starting with 'r'
    if(mb_startswith($st, "rr")) return 'r'.sonx(mb_substr($st, 2));

    // Starting with 's'
    if($st == "s") return "";
    if(mb_startswith($st, "ss")) return 's'.sonx(mb_substr($st, 2));
    if(mb_startswith($st, "st")) return "st".sonx(mb_substr($st, 2));
    if(mb_startswith($st, "sci")) return 's'.sonx('i'.mb_substr($st, 3));

    // Starting with 't'
    if($st == "t") return "";
    if($st == "ts") return "";
    if(mb_startswith($st, "tier")) return 't'.sonx("ier".mb_substr($st,4));
    if(mb_startswith($st, "ti")) {
        $v = mb_substr($st, 2, 1);
        $cs = mb_substr($st, 3);
        if(isVowel($v)) return 's'.sonx('i'.$v.$cs);
        return 't'.sonx('i'.$v.$cs);
    }
    if(mb_startswith($st, "tt")) return 't'.sonx(mb_substr($st, 2));

    // Starting with 'u'
    if($st == "un") return "1";
    if($head == "û") return 'u'.sonx($tail);
    if($st == "ussent") return "us";
    if(mb_startswith($st, "us")) {
        $c = mb_substr($st, 2, 1);
        $cs = mb_substr($st, 3);
        if($c == 's') return "us".sonx($cs);
        if(isConson($c)) return "us".sonx($c.$cs);
        return "uz".sonx($c.$cs);
    }

    // Starting with 'v'
    // 'v' can be handled by the generic case since there is no special thing
    // about this letter, it’s always pronounced 'v' and never doubled.

    // Starting with 'w'
    if($head == "w") return 'v'.sonx($tail);

    // Starting with 'x'
    if($st == "x") return "";
    if(mb_startswith($st, "x")) {
        $c = mb_substr($st, 2, 1);
        $cs = mb_substr($st, 3);
        if($c == 'c') return "ks".sonx($cs);
        if(isVowel($c)) return "kz".sonx($c.$cs);
        return "ks".sonx($c.$cs);
    }

    // Starting with 'y'
    if($head == "y") return 'i'.sonx($tail);

    // Starting with 'z'
    if(mb_startswith($st, "zz")) return 'z'.sonx(mb_substr($st, 2));

    // Copy every other character as is;
    if(isConson($head) or isVowel($head)) {
        return $head.sonx($tail);
    } else {
        return sonx($tail);
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
            if(mb_startswith($st, "tien"))
                return 't'.sonx("ien".mb_substr($st, 4));
            return sonx($st);
    }
}

function clean_phrase($phrase) {
    return trim(preg_replace('/[ \t_,.;:!-]+/', ' ', $phrase));
}

function sonnex_phrase($phrase) {
    $phrase = clean_phrase($phrase);
    $words = explode(' ', $phrase);
    $sonnexs = array();
    foreach($words as $word) {
        $sonnexs[] = sonnex($word);
    }

    return $sonnexs;
}

function sonnex_libelle($libelle) {
    $libelle = clean_phrase($libelle);
    $libelle = preg_replace(
        "/( aux | de la | de l'| des | les | de | du | d')/",
        ' ',
        $libelle
    );

    return sonnex_phrase($libelle);
}

mb_internal_encoding("UTF-8");
