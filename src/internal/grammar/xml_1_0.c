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
  xml_1_0__Exclusion001 = 0     , /* _Exclusion001 ~ 'PubidChar - _Lex032' */
  xml_1_0__Exclusion002         , /* _Exclusion002 ~ '_Lex040_any - _Gen086' */
  xml_1_0__Exclusion003         , /* _Exclusion003 ~ 'Char - _Lex024' */
  xml_1_0__Exclusion004         , /* _Exclusion004 ~ 'Char_any - _Gen099' */
  xml_1_0__Exclusion005         , /* _Exclusion005 ~ 'Name - _Gen112' */
  xml_1_0__Exclusion006         , /* _Exclusion006 ~ 'Char_any - _Gen117' */
  xml_1_0__Exclusion007         , /* _Exclusion007 ~ 'Char_any - _Gen271' */
  xml_1_0__Lex001               , /* _Lex001 ~ [\x{9}] */
  xml_1_0__Lex002               , /* _Lex002 ~ [\x{a}] */
  xml_1_0__Lex003               , /* _Lex003 ~ [\x{d}] */
  xml_1_0__Lex004               , /* _Lex004 ~ [\x{20}-\x{d7ff}] */
  xml_1_0__Lex005               , /* _Lex005 ~ [\x{e000}-\x{fffd}] */
  xml_1_0__Lex006               , /* _Lex006 ~ [\x{10000}-\x{10ffff}] */
  xml_1_0__Lex007               , /* _Lex007 ~ [\x{20}] */
  xml_1_0__Lex008               , /* _Lex008 ~ ':' */
  xml_1_0__Lex009               , /* _Lex009 ~ [A-Z] */
  xml_1_0__Lex010               , /* _Lex010 ~ '_' */
  xml_1_0__Lex011               , /* _Lex011 ~ [a-z] */
  xml_1_0__Lex012               , /* _Lex012 ~ [\x{c0}-\x{d6}] */
  xml_1_0__Lex013               , /* _Lex013 ~ [\x{d8}-\x{f6}] */
  xml_1_0__Lex014               , /* _Lex014 ~ [\x{f8}-\x{2ff}] */
  xml_1_0__Lex015               , /* _Lex015 ~ [\x{370}-\x{37d}] */
  xml_1_0__Lex016               , /* _Lex016 ~ [\x{37f}-\x{1fff}] */
  xml_1_0__Lex017               , /* _Lex017 ~ [\x{200c}-\x{200d}] */
  xml_1_0__Lex018               , /* _Lex018 ~ [\x{2070}-\x{218f}] */
  xml_1_0__Lex019               , /* _Lex019 ~ [\x{2c00}-\x{2fef}] */
  xml_1_0__Lex020               , /* _Lex020 ~ [\x{3001}-\x{d7ff}] */
  xml_1_0__Lex021               , /* _Lex021 ~ [\x{f900}-\x{fdcf}] */
  xml_1_0__Lex022               , /* _Lex022 ~ [\x{fdf0}-\x{fffd}] */
  xml_1_0__Lex023               , /* _Lex023 ~ [\x{10000}-\x{effff}] */
  xml_1_0__Lex024               , /* _Lex024 ~ '-' */
  xml_1_0__Lex025               , /* _Lex025 ~ '.' */
  xml_1_0__Lex026               , /* _Lex026 ~ [0-9] */
  xml_1_0__Lex027               , /* _Lex027 ~ [\x{b7}] */
  xml_1_0__Lex028               , /* _Lex028 ~ [\x{300}-\x{36f}] */
  xml_1_0__Lex029               , /* _Lex029 ~ [\x{203f}-\x{2040}] */
  xml_1_0__Lex030               , /* _Lex030 ~ '"' */
  xml_1_0__Lex031               , /* _Lex031 ~ [^%&"] */
  xml_1_0__Lex032               , /* _Lex032 ~ ['] */
  xml_1_0__Lex033               , /* _Lex033 ~ [^%&'] */
  xml_1_0__Lex034               , /* _Lex034 ~ [^<&"] */
  xml_1_0__Lex035               , /* _Lex035 ~ [^<&'] */
  xml_1_0__Lex036               , /* _Lex036 ~ [^"] */
  xml_1_0__Lex037               , /* _Lex037 ~ [^'] */
  xml_1_0__Lex038               , /* _Lex038 ~ [a-zA-Z0-9] */
  xml_1_0__Lex039               , /* _Lex039 ~ [-'()+,./:=?;!*#@$_%] */
  xml_1_0__Lex040               , /* _Lex040 ~ [^<&] */
  xml_1_0__Lex041               , /* _Lex041 ~ ']]>' */
  xml_1_0__Lex042               , /* _Lex042 ~ '<!--' */
  xml_1_0__Lex043               , /* _Lex043 ~ '-->' */
  xml_1_0__Lex044               , /* _Lex044 ~ '<?' */
  xml_1_0__Lex045               , /* _Lex045 ~ '?>' */
  xml_1_0__Lex046               , /* _Lex046 ~ 'X' */
  xml_1_0__Lex047               , /* _Lex047 ~ 'x' */
  xml_1_0__Lex048               , /* _Lex048 ~ 'M' */
  xml_1_0__Lex049               , /* _Lex049 ~ 'm' */
  xml_1_0__Lex050               , /* _Lex050 ~ 'L' */
  xml_1_0__Lex051               , /* _Lex051 ~ 'l' */
  xml_1_0__Lex052               , /* _Lex052 ~ '<![CDATA[' */
  xml_1_0__Lex053               , /* _Lex053 ~ '<?xml' */
  xml_1_0__Lex054               , /* _Lex054 ~ 'version' */
  xml_1_0__Lex055               , /* _Lex055 ~ '=' */
  xml_1_0__Lex056               , /* _Lex056 ~ '1.' */
  xml_1_0__Lex057               , /* _Lex057 ~ '<!DOCTYPE' */
  xml_1_0__Lex058               , /* _Lex058 ~ '[' */
  xml_1_0__Lex059               , /* _Lex059 ~ ']' */
  xml_1_0__Lex060               , /* _Lex060 ~ '>' */
  xml_1_0__Lex061               , /* _Lex061 ~ 'standalone' */
  xml_1_0__Lex062               , /* _Lex062 ~ 'yes' */
  xml_1_0__Lex063               , /* _Lex063 ~ 'no' */
  xml_1_0__Lex064               , /* _Lex064 ~ '<' */
  xml_1_0__Lex065               , /* _Lex065 ~ '</' */
  xml_1_0__Lex066               , /* _Lex066 ~ '/>' */
  xml_1_0__Lex067               , /* _Lex067 ~ '<!ELEMENT' */
  xml_1_0__Lex068               , /* _Lex068 ~ 'EMPTY' */
  xml_1_0__Lex069               , /* _Lex069 ~ 'ANY' */
  xml_1_0__Lex070               , /* _Lex070 ~ '?' */
  xml_1_0__Lex071               , /* _Lex071 ~ '*' */
  xml_1_0__Lex072               , /* _Lex072 ~ '+' */
  xml_1_0__Lex073               , /* _Lex073 ~ '(' */
  xml_1_0__Lex074               , /* _Lex074 ~ '|' */
  xml_1_0__Lex075               , /* _Lex075 ~ ')' */
  xml_1_0__Lex076               , /* _Lex076 ~ ',' */
  xml_1_0__Lex077               , /* _Lex077 ~ '#PCDATA' */
  xml_1_0__Lex078               , /* _Lex078 ~ ')*' */
  xml_1_0__Lex079               , /* _Lex079 ~ '<!ATTLIST' */
  xml_1_0__Lex080               , /* _Lex080 ~ 'CDATA' */
  xml_1_0__Lex081               , /* _Lex081 ~ 'ID' */
  xml_1_0__Lex082               , /* _Lex082 ~ 'IDREF' */
  xml_1_0__Lex083               , /* _Lex083 ~ 'IDREFS' */
  xml_1_0__Lex084               , /* _Lex084 ~ 'ENTITY' */
  xml_1_0__Lex085               , /* _Lex085 ~ 'ENTITIES' */
  xml_1_0__Lex086               , /* _Lex086 ~ 'NMTOKEN' */
  xml_1_0__Lex087               , /* _Lex087 ~ 'NMTOKENS' */
  xml_1_0__Lex088               , /* _Lex088 ~ 'NOTATION' */
  xml_1_0__Lex089               , /* _Lex089 ~ '#REQUIRED' */
  xml_1_0__Lex090               , /* _Lex090 ~ '#IMPLIED' */
  xml_1_0__Lex091               , /* _Lex091 ~ '#FIXED' */
  xml_1_0__Lex092               , /* _Lex092 ~ '<![' */
  xml_1_0__Lex093               , /* _Lex093 ~ 'INCLUDE' */
  xml_1_0__Lex094               , /* _Lex094 ~ 'IGNORE' */
  xml_1_0__Lex095               , /* _Lex095 ~ '&#' */
  xml_1_0__Lex096               , /* _Lex096 ~ ';' */
  xml_1_0__Lex097               , /* _Lex097 ~ '&#x' */
  xml_1_0__Lex098               , /* _Lex098 ~ [0-9a-fA-F] */
  xml_1_0__Lex099               , /* _Lex099 ~ '&' */
  xml_1_0__Lex100               , /* _Lex100 ~ '%' */
  xml_1_0__Lex101               , /* _Lex101 ~ '<!ENTITY' */
  xml_1_0__Lex102               , /* _Lex102 ~ 'SYSTEM' */
  xml_1_0__Lex103               , /* _Lex103 ~ 'PUBLIC' */
  xml_1_0__Lex104               , /* _Lex104 ~ 'NDATA' */
  xml_1_0__Lex105               , /* _Lex105 ~ 'encoding' */
  xml_1_0__Lex106               , /* _Lex106 ~ [A-Za-z] */
  xml_1_0__Lex107               , /* _Lex107 ~ [A-Za-z0-9._] */
  xml_1_0__Lex108               , /* _Lex108 ~ '<!NOTATION' */
  /* Non-terminals */
  xml_1_0_AttDef                ,
  xml_1_0_AttDef_any            ,
  xml_1_0_AttType               ,
  xml_1_0_AttValue              ,
  xml_1_0_AttlistDecl           ,
  xml_1_0_Attribute             ,
  xml_1_0_CDEnd                 ,
  xml_1_0_CDSect                ,
  xml_1_0_CDStart               ,
  xml_1_0_CData                 ,
  xml_1_0_Char                  ,
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
  xml_1_0_NameStartChar         ,
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
  xml_1_0_PubidChar             ,
  xml_1_0_PubidChar_any         ,
  xml_1_0_PubidLiteral          ,
  xml_1_0_PublicID              ,
  xml_1_0_Reference             ,
  xml_1_0_S                     ,
  xml_1_0_SDDecl                ,
  xml_1_0_SDDecl_maybe          ,
  xml_1_0_STag                  ,
  xml_1_0_S_maybe               ,
  xml_1_0_StringType            ,
  xml_1_0_SystemLiteral         ,
  xml_1_0_TextDecl              ,
  xml_1_0_TextDecl_maybe        ,
  xml_1_0_TokenizedType         ,
  xml_1_0_VersionInfo           ,
  xml_1_0_VersionInfo_maybe     ,
  xml_1_0_VersionNum            ,
  xml_1_0_XMLDecl               ,
  xml_1_0_XMLDecl_maybe         ,
  xml_1_0__Gen009               ,
  xml_1_0__Gen009_many          ,
  xml_1_0__Gen038               ,
  xml_1_0__Gen038_any           ,
  xml_1_0__Gen041               ,
  xml_1_0__Gen041_any           ,
  xml_1_0__Gen044               ,
  xml_1_0__Gen044_many          ,
  xml_1_0__Gen047               ,
  xml_1_0__Gen047_any           ,
  xml_1_0__Gen050               ,
  xml_1_0__Gen050_any           ,
  xml_1_0__Gen054               ,
  xml_1_0__Gen054_any           ,
  xml_1_0__Gen060               ,
  xml_1_0__Gen060_any           ,
  xml_1_0__Gen063               ,
  xml_1_0__Gen063_any           ,
  xml_1_0__Gen069               ,
  xml_1_0__Gen071               ,
  xml_1_0__Gen075               ,
  xml_1_0__Gen076               ,
  xml_1_0__Gen076_any           ,
  xml_1_0__Gen086               ,
  xml_1_0__Gen087               ,
  xml_1_0__Gen089               ,
  xml_1_0__Gen090               ,
  xml_1_0__Gen091               ,
  xml_1_0__Gen092               ,
  xml_1_0__Gen093               ,
  xml_1_0__Gen094               ,
  xml_1_0__Gen094_any           ,
  xml_1_0__Gen099               ,
  xml_1_0__Gen100               ,
  xml_1_0__Gen101               ,
  xml_1_0__Gen102               ,
  xml_1_0__Gen102_maybe         ,
  xml_1_0__Gen106               ,
  xml_1_0__Gen108               ,
  xml_1_0__Gen110               ,
  xml_1_0__Gen112               ,
  xml_1_0__Gen113               ,
  xml_1_0__Gen117               ,
  xml_1_0__Gen118               ,
  xml_1_0__Gen119               ,
  xml_1_0__Gen124               ,
  xml_1_0__Gen124_maybe         ,
  xml_1_0__Gen135               ,
  xml_1_0__Gen144               ,
  xml_1_0__Gen144_maybe         ,
  xml_1_0__Gen147               ,
  xml_1_0__Gen147_maybe         ,
  xml_1_0__Gen153               ,
  xml_1_0__Gen153_any           ,
  xml_1_0__Gen166               ,
  xml_1_0__Gen166_any           ,
  xml_1_0__Gen171               ,
  xml_1_0__Gen173               ,
  xml_1_0__Gen174               ,
  xml_1_0__Gen176               ,
  xml_1_0__Gen177               ,
  xml_1_0__Gen182               ,
  xml_1_0__Gen182_any           ,
  xml_1_0__Gen189               ,
  xml_1_0__Gen194               ,
  xml_1_0__Gen194_any           ,
  xml_1_0__Gen197               ,
  xml_1_0__Gen197_any           ,
  xml_1_0__Gen205               ,
  xml_1_0__Gen207               ,
  xml_1_0__Gen207_maybe         ,
  xml_1_0__Gen213               ,
  xml_1_0__Gen216               ,
  xml_1_0__Gen216_maybe         ,
  xml_1_0__Gen222               ,
  xml_1_0__Gen222_many          ,
  xml_1_0__Gen225               ,
  xml_1_0__Gen225_any           ,
  xml_1_0__Gen228               ,
  xml_1_0__Gen228_any           ,
  xml_1_0__Gen248               ,
  xml_1_0__Gen248_any           ,
  xml_1_0__Gen251               ,
  xml_1_0__Gen251_any           ,
  xml_1_0__Gen254               ,
  xml_1_0__Gen254_maybe         ,
  xml_1_0__Gen257               ,
  xml_1_0__Gen266               ,
  xml_1_0__Gen266_any           ,
  xml_1_0__Gen269               ,
  xml_1_0__Gen271               ,
  xml_1_0__Gen272               ,
  xml_1_0__Gen287               ,
  xml_1_0__Gen299               ,
  xml_1_0__Gen302               ,
  xml_1_0__Gen302_any           ,
  xml_1_0__Gen306               ,
  xml_1_0__Lex026_many          ,
  xml_1_0__Lex036_any           ,
  xml_1_0__Lex037_any           ,
  xml_1_0__Lex040_any           ,
  xml_1_0__Lex098_many          ,
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
  XML_1_0_SYMBOL_MAX
} xml_1_0_symbol_t;

#define XML_1_0_TERMINAL_MAX xml_1_0__Lex108

/* Rules */
typedef enum xml_1_0_rule {
  xml_1_0_Misc_any_001 = 0      , /* Misc_any ::= Misc * */
  xml_1_0_document_001          , /* document ::= prolog element Misc_any  */
  xml_1_0_Char_001              , /* Char ::= _Lex001  */
  xml_1_0_Char_002              , /* Char ::= _Lex002  */
  xml_1_0_Char_003              , /* Char ::= _Lex003  */
  xml_1_0_Char_004              , /* Char ::= _Lex004  */
  xml_1_0_Char_005              , /* Char ::= _Lex005  */
  xml_1_0_Char_006              , /* Char ::= _Lex006  */
  xml_1_0__Gen009_001           , /* _Gen009 ::= _Lex007  */
  xml_1_0__Gen009_002           , /* _Gen009 ::= _Lex001  */
  xml_1_0__Gen009_003           , /* _Gen009 ::= _Lex003  */
  xml_1_0__Gen009_004           , /* _Gen009 ::= _Lex002  */
  xml_1_0__Gen009_many_001      , /* _Gen009_many ::= _Gen009 + */
  xml_1_0_S_001                 , /* S ::= _Gen009_many  */
  xml_1_0_NameStartChar_001     , /* NameStartChar ::= _Lex008  */
  xml_1_0_NameStartChar_002     , /* NameStartChar ::= _Lex009  */
  xml_1_0_NameStartChar_003     , /* NameStartChar ::= _Lex010  */
  xml_1_0_NameStartChar_004     , /* NameStartChar ::= _Lex011  */
  xml_1_0_NameStartChar_005     , /* NameStartChar ::= _Lex012  */
  xml_1_0_NameStartChar_006     , /* NameStartChar ::= _Lex013  */
  xml_1_0_NameStartChar_007     , /* NameStartChar ::= _Lex014  */
  xml_1_0_NameStartChar_008     , /* NameStartChar ::= _Lex015  */
  xml_1_0_NameStartChar_009     , /* NameStartChar ::= _Lex016  */
  xml_1_0_NameStartChar_010     , /* NameStartChar ::= _Lex017  */
  xml_1_0_NameStartChar_011     , /* NameStartChar ::= _Lex018  */
  xml_1_0_NameStartChar_012     , /* NameStartChar ::= _Lex019  */
  xml_1_0_NameStartChar_013     , /* NameStartChar ::= _Lex020  */
  xml_1_0_NameStartChar_014     , /* NameStartChar ::= _Lex021  */
  xml_1_0_NameStartChar_015     , /* NameStartChar ::= _Lex022  */
  xml_1_0_NameStartChar_016     , /* NameStartChar ::= _Lex023  */
  xml_1_0_NameChar_001          , /* NameChar ::= NameStartChar  */
  xml_1_0_NameChar_002          , /* NameChar ::= _Lex024  */
  xml_1_0_NameChar_003          , /* NameChar ::= _Lex025  */
  xml_1_0_NameChar_004          , /* NameChar ::= _Lex026  */
  xml_1_0_NameChar_005          , /* NameChar ::= _Lex027  */
  xml_1_0_NameChar_006          , /* NameChar ::= _Lex028  */
  xml_1_0_NameChar_007          , /* NameChar ::= _Lex029  */
  xml_1_0__Gen038_001           , /* _Gen038 ::= NameChar  */
  xml_1_0__Gen038_any_001       , /* _Gen038_any ::= _Gen038 * */
  xml_1_0_Name_001              , /* Name ::= NameStartChar _Gen038_any  */
  xml_1_0__Gen041_001           , /* _Gen041 ::= _Lex007 Name  */
  xml_1_0__Gen041_any_001       , /* _Gen041_any ::= _Gen041 * */
  xml_1_0_Names_001             , /* Names ::= Name _Gen041_any  */
  xml_1_0__Gen044_001           , /* _Gen044 ::= NameChar  */
  xml_1_0__Gen044_many_001      , /* _Gen044_many ::= _Gen044 + */
  xml_1_0_Nmtoken_001           , /* Nmtoken ::= _Gen044_many  */
  xml_1_0__Gen047_001           , /* _Gen047 ::= _Lex007 Nmtoken  */
  xml_1_0__Gen047_any_001       , /* _Gen047_any ::= _Gen047 * */
  xml_1_0_Nmtokens_001          , /* Nmtokens ::= Nmtoken _Gen047_any  */
  xml_1_0__Gen050_001           , /* _Gen050 ::= _Lex031  */
  xml_1_0__Gen050_002           , /* _Gen050 ::= PEReference  */
  xml_1_0__Gen050_003           , /* _Gen050 ::= Reference  */
  xml_1_0__Gen050_any_001       , /* _Gen050_any ::= _Gen050 * */
  xml_1_0__Gen054_001           , /* _Gen054 ::= _Lex033  */
  xml_1_0__Gen054_002           , /* _Gen054 ::= PEReference  */
  xml_1_0__Gen054_003           , /* _Gen054 ::= Reference  */
  xml_1_0__Gen054_any_001       , /* _Gen054_any ::= _Gen054 * */
  xml_1_0_EntityValue_001       , /* EntityValue ::= _Lex030 _Gen050_any _Lex030  */
  xml_1_0_EntityValue_002       , /* EntityValue ::= _Lex032 _Gen054_any _Lex032  */
  xml_1_0__Gen060_001           , /* _Gen060 ::= _Lex034  */
  xml_1_0__Gen060_002           , /* _Gen060 ::= Reference  */
  xml_1_0__Gen060_any_001       , /* _Gen060_any ::= _Gen060 * */
  xml_1_0__Gen063_001           , /* _Gen063 ::= _Lex035  */
  xml_1_0__Gen063_002           , /* _Gen063 ::= Reference  */
  xml_1_0__Gen063_any_001       , /* _Gen063_any ::= _Gen063 * */
  xml_1_0_AttValue_001          , /* AttValue ::= _Lex030 _Gen060_any _Lex030  */
  xml_1_0_AttValue_002          , /* AttValue ::= _Lex032 _Gen063_any _Lex032  */
  xml_1_0__Lex036_any_001       , /* _Lex036_any ::= _Lex036 * */
  xml_1_0__Gen069_001           , /* _Gen069 ::= _Lex030 _Lex036_any _Lex030  */
  xml_1_0__Lex037_any_001       , /* _Lex037_any ::= _Lex037 * */
  xml_1_0__Gen071_001           , /* _Gen071 ::= _Lex032 _Lex037_any _Lex032  */
  xml_1_0_SystemLiteral_001     , /* SystemLiteral ::= _Gen069  */
  xml_1_0_SystemLiteral_002     , /* SystemLiteral ::= _Gen071  */
  xml_1_0_PubidChar_any_001     , /* PubidChar_any ::= PubidChar * */
  xml_1_0__Gen075_001           , /* _Gen075 ::= _Exclusion001  */
  xml_1_0__Gen076_001           , /* _Gen076 ::= _Gen075  */
  xml_1_0__Gen076_any_001       , /* _Gen076_any ::= _Gen076 * */
  xml_1_0_PubidLiteral_001      , /* PubidLiteral ::= _Lex030 PubidChar_any _Lex030  */
  xml_1_0_PubidLiteral_002      , /* PubidLiteral ::= _Lex032 _Gen076_any _Lex032  */
  xml_1_0_PubidChar_001         , /* PubidChar ::= _Lex007  */
  xml_1_0_PubidChar_002         , /* PubidChar ::= _Lex003  */
  xml_1_0_PubidChar_003         , /* PubidChar ::= _Lex002  */
  xml_1_0_PubidChar_004         , /* PubidChar ::= _Lex038  */
  xml_1_0_PubidChar_005         , /* PubidChar ::= _Lex039  */
  xml_1_0__Lex040_any_001       , /* _Lex040_any ::= _Lex040 * */
  xml_1_0__Gen086_001           , /* _Gen086 ::= _Lex040_any _Lex041 _Lex040_any  */
  xml_1_0__Gen087_001           , /* _Gen087 ::= _Exclusion002  */
  xml_1_0_CharData_001          , /* CharData ::= _Gen087  */
  xml_1_0__Gen089_001           , /* _Gen089 ::= _Exclusion003  */
  xml_1_0__Gen090_001           , /* _Gen090 ::= _Gen089  */
  xml_1_0__Gen091_001           , /* _Gen091 ::= _Exclusion003  */
  xml_1_0__Gen092_001           , /* _Gen092 ::= _Gen091  */
  xml_1_0__Gen093_001           , /* _Gen093 ::= _Lex024 _Gen092  */
  xml_1_0__Gen094_001           , /* _Gen094 ::= _Gen090  */
  xml_1_0__Gen094_002           , /* _Gen094 ::= _Gen093  */
  xml_1_0__Gen094_any_001       , /* _Gen094_any ::= _Gen094 * */
  xml_1_0_Comment_001           , /* Comment ::= _Lex042 _Gen094_any _Lex043  */
  xml_1_0_Char_any_001          , /* Char_any ::= Char * */
  xml_1_0__Gen099_001           , /* _Gen099 ::= Char_any _Lex045 Char_any  */
  xml_1_0__Gen100_001           , /* _Gen100 ::= _Exclusion004  */
  xml_1_0__Gen101_001           , /* _Gen101 ::= _Gen100  */
  xml_1_0__Gen102_001           , /* _Gen102 ::= S _Gen101  */
  xml_1_0__Gen102_maybe_001     , /* _Gen102_maybe ::= _Gen102  */
  xml_1_0__Gen102_maybe_002     , /* _Gen102_maybe ::=   */
  xml_1_0_PI_001                , /* PI ::= _Lex044 PITarget _Gen102_maybe _Lex045  */
  xml_1_0__Gen106_001           , /* _Gen106 ::= _Lex046  */
  xml_1_0__Gen106_002           , /* _Gen106 ::= _Lex047  */
  xml_1_0__Gen108_001           , /* _Gen108 ::= _Lex048  */
  xml_1_0__Gen108_002           , /* _Gen108 ::= _Lex049  */
  xml_1_0__Gen110_001           , /* _Gen110 ::= _Lex050  */
  xml_1_0__Gen110_002           , /* _Gen110 ::= _Lex051  */
  xml_1_0__Gen112_001           , /* _Gen112 ::= _Gen106 _Gen108 _Gen110  */
  xml_1_0__Gen113_001           , /* _Gen113 ::= _Exclusion005  */
  xml_1_0_PITarget_001          , /* PITarget ::= _Gen113  */
  xml_1_0_CDSect_001            , /* CDSect ::= CDStart CData CDEnd  */
  xml_1_0_CDStart_001           , /* CDStart ::= _Lex052  */
  xml_1_0__Gen117_001           , /* _Gen117 ::= Char_any _Lex041 Char_any  */
  xml_1_0__Gen118_001           , /* _Gen118 ::= _Exclusion006  */
  xml_1_0__Gen119_001           , /* _Gen119 ::= _Gen118  */
  xml_1_0_CData_001             , /* CData ::= _Gen119  */
  xml_1_0_CDEnd_001             , /* CDEnd ::= _Lex041  */
  xml_1_0_XMLDecl_maybe_001     , /* XMLDecl_maybe ::= XMLDecl  */
  xml_1_0_XMLDecl_maybe_002     , /* XMLDecl_maybe ::=   */
  xml_1_0__Gen124_001           , /* _Gen124 ::= doctypedecl Misc_any  */
  xml_1_0__Gen124_maybe_001     , /* _Gen124_maybe ::= _Gen124  */
  xml_1_0__Gen124_maybe_002     , /* _Gen124_maybe ::=   */
  xml_1_0_prolog_001            , /* prolog ::= XMLDecl_maybe Misc_any _Gen124_maybe  */
  xml_1_0_EncodingDecl_maybe_001, /* EncodingDecl_maybe ::= EncodingDecl  */
  xml_1_0_EncodingDecl_maybe_002, /* EncodingDecl_maybe ::=   */
  xml_1_0_SDDecl_maybe_001      , /* SDDecl_maybe ::= SDDecl  */
  xml_1_0_SDDecl_maybe_002      , /* SDDecl_maybe ::=   */
  xml_1_0_S_maybe_001           , /* S_maybe ::= S  */
  xml_1_0_S_maybe_002           , /* S_maybe ::=   */
  xml_1_0_XMLDecl_001           , /* XMLDecl ::= _Lex053 VersionInfo EncodingDecl_maybe SDDecl_maybe S_maybe _Lex045  */
  xml_1_0__Gen135_001           , /* _Gen135 ::= _Lex032 VersionNum _Lex032  */
  xml_1_0__Gen135_002           , /* _Gen135 ::= _Lex030 VersionNum _Lex030  */
  xml_1_0_VersionInfo_001       , /* VersionInfo ::= S _Lex054 Eq _Gen135  */
  xml_1_0_Eq_001                , /* Eq ::= S_maybe _Lex055 S_maybe  */
  xml_1_0__Lex026_many_001      , /* _Lex026_many ::= _Lex026 + */
  xml_1_0_VersionNum_001        , /* VersionNum ::= _Lex056 _Lex026_many  */
  xml_1_0_Misc_001              , /* Misc ::= Comment  */
  xml_1_0_Misc_002              , /* Misc ::= PI  */
  xml_1_0_Misc_003              , /* Misc ::= S  */
  xml_1_0__Gen144_001           , /* _Gen144 ::= S ExternalID  */
  xml_1_0__Gen144_maybe_001     , /* _Gen144_maybe ::= _Gen144  */
  xml_1_0__Gen144_maybe_002     , /* _Gen144_maybe ::=   */
  xml_1_0__Gen147_001           , /* _Gen147 ::= _Lex058 intSubset _Lex059 S_maybe  */
  xml_1_0__Gen147_maybe_001     , /* _Gen147_maybe ::= _Gen147  */
  xml_1_0__Gen147_maybe_002     , /* _Gen147_maybe ::=   */
  xml_1_0_doctypedecl_001       , /* doctypedecl ::= _Lex057 S Name _Gen144_maybe S_maybe _Gen147_maybe _Lex060  */
  xml_1_0_DeclSep_001           , /* DeclSep ::= PEReference  */
  xml_1_0_DeclSep_002           , /* DeclSep ::= S  */
  xml_1_0__Gen153_001           , /* _Gen153 ::= markupdecl  */
  xml_1_0__Gen153_002           , /* _Gen153 ::= DeclSep  */
  xml_1_0__Gen153_any_001       , /* _Gen153_any ::= _Gen153 * */
  xml_1_0_intSubset_001         , /* intSubset ::= _Gen153_any  */
  xml_1_0_markupdecl_001        , /* markupdecl ::= elementdecl  */
  xml_1_0_markupdecl_002        , /* markupdecl ::= AttlistDecl  */
  xml_1_0_markupdecl_003        , /* markupdecl ::= EntityDecl  */
  xml_1_0_markupdecl_004        , /* markupdecl ::= NotationDecl  */
  xml_1_0_markupdecl_005        , /* markupdecl ::= PI  */
  xml_1_0_markupdecl_006        , /* markupdecl ::= Comment  */
  xml_1_0_TextDecl_maybe_001    , /* TextDecl_maybe ::= TextDecl  */
  xml_1_0_TextDecl_maybe_002    , /* TextDecl_maybe ::=   */
  xml_1_0_extSubset_001         , /* extSubset ::= TextDecl_maybe extSubsetDecl  */
  xml_1_0__Gen166_001           , /* _Gen166 ::= markupdecl  */
  xml_1_0__Gen166_002           , /* _Gen166 ::= conditionalSect  */
  xml_1_0__Gen166_003           , /* _Gen166 ::= DeclSep  */
  xml_1_0__Gen166_any_001       , /* _Gen166_any ::= _Gen166 * */
  xml_1_0_extSubsetDecl_001     , /* extSubsetDecl ::= _Gen166_any  */
  xml_1_0__Gen171_001           , /* _Gen171 ::= _Lex062  */
  xml_1_0__Gen171_002           , /* _Gen171 ::= _Lex063  */
  xml_1_0__Gen173_001           , /* _Gen173 ::= _Lex032 _Gen171 _Lex032  */
  xml_1_0__Gen174_001           , /* _Gen174 ::= _Lex062  */
  xml_1_0__Gen174_002           , /* _Gen174 ::= _Lex063  */
  xml_1_0__Gen176_001           , /* _Gen176 ::= _Lex030 _Gen174 _Lex030  */
  xml_1_0__Gen177_001           , /* _Gen177 ::= _Gen173  */
  xml_1_0__Gen177_002           , /* _Gen177 ::= _Gen176  */
  xml_1_0_SDDecl_001            , /* SDDecl ::= S _Lex061 Eq _Gen177  */
  xml_1_0_element_001           , /* element ::= EmptyElemTag  */
  xml_1_0_element_002           , /* element ::= STag content ETag  */
  xml_1_0__Gen182_001           , /* _Gen182 ::= S Attribute  */
  xml_1_0__Gen182_any_001       , /* _Gen182_any ::= _Gen182 * */
  xml_1_0_STag_001              , /* STag ::= _Lex064 Name _Gen182_any S_maybe _Lex060  */
  xml_1_0_Attribute_001         , /* Attribute ::= Name Eq AttValue  */
  xml_1_0_ETag_001              , /* ETag ::= _Lex065 Name S_maybe _Lex060  */
  xml_1_0_CharData_maybe_001    , /* CharData_maybe ::= CharData  */
  xml_1_0_CharData_maybe_002    , /* CharData_maybe ::=   */
  xml_1_0__Gen189_001           , /* _Gen189 ::= element  */
  xml_1_0__Gen189_002           , /* _Gen189 ::= Reference  */
  xml_1_0__Gen189_003           , /* _Gen189 ::= CDSect  */
  xml_1_0__Gen189_004           , /* _Gen189 ::= PI  */
  xml_1_0__Gen189_005           , /* _Gen189 ::= Comment  */
  xml_1_0__Gen194_001           , /* _Gen194 ::= _Gen189 CharData_maybe  */
  xml_1_0__Gen194_any_001       , /* _Gen194_any ::= _Gen194 * */
  xml_1_0_content_001           , /* content ::= CharData_maybe _Gen194_any  */
  xml_1_0__Gen197_001           , /* _Gen197 ::= S Attribute  */
  xml_1_0__Gen197_any_001       , /* _Gen197_any ::= _Gen197 * */
  xml_1_0_EmptyElemTag_001      , /* EmptyElemTag ::= _Lex064 Name _Gen197_any S_maybe _Lex066  */
  xml_1_0_elementdecl_001       , /* elementdecl ::= _Lex067 S Name S contentspec S_maybe _Lex060  */
  xml_1_0_contentspec_001       , /* contentspec ::= _Lex068  */
  xml_1_0_contentspec_002       , /* contentspec ::= _Lex069  */
  xml_1_0_contentspec_003       , /* contentspec ::= Mixed  */
  xml_1_0_contentspec_004       , /* contentspec ::= children  */
  xml_1_0__Gen205_001           , /* _Gen205 ::= choice  */
  xml_1_0__Gen205_002           , /* _Gen205 ::= seq  */
  xml_1_0__Gen207_001           , /* _Gen207 ::= _Lex070  */
  xml_1_0__Gen207_002           , /* _Gen207 ::= _Lex071  */
  xml_1_0__Gen207_003           , /* _Gen207 ::= _Lex072  */
  xml_1_0__Gen207_maybe_001     , /* _Gen207_maybe ::= _Gen207  */
  xml_1_0__Gen207_maybe_002     , /* _Gen207_maybe ::=   */
  xml_1_0_children_001          , /* children ::= _Gen205 _Gen207_maybe  */
  xml_1_0__Gen213_001           , /* _Gen213 ::= Name  */
  xml_1_0__Gen213_002           , /* _Gen213 ::= choice  */
  xml_1_0__Gen213_003           , /* _Gen213 ::= seq  */
  xml_1_0__Gen216_001           , /* _Gen216 ::= _Lex070  */
  xml_1_0__Gen216_002           , /* _Gen216 ::= _Lex071  */
  xml_1_0__Gen216_003           , /* _Gen216 ::= _Lex072  */
  xml_1_0__Gen216_maybe_001     , /* _Gen216_maybe ::= _Gen216  */
  xml_1_0__Gen216_maybe_002     , /* _Gen216_maybe ::=   */
  xml_1_0_cp_001                , /* cp ::= _Gen213 _Gen216_maybe  */
  xml_1_0__Gen222_001           , /* _Gen222 ::= S_maybe _Lex074 S_maybe cp  */
  xml_1_0__Gen222_many_001      , /* _Gen222_many ::= _Gen222 + */
  xml_1_0_choice_001            , /* choice ::= _Lex073 S_maybe cp _Gen222_many S_maybe _Lex075  */
  xml_1_0__Gen225_001           , /* _Gen225 ::= S_maybe _Lex076 S_maybe cp  */
  xml_1_0__Gen225_any_001       , /* _Gen225_any ::= _Gen225 * */
  xml_1_0_seq_001               , /* seq ::= _Lex073 S_maybe cp _Gen225_any S_maybe _Lex075  */
  xml_1_0__Gen228_001           , /* _Gen228 ::= S_maybe _Lex074 S_maybe Name  */
  xml_1_0__Gen228_any_001       , /* _Gen228_any ::= _Gen228 * */
  xml_1_0_Mixed_001             , /* Mixed ::= _Lex073 S_maybe _Lex077 _Gen228_any S_maybe _Lex078  */
  xml_1_0_Mixed_002             , /* Mixed ::= _Lex073 S_maybe _Lex077 S_maybe _Lex075  */
  xml_1_0_AttDef_any_001        , /* AttDef_any ::= AttDef * */
  xml_1_0_AttlistDecl_001       , /* AttlistDecl ::= _Lex079 S Name AttDef_any S_maybe _Lex060  */
  xml_1_0_AttDef_001            , /* AttDef ::= S Name S AttType S DefaultDecl  */
  xml_1_0_AttType_001           , /* AttType ::= StringType  */
  xml_1_0_AttType_002           , /* AttType ::= TokenizedType  */
  xml_1_0_AttType_003           , /* AttType ::= EnumeratedType  */
  xml_1_0_StringType_001        , /* StringType ::= _Lex080  */
  xml_1_0_TokenizedType_001     , /* TokenizedType ::= _Lex081  */
  xml_1_0_TokenizedType_002     , /* TokenizedType ::= _Lex082  */
  xml_1_0_TokenizedType_003     , /* TokenizedType ::= _Lex083  */
  xml_1_0_TokenizedType_004     , /* TokenizedType ::= _Lex084  */
  xml_1_0_TokenizedType_005     , /* TokenizedType ::= _Lex085  */
  xml_1_0_TokenizedType_006     , /* TokenizedType ::= _Lex086  */
  xml_1_0_TokenizedType_007     , /* TokenizedType ::= _Lex087  */
  xml_1_0_EnumeratedType_001    , /* EnumeratedType ::= NotationType  */
  xml_1_0_EnumeratedType_002    , /* EnumeratedType ::= Enumeration  */
  xml_1_0__Gen248_001           , /* _Gen248 ::= S_maybe _Lex074 S_maybe Name  */
  xml_1_0__Gen248_any_001       , /* _Gen248_any ::= _Gen248 * */
  xml_1_0_NotationType_001      , /* NotationType ::= _Lex088 S _Lex073 S_maybe Name _Gen248_any S_maybe _Lex075  */
  xml_1_0__Gen251_001           , /* _Gen251 ::= S_maybe _Lex074 S_maybe Nmtoken  */
  xml_1_0__Gen251_any_001       , /* _Gen251_any ::= _Gen251 * */
  xml_1_0_Enumeration_001       , /* Enumeration ::= _Lex073 S_maybe Nmtoken _Gen251_any S_maybe _Lex075  */
  xml_1_0__Gen254_001           , /* _Gen254 ::= _Lex091 S  */
  xml_1_0__Gen254_maybe_001     , /* _Gen254_maybe ::= _Gen254  */
  xml_1_0__Gen254_maybe_002     , /* _Gen254_maybe ::=   */
  xml_1_0__Gen257_001           , /* _Gen257 ::= _Gen254_maybe AttValue  */
  xml_1_0_DefaultDecl_001       , /* DefaultDecl ::= _Lex089  */
  xml_1_0_DefaultDecl_002       , /* DefaultDecl ::= _Lex090  */
  xml_1_0_DefaultDecl_003       , /* DefaultDecl ::= _Gen257  */
  xml_1_0_conditionalSect_001   , /* conditionalSect ::= includeSect  */
  xml_1_0_conditionalSect_002   , /* conditionalSect ::= ignoreSect  */
  xml_1_0_includeSect_001       , /* includeSect ::= _Lex092 S_maybe _Lex093 S_maybe _Lex058 extSubsetDecl _Lex041  */
  xml_1_0_ignoreSectContents_any_001, /* ignoreSectContents_any ::= ignoreSectContents * */
  xml_1_0_ignoreSect_001        , /* ignoreSect ::= _Lex092 S_maybe _Lex094 S_maybe _Lex058 ignoreSectContents_any _Lex041  */
  xml_1_0__Gen266_001           , /* _Gen266 ::= _Lex092 ignoreSectContents _Lex041 Ignore  */
  xml_1_0__Gen266_any_001       , /* _Gen266_any ::= _Gen266 * */
  xml_1_0_ignoreSectContents_001, /* ignoreSectContents ::= Ignore _Gen266_any  */
  xml_1_0__Gen269_001           , /* _Gen269 ::= _Lex092  */
  xml_1_0__Gen269_002           , /* _Gen269 ::= _Lex041  */
  xml_1_0__Gen271_001           , /* _Gen271 ::= Char_any _Gen269 Char_any  */
  xml_1_0__Gen272_001           , /* _Gen272 ::= _Exclusion007  */
  xml_1_0_Ignore_001            , /* Ignore ::= _Gen272  */
  xml_1_0__Lex098_many_001      , /* _Lex098_many ::= _Lex098 + */
  xml_1_0_CharRef_001           , /* CharRef ::= _Lex095 _Lex026_many _Lex096  */
  xml_1_0_CharRef_002           , /* CharRef ::= _Lex097 _Lex098_many _Lex096  */
  xml_1_0_Reference_001         , /* Reference ::= EntityRef  */
  xml_1_0_Reference_002         , /* Reference ::= CharRef  */
  xml_1_0_EntityRef_001         , /* EntityRef ::= _Lex099 Name _Lex096  */
  xml_1_0_PEReference_001       , /* PEReference ::= _Lex100 Name _Lex096  */
  xml_1_0_EntityDecl_001        , /* EntityDecl ::= GEDecl  */
  xml_1_0_EntityDecl_002        , /* EntityDecl ::= PEDecl  */
  xml_1_0_GEDecl_001            , /* GEDecl ::= _Lex101 S Name S EntityDef S_maybe _Lex060  */
  xml_1_0_PEDecl_001            , /* PEDecl ::= _Lex101 S _Lex100 S Name S PEDef S_maybe _Lex060  */
  xml_1_0_NDataDecl_maybe_001   , /* NDataDecl_maybe ::= NDataDecl  */
  xml_1_0_NDataDecl_maybe_002   , /* NDataDecl_maybe ::=   */
  xml_1_0__Gen287_001           , /* _Gen287 ::= ExternalID NDataDecl_maybe  */
  xml_1_0_EntityDef_001         , /* EntityDef ::= EntityValue  */
  xml_1_0_EntityDef_002         , /* EntityDef ::= _Gen287  */
  xml_1_0_PEDef_001             , /* PEDef ::= EntityValue  */
  xml_1_0_PEDef_002             , /* PEDef ::= ExternalID  */
  xml_1_0_ExternalID_001        , /* ExternalID ::= _Lex102 S SystemLiteral  */
  xml_1_0_ExternalID_002        , /* ExternalID ::= _Lex103 S PubidLiteral S SystemLiteral  */
  xml_1_0_NDataDecl_001         , /* NDataDecl ::= S _Lex104 S Name  */
  xml_1_0_VersionInfo_maybe_001 , /* VersionInfo_maybe ::= VersionInfo  */
  xml_1_0_VersionInfo_maybe_002 , /* VersionInfo_maybe ::=   */
  xml_1_0_TextDecl_001          , /* TextDecl ::= _Lex053 VersionInfo_maybe EncodingDecl S_maybe _Lex045  */
  xml_1_0_extParsedEnt_001      , /* extParsedEnt ::= TextDecl_maybe content  */
  xml_1_0__Gen299_001           , /* _Gen299 ::= _Lex030 EncName _Lex030  */
  xml_1_0__Gen299_002           , /* _Gen299 ::= _Lex032 EncName _Lex032  */
  xml_1_0_EncodingDecl_001      , /* EncodingDecl ::= S _Lex105 Eq _Gen299  */
  xml_1_0__Gen302_001           , /* _Gen302 ::= _Lex107  */
  xml_1_0__Gen302_002           , /* _Gen302 ::= _Lex024  */
  xml_1_0__Gen302_any_001       , /* _Gen302_any ::= _Gen302 * */
  xml_1_0_EncName_001           , /* EncName ::= _Lex106 _Gen302_any  */
  xml_1_0__Gen306_001           , /* _Gen306 ::= ExternalID  */
  xml_1_0__Gen306_002           , /* _Gen306 ::= PublicID  */
  xml_1_0_NotationDecl_001      , /* NotationDecl ::= _Lex108 S Name S _Gen306 S_maybe _Lex060  */
  xml_1_0_PublicID_001          , /* PublicID ::= _Lex103 S PubidLiteral  */
  XML_1_0_RULE_MAX
} xml_1_0_rule_t;


/* Work structure */
struct xml_1_0 {
  marpaWrapper_t        *marpaWrapperp;
  marpaWrapperSymbol_t **marpaWrapperSymbolArrayp;
  size_t                 marpaWrapperSymbolArrayLengthi;
  marpaWrapperRule_t   **marpaWrapperRuleArrayp;
  size_t                 marpaWrapperRuleArrayLengthi;
};

static C_INLINE marpaWrapperBool_t _xml_1_0_buildGrammarb(xml_1_0_t *xml_1_0p, marpaWrapperOption_t *marpaWrapperOptionp);
static C_INLINE marpaWrapperBool_t _xml_1_0_buildSymbolsb(xml_1_0_t *xml_1_0p);
static C_INLINE marpaWrapperBool_t _xml_1_0_buildSymbols_withStartb(xml_1_0_t *xml_1_0p, int starti);
static C_INLINE marpaWrapperBool_t _xml_1_0_buildRulesb(xml_1_0_t *xml_1_0p);
static C_INLINE marpaWrapperBool_t _xml_1_0_pushLexemeb(xml_1_0_t *xml_1_0p, xml_1_0_symbol_t xml_1_0_symbol, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion001b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion002b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion003b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion004b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion005b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion006b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion007b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex001b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex002b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex003b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex004b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex005b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex006b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex007b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex008b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex009b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex010b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex011b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex012b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex013b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex014b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex015b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex016b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex017b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex018b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex019b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex020b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex021b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex022b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex023b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex024b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex025b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex026b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex027b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex028b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex029b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex030b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex031b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex032b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex033b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex034b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex035b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex036b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex037b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex038b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex039b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex040b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex041b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex042b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex043b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex044b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex045b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex046b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex047b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex048b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex049b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex050b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex051b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex052b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex053b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex054b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex055b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex056b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex057b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex058b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex059b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex060b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex061b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex062b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex063b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex064b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex065b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex066b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex067b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex068b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex069b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex070b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex071b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex072b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex073b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex074b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex075b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex076b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex077b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex078b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex079b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex080b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex081b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex082b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex083b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex084b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex085b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex086b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex087b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex088b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex089b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex090b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex091b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex092b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex093b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex094b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex095b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex096b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex097b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex098b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex099b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex100b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex101b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex102b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex103b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex104b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex105b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex106b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex107b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex108b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp);

/*******************/
/* xml_1_0_newp  */
/*******************/
xml_1_0_t *xml_1_0_newp(marpaWrapperOption_t *marpaWrapperOptionp, xml_commonOption_t *xml_commonOptionp) {
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
static C_INLINE marpaWrapperBool_t _xml_1_0_buildGrammarb(xml_1_0_t *xml_1_0p, marpaWrapperOption_t *marpaWrapperOptionp) {

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
static C_INLINE marpaWrapperBool_t _xml_1_0_buildSymbolsb(xml_1_0_t *xml_1_0p) {
  return _xml_1_0_buildSymbols_withStartb(xml_1_0p, xml_1_0_document);
}

/**************************/
/* _xml_1_0_buildSymbols_withStartb */
/**************************/
static C_INLINE marpaWrapperBool_t _xml_1_0_buildSymbols_withStartb(xml_1_0_t *xml_1_0p, int starti) {
  int                        i;
  marpaWrapperSymbolOption_t marpaWrapperSymbolOption;

  xml_1_0p->marpaWrapperSymbolArrayp = malloc(XML_1_0_SYMBOL_MAX * sizeof(marpaWrapperSymbol_t *));
  if (xml_1_0p->marpaWrapperSymbolArrayp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }
  xml_1_0p->marpaWrapperSymbolArrayLengthi = XML_1_0_SYMBOL_MAX;

  for (i = 0; i < XML_1_0_SYMBOL_MAX; i++) {

    /* Fill default options */
    if (marpaWrapper_symbolOptionDefaultb(&marpaWrapperSymbolOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }

    /* Opaque data associated to symbol will be the symbol enum */
    marpaWrapperSymbolOption.datavp = (void *) i;

    /* Optional, but we can make ourself the terminals */
    marpaWrapperSymbolOption.terminalb = (i <= XML_1_0_TERMINAL_MAX) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;

    /* Start rule ? */
    marpaWrapperSymbolOption.startb = (i == starti) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;

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
    /* [xml_1_0_Char_001] Char ::= _Lex001  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex001]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_Char_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Char];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Char_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Char_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Char_002] Char ::= _Lex002  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex002]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_Char_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Char];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Char_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Char_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Char_003] Char ::= _Lex003  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex003]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_Char_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Char];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Char_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Char_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Char_004] Char ::= _Lex004  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex004]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_Char_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Char];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Char_004] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Char_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Char_005] Char ::= _Lex005  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex005]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_Char_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Char];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Char_005] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Char_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Char_006] Char ::= _Lex006  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex006]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_Char_006;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Char];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Char_006] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Char_006] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen009_001] _Gen009 ::= _Lex007  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex007]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen009_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen009];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen009_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen009_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen009_002] _Gen009 ::= _Lex001  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex001]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen009_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen009];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen009_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen009_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen009_003] _Gen009 ::= _Lex003  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex003]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen009_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen009];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen009_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen009_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen009_004] _Gen009 ::= _Lex002  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex002]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen009_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen009];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen009_004] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen009_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen009_many_001] _Gen009_many ::= _Gen009 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen009]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen009_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen009_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen009_many_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen009_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_S_001] S ::= _Gen009_many  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen009_many]
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
    /* [xml_1_0_NameStartChar_001] NameStartChar ::= _Lex008  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex008]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NameStartChar_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NameStartChar_002] NameStartChar ::= _Lex009  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex009]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NameStartChar_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NameStartChar_003] NameStartChar ::= _Lex010  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex010]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NameStartChar_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NameStartChar_004] NameStartChar ::= _Lex011  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex011]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NameStartChar_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_004] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NameStartChar_005] NameStartChar ::= _Lex012  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex012]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NameStartChar_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_005] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NameStartChar_006] NameStartChar ::= _Lex013  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex013]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NameStartChar_006;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_006] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_006] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NameStartChar_007] NameStartChar ::= _Lex014  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex014]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NameStartChar_007;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_007] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_007] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NameStartChar_008] NameStartChar ::= _Lex015  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex015]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NameStartChar_008;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_008] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_008] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NameStartChar_009] NameStartChar ::= _Lex016  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex016]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NameStartChar_009;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_009] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_009] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NameStartChar_010] NameStartChar ::= _Lex017  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex017]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NameStartChar_010;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_010] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_010] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NameStartChar_011] NameStartChar ::= _Lex018  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex018]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NameStartChar_011;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_011] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_011] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NameStartChar_012] NameStartChar ::= _Lex019  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex019]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NameStartChar_012;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_012] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_012] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NameStartChar_013] NameStartChar ::= _Lex020  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex020]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NameStartChar_013;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_013] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_013] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NameStartChar_014] NameStartChar ::= _Lex021  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex021]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NameStartChar_014;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_014] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_014] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NameStartChar_015] NameStartChar ::= _Lex022  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex022]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NameStartChar_015;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_015] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_015] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NameStartChar_016] NameStartChar ::= _Lex023  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex023]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NameStartChar_016;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_016] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameStartChar_016] == NULL) {
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
    /* [xml_1_0_NameChar_002] NameChar ::= _Lex024  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex024]
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
    /* [xml_1_0_NameChar_003] NameChar ::= _Lex025  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex025]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NameChar_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameChar_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameChar_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NameChar_004] NameChar ::= _Lex026  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex026]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NameChar_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameChar_004] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameChar_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NameChar_005] NameChar ::= _Lex027  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex027]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NameChar_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameChar_005] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameChar_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NameChar_006] NameChar ::= _Lex028  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex028]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NameChar_006;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameChar_006] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameChar_006] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NameChar_007] NameChar ::= _Lex029  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex029]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_NameChar_007;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameChar_007] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_NameChar_007] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen038_001] _Gen038 ::= NameChar  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen038_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen038];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen038_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen038_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen038_any_001] _Gen038_any ::= _Gen038 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen038]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen038_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen038_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen038_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen038_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Name_001] Name ::= NameStartChar _Gen038_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameStartChar],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen038_any]
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
    /* [xml_1_0__Gen041_001] _Gen041 ::= _Lex007 Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex007],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen041_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen041];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen041_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen041_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen041_any_001] _Gen041_any ::= _Gen041 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen041]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen041_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen041_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen041_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen041_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Names_001] Names ::= Name _Gen041_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen041_any]
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
    /* [xml_1_0__Gen044_001] _Gen044 ::= NameChar  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NameChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen044_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen044];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen044_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen044_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen044_many_001] _Gen044_many ::= _Gen044 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen044]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen044_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen044_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen044_many_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen044_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Nmtoken_001] Nmtoken ::= _Gen044_many  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen044_many]
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
    /* [xml_1_0__Gen047_001] _Gen047 ::= _Lex007 Nmtoken  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex007],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Nmtoken]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen047_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen047];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen047_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen047_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen047_any_001] _Gen047_any ::= _Gen047 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen047]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen047_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen047_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen047_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen047_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Nmtokens_001] Nmtokens ::= Nmtoken _Gen047_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Nmtoken],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen047_any]
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
    /* [xml_1_0__Gen050_001] _Gen050 ::= _Lex031  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex031]
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
    /* [xml_1_0__Gen050_002] _Gen050 ::= PEReference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PEReference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen050_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen050];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen050_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen050_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen050_003] _Gen050 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen050_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen050];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen050_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen050_003] == NULL) {
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
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen050_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen050_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen054_001] _Gen054 ::= _Lex033  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex033]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen054_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen054];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen054_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen054_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen054_002] _Gen054 ::= PEReference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PEReference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen054_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen054];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen054_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen054_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen054_003] _Gen054 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen054_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen054];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen054_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen054_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen054_any_001] _Gen054_any ::= _Gen054 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen054]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen054_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen054_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen054_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen054_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_EntityValue_001] EntityValue ::= _Lex030 _Gen050_any _Lex030  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex030],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen050_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex030]
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
    /* [xml_1_0_EntityValue_002] EntityValue ::= _Lex032 _Gen054_any _Lex032  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex032],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen054_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex032]
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
    /* [xml_1_0__Gen060_001] _Gen060 ::= _Lex034  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex034]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen060_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen060];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen060_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen060_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen060_002] _Gen060 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen060_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen060];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen060_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen060_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen060_any_001] _Gen060_any ::= _Gen060 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen060]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen060_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen060_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen060_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen060_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen063_001] _Gen063 ::= _Lex035  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex035]
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
    /* [xml_1_0__Gen063_002] _Gen063 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen063_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen063];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen063_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen063_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen063_any_001] _Gen063_any ::= _Gen063 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen063]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen063_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen063_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen063_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen063_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_AttValue_001] AttValue ::= _Lex030 _Gen060_any _Lex030  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex030],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen060_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex030]
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
    /* [xml_1_0_AttValue_002] AttValue ::= _Lex032 _Gen063_any _Lex032  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex032],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen063_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex032]
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
    /* [xml_1_0__Lex036_any_001] _Lex036_any ::= _Lex036 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex036]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Lex036_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex036_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Lex036_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Lex036_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen069_001] _Gen069 ::= _Lex030 _Lex036_any _Lex030  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex030],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex036_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex030]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen069_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen069];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen069_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen069_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Lex037_any_001] _Lex037_any ::= _Lex037 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex037]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Lex037_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex037_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Lex037_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Lex037_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen071_001] _Gen071 ::= _Lex032 _Lex037_any _Lex032  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex032],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex037_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex032]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen071_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen071];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen071_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen071_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_SystemLiteral_001] SystemLiteral ::= _Gen069  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen069]
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
    /* [xml_1_0_SystemLiteral_002] SystemLiteral ::= _Gen071  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen071]
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
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PubidChar_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PubidChar_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen075_001] _Gen075 ::= _Exclusion001  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Exclusion001]
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
    /* [xml_1_0__Gen076_001] _Gen076 ::= _Gen075  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen075]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen076_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen076];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen076_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen076_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen076_any_001] _Gen076_any ::= _Gen076 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen076]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen076_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen076_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen076_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen076_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_PubidLiteral_001] PubidLiteral ::= _Lex030 PubidChar_any _Lex030  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex030],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PubidChar_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex030]
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
    /* [xml_1_0_PubidLiteral_002] PubidLiteral ::= _Lex032 _Gen076_any _Lex032  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex032],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen076_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex032]
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
    /* [xml_1_0_PubidChar_001] PubidChar ::= _Lex007  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex007]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_PubidChar_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PubidChar_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PubidChar_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_PubidChar_002] PubidChar ::= _Lex003  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex003]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_PubidChar_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PubidChar_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PubidChar_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_PubidChar_003] PubidChar ::= _Lex002  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex002]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_PubidChar_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PubidChar_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PubidChar_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_PubidChar_004] PubidChar ::= _Lex038  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex038]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_PubidChar_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PubidChar_004] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PubidChar_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_PubidChar_005] PubidChar ::= _Lex039  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex039]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_PubidChar_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PubidChar_005] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_PubidChar_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Lex040_any_001] _Lex040_any ::= _Lex040 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex040]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Lex040_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex040_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Lex040_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Lex040_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen086_001] _Gen086 ::= _Lex040_any _Lex041 _Lex040_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex040_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex041],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex040_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen086_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen086];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen086_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen086_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen087_001] _Gen087 ::= _Exclusion002  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Exclusion002]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen087_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen087];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen087_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen087_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_CharData_001] CharData ::= _Gen087  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen087]
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
    /* [xml_1_0__Gen089_001] _Gen089 ::= _Exclusion003  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Exclusion003]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen089_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen089];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen089_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen089_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen090_001] _Gen090 ::= _Gen089  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen089]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen090_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen090];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen090_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen090_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen091_001] _Gen091 ::= _Exclusion003  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Exclusion003]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen091_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen091];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen091_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen091_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen092_001] _Gen092 ::= _Gen091  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen091]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen092_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen092];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen092_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen092_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen093_001] _Gen093 ::= _Lex024 _Gen092  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex024],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen092]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen093_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen093];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen093_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen093_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen094_001] _Gen094 ::= _Gen090  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen090]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen094_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen094];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen094_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen094_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen094_002] _Gen094 ::= _Gen093  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen093]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen094_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen094];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen094_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen094_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen094_any_001] _Gen094_any ::= _Gen094 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen094]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen094_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen094_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen094_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen094_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Comment_001] Comment ::= _Lex042 _Gen094_any _Lex043  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex042],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen094_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex043]
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
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Char_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_Char_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen099_001] _Gen099 ::= Char_any _Lex045 Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Char_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex045],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen099_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen099];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen099_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen099_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen100_001] _Gen100 ::= _Exclusion004  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Exclusion004]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen100_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen100];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen100_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen100_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen101_001] _Gen101 ::= _Gen100  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen100]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen101_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen101];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen101_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen101_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen102_001] _Gen102 ::= S _Gen101  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen101]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen102_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen102];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen102_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen102_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen102_maybe_001] _Gen102_maybe ::= _Gen102  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen102]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen102_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen102_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen102_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen102_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen102_maybe_002] _Gen102_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen102_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen102_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen102_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen102_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_PI_001] PI ::= _Lex044 PITarget _Gen102_maybe _Lex045  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex044],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PITarget],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen102_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex045]
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
    /* [xml_1_0__Gen106_001] _Gen106 ::= _Lex046  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex046]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen106_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen106];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen106_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen106_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen106_002] _Gen106 ::= _Lex047  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex047]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen106_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen106];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen106_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen106_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen108_001] _Gen108 ::= _Lex048  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex048]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen108_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen108];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen108_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen108_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen108_002] _Gen108 ::= _Lex049  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex049]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen108_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen108];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen108_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen108_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen110_001] _Gen110 ::= _Lex050  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex050]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen110_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen110];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen110_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen110_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen110_002] _Gen110 ::= _Lex051  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex051]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen110_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen110];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen110_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen110_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen112_001] _Gen112 ::= _Gen106 _Gen108 _Gen110  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen106],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen108],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen110]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen112_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen112];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen112_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen112_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen113_001] _Gen113 ::= _Exclusion005  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Exclusion005]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen113_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen113];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen113_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen113_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_PITarget_001] PITarget ::= _Gen113  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen113]
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
    /* [xml_1_0_CDStart_001] CDStart ::= _Lex052  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex052]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_CDStart_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_CDStart];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_CDStart_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_CDStart_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen117_001] _Gen117 ::= Char_any _Lex041 Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Char_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex041],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen117_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen117];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen117_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen117_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen118_001] _Gen118 ::= _Exclusion006  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Exclusion006]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen118_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen118];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen118_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen118_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen119_001] _Gen119 ::= _Gen118  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen118]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen119_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen119];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen119_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen119_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_CData_001] CData ::= _Gen119  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen119]
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
    /* [xml_1_0_CDEnd_001] CDEnd ::= _Lex041  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex041]
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
    /* [xml_1_0__Gen124_001] _Gen124 ::= doctypedecl Misc_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_doctypedecl],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Misc_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen124_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen124];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen124_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen124_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen124_maybe_001] _Gen124_maybe ::= _Gen124  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen124]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen124_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen124_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen124_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen124_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen124_maybe_002] _Gen124_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen124_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen124_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen124_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen124_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_prolog_001] prolog ::= XMLDecl_maybe Misc_any _Gen124_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_XMLDecl_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Misc_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen124_maybe]
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
    /* [xml_1_0_XMLDecl_001] XMLDecl ::= _Lex053 VersionInfo EncodingDecl_maybe SDDecl_maybe S_maybe _Lex045  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex053],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_VersionInfo],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EncodingDecl_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_SDDecl_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex045]
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
    /* [xml_1_0__Gen135_001] _Gen135 ::= _Lex032 VersionNum _Lex032  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex032],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_VersionNum],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex032]
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
    /* [xml_1_0__Gen135_002] _Gen135 ::= _Lex030 VersionNum _Lex030  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex030],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_VersionNum],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex030]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen135_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen135];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen135_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen135_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_VersionInfo_001] VersionInfo ::= S _Lex054 Eq _Gen135  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex054],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Eq],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen135]
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
    /* [xml_1_0_Eq_001] Eq ::= S_maybe _Lex055 S_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex055],
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
    /* [xml_1_0__Lex026_many_001] _Lex026_many ::= _Lex026 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex026]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Lex026_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex026_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Lex026_many_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Lex026_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_VersionNum_001] VersionNum ::= _Lex056 _Lex026_many  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex056],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex026_many]
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
    /* [xml_1_0__Gen144_001] _Gen144 ::= S ExternalID  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_ExternalID]
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
    /* [xml_1_0__Gen144_maybe_001] _Gen144_maybe ::= _Gen144  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen144]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen144_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen144_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen144_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen144_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen144_maybe_002] _Gen144_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen144_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen144_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen144_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen144_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen147_001] _Gen147 ::= _Lex058 intSubset _Lex059 S_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex058],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_intSubset],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex059],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen147_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen147];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen147_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen147_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen147_maybe_001] _Gen147_maybe ::= _Gen147  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen147]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen147_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen147_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen147_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen147_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen147_maybe_002] _Gen147_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen147_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen147_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen147_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen147_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_doctypedecl_001] doctypedecl ::= _Lex057 S Name _Gen144_maybe S_maybe _Gen147_maybe _Lex060  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex057],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen144_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen147_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex060]
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
    /* [xml_1_0__Gen153_001] _Gen153 ::= markupdecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_markupdecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen153_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen153];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen153_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen153_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen153_002] _Gen153 ::= DeclSep  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_DeclSep]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen153_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen153];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen153_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen153_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen153_any_001] _Gen153_any ::= _Gen153 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen153]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen153_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen153_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen153_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen153_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_intSubset_001] intSubset ::= _Gen153_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen153_any]
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
    /* [xml_1_0__Gen166_001] _Gen166 ::= markupdecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_markupdecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen166_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen166];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen166_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen166_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen166_002] _Gen166 ::= conditionalSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_conditionalSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen166_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen166];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen166_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen166_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen166_003] _Gen166 ::= DeclSep  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_DeclSep]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen166_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen166];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen166_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen166_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen166_any_001] _Gen166_any ::= _Gen166 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen166]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen166_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen166_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen166_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen166_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_extSubsetDecl_001] extSubsetDecl ::= _Gen166_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen166_any]
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
    /* [xml_1_0__Gen171_001] _Gen171 ::= _Lex062  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex062]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen171_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen171];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen171_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen171_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen171_002] _Gen171 ::= _Lex063  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex063]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen171_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen171];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen171_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen171_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen173_001] _Gen173 ::= _Lex032 _Gen171 _Lex032  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex032],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen171],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex032]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen173_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen173];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen173_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen173_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen174_001] _Gen174 ::= _Lex062  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex062]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen174_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen174];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen174_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen174_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen174_002] _Gen174 ::= _Lex063  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex063]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen174_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen174];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen174_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen174_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen176_001] _Gen176 ::= _Lex030 _Gen174 _Lex030  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex030],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen174],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex030]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen176_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen176];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen176_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen176_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen177_001] _Gen177 ::= _Gen173  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen173]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen177_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen177];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen177_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen177_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen177_002] _Gen177 ::= _Gen176  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen176]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen177_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen177];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen177_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen177_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_SDDecl_001] SDDecl ::= S _Lex061 Eq _Gen177  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex061],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Eq],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen177]
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
    /* [xml_1_0__Gen182_001] _Gen182 ::= S Attribute  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Attribute]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen182_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen182];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen182_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen182_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen182_any_001] _Gen182_any ::= _Gen182 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen182]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen182_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen182_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen182_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen182_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_STag_001] STag ::= _Lex064 Name _Gen182_any S_maybe _Lex060  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex064],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen182_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex060]
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
    /* [xml_1_0_ETag_001] ETag ::= _Lex065 Name S_maybe _Lex060  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex065],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex060]
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
    /* [xml_1_0__Gen189_001] _Gen189 ::= element  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_element]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen189_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen189];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen189_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen189_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen189_002] _Gen189 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen189_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen189];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen189_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen189_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen189_003] _Gen189 ::= CDSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_CDSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen189_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen189];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen189_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen189_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen189_004] _Gen189 ::= PI  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PI]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen189_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen189];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen189_004] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen189_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen189_005] _Gen189 ::= Comment  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Comment]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen189_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen189];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen189_005] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen189_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen194_001] _Gen194 ::= _Gen189 CharData_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen189],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_CharData_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen194_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen194];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen194_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen194_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen194_any_001] _Gen194_any ::= _Gen194 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen194]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen194_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen194_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen194_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen194_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_content_001] content ::= CharData_maybe _Gen194_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_CharData_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen194_any]
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
    /* [xml_1_0__Gen197_001] _Gen197 ::= S Attribute  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Attribute]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen197_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen197];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen197_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen197_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen197_any_001] _Gen197_any ::= _Gen197 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen197]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen197_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen197_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen197_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen197_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_EmptyElemTag_001] EmptyElemTag ::= _Lex064 Name _Gen197_any S_maybe _Lex066  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex064],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen197_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex066]
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
    /* [xml_1_0_elementdecl_001] elementdecl ::= _Lex067 S Name S contentspec S_maybe _Lex060  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex067],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_contentspec],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex060]
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
    /* [xml_1_0_contentspec_001] contentspec ::= _Lex068  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex068]
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
    /* [xml_1_0_contentspec_002] contentspec ::= _Lex069  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex069]
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
    /* [xml_1_0__Gen205_001] _Gen205 ::= choice  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_choice]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen205_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen205];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen205_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen205_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen205_002] _Gen205 ::= seq  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_seq]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen205_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen205];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen205_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen205_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen207_001] _Gen207 ::= _Lex070  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex070]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen207_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen207];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen207_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen207_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen207_002] _Gen207 ::= _Lex071  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex071]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen207_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen207];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen207_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen207_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen207_003] _Gen207 ::= _Lex072  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex072]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen207_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen207];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen207_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen207_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen207_maybe_001] _Gen207_maybe ::= _Gen207  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen207]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen207_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen207_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen207_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen207_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen207_maybe_002] _Gen207_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen207_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen207_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen207_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen207_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_children_001] children ::= _Gen205 _Gen207_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen205],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen207_maybe]
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
    /* [xml_1_0__Gen213_001] _Gen213 ::= Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen213_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen213];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen213_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen213_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen213_002] _Gen213 ::= choice  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_choice]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen213_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen213];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen213_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen213_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen213_003] _Gen213 ::= seq  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_seq]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen213_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen213];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen213_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen213_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen216_001] _Gen216 ::= _Lex070  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex070]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen216_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen216];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen216_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen216_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen216_002] _Gen216 ::= _Lex071  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex071]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen216_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen216];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen216_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen216_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen216_003] _Gen216 ::= _Lex072  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex072]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen216_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen216];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen216_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen216_003] == NULL) {
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
    /* [xml_1_0_cp_001] cp ::= _Gen213 _Gen216_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen213],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen216_maybe]
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
    /* [xml_1_0__Gen222_001] _Gen222 ::= S_maybe _Lex074 S_maybe cp  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex074],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_cp]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen222_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen222];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen222_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen222_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen222_many_001] _Gen222_many ::= _Gen222 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen222]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen222_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen222_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen222_many_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen222_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_choice_001] choice ::= _Lex073 S_maybe cp _Gen222_many S_maybe _Lex075  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex073],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_cp],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen222_many],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex075]
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
    /* [xml_1_0__Gen225_001] _Gen225 ::= S_maybe _Lex076 S_maybe cp  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex076],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_cp]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen225_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen225];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen225_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen225_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen225_any_001] _Gen225_any ::= _Gen225 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen225]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen225_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen225_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen225_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen225_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_seq_001] seq ::= _Lex073 S_maybe cp _Gen225_any S_maybe _Lex075  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex073],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_cp],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen225_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex075]
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
    /* [xml_1_0__Gen228_001] _Gen228 ::= S_maybe _Lex074 S_maybe Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex074],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name]
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
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen228_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen228_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Mixed_001] Mixed ::= _Lex073 S_maybe _Lex077 _Gen228_any S_maybe _Lex078  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex073],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex077],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen228_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex078]
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
    /* [xml_1_0_Mixed_002] Mixed ::= _Lex073 S_maybe _Lex077 S_maybe _Lex075  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex073],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex077],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex075]
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
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_AttDef_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_AttDef_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_AttlistDecl_001] AttlistDecl ::= _Lex079 S Name AttDef_any S_maybe _Lex060  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex079],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_AttDef_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex060]
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
    /* [xml_1_0_StringType_001] StringType ::= _Lex080  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex080]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0_StringType_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_StringType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_StringType_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_StringType_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_TokenizedType_001] TokenizedType ::= _Lex081  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex081]
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
    /* [xml_1_0_TokenizedType_002] TokenizedType ::= _Lex082  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex082]
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
    /* [xml_1_0_TokenizedType_003] TokenizedType ::= _Lex083  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex083]
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
    /* [xml_1_0_TokenizedType_004] TokenizedType ::= _Lex084  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex084]
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
    /* [xml_1_0_TokenizedType_005] TokenizedType ::= _Lex085  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex085]
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
    /* [xml_1_0_TokenizedType_006] TokenizedType ::= _Lex086  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex086]
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
    /* [xml_1_0_TokenizedType_007] TokenizedType ::= _Lex087  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex087]
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
    /* [xml_1_0__Gen248_001] _Gen248 ::= S_maybe _Lex074 S_maybe Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex074],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen248_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen248];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen248_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen248_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen248_any_001] _Gen248_any ::= _Gen248 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen248]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen248_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen248_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen248_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen248_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NotationType_001] NotationType ::= _Lex088 S _Lex073 S_maybe Name _Gen248_any S_maybe _Lex075  */
    marpaWrapperSymbol_t *rhsSymbolpp[8] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex088],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex073],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen248_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex075]
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
    /* [xml_1_0__Gen251_001] _Gen251 ::= S_maybe _Lex074 S_maybe Nmtoken  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex074],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Nmtoken]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen251_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen251];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen251_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen251_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen251_any_001] _Gen251_any ::= _Gen251 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen251]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen251_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen251_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen251_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen251_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Enumeration_001] Enumeration ::= _Lex073 S_maybe Nmtoken _Gen251_any S_maybe _Lex075  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex073],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Nmtoken],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen251_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex075]
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
    /* [xml_1_0__Gen254_001] _Gen254 ::= _Lex091 S  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex091],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen254_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen254];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen254_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen254_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen254_maybe_001] _Gen254_maybe ::= _Gen254  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen254]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen254_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen254_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen254_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen254_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen254_maybe_002] _Gen254_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen254_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen254_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen254_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen254_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen257_001] _Gen257 ::= _Gen254_maybe AttValue  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen254_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_AttValue]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen257_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen257];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen257_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen257_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_DefaultDecl_001] DefaultDecl ::= _Lex089  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex089]
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
    /* [xml_1_0_DefaultDecl_002] DefaultDecl ::= _Lex090  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex090]
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
    /* [xml_1_0_DefaultDecl_003] DefaultDecl ::= _Gen257  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen257]
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
    /* [xml_1_0_includeSect_001] includeSect ::= _Lex092 S_maybe _Lex093 S_maybe _Lex058 extSubsetDecl _Lex041  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex092],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex093],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex058],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_extSubsetDecl],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex041]
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
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_ignoreSectContents_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0_ignoreSectContents_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_ignoreSect_001] ignoreSect ::= _Lex092 S_maybe _Lex094 S_maybe _Lex058 ignoreSectContents_any _Lex041  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex092],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex094],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex058],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_ignoreSectContents_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex041]
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
    /* [xml_1_0__Gen266_001] _Gen266 ::= _Lex092 ignoreSectContents _Lex041 Ignore  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex092],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_ignoreSectContents],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex041],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Ignore]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen266_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen266];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen266_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen266_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen266_any_001] _Gen266_any ::= _Gen266 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen266]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen266_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen266_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen266_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen266_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_ignoreSectContents_001] ignoreSectContents ::= Ignore _Gen266_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Ignore],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen266_any]
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
    /* [xml_1_0__Gen269_001] _Gen269 ::= _Lex092  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex092]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen269_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen269];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen269_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen269_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen269_002] _Gen269 ::= _Lex041  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex041]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen269_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen269];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen269_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen269_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen271_001] _Gen271 ::= Char_any _Gen269 Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Char_any],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen269],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen271_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen271];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen271_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen271_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen272_001] _Gen272 ::= _Exclusion007  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Exclusion007]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen272_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen272];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen272_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen272_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_Ignore_001] Ignore ::= _Gen272  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen272]
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
    /* [xml_1_0__Lex098_many_001] _Lex098_many ::= _Lex098 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex098]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Lex098_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex098_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Lex098_many_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Lex098_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_CharRef_001] CharRef ::= _Lex095 _Lex026_many _Lex096  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex095],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex026_many],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex096]
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
    /* [xml_1_0_CharRef_002] CharRef ::= _Lex097 _Lex098_many _Lex096  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex097],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex098_many],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex096]
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
    /* [xml_1_0_EntityRef_001] EntityRef ::= _Lex099 Name _Lex096  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex099],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex096]
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
    /* [xml_1_0_PEReference_001] PEReference ::= _Lex100 Name _Lex096  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex100],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex096]
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
    /* [xml_1_0_GEDecl_001] GEDecl ::= _Lex101 S Name S EntityDef S_maybe _Lex060  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex101],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EntityDef],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex060]
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
    /* [xml_1_0_PEDecl_001] PEDecl ::= _Lex101 S _Lex100 S Name S PEDef S_maybe _Lex060  */
    marpaWrapperSymbol_t *rhsSymbolpp[9] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex101],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex100],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PEDef],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex060]
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
    /* [xml_1_0__Gen287_001] _Gen287 ::= ExternalID NDataDecl_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_ExternalID],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_NDataDecl_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen287_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen287];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen287_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen287_001] == NULL) {
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
    /* [xml_1_0_EntityDef_002] EntityDef ::= _Gen287  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen287]
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
    /* [xml_1_0_ExternalID_001] ExternalID ::= _Lex102 S SystemLiteral  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex102],
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
    /* [xml_1_0_ExternalID_002] ExternalID ::= _Lex103 S PubidLiteral S SystemLiteral  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex103],
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
    /* [xml_1_0_NDataDecl_001] NDataDecl ::= S _Lex104 S Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex104],
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
    /* [xml_1_0_TextDecl_001] TextDecl ::= _Lex053 VersionInfo_maybe EncodingDecl S_maybe _Lex045  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex053],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_VersionInfo_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EncodingDecl],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex045]
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
    /* [xml_1_0__Gen299_001] _Gen299 ::= _Lex030 EncName _Lex030  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex030],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EncName],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex030]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen299_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen299];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen299_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen299_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen299_002] _Gen299 ::= _Lex032 EncName _Lex032  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex032],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_EncName],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex032]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen299_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen299];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen299_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen299_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_EncodingDecl_001] EncodingDecl ::= S _Lex105 Eq _Gen299  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex105],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Eq],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen299]
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
    /* [xml_1_0__Gen302_001] _Gen302 ::= _Lex107  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex107]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen302_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen302];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen302_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen302_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen302_002] _Gen302 ::= _Lex024  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex024]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen302_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen302];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen302_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen302_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen302_any_001] _Gen302_any ::= _Gen302 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen302]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen302_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen302_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen302_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen302_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_EncName_001] EncName ::= _Lex106 _Gen302_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex106],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen302_any]
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
    /* [xml_1_0__Gen306_001] _Gen306 ::= ExternalID  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_ExternalID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen306_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen306];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen306_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen306_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0__Gen306_002] _Gen306 ::= PublicID  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_PublicID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_0__Gen306_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen306];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen306_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[xml_1_0__Gen306_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_0_NotationDecl_001] NotationDecl ::= _Lex108 S Name S _Gen306 S_maybe _Lex060  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex108],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_Name],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Gen306],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0_S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex060]
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
    /* [xml_1_0_PublicID_001] PublicID ::= _Lex103 S PubidLiteral  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[xml_1_0__Lex103],
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
/* _xml_1_0_pushLexemeb */
/************************/

static C_INLINE marpaWrapperBool_t _xml_1_0_pushLexemeb(xml_1_0_t *xml_1_0p, xml_1_0_symbol_t xml_1_0_symbol, signed int currenti, streamIn_t *streamInp) {
  marpaWrapperBool_t rcb;

  switch (xml_1_0_symbol) {
    case xml_1_0__Exclusion001:
      rcb = _xml_1_0__Exclusion001b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Exclusion002:
      rcb = _xml_1_0__Exclusion002b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Exclusion003:
      rcb = _xml_1_0__Exclusion003b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Exclusion004:
      rcb = _xml_1_0__Exclusion004b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Exclusion005:
      rcb = _xml_1_0__Exclusion005b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Exclusion006:
      rcb = _xml_1_0__Exclusion006b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Exclusion007:
      rcb = _xml_1_0__Exclusion007b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex001:
      rcb = _xml_1_0__Lex001b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex002:
      rcb = _xml_1_0__Lex002b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex003:
      rcb = _xml_1_0__Lex003b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex004:
      rcb = _xml_1_0__Lex004b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex005:
      rcb = _xml_1_0__Lex005b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex006:
      rcb = _xml_1_0__Lex006b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex007:
      rcb = _xml_1_0__Lex007b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex008:
      rcb = _xml_1_0__Lex008b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex009:
      rcb = _xml_1_0__Lex009b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex010:
      rcb = _xml_1_0__Lex010b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex011:
      rcb = _xml_1_0__Lex011b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex012:
      rcb = _xml_1_0__Lex012b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex013:
      rcb = _xml_1_0__Lex013b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex014:
      rcb = _xml_1_0__Lex014b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex015:
      rcb = _xml_1_0__Lex015b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex016:
      rcb = _xml_1_0__Lex016b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex017:
      rcb = _xml_1_0__Lex017b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex018:
      rcb = _xml_1_0__Lex018b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex019:
      rcb = _xml_1_0__Lex019b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex020:
      rcb = _xml_1_0__Lex020b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex021:
      rcb = _xml_1_0__Lex021b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex022:
      rcb = _xml_1_0__Lex022b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex023:
      rcb = _xml_1_0__Lex023b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex024:
      rcb = _xml_1_0__Lex024b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex025:
      rcb = _xml_1_0__Lex025b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex026:
      rcb = _xml_1_0__Lex026b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex027:
      rcb = _xml_1_0__Lex027b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex028:
      rcb = _xml_1_0__Lex028b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex029:
      rcb = _xml_1_0__Lex029b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex030:
      rcb = _xml_1_0__Lex030b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex031:
      rcb = _xml_1_0__Lex031b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex032:
      rcb = _xml_1_0__Lex032b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex033:
      rcb = _xml_1_0__Lex033b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex034:
      rcb = _xml_1_0__Lex034b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex035:
      rcb = _xml_1_0__Lex035b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex036:
      rcb = _xml_1_0__Lex036b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex037:
      rcb = _xml_1_0__Lex037b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex038:
      rcb = _xml_1_0__Lex038b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex039:
      rcb = _xml_1_0__Lex039b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex040:
      rcb = _xml_1_0__Lex040b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex041:
      rcb = _xml_1_0__Lex041b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex042:
      rcb = _xml_1_0__Lex042b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex043:
      rcb = _xml_1_0__Lex043b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex044:
      rcb = _xml_1_0__Lex044b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex045:
      rcb = _xml_1_0__Lex045b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex046:
      rcb = _xml_1_0__Lex046b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex047:
      rcb = _xml_1_0__Lex047b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex048:
      rcb = _xml_1_0__Lex048b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex049:
      rcb = _xml_1_0__Lex049b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex050:
      rcb = _xml_1_0__Lex050b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex051:
      rcb = _xml_1_0__Lex051b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex052:
      rcb = _xml_1_0__Lex052b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex053:
      rcb = _xml_1_0__Lex053b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex054:
      rcb = _xml_1_0__Lex054b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex055:
      rcb = _xml_1_0__Lex055b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex056:
      rcb = _xml_1_0__Lex056b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex057:
      rcb = _xml_1_0__Lex057b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex058:
      rcb = _xml_1_0__Lex058b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex059:
      rcb = _xml_1_0__Lex059b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex060:
      rcb = _xml_1_0__Lex060b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex061:
      rcb = _xml_1_0__Lex061b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex062:
      rcb = _xml_1_0__Lex062b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex063:
      rcb = _xml_1_0__Lex063b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex064:
      rcb = _xml_1_0__Lex064b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex065:
      rcb = _xml_1_0__Lex065b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex066:
      rcb = _xml_1_0__Lex066b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex067:
      rcb = _xml_1_0__Lex067b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex068:
      rcb = _xml_1_0__Lex068b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex069:
      rcb = _xml_1_0__Lex069b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex070:
      rcb = _xml_1_0__Lex070b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex071:
      rcb = _xml_1_0__Lex071b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex072:
      rcb = _xml_1_0__Lex072b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex073:
      rcb = _xml_1_0__Lex073b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex074:
      rcb = _xml_1_0__Lex074b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex075:
      rcb = _xml_1_0__Lex075b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex076:
      rcb = _xml_1_0__Lex076b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex077:
      rcb = _xml_1_0__Lex077b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex078:
      rcb = _xml_1_0__Lex078b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex079:
      rcb = _xml_1_0__Lex079b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex080:
      rcb = _xml_1_0__Lex080b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex081:
      rcb = _xml_1_0__Lex081b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex082:
      rcb = _xml_1_0__Lex082b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex083:
      rcb = _xml_1_0__Lex083b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex084:
      rcb = _xml_1_0__Lex084b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex085:
      rcb = _xml_1_0__Lex085b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex086:
      rcb = _xml_1_0__Lex086b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex087:
      rcb = _xml_1_0__Lex087b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex088:
      rcb = _xml_1_0__Lex088b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex089:
      rcb = _xml_1_0__Lex089b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex090:
      rcb = _xml_1_0__Lex090b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex091:
      rcb = _xml_1_0__Lex091b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex092:
      rcb = _xml_1_0__Lex092b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex093:
      rcb = _xml_1_0__Lex093b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex094:
      rcb = _xml_1_0__Lex094b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex095:
      rcb = _xml_1_0__Lex095b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex096:
      rcb = _xml_1_0__Lex096b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex097:
      rcb = _xml_1_0__Lex097b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex098:
      rcb = _xml_1_0__Lex098b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex099:
      rcb = _xml_1_0__Lex099b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex100:
      rcb = _xml_1_0__Lex100b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex101:
      rcb = _xml_1_0__Lex101b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex102:
      rcb = _xml_1_0__Lex102b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex103:
      rcb = _xml_1_0__Lex103b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex104:
      rcb = _xml_1_0__Lex104b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex105:
      rcb = _xml_1_0__Lex105b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex106:
      rcb = _xml_1_0__Lex106b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex107:
      rcb = _xml_1_0__Lex107b(xml_1_0p, currenti, streamInp);
      break;
    case xml_1_0__Lex108:
      rcb = _xml_1_0__Lex108b(xml_1_0p, currenti, streamInp);
      break;
    default:
      rcb = MARPAWRAPPER_BOOL_FALSE;
      break;
  }

  return rcb;
}
/************************************************
  _Exclusion001 ~ 'PubidChar - _Lex032'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion001b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Exclusion002 ~ '_Lex040_any - _Gen086'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion002b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Exclusion003 ~ 'Char - _Lex024'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion003b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Exclusion004 ~ 'Char_any - _Gen099'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion004b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Exclusion005 ~ 'Name - _Gen112'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion005b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Exclusion006 ~ 'Char_any - _Gen117'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion006b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Exclusion007 ~ 'Char_any - _Gen271'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion007b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Lex001 ~ [\x{9}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex001b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x9 /* #x9 */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex002 ~ [\x{a}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex002b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0xa /* #xa */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex003 ~ [\x{d}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex003b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0xd /* #xd */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex004 ~ [\x{20}-\x{d7ff}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex004b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x20 && currenti <= 0xd7ff /* [#x20-#xd7ff] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex005 ~ [\x{e000}-\x{fffd}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex005b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0xe000 && currenti <= 0xfffd /* [#xe000-#xfffd] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex006 ~ [\x{10000}-\x{10ffff}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex006b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x10000 && currenti <= 0x10ffff /* [#x10000-#x10ffff] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex007 ~ [\x{20}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex007b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x20 /* #x20 */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex008 ~ ':'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex008b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x3a /* : */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex009 ~ [A-Z]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex009b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x41 && currenti <= 0x5a /* [A-Z] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex010 ~ '_'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex010b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x5f /* _ */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex011 ~ [a-z]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex011b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x61 && currenti <= 0x7a /* [a-z] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex012 ~ [\x{c0}-\x{d6}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex012b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0xc0 && currenti <= 0xd6 /* [#xc0-#xd6] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex013 ~ [\x{d8}-\x{f6}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex013b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0xd8 && currenti <= 0xf6 /* [#xd8-#xf6] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex014 ~ [\x{f8}-\x{2ff}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex014b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0xf8 && currenti <= 0x2ff /* [#xf8-#x2ff] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex015 ~ [\x{370}-\x{37d}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex015b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x370 && currenti <= 0x37d /* [#x370-#x37d] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex016 ~ [\x{37f}-\x{1fff}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex016b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x37f && currenti <= 0x1fff /* [#x37f-#x1fff] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex017 ~ [\x{200c}-\x{200d}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex017b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x200c && currenti <= 0x200d /* [#x200c-#x200d] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex018 ~ [\x{2070}-\x{218f}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex018b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x2070 && currenti <= 0x218f /* [#x2070-#x218f] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex019 ~ [\x{2c00}-\x{2fef}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex019b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x2c00 && currenti <= 0x2fef /* [#x2c00-#x2fef] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex020 ~ [\x{3001}-\x{d7ff}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex020b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x3001 && currenti <= 0xd7ff /* [#x3001-#xd7ff] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex021 ~ [\x{f900}-\x{fdcf}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex021b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0xf900 && currenti <= 0xfdcf /* [#xf900-#xfdcf] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex022 ~ [\x{fdf0}-\x{fffd}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex022b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0xfdf0 && currenti <= 0xfffd /* [#xfdf0-#xfffd] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex023 ~ [\x{10000}-\x{effff}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex023b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x10000 && currenti <= 0xeffff /* [#x10000-#xeffff] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex024 ~ '-'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex024b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x2d /* - */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex025 ~ '.'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex025b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x2e /* . */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex026 ~ [0-9]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex026b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x30 && currenti <= 0x39 /* [0-9] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex027 ~ [\x{b7}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex027b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0xb7 /* #xb7 */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex028 ~ [\x{300}-\x{36f}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex028b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x300 && currenti <= 0x36f /* [#x300-#x36f] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex029 ~ [\x{203f}-\x{2040}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex029b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti >= 0x203f && currenti <= 0x2040 /* [#x203f-#x2040] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex030 ~ '"'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex030b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x22 /* " */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex031 ~ [^%&"]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex031b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return ((currenti == 0x25) /* % */ ||
          (currenti == 0x26) /* & */ ||
          (currenti == 0x22) /* " */) ? MARPAWRAPPER_BOOL_FALSE : MARPAWRAPPER_BOOL_TRUE;
}
/************************************************
  _Lex032 ~ [']
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex032b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x27 /* ' */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex033 ~ [^%&']
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex033b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return ((currenti == 0x25) /* % */ ||
          (currenti == 0x26) /* & */ ||
          (currenti == 0x27) /* ' */) ? MARPAWRAPPER_BOOL_FALSE : MARPAWRAPPER_BOOL_TRUE;
}
/************************************************
  _Lex034 ~ [^<&"]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex034b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return ((currenti == 0x3c) /* < */ ||
          (currenti == 0x26) /* & */ ||
          (currenti == 0x22) /* " */) ? MARPAWRAPPER_BOOL_FALSE : MARPAWRAPPER_BOOL_TRUE;
}
/************************************************
  _Lex035 ~ [^<&']
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex035b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return ((currenti == 0x3c) /* < */ ||
          (currenti == 0x26) /* & */ ||
          (currenti == 0x27) /* ' */) ? MARPAWRAPPER_BOOL_FALSE : MARPAWRAPPER_BOOL_TRUE;
}
/************************************************
  _Lex036 ~ [^"]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex036b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x22 /* " */) ? MARPAWRAPPER_BOOL_FALSE : MARPAWRAPPER_BOOL_TRUE;
}
/************************************************
  _Lex037 ~ [^']
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex037b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x27 /* ' */) ? MARPAWRAPPER_BOOL_FALSE : MARPAWRAPPER_BOOL_TRUE;
}
/************************************************
  _Lex038 ~ [a-zA-Z0-9]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex038b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return ((currenti >= 0x61 && currenti <= 0x7a) /* [a-z] */ ||
          (currenti >= 0x41 && currenti <= 0x5a) /* [A-Z] */ ||
          (currenti >= 0x30 && currenti <= 0x39) /* [0-9] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex039 ~ [-'()+,./:=?;!*#@$_%]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex039b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex040 ~ [^<&]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex040b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return ((currenti == 0x3c) /* < */ ||
          (currenti == 0x26) /* & */) ? MARPAWRAPPER_BOOL_FALSE : MARPAWRAPPER_BOOL_TRUE;
}
/************************************************
  _Lex041 ~ ']]>'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex041b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex042 ~ '<!--'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex042b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex043 ~ '-->'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex043b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex044 ~ '<?'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex044b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex045 ~ '?>'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex045b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex046 ~ 'X'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex046b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x58 /* X */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex047 ~ 'x'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex047b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x78 /* x */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex048 ~ 'M'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex048b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x4d /* M */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex049 ~ 'm'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex049b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x6d /* m */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex050 ~ 'L'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex050b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x4c /* L */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex051 ~ 'l'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex051b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x6c /* l */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex052 ~ '<![CDATA['
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex052b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex053 ~ '<?xml'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex053b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex054 ~ 'version'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex054b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex055 ~ '='
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex055b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x3d /* = */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex056 ~ '1.'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex056b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
    rcb = streamInUtf8_currentFromMarkedb(streamInp);
  }

  return rcb;
}
/************************************************
  _Lex057 ~ '<!DOCTYPE'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex057b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex058 ~ '['
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex058b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x5b /* [ */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex059 ~ ']'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex059b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x5d /* ] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex060 ~ '>'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex060b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x3e /* > */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex061 ~ 'standalone'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex061b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex062 ~ 'yes'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex062b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex063 ~ 'no'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex063b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex064 ~ '<'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex064b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x3c /* < */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex065 ~ '</'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex065b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex066 ~ '/>'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex066b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex067 ~ '<!ELEMENT'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex067b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex068 ~ 'EMPTY'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex068b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex069 ~ 'ANY'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex069b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex070 ~ '?'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex070b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x3f /* ? */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex071 ~ '*'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex071b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x2a /* * */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex072 ~ '+'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex072b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x2b /* + */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex073 ~ '('
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex073b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x28 /* ( */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex074 ~ '|'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex074b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x7c /* | */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex075 ~ ')'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex075b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x29 /* ) */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex076 ~ ','
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex076b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x2c /* , */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex077 ~ '#PCDATA'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex077b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex078 ~ ')*'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex078b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex079 ~ '<!ATTLIST'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex079b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex080 ~ 'CDATA'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex080b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex081 ~ 'ID'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex081b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex082 ~ 'IDREF'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex082b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex083 ~ 'IDREFS'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex083b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex084 ~ 'ENTITY'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex084b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex085 ~ 'ENTITIES'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex085b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex086 ~ 'NMTOKEN'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex086b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex087 ~ 'NMTOKENS'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex087b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex088 ~ 'NOTATION'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex088b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex089 ~ '#REQUIRED'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex089b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex090 ~ '#IMPLIED'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex090b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex091 ~ '#FIXED'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex091b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex092 ~ '<!['
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex092b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex093 ~ 'INCLUDE'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex093b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex094 ~ 'IGNORE'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex094b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex095 ~ '&#'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex095b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex096 ~ ';'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex096b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x3b /* ; */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex097 ~ '&#x'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex097b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex098 ~ [0-9a-fA-F]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex098b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return ((currenti >= 0x30 && currenti <= 0x39) /* [0-9] */ ||
          (currenti >= 0x61 && currenti <= 0x66) /* [a-f] */ ||
          (currenti >= 0x41 && currenti <= 0x46) /* [A-F] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex099 ~ '&'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex099b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x26 /* & */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex100 ~ '%'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex100b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return (currenti == 0x25 /* % */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex101 ~ '<!ENTITY'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex101b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex102 ~ 'SYSTEM'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex102b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex103 ~ 'PUBLIC'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex103b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex104 ~ 'NDATA'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex104b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex105 ~ 'encoding'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex105b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
  _Lex106 ~ [A-Za-z]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex106b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return ((currenti >= 0x41 && currenti <= 0x5a) /* [A-Z] */ ||
          (currenti >= 0x61 && currenti <= 0x7a) /* [a-z] */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex107 ~ [A-Za-z0-9._]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex107b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
  return ((currenti >= 0x41 && currenti <= 0x5a) /* [A-Z] */ ||
          (currenti >= 0x61 && currenti <= 0x7a) /* [a-z] */ ||
          (currenti >= 0x30 && currenti <= 0x39) /* [0-9] */ ||
          (currenti == 0x2e) /* . */ ||
          (currenti == 0x5f) /* _ */) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
}
/************************************************
  _Lex108 ~ '<!NOTATION'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Lex108b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp) {
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
