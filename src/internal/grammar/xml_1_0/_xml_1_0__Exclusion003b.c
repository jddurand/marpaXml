/************************************************
  _Exclusion003 ~ 'Char_many - _Gen063'
  _Gen063 ::= Char_any _Lex020 Char_any
  _Lex020 ~ '?>'

  which means:

  _Exclusion003 ~ Char_many minus '?>'
  
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion003b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  size_t             sizeCharl;
  size_t             sizel;
  signed int         lasttwoi[2];

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  /* Consume many Char - we KNOW in advance that lex015 does not play with utf8 mark and have a size 1 */
  sizel = 0;
  while(_xml_1_0_Charb(xml_1_0p, currenti, streamInp, &sizeCharl) == MARPAWRAPPER_BOOL_TRUE) {
    /* For performance reason it is better to do the test on sizel >= 2 first: the probability  */
    /* to have two or more characters is much higher than having less than two characters       */
    if (sizel >= 2) {
      if (currenti == '>' && lasttwoi[1] == '?') {
	break;
      }
      lasttwoi[0] = lasttwoi[1];
      lasttwoi[1] = currenti;
    } else if (sizel == 1) {
      if (currenti == '>' && lasttwoi[0] == '?') {
	break;
      }
      lasttwoi[1] = currenti;
    } else {
      lasttwoi[0] = currenti;
    }
    sizel++;
    currenti = streamInUtf8_nexti(streamInp);
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
