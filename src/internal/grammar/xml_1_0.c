/****************************/
/* This is a generated file */
/****************************/
#include <stdlib.h>
#include <errno.h>
#include "internal/streamIn.h"
#include "internal/grammar/xml_1_0.h"

/* Symbols */
typedef enum xml_1_0_symbol {
  /* Terminals */
  xml_1_0_CDStart = 0           , /* CDStart ~ '<![CDATA[' */
  xml_1_0_Char                  , /* Char ~ [\x{9}\x{a}\x{d}\x{20}-\x{d7ff}\x{e000}-\x{fffd}\x{10000}-\x{10ffff}] */
  xml_1_0_NameStartChar         , /* NameStartChar ~ [:A-Z_a-z\x{c0}-\x{d6}\x{d8}-\x{f6}\x{f8}-\x{2ff}\x{370}-\x{37d}\x{37f}-\x{1fff}\x{200c}-\x{200d}\x{2070}-\x{218f}\x{2c00}-\x{2fef}\x{3001}-\x{d7ff}\x{f900}-\x{fdcf}\x{fdf0}-\x{fffd}\x{10000}-\x{effff}] */
  xml_1_0_PubidChar             , /* PubidChar ~ [a-zA-Z0-9-'()+,./:=?;!*#@$_%\x{20}\x{d}\x{a}] */
  xml_1_0_StringType            , /* StringType ~ 'CDATA' */
  xml_1_0__Exclusion001         , /* _Exclusion001 ~ 'PubidChar - _Lex008' */
  xml_1_0__Exclusion002         , /* _Exclusion002 ~ '_Lex015_any - _Gen056' */
  xml_1_0__Exclusion003         , /* _Exclusion003 ~ 'Char_any - _Gen061' */
  xml_1_0__Exclusion004         , /* _Exclusion004 ~ 'Name - _Gen074' */
  xml_1_0__Exclusion005         , /* _Exclusion005 ~ 'Char_any - _Gen079' */
  xml_1_0__Exclusion006         , /* _Exclusion006 ~ 'Char_any - _Gen233' */
  xml_1_0__Lex002               , /* _Lex002 ~ [\x{20}\x{9}\x{d}\x{a}] */
  xml_1_0__Lex004               , /* _Lex004 ~ [-.0-9\x{b7}\x{300}-\x{36f}\x{203f}-\x{2040}] */
  xml_1_0__Lex005               , /* _Lex005 ~ [\x{20}] */
  xml_1_0__Lex006               , /* _Lex006 ~ '"' */
  xml_1_0__Lex007               , /* _Lex007 ~ [^%&"] */
  xml_1_0__Lex008               , /* _Lex008 ~ ['] */
  xml_1_0__Lex009               , /* _Lex009 ~ [^%&'] */
  xml_1_0__Lex010               , /* _Lex010 ~ [^<&"] */
  xml_1_0__Lex011               , /* _Lex011 ~ [^<&'] */
  xml_1_0__Lex012               , /* _Lex012 ~ [^"] */
  xml_1_0__Lex013               , /* _Lex013 ~ [^'] */
  xml_1_0__Lex015               , /* _Lex015 ~ [^<&] */
  xml_1_0__Lex016               , /* _Lex016 ~ ']]>' */
  xml_1_0__Lex017               , /* _Lex017 ~ '<!--' */
  xml_1_0__Lex018               , /* _Lex018 ~ '-->' */
  xml_1_0__Lex019               , /* _Lex019 ~ '<?' */
  xml_1_0__Lex020               , /* _Lex020 ~ '?>' */
  xml_1_0__Lex021               , /* _Lex021 ~ 'X' */
  xml_1_0__Lex022               , /* _Lex022 ~ 'x' */
  xml_1_0__Lex023               , /* _Lex023 ~ 'M' */
  xml_1_0__Lex024               , /* _Lex024 ~ 'm' */
  xml_1_0__Lex025               , /* _Lex025 ~ 'L' */
  xml_1_0__Lex026               , /* _Lex026 ~ 'l' */
  xml_1_0__Lex028               , /* _Lex028 ~ '<?xml' */
  xml_1_0__Lex029               , /* _Lex029 ~ 'version' */
  xml_1_0__Lex030               , /* _Lex030 ~ '=' */
  xml_1_0__Lex031               , /* _Lex031 ~ '1.' */
  xml_1_0__Lex032               , /* _Lex032 ~ [0-9] */
  xml_1_0__Lex033               , /* _Lex033 ~ '<!DOCTYPE' */
  xml_1_0__Lex034               , /* _Lex034 ~ '[' */
  xml_1_0__Lex035               , /* _Lex035 ~ ']' */
  xml_1_0__Lex036               , /* _Lex036 ~ '>' */
  xml_1_0__Lex037               , /* _Lex037 ~ 'standalone' */
  xml_1_0__Lex038               , /* _Lex038 ~ 'yes' */
  xml_1_0__Lex039               , /* _Lex039 ~ 'no' */
  xml_1_0__Lex040               , /* _Lex040 ~ '<' */
  xml_1_0__Lex041               , /* _Lex041 ~ '</' */
  xml_1_0__Lex042               , /* _Lex042 ~ '/>' */
  xml_1_0__Lex043               , /* _Lex043 ~ '<!ELEMENT' */
  xml_1_0__Lex044               , /* _Lex044 ~ 'EMPTY' */
  xml_1_0__Lex045               , /* _Lex045 ~ 'ANY' */
  xml_1_0__Lex046               , /* _Lex046 ~ '?' */
  xml_1_0__Lex047               , /* _Lex047 ~ '*' */
  xml_1_0__Lex048               , /* _Lex048 ~ '+' */
  xml_1_0__Lex049               , /* _Lex049 ~ '(' */
  xml_1_0__Lex050               , /* _Lex050 ~ '|' */
  xml_1_0__Lex051               , /* _Lex051 ~ ')' */
  xml_1_0__Lex052               , /* _Lex052 ~ ',' */
  xml_1_0__Lex053               , /* _Lex053 ~ '#PCDATA' */
  xml_1_0__Lex054               , /* _Lex054 ~ ')*' */
  xml_1_0__Lex055               , /* _Lex055 ~ '<!ATTLIST' */
  xml_1_0__Lex057               , /* _Lex057 ~ 'ID' */
  xml_1_0__Lex058               , /* _Lex058 ~ 'IDREF' */
  xml_1_0__Lex059               , /* _Lex059 ~ 'IDREFS' */
  xml_1_0__Lex060               , /* _Lex060 ~ 'ENTITY' */
  xml_1_0__Lex061               , /* _Lex061 ~ 'ENTITIES' */
  xml_1_0__Lex062               , /* _Lex062 ~ 'NMTOKEN' */
  xml_1_0__Lex063               , /* _Lex063 ~ 'NMTOKENS' */
  xml_1_0__Lex064               , /* _Lex064 ~ 'NOTATION' */
  xml_1_0__Lex065               , /* _Lex065 ~ '#REQUIRED' */
  xml_1_0__Lex066               , /* _Lex066 ~ '#IMPLIED' */
  xml_1_0__Lex067               , /* _Lex067 ~ '#FIXED' */
  xml_1_0__Lex068               , /* _Lex068 ~ '<![' */
  xml_1_0__Lex069               , /* _Lex069 ~ 'INCLUDE' */
  xml_1_0__Lex070               , /* _Lex070 ~ 'IGNORE' */
  xml_1_0__Lex071               , /* _Lex071 ~ '&#' */
  xml_1_0__Lex072               , /* _Lex072 ~ ';' */
  xml_1_0__Lex073               , /* _Lex073 ~ '&#x' */
  xml_1_0__Lex074               , /* _Lex074 ~ [0-9a-fA-F] */
  xml_1_0__Lex075               , /* _Lex075 ~ '&' */
  xml_1_0__Lex076               , /* _Lex076 ~ '%' */
  xml_1_0__Lex077               , /* _Lex077 ~ '<!ENTITY' */
  xml_1_0__Lex078               , /* _Lex078 ~ 'SYSTEM' */
  xml_1_0__Lex079               , /* _Lex079 ~ 'PUBLIC' */
  xml_1_0__Lex080               , /* _Lex080 ~ 'NDATA' */
  xml_1_0__Lex081               , /* _Lex081 ~ 'encoding' */
  xml_1_0__Lex082               , /* _Lex082 ~ [A-Za-z] */
  xml_1_0__Lex083               , /* _Lex083 ~ [A-Za-z0-9._] */
  xml_1_0__Lex084               , /* _Lex084 ~ '-' */
  xml_1_0__Lex085               , /* _Lex085 ~ '<!NOTATION' */
  /* Non-terminals */
  xml_1_0_AttDef                ,
  xml_1_0_AttDef_any            ,
  xml_1_0_AttType               ,
  xml_1_0_AttValue              ,
  xml_1_0_AttlistDecl           ,
  xml_1_0_Attribute             ,
  xml_1_0_CDEnd                 ,
  xml_1_0_CDSect                ,
  xml_1_0_CData                 ,
  xml_1_0_CharData              ,
  xml_1_0_CharData_maybe        ,
  xml_1_0_CharRef               ,
  xml_1_0_Char_any              ,
  xml_1_0_Comment               ,
  xml_1_0_DeclSep               ,
  xml_1_0_DefaultDecl           ,
  xml_1_0_ETag                  ,
  xml_1_0_EmptyElemTag          ,
  xml_1_0_EncName               ,
  xml_1_0_EncodingDecl          ,
  xml_1_0_EncodingDecl_maybe    ,
  xml_1_0_EntityDecl            ,
  xml_1_0_EntityDef             ,
  xml_1_0_EntityRef             ,
  xml_1_0_EntityValue           ,
  xml_1_0_EnumeratedType        ,
  xml_1_0_Enumeration           ,
  xml_1_0_Eq                    ,
  xml_1_0_ExternalID            ,
  xml_1_0_GEDecl                ,
  xml_1_0_Ignore                ,
  xml_1_0_Misc                  ,
  xml_1_0_Misc_any              ,
  xml_1_0_Mixed                 ,
  xml_1_0_NDataDecl             ,
  xml_1_0_NDataDecl_maybe       ,
  xml_1_0_Name                  ,
  xml_1_0_NameChar              ,
  xml_1_0_Names                 ,
  xml_1_0_Nmtoken               ,
  xml_1_0_Nmtokens              ,
  xml_1_0_NotationDecl          ,
  xml_1_0_NotationType          ,
  xml_1_0_PEDecl                ,
  xml_1_0_PEDef                 ,
  xml_1_0_PEReference           ,
  xml_1_0_PI                    ,
  xml_1_0_PITarget              ,
  xml_1_0_PubidChar_any         ,
  xml_1_0_PubidLiteral          ,
  xml_1_0_PublicID              ,
  xml_1_0_Reference             ,
  xml_1_0_S                     ,
  xml_1_0_SDDecl                ,
  xml_1_0_SDDecl_maybe          ,
  xml_1_0_STag                  ,
  xml_1_0_S_maybe               ,
  xml_1_0_SystemLiteral         ,
  xml_1_0_TextDecl              ,
  xml_1_0_TextDecl_maybe        ,
  xml_1_0_TokenizedType         ,
  xml_1_0_VersionInfo           ,
  xml_1_0_VersionInfo_maybe     ,
  xml_1_0_VersionNum            ,
  xml_1_0_XMLDecl               ,
  xml_1_0_XMLDecl_maybe         ,
  xml_1_0__Gen012               ,
  xml_1_0__Gen012_any           ,
  xml_1_0__Gen015               ,
  xml_1_0__Gen015_any           ,
  xml_1_0__Gen018               ,
  xml_1_0__Gen018_many          ,
  xml_1_0__Gen021               ,
  xml_1_0__Gen021_any           ,
  xml_1_0__Gen024               ,
  xml_1_0__Gen024_any           ,
  xml_1_0__Gen028               ,
  xml_1_0__Gen028_any           ,
  xml_1_0__Gen034               ,
  xml_1_0__Gen034_any           ,
  xml_1_0__Gen037               ,
  xml_1_0__Gen037_any           ,
  xml_1_0__Gen043               ,
  xml_1_0__Gen045               ,
  xml_1_0__Gen049               ,
  xml_1_0__Gen050               ,
  xml_1_0__Gen050_any           ,
  xml_1_0__Gen056               ,
  xml_1_0__Gen057               ,
  xml_1_0__Gen061               ,
  xml_1_0__Gen062               ,
  xml_1_0__Gen063               ,
  xml_1_0__Gen064               ,
  xml_1_0__Gen064_maybe         ,
  xml_1_0__Gen068               ,
  xml_1_0__Gen070               ,
  xml_1_0__Gen072               ,
  xml_1_0__Gen074               ,
  xml_1_0__Gen075               ,
  xml_1_0__Gen079               ,
  xml_1_0__Gen080               ,
  xml_1_0__Gen081               ,
  xml_1_0__Gen086               ,
  xml_1_0__Gen086_maybe         ,
  xml_1_0__Gen097               ,
  xml_1_0__Gen106               ,
  xml_1_0__Gen106_maybe         ,
  xml_1_0__Gen109               ,
  xml_1_0__Gen109_maybe         ,
  xml_1_0__Gen115               ,
  xml_1_0__Gen115_any           ,
  xml_1_0__Gen128               ,
  xml_1_0__Gen128_any           ,
  xml_1_0__Gen133               ,
  xml_1_0__Gen135               ,
  xml_1_0__Gen136               ,
  xml_1_0__Gen138               ,
  xml_1_0__Gen139               ,
  xml_1_0__Gen144               ,
  xml_1_0__Gen144_any           ,
  xml_1_0__Gen151               ,
  xml_1_0__Gen156               ,
  xml_1_0__Gen156_any           ,
  xml_1_0__Gen159               ,
  xml_1_0__Gen159_any           ,
  xml_1_0__Gen167               ,
  xml_1_0__Gen169               ,
  xml_1_0__Gen169_maybe         ,
  xml_1_0__Gen175               ,
  xml_1_0__Gen178               ,
  xml_1_0__Gen178_maybe         ,
  xml_1_0__Gen184               ,
  xml_1_0__Gen184_many          ,
  xml_1_0__Gen187               ,
  xml_1_0__Gen187_any           ,
  xml_1_0__Gen190               ,
  xml_1_0__Gen190_any           ,
  xml_1_0__Gen210               ,
  xml_1_0__Gen210_any           ,
  xml_1_0__Gen213               ,
  xml_1_0__Gen213_any           ,
  xml_1_0__Gen216               ,
  xml_1_0__Gen216_maybe         ,
  xml_1_0__Gen219               ,
  xml_1_0__Gen228               ,
  xml_1_0__Gen228_any           ,
  xml_1_0__Gen231               ,
  xml_1_0__Gen233               ,
  xml_1_0__Gen234               ,
  xml_1_0__Gen249               ,
  xml_1_0__Gen261               ,
  xml_1_0__Gen264               ,
  xml_1_0__Gen264_any           ,
  xml_1_0__Gen268               ,
  xml_1_0__Lex002_many          ,
  xml_1_0__Lex012_any           ,
  xml_1_0__Lex013_any           ,
  xml_1_0__Lex015_any           ,
  xml_1_0__Lex032_many          ,
  xml_1_0__Lex074_many          ,
  xml_1_0_children              ,
  xml_1_0_choice                ,
  xml_1_0_conditionalSect       ,
  xml_1_0_content               ,
  xml_1_0_contentspec           ,
  xml_1_0_cp                    ,
  xml_1_0_doctypedecl           ,
  xml_1_0_document              ,
  xml_1_0_element               ,
  xml_1_0_elementdecl           ,
  xml_1_0_extParsedEnt          ,
  xml_1_0_extSubset             ,
  xml_1_0_extSubsetDecl         ,
  xml_1_0_ignoreSect            ,
  xml_1_0_ignoreSectContents    ,
  xml_1_0_ignoreSectContents_any,
  xml_1_0_includeSect           ,
  xml_1_0_intSubset             ,
  xml_1_0_markupdecl            ,
  xml_1_0_prolog                ,
  xml_1_0_seq                   ,
  xml_1_0_start                 ,
  XML_1_0_SYMBOL_MAX
} xml_1_0_symbol_t;

#define XML_1_0_TERMINAL_MAX xml_1_0__Lex085

/* Rules */
typedef enum xml_1_0_rule {
  xml_1_0_start_001 = 0         , /* start ::= document  */
  xml_1_0_start_002             , /* start ::= extParsedEnt  */
  xml_1_0_start_003             , /* start ::= extSubset  */
  xml_1_0_Misc_any_001          , /* Misc_any ::= Misc * */
  xml_1_0_document_001          , /* document ::= prolog element Misc_any  */
  xml_1_0__Lex002_many_001      , /* _Lex002_many ::= _Lex002 + */
  xml_1_0_S_001                 , /* S ::= _Lex002_many  */
  xml_1_0_NameChar_001          , /* NameChar ::= NameStartChar  */
  xml_1_0_NameChar_002          , /* NameChar ::= _Lex004  */
  xml_1_0__Gen012_001           , /* _Gen012 ::= NameChar  */
  xml_1_0__Gen012_any_001       , /* _Gen012_any ::= _Gen012 * */
  xml_1_0_Name_001              , /* Name ::= NameStartChar _Gen012_any  */
  xml_1_0__Gen015_001           , /* _Gen015 ::= _Lex005 Name  */
  xml_1_0__Gen015_any_001       , /* _Gen015_any ::= _Gen015 * */
  xml_1_0_Names_001             , /* Names ::= Name _Gen015_any  */
  xml_1_0__Gen018_001           , /* _Gen018 ::= NameChar  */
  xml_1_0__Gen018_many_001      , /* _Gen018_many ::= _Gen018 + */
  xml_1_0_Nmtoken_001           , /* Nmtoken ::= _Gen018_many  */
  xml_1_0__Gen021_001           , /* _Gen021 ::= _Lex005 Nmtoken  */
  xml_1_0__Gen021_any_001       , /* _Gen021_any ::= _Gen021 * */
  xml_1_0_Nmtokens_001          , /* Nmtokens ::= Nmtoken _Gen021_any  */
  xml_1_0__Gen024_001           , /* _Gen024 ::= _Lex007  */
  xml_1_0__Gen024_002           , /* _Gen024 ::= PEReference  */
  xml_1_0__Gen024_003           , /* _Gen024 ::= Reference  */
  xml_1_0__Gen024_any_001       , /* _Gen024_any ::= _Gen024 * */
  xml_1_0__Gen028_001           , /* _Gen028 ::= _Lex009  */
  xml_1_0__Gen028_002           , /* _Gen028 ::= PEReference  */
  xml_1_0__Gen028_003           , /* _Gen028 ::= Reference  */
  xml_1_0__Gen028_any_001       , /* _Gen028_any ::= _Gen028 * */
  xml_1_0_EntityValue_001       , /* EntityValue ::= _Lex006 _Gen024_any _Lex006  */
  xml_1_0_EntityValue_002       , /* EntityValue ::= _Lex008 _Gen028_any _Lex008  */
  xml_1_0__Gen034_001           , /* _Gen034 ::= _Lex010  */
  xml_1_0__Gen034_002           , /* _Gen034 ::= Reference  */
  xml_1_0__Gen034_any_001       , /* _Gen034_any ::= _Gen034 * */
  xml_1_0__Gen037_001           , /* _Gen037 ::= _Lex011  */
  xml_1_0__Gen037_002           , /* _Gen037 ::= Reference  */
  xml_1_0__Gen037_any_001       , /* _Gen037_any ::= _Gen037 * */
  xml_1_0_AttValue_001          , /* AttValue ::= _Lex006 _Gen034_any _Lex006  */
  xml_1_0_AttValue_002          , /* AttValue ::= _Lex008 _Gen037_any _Lex008  */
  xml_1_0__Lex012_any_001       , /* _Lex012_any ::= _Lex012 * */
  xml_1_0__Gen043_001           , /* _Gen043 ::= _Lex006 _Lex012_any _Lex006  */
  xml_1_0__Lex013_any_001       , /* _Lex013_any ::= _Lex013 * */
  xml_1_0__Gen045_001           , /* _Gen045 ::= _Lex008 _Lex013_any _Lex008  */
  xml_1_0_SystemLiteral_001     , /* SystemLiteral ::= _Gen043  */
  xml_1_0_SystemLiteral_002     , /* SystemLiteral ::= _Gen045  */
  xml_1_0_PubidChar_any_001     , /* PubidChar_any ::= PubidChar * */
  xml_1_0__Gen049_001           , /* _Gen049 ::= _Exclusion001  */
  xml_1_0__Gen050_001           , /* _Gen050 ::= _Gen049  */
  xml_1_0__Gen050_any_001       , /* _Gen050_any ::= _Gen050 * */
  xml_1_0_PubidLiteral_001      , /* PubidLiteral ::= _Lex006 PubidChar_any _Lex006  */
  xml_1_0_PubidLiteral_002      , /* PubidLiteral ::= _Lex008 _Gen050_any _Lex008  */
  xml_1_0__Lex015_any_001       , /* _Lex015_any ::= _Lex015 * */
  xml_1_0__Gen056_001           , /* _Gen056 ::= _Lex015_any _Lex016 _Lex015_any  */
  xml_1_0__Gen057_001           , /* _Gen057 ::= _Exclusion002  */
  xml_1_0_CharData_001          , /* CharData ::= _Gen057  */
  xml_1_0_Char_any_001          , /* Char_any ::= Char * */
  xml_1_0_Comment_001           , /* Comment ::= _Lex017 Char_any _Lex018  */
  xml_1_0__Gen061_001           , /* _Gen061 ::= Char_any _Lex020 Char_any  */
  xml_1_0__Gen062_001           , /* _Gen062 ::= _Exclusion003  */
  xml_1_0__Gen063_001           , /* _Gen063 ::= _Gen062  */
  xml_1_0__Gen064_001           , /* _Gen064 ::= S _Gen063  */
  xml_1_0__Gen064_maybe_001     , /* _Gen064_maybe ::= _Gen064  */
  xml_1_0__Gen064_maybe_002     , /* _Gen064_maybe ::=   */
  xml_1_0_PI_001                , /* PI ::= _Lex019 PITarget _Gen064_maybe _Lex020  */
  xml_1_0__Gen068_001           , /* _Gen068 ::= _Lex021  */
  xml_1_0__Gen068_002           , /* _Gen068 ::= _Lex022  */
  xml_1_0__Gen070_001           , /* _Gen070 ::= _Lex023  */
  xml_1_0__Gen070_002           , /* _Gen070 ::= _Lex024  */
  xml_1_0__Gen072_001           , /* _Gen072 ::= _Lex025  */
  xml_1_0__Gen072_002           , /* _Gen072 ::= _Lex026  */
  xml_1_0__Gen074_001           , /* _Gen074 ::= _Gen068 _Gen070 _Gen072  */
  xml_1_0__Gen075_001           , /* _Gen075 ::= _Exclusion004  */
  xml_1_0_PITarget_001          , /* PITarget ::= _Gen075  */
  xml_1_0_CDSect_001            , /* CDSect ::= CDStart CData CDEnd  */
  xml_1_0__Gen079_001           , /* _Gen079 ::= Char_any _Lex016 Char_any  */
  xml_1_0__Gen080_001           , /* _Gen080 ::= _Exclusion005  */
  xml_1_0__Gen081_001           , /* _Gen081 ::= _Gen080  */
  xml_1_0_CData_001             , /* CData ::= _Gen081  */
  xml_1_0_CDEnd_001             , /* CDEnd ::= _Lex016  */
  xml_1_0_XMLDecl_maybe_001     , /* XMLDecl_maybe ::= XMLDecl  */
  xml_1_0_XMLDecl_maybe_002     , /* XMLDecl_maybe ::=   */
  xml_1_0__Gen086_001           , /* _Gen086 ::= doctypedecl Misc_any  */
  xml_1_0__Gen086_maybe_001     , /* _Gen086_maybe ::= _Gen086  */
  xml_1_0__Gen086_maybe_002     , /* _Gen086_maybe ::=   */
  xml_1_0_prolog_001            , /* prolog ::= XMLDecl_maybe Misc_any _Gen086_maybe  */
  xml_1_0_EncodingDecl_maybe_001, /* EncodingDecl_maybe ::= EncodingDecl  */
  xml_1_0_EncodingDecl_maybe_002, /* EncodingDecl_maybe ::=   */
  xml_1_0_SDDecl_maybe_001      , /* SDDecl_maybe ::= SDDecl  */
  xml_1_0_SDDecl_maybe_002      , /* SDDecl_maybe ::=   */
  xml_1_0_S_maybe_001           , /* S_maybe ::= S  */
  xml_1_0_S_maybe_002           , /* S_maybe ::=   */
  xml_1_0_XMLDecl_001           , /* XMLDecl ::= _Lex028 VersionInfo EncodingDecl_maybe SDDecl_maybe S_maybe _Lex020  */
  xml_1_0__Gen097_001           , /* _Gen097 ::= _Lex008 VersionNum _Lex008  */
  xml_1_0__Gen097_002           , /* _Gen097 ::= _Lex006 VersionNum _Lex006  */
  xml_1_0_VersionInfo_001       , /* VersionInfo ::= S _Lex029 Eq _Gen097  */
  xml_1_0_Eq_001                , /* Eq ::= S_maybe _Lex030 S_maybe  */
  xml_1_0__Lex032_many_001      , /* _Lex032_many ::= _Lex032 + */
  xml_1_0_VersionNum_001        , /* VersionNum ::= _Lex031 _Lex032_many  */
  xml_1_0_Misc_001              , /* Misc ::= Comment  */
  xml_1_0_Misc_002              , /* Misc ::= PI  */
  xml_1_0_Misc_003              , /* Misc ::= S  */
  xml_1_0__Gen106_001           , /* _Gen106 ::= S ExternalID  */
  xml_1_0__Gen106_maybe_001     , /* _Gen106_maybe ::= _Gen106  */
  xml_1_0__Gen106_maybe_002     , /* _Gen106_maybe ::=   */
  xml_1_0__Gen109_001           , /* _Gen109 ::= _Lex034 intSubset _Lex035 S_maybe  */
  xml_1_0__Gen109_maybe_001     , /* _Gen109_maybe ::= _Gen109  */
  xml_1_0__Gen109_maybe_002     , /* _Gen109_maybe ::=   */
  xml_1_0_doctypedecl_001       , /* doctypedecl ::= _Lex033 S Name _Gen106_maybe S_maybe _Gen109_maybe _Lex036  */
  xml_1_0_DeclSep_001           , /* DeclSep ::= PEReference  */
  xml_1_0_DeclSep_002           , /* DeclSep ::= S  */
  xml_1_0__Gen115_001           , /* _Gen115 ::= markupdecl  */
  xml_1_0__Gen115_002           , /* _Gen115 ::= DeclSep  */
  xml_1_0__Gen115_any_001       , /* _Gen115_any ::= _Gen115 * */
  xml_1_0_intSubset_001         , /* intSubset ::= _Gen115_any  */
  xml_1_0_markupdecl_001        , /* markupdecl ::= elementdecl  */
  xml_1_0_markupdecl_002        , /* markupdecl ::= AttlistDecl  */
  xml_1_0_markupdecl_003        , /* markupdecl ::= EntityDecl  */
  xml_1_0_markupdecl_004        , /* markupdecl ::= NotationDecl  */
  xml_1_0_markupdecl_005        , /* markupdecl ::= PI  */
  xml_1_0_markupdecl_006        , /* markupdecl ::= Comment  */
  xml_1_0_TextDecl_maybe_001    , /* TextDecl_maybe ::= TextDecl  */
  xml_1_0_TextDecl_maybe_002    , /* TextDecl_maybe ::=   */
  xml_1_0_extSubset_001         , /* extSubset ::= TextDecl_maybe extSubsetDecl  */
  xml_1_0__Gen128_001           , /* _Gen128 ::= markupdecl  */
  xml_1_0__Gen128_002           , /* _Gen128 ::= conditionalSect  */
  xml_1_0__Gen128_003           , /* _Gen128 ::= DeclSep  */
  xml_1_0__Gen128_any_001       , /* _Gen128_any ::= _Gen128 * */
  xml_1_0_extSubsetDecl_001     , /* extSubsetDecl ::= _Gen128_any  */
  xml_1_0__Gen133_001           , /* _Gen133 ::= _Lex038  */
  xml_1_0__Gen133_002           , /* _Gen133 ::= _Lex039  */
  xml_1_0__Gen135_001           , /* _Gen135 ::= _Lex008 _Gen133 _Lex008  */
  xml_1_0__Gen136_001           , /* _Gen136 ::= _Lex038  */
  xml_1_0__Gen136_002           , /* _Gen136 ::= _Lex039  */
  xml_1_0__Gen138_001           , /* _Gen138 ::= _Lex006 _Gen136 _Lex006  */
  xml_1_0__Gen139_001           , /* _Gen139 ::= _Gen135  */
  xml_1_0__Gen139_002           , /* _Gen139 ::= _Gen138  */
  xml_1_0_SDDecl_001            , /* SDDecl ::= S _Lex037 Eq _Gen139  */
  xml_1_0_element_001           , /* element ::= EmptyElemTag  */
  xml_1_0_element_002           , /* element ::= STag content ETag  */
  xml_1_0__Gen144_001           , /* _Gen144 ::= S Attribute  */
  xml_1_0__Gen144_any_001       , /* _Gen144_any ::= _Gen144 * */
  xml_1_0_STag_001              , /* STag ::= _Lex040 Name _Gen144_any S_maybe _Lex036  */
  xml_1_0_Attribute_001         , /* Attribute ::= Name Eq AttValue  */
  xml_1_0_ETag_001              , /* ETag ::= _Lex041 Name S_maybe _Lex036  */
  xml_1_0_CharData_maybe_001    , /* CharData_maybe ::= CharData  */
  xml_1_0_CharData_maybe_002    , /* CharData_maybe ::=   */
  xml_1_0__Gen151_001           , /* _Gen151 ::= element  */
  xml_1_0__Gen151_002           , /* _Gen151 ::= Reference  */
  xml_1_0__Gen151_003           , /* _Gen151 ::= CDSect  */
  xml_1_0__Gen151_004           , /* _Gen151 ::= PI  */
  xml_1_0__Gen151_005           , /* _Gen151 ::= Comment  */
  xml_1_0__Gen156_001           , /* _Gen156 ::= _Gen151 CharData_maybe  */
  xml_1_0__Gen156_any_001       , /* _Gen156_any ::= _Gen156 * */
  xml_1_0_content_001           , /* content ::= CharData_maybe _Gen156_any  */
  xml_1_0__Gen159_001           , /* _Gen159 ::= S Attribute  */
  xml_1_0__Gen159_any_001       , /* _Gen159_any ::= _Gen159 * */
  xml_1_0_EmptyElemTag_001      , /* EmptyElemTag ::= _Lex040 Name _Gen159_any S_maybe _Lex042  */
  xml_1_0_elementdecl_001       , /* elementdecl ::= _Lex043 S Name S contentspec S_maybe _Lex036  */
  xml_1_0_contentspec_001       , /* contentspec ::= _Lex044  */
  xml_1_0_contentspec_002       , /* contentspec ::= _Lex045  */
  xml_1_0_contentspec_003       , /* contentspec ::= Mixed  */
  xml_1_0_contentspec_004       , /* contentspec ::= children  */
  xml_1_0__Gen167_001           , /* _Gen167 ::= choice  */
  xml_1_0__Gen167_002           , /* _Gen167 ::= seq  */
  xml_1_0__Gen169_001           , /* _Gen169 ::= _Lex046  */
  xml_1_0__Gen169_002           , /* _Gen169 ::= _Lex047  */
  xml_1_0__Gen169_003           , /* _Gen169 ::= _Lex048  */
  xml_1_0__Gen169_maybe_001     , /* _Gen169_maybe ::= _Gen169  */
  xml_1_0__Gen169_maybe_002     , /* _Gen169_maybe ::=   */
  xml_1_0_children_001          , /* children ::= _Gen167 _Gen169_maybe  */
  xml_1_0__Gen175_001           , /* _Gen175 ::= Name  */
  xml_1_0__Gen175_002           , /* _Gen175 ::= choice  */
  xml_1_0__Gen175_003           , /* _Gen175 ::= seq  */
  xml_1_0__Gen178_001           , /* _Gen178 ::= _Lex046  */
  xml_1_0__Gen178_002           , /* _Gen178 ::= _Lex047  */
  xml_1_0__Gen178_003           , /* _Gen178 ::= _Lex048  */
  xml_1_0__Gen178_maybe_001     , /* _Gen178_maybe ::= _Gen178  */
  xml_1_0__Gen178_maybe_002     , /* _Gen178_maybe ::=   */
  xml_1_0_cp_001                , /* cp ::= _Gen175 _Gen178_maybe  */
  xml_1_0__Gen184_001           , /* _Gen184 ::= S_maybe _Lex050 S_maybe cp  */
  xml_1_0__Gen184_many_001      , /* _Gen184_many ::= _Gen184 + */
  xml_1_0_choice_001            , /* choice ::= _Lex049 S_maybe cp _Gen184_many S_maybe _Lex051  */
  xml_1_0__Gen187_001           , /* _Gen187 ::= S_maybe _Lex052 S_maybe cp  */
  xml_1_0__Gen187_any_001       , /* _Gen187_any ::= _Gen187 * */
  xml_1_0_seq_001               , /* seq ::= _Lex049 S_maybe cp _Gen187_any S_maybe _Lex051  */
  xml_1_0__Gen190_001           , /* _Gen190 ::= S_maybe _Lex050 S_maybe Name  */
  xml_1_0__Gen190_any_001       , /* _Gen190_any ::= _Gen190 * */
  xml_1_0_Mixed_001             , /* Mixed ::= _Lex049 S_maybe _Lex053 _Gen190_any S_maybe _Lex054  */
  xml_1_0_Mixed_002             , /* Mixed ::= _Lex049 S_maybe _Lex053 S_maybe _Lex051  */
  xml_1_0_AttDef_any_001        , /* AttDef_any ::= AttDef * */
  xml_1_0_AttlistDecl_001       , /* AttlistDecl ::= _Lex055 S Name AttDef_any S_maybe _Lex036  */
  xml_1_0_AttDef_001            , /* AttDef ::= S Name S AttType S DefaultDecl  */
  xml_1_0_AttType_001           , /* AttType ::= StringType  */
  xml_1_0_AttType_002           , /* AttType ::= TokenizedType  */
  xml_1_0_AttType_003           , /* AttType ::= EnumeratedType  */
  xml_1_0_TokenizedType_001     , /* TokenizedType ::= _Lex057  */
  xml_1_0_TokenizedType_002     , /* TokenizedType ::= _Lex058  */
  xml_1_0_TokenizedType_003     , /* TokenizedType ::= _Lex059  */
  xml_1_0_TokenizedType_004     , /* TokenizedType ::= _Lex060  */
  xml_1_0_TokenizedType_005     , /* TokenizedType ::= _Lex061  */
  xml_1_0_TokenizedType_006     , /* TokenizedType ::= _Lex062  */
  xml_1_0_TokenizedType_007     , /* TokenizedType ::= _Lex063  */
  xml_1_0_EnumeratedType_001    , /* EnumeratedType ::= NotationType  */
  xml_1_0_EnumeratedType_002    , /* EnumeratedType ::= Enumeration  */
  xml_1_0__Gen210_001           , /* _Gen210 ::= S_maybe _Lex050 S_maybe Name  */
  xml_1_0__Gen210_any_001       , /* _Gen210_any ::= _Gen210 * */
  xml_1_0_NotationType_001      , /* NotationType ::= _Lex064 S _Lex049 S_maybe Name _Gen210_any S_maybe _Lex051  */
  xml_1_0__Gen213_001           , /* _Gen213 ::= S_maybe _Lex050 S_maybe Nmtoken  */
  xml_1_0__Gen213_any_001       , /* _Gen213_any ::= _Gen213 * */
  xml_1_0_Enumeration_001       , /* Enumeration ::= _Lex049 S_maybe Nmtoken _Gen213_any S_maybe _Lex051  */
  xml_1_0__Gen216_001           , /* _Gen216 ::= _Lex067 S  */
  xml_1_0__Gen216_maybe_001     , /* _Gen216_maybe ::= _Gen216  */
  xml_1_0__Gen216_maybe_002     , /* _Gen216_maybe ::=   */
  xml_1_0__Gen219_001           , /* _Gen219 ::= _Gen216_maybe AttValue  */
  xml_1_0_DefaultDecl_001       , /* DefaultDecl ::= _Lex065  */
  xml_1_0_DefaultDecl_002       , /* DefaultDecl ::= _Lex066  */
  xml_1_0_DefaultDecl_003       , /* DefaultDecl ::= _Gen219  */
  xml_1_0_conditionalSect_001   , /* conditionalSect ::= includeSect  */
  xml_1_0_conditionalSect_002   , /* conditionalSect ::= ignoreSect  */
  xml_1_0_includeSect_001       , /* includeSect ::= _Lex068 S_maybe _Lex069 S_maybe _Lex034 extSubsetDecl _Lex016  */
  xml_1_0_ignoreSectContents_any_001, /* ignoreSectContents_any ::= ignoreSectContents * */
  xml_1_0_ignoreSect_001        , /* ignoreSect ::= _Lex068 S_maybe _Lex070 S_maybe _Lex034 ignoreSectContents_any _Lex016  */
  xml_1_0__Gen228_001           , /* _Gen228 ::= _Lex068 ignoreSectContents _Lex016 Ignore  */
  xml_1_0__Gen228_any_001       , /* _Gen228_any ::= _Gen228 * */
  xml_1_0_ignoreSectContents_001, /* ignoreSectContents ::= Ignore _Gen228_any  */
  xml_1_0__Gen231_001           , /* _Gen231 ::= _Lex068  */
  xml_1_0__Gen231_002           , /* _Gen231 ::= _Lex016  */
  xml_1_0__Gen233_001           , /* _Gen233 ::= Char_any _Gen231 Char_any  */
  xml_1_0__Gen234_001           , /* _Gen234 ::= _Exclusion006  */
  xml_1_0_Ignore_001            , /* Ignore ::= _Gen234  */
  xml_1_0__Lex074_many_001      , /* _Lex074_many ::= _Lex074 + */
  xml_1_0_CharRef_001           , /* CharRef ::= _Lex071 _Lex032_many _Lex072  */
  xml_1_0_CharRef_002           , /* CharRef ::= _Lex073 _Lex074_many _Lex072  */
  xml_1_0_Reference_001         , /* Reference ::= EntityRef  */
  xml_1_0_Reference_002         , /* Reference ::= CharRef  */
  xml_1_0_EntityRef_001         , /* EntityRef ::= _Lex075 Name _Lex072  */
  xml_1_0_PEReference_001       , /* PEReference ::= _Lex076 Name _Lex072  */
  xml_1_0_EntityDecl_001        , /* EntityDecl ::= GEDecl  */
  xml_1_0_EntityDecl_002        , /* EntityDecl ::= PEDecl  */
  xml_1_0_GEDecl_001            , /* GEDecl ::= _Lex077 S Name S EntityDef S_maybe _Lex036  */
  xml_1_0_PEDecl_001            , /* PEDecl ::= _Lex077 S _Lex076 S Name S PEDef S_maybe _Lex036  */
  xml_1_0_NDataDecl_maybe_001   , /* NDataDecl_maybe ::= NDataDecl  */
  xml_1_0_NDataDecl_maybe_002   , /* NDataDecl_maybe ::=   */
  xml_1_0__Gen249_001           , /* _Gen249 ::= ExternalID NDataDecl_maybe  */
  xml_1_0_EntityDef_001         , /* EntityDef ::= EntityValue  */
  xml_1_0_EntityDef_002         , /* EntityDef ::= _Gen249  */
  xml_1_0_PEDef_001             , /* PEDef ::= EntityValue  */
  xml_1_0_PEDef_002             , /* PEDef ::= ExternalID  */
  xml_1_0_ExternalID_001        , /* ExternalID ::= _Lex078 S SystemLiteral  */
  xml_1_0_ExternalID_002        , /* ExternalID ::= _Lex079 S PubidLiteral S SystemLiteral  */
  xml_1_0_NDataDecl_001         , /* NDataDecl ::= S _Lex080 S Name  */
  xml_1_0_VersionInfo_maybe_001 , /* VersionInfo_maybe ::= VersionInfo  */
  xml_1_0_VersionInfo_maybe_002 , /* VersionInfo_maybe ::=   */
  xml_1_0_TextDecl_001          , /* TextDecl ::= _Lex028 VersionInfo_maybe EncodingDecl S_maybe _Lex020  */
  xml_1_0_extParsedEnt_001      , /* extParsedEnt ::= TextDecl_maybe content  */
  xml_1_0__Gen261_001           , /* _Gen261 ::= _Lex006 EncName _Lex006  */
  xml_1_0__Gen261_002           , /* _Gen261 ::= _Lex008 EncName _Lex008  */
  xml_1_0_EncodingDecl_001      , /* EncodingDecl ::= S _Lex081 Eq _Gen261  */
  xml_1_0__Gen264_001           , /* _Gen264 ::= _Lex083  */
  xml_1_0__Gen264_002           , /* _Gen264 ::= _Lex084  */
  xml_1_0__Gen264_any_001       , /* _Gen264_any ::= _Gen264 * */
  xml_1_0_EncName_001           , /* EncName ::= _Lex082 _Gen264_any  */
  xml_1_0__Gen268_001           , /* _Gen268 ::= ExternalID  */
  xml_1_0__Gen268_002           , /* _Gen268 ::= PublicID  */
  xml_1_0_NotationDecl_001      , /* NotationDecl ::= _Lex085 S Name S _Gen268 S_maybe _Lex036  */
  xml_1_0_PublicID_001          , /* PublicID ::= _Lex079 S PubidLiteral  */
  XML_1_0_RULE_MAX
} xml_1_0_rule_t;


/* Callback structure for symbols */
typedef struct xml_1_0_callback {
  xml_1_0_t *xml_1_0p;
  xml_1_0_symbol_t xml_1_0_symboli;
} xml_1_0_callback_t;

/* Work structure */
struct xml_1_0 {
  marpaWrapper_t          *marpaWrapperp;
  marpaWrapperSymbol_t   **marpaWrapperSymbolArrayp;
  size_t                   marpaWrapperSymbolArrayLengthi;
  marpaWrapperRule_t     **marpaWrapperRuleArrayp;
  size_t                   marpaWrapperRuleArrayLengthi;
  xml_1_0_callback_t *marpaWrapperSymbolCallbackArrayp;
  size_t                   marpaWrapperSymbolCallbackArrayLengthi;
};

/* Terminals to string - indexed by xml_1_0_symbol_t */
static const char *symbolsToString[] = {
    /* Terminals */
  "CDStart ~ '<![CDATA['",
  "Char ~ [\\x{9}\\x{a}\\x{d}\\x{20}-\\x{d7ff}\\x{e000}-\\x{fffd}\\x{10000}-\\x{10ffff}]",
  "NameStartChar ~ [:A-Z_a-z\\x{c0}-\\x{d6}\\x{d8}-\\x{f6}\\x{f8}-\\x{2ff}\\x{370}-\\x{37d}\\x{37f}-\\x{1fff}\\x{200c}-\\x{200d}\\x{2070}-\\x{218f}\\x{2c00}-\\x{2fef}\\x{3001}-\\x{d7ff}\\x{f900}-\\x{fdcf}\\x{fdf0}-\\x{fffd}\\x{10000}-\\x{effff}]",
  "PubidChar ~ [a-zA-Z0-9-'()+,./:=?;!*#@$_%\\x{20}\\x{d}\\x{a}]",
  "StringType ~ 'CDATA'",
  "_Exclusion001 ~ 'PubidChar - _Lex008'",
  "_Exclusion002 ~ '_Lex015_any - _Gen056'",
  "_Exclusion003 ~ 'Char_any - _Gen061'",
  "_Exclusion004 ~ 'Name - _Gen074'",
  "_Exclusion005 ~ 'Char_any - _Gen079'",
  "_Exclusion006 ~ 'Char_any - _Gen233'",
  "_Lex002 ~ [\\x{20}\\x{9}\\x{d}\\x{a}]",
  "_Lex004 ~ [-.0-9\\x{b7}\\x{300}-\\x{36f}\\x{203f}-\\x{2040}]",
  "_Lex005 ~ [\\x{20}]",
  "_Lex006 ~ '\"'",
  "_Lex007 ~ [^%&\"]",
  "_Lex008 ~ [']",
  "_Lex009 ~ [^%&']",
  "_Lex010 ~ [^<&\"]",
  "_Lex011 ~ [^<&']",
  "_Lex012 ~ [^\"]",
  "_Lex013 ~ [^']",
  "_Lex015 ~ [^<&]",
  "_Lex016 ~ ']]>'",
  "_Lex017 ~ '<!--'",
  "_Lex018 ~ '-->'",
  "_Lex019 ~ '<?'",
  "_Lex020 ~ '?>'",
  "_Lex021 ~ 'X'",
  "_Lex022 ~ 'x'",
  "_Lex023 ~ 'M'",
  "_Lex024 ~ 'm'",
  "_Lex025 ~ 'L'",
  "_Lex026 ~ 'l'",
  "_Lex028 ~ '<?xml'",
  "_Lex029 ~ 'version'",
  "_Lex030 ~ '='",
  "_Lex031 ~ '1.'",
  "_Lex032 ~ [0-9]",
  "_Lex033 ~ '<!DOCTYPE'",
  "_Lex034 ~ '['",
  "_Lex035 ~ ']'",
  "_Lex036 ~ '>'",
  "_Lex037 ~ 'standalone'",
  "_Lex038 ~ 'yes'",
  "_Lex039 ~ 'no'",
  "_Lex040 ~ '<'",
  "_Lex041 ~ '</'",
  "_Lex042 ~ '/>'",
  "_Lex043 ~ '<!ELEMENT'",
  "_Lex044 ~ 'EMPTY'",
  "_Lex045 ~ 'ANY'",
  "_Lex046 ~ '?'",
  "_Lex047 ~ '*'",
  "_Lex048 ~ '+'",
  "_Lex049 ~ '('",
  "_Lex050 ~ '|'",
  "_Lex051 ~ ')'",
  "_Lex052 ~ ','",
  "_Lex053 ~ '#PCDATA'",
  "_Lex054 ~ ')*'",
  "_Lex055 ~ '<!ATTLIST'",
  "_Lex057 ~ 'ID'",
  "_Lex058 ~ 'IDREF'",
  "_Lex059 ~ 'IDREFS'",
  "_Lex060 ~ 'ENTITY'",
  "_Lex061 ~ 'ENTITIES'",
  "_Lex062 ~ 'NMTOKEN'",
  "_Lex063 ~ 'NMTOKENS'",
  "_Lex064 ~ 'NOTATION'",
  "_Lex065 ~ '#REQUIRED'",
  "_Lex066 ~ '#IMPLIED'",
  "_Lex067 ~ '#FIXED'",
  "_Lex068 ~ '<!['",
  "_Lex069 ~ 'INCLUDE'",
  "_Lex070 ~ 'IGNORE'",
  "_Lex071 ~ '&#'",
  "_Lex072 ~ ';'",
  "_Lex073 ~ '&#x'",
  "_Lex074 ~ [0-9a-fA-F]",
  "_Lex075 ~ '&'",
  "_Lex076 ~ '%'",
  "_Lex077 ~ '<!ENTITY'",
  "_Lex078 ~ 'SYSTEM'",
  "_Lex079 ~ 'PUBLIC'",
  "_Lex080 ~ 'NDATA'",
  "_Lex081 ~ 'encoding'",
  "_Lex082 ~ [A-Za-z]",
  "_Lex083 ~ [A-Za-z0-9._]",
  "_Lex084 ~ '-'",
  "_Lex085 ~ '<!NOTATION'",
  /* Non-terminals */
  "AttDef",
  "AttDef_any",
  "AttType",
  "AttValue",
  "AttlistDecl",
  "Attribute",
  "CDEnd",
  "CDSect",
  "CData",
  "CharData",
  "CharData_maybe",
  "CharRef",
  "Char_any",
  "Comment",
  "DeclSep",
  "DefaultDecl",
  "ETag",
  "EmptyElemTag",
  "EncName",
  "EncodingDecl",
  "EncodingDecl_maybe",
  "EntityDecl",
  "EntityDef",
  "EntityRef",
  "EntityValue",
  "EnumeratedType",
  "Enumeration",
  "Eq",
  "ExternalID",
  "GEDecl",
  "Ignore",
  "Misc",
  "Misc_any",
  "Mixed",
  "NDataDecl",
  "NDataDecl_maybe",
  "Name",
  "NameChar",
  "Names",
  "Nmtoken",
  "Nmtokens",
  "NotationDecl",
  "NotationType",
  "PEDecl",
  "PEDef",
  "PEReference",
  "PI",
  "PITarget",
  "PubidChar_any",
  "PubidLiteral",
  "PublicID",
  "Reference",
  "S",
  "SDDecl",
  "SDDecl_maybe",
  "STag",
  "S_maybe",
  "SystemLiteral",
  "TextDecl",
  "TextDecl_maybe",
  "TokenizedType",
  "VersionInfo",
  "VersionInfo_maybe",
  "VersionNum",
  "XMLDecl",
  "XMLDecl_maybe",
  "_Gen012",
  "_Gen012_any",
  "_Gen015",
  "_Gen015_any",
  "_Gen018",
  "_Gen018_many",
  "_Gen021",
  "_Gen021_any",
  "_Gen024",
  "_Gen024_any",
  "_Gen028",
  "_Gen028_any",
  "_Gen034",
  "_Gen034_any",
  "_Gen037",
  "_Gen037_any",
  "_Gen043",
  "_Gen045",
  "_Gen049",
  "_Gen050",
  "_Gen050_any",
  "_Gen056",
  "_Gen057",
  "_Gen061",
  "_Gen062",
  "_Gen063",
  "_Gen064",
  "_Gen064_maybe",
  "_Gen068",
  "_Gen070",
  "_Gen072",
  "_Gen074",
  "_Gen075",
  "_Gen079",
  "_Gen080",
  "_Gen081",
  "_Gen086",
  "_Gen086_maybe",
  "_Gen097",
  "_Gen106",
  "_Gen106_maybe",
  "_Gen109",
  "_Gen109_maybe",
  "_Gen115",
  "_Gen115_any",
  "_Gen128",
  "_Gen128_any",
  "_Gen133",
  "_Gen135",
  "_Gen136",
  "_Gen138",
  "_Gen139",
  "_Gen144",
  "_Gen144_any",
  "_Gen151",
  "_Gen156",
  "_Gen156_any",
  "_Gen159",
  "_Gen159_any",
  "_Gen167",
  "_Gen169",
  "_Gen169_maybe",
  "_Gen175",
  "_Gen178",
  "_Gen178_maybe",
  "_Gen184",
  "_Gen184_many",
  "_Gen187",
  "_Gen187_any",
  "_Gen190",
  "_Gen190_any",
  "_Gen210",
  "_Gen210_any",
  "_Gen213",
  "_Gen213_any",
  "_Gen216",
  "_Gen216_maybe",
  "_Gen219",
  "_Gen228",
  "_Gen228_any",
  "_Gen231",
  "_Gen233",
  "_Gen234",
  "_Gen249",
  "_Gen261",
  "_Gen264",
  "_Gen264_any",
  "_Gen268",
  "_Lex002_many",
  "_Lex012_any",
  "_Lex013_any",
  "_Lex015_any",
  "_Lex032_many",
  "_Lex074_many",
  "children",
  "choice",
  "conditionalSect",
  "content",
  "contentspec",
  "cp",
  "doctypedecl",
  "document",
  "element",
  "elementdecl",
  "extParsedEnt",
  "extSubset",
  "extSubsetDecl",
  "ignoreSect",
  "ignoreSectContents",
  "ignoreSectContents_any",
  "includeSect",
  "intSubset",
  "markupdecl",
  "prolog",
  "seq",
  "start"
};

/* Rules to string indexed by xml_1_0_rule_t */
static const char *rulesToString[] = {
  "start ::= document ",
  "start ::= extParsedEnt ",
  "start ::= extSubset ",
  "Misc_any ::= Misc *",
  "document ::= prolog element Misc_any ",
  "_Lex002_many ::= _Lex002 +",
  "S ::= _Lex002_many ",
  "NameChar ::= NameStartChar ",
  "NameChar ::= _Lex004 ",
  "_Gen012 ::= NameChar ",
  "_Gen012_any ::= _Gen012 *",
  "Name ::= NameStartChar _Gen012_any ",
  "_Gen015 ::= _Lex005 Name ",
  "_Gen015_any ::= _Gen015 *",
  "Names ::= Name _Gen015_any ",
  "_Gen018 ::= NameChar ",
  "_Gen018_many ::= _Gen018 +",
  "Nmtoken ::= _Gen018_many ",
  "_Gen021 ::= _Lex005 Nmtoken ",
  "_Gen021_any ::= _Gen021 *",
  "Nmtokens ::= Nmtoken _Gen021_any ",
  "_Gen024 ::= _Lex007 ",
  "_Gen024 ::= PEReference ",
  "_Gen024 ::= Reference ",
  "_Gen024_any ::= _Gen024 *",
  "_Gen028 ::= _Lex009 ",
  "_Gen028 ::= PEReference ",
  "_Gen028 ::= Reference ",
  "_Gen028_any ::= _Gen028 *",
  "EntityValue ::= _Lex006 _Gen024_any _Lex006 ",
  "EntityValue ::= _Lex008 _Gen028_any _Lex008 ",
  "_Gen034 ::= _Lex010 ",
  "_Gen034 ::= Reference ",
  "_Gen034_any ::= _Gen034 *",
  "_Gen037 ::= _Lex011 ",
  "_Gen037 ::= Reference ",
  "_Gen037_any ::= _Gen037 *",
  "AttValue ::= _Lex006 _Gen034_any _Lex006 ",
  "AttValue ::= _Lex008 _Gen037_any _Lex008 ",
  "_Lex012_any ::= _Lex012 *",
  "_Gen043 ::= _Lex006 _Lex012_any _Lex006 ",
  "_Lex013_any ::= _Lex013 *",
  "_Gen045 ::= _Lex008 _Lex013_any _Lex008 ",
  "SystemLiteral ::= _Gen043 ",
  "SystemLiteral ::= _Gen045 ",
  "PubidChar_any ::= PubidChar *",
  "_Gen049 ::= _Exclusion001 ",
  "_Gen050 ::= _Gen049 ",
  "_Gen050_any ::= _Gen050 *",
  "PubidLiteral ::= _Lex006 PubidChar_any _Lex006 ",
  "PubidLiteral ::= _Lex008 _Gen050_any _Lex008 ",
  "_Lex015_any ::= _Lex015 *",
  "_Gen056 ::= _Lex015_any _Lex016 _Lex015_any ",
  "_Gen057 ::= _Exclusion002 ",
  "CharData ::= _Gen057 ",
  "Char_any ::= Char *",
  "Comment ::= _Lex017 Char_any _Lex018 ",
  "_Gen061 ::= Char_any _Lex020 Char_any ",
  "_Gen062 ::= _Exclusion003 ",
  "_Gen063 ::= _Gen062 ",
  "_Gen064 ::= S _Gen063 ",
  "_Gen064_maybe ::= _Gen064 ",
  "_Gen064_maybe ::=  ",
  "PI ::= _Lex019 PITarget _Gen064_maybe _Lex020 ",
  "_Gen068 ::= _Lex021 ",
  "_Gen068 ::= _Lex022 ",
  "_Gen070 ::= _Lex023 ",
  "_Gen070 ::= _Lex024 ",
  "_Gen072 ::= _Lex025 ",
  "_Gen072 ::= _Lex026 ",
  "_Gen074 ::= _Gen068 _Gen070 _Gen072 ",
  "_Gen075 ::= _Exclusion004 ",
  "PITarget ::= _Gen075 ",
  "CDSect ::= CDStart CData CDEnd ",
  "_Gen079 ::= Char_any _Lex016 Char_any ",
  "_Gen080 ::= _Exclusion005 ",
  "_Gen081 ::= _Gen080 ",
  "CData ::= _Gen081 ",
  "CDEnd ::= _Lex016 ",
  "XMLDecl_maybe ::= XMLDecl ",
  "XMLDecl_maybe ::=  ",
  "_Gen086 ::= doctypedecl Misc_any ",
  "_Gen086_maybe ::= _Gen086 ",
  "_Gen086_maybe ::=  ",
  "prolog ::= XMLDecl_maybe Misc_any _Gen086_maybe ",
  "EncodingDecl_maybe ::= EncodingDecl ",
  "EncodingDecl_maybe ::=  ",
  "SDDecl_maybe ::= SDDecl ",
  "SDDecl_maybe ::=  ",
  "S_maybe ::= S ",
  "S_maybe ::=  ",
  "XMLDecl ::= _Lex028 VersionInfo EncodingDecl_maybe SDDecl_maybe S_maybe _Lex020 ",
  "_Gen097 ::= _Lex008 VersionNum _Lex008 ",
  "_Gen097 ::= _Lex006 VersionNum _Lex006 ",
  "VersionInfo ::= S _Lex029 Eq _Gen097 ",
  "Eq ::= S_maybe _Lex030 S_maybe ",
  "_Lex032_many ::= _Lex032 +",
  "VersionNum ::= _Lex031 _Lex032_many ",
  "Misc ::= Comment ",
  "Misc ::= PI ",
  "Misc ::= S ",
  "_Gen106 ::= S ExternalID ",
  "_Gen106_maybe ::= _Gen106 ",
  "_Gen106_maybe ::=  ",
  "_Gen109 ::= _Lex034 intSubset _Lex035 S_maybe ",
  "_Gen109_maybe ::= _Gen109 ",
  "_Gen109_maybe ::=  ",
  "doctypedecl ::= _Lex033 S Name _Gen106_maybe S_maybe _Gen109_maybe _Lex036 ",
  "DeclSep ::= PEReference ",
  "DeclSep ::= S ",
  "_Gen115 ::= markupdecl ",
  "_Gen115 ::= DeclSep ",
  "_Gen115_any ::= _Gen115 *",
  "intSubset ::= _Gen115_any ",
  "markupdecl ::= elementdecl ",
  "markupdecl ::= AttlistDecl ",
  "markupdecl ::= EntityDecl ",
  "markupdecl ::= NotationDecl ",
  "markupdecl ::= PI ",
  "markupdecl ::= Comment ",
  "TextDecl_maybe ::= TextDecl ",
  "TextDecl_maybe ::=  ",
  "extSubset ::= TextDecl_maybe extSubsetDecl ",
  "_Gen128 ::= markupdecl ",
  "_Gen128 ::= conditionalSect ",
  "_Gen128 ::= DeclSep ",
  "_Gen128_any ::= _Gen128 *",
  "extSubsetDecl ::= _Gen128_any ",
  "_Gen133 ::= _Lex038 ",
  "_Gen133 ::= _Lex039 ",
  "_Gen135 ::= _Lex008 _Gen133 _Lex008 ",
  "_Gen136 ::= _Lex038 ",
  "_Gen136 ::= _Lex039 ",
  "_Gen138 ::= _Lex006 _Gen136 _Lex006 ",
  "_Gen139 ::= _Gen135 ",
  "_Gen139 ::= _Gen138 ",
  "SDDecl ::= S _Lex037 Eq _Gen139 ",
  "element ::= EmptyElemTag ",
  "element ::= STag content ETag ",
  "_Gen144 ::= S Attribute ",
  "_Gen144_any ::= _Gen144 *",
  "STag ::= _Lex040 Name _Gen144_any S_maybe _Lex036 ",
  "Attribute ::= Name Eq AttValue ",
  "ETag ::= _Lex041 Name S_maybe _Lex036 ",
  "CharData_maybe ::= CharData ",
  "CharData_maybe ::=  ",
  "_Gen151 ::= element ",
  "_Gen151 ::= Reference ",
  "_Gen151 ::= CDSect ",
  "_Gen151 ::= PI ",
  "_Gen151 ::= Comment ",
  "_Gen156 ::= _Gen151 CharData_maybe ",
  "_Gen156_any ::= _Gen156 *",
  "content ::= CharData_maybe _Gen156_any ",
  "_Gen159 ::= S Attribute ",
  "_Gen159_any ::= _Gen159 *",
  "EmptyElemTag ::= _Lex040 Name _Gen159_any S_maybe _Lex042 ",
  "elementdecl ::= _Lex043 S Name S contentspec S_maybe _Lex036 ",
  "contentspec ::= _Lex044 ",
  "contentspec ::= _Lex045 ",
  "contentspec ::= Mixed ",
  "contentspec ::= children ",
  "_Gen167 ::= choice ",
  "_Gen167 ::= seq ",
  "_Gen169 ::= _Lex046 ",
  "_Gen169 ::= _Lex047 ",
  "_Gen169 ::= _Lex048 ",
  "_Gen169_maybe ::= _Gen169 ",
  "_Gen169_maybe ::=  ",
  "children ::= _Gen167 _Gen169_maybe ",
  "_Gen175 ::= Name ",
  "_Gen175 ::= choice ",
  "_Gen175 ::= seq ",
  "_Gen178 ::= _Lex046 ",
  "_Gen178 ::= _Lex047 ",
  "_Gen178 ::= _Lex048 ",
  "_Gen178_maybe ::= _Gen178 ",
  "_Gen178_maybe ::=  ",
  "cp ::= _Gen175 _Gen178_maybe ",
  "_Gen184 ::= S_maybe _Lex050 S_maybe cp ",
  "_Gen184_many ::= _Gen184 +",
  "choice ::= _Lex049 S_maybe cp _Gen184_many S_maybe _Lex051 ",
  "_Gen187 ::= S_maybe _Lex052 S_maybe cp ",
  "_Gen187_any ::= _Gen187 *",
  "seq ::= _Lex049 S_maybe cp _Gen187_any S_maybe _Lex051 ",
  "_Gen190 ::= S_maybe _Lex050 S_maybe Name ",
  "_Gen190_any ::= _Gen190 *",
  "Mixed ::= _Lex049 S_maybe _Lex053 _Gen190_any S_maybe _Lex054 ",
  "Mixed ::= _Lex049 S_maybe _Lex053 S_maybe _Lex051 ",
  "AttDef_any ::= AttDef *",
  "AttlistDecl ::= _Lex055 S Name AttDef_any S_maybe _Lex036 ",
  "AttDef ::= S Name S AttType S DefaultDecl ",
  "AttType ::= StringType ",
  "AttType ::= TokenizedType ",
  "AttType ::= EnumeratedType ",
  "TokenizedType ::= _Lex057 ",
  "TokenizedType ::= _Lex058 ",
  "TokenizedType ::= _Lex059 ",
  "TokenizedType ::= _Lex060 ",
  "TokenizedType ::= _Lex061 ",
  "TokenizedType ::= _Lex062 ",
  "TokenizedType ::= _Lex063 ",
  "EnumeratedType ::= NotationType ",
  "EnumeratedType ::= Enumeration ",
  "_Gen210 ::= S_maybe _Lex050 S_maybe Name ",
  "_Gen210_any ::= _Gen210 *",
  "NotationType ::= _Lex064 S _Lex049 S_maybe Name _Gen210_any S_maybe _Lex051 ",
  "_Gen213 ::= S_maybe _Lex050 S_maybe Nmtoken ",
  "_Gen213_any ::= _Gen213 *",
  "Enumeration ::= _Lex049 S_maybe Nmtoken _Gen213_any S_maybe _Lex051 ",
  "_Gen216 ::= _Lex067 S ",
  "_Gen216_maybe ::= _Gen216 ",
  "_Gen216_maybe ::=  ",
  "_Gen219 ::= _Gen216_maybe AttValue ",
  "DefaultDecl ::= _Lex065 ",
  "DefaultDecl ::= _Lex066 ",
  "DefaultDecl ::= _Gen219 ",
  "conditionalSect ::= includeSect ",
  "conditionalSect ::= ignoreSect ",
  "includeSect ::= _Lex068 S_maybe _Lex069 S_maybe _Lex034 extSubsetDecl _Lex016 ",
  "ignoreSectContents_any ::= ignoreSectContents *",
  "ignoreSect ::= _Lex068 S_maybe _Lex070 S_maybe _Lex034 ignoreSectContents_any _Lex016 ",
  "_Gen228 ::= _Lex068 ignoreSectContents _Lex016 Ignore ",
  "_Gen228_any ::= _Gen228 *",
  "ignoreSectContents ::= Ignore _Gen228_any ",
  "_Gen231 ::= _Lex068 ",
  "_Gen231 ::= _Lex016 ",
  "_Gen233 ::= Char_any _Gen231 Char_any ",
  "_Gen234 ::= _Exclusion006 ",
  "Ignore ::= _Gen234 ",
  "_Lex074_many ::= _Lex074 +",
  "CharRef ::= _Lex071 _Lex032_many _Lex072 ",
  "CharRef ::= _Lex073 _Lex074_many _Lex072 ",
  "Reference ::= EntityRef ",
  "Reference ::= CharRef ",
  "EntityRef ::= _Lex075 Name _Lex072 ",
  "PEReference ::= _Lex076 Name _Lex072 ",
  "EntityDecl ::= GEDecl ",
  "EntityDecl ::= PEDecl ",
  "GEDecl ::= _Lex077 S Name S EntityDef S_maybe _Lex036 ",
  "PEDecl ::= _Lex077 S _Lex076 S Name S PEDef S_maybe _Lex036 ",
  "NDataDecl_maybe ::= NDataDecl ",
  "NDataDecl_maybe ::=  ",
  "_Gen249 ::= ExternalID NDataDecl_maybe ",
  "EntityDef ::= EntityValue ",
  "EntityDef ::= _Gen249 ",
  "PEDef ::= EntityValue ",
  "PEDef ::= ExternalID ",
  "ExternalID ::= _Lex078 S SystemLiteral ",
  "ExternalID ::= _Lex079 S PubidLiteral S SystemLiteral ",
  "NDataDecl ::= S _Lex080 S Name ",
  "VersionInfo_maybe ::= VersionInfo ",
  "VersionInfo_maybe ::=  ",
  "TextDecl ::= _Lex028 VersionInfo_maybe EncodingDecl S_maybe _Lex020 ",
  "extParsedEnt ::= TextDecl_maybe content ",
  "_Gen261 ::= _Lex006 EncName _Lex006 ",
  "_Gen261 ::= _Lex008 EncName _Lex008 ",
  "EncodingDecl ::= S _Lex081 Eq _Gen261 ",
  "_Gen264 ::= _Lex083 ",
  "_Gen264 ::= _Lex084 ",
  "_Gen264_any ::= _Gen264 *",
  "EncName ::= _Lex082 _Gen264_any ",
  "_Gen268 ::= ExternalID ",
  "_Gen268 ::= PublicID ",
  "NotationDecl ::= _Lex085 S Name S _Gen268 S_maybe _Lex036 ",
  "PublicID ::= _Lex079 S PubidLiteral "
};

static C_INLINE marpaWrapperBool_t _xml_1_0_buildGrammarb(xml_1_0_t *xml_1_0p, marpaWrapperOption_t *marpaWrapperOptionp, xml_common_option_t *xml_common_optionp);
static C_INLINE marpaWrapperBool_t _xml_1_0_buildSymbolsb(xml_1_0_t *xml_1_0p, marpaWrapperOption_t *marpaWrapperOptionp, xml_common_option_t *xml_common_optionp);
static C_INLINE marpaWrapperBool_t _xml_1_0_buildRulesb(xml_1_0_t *xml_1_0p);
static C_INLINE marpaWrapperBool_t _xml_1_0_isLexemeb(void *p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0_CDStartb(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0_Charb(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0_NameStartCharb(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0_PubidCharb(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0_StringTypeb(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion001b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion002b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion003b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion004b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion005b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion006b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex002b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex004b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex005b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex006b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex007b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex008b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex009b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex010b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex011b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex012b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex013b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex015b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex016b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex017b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex018b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex019b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex020b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex021b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex022b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex023b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex024b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex025b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex026b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex028b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex029b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex030b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex031b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex032b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex033b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex034b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex035b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex036b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex037b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex038b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex039b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex040b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex041b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex042b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex043b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex044b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex045b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex046b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex047b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex048b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex049b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex050b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex051b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex052b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex053b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex054b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex055b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex057b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex058b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex059b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex060b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex061b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex062b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex063b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex064b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex065b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex066b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex067b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex068b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex069b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex070b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex071b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex072b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex073b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex074b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex075b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex076b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex077b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex078b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex079b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex080b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex081b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex082b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex083b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex084b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex085b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);

/*******************/
/* xml_1_0_newp  */
/*******************/
xml_1_0_t *xml_1_0_newp(marpaWrapperOption_t *marpaWrapperOptionp, xml_common_option_t *xml_common_optionp) {
  xml_1_0_t           *xml_1_0p;
  marpaWrapperOption_t marpaWrapperOption;

  /* Fill the defaults */
  if (marpaWrapperOptionp == NULL) {
    marpaWrapper_optionDefaultb(&marpaWrapperOption);
  } else {
    marpaWrapperOption = *marpaWrapperOptionp;
  }

  /* xml_common_optionp is internal and should always be setted */
  if (xml_common_optionp == NULL) {
    marpaWrapper_logExt(marpaWrapperOption.logCallbackp,
		        marpaWrapperOption.logCallbackDatavp,
		        NULL,
		        marpaWrapperOption.logLevelWantedi,
		        MARPAWRAPPERERRORORIGIN_NA,
		        errno,
		        "Missing xml_common_optionp",
		        MARPAWRAPPER_LOGLEVEL_ERROR);
    return NULL;
  }

  xml_1_0p = malloc(sizeof(xml_1_0_t));
  if (xml_1_0p == NULL) {
    marpaWrapper_logExt(marpaWrapperOption.logCallbackp,
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
  xml_1_0p->marpaWrapperSymbolCallbackArrayp = NULL;
  xml_1_0p->marpaWrapperSymbolCallbackArrayLengthi = 0;

  if (_xml_1_0_buildGrammarb(xml_1_0p, &marpaWrapperOption, xml_common_optionp) == MARPAWRAPPER_BOOL_FALSE) {
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
      if (xml_1_0p->marpaWrapperRuleArrayp != NULL) {
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
static C_INLINE marpaWrapperBool_t _xml_1_0_buildGrammarb(xml_1_0_t *xml_1_0p, marpaWrapperOption_t *marpaWrapperOptionp, xml_common_option_t *xml_common_optionp) {

  xml_1_0p->marpaWrapperp = marpaWrapper_newp(marpaWrapperOptionp);
  if (xml_1_0p->marpaWrapperp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (_xml_1_0_buildSymbolsb(xml_1_0p, marpaWrapperOptionp, xml_common_optionp) == MARPAWRAPPER_BOOL_FALSE) {
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
static C_INLINE marpaWrapperBool_t _xml_1_0_buildSymbolsb(xml_1_0_t *xml_1_0p, marpaWrapperOption_t *marpaWrapperOptionp, xml_common_option_t *xml_common_optionp) {
  int                        i;
  marpaWrapperSymbolOption_t marpaWrapperSymbolOption;

  xml_1_0p->marpaWrapperSymbolArrayp = malloc(XML_1_0_SYMBOL_MAX * sizeof(marpaWrapperSymbol_t *));
  if (xml_1_0p->marpaWrapperSymbolArrayp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }
  xml_1_0p->marpaWrapperSymbolCallbackArrayp = malloc(XML_1_0_SYMBOL_MAX * sizeof(xml_1_0_callback_t));
  if (xml_1_0p->marpaWrapperSymbolCallbackArrayp == NULL) {
    free(xml_1_0p->marpaWrapperSymbolArrayp);
    return MARPAWRAPPER_BOOL_FALSE;
  }
 
  xml_1_0p->marpaWrapperSymbolArrayLengthi = XML_1_0_SYMBOL_MAX;
  xml_1_0p->marpaWrapperSymbolCallbackArrayLengthi = XML_1_0_SYMBOL_MAX;

  for (i = 0; i < XML_1_0_SYMBOL_MAX; i++) {

    /* Fill default options */
    if (marpaWrapper_symbolOptionDefaultb(&marpaWrapperSymbolOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }

    /* Opaque data associated to symbol will be the symbol enum */
    xml_1_0p->marpaWrapperSymbolCallbackArrayp[i].xml_1_0p = xml_1_0p;
    xml_1_0p->marpaWrapperSymbolCallbackArrayp[i].xml_1_0_symboli = i;
    marpaWrapperSymbolOption.datavp = (void *) &(xml_1_0p->marpaWrapperSymbolCallbackArrayp[i]);

    /* Optional, but we can make ourself the terminals */
    marpaWrapperSymbolOption.terminalb = (i <= XML_1_0_TERMINAL_MAX) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;

    /* Start rule ? */
    switch (xml_common_optionp->xml_common_topi) {
      case XML_COMMON_TOP_DOCUMENT:
        marpaWrapperSymbolOption.startb = (i == xml_1_0_document) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
        break;
      case XML_COMMON_TOP_EXTPARSEDENT:
        marpaWrapperSymbolOption.startb = (i == xml_1_0_extParsedEnt) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
        break;
      case XML_COMMON_TOP_EXTSUBSET:
        marpaWrapperSymbolOption.startb = (i == xml_1_0_extSubset) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
        break;
      default:
        marpaWrapper_logExt(marpaWrapperOptionp->logCallbackp,
                            marpaWrapperOptionp->logCallbackDatavp,
                            xml_1_0p->marpaWrapperp,
                            marpaWrapperOptionp->logLevelWantedi,
                            MARPAWRAPPERERRORORIGIN_NA,
                            EINVAL,
                            "Bad top-level symbol()",
                            MARPAWRAPPER_LOGLEVEL_ERROR);
        return MARPAWRAPPER_BOOL_FALSE;
        break;
      }

    /* Create the symbol */
    xml_1_0p->marpaWrapperSymbolArrayp[i] = marpaWrapper_g_addSymbolp(xml_1_0p->marpaWrapperp, &marpaWrapperSymbolOption);
    if (xml_1_0p->marpaWrapperSymbolArrayp[i] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }

  }

  return MARPAWRAPPER_BOOL_TRUE;
}

/************************/
/* _xml_1_0_buildRulesb */
/************************/
static C_INLINE marpaWrapperBool_t _xml_1_0_buildRulesb(xml_1_0_t *xml_1_0p) {
  marpaWrapperRuleOption_t   marpaWrapperRuleOption;

  xml_1_0p->marpaWrapperRuleArrayp = malloc(XML_1_0_RULE_MAX * sizeof(marpaWrapperRule_t *));
  if (xml_1_0p->marpaWrapperRuleArrayp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }
  xml_1_0p->marpaWrapperRuleArrayLengthi = XML_1_0_RULE_MAX;

  {
    /* [xml_1_0_start_001] start ::= document  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_document]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_start_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_start];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_start_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_start_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_start_002] start ::= extParsedEnt  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_extParsedEnt]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_start_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_start];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_start_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_start_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_start_003] start ::= extSubset  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_extSubset]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_start_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_start];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_start_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_start_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Misc_any_001] Misc_any ::= Misc * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Misc]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_Misc_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Misc_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Misc_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Misc_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_document_001] document ::= prolog element Misc_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_prolog],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_element],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Misc_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_document_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_document];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_document_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_document_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Lex002_many_001] _Lex002_many ::= _Lex002 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex002]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Lex002_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex002_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 1;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Lex002_many_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Lex002_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_S_001] S ::= _Lex002_many  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex002_many]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_S_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_S_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_S_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NameChar_001] NameChar ::= NameStartChar  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameStartChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NameChar_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameChar_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameChar_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NameChar_002] NameChar ::= _Lex004  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex004]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NameChar_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameChar_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameChar_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen012_001] _Gen012 ::= NameChar  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen012_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen012];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen012_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen012_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen012_any_001] _Gen012_any ::= _Gen012 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen012]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen012_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen012_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen012_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen012_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Name_001] Name ::= NameStartChar _Gen012_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameStartChar],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen012_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_Name_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Name_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Name_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen015_001] _Gen015 ::= _Lex005 Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex005],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen015_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen015];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen015_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen015_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen015_any_001] _Gen015_any ::= _Gen015 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen015]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen015_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen015_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen015_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen015_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Names_001] Names ::= Name _Gen015_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen015_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_Names_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Names];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Names_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Names_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen018_001] _Gen018 ::= NameChar  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen018_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen018];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen018_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen018_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen018_many_001] _Gen018_many ::= _Gen018 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen018]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen018_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen018_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 1;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen018_many_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen018_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Nmtoken_001] Nmtoken ::= _Gen018_many  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen018_many]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_Nmtoken_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Nmtoken];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Nmtoken_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Nmtoken_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen021_001] _Gen021 ::= _Lex005 Nmtoken  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex005],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Nmtoken]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen021_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen021];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen021_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen021_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen021_any_001] _Gen021_any ::= _Gen021 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen021]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen021_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen021_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen021_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen021_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Nmtokens_001] Nmtokens ::= Nmtoken _Gen021_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Nmtoken],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen021_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_Nmtokens_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Nmtokens];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Nmtokens_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Nmtokens_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen024_001] _Gen024 ::= _Lex007  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex007]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen024_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen024];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen024_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen024_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen024_002] _Gen024 ::= PEReference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PEReference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen024_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen024];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen024_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen024_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen024_003] _Gen024 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen024_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen024];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen024_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen024_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen024_any_001] _Gen024_any ::= _Gen024 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen024]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen024_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen024_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen024_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen024_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen028_001] _Gen028 ::= _Lex009  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex009]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen028_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen028];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen028_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen028_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen028_002] _Gen028 ::= PEReference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PEReference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen028_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen028];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen028_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen028_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen028_003] _Gen028 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen028_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen028];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen028_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen028_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen028_any_001] _Gen028_any ::= _Gen028 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen028]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen028_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen028_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen028_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen028_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_EntityValue_001] EntityValue ::= _Lex006 _Gen024_any _Lex006  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex006],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen024_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex006]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_EntityValue_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EntityValue];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EntityValue_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EntityValue_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_EntityValue_002] EntityValue ::= _Lex008 _Gen028_any _Lex008  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex008],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen028_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex008]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_EntityValue_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EntityValue];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EntityValue_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EntityValue_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen034_001] _Gen034 ::= _Lex010  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex010]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen034_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen034];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen034_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen034_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen034_002] _Gen034 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen034_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen034];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen034_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen034_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen034_any_001] _Gen034_any ::= _Gen034 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen034]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen034_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen034_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen034_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen034_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen037_001] _Gen037 ::= _Lex011  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex011]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen037_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen037];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen037_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen037_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen037_002] _Gen037 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen037_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen037];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen037_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen037_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen037_any_001] _Gen037_any ::= _Gen037 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen037]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen037_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen037_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen037_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen037_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_AttValue_001] AttValue ::= _Lex006 _Gen034_any _Lex006  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex006],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen034_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex006]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_AttValue_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_AttValue];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_AttValue_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_AttValue_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_AttValue_002] AttValue ::= _Lex008 _Gen037_any _Lex008  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex008],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen037_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex008]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_AttValue_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_AttValue];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_AttValue_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_AttValue_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Lex012_any_001] _Lex012_any ::= _Lex012 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex012]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Lex012_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex012_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Lex012_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Lex012_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen043_001] _Gen043 ::= _Lex006 _Lex012_any _Lex006  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex006],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex012_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex006]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen043_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen043];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen043_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen043_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Lex013_any_001] _Lex013_any ::= _Lex013 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex013]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Lex013_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex013_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Lex013_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Lex013_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen045_001] _Gen045 ::= _Lex008 _Lex013_any _Lex008  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex008],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex013_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex008]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen045_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen045];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen045_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen045_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_SystemLiteral_001] SystemLiteral ::= _Gen043  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen043]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_SystemLiteral_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_SystemLiteral];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_SystemLiteral_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_SystemLiteral_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_SystemLiteral_002] SystemLiteral ::= _Gen045  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen045]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_SystemLiteral_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_SystemLiteral];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_SystemLiteral_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_SystemLiteral_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_PubidChar_any_001] PubidChar_any ::= PubidChar * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PubidChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_PubidChar_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PubidChar_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PubidChar_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PubidChar_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen049_001] _Gen049 ::= _Exclusion001  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Exclusion001]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen049_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen049];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen049_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen049_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen050_001] _Gen050 ::= _Gen049  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen049]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen050_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen050];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen050_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen050_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen050_any_001] _Gen050_any ::= _Gen050 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen050]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen050_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen050_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen050_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen050_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_PubidLiteral_001] PubidLiteral ::= _Lex006 PubidChar_any _Lex006  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex006],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PubidChar_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex006]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_PubidLiteral_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PubidLiteral];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PubidLiteral_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PubidLiteral_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_PubidLiteral_002] PubidLiteral ::= _Lex008 _Gen050_any _Lex008  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex008],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen050_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex008]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_PubidLiteral_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PubidLiteral];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PubidLiteral_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PubidLiteral_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Lex015_any_001] _Lex015_any ::= _Lex015 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex015]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Lex015_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex015_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Lex015_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Lex015_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen056_001] _Gen056 ::= _Lex015_any _Lex016 _Lex015_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex015_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex016],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex015_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen056_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen056];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen056_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen056_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen057_001] _Gen057 ::= _Exclusion002  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Exclusion002]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen057_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen057];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen057_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen057_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_CharData_001] CharData ::= _Gen057  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen057]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_CharData_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_CharData];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_CharData_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_CharData_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Char_any_001] Char_any ::= Char * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Char]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_Char_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Char_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Char_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Char_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Comment_001] Comment ::= _Lex017 Char_any _Lex018  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex017],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Char_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex018]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_Comment_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Comment];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Comment_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Comment_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen061_001] _Gen061 ::= Char_any _Lex020 Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Char_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex020],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen061_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen061];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen061_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen061_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen062_001] _Gen062 ::= _Exclusion003  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Exclusion003]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen062_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen062];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen062_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen062_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen063_001] _Gen063 ::= _Gen062  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen062]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen063_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen063];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen063_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen063_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen064_001] _Gen064 ::= S _Gen063  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen063]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen064_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen064];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen064_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen064_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen064_maybe_001] _Gen064_maybe ::= _Gen064  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen064]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen064_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen064_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen064_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen064_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen064_maybe_002] _Gen064_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen064_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen064_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen064_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen064_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_PI_001] PI ::= _Lex019 PITarget _Gen064_maybe _Lex020  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex019],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PITarget],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen064_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex020]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_PI_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PI];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PI_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PI_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen068_001] _Gen068 ::= _Lex021  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex021]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen068_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen068];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen068_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen068_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen068_002] _Gen068 ::= _Lex022  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex022]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen068_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen068];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen068_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen068_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen070_001] _Gen070 ::= _Lex023  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex023]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen070_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen070];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen070_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen070_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen070_002] _Gen070 ::= _Lex024  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex024]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen070_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen070];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen070_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen070_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen072_001] _Gen072 ::= _Lex025  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex025]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen072_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen072];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen072_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen072_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen072_002] _Gen072 ::= _Lex026  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex026]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen072_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen072];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen072_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen072_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen074_001] _Gen074 ::= _Gen068 _Gen070 _Gen072  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen068],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen070],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen072]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen074_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen074];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen074_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen074_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen075_001] _Gen075 ::= _Exclusion004  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Exclusion004]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen075_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen075];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen075_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen075_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_PITarget_001] PITarget ::= _Gen075  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen075]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_PITarget_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PITarget];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PITarget_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PITarget_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_CDSect_001] CDSect ::= CDStart CData CDEnd  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_CDStart],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_CData],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_CDEnd]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_CDSect_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_CDSect];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_CDSect_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_CDSect_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen079_001] _Gen079 ::= Char_any _Lex016 Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Char_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex016],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen079_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen079];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen079_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen079_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen080_001] _Gen080 ::= _Exclusion005  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Exclusion005]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen080_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen080];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen080_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen080_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen081_001] _Gen081 ::= _Gen080  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen080]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen081_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen081];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen081_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen081_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_CData_001] CData ::= _Gen081  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen081]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_CData_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_CData];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_CData_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_CData_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_CDEnd_001] CDEnd ::= _Lex016  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex016]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_CDEnd_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_CDEnd];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_CDEnd_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_CDEnd_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_XMLDecl_maybe_001] XMLDecl_maybe ::= XMLDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_XMLDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_XMLDecl_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_XMLDecl_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_XMLDecl_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_XMLDecl_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_XMLDecl_maybe_002] XMLDecl_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_XMLDecl_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_XMLDecl_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_XMLDecl_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_XMLDecl_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen086_001] _Gen086 ::= doctypedecl Misc_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_doctypedecl],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Misc_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen086_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen086];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen086_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen086_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen086_maybe_001] _Gen086_maybe ::= _Gen086  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen086]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen086_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen086_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen086_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen086_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen086_maybe_002] _Gen086_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen086_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen086_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen086_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen086_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_prolog_001] prolog ::= XMLDecl_maybe Misc_any _Gen086_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_XMLDecl_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Misc_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen086_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_prolog_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_prolog];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_prolog_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_prolog_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_EncodingDecl_maybe_001] EncodingDecl_maybe ::= EncodingDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EncodingDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_EncodingDecl_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EncodingDecl_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EncodingDecl_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EncodingDecl_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_EncodingDecl_maybe_002] EncodingDecl_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_EncodingDecl_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EncodingDecl_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EncodingDecl_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EncodingDecl_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_SDDecl_maybe_001] SDDecl_maybe ::= SDDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_SDDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_SDDecl_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_SDDecl_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_SDDecl_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_SDDecl_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_SDDecl_maybe_002] SDDecl_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_SDDecl_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_SDDecl_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_SDDecl_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_SDDecl_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_S_maybe_001] S_maybe ::= S  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_S_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_S_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_S_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_S_maybe_002] S_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_S_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_S_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_S_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_XMLDecl_001] XMLDecl ::= _Lex028 VersionInfo EncodingDecl_maybe SDDecl_maybe S_maybe _Lex020  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex028],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_VersionInfo],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EncodingDecl_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_SDDecl_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex020]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_XMLDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_XMLDecl];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_XMLDecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_XMLDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen097_001] _Gen097 ::= _Lex008 VersionNum _Lex008  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex008],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_VersionNum],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex008]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen097_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen097];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen097_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen097_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen097_002] _Gen097 ::= _Lex006 VersionNum _Lex006  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex006],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_VersionNum],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex006]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen097_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen097];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen097_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen097_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_VersionInfo_001] VersionInfo ::= S _Lex029 Eq _Gen097  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex029],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Eq],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen097]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_VersionInfo_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_VersionInfo];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_VersionInfo_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_VersionInfo_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Eq_001] Eq ::= S_maybe _Lex030 S_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex030],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_Eq_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Eq];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Eq_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Eq_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Lex032_many_001] _Lex032_many ::= _Lex032 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex032]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Lex032_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex032_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 1;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Lex032_many_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Lex032_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_VersionNum_001] VersionNum ::= _Lex031 _Lex032_many  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex031],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex032_many]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_VersionNum_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_VersionNum];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_VersionNum_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_VersionNum_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Misc_001] Misc ::= Comment  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Comment]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_Misc_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Misc];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Misc_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Misc_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Misc_002] Misc ::= PI  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PI]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_Misc_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Misc];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Misc_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Misc_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Misc_003] Misc ::= S  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_Misc_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Misc];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Misc_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Misc_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen106_001] _Gen106 ::= S ExternalID  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_ExternalID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen106_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen106];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen106_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen106_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen106_maybe_001] _Gen106_maybe ::= _Gen106  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen106]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen106_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen106_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen106_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen106_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen106_maybe_002] _Gen106_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen106_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen106_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen106_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen106_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen109_001] _Gen109 ::= _Lex034 intSubset _Lex035 S_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex034],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_intSubset],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex035],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen109_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen109];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen109_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen109_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen109_maybe_001] _Gen109_maybe ::= _Gen109  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen109]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen109_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen109_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen109_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen109_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen109_maybe_002] _Gen109_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen109_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen109_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen109_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen109_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_doctypedecl_001] doctypedecl ::= _Lex033 S Name _Gen106_maybe S_maybe _Gen109_maybe _Lex036  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex033],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen106_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen109_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex036]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_doctypedecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_doctypedecl];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_doctypedecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_doctypedecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_DeclSep_001] DeclSep ::= PEReference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PEReference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_DeclSep_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_DeclSep];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_DeclSep_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_DeclSep_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_DeclSep_002] DeclSep ::= S  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_DeclSep_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_DeclSep];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_DeclSep_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_DeclSep_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen115_001] _Gen115 ::= markupdecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_markupdecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen115_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen115];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen115_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen115_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen115_002] _Gen115 ::= DeclSep  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_DeclSep]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen115_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen115];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen115_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen115_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen115_any_001] _Gen115_any ::= _Gen115 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen115]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen115_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen115_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen115_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen115_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_intSubset_001] intSubset ::= _Gen115_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen115_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_intSubset_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_intSubset];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_intSubset_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_intSubset_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_markupdecl_001] markupdecl ::= elementdecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_elementdecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_markupdecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_markupdecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_markupdecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_markupdecl_002] markupdecl ::= AttlistDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_AttlistDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_markupdecl_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_markupdecl_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_markupdecl_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_markupdecl_003] markupdecl ::= EntityDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EntityDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_markupdecl_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_markupdecl_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_markupdecl_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_markupdecl_004] markupdecl ::= NotationDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NotationDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_markupdecl_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_markupdecl_004] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_markupdecl_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_markupdecl_005] markupdecl ::= PI  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PI]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_markupdecl_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_markupdecl_005] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_markupdecl_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_markupdecl_006] markupdecl ::= Comment  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Comment]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_markupdecl_006;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_markupdecl_006] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_markupdecl_006] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_TextDecl_maybe_001] TextDecl_maybe ::= TextDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_TextDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_TextDecl_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_TextDecl_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_TextDecl_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_TextDecl_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_TextDecl_maybe_002] TextDecl_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_TextDecl_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_TextDecl_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_TextDecl_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_TextDecl_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_extSubset_001] extSubset ::= TextDecl_maybe extSubsetDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_TextDecl_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_extSubsetDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_extSubset_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_extSubset];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_extSubset_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_extSubset_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen128_001] _Gen128 ::= markupdecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_markupdecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen128_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen128];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen128_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen128_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen128_002] _Gen128 ::= conditionalSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_conditionalSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen128_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen128];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen128_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen128_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen128_003] _Gen128 ::= DeclSep  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_DeclSep]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen128_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen128];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen128_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen128_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen128_any_001] _Gen128_any ::= _Gen128 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen128]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen128_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen128_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen128_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen128_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_extSubsetDecl_001] extSubsetDecl ::= _Gen128_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen128_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_extSubsetDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_extSubsetDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_extSubsetDecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_extSubsetDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen133_001] _Gen133 ::= _Lex038  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex038]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen133_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen133];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen133_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen133_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen133_002] _Gen133 ::= _Lex039  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex039]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen133_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen133];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen133_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen133_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen135_001] _Gen135 ::= _Lex008 _Gen133 _Lex008  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex008],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen133],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex008]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen135_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen135];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen135_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen135_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen136_001] _Gen136 ::= _Lex038  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex038]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen136_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen136];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen136_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen136_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen136_002] _Gen136 ::= _Lex039  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex039]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen136_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen136];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen136_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen136_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen138_001] _Gen138 ::= _Lex006 _Gen136 _Lex006  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex006],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen136],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex006]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen138_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen138];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen138_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen138_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen139_001] _Gen139 ::= _Gen135  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen135]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen139_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen139];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen139_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen139_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen139_002] _Gen139 ::= _Gen138  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen138]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen139_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen139];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen139_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen139_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_SDDecl_001] SDDecl ::= S _Lex037 Eq _Gen139  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex037],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Eq],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen139]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_SDDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_SDDecl];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_SDDecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_SDDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_element_001] element ::= EmptyElemTag  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EmptyElemTag]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_element_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_element];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_element_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_element_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_element_002] element ::= STag content ETag  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_STag],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_content],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_ETag]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_element_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_element];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_element_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_element_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen144_001] _Gen144 ::= S Attribute  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Attribute]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen144_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen144];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen144_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen144_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen144_any_001] _Gen144_any ::= _Gen144 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen144]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen144_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen144_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen144_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen144_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_STag_001] STag ::= _Lex040 Name _Gen144_any S_maybe _Lex036  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex040],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen144_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex036]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_STag_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_STag];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_STag_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_STag_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Attribute_001] Attribute ::= Name Eq AttValue  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Eq],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_AttValue]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_Attribute_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Attribute];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Attribute_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Attribute_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_ETag_001] ETag ::= _Lex041 Name S_maybe _Lex036  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex041],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex036]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_ETag_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_ETag];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_ETag_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_ETag_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_CharData_maybe_001] CharData_maybe ::= CharData  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_CharData]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_CharData_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_CharData_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_CharData_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_CharData_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_CharData_maybe_002] CharData_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_CharData_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_CharData_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_CharData_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_CharData_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen151_001] _Gen151 ::= element  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_element]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen151_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen151];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen151_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen151_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen151_002] _Gen151 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen151_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen151];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen151_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen151_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen151_003] _Gen151 ::= CDSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_CDSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen151_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen151];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen151_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen151_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen151_004] _Gen151 ::= PI  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PI]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen151_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen151];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen151_004] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen151_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen151_005] _Gen151 ::= Comment  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Comment]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen151_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen151];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen151_005] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen151_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen156_001] _Gen156 ::= _Gen151 CharData_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen151],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_CharData_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen156_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen156];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen156_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen156_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen156_any_001] _Gen156_any ::= _Gen156 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen156]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen156_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen156_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen156_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen156_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_content_001] content ::= CharData_maybe _Gen156_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_CharData_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen156_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_content_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_content];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_content_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_content_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen159_001] _Gen159 ::= S Attribute  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Attribute]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen159_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen159];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen159_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen159_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen159_any_001] _Gen159_any ::= _Gen159 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen159]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen159_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen159_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen159_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen159_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_EmptyElemTag_001] EmptyElemTag ::= _Lex040 Name _Gen159_any S_maybe _Lex042  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex040],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen159_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex042]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_EmptyElemTag_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EmptyElemTag];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EmptyElemTag_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EmptyElemTag_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_elementdecl_001] elementdecl ::= _Lex043 S Name S contentspec S_maybe _Lex036  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex043],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_contentspec],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex036]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_elementdecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_elementdecl];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_elementdecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_elementdecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_contentspec_001] contentspec ::= _Lex044  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex044]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_contentspec_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_contentspec];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_contentspec_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_contentspec_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_contentspec_002] contentspec ::= _Lex045  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex045]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_contentspec_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_contentspec];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_contentspec_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_contentspec_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_contentspec_003] contentspec ::= Mixed  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Mixed]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_contentspec_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_contentspec];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_contentspec_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_contentspec_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_contentspec_004] contentspec ::= children  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_children]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_contentspec_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_contentspec];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_contentspec_004] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_contentspec_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen167_001] _Gen167 ::= choice  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_choice]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen167_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen167];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen167_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen167_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen167_002] _Gen167 ::= seq  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_seq]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen167_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen167];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen167_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen167_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen169_001] _Gen169 ::= _Lex046  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex046]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen169_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen169];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen169_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen169_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen169_002] _Gen169 ::= _Lex047  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex047]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen169_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen169];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen169_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen169_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen169_003] _Gen169 ::= _Lex048  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex048]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen169_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen169];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen169_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen169_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen169_maybe_001] _Gen169_maybe ::= _Gen169  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen169]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen169_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen169_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen169_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen169_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen169_maybe_002] _Gen169_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen169_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen169_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen169_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen169_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_children_001] children ::= _Gen167 _Gen169_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen167],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen169_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_children_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_children];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_children_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_children_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen175_001] _Gen175 ::= Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen175_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen175];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen175_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen175_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen175_002] _Gen175 ::= choice  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_choice]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen175_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen175];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen175_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen175_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen175_003] _Gen175 ::= seq  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_seq]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen175_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen175];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen175_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen175_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen178_001] _Gen178 ::= _Lex046  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex046]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen178_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen178];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen178_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen178_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen178_002] _Gen178 ::= _Lex047  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex047]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen178_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen178];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen178_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen178_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen178_003] _Gen178 ::= _Lex048  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex048]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen178_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen178];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen178_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen178_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen178_maybe_001] _Gen178_maybe ::= _Gen178  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen178]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen178_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen178_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen178_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen178_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen178_maybe_002] _Gen178_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen178_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen178_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen178_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen178_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_cp_001] cp ::= _Gen175 _Gen178_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen175],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen178_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_cp_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_cp];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_cp_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_cp_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen184_001] _Gen184 ::= S_maybe _Lex050 S_maybe cp  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex050],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_cp]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen184_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen184];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen184_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen184_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen184_many_001] _Gen184_many ::= _Gen184 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen184]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen184_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen184_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 1;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen184_many_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen184_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_choice_001] choice ::= _Lex049 S_maybe cp _Gen184_many S_maybe _Lex051  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex049],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_cp],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen184_many],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex051]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_choice_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_choice];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_choice_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_choice_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen187_001] _Gen187 ::= S_maybe _Lex052 S_maybe cp  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex052],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_cp]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen187_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen187];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen187_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen187_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen187_any_001] _Gen187_any ::= _Gen187 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen187]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen187_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen187_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen187_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen187_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_seq_001] seq ::= _Lex049 S_maybe cp _Gen187_any S_maybe _Lex051  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex049],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_cp],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen187_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex051]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_seq_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_seq];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_seq_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_seq_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen190_001] _Gen190 ::= S_maybe _Lex050 S_maybe Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex050],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen190_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen190];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen190_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen190_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen190_any_001] _Gen190_any ::= _Gen190 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen190]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen190_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen190_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen190_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen190_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Mixed_001] Mixed ::= _Lex049 S_maybe _Lex053 _Gen190_any S_maybe _Lex054  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex049],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex053],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen190_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex054]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_Mixed_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Mixed];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Mixed_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Mixed_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Mixed_002] Mixed ::= _Lex049 S_maybe _Lex053 S_maybe _Lex051  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex049],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex053],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex051]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_Mixed_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Mixed];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Mixed_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Mixed_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_AttDef_any_001] AttDef_any ::= AttDef * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_AttDef]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_AttDef_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_AttDef_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_AttDef_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_AttDef_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_AttlistDecl_001] AttlistDecl ::= _Lex055 S Name AttDef_any S_maybe _Lex036  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex055],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_AttDef_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex036]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_AttlistDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_AttlistDecl];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_AttlistDecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_AttlistDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_AttDef_001] AttDef ::= S Name S AttType S DefaultDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_AttType],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_DefaultDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_AttDef_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_AttDef];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_AttDef_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_AttDef_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_AttType_001] AttType ::= StringType  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_StringType]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_AttType_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_AttType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_AttType_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_AttType_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_AttType_002] AttType ::= TokenizedType  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_TokenizedType]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_AttType_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_AttType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_AttType_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_AttType_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_AttType_003] AttType ::= EnumeratedType  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EnumeratedType]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_AttType_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_AttType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_AttType_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_AttType_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_TokenizedType_001] TokenizedType ::= _Lex057  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex057]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_TokenizedType_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_TokenizedType_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_TokenizedType_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_TokenizedType_002] TokenizedType ::= _Lex058  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex058]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_TokenizedType_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_TokenizedType_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_TokenizedType_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_TokenizedType_003] TokenizedType ::= _Lex059  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex059]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_TokenizedType_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_TokenizedType_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_TokenizedType_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_TokenizedType_004] TokenizedType ::= _Lex060  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex060]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_TokenizedType_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_TokenizedType_004] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_TokenizedType_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_TokenizedType_005] TokenizedType ::= _Lex061  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex061]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_TokenizedType_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_TokenizedType_005] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_TokenizedType_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_TokenizedType_006] TokenizedType ::= _Lex062  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex062]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_TokenizedType_006;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_TokenizedType_006] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_TokenizedType_006] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_TokenizedType_007] TokenizedType ::= _Lex063  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex063]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_TokenizedType_007;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_TokenizedType_007] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_TokenizedType_007] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_EnumeratedType_001] EnumeratedType ::= NotationType  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NotationType]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_EnumeratedType_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EnumeratedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EnumeratedType_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EnumeratedType_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_EnumeratedType_002] EnumeratedType ::= Enumeration  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Enumeration]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_EnumeratedType_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EnumeratedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EnumeratedType_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EnumeratedType_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen210_001] _Gen210 ::= S_maybe _Lex050 S_maybe Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex050],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen210_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen210];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen210_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen210_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen210_any_001] _Gen210_any ::= _Gen210 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen210]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen210_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen210_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen210_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen210_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NotationType_001] NotationType ::= _Lex064 S _Lex049 S_maybe Name _Gen210_any S_maybe _Lex051  */
    marpaWrapperSymbol_t *rhsSymbolpp[8] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex064],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex049],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen210_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex051]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NotationType_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NotationType];
    marpaWrapperRuleOption.nRhsSymboli = 8;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NotationType_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NotationType_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen213_001] _Gen213 ::= S_maybe _Lex050 S_maybe Nmtoken  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex050],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Nmtoken]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen213_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen213];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen213_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen213_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen213_any_001] _Gen213_any ::= _Gen213 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen213]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen213_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen213_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen213_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen213_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Enumeration_001] Enumeration ::= _Lex049 S_maybe Nmtoken _Gen213_any S_maybe _Lex051  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex049],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Nmtoken],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen213_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex051]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_Enumeration_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Enumeration];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Enumeration_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Enumeration_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen216_001] _Gen216 ::= _Lex067 S  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex067],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen216_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen216];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen216_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen216_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen216_maybe_001] _Gen216_maybe ::= _Gen216  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen216]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen216_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen216_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen216_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen216_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen216_maybe_002] _Gen216_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen216_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen216_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen216_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen216_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen219_001] _Gen219 ::= _Gen216_maybe AttValue  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen216_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_AttValue]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen219_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen219];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen219_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen219_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_DefaultDecl_001] DefaultDecl ::= _Lex065  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex065]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_DefaultDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_DefaultDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_DefaultDecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_DefaultDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_DefaultDecl_002] DefaultDecl ::= _Lex066  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex066]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_DefaultDecl_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_DefaultDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_DefaultDecl_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_DefaultDecl_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_DefaultDecl_003] DefaultDecl ::= _Gen219  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen219]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_DefaultDecl_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_DefaultDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_DefaultDecl_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_DefaultDecl_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_conditionalSect_001] conditionalSect ::= includeSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_includeSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_conditionalSect_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_conditionalSect];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_conditionalSect_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_conditionalSect_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_conditionalSect_002] conditionalSect ::= ignoreSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_ignoreSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_conditionalSect_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_conditionalSect];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_conditionalSect_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_conditionalSect_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_includeSect_001] includeSect ::= _Lex068 S_maybe _Lex069 S_maybe _Lex034 extSubsetDecl _Lex016  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex068],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex069],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex034],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_extSubsetDecl],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex016]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_includeSect_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_includeSect];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_includeSect_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_includeSect_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_ignoreSectContents_any_001] ignoreSectContents_any ::= ignoreSectContents * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_ignoreSectContents]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_ignoreSectContents_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_ignoreSectContents_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_ignoreSectContents_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_ignoreSectContents_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_ignoreSect_001] ignoreSect ::= _Lex068 S_maybe _Lex070 S_maybe _Lex034 ignoreSectContents_any _Lex016  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex068],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex070],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex034],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_ignoreSectContents_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex016]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_ignoreSect_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_ignoreSect];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_ignoreSect_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_ignoreSect_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen228_001] _Gen228 ::= _Lex068 ignoreSectContents _Lex016 Ignore  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex068],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_ignoreSectContents],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex016],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Ignore]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen228_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen228];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen228_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen228_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen228_any_001] _Gen228_any ::= _Gen228 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen228]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen228_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen228_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen228_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen228_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_ignoreSectContents_001] ignoreSectContents ::= Ignore _Gen228_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Ignore],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen228_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_ignoreSectContents_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_ignoreSectContents];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_ignoreSectContents_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_ignoreSectContents_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen231_001] _Gen231 ::= _Lex068  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex068]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen231_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen231];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen231_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen231_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen231_002] _Gen231 ::= _Lex016  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex016]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen231_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen231];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen231_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen231_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen233_001] _Gen233 ::= Char_any _Gen231 Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Char_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen231],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen233_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen233];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen233_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen233_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen234_001] _Gen234 ::= _Exclusion006  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Exclusion006]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen234_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen234];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen234_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen234_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Ignore_001] Ignore ::= _Gen234  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen234]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_Ignore_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Ignore];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Ignore_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Ignore_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Lex074_many_001] _Lex074_many ::= _Lex074 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex074]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Lex074_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex074_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 1;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Lex074_many_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Lex074_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_CharRef_001] CharRef ::= _Lex071 _Lex032_many _Lex072  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex071],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex032_many],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex072]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_CharRef_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_CharRef];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_CharRef_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_CharRef_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_CharRef_002] CharRef ::= _Lex073 _Lex074_many _Lex072  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex073],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex074_many],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex072]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_CharRef_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_CharRef];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_CharRef_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_CharRef_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Reference_001] Reference ::= EntityRef  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EntityRef]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_Reference_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Reference];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Reference_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Reference_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Reference_002] Reference ::= CharRef  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_CharRef]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_Reference_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Reference];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Reference_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Reference_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_EntityRef_001] EntityRef ::= _Lex075 Name _Lex072  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex075],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex072]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_EntityRef_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EntityRef];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EntityRef_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EntityRef_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_PEReference_001] PEReference ::= _Lex076 Name _Lex072  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex076],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex072]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_PEReference_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PEReference];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PEReference_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PEReference_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_EntityDecl_001] EntityDecl ::= GEDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_GEDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_EntityDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EntityDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EntityDecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EntityDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_EntityDecl_002] EntityDecl ::= PEDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PEDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_EntityDecl_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EntityDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EntityDecl_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EntityDecl_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_GEDecl_001] GEDecl ::= _Lex077 S Name S EntityDef S_maybe _Lex036  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex077],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EntityDef],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex036]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_GEDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_GEDecl];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_GEDecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_GEDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_PEDecl_001] PEDecl ::= _Lex077 S _Lex076 S Name S PEDef S_maybe _Lex036  */
    marpaWrapperSymbol_t *rhsSymbolpp[9] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex077],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex076],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PEDef],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex036]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_PEDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PEDecl];
    marpaWrapperRuleOption.nRhsSymboli = 9;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PEDecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PEDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NDataDecl_maybe_001] NDataDecl_maybe ::= NDataDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NDataDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NDataDecl_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NDataDecl_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NDataDecl_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NDataDecl_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NDataDecl_maybe_002] NDataDecl_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NDataDecl_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NDataDecl_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NDataDecl_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NDataDecl_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen249_001] _Gen249 ::= ExternalID NDataDecl_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_ExternalID],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NDataDecl_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen249_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen249];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen249_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen249_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_EntityDef_001] EntityDef ::= EntityValue  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EntityValue]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_EntityDef_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EntityDef];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EntityDef_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EntityDef_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_EntityDef_002] EntityDef ::= _Gen249  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen249]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_EntityDef_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EntityDef];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EntityDef_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EntityDef_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_PEDef_001] PEDef ::= EntityValue  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EntityValue]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_PEDef_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PEDef];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PEDef_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PEDef_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_PEDef_002] PEDef ::= ExternalID  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_ExternalID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_PEDef_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PEDef];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PEDef_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PEDef_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_ExternalID_001] ExternalID ::= _Lex078 S SystemLiteral  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex078],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_SystemLiteral]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_ExternalID_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_ExternalID];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_ExternalID_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_ExternalID_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_ExternalID_002] ExternalID ::= _Lex079 S PubidLiteral S SystemLiteral  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex079],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PubidLiteral],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_SystemLiteral]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_ExternalID_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_ExternalID];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_ExternalID_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_ExternalID_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NDataDecl_001] NDataDecl ::= S _Lex080 S Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex080],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NDataDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NDataDecl];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NDataDecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NDataDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_VersionInfo_maybe_001] VersionInfo_maybe ::= VersionInfo  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_VersionInfo]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_VersionInfo_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_VersionInfo_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_VersionInfo_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_VersionInfo_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_VersionInfo_maybe_002] VersionInfo_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_VersionInfo_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_VersionInfo_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_VersionInfo_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_VersionInfo_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_TextDecl_001] TextDecl ::= _Lex028 VersionInfo_maybe EncodingDecl S_maybe _Lex020  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex028],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_VersionInfo_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EncodingDecl],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex020]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_TextDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_TextDecl];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_TextDecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_TextDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_extParsedEnt_001] extParsedEnt ::= TextDecl_maybe content  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_TextDecl_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_content]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_extParsedEnt_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_extParsedEnt];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_extParsedEnt_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_extParsedEnt_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen261_001] _Gen261 ::= _Lex006 EncName _Lex006  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex006],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EncName],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex006]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen261_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen261];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen261_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen261_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen261_002] _Gen261 ::= _Lex008 EncName _Lex008  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex008],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EncName],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex008]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen261_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen261];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen261_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen261_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_EncodingDecl_001] EncodingDecl ::= S _Lex081 Eq _Gen261  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex081],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Eq],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen261]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_EncodingDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EncodingDecl];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EncodingDecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EncodingDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen264_001] _Gen264 ::= _Lex083  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex083]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen264_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen264];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen264_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen264_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen264_002] _Gen264 ::= _Lex084  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex084]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen264_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen264];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen264_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen264_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen264_any_001] _Gen264_any ::= _Gen264 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen264]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen264_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen264_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen264_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen264_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_EncName_001] EncName ::= _Lex082 _Gen264_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex082],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen264_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_EncName_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EncName];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EncName_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_EncName_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen268_001] _Gen268 ::= ExternalID  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_ExternalID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen268_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen268];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen268_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen268_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen268_002] _Gen268 ::= PublicID  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PublicID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen268_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen268];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen268_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen268_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NotationDecl_001] NotationDecl ::= _Lex085 S Name S _Gen268 S_maybe _Lex036  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex085],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen268],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex036]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NotationDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NotationDecl];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NotationDecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NotationDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_PublicID_001] PublicID ::= _Lex079 S PubidLiteral  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex079],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PubidLiteral]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_PublicID_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PublicID];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PublicID_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PublicID_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
    return MARPAWRAPPER_BOOL_TRUE;
}

/************************/
/* _xml_1_0_isLexemeb */
/************************/

static C_INLINE marpaWrapperBool_t _xml_1_0_isLexemeb(void *p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  marpaWrapperBool_t rcb;
  xml_1_0_callback_t *xml_1_0_callbackp = (xml_1_0_callback_t *) p;

  switch (xml_1_0_callbackp->xml_1_0_symboli) {
    case xml_1_0_CDStart:
      rcb = _xml_1_0_CDStartb(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0_Char:
      rcb = _xml_1_0_Charb(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0_NameStartChar:
      rcb = _xml_1_0_NameStartCharb(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0_PubidChar:
      rcb = _xml_1_0_PubidCharb(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0_StringType:
      rcb = _xml_1_0_StringTypeb(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Exclusion001:
      rcb = _xml_1_0__Exclusion001b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Exclusion002:
      rcb = _xml_1_0__Exclusion002b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Exclusion003:
      rcb = _xml_1_0__Exclusion003b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Exclusion004:
      rcb = _xml_1_0__Exclusion004b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Exclusion005:
      rcb = _xml_1_0__Exclusion005b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Exclusion006:
      rcb = _xml_1_0__Exclusion006b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex002:
      rcb = _xml_1_0__Lex002b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex004:
      rcb = _xml_1_0__Lex004b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex005:
      rcb = _xml_1_0__Lex005b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex006:
      rcb = _xml_1_0__Lex006b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex007:
      rcb = _xml_1_0__Lex007b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex008:
      rcb = _xml_1_0__Lex008b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex009:
      rcb = _xml_1_0__Lex009b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex010:
      rcb = _xml_1_0__Lex010b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex011:
      rcb = _xml_1_0__Lex011b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex012:
      rcb = _xml_1_0__Lex012b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex013:
      rcb = _xml_1_0__Lex013b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex015:
      rcb = _xml_1_0__Lex015b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex016:
      rcb = _xml_1_0__Lex016b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex017:
      rcb = _xml_1_0__Lex017b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex018:
      rcb = _xml_1_0__Lex018b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex019:
      rcb = _xml_1_0__Lex019b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex020:
      rcb = _xml_1_0__Lex020b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex021:
      rcb = _xml_1_0__Lex021b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex022:
      rcb = _xml_1_0__Lex022b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex023:
      rcb = _xml_1_0__Lex023b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex024:
      rcb = _xml_1_0__Lex024b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex025:
      rcb = _xml_1_0__Lex025b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex026:
      rcb = _xml_1_0__Lex026b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex028:
      rcb = _xml_1_0__Lex028b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex029:
      rcb = _xml_1_0__Lex029b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex030:
      rcb = _xml_1_0__Lex030b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex031:
      rcb = _xml_1_0__Lex031b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex032:
      rcb = _xml_1_0__Lex032b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex033:
      rcb = _xml_1_0__Lex033b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex034:
      rcb = _xml_1_0__Lex034b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex035:
      rcb = _xml_1_0__Lex035b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex036:
      rcb = _xml_1_0__Lex036b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex037:
      rcb = _xml_1_0__Lex037b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex038:
      rcb = _xml_1_0__Lex038b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex039:
      rcb = _xml_1_0__Lex039b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex040:
      rcb = _xml_1_0__Lex040b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex041:
      rcb = _xml_1_0__Lex041b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex042:
      rcb = _xml_1_0__Lex042b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex043:
      rcb = _xml_1_0__Lex043b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex044:
      rcb = _xml_1_0__Lex044b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex045:
      rcb = _xml_1_0__Lex045b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex046:
      rcb = _xml_1_0__Lex046b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex047:
      rcb = _xml_1_0__Lex047b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex048:
      rcb = _xml_1_0__Lex048b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex049:
      rcb = _xml_1_0__Lex049b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex050:
      rcb = _xml_1_0__Lex050b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex051:
      rcb = _xml_1_0__Lex051b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex052:
      rcb = _xml_1_0__Lex052b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex053:
      rcb = _xml_1_0__Lex053b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex054:
      rcb = _xml_1_0__Lex054b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex055:
      rcb = _xml_1_0__Lex055b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex057:
      rcb = _xml_1_0__Lex057b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex058:
      rcb = _xml_1_0__Lex058b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex059:
      rcb = _xml_1_0__Lex059b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex060:
      rcb = _xml_1_0__Lex060b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex061:
      rcb = _xml_1_0__Lex061b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex062:
      rcb = _xml_1_0__Lex062b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex063:
      rcb = _xml_1_0__Lex063b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex064:
      rcb = _xml_1_0__Lex064b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex065:
      rcb = _xml_1_0__Lex065b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex066:
      rcb = _xml_1_0__Lex066b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex067:
      rcb = _xml_1_0__Lex067b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex068:
      rcb = _xml_1_0__Lex068b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex069:
      rcb = _xml_1_0__Lex069b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex070:
      rcb = _xml_1_0__Lex070b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex071:
      rcb = _xml_1_0__Lex071b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex072:
      rcb = _xml_1_0__Lex072b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex073:
      rcb = _xml_1_0__Lex073b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex074:
      rcb = _xml_1_0__Lex074b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex075:
      rcb = _xml_1_0__Lex075b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex076:
      rcb = _xml_1_0__Lex076b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex077:
      rcb = _xml_1_0__Lex077b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex078:
      rcb = _xml_1_0__Lex078b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex079:
      rcb = _xml_1_0__Lex079b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex080:
      rcb = _xml_1_0__Lex080b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex081:
      rcb = _xml_1_0__Lex081b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex082:
      rcb = _xml_1_0__Lex082b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex083:
      rcb = _xml_1_0__Lex083b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex084:
      rcb = _xml_1_0__Lex084b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    case xml_1_0__Lex085:
      rcb = _xml_1_0__Lex085b(xml_1_0_callbackp->xml_1_0p, currenti, streamInp, sizelp);
      break;
    default:
      rcb = MARPAWRAPPER_BOOL_FALSE;
      break;
  }

  return rcb;
}
/************************************************
  CDStart ~ '<![CDATA['
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0_CDStartb(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[9] = {
    0x3c /* < */,
    0x21 /* ! */,
    0x5b /* [ */,
    0x43 /* C */,
    0x44 /* D */,
    0x41 /* A */,
    0x54 /* T */,
    0x41 /* A */,
    0x5b /* [ */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 9);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 9;
  }

  return rcb;
}
/************************************************
  Char ~ [\x{9}\x{a}\x{d}\x{20}-\x{d7ff}\x{e000}-\x{fffd}\x{10000}-\x{10ffff}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0_Charb(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if ((currenti == 0x9) /* #x9 */ ||
      (currenti == 0xa) /* #xa */ ||
      (currenti == 0xd) /* #xd */ ||
      (currenti >= 0x20 && currenti <= 0xd7ff) /* [#x20-#xd7ff] */ ||
      (currenti >= 0xe000 && currenti <= 0xfffd) /* [#xe000-#xfffd] */ ||
      (currenti >= 0x10000 && currenti <= 0x10ffff) /* [#x10000-#x10ffff] */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  NameStartChar ~ [:A-Z_a-z\x{c0}-\x{d6}\x{d8}-\x{f6}\x{f8}-\x{2ff}\x{370}-\x{37d}\x{37f}-\x{1fff}\x{200c}-\x{200d}\x{2070}-\x{218f}\x{2c00}-\x{2fef}\x{3001}-\x{d7ff}\x{f900}-\x{fdcf}\x{fdf0}-\x{fffd}\x{10000}-\x{effff}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0_NameStartCharb(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if ((currenti == 0x3a) /* : */ ||
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
      (currenti >= 0x10000 && currenti <= 0xeffff) /* [#x10000-#xeffff] */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  PubidChar ~ [a-zA-Z0-9-'()+,./:=?;!*#@$_%\x{20}\x{d}\x{a}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0_PubidCharb(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if ((currenti >= 0x61 && currenti <= 0x7a) /* [a-z] */ ||
      (currenti >= 0x41 && currenti <= 0x5a) /* [A-Z] */ ||
      (currenti >= 0x30 && currenti <= 0x39) /* [0-9] */ ||
      (currenti == 0x2d) /* - */ ||
      (currenti == 0x27) /* ' */ ||
      (currenti == 0x28) /* ( */ ||
      (currenti == 0x29) /* ) */ ||
      (currenti == 0x2b) /* + */ ||
      (currenti == 0x2c) /* , */ ||
      (currenti == 0x2e) /* . */ ||
      (currenti == 0x2f) /* / */ ||
      (currenti == 0x3a) /* : */ ||
      (currenti == 0x3d) /* = */ ||
      (currenti == 0x3f) /* ? */ ||
      (currenti == 0x3b) /* ; */ ||
      (currenti == 0x21) /* ! */ ||
      (currenti == 0x2a) /* * */ ||
      (currenti == 0x23) /* # */ ||
      (currenti == 0x40) /* @ */ ||
      (currenti == 0x24) /* $ */ ||
      (currenti == 0x5f) /* _ */ ||
      (currenti == 0x25) /* % */ ||
      (currenti == 0x20) /* #x20 */ ||
      (currenti == 0xd) /* #xd */ ||
      (currenti == 0xa) /* #xa */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  StringType ~ 'CDATA'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0_StringTypeb(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[5] = {
    0x43 /* C */,
    0x44 /* D */,
    0x41 /* A */,
    0x54 /* T */,
    0x41 /* A */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 5);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 5;
  }

  return rcb;
}
/************************************************
  _Exclusion001 ~ 'PubidChar - _Lex008'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion001b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Exclusion002 ~ '_Lex015_any - _Gen056'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion002b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Exclusion003 ~ 'Char_any - _Gen061'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion003b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Exclusion004 ~ 'Name - _Gen074'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion004b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Exclusion005 ~ 'Char_any - _Gen079'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion005b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Exclusion006 ~ 'Char_any - _Gen233'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion006b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Lex002 ~ [\x{20}\x{9}\x{d}\x{a}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex002b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if ((currenti == 0x20) /* #x20 */ ||
      (currenti == 0x9) /* #x9 */ ||
      (currenti == 0xd) /* #xd */ ||
      (currenti == 0xa) /* #xa */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex004 ~ [-.0-9\x{b7}\x{300}-\x{36f}\x{203f}-\x{2040}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex004b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if ((currenti == 0x2d) /* - */ ||
      (currenti == 0x2e) /* . */ ||
      (currenti >= 0x30 && currenti <= 0x39) /* [0-9] */ ||
      (currenti == 0xb7) /* #xb7 */ ||
      (currenti >= 0x300 && currenti <= 0x36f) /* [#x300-#x36f] */ ||
      (currenti >= 0x203f && currenti <= 0x2040) /* [#x203f-#x2040] */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex005 ~ [\x{20}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex005b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x20 /* #x20 */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex006 ~ '"'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex006b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x22 /* " */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex007 ~ [^%&"]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex007b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if ((currenti == 0x25) /* % */ ||
      (currenti == 0x26) /* & */ ||
      (currenti == 0x22) /* " */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_FALSE;
  } else {
    return MARPAWRAPPER_BOOL_TRUE;
  }
}
/************************************************
  _Lex008 ~ [']
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex008b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x27 /* ' */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex009 ~ [^%&']
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex009b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if ((currenti == 0x25) /* % */ ||
      (currenti == 0x26) /* & */ ||
      (currenti == 0x27) /* ' */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_FALSE;
  } else {
    return MARPAWRAPPER_BOOL_TRUE;
  }
}
/************************************************
  _Lex010 ~ [^<&"]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex010b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if ((currenti == 0x3c) /* < */ ||
      (currenti == 0x26) /* & */ ||
      (currenti == 0x22) /* " */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_FALSE;
  } else {
    return MARPAWRAPPER_BOOL_TRUE;
  }
}
/************************************************
  _Lex011 ~ [^<&']
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex011b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if ((currenti == 0x3c) /* < */ ||
      (currenti == 0x26) /* & */ ||
      (currenti == 0x27) /* ' */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_FALSE;
  } else {
    return MARPAWRAPPER_BOOL_TRUE;
  }
}
/************************************************
  _Lex012 ~ [^"]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex012b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x22 /* " */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_FALSE;
  } else {
    return MARPAWRAPPER_BOOL_TRUE;
  }
}
/************************************************
  _Lex013 ~ [^']
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex013b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x27 /* ' */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_FALSE;
  } else {
    return MARPAWRAPPER_BOOL_TRUE;
  }
}
/************************************************
  _Lex015 ~ [^<&]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex015b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if ((currenti == 0x3c) /* < */ ||
      (currenti == 0x26) /* & */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_FALSE;
  } else {
    return MARPAWRAPPER_BOOL_TRUE;
  }
}
/************************************************
  _Lex016 ~ ']]>'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex016b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[3] = {
    0x5d /* ] */,
    0x5d /* ] */,
    0x3e /* > */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 3);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 3;
  }

  return rcb;
}
/************************************************
  _Lex017 ~ '<!--'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex017b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[4] = {
    0x3c /* < */,
    0x21 /* ! */,
    0x2d /* - */,
    0x2d /* - */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 4);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 4;
  }

  return rcb;
}
/************************************************
  _Lex018 ~ '-->'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex018b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[3] = {
    0x2d /* - */,
    0x2d /* - */,
    0x3e /* > */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 3);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 3;
  }

  return rcb;
}
/************************************************
  _Lex019 ~ '<?'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex019b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[2] = {
    0x3c /* < */,
    0x3f /* ? */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 2);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 2;
  }

  return rcb;
}
/************************************************
  _Lex020 ~ '?>'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex020b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[2] = {
    0x3f /* ? */,
    0x3e /* > */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 2);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 2;
  }

  return rcb;
}
/************************************************
  _Lex021 ~ 'X'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex021b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x58 /* X */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex022 ~ 'x'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex022b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x78 /* x */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex023 ~ 'M'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex023b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x4d /* M */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex024 ~ 'm'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex024b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x6d /* m */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex025 ~ 'L'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex025b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x4c /* L */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex026 ~ 'l'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex026b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x6c /* l */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex028 ~ '<?xml'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex028b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[5] = {
    0x3c /* < */,
    0x3f /* ? */,
    0x78 /* x */,
    0x6d /* m */,
    0x6c /* l */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 5);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 5;
  }

  return rcb;
}
/************************************************
  _Lex029 ~ 'version'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex029b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[7] = {
    0x76 /* v */,
    0x65 /* e */,
    0x72 /* r */,
    0x73 /* s */,
    0x69 /* i */,
    0x6f /* o */,
    0x6e /* n */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 7);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 7;
  }

  return rcb;
}
/************************************************
  _Lex030 ~ '='
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex030b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x3d /* = */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex031 ~ '1.'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex031b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[2] = {
    0x31 /* 1 */,
    0x2e /* . */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 2);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 2;
  }

  return rcb;
}
/************************************************
  _Lex032 ~ [0-9]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex032b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti >= 0x30 && currenti <= 0x39 /* [0-9] */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex033 ~ '<!DOCTYPE'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex033b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[9] = {
    0x3c /* < */,
    0x21 /* ! */,
    0x44 /* D */,
    0x4f /* O */,
    0x43 /* C */,
    0x54 /* T */,
    0x59 /* Y */,
    0x50 /* P */,
    0x45 /* E */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 9);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 9;
  }

  return rcb;
}
/************************************************
  _Lex034 ~ '['
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex034b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x5b /* [ */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex035 ~ ']'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex035b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x5d /* ] */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex036 ~ '>'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex036b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x3e /* > */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex037 ~ 'standalone'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex037b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[10] = {
    0x73 /* s */,
    0x74 /* t */,
    0x61 /* a */,
    0x6e /* n */,
    0x64 /* d */,
    0x61 /* a */,
    0x6c /* l */,
    0x6f /* o */,
    0x6e /* n */,
    0x65 /* e */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 10);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 10;
  }

  return rcb;
}
/************************************************
  _Lex038 ~ 'yes'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex038b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[3] = {
    0x79 /* y */,
    0x65 /* e */,
    0x73 /* s */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 3);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 3;
  }

  return rcb;
}
/************************************************
  _Lex039 ~ 'no'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex039b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[2] = {
    0x6e /* n */,
    0x6f /* o */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 2);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 2;
  }

  return rcb;
}
/************************************************
  _Lex040 ~ '<'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex040b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x3c /* < */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex041 ~ '</'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex041b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[2] = {
    0x3c /* < */,
    0x2f /* / */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 2);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 2;
  }

  return rcb;
}
/************************************************
  _Lex042 ~ '/>'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex042b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[2] = {
    0x2f /* / */,
    0x3e /* > */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 2);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 2;
  }

  return rcb;
}
/************************************************
  _Lex043 ~ '<!ELEMENT'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex043b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[9] = {
    0x3c /* < */,
    0x21 /* ! */,
    0x45 /* E */,
    0x4c /* L */,
    0x45 /* E */,
    0x4d /* M */,
    0x45 /* E */,
    0x4e /* N */,
    0x54 /* T */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 9);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 9;
  }

  return rcb;
}
/************************************************
  _Lex044 ~ 'EMPTY'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex044b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[5] = {
    0x45 /* E */,
    0x4d /* M */,
    0x50 /* P */,
    0x54 /* T */,
    0x59 /* Y */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 5);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 5;
  }

  return rcb;
}
/************************************************
  _Lex045 ~ 'ANY'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex045b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[3] = {
    0x41 /* A */,
    0x4e /* N */,
    0x59 /* Y */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 3);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 3;
  }

  return rcb;
}
/************************************************
  _Lex046 ~ '?'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex046b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x3f /* ? */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex047 ~ '*'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex047b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x2a /* * */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex048 ~ '+'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex048b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x2b /* + */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex049 ~ '('
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex049b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x28 /* ( */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex050 ~ '|'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex050b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x7c /* | */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex051 ~ ')'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex051b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x29 /* ) */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex052 ~ ','
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex052b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x2c /* , */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex053 ~ '#PCDATA'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex053b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[7] = {
    0x23 /* # */,
    0x50 /* P */,
    0x43 /* C */,
    0x44 /* D */,
    0x41 /* A */,
    0x54 /* T */,
    0x41 /* A */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 7);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 7;
  }

  return rcb;
}
/************************************************
  _Lex054 ~ ')*'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex054b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[2] = {
    0x29 /* ) */,
    0x2a /* * */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 2);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 2;
  }

  return rcb;
}
/************************************************
  _Lex055 ~ '<!ATTLIST'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex055b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[9] = {
    0x3c /* < */,
    0x21 /* ! */,
    0x41 /* A */,
    0x54 /* T */,
    0x54 /* T */,
    0x4c /* L */,
    0x49 /* I */,
    0x53 /* S */,
    0x54 /* T */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 9);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 9;
  }

  return rcb;
}
/************************************************
  _Lex057 ~ 'ID'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex057b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[2] = {
    0x49 /* I */,
    0x44 /* D */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 2);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 2;
  }

  return rcb;
}
/************************************************
  _Lex058 ~ 'IDREF'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex058b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[5] = {
    0x49 /* I */,
    0x44 /* D */,
    0x52 /* R */,
    0x45 /* E */,
    0x46 /* F */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 5);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 5;
  }

  return rcb;
}
/************************************************
  _Lex059 ~ 'IDREFS'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex059b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[6] = {
    0x49 /* I */,
    0x44 /* D */,
    0x52 /* R */,
    0x45 /* E */,
    0x46 /* F */,
    0x53 /* S */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 6);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 6;
  }

  return rcb;
}
/************************************************
  _Lex060 ~ 'ENTITY'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex060b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[6] = {
    0x45 /* E */,
    0x4e /* N */,
    0x54 /* T */,
    0x49 /* I */,
    0x54 /* T */,
    0x59 /* Y */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 6);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 6;
  }

  return rcb;
}
/************************************************
  _Lex061 ~ 'ENTITIES'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex061b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[8] = {
    0x45 /* E */,
    0x4e /* N */,
    0x54 /* T */,
    0x49 /* I */,
    0x54 /* T */,
    0x49 /* I */,
    0x45 /* E */,
    0x53 /* S */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 8);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 8;
  }

  return rcb;
}
/************************************************
  _Lex062 ~ 'NMTOKEN'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex062b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[7] = {
    0x4e /* N */,
    0x4d /* M */,
    0x54 /* T */,
    0x4f /* O */,
    0x4b /* K */,
    0x45 /* E */,
    0x4e /* N */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 7);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 7;
  }

  return rcb;
}
/************************************************
  _Lex063 ~ 'NMTOKENS'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex063b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[8] = {
    0x4e /* N */,
    0x4d /* M */,
    0x54 /* T */,
    0x4f /* O */,
    0x4b /* K */,
    0x45 /* E */,
    0x4e /* N */,
    0x53 /* S */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 8);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 8;
  }

  return rcb;
}
/************************************************
  _Lex064 ~ 'NOTATION'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex064b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[8] = {
    0x4e /* N */,
    0x4f /* O */,
    0x54 /* T */,
    0x41 /* A */,
    0x54 /* T */,
    0x49 /* I */,
    0x4f /* O */,
    0x4e /* N */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 8);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 8;
  }

  return rcb;
}
/************************************************
  _Lex065 ~ '#REQUIRED'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex065b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[9] = {
    0x23 /* # */,
    0x52 /* R */,
    0x45 /* E */,
    0x51 /* Q */,
    0x55 /* U */,
    0x49 /* I */,
    0x52 /* R */,
    0x45 /* E */,
    0x44 /* D */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 9);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 9;
  }

  return rcb;
}
/************************************************
  _Lex066 ~ '#IMPLIED'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex066b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[8] = {
    0x23 /* # */,
    0x49 /* I */,
    0x4d /* M */,
    0x50 /* P */,
    0x4c /* L */,
    0x49 /* I */,
    0x45 /* E */,
    0x44 /* D */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 8);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 8;
  }

  return rcb;
}
/************************************************
  _Lex067 ~ '#FIXED'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex067b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[6] = {
    0x23 /* # */,
    0x46 /* F */,
    0x49 /* I */,
    0x58 /* X */,
    0x45 /* E */,
    0x44 /* D */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 6);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 6;
  }

  return rcb;
}
/************************************************
  _Lex068 ~ '<!['
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex068b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[3] = {
    0x3c /* < */,
    0x21 /* ! */,
    0x5b /* [ */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 3);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 3;
  }

  return rcb;
}
/************************************************
  _Lex069 ~ 'INCLUDE'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex069b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[7] = {
    0x49 /* I */,
    0x4e /* N */,
    0x43 /* C */,
    0x4c /* L */,
    0x55 /* U */,
    0x44 /* D */,
    0x45 /* E */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 7);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 7;
  }

  return rcb;
}
/************************************************
  _Lex070 ~ 'IGNORE'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex070b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[6] = {
    0x49 /* I */,
    0x47 /* G */,
    0x4e /* N */,
    0x4f /* O */,
    0x52 /* R */,
    0x45 /* E */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 6);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 6;
  }

  return rcb;
}
/************************************************
  _Lex071 ~ '&#'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex071b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[2] = {
    0x26 /* & */,
    0x23 /* # */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 2);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 2;
  }

  return rcb;
}
/************************************************
  _Lex072 ~ ';'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex072b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x3b /* ; */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex073 ~ '&#x'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex073b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[3] = {
    0x26 /* & */,
    0x23 /* # */,
    0x78 /* x */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 3);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 3;
  }

  return rcb;
}
/************************************************
  _Lex074 ~ [0-9a-fA-F]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex074b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if ((currenti >= 0x30 && currenti <= 0x39) /* [0-9] */ ||
      (currenti >= 0x61 && currenti <= 0x66) /* [a-f] */ ||
      (currenti >= 0x41 && currenti <= 0x46) /* [A-F] */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex075 ~ '&'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex075b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x26 /* & */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex076 ~ '%'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex076b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x25 /* % */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex077 ~ '<!ENTITY'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex077b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[8] = {
    0x3c /* < */,
    0x21 /* ! */,
    0x45 /* E */,
    0x4e /* N */,
    0x54 /* T */,
    0x49 /* I */,
    0x54 /* T */,
    0x59 /* Y */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 8);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 8;
  }

  return rcb;
}
/************************************************
  _Lex078 ~ 'SYSTEM'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex078b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[6] = {
    0x53 /* S */,
    0x59 /* Y */,
    0x53 /* S */,
    0x54 /* T */,
    0x45 /* E */,
    0x4d /* M */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 6);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 6;
  }

  return rcb;
}
/************************************************
  _Lex079 ~ 'PUBLIC'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex079b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[6] = {
    0x50 /* P */,
    0x55 /* U */,
    0x42 /* B */,
    0x4c /* L */,
    0x49 /* I */,
    0x43 /* C */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 6);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 6;
  }

  return rcb;
}
/************************************************
  _Lex080 ~ 'NDATA'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex080b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[5] = {
    0x4e /* N */,
    0x44 /* D */,
    0x41 /* A */,
    0x54 /* T */,
    0x41 /* A */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 5);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 5;
  }

  return rcb;
}
/************************************************
  _Lex081 ~ 'encoding'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex081b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[8] = {
    0x65 /* e */,
    0x6e /* n */,
    0x63 /* c */,
    0x6f /* o */,
    0x64 /* d */,
    0x69 /* i */,
    0x6e /* n */,
    0x67 /* g */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 8);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 8;
  }

  return rcb;
}
/************************************************
  _Lex082 ~ [A-Za-z]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex082b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if ((currenti >= 0x41 && currenti <= 0x5a) /* [A-Z] */ ||
      (currenti >= 0x61 && currenti <= 0x7a) /* [a-z] */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex083 ~ [A-Za-z0-9._]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex083b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if ((currenti >= 0x41 && currenti <= 0x5a) /* [A-Z] */ ||
      (currenti >= 0x61 && currenti <= 0x7a) /* [a-z] */ ||
      (currenti >= 0x30 && currenti <= 0x39) /* [0-9] */ ||
      (currenti == 0x2e) /* . */ ||
      (currenti == 0x5f) /* _ */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex084 ~ '-'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex084b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x2d /* - */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex085 ~ '<!NOTATION'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex085b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  static const signed int wanted[10] = {
    0x3c /* < */,
    0x21 /* ! */,
    0x4e /* N */,
    0x4f /* O */,
    0x54 /* T */,
    0x41 /* A */,
    0x54 /* T */,
    0x49 /* I */,
    0x4f /* O */,
    0x4e /* N */
  };
  signed int           got = currenti;
  int                  i = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_TRUE) {
    do {
      if (got != wanted[i]) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      got = streamInUtf8_nexti(streamInp);
    } while (++i < 10);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 10;
  }

  return rcb;
}
