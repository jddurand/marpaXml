/************************************************
  _Exclusion004 ~ 'Name - _Gen080'
  Name ::= NameStartChar _Gen012_any
  _Gen012 ::= NameChar
  NameChar ::= NameStartChar
  NameChar ::= _Lex004
  _Gen080 ::= _Gen074 _Gen076 _Gen078
  _Gen074 ::= _Lex021
  _Gen074 ::= _Lex022
  _Gen076 ::= _Lex023
  _Gen076 ::= _Lex024
  _Gen078 ::= _Lex025
  _Gen078 ::= _Lex026
  _Lex021 ~ 'X'
  _Lex022 ~ 'x'
  _Lex023 ~ 'M'
  _Lex024 ~ 'm'
  _Lex025 ~ 'L'
  _Lex026 ~ 'l'

  which means:

  _Exclusion003 ~ Name minus [xX][mM][lL]
  
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion004b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  size_t               sizel = 0;
  size_t               dummySizel = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;
  signed int           lastthreei[3];
  marpaWrapperBool_t   noMoreTestb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  /* Do the if only on the three first character ... */
  do {
    if (sizel == 0 && _xml_1_0_NameStartCharb(xml_1_0p, currenti, streamInp, &dummySizel) == MARPAWRAPPER_BOOL_FALSE) {
      rcb = MARPAWRAPPER_BOOL_FALSE;
      break;
    } else if (_xml_1_0_NameStartCharb(xml_1_0p, currenti, streamInp, &sizel) == MARPAWRAPPER_BOOL_FALSE) {
      break;
    }
    if (sizel++ <= 2) {
      switch (sizel) {
      case 1:
	lastthreei[0] = currenti;
	break;
      case 2:
	lastthreei[1] = currenti;
	break;
      case 3:
	lastthreei[2] = currenti;
	break;
      default:
	/* Never reached */
	break;
      }
      noMoreTestb = MARPAWRAPPER_BOOL_TRUE; /* No more test needed */
      break;
    }
    currenti = streamInUtf8_nexti(streamInp);
  } while (currenti >= 0);

  /* And stop the if when more */
  if (noMoreTestb == MARPAWRAPPER_BOOL_TRUE) {
    while ((currenti = streamInUtf8_nexti(streamInp)) >= 0) {
      if (_xml_1_0_NameStartCharb(xml_1_0p, currenti, streamInp, &sizel) == MARPAWRAPPER_BOOL_FALSE) {
	break;
      }
    }
  }

  if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
    rcb = MARPAWRAPPER_BOOL_FALSE;
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    if (sizel == 3 &&
	(lastthreei[0] == 'x' || lastthreei[0] == 'X') &&
	(lastthreei[1] == 'm' || lastthreei[0] == 'M') &&
	(lastthreei[1] == 'l' || lastthreei[0] == 'L')) {
      rcb = MARPAWRAPPER_BOOL_FALSE;
    } else {
    }
    *sizelp = sizel;
  }

  return rcb;
}