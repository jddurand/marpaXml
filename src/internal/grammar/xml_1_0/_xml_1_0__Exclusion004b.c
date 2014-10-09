/************************************************
  _Exclusion004 ~ 'Name - _Gen083'
  Name ::= NameStartChar _Gen011_any
  _Gen011_any ::= _Gen011 *
  _Gen011 ::= NameChar
  _Gen083 ::= _Gen077 _Gen079 _Gen081
  _Gen077 ::= _Lex023
  _Gen077 ::= _Lex024
  _Gen079 ::= _Lex025
  _Gen079 ::= _Lex026
  _Gen081 ::= _Lex027
  _Gen081 ::= _Lex028
  <_Lex023> ~ 'X'
  <_Lex024> ~ 'x'
  <_Lex025> ~ 'M'
  <_Lex026> ~ 'm'
  <_Lex027> ~ 'L'
  <_Lex028> ~ 'l'
  NameChar ::= NameStartChar
  NameChar ::= _Lex004
  <NameStartChar> ~ [:A-Z_a-z\x{c0}-\x{d6}\x{d8}-\x{f6}\x{f8}-\x{2ff}\x{370}-\x{37d}\x{37f}-\x{1fff}\x{200c}-\x{200d}\x{2070}-\x{218f}\x{2c00}-\x{2fef}\x{3001}-\x{d7ff}\x{f900}-\x{fdcf}\x{fdf0}-\x{fffd}\x{10000}-\x{effff}]
  <_Lex004> ~ [-.0-9\x{b7}\x{300}-\x{36f}\x{203f}-\x{2040}]

  which means:

  _Exclusion003 ~ Name minus [xX][mM][lL]
  
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion004b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  size_t               sizel = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_TRUE;
  signed int           lastthreei[3] = {0, 0, 0};
  marpaWrapperBool_t   noTestOnGen080b = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  /* Do the if only on the three first characters ... */
  do {
    if (sizel == 0) {
      if (!
	  ((currenti == 0x3a) /* : */ ||
	   (currenti >= 0x41 && currenti <= 0x5a) /* [A-Z] */ ||
	   (currenti == 0x5f) /* _ */ ||
	   (currenti >= 0x61 && currenti <= 0x7a) /* [a-z] */ ||
	   (currenti >= 0xc0 && currenti <= 0xd6) /* [#xc0-#xd6] */ ||
	   (currenti >= 0xd8 && currenti <= 0xf6) /* [#xd8-#xf6] */ ||
	   (currenti >= 0xf8 && currenti <= 0x2ff) /* [#xf8-#x2ff] */ ||
	   (currenti >= 0x370 && currenti <= 0x37d) /* [#x370-#x37d] */ ||
	   (currenti >= 0x37f && currenti <= 0x1fff) /* [#x37f-#x1fff] */ ||
	   (currenti >= 0x200c && currenti <= 0x200d) /* [#x200c-#x200d] */ ||
	   (currenti >= 0x2070 && currenti <= 0x218f) /* [#x2070-#x218f] */ ||
	   (currenti >= 0x2c00 && currenti <= 0x2fef) /* [#x2c00-#x2fef] */ ||
	   (currenti >= 0x3001 && currenti <= 0xd7ff) /* [#x3001-#xd7ff] */ ||
	   (currenti >= 0xf900 && currenti <= 0xfdcf) /* [#xf900-#xfdcf] */ ||
	   (currenti >= 0xfdf0 && currenti <= 0xfffd) /* [#xfdf0-#xfffd] */ ||
	   (currenti >= 0x10000 && currenti <= 0xeffff) /* [#x10000-#xeffff] */)) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
	break;
      }
    } else if (!
	       ((currenti == 0x3a) /* : */ ||
		(currenti >= 0x41 && currenti <= 0x5a) /* [A-Z] */ ||
		(currenti == 0x5f) /* _ */ ||
		(currenti >= 0x61 && currenti <= 0x7a) /* [a-z] */ ||
		(currenti >= 0xc0 && currenti <= 0xd6) /* [#xc0-#xd6] */ ||
		(currenti >= 0xd8 && currenti <= 0xf6) /* [#xd8-#xf6] */ ||
		(currenti >= 0xf8 && currenti <= 0x2ff) /* [#xf8-#x2ff] */ ||
		(currenti >= 0x370 && currenti <= 0x37d) /* [#x370-#x37d] */ ||
		(currenti >= 0x37f && currenti <= 0x1fff) /* [#x37f-#x1fff] */ ||
		(currenti >= 0x200c && currenti <= 0x200d) /* [#x200c-#x200d] */ ||
		(currenti >= 0x2070 && currenti <= 0x218f) /* [#x2070-#x218f] */ ||
		(currenti >= 0x2c00 && currenti <= 0x2fef) /* [#x2c00-#x2fef] */ ||
		(currenti >= 0x3001 && currenti <= 0xd7ff) /* [#x3001-#xd7ff] */ ||
		(currenti >= 0xf900 && currenti <= 0xfdcf) /* [#xf900-#xfdcf] */ ||
		(currenti >= 0xfdf0 && currenti <= 0xfffd) /* [#xfdf0-#xfffd] */ ||
		(currenti >= 0x10000 && currenti <= 0xeffff) /* [#x10000-#xeffff] */) &&
	       !
	       ((currenti == 0x2d) /* - */ ||
		(currenti == 0x2e) /* . */ ||
		(currenti >= 0x30 && currenti <= 0x39) /* [0-9] */ ||
		(currenti == 0xb7) /* #xb7 */ ||
		(currenti >= 0x300 && currenti <= 0x36f) /* [#x300-#x36f] */ ||
		(currenti >= 0x203f && currenti <= 0x2040) /* [#x203f-#x2040] */)) {
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
    } else {
      noTestOnGen080b = MARPAWRAPPER_BOOL_TRUE; /* Token is longer than 3: no test on [xX][mM][lL] needed */
      break;
    }
  } while (streamInUtf8_nexti(streamInp, &currenti) == STREAMIN_BOOL_TRUE);
  
  if (noTestOnGen080b == MARPAWRAPPER_BOOL_TRUE) {
    while (streamInUtf8_nexti(streamInp, &currenti) == STREAMIN_BOOL_TRUE) {
      if (!
	  ((currenti == 0x3a) /* : */ ||
	   (currenti >= 0x41 && currenti <= 0x5a) /* [A-Z] */ ||
	   (currenti == 0x5f) /* _ */ ||
	   (currenti >= 0x61 && currenti <= 0x7a) /* [a-z] */ ||
	   (currenti >= 0xc0 && currenti <= 0xd6) /* [#xc0-#xd6] */ ||
	   (currenti >= 0xd8 && currenti <= 0xf6) /* [#xd8-#xf6] */ ||
	   (currenti >= 0xf8 && currenti <= 0x2ff) /* [#xf8-#x2ff] */ ||
	   (currenti >= 0x370 && currenti <= 0x37d) /* [#x370-#x37d] */ ||
	   (currenti >= 0x37f && currenti <= 0x1fff) /* [#x37f-#x1fff] */ ||
	   (currenti >= 0x200c && currenti <= 0x200d) /* [#x200c-#x200d] */ ||
	   (currenti >= 0x2070 && currenti <= 0x218f) /* [#x2070-#x218f] */ ||
	   (currenti >= 0x2c00 && currenti <= 0x2fef) /* [#x2c00-#x2fef] */ ||
	   (currenti >= 0x3001 && currenti <= 0xd7ff) /* [#x3001-#xd7ff] */ ||
	   (currenti >= 0xf900 && currenti <= 0xfdcf) /* [#xf900-#xfdcf] */ ||
	   (currenti >= 0xfdf0 && currenti <= 0xfffd) /* [#xfdf0-#xfffd] */ ||
	   (currenti >= 0x10000 && currenti <= 0xeffff) /* [#x10000-#xeffff] */) &&
	  !
	  ((currenti == 0x2d) /* - */ ||
	   (currenti == 0x2e) /* . */ ||
	   (currenti >= 0x30 && currenti <= 0x39) /* [0-9] */ ||
	   (currenti == 0xb7) /* #xb7 */ ||
	   (currenti >= 0x300 && currenti <= 0x36f) /* [#x300-#x36f] */ ||
	   (currenti >= 0x203f && currenti <= 0x2040) /* [#x203f-#x2040] */)) {
	break;
      }
      sizel++;
    }
  }

  /* Mark it anyway */
  if (streamInUtf8_userMarkPreviousb(streamInp, xml_1_0__Exclusion004) == STREAMIN_BOOL_FALSE) {
    rcb = MARPAWRAPPER_BOOL_FALSE;
  }

  if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
    rcb = MARPAWRAPPER_BOOL_FALSE;
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    if (noTestOnGen080b == MARPAWRAPPER_BOOL_FALSE &&
	(lastthreei[0] == 'x' || lastthreei[0] == 'X') &&
	(lastthreei[1] == 'm' || lastthreei[1] == 'M') &&
	(lastthreei[1] == 'l' || lastthreei[2] == 'L')) {
      rcb = MARPAWRAPPER_BOOL_FALSE;
    } else {
      *sizelp = sizel;
    }
  }

  return rcb;
}
