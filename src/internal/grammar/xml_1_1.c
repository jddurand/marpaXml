/****************************/
/* This is a generated file */
/****************************/
#include <stdlib.h>
#include <errno.h>
#include "internal/streamIn.h"
#include "internal/grammar/xml_1_1.h"

/* Symbols */
typedef enum xml_1_1_symbol {
  /* Terminals */
  xml_1_1__Exclusion001 = 0     , /* _Exclusion001 ~ '_Gen002 - _Gen004' */
  xml_1_1__Exclusion002         , /* _Exclusion002 ~ 'PubidChar - _Lex037' */
  xml_1_1__Exclusion003         , /* _Exclusion003 ~ '_Lex045_any - _Gen092' */
  xml_1_1__Exclusion004         , /* _Exclusion004 ~ 'Char - _Lex029' */
  xml_1_1__Exclusion005         , /* _Exclusion005 ~ 'Char_any - _Gen104' */
  xml_1_1__Exclusion006         , /* _Exclusion006 ~ 'Name - _Gen117' */
  xml_1_1__Exclusion007         , /* _Exclusion007 ~ 'Char_any - _Gen122' */
  xml_1_1__Exclusion008         , /* _Exclusion008 ~ 'Char_any - _Gen273' */
  xml_1_1__Exclusion009         , /* _Exclusion009 ~ '_Gen301 - _Gen302' */
  xml_1_1__Lex001               , /* _Lex001 ~ [\x{1}-\x{d7ff}] */
  xml_1_1__Lex002               , /* _Lex002 ~ [\x{e000}-\x{fffd}] */
  xml_1_1__Lex003               , /* _Lex003 ~ [\x{10000}-\x{10ffff}] */
  xml_1_1__Lex004               , /* _Lex004 ~ [\x{1}-\x{8}] */
  xml_1_1__Lex005               , /* _Lex005 ~ [\x{b}-\x{c}] */
  xml_1_1__Lex006               , /* _Lex006 ~ [\x{e}-\x{1f}] */
  xml_1_1__Lex007               , /* _Lex007 ~ [\x{7f}-\x{84}] */
  xml_1_1__Lex008               , /* _Lex008 ~ [\x{86}-\x{9f}] */
  xml_1_1__Lex009               , /* _Lex009 ~ [\x{20}] */
  xml_1_1__Lex010               , /* _Lex010 ~ [\x{9}] */
  xml_1_1__Lex011               , /* _Lex011 ~ [\x{d}] */
  xml_1_1__Lex012               , /* _Lex012 ~ [\x{a}] */
  xml_1_1__Lex013               , /* _Lex013 ~ ':' */
  xml_1_1__Lex014               , /* _Lex014 ~ [A-Z] */
  xml_1_1__Lex015               , /* _Lex015 ~ '_' */
  xml_1_1__Lex016               , /* _Lex016 ~ [a-z] */
  xml_1_1__Lex017               , /* _Lex017 ~ [\x{c0}-\x{d6}] */
  xml_1_1__Lex018               , /* _Lex018 ~ [\x{d8}-\x{f6}] */
  xml_1_1__Lex019               , /* _Lex019 ~ [\x{f8}-\x{2ff}] */
  xml_1_1__Lex020               , /* _Lex020 ~ [\x{370}-\x{37d}] */
  xml_1_1__Lex021               , /* _Lex021 ~ [\x{37f}-\x{1fff}] */
  xml_1_1__Lex022               , /* _Lex022 ~ [\x{200c}-\x{200d}] */
  xml_1_1__Lex023               , /* _Lex023 ~ [\x{2070}-\x{218f}] */
  xml_1_1__Lex024               , /* _Lex024 ~ [\x{2c00}-\x{2fef}] */
  xml_1_1__Lex025               , /* _Lex025 ~ [\x{3001}-\x{d7ff}] */
  xml_1_1__Lex026               , /* _Lex026 ~ [\x{f900}-\x{fdcf}] */
  xml_1_1__Lex027               , /* _Lex027 ~ [\x{fdf0}-\x{fffd}] */
  xml_1_1__Lex028               , /* _Lex028 ~ [\x{10000}-\x{effff}] */
  xml_1_1__Lex029               , /* _Lex029 ~ '-' */
  xml_1_1__Lex030               , /* _Lex030 ~ '.' */
  xml_1_1__Lex031               , /* _Lex031 ~ [0-9] */
  xml_1_1__Lex032               , /* _Lex032 ~ [\x{b7}] */
  xml_1_1__Lex033               , /* _Lex033 ~ [\x{300}-\x{36f}] */
  xml_1_1__Lex034               , /* _Lex034 ~ [\x{203f}-\x{2040}] */
  xml_1_1__Lex035               , /* _Lex035 ~ '"' */
  xml_1_1__Lex036               , /* _Lex036 ~ [^%&"] */
  xml_1_1__Lex037               , /* _Lex037 ~ ['] */
  xml_1_1__Lex038               , /* _Lex038 ~ [^%&'] */
  xml_1_1__Lex039               , /* _Lex039 ~ [^<&"] */
  xml_1_1__Lex040               , /* _Lex040 ~ [^<&'] */
  xml_1_1__Lex041               , /* _Lex041 ~ [^"] */
  xml_1_1__Lex042               , /* _Lex042 ~ [^'] */
  xml_1_1__Lex043               , /* _Lex043 ~ [a-zA-Z0-9] */
  xml_1_1__Lex044               , /* _Lex044 ~ [-'()+,./:=?;!*#@$_%] */
  xml_1_1__Lex045               , /* _Lex045 ~ [^<&] */
  xml_1_1__Lex046               , /* _Lex046 ~ ']]>' */
  xml_1_1__Lex047               , /* _Lex047 ~ '<!--' */
  xml_1_1__Lex048               , /* _Lex048 ~ '-->' */
  xml_1_1__Lex049               , /* _Lex049 ~ '<?' */
  xml_1_1__Lex050               , /* _Lex050 ~ '?>' */
  xml_1_1__Lex051               , /* _Lex051 ~ 'X' */
  xml_1_1__Lex052               , /* _Lex052 ~ 'x' */
  xml_1_1__Lex053               , /* _Lex053 ~ 'M' */
  xml_1_1__Lex054               , /* _Lex054 ~ 'm' */
  xml_1_1__Lex055               , /* _Lex055 ~ 'L' */
  xml_1_1__Lex056               , /* _Lex056 ~ 'l' */
  xml_1_1__Lex057               , /* _Lex057 ~ '<![CDATA[' */
  xml_1_1__Lex058               , /* _Lex058 ~ '<?xml' */
  xml_1_1__Lex059               , /* _Lex059 ~ 'version' */
  xml_1_1__Lex060               , /* _Lex060 ~ '=' */
  xml_1_1__Lex061               , /* _Lex061 ~ '1.1' */
  xml_1_1__Lex062               , /* _Lex062 ~ '<!DOCTYPE' */
  xml_1_1__Lex063               , /* _Lex063 ~ '[' */
  xml_1_1__Lex064               , /* _Lex064 ~ ']' */
  xml_1_1__Lex065               , /* _Lex065 ~ '>' */
  xml_1_1__Lex066               , /* _Lex066 ~ 'standalone' */
  xml_1_1__Lex067               , /* _Lex067 ~ 'yes' */
  xml_1_1__Lex068               , /* _Lex068 ~ 'no' */
  xml_1_1__Lex069               , /* _Lex069 ~ '<' */
  xml_1_1__Lex070               , /* _Lex070 ~ '</' */
  xml_1_1__Lex071               , /* _Lex071 ~ '/>' */
  xml_1_1__Lex072               , /* _Lex072 ~ '<!ELEMENT' */
  xml_1_1__Lex073               , /* _Lex073 ~ 'EMPTY' */
  xml_1_1__Lex074               , /* _Lex074 ~ 'ANY' */
  xml_1_1__Lex075               , /* _Lex075 ~ '?' */
  xml_1_1__Lex076               , /* _Lex076 ~ '*' */
  xml_1_1__Lex077               , /* _Lex077 ~ '+' */
  xml_1_1__Lex078               , /* _Lex078 ~ '(' */
  xml_1_1__Lex079               , /* _Lex079 ~ '|' */
  xml_1_1__Lex080               , /* _Lex080 ~ ')' */
  xml_1_1__Lex081               , /* _Lex081 ~ ',' */
  xml_1_1__Lex082               , /* _Lex082 ~ '#PCDATA' */
  xml_1_1__Lex083               , /* _Lex083 ~ ')*' */
  xml_1_1__Lex084               , /* _Lex084 ~ '<!ATTLIST' */
  xml_1_1__Lex085               , /* _Lex085 ~ 'CDATA' */
  xml_1_1__Lex086               , /* _Lex086 ~ 'ID' */
  xml_1_1__Lex087               , /* _Lex087 ~ 'IDREF' */
  xml_1_1__Lex088               , /* _Lex088 ~ 'IDREFS' */
  xml_1_1__Lex089               , /* _Lex089 ~ 'ENTITY' */
  xml_1_1__Lex090               , /* _Lex090 ~ 'ENTITIES' */
  xml_1_1__Lex091               , /* _Lex091 ~ 'NMTOKEN' */
  xml_1_1__Lex092               , /* _Lex092 ~ 'NMTOKENS' */
  xml_1_1__Lex093               , /* _Lex093 ~ 'NOTATION' */
  xml_1_1__Lex094               , /* _Lex094 ~ '#REQUIRED' */
  xml_1_1__Lex095               , /* _Lex095 ~ '#IMPLIED' */
  xml_1_1__Lex096               , /* _Lex096 ~ '#FIXED' */
  xml_1_1__Lex097               , /* _Lex097 ~ '<![' */
  xml_1_1__Lex098               , /* _Lex098 ~ 'INCLUDE' */
  xml_1_1__Lex099               , /* _Lex099 ~ 'IGNORE' */
  xml_1_1__Lex100               , /* _Lex100 ~ '&#' */
  xml_1_1__Lex101               , /* _Lex101 ~ ';' */
  xml_1_1__Lex102               , /* _Lex102 ~ '&#x' */
  xml_1_1__Lex103               , /* _Lex103 ~ [0-9a-fA-F] */
  xml_1_1__Lex104               , /* _Lex104 ~ '&' */
  xml_1_1__Lex105               , /* _Lex105 ~ '%' */
  xml_1_1__Lex106               , /* _Lex106 ~ '<!ENTITY' */
  xml_1_1__Lex107               , /* _Lex107 ~ 'SYSTEM' */
  xml_1_1__Lex108               , /* _Lex108 ~ 'PUBLIC' */
  xml_1_1__Lex109               , /* _Lex109 ~ 'NDATA' */
  xml_1_1__Lex110               , /* _Lex110 ~ 'encoding' */
  xml_1_1__Lex111               , /* _Lex111 ~ [A-Za-z] */
  xml_1_1__Lex112               , /* _Lex112 ~ [A-Za-z0-9._] */
  xml_1_1__Lex113               , /* _Lex113 ~ '<!NOTATION' */
  /* Non-terminals */
  xml_1_1_AttDef                ,
  xml_1_1_AttDef_any            ,
  xml_1_1_AttType               ,
  xml_1_1_AttValue              ,
  xml_1_1_AttlistDecl           ,
  xml_1_1_Attribute             ,
  xml_1_1_CDEnd                 ,
  xml_1_1_CDSect                ,
  xml_1_1_CDStart               ,
  xml_1_1_CData                 ,
  xml_1_1_Char                  ,
  xml_1_1_CharData              ,
  xml_1_1_CharData_maybe        ,
  xml_1_1_CharRef               ,
  xml_1_1_Char_any              ,
  xml_1_1_Comment               ,
  xml_1_1_DeclSep               ,
  xml_1_1_DefaultDecl           ,
  xml_1_1_ETag                  ,
  xml_1_1_EmptyElemTag          ,
  xml_1_1_EncName               ,
  xml_1_1_EncodingDecl          ,
  xml_1_1_EncodingDecl_maybe    ,
  xml_1_1_EntityDecl            ,
  xml_1_1_EntityDef             ,
  xml_1_1_EntityRef             ,
  xml_1_1_EntityValue           ,
  xml_1_1_EnumeratedType        ,
  xml_1_1_Enumeration           ,
  xml_1_1_Eq                    ,
  xml_1_1_ExternalID            ,
  xml_1_1_GEDecl                ,
  xml_1_1_Ignore                ,
  xml_1_1_Misc                  ,
  xml_1_1_Misc_any              ,
  xml_1_1_Mixed                 ,
  xml_1_1_NDataDecl             ,
  xml_1_1_NDataDecl_maybe       ,
  xml_1_1_Name                  ,
  xml_1_1_NameChar              ,
  xml_1_1_NameStartChar         ,
  xml_1_1_Names                 ,
  xml_1_1_Nmtoken               ,
  xml_1_1_Nmtokens              ,
  xml_1_1_NotationDecl          ,
  xml_1_1_NotationType          ,
  xml_1_1_PEDecl                ,
  xml_1_1_PEDef                 ,
  xml_1_1_PEReference           ,
  xml_1_1_PI                    ,
  xml_1_1_PITarget              ,
  xml_1_1_PubidChar             ,
  xml_1_1_PubidChar_any         ,
  xml_1_1_PubidLiteral          ,
  xml_1_1_PublicID              ,
  xml_1_1_Reference             ,
  xml_1_1_RestrictedChar        ,
  xml_1_1_S                     ,
  xml_1_1_SDDecl                ,
  xml_1_1_SDDecl_maybe          ,
  xml_1_1_STag                  ,
  xml_1_1_S_maybe               ,
  xml_1_1_StringType            ,
  xml_1_1_SystemLiteral         ,
  xml_1_1_TextDecl              ,
  xml_1_1_TextDecl_maybe        ,
  xml_1_1_TokenizedType         ,
  xml_1_1_VersionInfo           ,
  xml_1_1_VersionInfo_maybe     ,
  xml_1_1_VersionNum            ,
  xml_1_1_XMLDecl               ,
  xml_1_1__Gen002               ,
  xml_1_1__Gen004               ,
  xml_1_1__Gen005               ,
  xml_1_1__Gen015               ,
  xml_1_1__Gen015_many          ,
  xml_1_1__Gen044               ,
  xml_1_1__Gen044_any           ,
  xml_1_1__Gen047               ,
  xml_1_1__Gen047_any           ,
  xml_1_1__Gen050               ,
  xml_1_1__Gen050_many          ,
  xml_1_1__Gen053               ,
  xml_1_1__Gen053_any           ,
  xml_1_1__Gen056               ,
  xml_1_1__Gen056_any           ,
  xml_1_1__Gen060               ,
  xml_1_1__Gen060_any           ,
  xml_1_1__Gen066               ,
  xml_1_1__Gen066_any           ,
  xml_1_1__Gen069               ,
  xml_1_1__Gen069_any           ,
  xml_1_1__Gen075               ,
  xml_1_1__Gen077               ,
  xml_1_1__Gen081               ,
  xml_1_1__Gen082               ,
  xml_1_1__Gen082_any           ,
  xml_1_1__Gen092               ,
  xml_1_1__Gen093               ,
  xml_1_1__Gen095               ,
  xml_1_1__Gen096               ,
  xml_1_1__Gen097               ,
  xml_1_1__Gen098               ,
  xml_1_1__Gen099               ,
  xml_1_1__Gen100               ,
  xml_1_1__Gen100_any           ,
  xml_1_1__Gen104               ,
  xml_1_1__Gen105               ,
  xml_1_1__Gen106               ,
  xml_1_1__Gen107               ,
  xml_1_1__Gen107_maybe         ,
  xml_1_1__Gen111               ,
  xml_1_1__Gen113               ,
  xml_1_1__Gen115               ,
  xml_1_1__Gen117               ,
  xml_1_1__Gen118               ,
  xml_1_1__Gen122               ,
  xml_1_1__Gen123               ,
  xml_1_1__Gen124               ,
  xml_1_1__Gen127               ,
  xml_1_1__Gen127_maybe         ,
  xml_1_1__Gen138               ,
  xml_1_1__Gen146               ,
  xml_1_1__Gen146_maybe         ,
  xml_1_1__Gen149               ,
  xml_1_1__Gen149_maybe         ,
  xml_1_1__Gen155               ,
  xml_1_1__Gen155_any           ,
  xml_1_1__Gen168               ,
  xml_1_1__Gen168_any           ,
  xml_1_1__Gen173               ,
  xml_1_1__Gen175               ,
  xml_1_1__Gen176               ,
  xml_1_1__Gen178               ,
  xml_1_1__Gen179               ,
  xml_1_1__Gen184               ,
  xml_1_1__Gen184_any           ,
  xml_1_1__Gen191               ,
  xml_1_1__Gen196               ,
  xml_1_1__Gen196_any           ,
  xml_1_1__Gen199               ,
  xml_1_1__Gen199_any           ,
  xml_1_1__Gen207               ,
  xml_1_1__Gen209               ,
  xml_1_1__Gen209_maybe         ,
  xml_1_1__Gen215               ,
  xml_1_1__Gen218               ,
  xml_1_1__Gen218_maybe         ,
  xml_1_1__Gen224               ,
  xml_1_1__Gen224_many          ,
  xml_1_1__Gen227               ,
  xml_1_1__Gen227_any           ,
  xml_1_1__Gen230               ,
  xml_1_1__Gen230_any           ,
  xml_1_1__Gen250               ,
  xml_1_1__Gen250_any           ,
  xml_1_1__Gen253               ,
  xml_1_1__Gen253_any           ,
  xml_1_1__Gen256               ,
  xml_1_1__Gen256_maybe         ,
  xml_1_1__Gen259               ,
  xml_1_1__Gen268               ,
  xml_1_1__Gen268_any           ,
  xml_1_1__Gen271               ,
  xml_1_1__Gen273               ,
  xml_1_1__Gen274               ,
  xml_1_1__Gen290               ,
  xml_1_1__Gen301               ,
  xml_1_1__Gen302               ,
  xml_1_1__Gen303               ,
  xml_1_1__Gen305               ,
  xml_1_1__Gen308               ,
  xml_1_1__Gen308_any           ,
  xml_1_1__Gen312               ,
  xml_1_1__Lex031_many          ,
  xml_1_1__Lex041_any           ,
  xml_1_1__Lex042_any           ,
  xml_1_1__Lex045_any           ,
  xml_1_1__Lex103_many          ,
  xml_1_1_children              ,
  xml_1_1_choice                ,
  xml_1_1_conditionalSect       ,
  xml_1_1_content               ,
  xml_1_1_contentspec           ,
  xml_1_1_cp                    ,
  xml_1_1_doctypedecl           ,
  xml_1_1_document              ,
  xml_1_1_element               ,
  xml_1_1_elementdecl           ,
  xml_1_1_extParsedEnt          ,
  xml_1_1_extSubset             ,
  xml_1_1_extSubsetDecl         ,
  xml_1_1_ignoreSect            ,
  xml_1_1_ignoreSectContents    ,
  xml_1_1_ignoreSectContents_any,
  xml_1_1_includeSect           ,
  xml_1_1_intSubset             ,
  xml_1_1_markupdecl            ,
  xml_1_1_prolog                ,
  xml_1_1_seq                   ,
  XML_1_1_SYMBOL_MAX
} xml_1_1_symbol_t;

#define XML_1_1_TERMINAL_MAX xml_1_1__Lex113

/* Rules */
typedef enum xml_1_1_rule {
  xml_1_1_Misc_any_001 = 0      , /* Misc_any ::= Misc * */
  xml_1_1__Gen002_001           , /* _Gen002 ::= prolog element Misc_any  */
  xml_1_1_Char_any_001          , /* Char_any ::= Char * */
  xml_1_1__Gen004_001           , /* _Gen004 ::= Char_any RestrictedChar Char_any  */
  xml_1_1__Gen005_001           , /* _Gen005 ::= _Exclusion001  */
  xml_1_1_document_001          , /* document ::= _Gen005  */
  xml_1_1_Char_001              , /* Char ::= _Lex001  */
  xml_1_1_Char_002              , /* Char ::= _Lex002  */
  xml_1_1_Char_003              , /* Char ::= _Lex003  */
  xml_1_1_RestrictedChar_001    , /* RestrictedChar ::= _Lex004  */
  xml_1_1_RestrictedChar_002    , /* RestrictedChar ::= _Lex005  */
  xml_1_1_RestrictedChar_003    , /* RestrictedChar ::= _Lex006  */
  xml_1_1_RestrictedChar_004    , /* RestrictedChar ::= _Lex007  */
  xml_1_1_RestrictedChar_005    , /* RestrictedChar ::= _Lex008  */
  xml_1_1__Gen015_001           , /* _Gen015 ::= _Lex009  */
  xml_1_1__Gen015_002           , /* _Gen015 ::= _Lex010  */
  xml_1_1__Gen015_003           , /* _Gen015 ::= _Lex011  */
  xml_1_1__Gen015_004           , /* _Gen015 ::= _Lex012  */
  xml_1_1__Gen015_many_001      , /* _Gen015_many ::= _Gen015 + */
  xml_1_1_S_001                 , /* S ::= _Gen015_many  */
  xml_1_1_NameStartChar_001     , /* NameStartChar ::= _Lex013  */
  xml_1_1_NameStartChar_002     , /* NameStartChar ::= _Lex014  */
  xml_1_1_NameStartChar_003     , /* NameStartChar ::= _Lex015  */
  xml_1_1_NameStartChar_004     , /* NameStartChar ::= _Lex016  */
  xml_1_1_NameStartChar_005     , /* NameStartChar ::= _Lex017  */
  xml_1_1_NameStartChar_006     , /* NameStartChar ::= _Lex018  */
  xml_1_1_NameStartChar_007     , /* NameStartChar ::= _Lex019  */
  xml_1_1_NameStartChar_008     , /* NameStartChar ::= _Lex020  */
  xml_1_1_NameStartChar_009     , /* NameStartChar ::= _Lex021  */
  xml_1_1_NameStartChar_010     , /* NameStartChar ::= _Lex022  */
  xml_1_1_NameStartChar_011     , /* NameStartChar ::= _Lex023  */
  xml_1_1_NameStartChar_012     , /* NameStartChar ::= _Lex024  */
  xml_1_1_NameStartChar_013     , /* NameStartChar ::= _Lex025  */
  xml_1_1_NameStartChar_014     , /* NameStartChar ::= _Lex026  */
  xml_1_1_NameStartChar_015     , /* NameStartChar ::= _Lex027  */
  xml_1_1_NameStartChar_016     , /* NameStartChar ::= _Lex028  */
  xml_1_1_NameChar_001          , /* NameChar ::= NameStartChar  */
  xml_1_1_NameChar_002          , /* NameChar ::= _Lex029  */
  xml_1_1_NameChar_003          , /* NameChar ::= _Lex030  */
  xml_1_1_NameChar_004          , /* NameChar ::= _Lex031  */
  xml_1_1_NameChar_005          , /* NameChar ::= _Lex032  */
  xml_1_1_NameChar_006          , /* NameChar ::= _Lex033  */
  xml_1_1_NameChar_007          , /* NameChar ::= _Lex034  */
  xml_1_1__Gen044_001           , /* _Gen044 ::= NameChar  */
  xml_1_1__Gen044_any_001       , /* _Gen044_any ::= _Gen044 * */
  xml_1_1_Name_001              , /* Name ::= NameStartChar _Gen044_any  */
  xml_1_1__Gen047_001           , /* _Gen047 ::= _Lex009 Name  */
  xml_1_1__Gen047_any_001       , /* _Gen047_any ::= _Gen047 * */
  xml_1_1_Names_001             , /* Names ::= Name _Gen047_any  */
  xml_1_1__Gen050_001           , /* _Gen050 ::= NameChar  */
  xml_1_1__Gen050_many_001      , /* _Gen050_many ::= _Gen050 + */
  xml_1_1_Nmtoken_001           , /* Nmtoken ::= _Gen050_many  */
  xml_1_1__Gen053_001           , /* _Gen053 ::= _Lex009 Nmtoken  */
  xml_1_1__Gen053_any_001       , /* _Gen053_any ::= _Gen053 * */
  xml_1_1_Nmtokens_001          , /* Nmtokens ::= Nmtoken _Gen053_any  */
  xml_1_1__Gen056_001           , /* _Gen056 ::= _Lex036  */
  xml_1_1__Gen056_002           , /* _Gen056 ::= PEReference  */
  xml_1_1__Gen056_003           , /* _Gen056 ::= Reference  */
  xml_1_1__Gen056_any_001       , /* _Gen056_any ::= _Gen056 * */
  xml_1_1__Gen060_001           , /* _Gen060 ::= _Lex038  */
  xml_1_1__Gen060_002           , /* _Gen060 ::= PEReference  */
  xml_1_1__Gen060_003           , /* _Gen060 ::= Reference  */
  xml_1_1__Gen060_any_001       , /* _Gen060_any ::= _Gen060 * */
  xml_1_1_EntityValue_001       , /* EntityValue ::= _Lex035 _Gen056_any _Lex035  */
  xml_1_1_EntityValue_002       , /* EntityValue ::= _Lex037 _Gen060_any _Lex037  */
  xml_1_1__Gen066_001           , /* _Gen066 ::= _Lex039  */
  xml_1_1__Gen066_002           , /* _Gen066 ::= Reference  */
  xml_1_1__Gen066_any_001       , /* _Gen066_any ::= _Gen066 * */
  xml_1_1__Gen069_001           , /* _Gen069 ::= _Lex040  */
  xml_1_1__Gen069_002           , /* _Gen069 ::= Reference  */
  xml_1_1__Gen069_any_001       , /* _Gen069_any ::= _Gen069 * */
  xml_1_1_AttValue_001          , /* AttValue ::= _Lex035 _Gen066_any _Lex035  */
  xml_1_1_AttValue_002          , /* AttValue ::= _Lex037 _Gen069_any _Lex037  */
  xml_1_1__Lex041_any_001       , /* _Lex041_any ::= _Lex041 * */
  xml_1_1__Gen075_001           , /* _Gen075 ::= _Lex035 _Lex041_any _Lex035  */
  xml_1_1__Lex042_any_001       , /* _Lex042_any ::= _Lex042 * */
  xml_1_1__Gen077_001           , /* _Gen077 ::= _Lex037 _Lex042_any _Lex037  */
  xml_1_1_SystemLiteral_001     , /* SystemLiteral ::= _Gen075  */
  xml_1_1_SystemLiteral_002     , /* SystemLiteral ::= _Gen077  */
  xml_1_1_PubidChar_any_001     , /* PubidChar_any ::= PubidChar * */
  xml_1_1__Gen081_001           , /* _Gen081 ::= _Exclusion002  */
  xml_1_1__Gen082_001           , /* _Gen082 ::= _Gen081  */
  xml_1_1__Gen082_any_001       , /* _Gen082_any ::= _Gen082 * */
  xml_1_1_PubidLiteral_001      , /* PubidLiteral ::= _Lex035 PubidChar_any _Lex035  */
  xml_1_1_PubidLiteral_002      , /* PubidLiteral ::= _Lex037 _Gen082_any _Lex037  */
  xml_1_1_PubidChar_001         , /* PubidChar ::= _Lex009  */
  xml_1_1_PubidChar_002         , /* PubidChar ::= _Lex011  */
  xml_1_1_PubidChar_003         , /* PubidChar ::= _Lex012  */
  xml_1_1_PubidChar_004         , /* PubidChar ::= _Lex043  */
  xml_1_1_PubidChar_005         , /* PubidChar ::= _Lex044  */
  xml_1_1__Lex045_any_001       , /* _Lex045_any ::= _Lex045 * */
  xml_1_1__Gen092_001           , /* _Gen092 ::= _Lex045_any _Lex046 _Lex045_any  */
  xml_1_1__Gen093_001           , /* _Gen093 ::= _Exclusion003  */
  xml_1_1_CharData_001          , /* CharData ::= _Gen093  */
  xml_1_1__Gen095_001           , /* _Gen095 ::= _Exclusion004  */
  xml_1_1__Gen096_001           , /* _Gen096 ::= _Gen095  */
  xml_1_1__Gen097_001           , /* _Gen097 ::= _Exclusion004  */
  xml_1_1__Gen098_001           , /* _Gen098 ::= _Gen097  */
  xml_1_1__Gen099_001           , /* _Gen099 ::= _Lex029 _Gen098  */
  xml_1_1__Gen100_001           , /* _Gen100 ::= _Gen096  */
  xml_1_1__Gen100_002           , /* _Gen100 ::= _Gen099  */
  xml_1_1__Gen100_any_001       , /* _Gen100_any ::= _Gen100 * */
  xml_1_1_Comment_001           , /* Comment ::= _Lex047 _Gen100_any _Lex048  */
  xml_1_1__Gen104_001           , /* _Gen104 ::= Char_any _Lex050 Char_any  */
  xml_1_1__Gen105_001           , /* _Gen105 ::= _Exclusion005  */
  xml_1_1__Gen106_001           , /* _Gen106 ::= _Gen105  */
  xml_1_1__Gen107_001           , /* _Gen107 ::= S _Gen106  */
  xml_1_1__Gen107_maybe_001     , /* _Gen107_maybe ::= _Gen107  */
  xml_1_1__Gen107_maybe_002     , /* _Gen107_maybe ::=   */
  xml_1_1_PI_001                , /* PI ::= _Lex049 PITarget _Gen107_maybe _Lex050  */
  xml_1_1__Gen111_001           , /* _Gen111 ::= _Lex051  */
  xml_1_1__Gen111_002           , /* _Gen111 ::= _Lex052  */
  xml_1_1__Gen113_001           , /* _Gen113 ::= _Lex053  */
  xml_1_1__Gen113_002           , /* _Gen113 ::= _Lex054  */
  xml_1_1__Gen115_001           , /* _Gen115 ::= _Lex055  */
  xml_1_1__Gen115_002           , /* _Gen115 ::= _Lex056  */
  xml_1_1__Gen117_001           , /* _Gen117 ::= _Gen111 _Gen113 _Gen115  */
  xml_1_1__Gen118_001           , /* _Gen118 ::= _Exclusion006  */
  xml_1_1_PITarget_001          , /* PITarget ::= _Gen118  */
  xml_1_1_CDSect_001            , /* CDSect ::= CDStart CData CDEnd  */
  xml_1_1_CDStart_001           , /* CDStart ::= _Lex057  */
  xml_1_1__Gen122_001           , /* _Gen122 ::= Char_any _Lex046 Char_any  */
  xml_1_1__Gen123_001           , /* _Gen123 ::= _Exclusion007  */
  xml_1_1__Gen124_001           , /* _Gen124 ::= _Gen123  */
  xml_1_1_CData_001             , /* CData ::= _Gen124  */
  xml_1_1_CDEnd_001             , /* CDEnd ::= _Lex046  */
  xml_1_1__Gen127_001           , /* _Gen127 ::= doctypedecl Misc_any  */
  xml_1_1__Gen127_maybe_001     , /* _Gen127_maybe ::= _Gen127  */
  xml_1_1__Gen127_maybe_002     , /* _Gen127_maybe ::=   */
  xml_1_1_prolog_001            , /* prolog ::= XMLDecl Misc_any _Gen127_maybe  */
  xml_1_1_EncodingDecl_maybe_001, /* EncodingDecl_maybe ::= EncodingDecl  */
  xml_1_1_EncodingDecl_maybe_002, /* EncodingDecl_maybe ::=   */
  xml_1_1_SDDecl_maybe_001      , /* SDDecl_maybe ::= SDDecl  */
  xml_1_1_SDDecl_maybe_002      , /* SDDecl_maybe ::=   */
  xml_1_1_S_maybe_001           , /* S_maybe ::= S  */
  xml_1_1_S_maybe_002           , /* S_maybe ::=   */
  xml_1_1_XMLDecl_001           , /* XMLDecl ::= _Lex058 VersionInfo EncodingDecl_maybe SDDecl_maybe S_maybe _Lex050  */
  xml_1_1__Gen138_001           , /* _Gen138 ::= _Lex037 VersionNum _Lex037  */
  xml_1_1__Gen138_002           , /* _Gen138 ::= _Lex035 VersionNum _Lex035  */
  xml_1_1_VersionInfo_001       , /* VersionInfo ::= S _Lex059 Eq _Gen138  */
  xml_1_1_Eq_001                , /* Eq ::= S_maybe _Lex060 S_maybe  */
  xml_1_1_VersionNum_001        , /* VersionNum ::= _Lex061  */
  xml_1_1_Misc_001              , /* Misc ::= Comment  */
  xml_1_1_Misc_002              , /* Misc ::= PI  */
  xml_1_1_Misc_003              , /* Misc ::= S  */
  xml_1_1__Gen146_001           , /* _Gen146 ::= S ExternalID  */
  xml_1_1__Gen146_maybe_001     , /* _Gen146_maybe ::= _Gen146  */
  xml_1_1__Gen146_maybe_002     , /* _Gen146_maybe ::=   */
  xml_1_1__Gen149_001           , /* _Gen149 ::= _Lex063 intSubset _Lex064 S_maybe  */
  xml_1_1__Gen149_maybe_001     , /* _Gen149_maybe ::= _Gen149  */
  xml_1_1__Gen149_maybe_002     , /* _Gen149_maybe ::=   */
  xml_1_1_doctypedecl_001       , /* doctypedecl ::= _Lex062 S Name _Gen146_maybe S_maybe _Gen149_maybe _Lex065  */
  xml_1_1_DeclSep_001           , /* DeclSep ::= PEReference  */
  xml_1_1_DeclSep_002           , /* DeclSep ::= S  */
  xml_1_1__Gen155_001           , /* _Gen155 ::= markupdecl  */
  xml_1_1__Gen155_002           , /* _Gen155 ::= DeclSep  */
  xml_1_1__Gen155_any_001       , /* _Gen155_any ::= _Gen155 * */
  xml_1_1_intSubset_001         , /* intSubset ::= _Gen155_any  */
  xml_1_1_markupdecl_001        , /* markupdecl ::= elementdecl  */
  xml_1_1_markupdecl_002        , /* markupdecl ::= AttlistDecl  */
  xml_1_1_markupdecl_003        , /* markupdecl ::= EntityDecl  */
  xml_1_1_markupdecl_004        , /* markupdecl ::= NotationDecl  */
  xml_1_1_markupdecl_005        , /* markupdecl ::= PI  */
  xml_1_1_markupdecl_006        , /* markupdecl ::= Comment  */
  xml_1_1_TextDecl_maybe_001    , /* TextDecl_maybe ::= TextDecl  */
  xml_1_1_TextDecl_maybe_002    , /* TextDecl_maybe ::=   */
  xml_1_1_extSubset_001         , /* extSubset ::= TextDecl_maybe extSubsetDecl  */
  xml_1_1__Gen168_001           , /* _Gen168 ::= markupdecl  */
  xml_1_1__Gen168_002           , /* _Gen168 ::= conditionalSect  */
  xml_1_1__Gen168_003           , /* _Gen168 ::= DeclSep  */
  xml_1_1__Gen168_any_001       , /* _Gen168_any ::= _Gen168 * */
  xml_1_1_extSubsetDecl_001     , /* extSubsetDecl ::= _Gen168_any  */
  xml_1_1__Gen173_001           , /* _Gen173 ::= _Lex067  */
  xml_1_1__Gen173_002           , /* _Gen173 ::= _Lex068  */
  xml_1_1__Gen175_001           , /* _Gen175 ::= _Lex037 _Gen173 _Lex037  */
  xml_1_1__Gen176_001           , /* _Gen176 ::= _Lex067  */
  xml_1_1__Gen176_002           , /* _Gen176 ::= _Lex068  */
  xml_1_1__Gen178_001           , /* _Gen178 ::= _Lex035 _Gen176 _Lex035  */
  xml_1_1__Gen179_001           , /* _Gen179 ::= _Gen175  */
  xml_1_1__Gen179_002           , /* _Gen179 ::= _Gen178  */
  xml_1_1_SDDecl_001            , /* SDDecl ::= S _Lex066 Eq _Gen179  */
  xml_1_1_element_001           , /* element ::= EmptyElemTag  */
  xml_1_1_element_002           , /* element ::= STag content ETag  */
  xml_1_1__Gen184_001           , /* _Gen184 ::= S Attribute  */
  xml_1_1__Gen184_any_001       , /* _Gen184_any ::= _Gen184 * */
  xml_1_1_STag_001              , /* STag ::= _Lex069 Name _Gen184_any S_maybe _Lex065  */
  xml_1_1_Attribute_001         , /* Attribute ::= Name Eq AttValue  */
  xml_1_1_ETag_001              , /* ETag ::= _Lex070 Name S_maybe _Lex065  */
  xml_1_1_CharData_maybe_001    , /* CharData_maybe ::= CharData  */
  xml_1_1_CharData_maybe_002    , /* CharData_maybe ::=   */
  xml_1_1__Gen191_001           , /* _Gen191 ::= element  */
  xml_1_1__Gen191_002           , /* _Gen191 ::= Reference  */
  xml_1_1__Gen191_003           , /* _Gen191 ::= CDSect  */
  xml_1_1__Gen191_004           , /* _Gen191 ::= PI  */
  xml_1_1__Gen191_005           , /* _Gen191 ::= Comment  */
  xml_1_1__Gen196_001           , /* _Gen196 ::= _Gen191 CharData_maybe  */
  xml_1_1__Gen196_any_001       , /* _Gen196_any ::= _Gen196 * */
  xml_1_1_content_001           , /* content ::= CharData_maybe _Gen196_any  */
  xml_1_1__Gen199_001           , /* _Gen199 ::= S Attribute  */
  xml_1_1__Gen199_any_001       , /* _Gen199_any ::= _Gen199 * */
  xml_1_1_EmptyElemTag_001      , /* EmptyElemTag ::= _Lex069 Name _Gen199_any S_maybe _Lex071  */
  xml_1_1_elementdecl_001       , /* elementdecl ::= _Lex072 S Name S contentspec S_maybe _Lex065  */
  xml_1_1_contentspec_001       , /* contentspec ::= _Lex073  */
  xml_1_1_contentspec_002       , /* contentspec ::= _Lex074  */
  xml_1_1_contentspec_003       , /* contentspec ::= Mixed  */
  xml_1_1_contentspec_004       , /* contentspec ::= children  */
  xml_1_1__Gen207_001           , /* _Gen207 ::= choice  */
  xml_1_1__Gen207_002           , /* _Gen207 ::= seq  */
  xml_1_1__Gen209_001           , /* _Gen209 ::= _Lex075  */
  xml_1_1__Gen209_002           , /* _Gen209 ::= _Lex076  */
  xml_1_1__Gen209_003           , /* _Gen209 ::= _Lex077  */
  xml_1_1__Gen209_maybe_001     , /* _Gen209_maybe ::= _Gen209  */
  xml_1_1__Gen209_maybe_002     , /* _Gen209_maybe ::=   */
  xml_1_1_children_001          , /* children ::= _Gen207 _Gen209_maybe  */
  xml_1_1__Gen215_001           , /* _Gen215 ::= Name  */
  xml_1_1__Gen215_002           , /* _Gen215 ::= choice  */
  xml_1_1__Gen215_003           , /* _Gen215 ::= seq  */
  xml_1_1__Gen218_001           , /* _Gen218 ::= _Lex075  */
  xml_1_1__Gen218_002           , /* _Gen218 ::= _Lex076  */
  xml_1_1__Gen218_003           , /* _Gen218 ::= _Lex077  */
  xml_1_1__Gen218_maybe_001     , /* _Gen218_maybe ::= _Gen218  */
  xml_1_1__Gen218_maybe_002     , /* _Gen218_maybe ::=   */
  xml_1_1_cp_001                , /* cp ::= _Gen215 _Gen218_maybe  */
  xml_1_1__Gen224_001           , /* _Gen224 ::= S_maybe _Lex079 S_maybe cp  */
  xml_1_1__Gen224_many_001      , /* _Gen224_many ::= _Gen224 + */
  xml_1_1_choice_001            , /* choice ::= _Lex078 S_maybe cp _Gen224_many S_maybe _Lex080  */
  xml_1_1__Gen227_001           , /* _Gen227 ::= S_maybe _Lex081 S_maybe cp  */
  xml_1_1__Gen227_any_001       , /* _Gen227_any ::= _Gen227 * */
  xml_1_1_seq_001               , /* seq ::= _Lex078 S_maybe cp _Gen227_any S_maybe _Lex080  */
  xml_1_1__Gen230_001           , /* _Gen230 ::= S_maybe _Lex079 S_maybe Name  */
  xml_1_1__Gen230_any_001       , /* _Gen230_any ::= _Gen230 * */
  xml_1_1_Mixed_001             , /* Mixed ::= _Lex078 S_maybe _Lex082 _Gen230_any S_maybe _Lex083  */
  xml_1_1_Mixed_002             , /* Mixed ::= _Lex078 S_maybe _Lex082 S_maybe _Lex080  */
  xml_1_1_AttDef_any_001        , /* AttDef_any ::= AttDef * */
  xml_1_1_AttlistDecl_001       , /* AttlistDecl ::= _Lex084 S Name AttDef_any S_maybe _Lex065  */
  xml_1_1_AttDef_001            , /* AttDef ::= S Name S AttType S DefaultDecl  */
  xml_1_1_AttType_001           , /* AttType ::= StringType  */
  xml_1_1_AttType_002           , /* AttType ::= TokenizedType  */
  xml_1_1_AttType_003           , /* AttType ::= EnumeratedType  */
  xml_1_1_StringType_001        , /* StringType ::= _Lex085  */
  xml_1_1_TokenizedType_001     , /* TokenizedType ::= _Lex086  */
  xml_1_1_TokenizedType_002     , /* TokenizedType ::= _Lex087  */
  xml_1_1_TokenizedType_003     , /* TokenizedType ::= _Lex088  */
  xml_1_1_TokenizedType_004     , /* TokenizedType ::= _Lex089  */
  xml_1_1_TokenizedType_005     , /* TokenizedType ::= _Lex090  */
  xml_1_1_TokenizedType_006     , /* TokenizedType ::= _Lex091  */
  xml_1_1_TokenizedType_007     , /* TokenizedType ::= _Lex092  */
  xml_1_1_EnumeratedType_001    , /* EnumeratedType ::= NotationType  */
  xml_1_1_EnumeratedType_002    , /* EnumeratedType ::= Enumeration  */
  xml_1_1__Gen250_001           , /* _Gen250 ::= S_maybe _Lex079 S_maybe Name  */
  xml_1_1__Gen250_any_001       , /* _Gen250_any ::= _Gen250 * */
  xml_1_1_NotationType_001      , /* NotationType ::= _Lex093 S _Lex078 S_maybe Name _Gen250_any S_maybe _Lex080  */
  xml_1_1__Gen253_001           , /* _Gen253 ::= S_maybe _Lex079 S_maybe Nmtoken  */
  xml_1_1__Gen253_any_001       , /* _Gen253_any ::= _Gen253 * */
  xml_1_1_Enumeration_001       , /* Enumeration ::= _Lex078 S_maybe Nmtoken _Gen253_any S_maybe _Lex080  */
  xml_1_1__Gen256_001           , /* _Gen256 ::= _Lex096 S  */
  xml_1_1__Gen256_maybe_001     , /* _Gen256_maybe ::= _Gen256  */
  xml_1_1__Gen256_maybe_002     , /* _Gen256_maybe ::=   */
  xml_1_1__Gen259_001           , /* _Gen259 ::= _Gen256_maybe AttValue  */
  xml_1_1_DefaultDecl_001       , /* DefaultDecl ::= _Lex094  */
  xml_1_1_DefaultDecl_002       , /* DefaultDecl ::= _Lex095  */
  xml_1_1_DefaultDecl_003       , /* DefaultDecl ::= _Gen259  */
  xml_1_1_conditionalSect_001   , /* conditionalSect ::= includeSect  */
  xml_1_1_conditionalSect_002   , /* conditionalSect ::= ignoreSect  */
  xml_1_1_includeSect_001       , /* includeSect ::= _Lex097 S_maybe _Lex098 S_maybe _Lex063 extSubsetDecl _Lex046  */
  xml_1_1_ignoreSectContents_any_001, /* ignoreSectContents_any ::= ignoreSectContents * */
  xml_1_1_ignoreSect_001        , /* ignoreSect ::= _Lex097 S_maybe _Lex099 S_maybe _Lex063 ignoreSectContents_any _Lex046  */
  xml_1_1__Gen268_001           , /* _Gen268 ::= _Lex097 ignoreSectContents _Lex046 Ignore  */
  xml_1_1__Gen268_any_001       , /* _Gen268_any ::= _Gen268 * */
  xml_1_1_ignoreSectContents_001, /* ignoreSectContents ::= Ignore _Gen268_any  */
  xml_1_1__Gen271_001           , /* _Gen271 ::= _Lex097  */
  xml_1_1__Gen271_002           , /* _Gen271 ::= _Lex046  */
  xml_1_1__Gen273_001           , /* _Gen273 ::= Char_any _Gen271 Char_any  */
  xml_1_1__Gen274_001           , /* _Gen274 ::= _Exclusion008  */
  xml_1_1_Ignore_001            , /* Ignore ::= _Gen274  */
  xml_1_1__Lex031_many_001      , /* _Lex031_many ::= _Lex031 + */
  xml_1_1__Lex103_many_001      , /* _Lex103_many ::= _Lex103 + */
  xml_1_1_CharRef_001           , /* CharRef ::= _Lex100 _Lex031_many _Lex101  */
  xml_1_1_CharRef_002           , /* CharRef ::= _Lex102 _Lex103_many _Lex101  */
  xml_1_1_Reference_001         , /* Reference ::= EntityRef  */
  xml_1_1_Reference_002         , /* Reference ::= CharRef  */
  xml_1_1_EntityRef_001         , /* EntityRef ::= _Lex104 Name _Lex101  */
  xml_1_1_PEReference_001       , /* PEReference ::= _Lex105 Name _Lex101  */
  xml_1_1_EntityDecl_001        , /* EntityDecl ::= GEDecl  */
  xml_1_1_EntityDecl_002        , /* EntityDecl ::= PEDecl  */
  xml_1_1_GEDecl_001            , /* GEDecl ::= _Lex106 S Name S EntityDef S_maybe _Lex065  */
  xml_1_1_PEDecl_001            , /* PEDecl ::= _Lex106 S _Lex105 S Name S PEDef S_maybe _Lex065  */
  xml_1_1_NDataDecl_maybe_001   , /* NDataDecl_maybe ::= NDataDecl  */
  xml_1_1_NDataDecl_maybe_002   , /* NDataDecl_maybe ::=   */
  xml_1_1__Gen290_001           , /* _Gen290 ::= ExternalID NDataDecl_maybe  */
  xml_1_1_EntityDef_001         , /* EntityDef ::= EntityValue  */
  xml_1_1_EntityDef_002         , /* EntityDef ::= _Gen290  */
  xml_1_1_PEDef_001             , /* PEDef ::= EntityValue  */
  xml_1_1_PEDef_002             , /* PEDef ::= ExternalID  */
  xml_1_1_ExternalID_001        , /* ExternalID ::= _Lex107 S SystemLiteral  */
  xml_1_1_ExternalID_002        , /* ExternalID ::= _Lex108 S PubidLiteral S SystemLiteral  */
  xml_1_1_NDataDecl_001         , /* NDataDecl ::= S _Lex109 S Name  */
  xml_1_1_VersionInfo_maybe_001 , /* VersionInfo_maybe ::= VersionInfo  */
  xml_1_1_VersionInfo_maybe_002 , /* VersionInfo_maybe ::=   */
  xml_1_1_TextDecl_001          , /* TextDecl ::= _Lex058 VersionInfo_maybe EncodingDecl S_maybe _Lex050  */
  xml_1_1__Gen301_001           , /* _Gen301 ::= TextDecl_maybe content  */
  xml_1_1__Gen302_001           , /* _Gen302 ::= Char_any RestrictedChar Char_any  */
  xml_1_1__Gen303_001           , /* _Gen303 ::= _Exclusion009  */
  xml_1_1_extParsedEnt_001      , /* extParsedEnt ::= _Gen303  */
  xml_1_1__Gen305_001           , /* _Gen305 ::= _Lex035 EncName _Lex035  */
  xml_1_1__Gen305_002           , /* _Gen305 ::= _Lex037 EncName _Lex037  */
  xml_1_1_EncodingDecl_001      , /* EncodingDecl ::= S _Lex110 Eq _Gen305  */
  xml_1_1__Gen308_001           , /* _Gen308 ::= _Lex112  */
  xml_1_1__Gen308_002           , /* _Gen308 ::= _Lex029  */
  xml_1_1__Gen308_any_001       , /* _Gen308_any ::= _Gen308 * */
  xml_1_1_EncName_001           , /* EncName ::= _Lex111 _Gen308_any  */
  xml_1_1__Gen312_001           , /* _Gen312 ::= ExternalID  */
  xml_1_1__Gen312_002           , /* _Gen312 ::= PublicID  */
  xml_1_1_NotationDecl_001      , /* NotationDecl ::= _Lex113 S Name S _Gen312 S_maybe _Lex065  */
  xml_1_1_PublicID_001          , /* PublicID ::= _Lex108 S PubidLiteral  */
  XML_1_1_RULE_MAX
} xml_1_1_rule_t;


/* Work structure */
struct xml_1_1 {
  marpaWrapper_t        *marpaWrapperp;
  marpaWrapperSymbol_t **marpaWrapperSymbolArrayp;
  size_t                 marpaWrapperSymbolArrayLengthi;
  marpaWrapperRule_t   **marpaWrapperRuleArrayp;
  size_t                 marpaWrapperRuleArrayLengthi;
};

static C_INLINE marpaWrapperBool_t _xml_1_1_buildGrammarb(xml_1_1_t *xml_1_1p, marpaWrapperOption_t *marpaWrapperOptionp);
static C_INLINE marpaWrapperBool_t _xml_1_1_buildSymbolsb(xml_1_1_t *xml_1_1p);
static C_INLINE marpaWrapperBool_t _xml_1_1_buildSymbols_withStartb(xml_1_1_t *xml_1_1p, int starti);
static C_INLINE marpaWrapperBool_t _xml_1_1_buildRulesb(xml_1_1_t *xml_1_1p);
static C_INLINE marpaWrapperBool_t _xml_1_1_pushLexemeb(xml_1_1_t *xml_1_1p, xml_1_1_symbol_t xml_1_1_symbol, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion001b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion002b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion003b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion004b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion005b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion006b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion007b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion008b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion009b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex001b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex002b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex003b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex004b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex005b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex006b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex007b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex008b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex009b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex010b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex011b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex012b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex013b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex014b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex015b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex016b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex017b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex018b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex019b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex020b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex021b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex022b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex023b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex024b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex025b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex026b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex027b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex028b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex029b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex030b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex031b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex032b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex033b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex034b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex035b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex036b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex037b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex038b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex039b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex040b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex041b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex042b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex043b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex044b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex045b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex046b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex047b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex048b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex049b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex050b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex051b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex052b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex053b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex054b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex055b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex056b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex057b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex058b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex059b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex060b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex061b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex062b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex063b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex064b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex065b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex066b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex067b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex068b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex069b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex070b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex071b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex072b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex073b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex074b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex075b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex076b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex077b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex078b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex079b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex080b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex081b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex082b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex083b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex084b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex085b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex086b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex087b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex088b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex089b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex090b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex091b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex092b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex093b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex094b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex095b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex096b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex097b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex098b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex099b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex100b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex101b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex102b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex103b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex104b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex105b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex106b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex107b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex108b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex109b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex110b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex111b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex112b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex113b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp);

/*******************/
/* xml_1_1_newp  */
/*******************/
xml_1_1_t *xml_1_1_newp(marpaWrapperOption_t *marpaWrapperOptionp, xml_commonOption_t *xml_commonOptionp) {
  xml_1_1_t           *xml_1_1p;
  marpaWrapperOption_t marpaWrapperOption;

  /* Fill the defaults */
  if (marpaWrapperOptionp == NULL) {
    marpaWrapper_optionDefaultb(&marpaWrapperOption);
  } else {
    marpaWrapperOption = *marpaWrapperOptionp;
  }

  xml_1_1p = malloc(sizeof(xml_1_1_t));
  if (xml_1_1p == NULL) {
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

  xml_1_1p->marpaWrapperp = NULL;
  xml_1_1p->marpaWrapperSymbolArrayp = NULL;
  xml_1_1p->marpaWrapperSymbolArrayLengthi = 0;
  xml_1_1p->marpaWrapperRuleArrayp = NULL;
  xml_1_1p->marpaWrapperRuleArrayLengthi = 0;

  if (_xml_1_1_buildGrammarb(xml_1_1p, &marpaWrapperOption) == MARPAWRAPPER_BOOL_FALSE) {
    xml_1_1_destroyv(&xml_1_1p);
  }

  return xml_1_1p;
}

/*********************/
/* xml_1_1_destroyv  */
/*********************/
void xml_1_1_destroyv(xml_1_1_t **xml_1_1pp) {
  xml_1_1_t *xml_1_1p;

  if (xml_1_1pp != NULL) {
    xml_1_1p = *xml_1_1pp;

    if (xml_1_1p != NULL) {
      if (xml_1_1p->marpaWrapperp != NULL) {
	marpaWrapper_destroyv(&(xml_1_1p->marpaWrapperp));
      }
      if (xml_1_1p->marpaWrapperSymbolArrayp != NULL) {
	free(xml_1_1p->marpaWrapperSymbolArrayp);
      }
      if (xml_1_1p->marpaWrapperRuleArrayp != NULL) {
	free(xml_1_1p->marpaWrapperRuleArrayp);
      }
      free(xml_1_1p);
    }

    *xml_1_1pp = NULL;
  }
}

/**************************/
/* _xml_1_1_buildGrammarb */
/**************************/
static C_INLINE marpaWrapperBool_t _xml_1_1_buildGrammarb(xml_1_1_t *xml_1_1p, marpaWrapperOption_t *marpaWrapperOptionp) {

  xml_1_1p->marpaWrapperp = marpaWrapper_newp(marpaWrapperOptionp);
  if (xml_1_1p->marpaWrapperp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (_xml_1_1_buildSymbolsb(xml_1_1p) == MARPAWRAPPER_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (_xml_1_1_buildRulesb(xml_1_1p) == MARPAWRAPPER_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (marpaWrapper_g_precomputeb(xml_1_1p->marpaWrapperp) == MARPAWRAPPER_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  return MARPAWRAPPER_BOOL_TRUE;
}

/**************************/
/* _xml_1_1_buildSymbolsb */
/**************************/
static C_INLINE marpaWrapperBool_t _xml_1_1_buildSymbolsb(xml_1_1_t *xml_1_1p) {
  return _xml_1_1_buildSymbols_withStartb(xml_1_1p, xml_1_1_document);
}

/**************************/
/* _xml_1_1_buildSymbols_withStartb */
/**************************/
static C_INLINE marpaWrapperBool_t _xml_1_1_buildSymbols_withStartb(xml_1_1_t *xml_1_1p, int starti) {
  int                        i;
  marpaWrapperSymbolOption_t marpaWrapperSymbolOption;

  xml_1_1p->marpaWrapperSymbolArrayp = malloc(XML_1_1_SYMBOL_MAX * sizeof(marpaWrapperSymbol_t *));
  if (xml_1_1p->marpaWrapperSymbolArrayp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }
  xml_1_1p->marpaWrapperSymbolArrayLengthi = XML_1_1_SYMBOL_MAX;

  for (i = 0; i < XML_1_1_SYMBOL_MAX; i++) {

    /* Fill default options */
    if (marpaWrapper_symbolOptionDefaultb(&marpaWrapperSymbolOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }

    /* Opaque data associated to symbol will be the symbol enum */
    marpaWrapperSymbolOption.datavp = (void *) i;

    /* Optional, but we can make ourself the terminals */
    marpaWrapperSymbolOption.terminalb = (i <= XML_1_1_TERMINAL_MAX) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;

    /* Start rule ? */
    marpaWrapperSymbolOption.startb = (i == starti) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;

    /* Create the symbol */
    xml_1_1p->marpaWrapperSymbolArrayp[i] = marpaWrapper_g_addSymbolp(xml_1_1p->marpaWrapperp, &marpaWrapperSymbolOption);
    if (xml_1_1p->marpaWrapperSymbolArrayp[i] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }

  }

  return MARPAWRAPPER_BOOL_TRUE;
}

/************************/
/* _xml_1_1_buildRulesb */
/************************/
static C_INLINE marpaWrapperBool_t _xml_1_1_buildRulesb(xml_1_1_t *xml_1_1p) {
  marpaWrapperRuleOption_t   marpaWrapperRuleOption;

  xml_1_1p->marpaWrapperRuleArrayp = malloc(XML_1_1_RULE_MAX * sizeof(marpaWrapperRule_t *));
  if (xml_1_1p->marpaWrapperRuleArrayp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }
  xml_1_1p->marpaWrapperRuleArrayLengthi = XML_1_1_RULE_MAX;

  {
    /* [xml_1_1_Misc_any_001] Misc_any ::= Misc * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Misc]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_Misc_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Misc_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Misc_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Misc_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen002_001] _Gen002 ::= prolog element Misc_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_prolog],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_element],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Misc_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen002_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen002];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen002_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen002_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Char_any_001] Char_any ::= Char * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Char]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_Char_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Char_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Char_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Char_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen004_001] _Gen004 ::= Char_any RestrictedChar Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Char_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_RestrictedChar],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen004_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen004];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen004_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen004_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen005_001] _Gen005 ::= _Exclusion001  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Exclusion001]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen005_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen005];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen005_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen005_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_document_001] document ::= _Gen005  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen005]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_document_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_document];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_document_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_document_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Char_001] Char ::= _Lex001  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex001]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_Char_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Char];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Char_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Char_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Char_002] Char ::= _Lex002  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex002]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_Char_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Char];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Char_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Char_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Char_003] Char ::= _Lex003  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex003]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_Char_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Char];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Char_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Char_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_RestrictedChar_001] RestrictedChar ::= _Lex004  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex004]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_RestrictedChar_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_RestrictedChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_RestrictedChar_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_RestrictedChar_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_RestrictedChar_002] RestrictedChar ::= _Lex005  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex005]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_RestrictedChar_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_RestrictedChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_RestrictedChar_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_RestrictedChar_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_RestrictedChar_003] RestrictedChar ::= _Lex006  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex006]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_RestrictedChar_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_RestrictedChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_RestrictedChar_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_RestrictedChar_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_RestrictedChar_004] RestrictedChar ::= _Lex007  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex007]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_RestrictedChar_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_RestrictedChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_RestrictedChar_004] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_RestrictedChar_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_RestrictedChar_005] RestrictedChar ::= _Lex008  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex008]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_RestrictedChar_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_RestrictedChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_RestrictedChar_005] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_RestrictedChar_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen015_001] _Gen015 ::= _Lex009  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex009]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen015_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen015];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen015_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen015_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen015_002] _Gen015 ::= _Lex010  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex010]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen015_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen015];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen015_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen015_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen015_003] _Gen015 ::= _Lex011  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex011]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen015_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen015];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen015_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen015_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen015_004] _Gen015 ::= _Lex012  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex012]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen015_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen015];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen015_004] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen015_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen015_many_001] _Gen015_many ::= _Gen015 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen015]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen015_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen015_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen015_many_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen015_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_S_001] S ::= _Gen015_many  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen015_many]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_S_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_S_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_S_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NameStartChar_001] NameStartChar ::= _Lex013  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex013]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NameStartChar_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NameStartChar_002] NameStartChar ::= _Lex014  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex014]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NameStartChar_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NameStartChar_003] NameStartChar ::= _Lex015  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex015]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NameStartChar_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NameStartChar_004] NameStartChar ::= _Lex016  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex016]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NameStartChar_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_004] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NameStartChar_005] NameStartChar ::= _Lex017  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex017]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NameStartChar_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_005] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NameStartChar_006] NameStartChar ::= _Lex018  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex018]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NameStartChar_006;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_006] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_006] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NameStartChar_007] NameStartChar ::= _Lex019  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex019]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NameStartChar_007;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_007] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_007] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NameStartChar_008] NameStartChar ::= _Lex020  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex020]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NameStartChar_008;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_008] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_008] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NameStartChar_009] NameStartChar ::= _Lex021  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex021]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NameStartChar_009;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_009] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_009] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NameStartChar_010] NameStartChar ::= _Lex022  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex022]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NameStartChar_010;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_010] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_010] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NameStartChar_011] NameStartChar ::= _Lex023  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex023]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NameStartChar_011;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_011] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_011] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NameStartChar_012] NameStartChar ::= _Lex024  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex024]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NameStartChar_012;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_012] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_012] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NameStartChar_013] NameStartChar ::= _Lex025  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex025]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NameStartChar_013;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_013] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_013] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NameStartChar_014] NameStartChar ::= _Lex026  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex026]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NameStartChar_014;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_014] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_014] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NameStartChar_015] NameStartChar ::= _Lex027  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex027]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NameStartChar_015;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_015] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_015] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NameStartChar_016] NameStartChar ::= _Lex028  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex028]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NameStartChar_016;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_016] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameStartChar_016] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NameChar_001] NameChar ::= NameStartChar  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameStartChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NameChar_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameChar_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameChar_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NameChar_002] NameChar ::= _Lex029  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex029]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NameChar_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameChar_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameChar_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NameChar_003] NameChar ::= _Lex030  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex030]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NameChar_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameChar_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameChar_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NameChar_004] NameChar ::= _Lex031  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex031]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NameChar_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameChar_004] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameChar_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NameChar_005] NameChar ::= _Lex032  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex032]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NameChar_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameChar_005] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameChar_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NameChar_006] NameChar ::= _Lex033  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex033]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NameChar_006;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameChar_006] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameChar_006] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NameChar_007] NameChar ::= _Lex034  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex034]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NameChar_007;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameChar_007] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NameChar_007] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen044_001] _Gen044 ::= NameChar  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen044_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen044];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen044_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen044_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen044_any_001] _Gen044_any ::= _Gen044 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen044]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen044_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen044_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen044_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen044_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Name_001] Name ::= NameStartChar _Gen044_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameStartChar],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen044_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_Name_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Name_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Name_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen047_001] _Gen047 ::= _Lex009 Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex009],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen047_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen047];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen047_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen047_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen047_any_001] _Gen047_any ::= _Gen047 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen047]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen047_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen047_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen047_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen047_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Names_001] Names ::= Name _Gen047_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen047_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_Names_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Names];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Names_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Names_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen050_001] _Gen050 ::= NameChar  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen050_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen050];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen050_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen050_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen050_many_001] _Gen050_many ::= _Gen050 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen050]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen050_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen050_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen050_many_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen050_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Nmtoken_001] Nmtoken ::= _Gen050_many  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen050_many]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_Nmtoken_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Nmtoken];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Nmtoken_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Nmtoken_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen053_001] _Gen053 ::= _Lex009 Nmtoken  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex009],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Nmtoken]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen053_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen053];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen053_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen053_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen053_any_001] _Gen053_any ::= _Gen053 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen053]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen053_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen053_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen053_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen053_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Nmtokens_001] Nmtokens ::= Nmtoken _Gen053_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Nmtoken],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen053_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_Nmtokens_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Nmtokens];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Nmtokens_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Nmtokens_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen056_001] _Gen056 ::= _Lex036  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex036]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen056_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen056];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen056_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen056_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen056_002] _Gen056 ::= PEReference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PEReference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen056_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen056];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen056_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen056_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen056_003] _Gen056 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen056_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen056];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen056_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen056_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen056_any_001] _Gen056_any ::= _Gen056 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen056]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen056_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen056_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen056_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen056_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen060_001] _Gen060 ::= _Lex038  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex038]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen060_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen060];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen060_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen060_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen060_002] _Gen060 ::= PEReference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PEReference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen060_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen060];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen060_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen060_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen060_003] _Gen060 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen060_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen060];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen060_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen060_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen060_any_001] _Gen060_any ::= _Gen060 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen060]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen060_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen060_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen060_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen060_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_EntityValue_001] EntityValue ::= _Lex035 _Gen056_any _Lex035  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex035],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen056_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex035]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_EntityValue_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EntityValue];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EntityValue_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EntityValue_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_EntityValue_002] EntityValue ::= _Lex037 _Gen060_any _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex037],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen060_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex037]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_EntityValue_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EntityValue];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EntityValue_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EntityValue_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen066_001] _Gen066 ::= _Lex039  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex039]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen066_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen066];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen066_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen066_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen066_002] _Gen066 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen066_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen066];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen066_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen066_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen066_any_001] _Gen066_any ::= _Gen066 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen066]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen066_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen066_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen066_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen066_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen069_001] _Gen069 ::= _Lex040  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex040]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen069_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen069];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen069_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen069_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen069_002] _Gen069 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen069_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen069];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen069_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen069_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen069_any_001] _Gen069_any ::= _Gen069 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen069]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen069_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen069_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen069_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen069_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_AttValue_001] AttValue ::= _Lex035 _Gen066_any _Lex035  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex035],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen066_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex035]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_AttValue_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_AttValue];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_AttValue_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_AttValue_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_AttValue_002] AttValue ::= _Lex037 _Gen069_any _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex037],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen069_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex037]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_AttValue_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_AttValue];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_AttValue_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_AttValue_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Lex041_any_001] _Lex041_any ::= _Lex041 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex041]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Lex041_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex041_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Lex041_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Lex041_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen075_001] _Gen075 ::= _Lex035 _Lex041_any _Lex035  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex035],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex041_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex035]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen075_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen075];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen075_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen075_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Lex042_any_001] _Lex042_any ::= _Lex042 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex042]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Lex042_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex042_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Lex042_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Lex042_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen077_001] _Gen077 ::= _Lex037 _Lex042_any _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex037],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex042_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex037]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen077_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen077];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen077_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen077_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_SystemLiteral_001] SystemLiteral ::= _Gen075  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen075]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_SystemLiteral_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_SystemLiteral];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_SystemLiteral_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_SystemLiteral_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_SystemLiteral_002] SystemLiteral ::= _Gen077  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen077]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_SystemLiteral_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_SystemLiteral];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_SystemLiteral_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_SystemLiteral_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_PubidChar_any_001] PubidChar_any ::= PubidChar * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PubidChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_PubidChar_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PubidChar_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PubidChar_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PubidChar_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen081_001] _Gen081 ::= _Exclusion002  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Exclusion002]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen081_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen081];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen081_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen081_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen082_001] _Gen082 ::= _Gen081  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen081]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen082_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen082];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen082_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen082_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen082_any_001] _Gen082_any ::= _Gen082 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen082]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen082_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen082_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen082_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen082_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_PubidLiteral_001] PubidLiteral ::= _Lex035 PubidChar_any _Lex035  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex035],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PubidChar_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex035]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_PubidLiteral_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PubidLiteral];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PubidLiteral_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PubidLiteral_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_PubidLiteral_002] PubidLiteral ::= _Lex037 _Gen082_any _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex037],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen082_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex037]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_PubidLiteral_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PubidLiteral];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PubidLiteral_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PubidLiteral_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_PubidChar_001] PubidChar ::= _Lex009  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex009]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_PubidChar_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PubidChar_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PubidChar_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_PubidChar_002] PubidChar ::= _Lex011  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex011]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_PubidChar_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PubidChar_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PubidChar_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_PubidChar_003] PubidChar ::= _Lex012  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex012]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_PubidChar_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PubidChar_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PubidChar_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_PubidChar_004] PubidChar ::= _Lex043  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex043]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_PubidChar_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PubidChar_004] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PubidChar_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_PubidChar_005] PubidChar ::= _Lex044  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex044]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_PubidChar_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PubidChar_005] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PubidChar_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Lex045_any_001] _Lex045_any ::= _Lex045 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex045]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Lex045_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex045_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Lex045_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Lex045_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen092_001] _Gen092 ::= _Lex045_any _Lex046 _Lex045_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex045_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex046],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex045_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen092_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen092];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen092_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen092_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen093_001] _Gen093 ::= _Exclusion003  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Exclusion003]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen093_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen093];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen093_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen093_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_CharData_001] CharData ::= _Gen093  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen093]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_CharData_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_CharData];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_CharData_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_CharData_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen095_001] _Gen095 ::= _Exclusion004  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Exclusion004]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen095_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen095];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen095_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen095_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen096_001] _Gen096 ::= _Gen095  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen095]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen096_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen096];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen096_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen096_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen097_001] _Gen097 ::= _Exclusion004  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Exclusion004]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen097_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen097];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen097_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen097_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen098_001] _Gen098 ::= _Gen097  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen097]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen098_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen098];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen098_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen098_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen099_001] _Gen099 ::= _Lex029 _Gen098  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex029],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen098]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen099_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen099];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen099_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen099_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen100_001] _Gen100 ::= _Gen096  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen096]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen100_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen100];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen100_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen100_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen100_002] _Gen100 ::= _Gen099  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen099]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen100_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen100];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen100_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen100_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen100_any_001] _Gen100_any ::= _Gen100 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen100]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen100_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen100_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen100_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen100_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Comment_001] Comment ::= _Lex047 _Gen100_any _Lex048  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex047],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen100_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex048]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_Comment_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Comment];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Comment_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Comment_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen104_001] _Gen104 ::= Char_any _Lex050 Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Char_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex050],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen104_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen104];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen104_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen104_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen105_001] _Gen105 ::= _Exclusion005  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Exclusion005]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen105_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen105];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen105_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen105_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen106_001] _Gen106 ::= _Gen105  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen105]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen106_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen106];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen106_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen106_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen107_001] _Gen107 ::= S _Gen106  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen106]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen107_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen107];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen107_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen107_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen107_maybe_001] _Gen107_maybe ::= _Gen107  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen107]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen107_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen107_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen107_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen107_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen107_maybe_002] _Gen107_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen107_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen107_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen107_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen107_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_PI_001] PI ::= _Lex049 PITarget _Gen107_maybe _Lex050  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex049],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PITarget],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen107_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex050]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_PI_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PI];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PI_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PI_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen111_001] _Gen111 ::= _Lex051  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex051]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen111_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen111];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen111_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen111_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen111_002] _Gen111 ::= _Lex052  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex052]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen111_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen111];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen111_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen111_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen113_001] _Gen113 ::= _Lex053  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex053]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen113_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen113];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen113_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen113_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen113_002] _Gen113 ::= _Lex054  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex054]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen113_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen113];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen113_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen113_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen115_001] _Gen115 ::= _Lex055  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex055]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen115_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen115];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen115_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen115_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen115_002] _Gen115 ::= _Lex056  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex056]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen115_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen115];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen115_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen115_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen117_001] _Gen117 ::= _Gen111 _Gen113 _Gen115  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen111],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen113],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen115]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen117_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen117];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen117_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen117_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen118_001] _Gen118 ::= _Exclusion006  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Exclusion006]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen118_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen118];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen118_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen118_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_PITarget_001] PITarget ::= _Gen118  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen118]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_PITarget_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PITarget];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PITarget_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PITarget_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_CDSect_001] CDSect ::= CDStart CData CDEnd  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_CDStart],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_CData],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_CDEnd]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_CDSect_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_CDSect];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_CDSect_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_CDSect_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_CDStart_001] CDStart ::= _Lex057  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex057]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_CDStart_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_CDStart];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_CDStart_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_CDStart_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen122_001] _Gen122 ::= Char_any _Lex046 Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Char_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex046],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen122_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen122];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen122_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen122_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen123_001] _Gen123 ::= _Exclusion007  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Exclusion007]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen123_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen123];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen123_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen123_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen124_001] _Gen124 ::= _Gen123  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen123]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen124_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen124];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen124_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen124_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_CData_001] CData ::= _Gen124  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen124]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_CData_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_CData];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_CData_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_CData_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_CDEnd_001] CDEnd ::= _Lex046  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex046]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_CDEnd_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_CDEnd];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_CDEnd_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_CDEnd_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen127_001] _Gen127 ::= doctypedecl Misc_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_doctypedecl],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Misc_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen127_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen127];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen127_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen127_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen127_maybe_001] _Gen127_maybe ::= _Gen127  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen127]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen127_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen127_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen127_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen127_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen127_maybe_002] _Gen127_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen127_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen127_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen127_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen127_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_prolog_001] prolog ::= XMLDecl Misc_any _Gen127_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_XMLDecl],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Misc_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen127_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_prolog_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_prolog];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_prolog_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_prolog_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_EncodingDecl_maybe_001] EncodingDecl_maybe ::= EncodingDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EncodingDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_EncodingDecl_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EncodingDecl_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EncodingDecl_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EncodingDecl_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_EncodingDecl_maybe_002] EncodingDecl_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_EncodingDecl_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EncodingDecl_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EncodingDecl_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EncodingDecl_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_SDDecl_maybe_001] SDDecl_maybe ::= SDDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_SDDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_SDDecl_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_SDDecl_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_SDDecl_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_SDDecl_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_SDDecl_maybe_002] SDDecl_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_SDDecl_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_SDDecl_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_SDDecl_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_SDDecl_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_S_maybe_001] S_maybe ::= S  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_S_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_S_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_S_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_S_maybe_002] S_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_S_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_S_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_S_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_XMLDecl_001] XMLDecl ::= _Lex058 VersionInfo EncodingDecl_maybe SDDecl_maybe S_maybe _Lex050  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex058],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_VersionInfo],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EncodingDecl_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_SDDecl_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex050]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_XMLDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_XMLDecl];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_XMLDecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_XMLDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen138_001] _Gen138 ::= _Lex037 VersionNum _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex037],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_VersionNum],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex037]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen138_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen138];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen138_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen138_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen138_002] _Gen138 ::= _Lex035 VersionNum _Lex035  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex035],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_VersionNum],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex035]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen138_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen138];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen138_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen138_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_VersionInfo_001] VersionInfo ::= S _Lex059 Eq _Gen138  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex059],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Eq],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen138]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_VersionInfo_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_VersionInfo];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_VersionInfo_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_VersionInfo_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Eq_001] Eq ::= S_maybe _Lex060 S_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex060],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_Eq_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Eq];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Eq_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Eq_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_VersionNum_001] VersionNum ::= _Lex061  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex061]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_VersionNum_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_VersionNum];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_VersionNum_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_VersionNum_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Misc_001] Misc ::= Comment  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Comment]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_Misc_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Misc];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Misc_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Misc_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Misc_002] Misc ::= PI  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PI]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_Misc_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Misc];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Misc_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Misc_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Misc_003] Misc ::= S  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_Misc_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Misc];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Misc_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Misc_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen146_001] _Gen146 ::= S ExternalID  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_ExternalID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen146_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen146];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen146_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen146_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen146_maybe_001] _Gen146_maybe ::= _Gen146  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen146]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen146_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen146_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen146_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen146_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen146_maybe_002] _Gen146_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen146_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen146_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen146_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen146_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen149_001] _Gen149 ::= _Lex063 intSubset _Lex064 S_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex063],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_intSubset],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex064],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen149_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen149];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen149_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen149_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen149_maybe_001] _Gen149_maybe ::= _Gen149  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen149]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen149_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen149_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen149_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen149_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen149_maybe_002] _Gen149_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen149_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen149_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen149_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen149_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_doctypedecl_001] doctypedecl ::= _Lex062 S Name _Gen146_maybe S_maybe _Gen149_maybe _Lex065  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex062],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen146_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen149_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex065]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_doctypedecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_doctypedecl];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_doctypedecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_doctypedecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_DeclSep_001] DeclSep ::= PEReference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PEReference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_DeclSep_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_DeclSep];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_DeclSep_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_DeclSep_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_DeclSep_002] DeclSep ::= S  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_DeclSep_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_DeclSep];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_DeclSep_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_DeclSep_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen155_001] _Gen155 ::= markupdecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_markupdecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen155_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen155];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen155_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen155_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen155_002] _Gen155 ::= DeclSep  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_DeclSep]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen155_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen155];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen155_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen155_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen155_any_001] _Gen155_any ::= _Gen155 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen155]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen155_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen155_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen155_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen155_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_intSubset_001] intSubset ::= _Gen155_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen155_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_intSubset_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_intSubset];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_intSubset_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_intSubset_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_markupdecl_001] markupdecl ::= elementdecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_elementdecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_markupdecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_markupdecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_markupdecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_markupdecl_002] markupdecl ::= AttlistDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_AttlistDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_markupdecl_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_markupdecl_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_markupdecl_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_markupdecl_003] markupdecl ::= EntityDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EntityDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_markupdecl_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_markupdecl_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_markupdecl_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_markupdecl_004] markupdecl ::= NotationDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NotationDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_markupdecl_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_markupdecl_004] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_markupdecl_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_markupdecl_005] markupdecl ::= PI  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PI]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_markupdecl_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_markupdecl_005] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_markupdecl_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_markupdecl_006] markupdecl ::= Comment  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Comment]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_markupdecl_006;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_markupdecl_006] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_markupdecl_006] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_TextDecl_maybe_001] TextDecl_maybe ::= TextDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_TextDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_TextDecl_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_TextDecl_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_TextDecl_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_TextDecl_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_TextDecl_maybe_002] TextDecl_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_TextDecl_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_TextDecl_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_TextDecl_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_TextDecl_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_extSubset_001] extSubset ::= TextDecl_maybe extSubsetDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_TextDecl_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_extSubsetDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_extSubset_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_extSubset];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_extSubset_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_extSubset_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen168_001] _Gen168 ::= markupdecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_markupdecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen168_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen168];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen168_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen168_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen168_002] _Gen168 ::= conditionalSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_conditionalSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen168_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen168];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen168_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen168_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen168_003] _Gen168 ::= DeclSep  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_DeclSep]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen168_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen168];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen168_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen168_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen168_any_001] _Gen168_any ::= _Gen168 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen168]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen168_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen168_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen168_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen168_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_extSubsetDecl_001] extSubsetDecl ::= _Gen168_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen168_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_extSubsetDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_extSubsetDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_extSubsetDecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_extSubsetDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen173_001] _Gen173 ::= _Lex067  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex067]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen173_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen173];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen173_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen173_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen173_002] _Gen173 ::= _Lex068  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex068]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen173_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen173];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen173_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen173_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen175_001] _Gen175 ::= _Lex037 _Gen173 _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex037],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen173],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex037]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen175_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen175];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen175_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen175_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen176_001] _Gen176 ::= _Lex067  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex067]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen176_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen176];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen176_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen176_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen176_002] _Gen176 ::= _Lex068  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex068]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen176_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen176];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen176_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen176_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen178_001] _Gen178 ::= _Lex035 _Gen176 _Lex035  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex035],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen176],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex035]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen178_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen178];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen178_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen178_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen179_001] _Gen179 ::= _Gen175  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen175]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen179_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen179];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen179_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen179_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen179_002] _Gen179 ::= _Gen178  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen178]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen179_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen179];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen179_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen179_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_SDDecl_001] SDDecl ::= S _Lex066 Eq _Gen179  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex066],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Eq],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen179]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_SDDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_SDDecl];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_SDDecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_SDDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_element_001] element ::= EmptyElemTag  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EmptyElemTag]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_element_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_element];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_element_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_element_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_element_002] element ::= STag content ETag  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_STag],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_content],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_ETag]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_element_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_element];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_element_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_element_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen184_001] _Gen184 ::= S Attribute  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Attribute]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen184_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen184];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen184_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen184_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen184_any_001] _Gen184_any ::= _Gen184 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen184]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen184_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen184_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen184_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen184_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_STag_001] STag ::= _Lex069 Name _Gen184_any S_maybe _Lex065  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex069],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen184_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex065]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_STag_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_STag];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_STag_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_STag_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Attribute_001] Attribute ::= Name Eq AttValue  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Eq],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_AttValue]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_Attribute_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Attribute];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Attribute_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Attribute_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_ETag_001] ETag ::= _Lex070 Name S_maybe _Lex065  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex070],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex065]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_ETag_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_ETag];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_ETag_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_ETag_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_CharData_maybe_001] CharData_maybe ::= CharData  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_CharData]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_CharData_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_CharData_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_CharData_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_CharData_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_CharData_maybe_002] CharData_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_CharData_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_CharData_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_CharData_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_CharData_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen191_001] _Gen191 ::= element  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_element]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen191_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen191];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen191_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen191_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen191_002] _Gen191 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen191_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen191];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen191_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen191_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen191_003] _Gen191 ::= CDSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_CDSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen191_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen191];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen191_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen191_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen191_004] _Gen191 ::= PI  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PI]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen191_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen191];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen191_004] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen191_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen191_005] _Gen191 ::= Comment  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Comment]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen191_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen191];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen191_005] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen191_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen196_001] _Gen196 ::= _Gen191 CharData_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen191],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_CharData_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen196_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen196];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen196_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen196_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen196_any_001] _Gen196_any ::= _Gen196 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen196]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen196_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen196_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen196_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen196_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_content_001] content ::= CharData_maybe _Gen196_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_CharData_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen196_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_content_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_content];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_content_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_content_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen199_001] _Gen199 ::= S Attribute  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Attribute]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen199_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen199];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen199_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen199_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen199_any_001] _Gen199_any ::= _Gen199 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen199]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen199_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen199_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen199_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen199_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_EmptyElemTag_001] EmptyElemTag ::= _Lex069 Name _Gen199_any S_maybe _Lex071  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex069],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen199_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex071]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_EmptyElemTag_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EmptyElemTag];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EmptyElemTag_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EmptyElemTag_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_elementdecl_001] elementdecl ::= _Lex072 S Name S contentspec S_maybe _Lex065  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex072],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_contentspec],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex065]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_elementdecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_elementdecl];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_elementdecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_elementdecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_contentspec_001] contentspec ::= _Lex073  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex073]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_contentspec_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_contentspec];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_contentspec_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_contentspec_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_contentspec_002] contentspec ::= _Lex074  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex074]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_contentspec_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_contentspec];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_contentspec_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_contentspec_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_contentspec_003] contentspec ::= Mixed  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Mixed]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_contentspec_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_contentspec];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_contentspec_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_contentspec_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_contentspec_004] contentspec ::= children  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_children]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_contentspec_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_contentspec];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_contentspec_004] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_contentspec_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen207_001] _Gen207 ::= choice  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_choice]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen207_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen207];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen207_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen207_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen207_002] _Gen207 ::= seq  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_seq]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen207_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen207];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen207_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen207_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen209_001] _Gen209 ::= _Lex075  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex075]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen209_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen209];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen209_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen209_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen209_002] _Gen209 ::= _Lex076  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex076]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen209_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen209];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen209_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen209_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen209_003] _Gen209 ::= _Lex077  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex077]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen209_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen209];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen209_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen209_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen209_maybe_001] _Gen209_maybe ::= _Gen209  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen209]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen209_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen209_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen209_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen209_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen209_maybe_002] _Gen209_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen209_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen209_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen209_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen209_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_children_001] children ::= _Gen207 _Gen209_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen207],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen209_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_children_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_children];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_children_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_children_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen215_001] _Gen215 ::= Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen215_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen215];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen215_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen215_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen215_002] _Gen215 ::= choice  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_choice]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen215_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen215];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen215_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen215_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen215_003] _Gen215 ::= seq  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_seq]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen215_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen215];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen215_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen215_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen218_001] _Gen218 ::= _Lex075  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex075]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen218_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen218];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen218_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen218_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen218_002] _Gen218 ::= _Lex076  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex076]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen218_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen218];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen218_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen218_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen218_003] _Gen218 ::= _Lex077  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex077]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen218_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen218];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen218_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen218_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen218_maybe_001] _Gen218_maybe ::= _Gen218  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen218]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen218_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen218_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen218_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen218_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen218_maybe_002] _Gen218_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen218_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen218_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen218_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen218_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_cp_001] cp ::= _Gen215 _Gen218_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen215],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen218_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_cp_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_cp];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_cp_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_cp_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen224_001] _Gen224 ::= S_maybe _Lex079 S_maybe cp  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex079],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_cp]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen224_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen224];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen224_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen224_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen224_many_001] _Gen224_many ::= _Gen224 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen224]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen224_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen224_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen224_many_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen224_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_choice_001] choice ::= _Lex078 S_maybe cp _Gen224_many S_maybe _Lex080  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex078],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_cp],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen224_many],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex080]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_choice_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_choice];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_choice_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_choice_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen227_001] _Gen227 ::= S_maybe _Lex081 S_maybe cp  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex081],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_cp]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen227_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen227];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen227_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen227_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen227_any_001] _Gen227_any ::= _Gen227 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen227]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen227_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen227_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen227_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen227_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_seq_001] seq ::= _Lex078 S_maybe cp _Gen227_any S_maybe _Lex080  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex078],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_cp],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen227_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex080]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_seq_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_seq];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_seq_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_seq_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen230_001] _Gen230 ::= S_maybe _Lex079 S_maybe Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex079],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen230_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen230];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen230_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen230_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen230_any_001] _Gen230_any ::= _Gen230 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen230]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen230_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen230_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen230_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen230_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Mixed_001] Mixed ::= _Lex078 S_maybe _Lex082 _Gen230_any S_maybe _Lex083  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex078],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex082],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen230_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex083]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_Mixed_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Mixed];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Mixed_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Mixed_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Mixed_002] Mixed ::= _Lex078 S_maybe _Lex082 S_maybe _Lex080  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex078],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex082],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex080]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_Mixed_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Mixed];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Mixed_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Mixed_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_AttDef_any_001] AttDef_any ::= AttDef * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_AttDef]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_AttDef_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_AttDef_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_AttDef_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_AttDef_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_AttlistDecl_001] AttlistDecl ::= _Lex084 S Name AttDef_any S_maybe _Lex065  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex084],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_AttDef_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex065]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_AttlistDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_AttlistDecl];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_AttlistDecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_AttlistDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_AttDef_001] AttDef ::= S Name S AttType S DefaultDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_AttType],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_DefaultDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_AttDef_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_AttDef];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_AttDef_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_AttDef_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_AttType_001] AttType ::= StringType  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_StringType]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_AttType_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_AttType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_AttType_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_AttType_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_AttType_002] AttType ::= TokenizedType  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_TokenizedType]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_AttType_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_AttType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_AttType_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_AttType_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_AttType_003] AttType ::= EnumeratedType  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EnumeratedType]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_AttType_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_AttType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_AttType_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_AttType_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_StringType_001] StringType ::= _Lex085  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex085]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_StringType_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_StringType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_StringType_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_StringType_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_TokenizedType_001] TokenizedType ::= _Lex086  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex086]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_TokenizedType_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_TokenizedType_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_TokenizedType_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_TokenizedType_002] TokenizedType ::= _Lex087  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex087]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_TokenizedType_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_TokenizedType_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_TokenizedType_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_TokenizedType_003] TokenizedType ::= _Lex088  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex088]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_TokenizedType_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_TokenizedType_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_TokenizedType_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_TokenizedType_004] TokenizedType ::= _Lex089  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex089]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_TokenizedType_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_TokenizedType_004] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_TokenizedType_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_TokenizedType_005] TokenizedType ::= _Lex090  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex090]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_TokenizedType_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_TokenizedType_005] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_TokenizedType_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_TokenizedType_006] TokenizedType ::= _Lex091  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex091]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_TokenizedType_006;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_TokenizedType_006] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_TokenizedType_006] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_TokenizedType_007] TokenizedType ::= _Lex092  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex092]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_TokenizedType_007;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_TokenizedType_007] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_TokenizedType_007] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_EnumeratedType_001] EnumeratedType ::= NotationType  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NotationType]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_EnumeratedType_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EnumeratedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EnumeratedType_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EnumeratedType_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_EnumeratedType_002] EnumeratedType ::= Enumeration  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Enumeration]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_EnumeratedType_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EnumeratedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EnumeratedType_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EnumeratedType_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen250_001] _Gen250 ::= S_maybe _Lex079 S_maybe Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex079],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen250_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen250];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen250_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen250_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen250_any_001] _Gen250_any ::= _Gen250 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen250]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen250_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen250_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen250_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen250_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NotationType_001] NotationType ::= _Lex093 S _Lex078 S_maybe Name _Gen250_any S_maybe _Lex080  */
    marpaWrapperSymbol_t *rhsSymbolpp[8] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex093],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex078],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen250_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex080]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NotationType_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NotationType];
    marpaWrapperRuleOption.nRhsSymboli = 8;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NotationType_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NotationType_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen253_001] _Gen253 ::= S_maybe _Lex079 S_maybe Nmtoken  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex079],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Nmtoken]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen253_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen253];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen253_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen253_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen253_any_001] _Gen253_any ::= _Gen253 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen253]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen253_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen253_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen253_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen253_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Enumeration_001] Enumeration ::= _Lex078 S_maybe Nmtoken _Gen253_any S_maybe _Lex080  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex078],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Nmtoken],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen253_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex080]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_Enumeration_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Enumeration];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Enumeration_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Enumeration_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen256_001] _Gen256 ::= _Lex096 S  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex096],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen256_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen256];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen256_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen256_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen256_maybe_001] _Gen256_maybe ::= _Gen256  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen256]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen256_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen256_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen256_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen256_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen256_maybe_002] _Gen256_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen256_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen256_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen256_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen256_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen259_001] _Gen259 ::= _Gen256_maybe AttValue  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen256_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_AttValue]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen259_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen259];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen259_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen259_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_DefaultDecl_001] DefaultDecl ::= _Lex094  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex094]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_DefaultDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_DefaultDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_DefaultDecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_DefaultDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_DefaultDecl_002] DefaultDecl ::= _Lex095  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex095]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_DefaultDecl_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_DefaultDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_DefaultDecl_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_DefaultDecl_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_DefaultDecl_003] DefaultDecl ::= _Gen259  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen259]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_DefaultDecl_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_DefaultDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_DefaultDecl_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_DefaultDecl_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_conditionalSect_001] conditionalSect ::= includeSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_includeSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_conditionalSect_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_conditionalSect];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_conditionalSect_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_conditionalSect_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_conditionalSect_002] conditionalSect ::= ignoreSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_ignoreSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_conditionalSect_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_conditionalSect];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_conditionalSect_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_conditionalSect_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_includeSect_001] includeSect ::= _Lex097 S_maybe _Lex098 S_maybe _Lex063 extSubsetDecl _Lex046  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex097],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex098],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex063],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_extSubsetDecl],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex046]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_includeSect_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_includeSect];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_includeSect_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_includeSect_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_ignoreSectContents_any_001] ignoreSectContents_any ::= ignoreSectContents * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_ignoreSectContents]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_ignoreSectContents_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_ignoreSectContents_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_ignoreSectContents_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_ignoreSectContents_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_ignoreSect_001] ignoreSect ::= _Lex097 S_maybe _Lex099 S_maybe _Lex063 ignoreSectContents_any _Lex046  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex097],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex099],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex063],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_ignoreSectContents_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex046]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_ignoreSect_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_ignoreSect];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_ignoreSect_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_ignoreSect_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen268_001] _Gen268 ::= _Lex097 ignoreSectContents _Lex046 Ignore  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex097],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_ignoreSectContents],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex046],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Ignore]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen268_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen268];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen268_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen268_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen268_any_001] _Gen268_any ::= _Gen268 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen268]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen268_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen268_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen268_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen268_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_ignoreSectContents_001] ignoreSectContents ::= Ignore _Gen268_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Ignore],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen268_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_ignoreSectContents_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_ignoreSectContents];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_ignoreSectContents_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_ignoreSectContents_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen271_001] _Gen271 ::= _Lex097  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex097]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen271_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen271];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen271_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen271_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen271_002] _Gen271 ::= _Lex046  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex046]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen271_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen271];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen271_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen271_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen273_001] _Gen273 ::= Char_any _Gen271 Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Char_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen271],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen273_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen273];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen273_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen273_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen274_001] _Gen274 ::= _Exclusion008  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Exclusion008]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen274_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen274];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen274_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen274_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Ignore_001] Ignore ::= _Gen274  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen274]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_Ignore_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Ignore];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Ignore_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Ignore_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Lex031_many_001] _Lex031_many ::= _Lex031 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex031]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Lex031_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex031_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Lex031_many_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Lex031_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Lex103_many_001] _Lex103_many ::= _Lex103 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex103]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Lex103_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex103_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Lex103_many_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Lex103_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_CharRef_001] CharRef ::= _Lex100 _Lex031_many _Lex101  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex100],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex031_many],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex101]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_CharRef_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_CharRef];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_CharRef_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_CharRef_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_CharRef_002] CharRef ::= _Lex102 _Lex103_many _Lex101  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex102],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex103_many],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex101]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_CharRef_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_CharRef];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_CharRef_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_CharRef_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Reference_001] Reference ::= EntityRef  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EntityRef]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_Reference_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Reference];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Reference_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Reference_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Reference_002] Reference ::= CharRef  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_CharRef]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_Reference_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Reference];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Reference_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Reference_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_EntityRef_001] EntityRef ::= _Lex104 Name _Lex101  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex104],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex101]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_EntityRef_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EntityRef];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EntityRef_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EntityRef_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_PEReference_001] PEReference ::= _Lex105 Name _Lex101  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex105],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex101]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_PEReference_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PEReference];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PEReference_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PEReference_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_EntityDecl_001] EntityDecl ::= GEDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_GEDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_EntityDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EntityDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EntityDecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EntityDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_EntityDecl_002] EntityDecl ::= PEDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PEDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_EntityDecl_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EntityDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EntityDecl_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EntityDecl_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_GEDecl_001] GEDecl ::= _Lex106 S Name S EntityDef S_maybe _Lex065  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex106],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EntityDef],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex065]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_GEDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_GEDecl];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_GEDecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_GEDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_PEDecl_001] PEDecl ::= _Lex106 S _Lex105 S Name S PEDef S_maybe _Lex065  */
    marpaWrapperSymbol_t *rhsSymbolpp[9] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex106],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex105],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PEDef],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex065]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_PEDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PEDecl];
    marpaWrapperRuleOption.nRhsSymboli = 9;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PEDecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PEDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NDataDecl_maybe_001] NDataDecl_maybe ::= NDataDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NDataDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NDataDecl_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NDataDecl_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NDataDecl_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NDataDecl_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NDataDecl_maybe_002] NDataDecl_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NDataDecl_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NDataDecl_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NDataDecl_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NDataDecl_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen290_001] _Gen290 ::= ExternalID NDataDecl_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_ExternalID],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NDataDecl_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen290_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen290];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen290_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen290_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_EntityDef_001] EntityDef ::= EntityValue  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EntityValue]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_EntityDef_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EntityDef];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EntityDef_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EntityDef_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_EntityDef_002] EntityDef ::= _Gen290  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen290]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_EntityDef_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EntityDef];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EntityDef_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EntityDef_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_PEDef_001] PEDef ::= EntityValue  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EntityValue]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_PEDef_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PEDef];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PEDef_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PEDef_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_PEDef_002] PEDef ::= ExternalID  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_ExternalID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_PEDef_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PEDef];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PEDef_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PEDef_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_ExternalID_001] ExternalID ::= _Lex107 S SystemLiteral  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex107],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_SystemLiteral]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_ExternalID_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_ExternalID];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_ExternalID_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_ExternalID_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_ExternalID_002] ExternalID ::= _Lex108 S PubidLiteral S SystemLiteral  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex108],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PubidLiteral],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_SystemLiteral]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_ExternalID_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_ExternalID];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_ExternalID_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_ExternalID_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NDataDecl_001] NDataDecl ::= S _Lex109 S Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex109],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NDataDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NDataDecl];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NDataDecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NDataDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_VersionInfo_maybe_001] VersionInfo_maybe ::= VersionInfo  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_VersionInfo]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_VersionInfo_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_VersionInfo_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_VersionInfo_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_VersionInfo_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_VersionInfo_maybe_002] VersionInfo_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_VersionInfo_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_VersionInfo_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_VersionInfo_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_VersionInfo_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_TextDecl_001] TextDecl ::= _Lex058 VersionInfo_maybe EncodingDecl S_maybe _Lex050  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex058],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_VersionInfo_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EncodingDecl],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex050]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_TextDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_TextDecl];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_TextDecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_TextDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen301_001] _Gen301 ::= TextDecl_maybe content  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_TextDecl_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_content]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen301_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen301];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen301_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen301_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen302_001] _Gen302 ::= Char_any RestrictedChar Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Char_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_RestrictedChar],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen302_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen302];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen302_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen302_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen303_001] _Gen303 ::= _Exclusion009  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Exclusion009]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen303_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen303];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen303_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen303_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_extParsedEnt_001] extParsedEnt ::= _Gen303  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen303]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_extParsedEnt_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_extParsedEnt];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_extParsedEnt_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_extParsedEnt_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen305_001] _Gen305 ::= _Lex035 EncName _Lex035  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex035],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EncName],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex035]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen305_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen305];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen305_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen305_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen305_002] _Gen305 ::= _Lex037 EncName _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex037],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EncName],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex037]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen305_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen305];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen305_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen305_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_EncodingDecl_001] EncodingDecl ::= S _Lex110 Eq _Gen305  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex110],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Eq],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen305]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_EncodingDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EncodingDecl];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EncodingDecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EncodingDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen308_001] _Gen308 ::= _Lex112  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex112]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen308_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen308];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen308_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen308_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen308_002] _Gen308 ::= _Lex029  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex029]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen308_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen308];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen308_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen308_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen308_any_001] _Gen308_any ::= _Gen308 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen308]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen308_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen308_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen308_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen308_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_EncName_001] EncName ::= _Lex111 _Gen308_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex111],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen308_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_EncName_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EncName];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EncName_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_EncName_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen312_001] _Gen312 ::= ExternalID  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_ExternalID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen312_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen312];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen312_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen312_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen312_002] _Gen312 ::= PublicID  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PublicID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen312_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen312];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen312_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen312_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NotationDecl_001] NotationDecl ::= _Lex113 S Name S _Gen312 S_maybe _Lex065  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex113],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen312],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex065]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_NotationDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NotationDecl];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NotationDecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_NotationDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_PublicID_001] PublicID ::= _Lex108 S PubidLiteral  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex108],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PubidLiteral]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_PublicID_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PublicID];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PublicID_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PublicID_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
    return MARPAWRAPPER_BOOL_TRUE;
}

/************************/
/* _xml_1_1_pushLexemeb */
/************************/

static C_INLINE marpaWrapperBool_t _xml_1_1_pushLexemeb(xml_1_1_t *xml_1_1p, xml_1_1_symbol_t xml_1_1_symbol, signed int currenti, streamIn_t *streamInp) {
  marpaWrapperBool_t rcb;

  switch (xml_1_1_symbol) {
    case xml_1_1__Exclusion001:
      rcb = _xml_1_1__Exclusion001b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Exclusion002:
      rcb = _xml_1_1__Exclusion002b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Exclusion003:
      rcb = _xml_1_1__Exclusion003b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Exclusion004:
      rcb = _xml_1_1__Exclusion004b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Exclusion005:
      rcb = _xml_1_1__Exclusion005b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Exclusion006:
      rcb = _xml_1_1__Exclusion006b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Exclusion007:
      rcb = _xml_1_1__Exclusion007b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Exclusion008:
      rcb = _xml_1_1__Exclusion008b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Exclusion009:
      rcb = _xml_1_1__Exclusion009b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex001:
      rcb = _xml_1_1__Lex001b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex002:
      rcb = _xml_1_1__Lex002b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex003:
      rcb = _xml_1_1__Lex003b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex004:
      rcb = _xml_1_1__Lex004b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex005:
      rcb = _xml_1_1__Lex005b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex006:
      rcb = _xml_1_1__Lex006b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex007:
      rcb = _xml_1_1__Lex007b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex008:
      rcb = _xml_1_1__Lex008b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex009:
      rcb = _xml_1_1__Lex009b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex010:
      rcb = _xml_1_1__Lex010b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex011:
      rcb = _xml_1_1__Lex011b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex012:
      rcb = _xml_1_1__Lex012b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex013:
      rcb = _xml_1_1__Lex013b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex014:
      rcb = _xml_1_1__Lex014b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex015:
      rcb = _xml_1_1__Lex015b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex016:
      rcb = _xml_1_1__Lex016b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex017:
      rcb = _xml_1_1__Lex017b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex018:
      rcb = _xml_1_1__Lex018b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex019:
      rcb = _xml_1_1__Lex019b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex020:
      rcb = _xml_1_1__Lex020b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex021:
      rcb = _xml_1_1__Lex021b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex022:
      rcb = _xml_1_1__Lex022b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex023:
      rcb = _xml_1_1__Lex023b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex024:
      rcb = _xml_1_1__Lex024b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex025:
      rcb = _xml_1_1__Lex025b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex026:
      rcb = _xml_1_1__Lex026b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex027:
      rcb = _xml_1_1__Lex027b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex028:
      rcb = _xml_1_1__Lex028b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex029:
      rcb = _xml_1_1__Lex029b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex030:
      rcb = _xml_1_1__Lex030b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex031:
      rcb = _xml_1_1__Lex031b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex032:
      rcb = _xml_1_1__Lex032b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex033:
      rcb = _xml_1_1__Lex033b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex034:
      rcb = _xml_1_1__Lex034b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex035:
      rcb = _xml_1_1__Lex035b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex036:
      rcb = _xml_1_1__Lex036b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex037:
      rcb = _xml_1_1__Lex037b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex038:
      rcb = _xml_1_1__Lex038b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex039:
      rcb = _xml_1_1__Lex039b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex040:
      rcb = _xml_1_1__Lex040b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex041:
      rcb = _xml_1_1__Lex041b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex042:
      rcb = _xml_1_1__Lex042b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex043:
      rcb = _xml_1_1__Lex043b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex044:
      rcb = _xml_1_1__Lex044b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex045:
      rcb = _xml_1_1__Lex045b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex046:
      rcb = _xml_1_1__Lex046b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex047:
      rcb = _xml_1_1__Lex047b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex048:
      rcb = _xml_1_1__Lex048b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex049:
      rcb = _xml_1_1__Lex049b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex050:
      rcb = _xml_1_1__Lex050b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex051:
      rcb = _xml_1_1__Lex051b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex052:
      rcb = _xml_1_1__Lex052b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex053:
      rcb = _xml_1_1__Lex053b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex054:
      rcb = _xml_1_1__Lex054b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex055:
      rcb = _xml_1_1__Lex055b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex056:
      rcb = _xml_1_1__Lex056b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex057:
      rcb = _xml_1_1__Lex057b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex058:
      rcb = _xml_1_1__Lex058b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex059:
      rcb = _xml_1_1__Lex059b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex060:
      rcb = _xml_1_1__Lex060b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex061:
      rcb = _xml_1_1__Lex061b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex062:
      rcb = _xml_1_1__Lex062b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex063:
      rcb = _xml_1_1__Lex063b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex064:
      rcb = _xml_1_1__Lex064b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex065:
      rcb = _xml_1_1__Lex065b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex066:
      rcb = _xml_1_1__Lex066b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex067:
      rcb = _xml_1_1__Lex067b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex068:
      rcb = _xml_1_1__Lex068b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex069:
      rcb = _xml_1_1__Lex069b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex070:
      rcb = _xml_1_1__Lex070b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex071:
      rcb = _xml_1_1__Lex071b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex072:
      rcb = _xml_1_1__Lex072b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex073:
      rcb = _xml_1_1__Lex073b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex074:
      rcb = _xml_1_1__Lex074b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex075:
      rcb = _xml_1_1__Lex075b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex076:
      rcb = _xml_1_1__Lex076b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex077:
      rcb = _xml_1_1__Lex077b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex078:
      rcb = _xml_1_1__Lex078b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex079:
      rcb = _xml_1_1__Lex079b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex080:
      rcb = _xml_1_1__Lex080b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex081:
      rcb = _xml_1_1__Lex081b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex082:
      rcb = _xml_1_1__Lex082b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex083:
      rcb = _xml_1_1__Lex083b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex084:
      rcb = _xml_1_1__Lex084b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex085:
      rcb = _xml_1_1__Lex085b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex086:
      rcb = _xml_1_1__Lex086b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex087:
      rcb = _xml_1_1__Lex087b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex088:
      rcb = _xml_1_1__Lex088b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex089:
      rcb = _xml_1_1__Lex089b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex090:
      rcb = _xml_1_1__Lex090b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex091:
      rcb = _xml_1_1__Lex091b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex092:
      rcb = _xml_1_1__Lex092b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex093:
      rcb = _xml_1_1__Lex093b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex094:
      rcb = _xml_1_1__Lex094b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex095:
      rcb = _xml_1_1__Lex095b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex096:
      rcb = _xml_1_1__Lex096b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex097:
      rcb = _xml_1_1__Lex097b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex098:
      rcb = _xml_1_1__Lex098b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex099:
      rcb = _xml_1_1__Lex099b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex100:
      rcb = _xml_1_1__Lex100b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex101:
      rcb = _xml_1_1__Lex101b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex102:
      rcb = _xml_1_1__Lex102b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex103:
      rcb = _xml_1_1__Lex103b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex104:
      rcb = _xml_1_1__Lex104b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex105:
      rcb = _xml_1_1__Lex105b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex106:
      rcb = _xml_1_1__Lex106b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex107:
      rcb = _xml_1_1__Lex107b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex108:
      rcb = _xml_1_1__Lex108b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex109:
      rcb = _xml_1_1__Lex109b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex110:
      rcb = _xml_1_1__Lex110b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex111:
      rcb = _xml_1_1__Lex111b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex112:
      rcb = _xml_1_1__Lex112b(xml_1_1p, currenti, streamInp);
      break;
    case xml_1_1__Lex113:
      rcb = _xml_1_1__Lex113b(xml_1_1p, currenti, streamInp);
      break;
    default:
      rcb = MARPAWRAPPER_BOOL_FALSE;
      break;
  }

  return rcb;
}
/************************************************
  _Exclusion001 ~ '_Gen002 - _Gen004'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion001b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Exclusion002 ~ 'PubidChar - _Lex037'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion002b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Exclusion003 ~ '_Lex045_any - _Gen092'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion003b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Exclusion004 ~ 'Char - _Lex029'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion004b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Exclusion005 ~ 'Char_any - _Gen104'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion005b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Exclusion006 ~ 'Name - _Gen117'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion006b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Exclusion007 ~ 'Char_any - _Gen122'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion007b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Exclusion008 ~ 'Char_any - _Gen273'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion008b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Exclusion009 ~ '_Gen301 - _Gen302'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion009b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Lex001 ~ [\x{1}-\x{d7ff}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex001b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x1 && currenti <= 0xd7ff /* [#x1-#xd7ff] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex002 ~ [\x{e000}-\x{fffd}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex002b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0xe000 && currenti <= 0xfffd /* [#xe000-#xfffd] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex003 ~ [\x{10000}-\x{10ffff}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex003b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x10000 && currenti <= 0x10ffff /* [#x10000-#x10ffff] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex004 ~ [\x{1}-\x{8}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex004b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x1 && currenti <= 0x8 /* [#x1-#x8] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex005 ~ [\x{b}-\x{c}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex005b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0xb && currenti <= 0xc /* [#xb-#xc] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex006 ~ [\x{e}-\x{1f}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex006b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0xe && currenti <= 0x1f /* [#xe-#x1f] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex007 ~ [\x{7f}-\x{84}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex007b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x7f && currenti <= 0x84 /* [#x7f-#x84] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex008 ~ [\x{86}-\x{9f}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex008b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x86 && currenti <= 0x9f /* [#x86-#x9f] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex009 ~ [\x{20}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex009b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x20 /* #x20 */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex010 ~ [\x{9}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex010b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x9 /* #x9 */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex011 ~ [\x{d}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex011b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0xd /* #xd */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex012 ~ [\x{a}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex012b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0xa /* #xa */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex013 ~ ':'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex013b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x3a /* : */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex014 ~ [A-Z]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex014b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x41 && currenti <= 0x5a /* [A-Z] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex015 ~ '_'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex015b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x5f /* _ */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex016 ~ [a-z]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex016b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x61 && currenti <= 0x7a /* [a-z] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex017 ~ [\x{c0}-\x{d6}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex017b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0xc0 && currenti <= 0xd6 /* [#xc0-#xd6] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex018 ~ [\x{d8}-\x{f6}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex018b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0xd8 && currenti <= 0xf6 /* [#xd8-#xf6] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex019 ~ [\x{f8}-\x{2ff}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex019b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0xf8 && currenti <= 0x2ff /* [#xf8-#x2ff] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex020 ~ [\x{370}-\x{37d}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex020b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x370 && currenti <= 0x37d /* [#x370-#x37d] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex021 ~ [\x{37f}-\x{1fff}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex021b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x37f && currenti <= 0x1fff /* [#x37f-#x1fff] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex022 ~ [\x{200c}-\x{200d}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex022b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x200c && currenti <= 0x200d /* [#x200c-#x200d] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex023 ~ [\x{2070}-\x{218f}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex023b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x2070 && currenti <= 0x218f /* [#x2070-#x218f] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex024 ~ [\x{2c00}-\x{2fef}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex024b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x2c00 && currenti <= 0x2fef /* [#x2c00-#x2fef] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex025 ~ [\x{3001}-\x{d7ff}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex025b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x3001 && currenti <= 0xd7ff /* [#x3001-#xd7ff] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex026 ~ [\x{f900}-\x{fdcf}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex026b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0xf900 && currenti <= 0xfdcf /* [#xf900-#xfdcf] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex027 ~ [\x{fdf0}-\x{fffd}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex027b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0xfdf0 && currenti <= 0xfffd /* [#xfdf0-#xfffd] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex028 ~ [\x{10000}-\x{effff}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex028b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x10000 && currenti <= 0xeffff /* [#x10000-#xeffff] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex029 ~ '-'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex029b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x2d /* - */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex030 ~ '.'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex030b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x2e /* . */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex031 ~ [0-9]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex031b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x30 && currenti <= 0x39 /* [0-9] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex032 ~ [\x{b7}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex032b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0xb7 /* #xb7 */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex033 ~ [\x{300}-\x{36f}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex033b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x300 && currenti <= 0x36f /* [#x300-#x36f] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex034 ~ [\x{203f}-\x{2040}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex034b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x203f && currenti <= 0x2040 /* [#x203f-#x2040] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex035 ~ '"'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex035b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x22 /* " */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex036 ~ [^%&"]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex036b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return ((currenti == 0x25) /* % */ ||
          (currenti == 0x26) /* & */ ||
          (currenti == 0x22) /* " */) ? MARPAWRAPPER_BOOL_FALSE : MARPAWRAPPER_BOOL_TRUE;
}
/************************************************
  _Lex037 ~ [']
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex037b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x27 /* ' */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex038 ~ [^%&']
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex038b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return ((currenti == 0x25) /* % */ ||
          (currenti == 0x26) /* & */ ||
          (currenti == 0x27) /* ' */) ? MARPAWRAPPER_BOOL_FALSE : MARPAWRAPPER_BOOL_TRUE;
}
/************************************************
  _Lex039 ~ [^<&"]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex039b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return ((currenti == 0x3c) /* < */ ||
          (currenti == 0x26) /* & */ ||
          (currenti == 0x22) /* " */) ? MARPAWRAPPER_BOOL_FALSE : MARPAWRAPPER_BOOL_TRUE;
}
/************************************************
  _Lex040 ~ [^<&']
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex040b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return ((currenti == 0x3c) /* < */ ||
          (currenti == 0x26) /* & */ ||
          (currenti == 0x27) /* ' */) ? MARPAWRAPPER_BOOL_FALSE : MARPAWRAPPER_BOOL_TRUE;
}
/************************************************
  _Lex041 ~ [^"]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex041b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x22 /* " */) ? MARPAWRAPPER_BOOL_FALSE : MARPAWRAPPER_BOOL_TRUE;
}
/************************************************
  _Lex042 ~ [^']
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex042b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x27 /* ' */) ? MARPAWRAPPER_BOOL_FALSE : MARPAWRAPPER_BOOL_TRUE;
}
/************************************************
  _Lex043 ~ [a-zA-Z0-9]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex043b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return ((currenti >= 0x61 && currenti <= 0x7a) /* [a-z] */ ||
          (currenti >= 0x41 && currenti <= 0x5a) /* [A-Z] */ ||
          (currenti >= 0x30 && currenti <= 0x39) /* [0-9] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex044 ~ [-'()+,./:=?;!*#@$_%]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex044b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return ((currenti == 0x2d) /* - */ ||
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
          (currenti == 0x25) /* % */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex045 ~ [^<&]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex045b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return ((currenti == 0x3c) /* < */ ||
          (currenti == 0x26) /* & */) ? MARPAWRAPPER_BOOL_FALSE : MARPAWRAPPER_BOOL_TRUE;
}
/************************************************
  _Lex046 ~ ']]>'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex046b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex047 ~ '<!--'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex047b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex048 ~ '-->'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex048b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex049 ~ '<?'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex049b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex050 ~ '?>'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex050b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex051 ~ 'X'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex051b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x58 /* X */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex052 ~ 'x'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex052b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x78 /* x */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex053 ~ 'M'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex053b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x4d /* M */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex054 ~ 'm'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex054b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x6d /* m */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex055 ~ 'L'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex055b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x4c /* L */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex056 ~ 'l'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex056b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x6c /* l */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex057 ~ '<![CDATA['
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex057b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex058 ~ '<?xml'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex058b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex059 ~ 'version'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex059b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex060 ~ '='
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex060b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x3d /* = */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex061 ~ '1.1'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex061b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  static const signed int wanted[3] = {
    0x31 /* 1 */,
    0x2e /* . */,
    0x31 /* 1 */
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex062 ~ '<!DOCTYPE'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex062b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex063 ~ '['
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex063b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x5b /* [ */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex064 ~ ']'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex064b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x5d /* ] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex065 ~ '>'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex065b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x3e /* > */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex066 ~ 'standalone'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex066b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex067 ~ 'yes'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex067b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex068 ~ 'no'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex068b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex069 ~ '<'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex069b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x3c /* < */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex070 ~ '</'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex070b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex071 ~ '/>'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex071b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex072 ~ '<!ELEMENT'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex072b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex073 ~ 'EMPTY'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex073b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex074 ~ 'ANY'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex074b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex075 ~ '?'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex075b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x3f /* ? */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex076 ~ '*'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex076b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x2a /* * */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex077 ~ '+'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex077b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x2b /* + */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex078 ~ '('
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex078b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x28 /* ( */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex079 ~ '|'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex079b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x7c /* | */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex080 ~ ')'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex080b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x29 /* ) */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex081 ~ ','
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex081b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x2c /* , */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex082 ~ '#PCDATA'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex082b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex083 ~ ')*'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex083b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex084 ~ '<!ATTLIST'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex084b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex085 ~ 'CDATA'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex085b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex086 ~ 'ID'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex086b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex087 ~ 'IDREF'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex087b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex088 ~ 'IDREFS'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex088b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex089 ~ 'ENTITY'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex089b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex090 ~ 'ENTITIES'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex090b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex091 ~ 'NMTOKEN'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex091b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex092 ~ 'NMTOKENS'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex092b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex093 ~ 'NOTATION'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex093b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex094 ~ '#REQUIRED'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex094b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex095 ~ '#IMPLIED'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex095b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex096 ~ '#FIXED'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex096b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex097 ~ '<!['
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex097b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex098 ~ 'INCLUDE'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex098b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex099 ~ 'IGNORE'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex099b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex100 ~ '&#'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex100b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex101 ~ ';'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex101b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x3b /* ; */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex102 ~ '&#x'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex102b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex103 ~ [0-9a-fA-F]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex103b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return ((currenti >= 0x30 && currenti <= 0x39) /* [0-9] */ ||
          (currenti >= 0x61 && currenti <= 0x66) /* [a-f] */ ||
          (currenti >= 0x41 && currenti <= 0x46) /* [A-F] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex104 ~ '&'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex104b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x26 /* & */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex105 ~ '%'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex105b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x25 /* % */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex106 ~ '<!ENTITY'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex106b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex107 ~ 'SYSTEM'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex107b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex108 ~ 'PUBLIC'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex108b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex109 ~ 'NDATA'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex109b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex110 ~ 'encoding'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex110b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex111 ~ [A-Za-z]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex111b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return ((currenti >= 0x41 && currenti <= 0x5a) /* [A-Z] */ ||
          (currenti >= 0x61 && currenti <= 0x7a) /* [a-z] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex112 ~ [A-Za-z0-9._]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex112b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
  return ((currenti >= 0x41 && currenti <= 0x5a) /* [A-Z] */ ||
          (currenti >= 0x61 && currenti <= 0x7a) /* [a-z] */ ||
          (currenti >= 0x30 && currenti <= 0x39) /* [0-9] */ ||
          (currenti == 0x2e) /* . */ ||
          (currenti == 0x5f) /* _ */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex113 ~ '<!NOTATION'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex113b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
