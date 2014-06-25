/************************************************
  _Exclusion005 ~ 'Char_any - _Gen233'
  Char ~ [\x{9}\x{a}\x{d}\x{20}-\x{d7ff}\x{e000}-\x{fffd}\x{10000}-\x{10ffff}]
  _Gen233 ::= Char_any _Gen231 Char_any
  _Gen231 ::= _Lex068
  _Gen231 ::= _Lex016
  _Lex068 ~ '<!['
  _Lex016 ~ ']]>'
  
  which means:

  _Exclusion005 ~ Char_any - ('<![' or ']]>')
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion006b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  size_t             sizeCharl;
  size_t             sizeLex016l;
  size_t             sizeLex068l;
  size_t             sizel;

  if (_xml_1_0__Lex016b(xml_1_0p, currenti, streamInp, &sizeLex016l) == MARPAWRAPPER_BOOL_TRUE ||
      _xml_1_0__Lex068b(xml_1_0p, currenti, streamInp, &sizeLex068l) == MARPAWRAPPER_BOOL_TRUE) {
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
