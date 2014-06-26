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
    if (sizel == 0) {
      lasttwoi[0] = currenti;
    } else if (sizel == 1) {
      if (lasttwoi[0] == '?' && currenti == '>') {
	break;
      }
      lasttwoi[1] = currenti;
    } else {
      if (lasttwoi[1] == '?' && currenti == '>') {
	break;
      }
      lasttwoi[0] = lasttwoi[1];
      lasttwoi[1] = currenti;
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
