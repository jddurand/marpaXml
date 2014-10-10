/************************************************
  _Exclusion005 ~ 'Char_any - _Gen088'
  Char_any ::= Char *
  <Char> ~ [\x{9}\x{a}\x{d}\x{20}-\x{d7ff}\x{e000}-\x{fffd}\x{10000}-\x{10ffff}]
  _Gen088 ::= Char_any _Lex017 Char_any
  <_Lex017> ~ ']]>'
  
  which means:

  _Exclusion005 ~ Char_any - ']]>' everywhere
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion005b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  size_t             sizel;
  signed int         lastthreei[3] = {0, 0, 0};

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  /* Consume any Char - we KNOW in advance that Char does not play with utf8 mark and have a size 1 */
  sizel = 0;
  while ((currenti == 0x9) /* #x9 */ ||
	 (currenti == 0xa) /* #xa */ ||
	 (currenti == 0xd) /* #xd */ ||
	 (currenti >= 0x20 && currenti <= 0xd7ff) /* [#x20-#xd7ff] */ ||
	 (currenti >= 0xe000 && currenti <= 0xfffd) /* [#xe000-#xfffd] */ ||
	 (currenti >= 0x10000 && currenti <= 0x10ffff) /* [#x10000-#x10ffff] */) {
#ifndef MARPAXML_NTRACE
  {
      marpaXmlLog_t *marpaXmlLogp = marpaWrapper_marpaXmlLogp(xml_1_0p->marpaWrapperp);
      MARPAXML_TRACEX("_xml_1_0__Exclusion005b : Accepted character 0x%lx", (long) currenti);
  }
#endif
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
#ifndef MARPAXML_NTRACE
        {
          marpaXmlLog_t *marpaXmlLogp = marpaWrapper_marpaXmlLogp(xml_1_0p->marpaWrapperp);
          MARPAXML_TRACEX("_xml_1_0__Exclusion005b : Got \"]]>\"");
        }
#endif
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

  if (sizel > 0) {
    if (streamInUtf8_userMarkPreviousb(streamInp, xml_1_0__Exclusion005) == STREAMIN_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
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
