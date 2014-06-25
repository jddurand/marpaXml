/************************************************
  _Exclusion003 ~ 'Char_any - _Gen061'
  _Gen061 ::= Char_any _Lex020 Char_any
  _Lex020 ~ '?>'

  which means:

  _Exclusion003 ~ Char_any minus _Lex020
  
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion003b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  size_t             sizeCharl;
  size_t             sizeLex020l;
  size_t             sizel;

  if (_xml_1_0__Lex020b(xml_1_0p, currenti, streamInp, &sizeLex020l) == MARPAWRAPPER_BOOL_TRUE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  /* Consume any Char */
  sizel = 0;
  while(_xml_1_0_Charb(xml_1_0p, currenti, streamInp, &sizeCharl) == MARPAWRAPPER_BOOL_TRUE) {
    sizel += sizeCharl;
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
