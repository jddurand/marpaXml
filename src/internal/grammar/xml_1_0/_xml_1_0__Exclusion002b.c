/************************************************
  _Exclusion002 ~ '_Lex015_many - _Gen057'
  _Gen056 ::= _Lex015_any _Lex016 _Lex015_any
  _Lex016 ~ ']]>'

  which means:

  _Exclusion002 ~ _Lex015_many minus ']]>'
  
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion002b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  size_t             sizeLex015l;
  size_t             sizel;
  signed int         lastthreei[3];

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  /* Consume many Lex015 - we KNOW in advance that lex015 does not play with utf8 mark and have a size 1 */
  sizel = 0;
  while(_xml_1_0__Lex015b(xml_1_0p, currenti, streamInp, &sizeLex015l) == MARPAWRAPPER_BOOL_TRUE) {
    /* For performance reason it is better to do the test on sizel >= 3 first: the probability      */
    /* to have three or more characters is much higher than having less than three characters       */
    if (sizel >= 3) {
      if (currenti == '>' && lastthreei[1] == ']' && lastthreei[2] == ']') {
	break;
      }
      lastthreei[0] = lastthreei[1];
      lastthreei[1] = lastthreei[2];
      lastthreei[2] = currenti;
    } else if (sizel == 2) {
      if (currenti == '>' && lastthreei[0] == ']' && lastthreei[1] == ']') {
	break;
      }
      lastthreei[2] = currenti;
    } else if (sizel == 1) {
      lastthreei[1] = currenti;
    } else {
      lastthreei[0] = currenti;
    }
    sizel++;
    if (streamInUtf8_nexti(streamInp, &currenti) == STREAMIN_BOOL_FALSE) {
      break;
    }
  }
  if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (sizel > 0) {
    *sizelp = sizel;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
