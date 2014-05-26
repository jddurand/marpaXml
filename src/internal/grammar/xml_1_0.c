#include <stdlib.h>
#include <errno.h>
#include "internal/grammar/xml_1_0.h"

/* Reference: http://www.w3.org/TR/2008/REC-xml-20081126/ */

static marpaWrapperBool_t _xml_1_0_buildGrammarb(xml_1_0_t *xml_1_0p, marpaWrapperOption_t *marpaWrapperOptionp);
static marpaWrapperBool_t _xml_1_0_buildSymbolsb(xml_1_0_t *xml_1_0p);
static marpaWrapperBool_t _xml_1_0_buildRulesb(xml_1_0_t *xml_1_0p);

/* Symbols */
typedef enum xml_1_0_symbol {
  /* Terminals */
  T_x20 = 0,
  T_S,
  T_Name,
  T_Char,
  T_Nmtoken,
  T_SystemLiteral,
  T_PubidLiteral,
  T_CharData,
  T_CData,
  T_CommentBeg,
  T_CommentEnd,
  T_CommentInterior,
  T_PiBeg,
  T_PiEnd,
  T_PITarget,
  T_PiInterior,
  T_CDStart,
  T_CDEnd,
  T_XmlBeg,
  T_XmlEnd,
  T_Version,
  T_Dquote,
  T_Squote,
  T_Equal,
  T_VersionNum,
  T_DoctypeBeg,
  T_Lbracket,
  T_Rbracket,
  T_Standalone,
  T_Yes,
  T_No,
  T_XTagBeg,
  T_XTagEnd,
  T_STagEnd,
  T_ETagEnd,
  T_ETagBeg,
  T_EmptyElemTagEnd,
  T_ElementDeclBeg,
  T_Empty,
  T_Any,
  T_QuestionMark,
  T_Star,
  T_Plus,
  T_Lparen,
  T_Rparen,
  T_Pipe,
  T_Comma,
  T_RparenStar,
  T_Pcdata,
  T_AttlistBeg,
  T_StringType,
  T_TypeId,
  T_TypeIdref,
  T_TypeIdrefs,
  T_TypeEntity,
  T_TypeEntities,
  T_TypeNmtoken,
  T_TypeNmtokens,
  T_Notation,
  T_Required,
  T_Implied,
  T_Fixed,
  T_SectBeg,
  T_Include,
  T_SectEnd,
  T_TOKIgnore,
  T_Ignore,
  T_CharRef,
  T_EntityRef,
  T_PEReference,
  T_EdeclBeg,
  T_Percent,
  T_System,
  T_Public,
  T_Ndata,
  T_Encoding,
  T_EncName,
  T_NotationBeg,
  T_AttValue,
  T_EntityValue,
  /* Non-terminals */
  S_document,
  S_Names,
  S_Nmtokens,
  S_Comment,
  S_PI,
  S_CDSect,
  S_prolog,
  S_XMLDecl,
  S_VersionInfo,
  S_Eq,
  S_Misc,
  S_doctypedecl,
  S_DeclSep,
  S_intSubset,
  S_markupdecl,
  S_extSubset,
  S_extSubsetDecl,
  S_SDDecl,
  S_element,
  S_STag,
  S_Attribute,
  S_ETag,
  S_content,
  S_EmptyElemTag,
  S_elementdecl,
  S_contentspec,
  S_children,
  S_cp,
  S_choice,
  S_seq,
  S_Mixed,
  S_AttlistDecl,
  S_AttDef,
  S_AttType,
  S_TokenizedType,
  S_EnumeratedType,
  S_NotationType,
  S_Enumeration,
  S_DefaultDecl,
  S_conditionalSect,
  S_includeSect,
  S_ignoreSect,
  S_ignoreSectContents,
  S_Reference,
  S_EntityDecl,
  S_GEDecl,
  S_PEDecl,
  S_EntityDef,
  S_PEDef,
  S_ExternalID,
  S_NDataDecl,
  S_TextDecl,
  S_extParsedEnt,
  S_EncodingDecl,
  S_NotationDecl,
  S_PublicID,
  S_XMLDeclMaybe,
  S_MiscAny,
  S_EncodingDeclMaybe,
  S_SDDeclMaybe,
  S_SMaybe,
  S_ContentInterior,
  S_ContentInteriorAny,
  S_intSubsetUnit,
  S_extSubsetDeclUnit,
  S_STagInterior,
  S_STagInteriorAny,
  S_CharDataMaybe,
  S_EmptyElemTagInterior,
  S_EmptyElemTagInteriorAny,
  S_Quantifier,
  S_QuantifierMaybe,
  S_ChoiceInterior,
  S_ChoiceInteriorMany,
  S_SeqInterior,
  S_SeqInteriorAny,
  S_MixedInterior,
  S_MixedInteriorAny,
  S_AttDefAny,
  S_NotationTypeInterior,
  S_NotationTypeInteriorAny,
  S_EnumerationInterior,
  S_EnumerationInteriorAny,
  S_ignoreSectContentsAny,
  S_ignoreSectContentsInterior,
  S_ignoreSectContentsInteriorAny,
  S_VersionInfoMaybe,
  S_DoctypeEnd,
  S_STagBeg,
  S_EmptyElemTagBeg,
  S_ElementDeclEnd,
  S_AttlistEnd,
  S_NotationEnd,
  S_EdeclEnd,
  _SYMBOL_MAX
} xml_1_0_symbol_t;

#define XML_1_0_TERMINAL_MAX T_EntityValue

/*******************/
/* xml_1_0_t_newp  */
/*******************/
xml_1_0_t *xml_1_0_newp(marpaWrapperOption_t *marpaWrapperOptionp) {
  xml_1_0_t           *xml_1_0p;
  marpaWrapperOption_t marpaWrapperOption;

  /* Fill the defaults */
  if (marpaWrapperOptionp == NULL) {
    marpaWrapper_optionDefaultb(&marpaWrapperOption);
  } else {
    marpaWrapperOption = *marpaWrapperOptionp;
  }

  xml_1_0p = malloc(sizeof(xml_1_0_t));
  if (xml_1_0p == NULL) {
    marpaWrapper_log(marpaWrapperOption.logCallbackp,
		     marpaWrapperOption.logCallbackDatavp,
		     NULL,
		     marpaWrapperOption.logLevelWantedi,
		     MARPAWRAPPERERRORORIGIN_SYSTEM,
		     errno,
		     "malloc()",
		     MARPAWRAPPER_LOGLEVEL_ERROR);
    return NULL;
  }

  xml_1_0p->marpaWrapperp = NULL;
  xml_1_0p->marpaWrapperSymbolArrayp = NULL;
  xml_1_0p->marpaWrapperSymbolArrayLengthi = 0;
  xml_1_0p->marpaWrapperRuleArrayp = NULL;
  xml_1_0p->marpaWrapperRuleArrayLengthi = 0;

  if (_xml_1_0_buildGrammarb(xml_1_0p, &marpaWrapperOption) == MARPAWRAPPER_BOOL_FALSE) {
    xml_1_0_destroyv(&xml_1_0p);
  }
  
  return xml_1_0p;
}

/*********************/
/* xml_1_0_destroyv  */
/*********************/
void xml_1_0_destroyv(xml_1_0_t **xml_1_0pp) {
  xml_1_0_t *xml_1_0p;

  if (xml_1_0pp != NULL) {
    xml_1_0p = *xml_1_0pp;

    if (xml_1_0p != NULL) {
      if (xml_1_0p->marpaWrapperp != NULL) {
	marpaWrapper_destroyv(&(xml_1_0p->marpaWrapperp));
      }
      if (xml_1_0p->marpaWrapperSymbolArrayp != NULL) {
	free(xml_1_0p->marpaWrapperSymbolArrayp);
      }
      if (xml_1_0p->marpaWrapperSymbolArrayp != NULL) {
	free(xml_1_0p->marpaWrapperRuleArrayp);
      }
      free(xml_1_0p);
    }

    *xml_1_0pp = NULL;
  }
}

/**************************/
/* _xml_1_0_buildGrammarb */
/**************************/
static marpaWrapperBool_t _xml_1_0_buildGrammarb(xml_1_0_t *xml_1_0p, marpaWrapperOption_t *marpaWrapperOptionp) {

  xml_1_0p->marpaWrapperp = marpaWrapper_newp(marpaWrapperOptionp);
  if (xml_1_0p->marpaWrapperp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (_xml_1_0_buildSymbolsb(xml_1_0p) == MARPAWRAPPER_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (_xml_1_0_buildRulesb(xml_1_0p) == MARPAWRAPPER_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (marpaWrapper_g_precomputeb(xml_1_0p->marpaWrapperp) == MARPAWRAPPER_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  return MARPAWRAPPER_BOOL_TRUE;
}

/**************************/
/* _xml_1_0_buildSymbolsb */
/**************************/
static marpaWrapperBool_t _xml_1_0_buildSymbolsb(xml_1_0_t *xml_1_0p) {
  int                        i;
  marpaWrapperSymbolOption_t marpaWrapperSymbolOption;

  xml_1_0p->marpaWrapperSymbolArrayp = malloc(_SYMBOL_MAX * sizeof(marpaWrapperSymbol_t *));
  if (xml_1_0p->marpaWrapperSymbolArrayp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  for (i = 0; i < _SYMBOL_MAX; i++) {

    /* Fill default options */
    if (marpaWrapper_symbolOptionDefaultb(&marpaWrapperSymbolOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }

    /* Opaque data will be our "this" */
    marpaWrapperSymbolOption.datavp = xml_1_0p;

    /* Optional, but we can make ourself the terminals */
    marpaWrapperSymbolOption.terminalb = (i <= XML_1_0_TERMINAL_MAX) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;

    /* Start rule ? */
    marpaWrapperSymbolOption.startb = (i == S_document) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;

    /* Create the symbol */
    xml_1_0p->marpaWrapperSymbolArrayp[i] = marpaWrapper_g_addSymbolp (xml_1_0p->marpaWrapperp, &marpaWrapperSymbolOption);
    if (xml_1_0p->marpaWrapperSymbolArrayp[i] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }

  }

  return MARPAWRAPPER_BOOL_TRUE;
}

#define ADD_RULE_BEG {							\
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) { \
      return MARPAWRAPPER_BOOL_FALSE;					\
    }									\
  }
#define ADD_RULE_END(lhs, rhsp, sep, min) {				\
    marpaWrapperRuleOption.datavp = xml_1_0p;				\
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[lhs]; \
    marpaWrapperRuleOption.rhsSymbolpp = rhsp;				\
    if (min == '+') {							\
      marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;	\
      marpaWrapperRuleOption.minimumi = 1;				\
    } else if (min == '*') {						\
      marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;	\
      marpaWrapperRuleOption.minimumi = 0;				\
    }									\
    if (sep >= 0) {							\
      marpaWrapperRuleOption.separatorSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[sep]; \
      marpaWrapperRuleOption.properb = MARPAWRAPPER_BOOL_TRUE;		\
    }									\
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) { \
      return MARPAWRAPPER_BOOL_FALSE;					\
    }									\
  }
#define ADD_RULE_0(lhs, sep, min) {					\
    ADD_RULE_BEG;							\
    {									\
      marpaWrapperRuleOption.nRhsSymboli = 0;				\
      ADD_RULE_END(lhs, NULL, sep, min);				\
    }									\
  }
#define ADD_RULE_1(lhs, rhs1, sep, min) {				\
    ADD_RULE_BEG;							\
    {									\
      marpaWrapperSymbol_t *rhsSymbolpp[1] = { xml_1_0p->marpaWrapperSymbolArrayp[rhs1] }; \
      marpaWrapperRuleOption.nRhsSymboli = 1;				\
      ADD_RULE_END(lhs, rhsSymbolpp, sep, min);				\
    }									\
  }
#define ADD_RULE_2(lhs, rhs1, rhs2, sep, min) {				\
    ADD_RULE_BEG;							\
    {									\
      marpaWrapperSymbol_t *rhsSymbolpp[2] = { xml_1_0p->marpaWrapperSymbolArrayp[rhs1], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs2] }; \
      marpaWrapperRuleOption.nRhsSymboli = 2;				\
      ADD_RULE_END(lhs, rhsSymbolpp, sep, min);				\
    }									\
  }
#define ADD_RULE_3(lhs, rhs1, rhs2, rhs3, sep, min) {			\
    ADD_RULE_BEG;							\
    {									\
      marpaWrapperSymbol_t *rhsSymbolpp[3] = { xml_1_0p->marpaWrapperSymbolArrayp[rhs1], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs2], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs3] }; \
      marpaWrapperRuleOption.nRhsSymboli = 3;				\
      ADD_RULE_END(lhs, rhsSymbolpp, sep, min);				\
    }									\
  }
#define ADD_RULE_4(lhs, rhs1, rhs2, rhs3, rhs4, sep, min) {		\
    ADD_RULE_BEG;							\
    {									\
      marpaWrapperSymbol_t *rhsSymbolpp[4] = { xml_1_0p->marpaWrapperSymbolArrayp[rhs1], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs2], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs3], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs4] }; \
      marpaWrapperRuleOption.nRhsSymboli = 4;				\
      ADD_RULE_END(lhs, rhsSymbolpp, sep, min);				\
    }									\
  }
#define ADD_RULE_5(lhs, rhs1, rhs2, rhs3, rhs4, rhs5, sep, min) {	\
    ADD_RULE_BEG;							\
    {									\
      marpaWrapperSymbol_t *rhsSymbolpp[5] = { xml_1_0p->marpaWrapperSymbolArrayp[rhs1], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs2], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs3], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs4], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs5] }; \
      marpaWrapperRuleOption.nRhsSymboli = 5;				\
      ADD_RULE_END(lhs, rhsSymbolpp, sep, min);				\
    }									\
  }
#define ADD_RULE_6(lhs, rhs1, rhs2, rhs3, rhs4, rhs5, rhs6, sep, min) {	\
    ADD_RULE_BEG;							\
    {									\
      marpaWrapperSymbol_t *rhsSymbolpp[6] = { xml_1_0p->marpaWrapperSymbolArrayp[rhs1], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs2], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs3], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs4], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs5], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs6] }; \
      marpaWrapperRuleOption.nRhsSymboli = 6;				\
      ADD_RULE_END(lhs, rhsSymbolpp, sep, min);				\
    }									\
  }
#define ADD_RULE_7(lhs, rhs1, rhs2, rhs3, rhs4, rhs5, rhs6, rhs7, sep, min) { \
    ADD_RULE_BEG;							\
    {									\
      marpaWrapperSymbol_t *rhsSymbolpp[7] = { xml_1_0p->marpaWrapperSymbolArrayp[rhs1], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs2], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs3], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs4], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs5], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs6], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs7] }; \
      marpaWrapperRuleOption.nRhsSymboli = 7;				\
      ADD_RULE_END(lhs, rhsSymbolpp, sep, min);				\
    }									\
  }
#define ADD_RULE_8(lhs, rhs1, rhs2, rhs3, rhs4, rhs5, rhs6, rhs7, rhs8, sep, min) { \
    ADD_RULE_BEG;							\
    {									\
      marpaWrapperSymbol_t *rhsSymbolpp[8] = { xml_1_0p->marpaWrapperSymbolArrayp[rhs1], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs2], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs3], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs4], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs5], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs6], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs7], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs8] }; \
      marpaWrapperRuleOption.nRhsSymboli = 8;				\
      ADD_RULE_END(lhs, rhsSymbolpp, sep, min);				\
    }									\
  }
#define ADD_RULE_9(lhs, rhs1, rhs2, rhs3, rhs4, rhs5, rhs6, rhs7, rhs8, rhs9, sep, min) { \
    ADD_RULE_BEG;							\
    {									\
      marpaWrapperSymbol_t *rhsSymbolpp[9] = { xml_1_0p->marpaWrapperSymbolArrayp[rhs1], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs2], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs3], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs4], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs5], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs6], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs7], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs8], \
					       xml_1_0p->marpaWrapperSymbolArrayp[rhs9] }; \
      marpaWrapperRuleOption.nRhsSymboli = 9;				\
      ADD_RULE_END(lhs, rhsSymbolpp, sep, min);				\
    }									\
  }
#define ADD_RULE_10(lhs, rhs1, rhs2, rhs3, rhs4, rhs5, rhs6, rhs7, rhs8, rhs9, rhs10, sep, min) { \
    ADD_RULE_BEG;							\
    {									\
      marpaWrapperSymbol_t *rhsSymbolpp[10] = { xml_1_0p->marpaWrapperSymbolArrayp[rhs1], \
						xml_1_0p->marpaWrapperSymbolArrayp[rhs2], \
						xml_1_0p->marpaWrapperSymbolArrayp[rhs3], \
						xml_1_0p->marpaWrapperSymbolArrayp[rhs4], \
						xml_1_0p->marpaWrapperSymbolArrayp[rhs5], \
						xml_1_0p->marpaWrapperSymbolArrayp[rhs6], \
						xml_1_0p->marpaWrapperSymbolArrayp[rhs7], \
						xml_1_0p->marpaWrapperSymbolArrayp[rhs8], \
						xml_1_0p->marpaWrapperSymbolArrayp[rhs9], \
						xml_1_0p->marpaWrapperSymbolArrayp[rhs10] }; \
      marpaWrapperRuleOption.nRhsSymboli = 10;				\
      ADD_RULE_END(lhs, rhsSymbolpp, sep, min);				\
    }									\
  }
#define ADD_RULE_11(lhs, rhs1, rhs2, rhs3, rhs4, rhs5, rhs6, rhs7, rhs8, rhs9, rhs10, rhs11, sep, min) { \
    ADD_RULE_BEG;							\
    {									\
      marpaWrapperSymbol_t *rhsSymbolpp[11] = { xml_1_0p->marpaWrapperSymbolArrayp[rhs1], \
						xml_1_0p->marpaWrapperSymbolArrayp[rhs2], \
						xml_1_0p->marpaWrapperSymbolArrayp[rhs3], \
						xml_1_0p->marpaWrapperSymbolArrayp[rhs4], \
						xml_1_0p->marpaWrapperSymbolArrayp[rhs5], \
						xml_1_0p->marpaWrapperSymbolArrayp[rhs6], \
						xml_1_0p->marpaWrapperSymbolArrayp[rhs7], \
						xml_1_0p->marpaWrapperSymbolArrayp[rhs8], \
						xml_1_0p->marpaWrapperSymbolArrayp[rhs9], \
						xml_1_0p->marpaWrapperSymbolArrayp[rhs10], \
						xml_1_0p->marpaWrapperSymbolArrayp[rhs11] }; \
      marpaWrapperRuleOption.nRhsSymboli = 11;				\
      ADD_RULE_END(lhs, rhsSymbolpp, sep, min);				\
    }									\
  }

/************************/
/* _xml_1_0_buildRulesb */
/************************/
static marpaWrapperBool_t _xml_1_0_buildRulesb(xml_1_0_t *xml_1_0p) {
  marpaWrapperRuleOption_t   marpaWrapperRuleOption;
  marpaWrapperSymbolOption_t marpaWrapperSymbolOption;

  ADD_RULE_3(S_document, S_prolog, S_element, S_MiscAny, -1, 0);

  ADD_RULE_1(S_Names, T_Name, T_x20, '+');

  ADD_RULE_1(S_Nmtokens, T_Nmtoken, T_x20, '+');

  ADD_RULE_3(S_Comment, T_CommentBeg, T_CommentInterior, T_CommentEnd, -1, 0);

  ADD_RULE_3(S_PI, T_PiBeg, T_PITarget, T_PiEnd, -1, 0);
  ADD_RULE_5(S_PI, T_PiBeg, T_PITarget, T_S, T_PiInterior, T_PiEnd, -1, 0);

  ADD_RULE_3(S_CDSect, T_CDStart, T_CData, T_CDEnd, -1, 0);

  ADD_RULE_2(S_prolog, S_XMLDeclMaybe, S_MiscAny, -1, 0);
  ADD_RULE_4(S_prolog, S_XMLDeclMaybe, S_MiscAny, S_doctypedecl, S_MiscAny, -1, 0);

  ADD_RULE_6(S_XMLDecl, T_XmlBeg, S_VersionInfo, S_EncodingDeclMaybe, S_SDDeclMaybe, S_SMaybe, T_XmlEnd, -1, 0);

  ADD_RULE_6(S_VersionInfo, T_S, T_Version, S_Eq, T_Squote, T_VersionNum, T_Squote, -1, 0);
  ADD_RULE_6(S_VersionInfo, T_S, T_Version, S_Eq, T_Dquote, T_VersionNum, T_Dquote, -1, 0);

  ADD_RULE_3(S_Eq, S_SMaybe, T_Equal, S_SMaybe, -1, 0);

  ADD_RULE_1(S_Misc, S_Comment, -1, 0);
  ADD_RULE_1(S_Misc, S_PI, -1, 0);
  ADD_RULE_1(S_Misc, T_S, -1, 0);

  ADD_RULE_5(S_doctypedecl, T_DoctypeBeg, T_S, T_Name, S_SMaybe, S_DoctypeEnd, -1, 0);
  ADD_RULE_9(S_doctypedecl, T_DoctypeBeg, T_S, T_Name, S_SMaybe, T_Lbracket, S_intSubset, T_Rbracket, S_SMaybe, S_DoctypeEnd, -1, 0);
  ADD_RULE_7(S_doctypedecl, T_DoctypeBeg, T_S, T_Name, T_S, S_ExternalID, S_SMaybe, S_DoctypeEnd, -1, 0);
  ADD_RULE_11(S_doctypedecl, T_DoctypeBeg, T_S, T_Name, T_S, S_ExternalID, S_SMaybe, T_Lbracket, S_intSubset, T_Rbracket, S_SMaybe, S_DoctypeEnd, -1, 0);

  ADD_RULE_1(S_DeclSep, T_PEReference, -1, 0);
  ADD_RULE_1(S_DeclSep, T_S, -1, 0);

  ADD_RULE_1(S_intSubset, S_intSubsetUnit, -1, '*');

  ADD_RULE_1(S_markupdecl, S_elementdecl, -1, 0);
  ADD_RULE_1(S_markupdecl, S_AttlistDecl, -1, 0);
  ADD_RULE_1(S_markupdecl, S_EntityDecl, -1, 0);
  ADD_RULE_1(S_markupdecl, S_NotationDecl, -1, 0);
  ADD_RULE_1(S_markupdecl, S_PI, -1, 0);
  ADD_RULE_1(S_markupdecl, S_Comment, -1, 0);

  ADD_RULE_1(S_extSubset, S_extSubsetDecl, -1, 0);
  ADD_RULE_2(S_extSubset, S_TextDecl, S_extSubsetDecl, -1, 0);

  ADD_RULE_1(S_extSubsetDecl, S_extSubsetDeclUnit, -1, '*');

  ADD_RULE_6(S_SDDecl, T_S, T_Standalone, S_Eq, T_Squote, T_Yes, T_Squote, -1, 0);
  ADD_RULE_6(S_SDDecl, T_S, T_Standalone, S_Eq, T_Dquote, T_Yes, T_Dquote, -1, 0);
  ADD_RULE_6(S_SDDecl, T_S, T_Standalone, S_Eq, T_Squote, T_No, T_Squote, -1, 0);
  ADD_RULE_6(S_SDDecl, T_S, T_Standalone, S_Eq, T_Dquote, T_No, T_Dquote, -1, 0);

  ADD_RULE_1(S_element, S_EmptyElemTag, -1, 0);
  ADD_RULE_3(S_element, S_STag, S_EmptyElemTag, S_ETag, -1, 0);

  ADD_RULE_5(S_STag, S_STagBeg, T_Name, S_STagInteriorAny, S_SMaybe, T_STagEnd, -1, 0);

  ADD_RULE_3(S_Attribute, T_Name, S_Eq, T_AttValue, -1, 0);

  ADD_RULE_4(S_ETag, T_ETagBeg, T_Name, S_SMaybe, T_ETagEnd, -1, 0);

  ADD_RULE_2(S_content, S_CharDataMaybe, S_ContentInteriorAny, -1, 0);

  ADD_RULE_5(S_EmptyElemTag, S_EmptyElemTagBeg, T_Name, S_EmptyElemTagInteriorAny, S_SMaybe, T_EmptyElemTagEnd, -1, 0);

  ADD_RULE_7(S_elementdecl, T_ElementDeclBeg, T_S, T_Name, T_S, S_contentspec, S_SMaybe, S_ElementDeclEnd, -1, 0);

  ADD_RULE_1(S_contentspec, T_Empty, -1, 0);
  ADD_RULE_1(S_contentspec, T_Any, -1, 0);
  ADD_RULE_1(S_contentspec, S_Mixed, -1, 0);
  ADD_RULE_1(S_contentspec, S_children, -1, 0);

  ADD_RULE_2(S_children, S_choice, S_QuantifierMaybe, -1, 0);
  ADD_RULE_2(S_children, S_seq, S_QuantifierMaybe, -1, 0);

  ADD_RULE_2(S_cp, T_Name, S_QuantifierMaybe, -1, 0);
  ADD_RULE_2(S_cp, S_choice, S_QuantifierMaybe, -1, 0);
  ADD_RULE_2(S_cp, S_seq, S_QuantifierMaybe, -1, 0);

  ADD_RULE_6(S_choice, T_Lparen, S_SMaybe, S_cp, S_ChoiceInteriorMany, S_SMaybe, T_Rparen, -1, 0);

  ADD_RULE_6(S_seq, T_Lparen, S_SMaybe, S_cp, S_SeqInteriorAny, S_SMaybe, T_Rparen, -1, 0);

  ADD_RULE_6(S_Mixed, T_Lparen, S_SMaybe, T_Pcdata, S_MixedInteriorAny, S_SMaybe, T_RparenStar, -1, 0);
  ADD_RULE_5(S_Mixed, T_Lparen, S_SMaybe, T_Pcdata, S_SMaybe, T_Rparen, -1, 0);

  ADD_RULE_6(S_AttlistDecl, T_AttlistBeg, T_S, T_Name, S_AttDefAny, T_S, S_AttlistEnd, -1, 0);

  ADD_RULE_6(S_AttDef, T_S, T_Name, T_S, S_AttType, T_S, S_DefaultDecl, -1, 0);

  ADD_RULE_1(S_AttType, T_StringType, -1, 0);
  ADD_RULE_1(S_AttType, S_TokenizedType, -1, 0);
  ADD_RULE_1(S_AttType, S_EnumeratedType, -1, 0);

  ADD_RULE_1(S_TokenizedType, T_TypeId, -1, 0);
  ADD_RULE_1(S_TokenizedType, T_TypeIdref, -1, 0);
  ADD_RULE_1(S_TokenizedType, T_TypeIdrefs, -1, 0);
  ADD_RULE_1(S_TokenizedType, T_TypeEntity, -1, 0);
  ADD_RULE_1(S_TokenizedType, T_TypeEntities, -1, 0);
  ADD_RULE_1(S_TokenizedType, T_TypeNmtoken, -1, 0);
  ADD_RULE_1(S_TokenizedType, T_TypeNmtokens, -1, 0);

  ADD_RULE_1(S_EnumeratedType, S_NotationType, -1, 0);
  ADD_RULE_1(S_EnumeratedType, S_Enumeration, -1, 0);

  ADD_RULE_8(S_NotationType, T_Notation, T_S, T_Lparen, S_SMaybe, T_Name, S_NotationTypeInteriorAny, S_SMaybe, T_Rparen, -1, 0);

  ADD_RULE_6(S_Enumeration, T_Lparen, S_SMaybe, T_Nmtoken, S_EnumerationInteriorAny, S_SMaybe, T_Rparen, -1, 0);

  ADD_RULE_1(S_DefaultDecl, T_Required, -1, 0);
  ADD_RULE_1(S_DefaultDecl, T_Implied, -1, 0);
  ADD_RULE_1(S_DefaultDecl, T_AttValue, -1, 0);
  ADD_RULE_3(S_DefaultDecl, T_Fixed, T_S, T_AttValue, -1, 0);

  ADD_RULE_1(S_conditionalSect, S_includeSect, -1, 0);
  ADD_RULE_1(S_conditionalSect, S_ignoreSect, -1, 0);

  ADD_RULE_7(S_includeSect, T_SectBeg, S_SMaybe, T_Include, S_SMaybe, T_Lbracket, S_extSubsetDecl, T_SectEnd, -1, 0);

  ADD_RULE_7(S_ignoreSect, T_SectBeg, S_SMaybe, T_TOKIgnore, S_SMaybe, T_Lbracket, S_ignoreSectContentsAny, T_SectEnd, -1, 0);

  ADD_RULE_2(S_ignoreSectContents, T_Ignore, S_ignoreSectContentsInteriorAny, -1, 0);

  ADD_RULE_1(S_Reference, T_EntityRef, -1, 0);
  ADD_RULE_1(S_Reference, T_CharRef, -1, 0);

  ADD_RULE_1(S_EntityDecl, S_GEDecl, -1, 0);
  ADD_RULE_1(S_EntityDecl, S_PEDecl, -1, 0);

  ADD_RULE_7(S_GEDecl, T_EdeclBeg, T_S, T_Name, T_S, S_EntityDef, S_SMaybe, S_EdeclEnd, -1, 0);
  ADD_RULE_9(S_PEDecl, T_EdeclBeg, T_S, T_Percent, T_S, T_Name, T_S, S_PEDef, S_SMaybe, S_EdeclEnd, -1, 0);

  ADD_RULE_1(S_EntityDef, T_EntityValue, -1, 0);
  ADD_RULE_1(S_EntityDef, S_ExternalID, -1, 0);
  ADD_RULE_2(S_EntityDef, S_ExternalID, S_NDataDecl, -1, 0);

  ADD_RULE_1(S_PEDef, T_EntityValue, -1, 0);
  ADD_RULE_1(S_PEDef, S_ExternalID, -1, 0);

  ADD_RULE_3(S_ExternalID, T_System, T_S, T_SystemLiteral, -1, 0);
  ADD_RULE_5(S_ExternalID, T_Public, T_S, T_PubidLiteral, T_S, T_SystemLiteral, -1, 0);

  ADD_RULE_4(S_NDataDecl, T_S, T_Ndata, T_S, T_Name, -1, 0);

  ADD_RULE_5(S_TextDecl, T_XmlBeg, S_VersionInfoMaybe, S_EncodingDecl, S_SMaybe, T_XmlEnd, -1, 0);

  ADD_RULE_1(S_extParsedEnt, S_content, -1, 0);
  ADD_RULE_2(S_extParsedEnt, S_TextDecl, S_content, -1, 0);

  ADD_RULE_6(S_EncodingDecl, T_S, T_Encoding, S_Eq, T_Dquote, T_EncName, T_Dquote, -1, 0);
  ADD_RULE_6(S_EncodingDecl, T_S, T_Encoding, S_Eq, T_Squote, T_EncName, T_Squote, -1, 0);

  ADD_RULE_7(S_NotationDecl, T_NotationBeg, T_S, T_Name, T_S, S_ExternalID, S_SMaybe, S_NotationEnd, -1, 0);
  ADD_RULE_7(S_NotationDecl, T_NotationBeg, T_S, T_Name, T_S, S_PublicID, S_SMaybe, S_NotationEnd, -1, 0);

  ADD_RULE_3(S_PublicID, T_Public, T_S, T_PubidLiteral, -1, 0);

  /* Helpers */

  ADD_RULE_1(S_XMLDeclMaybe, S_XMLDecl, -1, 0);
  ADD_RULE_0(S_XMLDeclMaybe, -1, 0);
  
  ADD_RULE_1(S_MiscAny, S_Misc, -1, '*');

  ADD_RULE_1(S_EncodingDeclMaybe, S_EncodingDecl, -1, 0);
  ADD_RULE_0(S_EncodingDeclMaybe, -1, 0);
  
  ADD_RULE_1(S_SDDeclMaybe, S_SDDecl, -1, 0);
  ADD_RULE_0(S_SDDeclMaybe, -1, 0);
  
  ADD_RULE_1(S_SMaybe, T_S, -1, 0);
  ADD_RULE_0(S_SMaybe, -1, 0);
  
  ADD_RULE_2(S_ContentInterior, S_element, S_CharDataMaybe, -1, 0);
  ADD_RULE_2(S_ContentInterior, S_Reference, S_CharDataMaybe, -1, 0);
  ADD_RULE_2(S_ContentInterior, S_CDSect, S_CharDataMaybe, -1, 0);
  ADD_RULE_2(S_ContentInterior, S_PI, S_CharDataMaybe, -1, 0);
  ADD_RULE_2(S_ContentInterior, S_Comment, S_CharDataMaybe, -1, 0);

  ADD_RULE_1(S_ContentInteriorAny, S_ContentInterior, -1, '*');

  ADD_RULE_1(S_intSubsetUnit, S_markupdecl, -1, 0);
  ADD_RULE_1(S_intSubsetUnit, S_DeclSep, -1, 0);

  ADD_RULE_1(S_extSubsetDeclUnit, S_markupdecl, -1, 0);
  ADD_RULE_1(S_extSubsetDeclUnit, S_conditionalSect, -1, 0);
  ADD_RULE_1(S_extSubsetDeclUnit, S_DeclSep, -1, 0);

  ADD_RULE_2(S_STagInterior, T_S, S_Attribute, -1, 0);

  ADD_RULE_1(S_STagInteriorAny, S_STagInterior, -1, '*');

  ADD_RULE_1(S_CharDataMaybe, T_CharData, -1, 0);
  ADD_RULE_0(S_CharDataMaybe, -1, 0);

  ADD_RULE_2(S_EmptyElemTagInterior, T_S, S_Attribute, -1, 0);

  ADD_RULE_1(S_EmptyElemTagInteriorAny, S_EmptyElemTagInterior, -1, '*');

  ADD_RULE_1(S_Quantifier, T_QuestionMark, -1, 0);
  ADD_RULE_1(S_Quantifier, T_Star, -1, 0);
  ADD_RULE_1(S_Quantifier, T_Plus, -1, 0);

  ADD_RULE_1(S_QuantifierMaybe, S_Quantifier, -1, 0);
  ADD_RULE_0(S_QuantifierMaybe, -1, 0);

  ADD_RULE_4(S_ChoiceInterior, S_SMaybe, T_Pipe, S_SMaybe, S_cp, -1, 0);

  ADD_RULE_1(S_ChoiceInteriorMany, S_ChoiceInterior, -1, '+');

  ADD_RULE_4(S_SeqInterior, S_SMaybe, T_Comma, S_SMaybe, S_cp, -1, 0);

  ADD_RULE_1(S_SeqInteriorAny, S_SeqInterior, -1, '*');

  ADD_RULE_4(S_MixedInterior, S_SMaybe, T_Pipe, S_SMaybe, T_Name, -1, 0);

  ADD_RULE_1(S_MixedInteriorAny, S_MixedInterior, -1, '*');

  ADD_RULE_1(S_AttDefAny, S_AttDef, -1, '*');

  ADD_RULE_4(S_NotationTypeInterior, S_SMaybe, T_Pipe, S_SMaybe, T_Name, -1, 0);

  ADD_RULE_1(S_NotationTypeInteriorAny, S_NotationTypeInterior, -1, '*');

  ADD_RULE_4(S_EnumerationInterior, S_SMaybe, T_Pipe, S_SMaybe, T_Nmtoken, -1, 0);

  ADD_RULE_1(S_EnumerationInteriorAny, S_EnumerationInterior, -1, '*');

  ADD_RULE_1(S_ignoreSectContentsAny, S_ignoreSectContents, -1, '*');

  ADD_RULE_4(S_ignoreSectContentsInterior, T_SectBeg, S_ignoreSectContents, T_SectEnd, T_Ignore, -1, 0);

  ADD_RULE_1(S_ignoreSectContentsInteriorAny, S_ignoreSectContentsInterior, -1, '*');

  ADD_RULE_1(S_VersionInfoMaybe, S_VersionInfo, -1, 0);
  ADD_RULE_0(S_VersionInfoMaybe, -1, 0);

  ADD_RULE_1(S_DoctypeEnd, T_XTagEnd, -1, 0);

  ADD_RULE_1(S_STagBeg, T_XTagBeg, -1, 0);

  ADD_RULE_1(S_EmptyElemTagBeg, T_XTagBeg, -1, 0);

  ADD_RULE_1(S_ElementDeclEnd, T_XTagEnd, -1, 0);

  ADD_RULE_1(S_AttlistEnd, T_XTagEnd, -1, 0);

  ADD_RULE_1(S_NotationEnd, T_XTagEnd, -1, 0);

  ADD_RULE_1(S_EdeclEnd, T_XTagEnd, -1, 0);

  return MARPAWRAPPER_BOOL_TRUE;
}

