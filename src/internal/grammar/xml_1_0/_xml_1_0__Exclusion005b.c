/************************************************
  _Exclusion005 ~ 'Char_any - _Gen085'
  Char ~ [\x{9}\x{a}\x{d}\x{20}-\x{d7ff}\x{e000}-\x{fffd}\x{10000}-\x{10ffff}]
  _Gen085 ::= Char_any _Lex016 Char_any
  _Lex016 ~ ']]>'
  
  which means:

  _Exclusion005 ~ Char_any - ']]>'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion005b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  size_t             sizeCharl;
  size_t             sizel;
  signed int         lastthreei[3];

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  /* Consume any Char - we KNOW in advance that Char does not play with utf8 mark and have a size 1 */
  sizel = 0;
  while(_xml_1_0_Charb(xml_1_0p, currenti, streamInp, &sizeCharl) == MARPAWRAPPER_BOOL_TRUE) {
    if (sizel == 0) {
      lastthreei[0] = currenti;
    } else if (sizel == 1) {
      lastthreei[1] = currenti;
    } else if (sizel == 2) {
      if (lastthreei[0] == ']' && lastthreei[1] == ']' && currenti == '>') {
	break;
      }
      lastthreei[2] = currenti;
    } else {
      if (lastthreei[1] == ']' && lastthreei[2] == ']' && currenti == '>') {
	break;
      }
      lastthreei[0] = lastthreei[1];
      lastthreei[1] = lastthreei[2];
      lastthreei[2] = currenti;
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
