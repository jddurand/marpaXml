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
  xml_1_1_CDStart = 0           , /* CDStart ~ '<![CDATA[' */
  xml_1_1_Char                  , /* Char ~ [\x{1}-\x{d7ff}\x{e000}-\x{fffd}\x{10000}-\x{10ffff}] */
  xml_1_1_NameStartChar         , /* NameStartChar ~ [:A-Z_a-z\x{c0}-\x{d6}\x{d8}-\x{f6}\x{f8}-\x{2ff}\x{370}-\x{37d}\x{37f}-\x{1fff}\x{200c}-\x{200d}\x{2070}-\x{218f}\x{2c00}-\x{2fef}\x{3001}-\x{d7ff}\x{f900}-\x{fdcf}\x{fdf0}-\x{fffd}\x{10000}-\x{effff}] */
  xml_1_1_PubidChar             , /* PubidChar ~ [a-zA-Z0-9-'()+,./:=?;!*#@$_%\x{20}\x{d}\x{a}] */
  xml_1_1_RestrictedChar        , /* RestrictedChar ~ [\x{1}-\x{8}\x{b}-\x{c}\x{e}-\x{1f}\x{7f}-\x{84}\x{86}-\x{9f}] */
  xml_1_1_StringType            , /* StringType ~ 'CDATA' */
  xml_1_1_VersionNum            , /* VersionNum ~ '1.1' */
  xml_1_1__Exclusion001         , /* _Exclusion001 ~ '_Gen005 - _Gen007' */
  xml_1_1__Exclusion002         , /* _Exclusion002 ~ 'PubidChar - _Lex009' */
  xml_1_1__Exclusion003         , /* _Exclusion003 ~ '_Lex016_many - _Gen062' */
  xml_1_1__Exclusion004         , /* _Exclusion004 ~ 'Char - _Lex019' */
  xml_1_1__Exclusion005         , /* _Exclusion005 ~ 'Char_many - _Gen075' */
  xml_1_1__Exclusion006         , /* _Exclusion006 ~ 'Name - _Gen092' */
  xml_1_1__Exclusion007         , /* _Exclusion007 ~ 'Char_any - _Gen097' */
  xml_1_1__Exclusion008         , /* _Exclusion008 ~ 'Char_many - _Gen253' */
  xml_1_1__Exclusion009         , /* _Exclusion009 ~ '_Gen281 - _Gen282' */
  xml_1_1__Lex003               , /* _Lex003 ~ [\x{20}\x{9}\x{d}\x{a}] */
  xml_1_1__Lex005               , /* _Lex005 ~ [-.0-9\x{b7}\x{300}-\x{36f}\x{203f}-\x{2040}] */
  xml_1_1__Lex006               , /* _Lex006 ~ [\x{20}] */
  xml_1_1__Lex007               , /* _Lex007 ~ '"' */
  xml_1_1__Lex008               , /* _Lex008 ~ [^%&"] */
  xml_1_1__Lex009               , /* _Lex009 ~ ['] */
  xml_1_1__Lex010               , /* _Lex010 ~ [^%&'] */
  xml_1_1__Lex011               , /* _Lex011 ~ [^<&"] */
  xml_1_1__Lex012               , /* _Lex012 ~ [^<&'] */
  xml_1_1__Lex013               , /* _Lex013 ~ [^"] */
  xml_1_1__Lex014               , /* _Lex014 ~ [^'] */
  xml_1_1__Lex016               , /* _Lex016 ~ [^<&] */
  xml_1_1__Lex017               , /* _Lex017 ~ ']]>' */
  xml_1_1__Lex018               , /* _Lex018 ~ '<!--' */
  xml_1_1__Lex019               , /* _Lex019 ~ '-' */
  xml_1_1__Lex020               , /* _Lex020 ~ '-->' */
  xml_1_1__Lex021               , /* _Lex021 ~ '<?' */
  xml_1_1__Lex022               , /* _Lex022 ~ '?>' */
  xml_1_1__Lex023               , /* _Lex023 ~ 'X' */
  xml_1_1__Lex024               , /* _Lex024 ~ 'x' */
  xml_1_1__Lex025               , /* _Lex025 ~ 'M' */
  xml_1_1__Lex026               , /* _Lex026 ~ 'm' */
  xml_1_1__Lex027               , /* _Lex027 ~ 'L' */
  xml_1_1__Lex028               , /* _Lex028 ~ 'l' */
  xml_1_1__Lex030               , /* _Lex030 ~ '<?xml' */
  xml_1_1__Lex031               , /* _Lex031 ~ 'version' */
  xml_1_1__Lex032               , /* _Lex032 ~ '=' */
  xml_1_1__Lex034               , /* _Lex034 ~ '<!DOCTYPE' */
  xml_1_1__Lex035               , /* _Lex035 ~ '[' */
  xml_1_1__Lex036               , /* _Lex036 ~ ']' */
  xml_1_1__Lex037               , /* _Lex037 ~ '>' */
  xml_1_1__Lex038               , /* _Lex038 ~ 'standalone' */
  xml_1_1__Lex039               , /* _Lex039 ~ 'yes' */
  xml_1_1__Lex040               , /* _Lex040 ~ 'no' */
  xml_1_1__Lex041               , /* _Lex041 ~ '<' */
  xml_1_1__Lex042               , /* _Lex042 ~ '</' */
  xml_1_1__Lex043               , /* _Lex043 ~ '/>' */
  xml_1_1__Lex044               , /* _Lex044 ~ '<!ELEMENT' */
  xml_1_1__Lex045               , /* _Lex045 ~ 'EMPTY' */
  xml_1_1__Lex046               , /* _Lex046 ~ 'ANY' */
  xml_1_1__Lex047               , /* _Lex047 ~ '?' */
  xml_1_1__Lex048               , /* _Lex048 ~ '*' */
  xml_1_1__Lex049               , /* _Lex049 ~ '+' */
  xml_1_1__Lex050               , /* _Lex050 ~ '(' */
  xml_1_1__Lex051               , /* _Lex051 ~ '|' */
  xml_1_1__Lex052               , /* _Lex052 ~ ')' */
  xml_1_1__Lex053               , /* _Lex053 ~ ',' */
  xml_1_1__Lex054               , /* _Lex054 ~ '#PCDATA' */
  xml_1_1__Lex055               , /* _Lex055 ~ ')*' */
  xml_1_1__Lex056               , /* _Lex056 ~ '<!ATTLIST' */
  xml_1_1__Lex058               , /* _Lex058 ~ 'ID' */
  xml_1_1__Lex059               , /* _Lex059 ~ 'IDREF' */
  xml_1_1__Lex060               , /* _Lex060 ~ 'IDREFS' */
  xml_1_1__Lex061               , /* _Lex061 ~ 'ENTITY' */
  xml_1_1__Lex062               , /* _Lex062 ~ 'ENTITIES' */
  xml_1_1__Lex063               , /* _Lex063 ~ 'NMTOKEN' */
  xml_1_1__Lex064               , /* _Lex064 ~ 'NMTOKENS' */
  xml_1_1__Lex065               , /* _Lex065 ~ 'NOTATION' */
  xml_1_1__Lex066               , /* _Lex066 ~ '#REQUIRED' */
  xml_1_1__Lex067               , /* _Lex067 ~ '#IMPLIED' */
  xml_1_1__Lex068               , /* _Lex068 ~ '#FIXED' */
  xml_1_1__Lex069               , /* _Lex069 ~ '<![' */
  xml_1_1__Lex070               , /* _Lex070 ~ 'INCLUDE' */
  xml_1_1__Lex071               , /* _Lex071 ~ 'IGNORE' */
  xml_1_1__Lex072               , /* _Lex072 ~ '&#' */
  xml_1_1__Lex073               , /* _Lex073 ~ [0-9] */
  xml_1_1__Lex074               , /* _Lex074 ~ ';' */
  xml_1_1__Lex075               , /* _Lex075 ~ '&#x' */
  xml_1_1__Lex076               , /* _Lex076 ~ [0-9a-fA-F] */
  xml_1_1__Lex077               , /* _Lex077 ~ '&' */
  xml_1_1__Lex078               , /* _Lex078 ~ '%' */
  xml_1_1__Lex079               , /* _Lex079 ~ '<!ENTITY' */
  xml_1_1__Lex080               , /* _Lex080 ~ 'SYSTEM' */
  xml_1_1__Lex081               , /* _Lex081 ~ 'PUBLIC' */
  xml_1_1__Lex082               , /* _Lex082 ~ 'NDATA' */
  xml_1_1__Lex083               , /* _Lex083 ~ 'encoding' */
  xml_1_1__Lex084               , /* _Lex084 ~ [A-Za-z] */
  xml_1_1__Lex085               , /* _Lex085 ~ [A-Za-z0-9._] */
  xml_1_1__Lex086               , /* _Lex086 ~ '<!NOTATION' */
  /* Non-terminals */
  xml_1_1_AttDef                ,
  xml_1_1_AttDef_any            ,
  xml_1_1_AttType               ,
  xml_1_1_AttValue              ,
  xml_1_1_AttlistDecl           ,
  xml_1_1_Attribute             ,
  xml_1_1_CDEnd                 ,
  xml_1_1_CDSect                ,
  xml_1_1_CData                 ,
  xml_1_1_CharData              ,
  xml_1_1_CharData_maybe        ,
  xml_1_1_CharRef               ,
  xml_1_1_Char_any              ,
  xml_1_1_Char_many             ,
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
  xml_1_1_PubidChar_any         ,
  xml_1_1_PubidLiteral          ,
  xml_1_1_PublicID              ,
  xml_1_1_Reference             ,
  xml_1_1_S                     ,
  xml_1_1_SDDecl                ,
  xml_1_1_SDDecl_maybe          ,
  xml_1_1_STag                  ,
  xml_1_1_S_maybe               ,
  xml_1_1_SystemLiteral         ,
  xml_1_1_TextDecl              ,
  xml_1_1_TextDecl_maybe        ,
  xml_1_1_TokenizedType         ,
  xml_1_1_VersionInfo           ,
  xml_1_1_VersionInfo_maybe     ,
  xml_1_1_XMLDecl               ,
  xml_1_1__Gen005               ,
  xml_1_1__Gen007               ,
  xml_1_1__Gen008               ,
  xml_1_1__Gen017               ,
  xml_1_1__Gen017_any           ,
  xml_1_1__Gen020               ,
  xml_1_1__Gen020_any           ,
  xml_1_1__Gen023               ,
  xml_1_1__Gen023_many          ,
  xml_1_1__Gen026               ,
  xml_1_1__Gen026_any           ,
  xml_1_1__Gen029               ,
  xml_1_1__Gen029_any           ,
  xml_1_1__Gen033               ,
  xml_1_1__Gen033_any           ,
  xml_1_1__Gen039               ,
  xml_1_1__Gen039_any           ,
  xml_1_1__Gen042               ,
  xml_1_1__Gen042_any           ,
  xml_1_1__Gen048               ,
  xml_1_1__Gen050               ,
  xml_1_1__Gen054               ,
  xml_1_1__Gen055               ,
  xml_1_1__Gen055_any           ,
  xml_1_1__Gen062               ,
  xml_1_1__Gen063               ,
  xml_1_1__Gen065               ,
  xml_1_1__Gen066               ,
  xml_1_1__Gen067               ,
  xml_1_1__Gen068               ,
  xml_1_1__Gen069               ,
  xml_1_1__Gen070               ,
  xml_1_1__Gen070_any           ,
  xml_1_1__Gen075               ,
  xml_1_1__Gen076               ,
  xml_1_1__Gen077               ,
  xml_1_1__Gen078               ,
  xml_1_1__Gen078_maybe         ,
  xml_1_1__Gen081               ,
  xml_1_1__Gen081_maybe         ,
  xml_1_1__Gen086               ,
  xml_1_1__Gen088               ,
  xml_1_1__Gen090               ,
  xml_1_1__Gen092               ,
  xml_1_1__Gen093               ,
  xml_1_1__Gen097               ,
  xml_1_1__Gen098               ,
  xml_1_1__Gen100               ,
  xml_1_1__Gen103               ,
  xml_1_1__Gen103_maybe         ,
  xml_1_1__Gen114               ,
  xml_1_1__Gen122               ,
  xml_1_1__Gen122_maybe         ,
  xml_1_1__Gen125               ,
  xml_1_1__Gen125_maybe         ,
  xml_1_1__Gen131               ,
  xml_1_1__Gen131_any           ,
  xml_1_1__Gen144               ,
  xml_1_1__Gen144_any           ,
  xml_1_1__Gen149               ,
  xml_1_1__Gen151               ,
  xml_1_1__Gen152               ,
  xml_1_1__Gen154               ,
  xml_1_1__Gen155               ,
  xml_1_1__Gen160               ,
  xml_1_1__Gen160_any           ,
  xml_1_1__Gen167               ,
  xml_1_1__Gen172               ,
  xml_1_1__Gen172_any           ,
  xml_1_1__Gen175               ,
  xml_1_1__Gen175_any           ,
  xml_1_1__Gen183               ,
  xml_1_1__Gen185               ,
  xml_1_1__Gen185_maybe         ,
  xml_1_1__Gen191               ,
  xml_1_1__Gen194               ,
  xml_1_1__Gen194_maybe         ,
  xml_1_1__Gen200               ,
  xml_1_1__Gen200_many          ,
  xml_1_1__Gen203               ,
  xml_1_1__Gen203_any           ,
  xml_1_1__Gen206               ,
  xml_1_1__Gen206_any           ,
  xml_1_1__Gen226               ,
  xml_1_1__Gen226_any           ,
  xml_1_1__Gen229               ,
  xml_1_1__Gen229_any           ,
  xml_1_1__Gen232               ,
  xml_1_1__Gen232_maybe         ,
  xml_1_1__Gen235               ,
  xml_1_1__Gen245               ,
  xml_1_1__Gen245_any           ,
  xml_1_1__Gen247               ,
  xml_1_1__Gen247_any           ,
  xml_1_1__Gen251               ,
  xml_1_1__Gen253               ,
  xml_1_1__Gen254               ,
  xml_1_1__Gen270               ,
  xml_1_1__Gen281               ,
  xml_1_1__Gen282               ,
  xml_1_1__Gen283               ,
  xml_1_1__Gen285               ,
  xml_1_1__Gen288               ,
  xml_1_1__Gen288_any           ,
  xml_1_1__Gen292               ,
  xml_1_1__Lex003_many          ,
  xml_1_1__Lex013_any           ,
  xml_1_1__Lex014_any           ,
  xml_1_1__Lex016_any           ,
  xml_1_1__Lex016_many          ,
  xml_1_1__Lex073_many          ,
  xml_1_1__Lex076_many          ,
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
  xml_1_1_start                 ,
  XML_1_1_SYMBOL_MAX
} xml_1_1_symbol_t;

#define XML_1_1_TERMINAL_MAX xml_1_1__Lex086

/* Rules */
typedef enum xml_1_1_rule {
  xml_1_1_start_001 = 0         , /* start ::= document  */
  xml_1_1_start_002             , /* start ::= extParsedEnt  */
  xml_1_1_start_003             , /* start ::= extSubset  */
  xml_1_1_Misc_any_001          , /* Misc_any ::= Misc * */
  xml_1_1__Gen005_001           , /* _Gen005 ::= prolog element Misc_any  */
  xml_1_1_Char_any_001          , /* Char_any ::= Char * */
  xml_1_1__Gen007_001           , /* _Gen007 ::= Char_any RestrictedChar Char_any  */
  xml_1_1__Gen008_001           , /* _Gen008 ::= _Exclusion001  */
  xml_1_1_document_001          , /* document ::= _Gen008  */
  xml_1_1__Lex003_many_001      , /* _Lex003_many ::= _Lex003 + */
  xml_1_1_S_001                 , /* S ::= _Lex003_many  */
  xml_1_1_NameChar_001          , /* NameChar ::= NameStartChar  */
  xml_1_1_NameChar_002          , /* NameChar ::= _Lex005  */
  xml_1_1__Gen017_001           , /* _Gen017 ::= NameChar  */
  xml_1_1__Gen017_any_001       , /* _Gen017_any ::= _Gen017 * */
  xml_1_1_Name_001              , /* Name ::= NameStartChar _Gen017_any  */
  xml_1_1__Gen020_001           , /* _Gen020 ::= _Lex006 Name  */
  xml_1_1__Gen020_any_001       , /* _Gen020_any ::= _Gen020 * */
  xml_1_1_Names_001             , /* Names ::= Name _Gen020_any  */
  xml_1_1__Gen023_001           , /* _Gen023 ::= NameChar  */
  xml_1_1__Gen023_many_001      , /* _Gen023_many ::= _Gen023 + */
  xml_1_1_Nmtoken_001           , /* Nmtoken ::= _Gen023_many  */
  xml_1_1__Gen026_001           , /* _Gen026 ::= _Lex006 Nmtoken  */
  xml_1_1__Gen026_any_001       , /* _Gen026_any ::= _Gen026 * */
  xml_1_1_Nmtokens_001          , /* Nmtokens ::= Nmtoken _Gen026_any  */
  xml_1_1__Gen029_001           , /* _Gen029 ::= _Lex008  */
  xml_1_1__Gen029_002           , /* _Gen029 ::= PEReference  */
  xml_1_1__Gen029_003           , /* _Gen029 ::= Reference  */
  xml_1_1__Gen029_any_001       , /* _Gen029_any ::= _Gen029 * */
  xml_1_1__Gen033_001           , /* _Gen033 ::= _Lex010  */
  xml_1_1__Gen033_002           , /* _Gen033 ::= PEReference  */
  xml_1_1__Gen033_003           , /* _Gen033 ::= Reference  */
  xml_1_1__Gen033_any_001       , /* _Gen033_any ::= _Gen033 * */
  xml_1_1_EntityValue_001       , /* EntityValue ::= _Lex007 _Gen029_any _Lex007  */
  xml_1_1_EntityValue_002       , /* EntityValue ::= _Lex009 _Gen033_any _Lex009  */
  xml_1_1__Gen039_001           , /* _Gen039 ::= _Lex011  */
  xml_1_1__Gen039_002           , /* _Gen039 ::= Reference  */
  xml_1_1__Gen039_any_001       , /* _Gen039_any ::= _Gen039 * */
  xml_1_1__Gen042_001           , /* _Gen042 ::= _Lex012  */
  xml_1_1__Gen042_002           , /* _Gen042 ::= Reference  */
  xml_1_1__Gen042_any_001       , /* _Gen042_any ::= _Gen042 * */
  xml_1_1_AttValue_001          , /* AttValue ::= _Lex007 _Gen039_any _Lex007  */
  xml_1_1_AttValue_002          , /* AttValue ::= _Lex009 _Gen042_any _Lex009  */
  xml_1_1__Lex013_any_001       , /* _Lex013_any ::= _Lex013 * */
  xml_1_1__Gen048_001           , /* _Gen048 ::= _Lex007 _Lex013_any _Lex007  */
  xml_1_1__Lex014_any_001       , /* _Lex014_any ::= _Lex014 * */
  xml_1_1__Gen050_001           , /* _Gen050 ::= _Lex009 _Lex014_any _Lex009  */
  xml_1_1_SystemLiteral_001     , /* SystemLiteral ::= _Gen048  */
  xml_1_1_SystemLiteral_002     , /* SystemLiteral ::= _Gen050  */
  xml_1_1_PubidChar_any_001     , /* PubidChar_any ::= PubidChar * */
  xml_1_1__Gen054_001           , /* _Gen054 ::= _Exclusion002  */
  xml_1_1__Gen055_001           , /* _Gen055 ::= _Gen054  */
  xml_1_1__Gen055_any_001       , /* _Gen055_any ::= _Gen055 * */
  xml_1_1_PubidLiteral_001      , /* PubidLiteral ::= _Lex007 PubidChar_any _Lex007  */
  xml_1_1_PubidLiteral_002      , /* PubidLiteral ::= _Lex009 _Gen055_any _Lex009  */
  xml_1_1__Lex016_many_001      , /* _Lex016_many ::= _Lex016 + */
  xml_1_1__Lex016_any_001       , /* _Lex016_any ::= _Lex016 * */
  xml_1_1__Gen062_001           , /* _Gen062 ::= _Lex016_any _Lex017 _Lex016_any  */
  xml_1_1__Gen063_001           , /* _Gen063 ::= _Exclusion003  */
  xml_1_1_CharData_001          , /* CharData ::= _Gen063  */
  xml_1_1__Gen065_001           , /* _Gen065 ::= _Exclusion004  */
  xml_1_1__Gen066_001           , /* _Gen066 ::= _Gen065  */
  xml_1_1__Gen067_001           , /* _Gen067 ::= _Exclusion004  */
  xml_1_1__Gen068_001           , /* _Gen068 ::= _Gen067  */
  xml_1_1__Gen069_001           , /* _Gen069 ::= _Lex019 _Gen068  */
  xml_1_1__Gen070_001           , /* _Gen070 ::= _Gen066  */
  xml_1_1__Gen070_002           , /* _Gen070 ::= _Gen069  */
  xml_1_1__Gen070_any_001       , /* _Gen070_any ::= _Gen070 * */
  xml_1_1_Comment_001           , /* Comment ::= _Lex018 _Gen070_any _Lex020  */
  xml_1_1_Char_many_001         , /* Char_many ::= Char + */
  xml_1_1__Gen075_001           , /* _Gen075 ::= Char_any _Lex022 Char_any  */
  xml_1_1__Gen076_001           , /* _Gen076 ::= _Exclusion005  */
  xml_1_1__Gen077_001           , /* _Gen077 ::= _Gen076  */
  xml_1_1__Gen078_001           , /* _Gen078 ::= S _Gen077  */
  xml_1_1__Gen078_maybe_001     , /* _Gen078_maybe ::= _Gen078  */
  xml_1_1__Gen078_maybe_002     , /* _Gen078_maybe ::=   */
  xml_1_1__Gen081_001           , /* _Gen081 ::= S  */
  xml_1_1__Gen081_maybe_001     , /* _Gen081_maybe ::= _Gen081  */
  xml_1_1__Gen081_maybe_002     , /* _Gen081_maybe ::=   */
  xml_1_1_PI_001                , /* PI ::= _Lex021 PITarget _Gen078_maybe _Lex022  */
  xml_1_1_PI_002                , /* PI ::= _Lex021 PITarget _Gen081_maybe _Lex022  */
  xml_1_1__Gen086_001           , /* _Gen086 ::= _Lex023  */
  xml_1_1__Gen086_002           , /* _Gen086 ::= _Lex024  */
  xml_1_1__Gen088_001           , /* _Gen088 ::= _Lex025  */
  xml_1_1__Gen088_002           , /* _Gen088 ::= _Lex026  */
  xml_1_1__Gen090_001           , /* _Gen090 ::= _Lex027  */
  xml_1_1__Gen090_002           , /* _Gen090 ::= _Lex028  */
  xml_1_1__Gen092_001           , /* _Gen092 ::= _Gen086 _Gen088 _Gen090  */
  xml_1_1__Gen093_001           , /* _Gen093 ::= _Exclusion006  */
  xml_1_1_PITarget_001          , /* PITarget ::= _Gen093  */
  xml_1_1_CDSect_001            , /* CDSect ::= CDStart CData CDEnd  */
  xml_1_1__Gen097_001           , /* _Gen097 ::= Char_any _Lex017 Char_any  */
  xml_1_1__Gen098_001           , /* _Gen098 ::= _Exclusion007  */
  xml_1_1__Gen098_002           , /* _Gen098 ::=   */
  xml_1_1__Gen100_001           , /* _Gen100 ::= _Gen098  */
  xml_1_1_CData_001             , /* CData ::= _Gen100  */
  xml_1_1_CDEnd_001             , /* CDEnd ::= _Lex017  */
  xml_1_1__Gen103_001           , /* _Gen103 ::= doctypedecl Misc_any  */
  xml_1_1__Gen103_maybe_001     , /* _Gen103_maybe ::= _Gen103  */
  xml_1_1__Gen103_maybe_002     , /* _Gen103_maybe ::=   */
  xml_1_1_prolog_001            , /* prolog ::= XMLDecl Misc_any _Gen103_maybe  */
  xml_1_1_EncodingDecl_maybe_001, /* EncodingDecl_maybe ::= EncodingDecl  */
  xml_1_1_EncodingDecl_maybe_002, /* EncodingDecl_maybe ::=   */
  xml_1_1_SDDecl_maybe_001      , /* SDDecl_maybe ::= SDDecl  */
  xml_1_1_SDDecl_maybe_002      , /* SDDecl_maybe ::=   */
  xml_1_1_S_maybe_001           , /* S_maybe ::= S  */
  xml_1_1_S_maybe_002           , /* S_maybe ::=   */
  xml_1_1_XMLDecl_001           , /* XMLDecl ::= _Lex030 VersionInfo EncodingDecl_maybe SDDecl_maybe S_maybe _Lex022  */
  xml_1_1__Gen114_001           , /* _Gen114 ::= _Lex009 VersionNum _Lex009  */
  xml_1_1__Gen114_002           , /* _Gen114 ::= _Lex007 VersionNum _Lex007  */
  xml_1_1_VersionInfo_001       , /* VersionInfo ::= S _Lex031 Eq _Gen114  */
  xml_1_1_Eq_001                , /* Eq ::= S_maybe _Lex032 S_maybe  */
  xml_1_1_Misc_001              , /* Misc ::= Comment  */
  xml_1_1_Misc_002              , /* Misc ::= PI  */
  xml_1_1_Misc_003              , /* Misc ::= S  */
  xml_1_1__Gen122_001           , /* _Gen122 ::= S ExternalID  */
  xml_1_1__Gen122_maybe_001     , /* _Gen122_maybe ::= _Gen122  */
  xml_1_1__Gen122_maybe_002     , /* _Gen122_maybe ::=   */
  xml_1_1__Gen125_001           , /* _Gen125 ::= _Lex035 intSubset _Lex036 S_maybe  */
  xml_1_1__Gen125_maybe_001     , /* _Gen125_maybe ::= _Gen125  */
  xml_1_1__Gen125_maybe_002     , /* _Gen125_maybe ::=   */
  xml_1_1_doctypedecl_001       , /* doctypedecl ::= _Lex034 S Name _Gen122_maybe S_maybe _Gen125_maybe _Lex037  */
  xml_1_1_DeclSep_001           , /* DeclSep ::= PEReference  */
  xml_1_1_DeclSep_002           , /* DeclSep ::= S  */
  xml_1_1__Gen131_001           , /* _Gen131 ::= markupdecl  */
  xml_1_1__Gen131_002           , /* _Gen131 ::= DeclSep  */
  xml_1_1__Gen131_any_001       , /* _Gen131_any ::= _Gen131 * */
  xml_1_1_intSubset_001         , /* intSubset ::= _Gen131_any  */
  xml_1_1_markupdecl_001        , /* markupdecl ::= elementdecl  */
  xml_1_1_markupdecl_002        , /* markupdecl ::= AttlistDecl  */
  xml_1_1_markupdecl_003        , /* markupdecl ::= EntityDecl  */
  xml_1_1_markupdecl_004        , /* markupdecl ::= NotationDecl  */
  xml_1_1_markupdecl_005        , /* markupdecl ::= PI  */
  xml_1_1_markupdecl_006        , /* markupdecl ::= Comment  */
  xml_1_1_TextDecl_maybe_001    , /* TextDecl_maybe ::= TextDecl  */
  xml_1_1_TextDecl_maybe_002    , /* TextDecl_maybe ::=   */
  xml_1_1_extSubset_001         , /* extSubset ::= TextDecl_maybe extSubsetDecl  */
  xml_1_1__Gen144_001           , /* _Gen144 ::= markupdecl  */
  xml_1_1__Gen144_002           , /* _Gen144 ::= conditionalSect  */
  xml_1_1__Gen144_003           , /* _Gen144 ::= DeclSep  */
  xml_1_1__Gen144_any_001       , /* _Gen144_any ::= _Gen144 * */
  xml_1_1_extSubsetDecl_001     , /* extSubsetDecl ::= _Gen144_any  */
  xml_1_1__Gen149_001           , /* _Gen149 ::= _Lex039  */
  xml_1_1__Gen149_002           , /* _Gen149 ::= _Lex040  */
  xml_1_1__Gen151_001           , /* _Gen151 ::= _Lex009 _Gen149 _Lex009  */
  xml_1_1__Gen152_001           , /* _Gen152 ::= _Lex039  */
  xml_1_1__Gen152_002           , /* _Gen152 ::= _Lex040  */
  xml_1_1__Gen154_001           , /* _Gen154 ::= _Lex007 _Gen152 _Lex007  */
  xml_1_1__Gen155_001           , /* _Gen155 ::= _Gen151  */
  xml_1_1__Gen155_002           , /* _Gen155 ::= _Gen154  */
  xml_1_1_SDDecl_001            , /* SDDecl ::= S _Lex038 Eq _Gen155  */
  xml_1_1_element_001           , /* element ::= EmptyElemTag  */
  xml_1_1_element_002           , /* element ::= STag content ETag  */
  xml_1_1__Gen160_001           , /* _Gen160 ::= S Attribute  */
  xml_1_1__Gen160_any_001       , /* _Gen160_any ::= _Gen160 * */
  xml_1_1_STag_001              , /* STag ::= _Lex041 Name _Gen160_any S_maybe _Lex037  */
  xml_1_1_Attribute_001         , /* Attribute ::= Name Eq AttValue  */
  xml_1_1_ETag_001              , /* ETag ::= _Lex042 Name S_maybe _Lex037  */
  xml_1_1_CharData_maybe_001    , /* CharData_maybe ::= CharData  */
  xml_1_1_CharData_maybe_002    , /* CharData_maybe ::=   */
  xml_1_1__Gen167_001           , /* _Gen167 ::= element  */
  xml_1_1__Gen167_002           , /* _Gen167 ::= Reference  */
  xml_1_1__Gen167_003           , /* _Gen167 ::= CDSect  */
  xml_1_1__Gen167_004           , /* _Gen167 ::= PI  */
  xml_1_1__Gen167_005           , /* _Gen167 ::= Comment  */
  xml_1_1__Gen172_001           , /* _Gen172 ::= _Gen167 CharData_maybe  */
  xml_1_1__Gen172_any_001       , /* _Gen172_any ::= _Gen172 * */
  xml_1_1_content_001           , /* content ::= CharData_maybe _Gen172_any  */
  xml_1_1__Gen175_001           , /* _Gen175 ::= S Attribute  */
  xml_1_1__Gen175_any_001       , /* _Gen175_any ::= _Gen175 * */
  xml_1_1_EmptyElemTag_001      , /* EmptyElemTag ::= _Lex041 Name _Gen175_any S_maybe _Lex043  */
  xml_1_1_elementdecl_001       , /* elementdecl ::= _Lex044 S Name S contentspec S_maybe _Lex037  */
  xml_1_1_contentspec_001       , /* contentspec ::= _Lex045  */
  xml_1_1_contentspec_002       , /* contentspec ::= _Lex046  */
  xml_1_1_contentspec_003       , /* contentspec ::= Mixed  */
  xml_1_1_contentspec_004       , /* contentspec ::= children  */
  xml_1_1__Gen183_001           , /* _Gen183 ::= choice  */
  xml_1_1__Gen183_002           , /* _Gen183 ::= seq  */
  xml_1_1__Gen185_001           , /* _Gen185 ::= _Lex047  */
  xml_1_1__Gen185_002           , /* _Gen185 ::= _Lex048  */
  xml_1_1__Gen185_003           , /* _Gen185 ::= _Lex049  */
  xml_1_1__Gen185_maybe_001     , /* _Gen185_maybe ::= _Gen185  */
  xml_1_1__Gen185_maybe_002     , /* _Gen185_maybe ::=   */
  xml_1_1_children_001          , /* children ::= _Gen183 _Gen185_maybe  */
  xml_1_1__Gen191_001           , /* _Gen191 ::= Name  */
  xml_1_1__Gen191_002           , /* _Gen191 ::= choice  */
  xml_1_1__Gen191_003           , /* _Gen191 ::= seq  */
  xml_1_1__Gen194_001           , /* _Gen194 ::= _Lex047  */
  xml_1_1__Gen194_002           , /* _Gen194 ::= _Lex048  */
  xml_1_1__Gen194_003           , /* _Gen194 ::= _Lex049  */
  xml_1_1__Gen194_maybe_001     , /* _Gen194_maybe ::= _Gen194  */
  xml_1_1__Gen194_maybe_002     , /* _Gen194_maybe ::=   */
  xml_1_1_cp_001                , /* cp ::= _Gen191 _Gen194_maybe  */
  xml_1_1__Gen200_001           , /* _Gen200 ::= S_maybe _Lex051 S_maybe cp  */
  xml_1_1__Gen200_many_001      , /* _Gen200_many ::= _Gen200 + */
  xml_1_1_choice_001            , /* choice ::= _Lex050 S_maybe cp _Gen200_many S_maybe _Lex052  */
  xml_1_1__Gen203_001           , /* _Gen203 ::= S_maybe _Lex053 S_maybe cp  */
  xml_1_1__Gen203_any_001       , /* _Gen203_any ::= _Gen203 * */
  xml_1_1_seq_001               , /* seq ::= _Lex050 S_maybe cp _Gen203_any S_maybe _Lex052  */
  xml_1_1__Gen206_001           , /* _Gen206 ::= S_maybe _Lex051 S_maybe Name  */
  xml_1_1__Gen206_any_001       , /* _Gen206_any ::= _Gen206 * */
  xml_1_1_Mixed_001             , /* Mixed ::= _Lex050 S_maybe _Lex054 _Gen206_any S_maybe _Lex055  */
  xml_1_1_Mixed_002             , /* Mixed ::= _Lex050 S_maybe _Lex054 S_maybe _Lex052  */
  xml_1_1_AttDef_any_001        , /* AttDef_any ::= AttDef * */
  xml_1_1_AttlistDecl_001       , /* AttlistDecl ::= _Lex056 S Name AttDef_any S_maybe _Lex037  */
  xml_1_1_AttDef_001            , /* AttDef ::= S Name S AttType S DefaultDecl  */
  xml_1_1_AttType_001           , /* AttType ::= StringType  */
  xml_1_1_AttType_002           , /* AttType ::= TokenizedType  */
  xml_1_1_AttType_003           , /* AttType ::= EnumeratedType  */
  xml_1_1_TokenizedType_001     , /* TokenizedType ::= _Lex058  */
  xml_1_1_TokenizedType_002     , /* TokenizedType ::= _Lex059  */
  xml_1_1_TokenizedType_003     , /* TokenizedType ::= _Lex060  */
  xml_1_1_TokenizedType_004     , /* TokenizedType ::= _Lex061  */
  xml_1_1_TokenizedType_005     , /* TokenizedType ::= _Lex062  */
  xml_1_1_TokenizedType_006     , /* TokenizedType ::= _Lex063  */
  xml_1_1_TokenizedType_007     , /* TokenizedType ::= _Lex064  */
  xml_1_1_EnumeratedType_001    , /* EnumeratedType ::= NotationType  */
  xml_1_1_EnumeratedType_002    , /* EnumeratedType ::= Enumeration  */
  xml_1_1__Gen226_001           , /* _Gen226 ::= S_maybe _Lex051 S_maybe Name  */
  xml_1_1__Gen226_any_001       , /* _Gen226_any ::= _Gen226 * */
  xml_1_1_NotationType_001      , /* NotationType ::= _Lex065 S _Lex050 S_maybe Name _Gen226_any S_maybe _Lex052  */
  xml_1_1__Gen229_001           , /* _Gen229 ::= S_maybe _Lex051 S_maybe Nmtoken  */
  xml_1_1__Gen229_any_001       , /* _Gen229_any ::= _Gen229 * */
  xml_1_1_Enumeration_001       , /* Enumeration ::= _Lex050 S_maybe Nmtoken _Gen229_any S_maybe _Lex052  */
  xml_1_1__Gen232_001           , /* _Gen232 ::= _Lex068 S  */
  xml_1_1__Gen232_maybe_001     , /* _Gen232_maybe ::= _Gen232  */
  xml_1_1__Gen232_maybe_002     , /* _Gen232_maybe ::=   */
  xml_1_1__Gen235_001           , /* _Gen235 ::= _Gen232_maybe AttValue  */
  xml_1_1_DefaultDecl_001       , /* DefaultDecl ::= _Lex066  */
  xml_1_1_DefaultDecl_002       , /* DefaultDecl ::= _Lex067  */
  xml_1_1_DefaultDecl_003       , /* DefaultDecl ::= _Gen235  */
  xml_1_1_conditionalSect_001   , /* conditionalSect ::= includeSect  */
  xml_1_1_conditionalSect_002   , /* conditionalSect ::= ignoreSect  */
  xml_1_1_includeSect_001       , /* includeSect ::= _Lex069 S_maybe _Lex070 S_maybe _Lex035 extSubsetDecl _Lex017  */
  xml_1_1_ignoreSectContents_any_001, /* ignoreSectContents_any ::= ignoreSectContents * */
  xml_1_1_ignoreSect_001        , /* ignoreSect ::= _Lex069 S_maybe _Lex071 S_maybe _Lex035 ignoreSectContents_any _Lex017  */
  xml_1_1_ignoreSect_002        , /* ignoreSect ::= _Lex069 S_maybe _Lex071 S_maybe _Lex035 _Lex017  */
  xml_1_1__Gen245_001           , /* _Gen245 ::= _Lex069 ignoreSectContents _Lex017 Ignore  */
  xml_1_1__Gen245_any_001       , /* _Gen245_any ::= _Gen245 * */
  xml_1_1__Gen247_001           , /* _Gen247 ::= _Lex069 _Lex017 Ignore  */
  xml_1_1__Gen247_any_001       , /* _Gen247_any ::= _Gen247 * */
  xml_1_1_ignoreSectContents_001, /* ignoreSectContents ::= Ignore _Gen245_any  */
  xml_1_1_ignoreSectContents_002, /* ignoreSectContents ::= Ignore _Gen247_any  */
  xml_1_1__Gen251_001           , /* _Gen251 ::= _Lex069  */
  xml_1_1__Gen251_002           , /* _Gen251 ::= _Lex017  */
  xml_1_1__Gen253_001           , /* _Gen253 ::= Char_any _Gen251 Char_any  */
  xml_1_1__Gen254_001           , /* _Gen254 ::= _Exclusion008  */
  xml_1_1_Ignore_001            , /* Ignore ::= _Gen254  */
  xml_1_1__Lex073_many_001      , /* _Lex073_many ::= _Lex073 + */
  xml_1_1__Lex076_many_001      , /* _Lex076_many ::= _Lex076 + */
  xml_1_1_CharRef_001           , /* CharRef ::= _Lex072 _Lex073_many _Lex074  */
  xml_1_1_CharRef_002           , /* CharRef ::= _Lex075 _Lex076_many _Lex074  */
  xml_1_1_Reference_001         , /* Reference ::= EntityRef  */
  xml_1_1_Reference_002         , /* Reference ::= CharRef  */
  xml_1_1_EntityRef_001         , /* EntityRef ::= _Lex077 Name _Lex074  */
  xml_1_1_PEReference_001       , /* PEReference ::= _Lex078 Name _Lex074  */
  xml_1_1_EntityDecl_001        , /* EntityDecl ::= GEDecl  */
  xml_1_1_EntityDecl_002        , /* EntityDecl ::= PEDecl  */
  xml_1_1_GEDecl_001            , /* GEDecl ::= _Lex079 S Name S EntityDef S_maybe _Lex037  */
  xml_1_1_PEDecl_001            , /* PEDecl ::= _Lex079 S _Lex078 S Name S PEDef S_maybe _Lex037  */
  xml_1_1_NDataDecl_maybe_001   , /* NDataDecl_maybe ::= NDataDecl  */
  xml_1_1_NDataDecl_maybe_002   , /* NDataDecl_maybe ::=   */
  xml_1_1__Gen270_001           , /* _Gen270 ::= ExternalID NDataDecl_maybe  */
  xml_1_1_EntityDef_001         , /* EntityDef ::= EntityValue  */
  xml_1_1_EntityDef_002         , /* EntityDef ::= _Gen270  */
  xml_1_1_PEDef_001             , /* PEDef ::= EntityValue  */
  xml_1_1_PEDef_002             , /* PEDef ::= ExternalID  */
  xml_1_1_ExternalID_001        , /* ExternalID ::= _Lex080 S SystemLiteral  */
  xml_1_1_ExternalID_002        , /* ExternalID ::= _Lex081 S PubidLiteral S SystemLiteral  */
  xml_1_1_NDataDecl_001         , /* NDataDecl ::= S _Lex082 S Name  */
  xml_1_1_VersionInfo_maybe_001 , /* VersionInfo_maybe ::= VersionInfo  */
  xml_1_1_VersionInfo_maybe_002 , /* VersionInfo_maybe ::=   */
  xml_1_1_TextDecl_001          , /* TextDecl ::= _Lex030 VersionInfo_maybe EncodingDecl S_maybe _Lex022  */
  xml_1_1__Gen281_001           , /* _Gen281 ::= TextDecl_maybe content  */
  xml_1_1__Gen282_001           , /* _Gen282 ::= Char_any RestrictedChar Char_any  */
  xml_1_1__Gen283_001           , /* _Gen283 ::= _Exclusion009  */
  xml_1_1_extParsedEnt_001      , /* extParsedEnt ::= _Gen283  */
  xml_1_1__Gen285_001           , /* _Gen285 ::= _Lex007 EncName _Lex007  */
  xml_1_1__Gen285_002           , /* _Gen285 ::= _Lex009 EncName _Lex009  */
  xml_1_1_EncodingDecl_001      , /* EncodingDecl ::= S _Lex083 Eq _Gen285  */
  xml_1_1__Gen288_001           , /* _Gen288 ::= _Lex085  */
  xml_1_1__Gen288_002           , /* _Gen288 ::= _Lex019  */
  xml_1_1__Gen288_any_001       , /* _Gen288_any ::= _Gen288 * */
  xml_1_1_EncName_001           , /* EncName ::= _Lex084 _Gen288_any  */
  xml_1_1__Gen292_001           , /* _Gen292 ::= ExternalID  */
  xml_1_1__Gen292_002           , /* _Gen292 ::= PublicID  */
  xml_1_1_NotationDecl_001      , /* NotationDecl ::= _Lex086 S Name S _Gen292 S_maybe _Lex037  */
  xml_1_1_PublicID_001          , /* PublicID ::= _Lex081 S PubidLiteral  */
  XML_1_1_RULE_MAX
} xml_1_1_rule_t;


/* Callback structure for symbols */
typedef struct xml_1_1_callback {
  xml_1_1_t *xml_1_1p;
  xml_1_1_symbol_t xml_1_1_symboli;
} xml_1_1_callback_t;

/* Work structure */
struct xml_1_1 {
  marpaWrapper_t          *marpaWrapperp;
  marpaWrapperSymbol_t   **marpaWrapperSymbolArrayp;
  size_t                   marpaWrapperSymbolArrayLengthi;
  marpaWrapperRule_t     **marpaWrapperRuleArrayp;
  size_t                   marpaWrapperRuleArrayLengthi;
  xml_1_1_callback_t *marpaWrapperSymbolCallbackArrayp;
  size_t                   marpaWrapperSymbolCallbackArrayLengthi;
};

/* Terminals to string - indexed by xml_1_1_symbol_t */
static const char *symbolsToString[] = {
    /* Terminals */
  "CDStart ~ '<![CDATA['",
  "Char ~ [\\x{1}-\\x{d7ff}\\x{e000}-\\x{fffd}\\x{10000}-\\x{10ffff}]",
  "NameStartChar ~ [:A-Z_a-z\\x{c0}-\\x{d6}\\x{d8}-\\x{f6}\\x{f8}-\\x{2ff}\\x{370}-\\x{37d}\\x{37f}-\\x{1fff}\\x{200c}-\\x{200d}\\x{2070}-\\x{218f}\\x{2c00}-\\x{2fef}\\x{3001}-\\x{d7ff}\\x{f900}-\\x{fdcf}\\x{fdf0}-\\x{fffd}\\x{10000}-\\x{effff}]",
  "PubidChar ~ [a-zA-Z0-9-'()+,./:=?;!*#@$_%\\x{20}\\x{d}\\x{a}]",
  "RestrictedChar ~ [\\x{1}-\\x{8}\\x{b}-\\x{c}\\x{e}-\\x{1f}\\x{7f}-\\x{84}\\x{86}-\\x{9f}]",
  "StringType ~ 'CDATA'",
  "VersionNum ~ '1.1'",
  "_Exclusion001 ~ '_Gen005 - _Gen007'",
  "_Exclusion002 ~ 'PubidChar - _Lex009'",
  "_Exclusion003 ~ '_Lex016_many - _Gen062'",
  "_Exclusion004 ~ 'Char - _Lex019'",
  "_Exclusion005 ~ 'Char_many - _Gen075'",
  "_Exclusion006 ~ 'Name - _Gen092'",
  "_Exclusion007 ~ 'Char_any - _Gen097'",
  "_Exclusion008 ~ 'Char_many - _Gen253'",
  "_Exclusion009 ~ '_Gen281 - _Gen282'",
  "_Lex003 ~ [\\x{20}\\x{9}\\x{d}\\x{a}]",
  "_Lex005 ~ [-.0-9\\x{b7}\\x{300}-\\x{36f}\\x{203f}-\\x{2040}]",
  "_Lex006 ~ [\\x{20}]",
  "_Lex007 ~ '\"'",
  "_Lex008 ~ [^%&\"]",
  "_Lex009 ~ [']",
  "_Lex010 ~ [^%&']",
  "_Lex011 ~ [^<&\"]",
  "_Lex012 ~ [^<&']",
  "_Lex013 ~ [^\"]",
  "_Lex014 ~ [^']",
  "_Lex016 ~ [^<&]",
  "_Lex017 ~ ']]>'",
  "_Lex018 ~ '<!--'",
  "_Lex019 ~ '-'",
  "_Lex020 ~ '-->'",
  "_Lex021 ~ '<?'",
  "_Lex022 ~ '?>'",
  "_Lex023 ~ 'X'",
  "_Lex024 ~ 'x'",
  "_Lex025 ~ 'M'",
  "_Lex026 ~ 'm'",
  "_Lex027 ~ 'L'",
  "_Lex028 ~ 'l'",
  "_Lex030 ~ '<?xml'",
  "_Lex031 ~ 'version'",
  "_Lex032 ~ '='",
  "_Lex034 ~ '<!DOCTYPE'",
  "_Lex035 ~ '['",
  "_Lex036 ~ ']'",
  "_Lex037 ~ '>'",
  "_Lex038 ~ 'standalone'",
  "_Lex039 ~ 'yes'",
  "_Lex040 ~ 'no'",
  "_Lex041 ~ '<'",
  "_Lex042 ~ '</'",
  "_Lex043 ~ '/>'",
  "_Lex044 ~ '<!ELEMENT'",
  "_Lex045 ~ 'EMPTY'",
  "_Lex046 ~ 'ANY'",
  "_Lex047 ~ '?'",
  "_Lex048 ~ '*'",
  "_Lex049 ~ '+'",
  "_Lex050 ~ '('",
  "_Lex051 ~ '|'",
  "_Lex052 ~ ')'",
  "_Lex053 ~ ','",
  "_Lex054 ~ '#PCDATA'",
  "_Lex055 ~ ')*'",
  "_Lex056 ~ '<!ATTLIST'",
  "_Lex058 ~ 'ID'",
  "_Lex059 ~ 'IDREF'",
  "_Lex060 ~ 'IDREFS'",
  "_Lex061 ~ 'ENTITY'",
  "_Lex062 ~ 'ENTITIES'",
  "_Lex063 ~ 'NMTOKEN'",
  "_Lex064 ~ 'NMTOKENS'",
  "_Lex065 ~ 'NOTATION'",
  "_Lex066 ~ '#REQUIRED'",
  "_Lex067 ~ '#IMPLIED'",
  "_Lex068 ~ '#FIXED'",
  "_Lex069 ~ '<!['",
  "_Lex070 ~ 'INCLUDE'",
  "_Lex071 ~ 'IGNORE'",
  "_Lex072 ~ '&#'",
  "_Lex073 ~ [0-9]",
  "_Lex074 ~ ';'",
  "_Lex075 ~ '&#x'",
  "_Lex076 ~ [0-9a-fA-F]",
  "_Lex077 ~ '&'",
  "_Lex078 ~ '%'",
  "_Lex079 ~ '<!ENTITY'",
  "_Lex080 ~ 'SYSTEM'",
  "_Lex081 ~ 'PUBLIC'",
  "_Lex082 ~ 'NDATA'",
  "_Lex083 ~ 'encoding'",
  "_Lex084 ~ [A-Za-z]",
  "_Lex085 ~ [A-Za-z0-9._]",
  "_Lex086 ~ '<!NOTATION'",
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
  "Char_many",
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
  "XMLDecl",
  "_Gen005",
  "_Gen007",
  "_Gen008",
  "_Gen017",
  "_Gen017_any",
  "_Gen020",
  "_Gen020_any",
  "_Gen023",
  "_Gen023_many",
  "_Gen026",
  "_Gen026_any",
  "_Gen029",
  "_Gen029_any",
  "_Gen033",
  "_Gen033_any",
  "_Gen039",
  "_Gen039_any",
  "_Gen042",
  "_Gen042_any",
  "_Gen048",
  "_Gen050",
  "_Gen054",
  "_Gen055",
  "_Gen055_any",
  "_Gen062",
  "_Gen063",
  "_Gen065",
  "_Gen066",
  "_Gen067",
  "_Gen068",
  "_Gen069",
  "_Gen070",
  "_Gen070_any",
  "_Gen075",
  "_Gen076",
  "_Gen077",
  "_Gen078",
  "_Gen078_maybe",
  "_Gen081",
  "_Gen081_maybe",
  "_Gen086",
  "_Gen088",
  "_Gen090",
  "_Gen092",
  "_Gen093",
  "_Gen097",
  "_Gen098",
  "_Gen100",
  "_Gen103",
  "_Gen103_maybe",
  "_Gen114",
  "_Gen122",
  "_Gen122_maybe",
  "_Gen125",
  "_Gen125_maybe",
  "_Gen131",
  "_Gen131_any",
  "_Gen144",
  "_Gen144_any",
  "_Gen149",
  "_Gen151",
  "_Gen152",
  "_Gen154",
  "_Gen155",
  "_Gen160",
  "_Gen160_any",
  "_Gen167",
  "_Gen172",
  "_Gen172_any",
  "_Gen175",
  "_Gen175_any",
  "_Gen183",
  "_Gen185",
  "_Gen185_maybe",
  "_Gen191",
  "_Gen194",
  "_Gen194_maybe",
  "_Gen200",
  "_Gen200_many",
  "_Gen203",
  "_Gen203_any",
  "_Gen206",
  "_Gen206_any",
  "_Gen226",
  "_Gen226_any",
  "_Gen229",
  "_Gen229_any",
  "_Gen232",
  "_Gen232_maybe",
  "_Gen235",
  "_Gen245",
  "_Gen245_any",
  "_Gen247",
  "_Gen247_any",
  "_Gen251",
  "_Gen253",
  "_Gen254",
  "_Gen270",
  "_Gen281",
  "_Gen282",
  "_Gen283",
  "_Gen285",
  "_Gen288",
  "_Gen288_any",
  "_Gen292",
  "_Lex003_many",
  "_Lex013_any",
  "_Lex014_any",
  "_Lex016_any",
  "_Lex016_many",
  "_Lex073_many",
  "_Lex076_many",
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

/* Rules to string indexed by xml_1_1_rule_t */
static const char *rulesToString[] = {
  "start ::= document ",
  "start ::= extParsedEnt ",
  "start ::= extSubset ",
  "Misc_any ::= Misc *",
  "_Gen005 ::= prolog element Misc_any ",
  "Char_any ::= Char *",
  "_Gen007 ::= Char_any RestrictedChar Char_any ",
  "_Gen008 ::= _Exclusion001 ",
  "document ::= _Gen008 ",
  "_Lex003_many ::= _Lex003 +",
  "S ::= _Lex003_many ",
  "NameChar ::= NameStartChar ",
  "NameChar ::= _Lex005 ",
  "_Gen017 ::= NameChar ",
  "_Gen017_any ::= _Gen017 *",
  "Name ::= NameStartChar _Gen017_any ",
  "_Gen020 ::= _Lex006 Name ",
  "_Gen020_any ::= _Gen020 *",
  "Names ::= Name _Gen020_any ",
  "_Gen023 ::= NameChar ",
  "_Gen023_many ::= _Gen023 +",
  "Nmtoken ::= _Gen023_many ",
  "_Gen026 ::= _Lex006 Nmtoken ",
  "_Gen026_any ::= _Gen026 *",
  "Nmtokens ::= Nmtoken _Gen026_any ",
  "_Gen029 ::= _Lex008 ",
  "_Gen029 ::= PEReference ",
  "_Gen029 ::= Reference ",
  "_Gen029_any ::= _Gen029 *",
  "_Gen033 ::= _Lex010 ",
  "_Gen033 ::= PEReference ",
  "_Gen033 ::= Reference ",
  "_Gen033_any ::= _Gen033 *",
  "EntityValue ::= _Lex007 _Gen029_any _Lex007 ",
  "EntityValue ::= _Lex009 _Gen033_any _Lex009 ",
  "_Gen039 ::= _Lex011 ",
  "_Gen039 ::= Reference ",
  "_Gen039_any ::= _Gen039 *",
  "_Gen042 ::= _Lex012 ",
  "_Gen042 ::= Reference ",
  "_Gen042_any ::= _Gen042 *",
  "AttValue ::= _Lex007 _Gen039_any _Lex007 ",
  "AttValue ::= _Lex009 _Gen042_any _Lex009 ",
  "_Lex013_any ::= _Lex013 *",
  "_Gen048 ::= _Lex007 _Lex013_any _Lex007 ",
  "_Lex014_any ::= _Lex014 *",
  "_Gen050 ::= _Lex009 _Lex014_any _Lex009 ",
  "SystemLiteral ::= _Gen048 ",
  "SystemLiteral ::= _Gen050 ",
  "PubidChar_any ::= PubidChar *",
  "_Gen054 ::= _Exclusion002 ",
  "_Gen055 ::= _Gen054 ",
  "_Gen055_any ::= _Gen055 *",
  "PubidLiteral ::= _Lex007 PubidChar_any _Lex007 ",
  "PubidLiteral ::= _Lex009 _Gen055_any _Lex009 ",
  "_Lex016_many ::= _Lex016 +",
  "_Lex016_any ::= _Lex016 *",
  "_Gen062 ::= _Lex016_any _Lex017 _Lex016_any ",
  "_Gen063 ::= _Exclusion003 ",
  "CharData ::= _Gen063 ",
  "_Gen065 ::= _Exclusion004 ",
  "_Gen066 ::= _Gen065 ",
  "_Gen067 ::= _Exclusion004 ",
  "_Gen068 ::= _Gen067 ",
  "_Gen069 ::= _Lex019 _Gen068 ",
  "_Gen070 ::= _Gen066 ",
  "_Gen070 ::= _Gen069 ",
  "_Gen070_any ::= _Gen070 *",
  "Comment ::= _Lex018 _Gen070_any _Lex020 ",
  "Char_many ::= Char +",
  "_Gen075 ::= Char_any _Lex022 Char_any ",
  "_Gen076 ::= _Exclusion005 ",
  "_Gen077 ::= _Gen076 ",
  "_Gen078 ::= S _Gen077 ",
  "_Gen078_maybe ::= _Gen078 ",
  "_Gen078_maybe ::=  ",
  "_Gen081 ::= S ",
  "_Gen081_maybe ::= _Gen081 ",
  "_Gen081_maybe ::=  ",
  "PI ::= _Lex021 PITarget _Gen078_maybe _Lex022 ",
  "PI ::= _Lex021 PITarget _Gen081_maybe _Lex022 ",
  "_Gen086 ::= _Lex023 ",
  "_Gen086 ::= _Lex024 ",
  "_Gen088 ::= _Lex025 ",
  "_Gen088 ::= _Lex026 ",
  "_Gen090 ::= _Lex027 ",
  "_Gen090 ::= _Lex028 ",
  "_Gen092 ::= _Gen086 _Gen088 _Gen090 ",
  "_Gen093 ::= _Exclusion006 ",
  "PITarget ::= _Gen093 ",
  "CDSect ::= CDStart CData CDEnd ",
  "_Gen097 ::= Char_any _Lex017 Char_any ",
  "_Gen098 ::= _Exclusion007 ",
  "_Gen098 ::=  ",
  "_Gen100 ::= _Gen098 ",
  "CData ::= _Gen100 ",
  "CDEnd ::= _Lex017 ",
  "_Gen103 ::= doctypedecl Misc_any ",
  "_Gen103_maybe ::= _Gen103 ",
  "_Gen103_maybe ::=  ",
  "prolog ::= XMLDecl Misc_any _Gen103_maybe ",
  "EncodingDecl_maybe ::= EncodingDecl ",
  "EncodingDecl_maybe ::=  ",
  "SDDecl_maybe ::= SDDecl ",
  "SDDecl_maybe ::=  ",
  "S_maybe ::= S ",
  "S_maybe ::=  ",
  "XMLDecl ::= _Lex030 VersionInfo EncodingDecl_maybe SDDecl_maybe S_maybe _Lex022 ",
  "_Gen114 ::= _Lex009 VersionNum _Lex009 ",
  "_Gen114 ::= _Lex007 VersionNum _Lex007 ",
  "VersionInfo ::= S _Lex031 Eq _Gen114 ",
  "Eq ::= S_maybe _Lex032 S_maybe ",
  "Misc ::= Comment ",
  "Misc ::= PI ",
  "Misc ::= S ",
  "_Gen122 ::= S ExternalID ",
  "_Gen122_maybe ::= _Gen122 ",
  "_Gen122_maybe ::=  ",
  "_Gen125 ::= _Lex035 intSubset _Lex036 S_maybe ",
  "_Gen125_maybe ::= _Gen125 ",
  "_Gen125_maybe ::=  ",
  "doctypedecl ::= _Lex034 S Name _Gen122_maybe S_maybe _Gen125_maybe _Lex037 ",
  "DeclSep ::= PEReference ",
  "DeclSep ::= S ",
  "_Gen131 ::= markupdecl ",
  "_Gen131 ::= DeclSep ",
  "_Gen131_any ::= _Gen131 *",
  "intSubset ::= _Gen131_any ",
  "markupdecl ::= elementdecl ",
  "markupdecl ::= AttlistDecl ",
  "markupdecl ::= EntityDecl ",
  "markupdecl ::= NotationDecl ",
  "markupdecl ::= PI ",
  "markupdecl ::= Comment ",
  "TextDecl_maybe ::= TextDecl ",
  "TextDecl_maybe ::=  ",
  "extSubset ::= TextDecl_maybe extSubsetDecl ",
  "_Gen144 ::= markupdecl ",
  "_Gen144 ::= conditionalSect ",
  "_Gen144 ::= DeclSep ",
  "_Gen144_any ::= _Gen144 *",
  "extSubsetDecl ::= _Gen144_any ",
  "_Gen149 ::= _Lex039 ",
  "_Gen149 ::= _Lex040 ",
  "_Gen151 ::= _Lex009 _Gen149 _Lex009 ",
  "_Gen152 ::= _Lex039 ",
  "_Gen152 ::= _Lex040 ",
  "_Gen154 ::= _Lex007 _Gen152 _Lex007 ",
  "_Gen155 ::= _Gen151 ",
  "_Gen155 ::= _Gen154 ",
  "SDDecl ::= S _Lex038 Eq _Gen155 ",
  "element ::= EmptyElemTag ",
  "element ::= STag content ETag ",
  "_Gen160 ::= S Attribute ",
  "_Gen160_any ::= _Gen160 *",
  "STag ::= _Lex041 Name _Gen160_any S_maybe _Lex037 ",
  "Attribute ::= Name Eq AttValue ",
  "ETag ::= _Lex042 Name S_maybe _Lex037 ",
  "CharData_maybe ::= CharData ",
  "CharData_maybe ::=  ",
  "_Gen167 ::= element ",
  "_Gen167 ::= Reference ",
  "_Gen167 ::= CDSect ",
  "_Gen167 ::= PI ",
  "_Gen167 ::= Comment ",
  "_Gen172 ::= _Gen167 CharData_maybe ",
  "_Gen172_any ::= _Gen172 *",
  "content ::= CharData_maybe _Gen172_any ",
  "_Gen175 ::= S Attribute ",
  "_Gen175_any ::= _Gen175 *",
  "EmptyElemTag ::= _Lex041 Name _Gen175_any S_maybe _Lex043 ",
  "elementdecl ::= _Lex044 S Name S contentspec S_maybe _Lex037 ",
  "contentspec ::= _Lex045 ",
  "contentspec ::= _Lex046 ",
  "contentspec ::= Mixed ",
  "contentspec ::= children ",
  "_Gen183 ::= choice ",
  "_Gen183 ::= seq ",
  "_Gen185 ::= _Lex047 ",
  "_Gen185 ::= _Lex048 ",
  "_Gen185 ::= _Lex049 ",
  "_Gen185_maybe ::= _Gen185 ",
  "_Gen185_maybe ::=  ",
  "children ::= _Gen183 _Gen185_maybe ",
  "_Gen191 ::= Name ",
  "_Gen191 ::= choice ",
  "_Gen191 ::= seq ",
  "_Gen194 ::= _Lex047 ",
  "_Gen194 ::= _Lex048 ",
  "_Gen194 ::= _Lex049 ",
  "_Gen194_maybe ::= _Gen194 ",
  "_Gen194_maybe ::=  ",
  "cp ::= _Gen191 _Gen194_maybe ",
  "_Gen200 ::= S_maybe _Lex051 S_maybe cp ",
  "_Gen200_many ::= _Gen200 +",
  "choice ::= _Lex050 S_maybe cp _Gen200_many S_maybe _Lex052 ",
  "_Gen203 ::= S_maybe _Lex053 S_maybe cp ",
  "_Gen203_any ::= _Gen203 *",
  "seq ::= _Lex050 S_maybe cp _Gen203_any S_maybe _Lex052 ",
  "_Gen206 ::= S_maybe _Lex051 S_maybe Name ",
  "_Gen206_any ::= _Gen206 *",
  "Mixed ::= _Lex050 S_maybe _Lex054 _Gen206_any S_maybe _Lex055 ",
  "Mixed ::= _Lex050 S_maybe _Lex054 S_maybe _Lex052 ",
  "AttDef_any ::= AttDef *",
  "AttlistDecl ::= _Lex056 S Name AttDef_any S_maybe _Lex037 ",
  "AttDef ::= S Name S AttType S DefaultDecl ",
  "AttType ::= StringType ",
  "AttType ::= TokenizedType ",
  "AttType ::= EnumeratedType ",
  "TokenizedType ::= _Lex058 ",
  "TokenizedType ::= _Lex059 ",
  "TokenizedType ::= _Lex060 ",
  "TokenizedType ::= _Lex061 ",
  "TokenizedType ::= _Lex062 ",
  "TokenizedType ::= _Lex063 ",
  "TokenizedType ::= _Lex064 ",
  "EnumeratedType ::= NotationType ",
  "EnumeratedType ::= Enumeration ",
  "_Gen226 ::= S_maybe _Lex051 S_maybe Name ",
  "_Gen226_any ::= _Gen226 *",
  "NotationType ::= _Lex065 S _Lex050 S_maybe Name _Gen226_any S_maybe _Lex052 ",
  "_Gen229 ::= S_maybe _Lex051 S_maybe Nmtoken ",
  "_Gen229_any ::= _Gen229 *",
  "Enumeration ::= _Lex050 S_maybe Nmtoken _Gen229_any S_maybe _Lex052 ",
  "_Gen232 ::= _Lex068 S ",
  "_Gen232_maybe ::= _Gen232 ",
  "_Gen232_maybe ::=  ",
  "_Gen235 ::= _Gen232_maybe AttValue ",
  "DefaultDecl ::= _Lex066 ",
  "DefaultDecl ::= _Lex067 ",
  "DefaultDecl ::= _Gen235 ",
  "conditionalSect ::= includeSect ",
  "conditionalSect ::= ignoreSect ",
  "includeSect ::= _Lex069 S_maybe _Lex070 S_maybe _Lex035 extSubsetDecl _Lex017 ",
  "ignoreSectContents_any ::= ignoreSectContents *",
  "ignoreSect ::= _Lex069 S_maybe _Lex071 S_maybe _Lex035 ignoreSectContents_any _Lex017 ",
  "ignoreSect ::= _Lex069 S_maybe _Lex071 S_maybe _Lex035 _Lex017 ",
  "_Gen245 ::= _Lex069 ignoreSectContents _Lex017 Ignore ",
  "_Gen245_any ::= _Gen245 *",
  "_Gen247 ::= _Lex069 _Lex017 Ignore ",
  "_Gen247_any ::= _Gen247 *",
  "ignoreSectContents ::= Ignore _Gen245_any ",
  "ignoreSectContents ::= Ignore _Gen247_any ",
  "_Gen251 ::= _Lex069 ",
  "_Gen251 ::= _Lex017 ",
  "_Gen253 ::= Char_any _Gen251 Char_any ",
  "_Gen254 ::= _Exclusion008 ",
  "Ignore ::= _Gen254 ",
  "_Lex073_many ::= _Lex073 +",
  "_Lex076_many ::= _Lex076 +",
  "CharRef ::= _Lex072 _Lex073_many _Lex074 ",
  "CharRef ::= _Lex075 _Lex076_many _Lex074 ",
  "Reference ::= EntityRef ",
  "Reference ::= CharRef ",
  "EntityRef ::= _Lex077 Name _Lex074 ",
  "PEReference ::= _Lex078 Name _Lex074 ",
  "EntityDecl ::= GEDecl ",
  "EntityDecl ::= PEDecl ",
  "GEDecl ::= _Lex079 S Name S EntityDef S_maybe _Lex037 ",
  "PEDecl ::= _Lex079 S _Lex078 S Name S PEDef S_maybe _Lex037 ",
  "NDataDecl_maybe ::= NDataDecl ",
  "NDataDecl_maybe ::=  ",
  "_Gen270 ::= ExternalID NDataDecl_maybe ",
  "EntityDef ::= EntityValue ",
  "EntityDef ::= _Gen270 ",
  "PEDef ::= EntityValue ",
  "PEDef ::= ExternalID ",
  "ExternalID ::= _Lex080 S SystemLiteral ",
  "ExternalID ::= _Lex081 S PubidLiteral S SystemLiteral ",
  "NDataDecl ::= S _Lex082 S Name ",
  "VersionInfo_maybe ::= VersionInfo ",
  "VersionInfo_maybe ::=  ",
  "TextDecl ::= _Lex030 VersionInfo_maybe EncodingDecl S_maybe _Lex022 ",
  "_Gen281 ::= TextDecl_maybe content ",
  "_Gen282 ::= Char_any RestrictedChar Char_any ",
  "_Gen283 ::= _Exclusion009 ",
  "extParsedEnt ::= _Gen283 ",
  "_Gen285 ::= _Lex007 EncName _Lex007 ",
  "_Gen285 ::= _Lex009 EncName _Lex009 ",
  "EncodingDecl ::= S _Lex083 Eq _Gen285 ",
  "_Gen288 ::= _Lex085 ",
  "_Gen288 ::= _Lex019 ",
  "_Gen288_any ::= _Gen288 *",
  "EncName ::= _Lex084 _Gen288_any ",
  "_Gen292 ::= ExternalID ",
  "_Gen292 ::= PublicID ",
  "NotationDecl ::= _Lex086 S Name S _Gen292 S_maybe _Lex037 ",
  "PublicID ::= _Lex081 S PubidLiteral "
};

static C_INLINE marpaWrapperBool_t _xml_1_1_buildGrammarb(xml_1_1_t *xml_1_1p, marpaWrapperOption_t *marpaWrapperOptionp, xml_common_option_t *xml_common_optionp);
static C_INLINE marpaWrapperBool_t _xml_1_1_buildSymbolsb(xml_1_1_t *xml_1_1p, marpaWrapperOption_t *marpaWrapperOptionp, xml_common_option_t *xml_common_optionp);
static C_INLINE marpaWrapperBool_t _xml_1_1_buildRulesb(xml_1_1_t *xml_1_1p);
static C_INLINE marpaWrapperBool_t _xml_1_1_isLexemeb(void *p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1_CDStartb(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1_Charb(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1_NameStartCharb(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1_PubidCharb(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1_RestrictedCharb(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1_StringTypeb(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1_VersionNumb(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion001b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion002b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion003b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion004b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion005b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion006b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion007b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion008b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion009b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex003b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex005b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex006b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex007b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex008b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex009b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex010b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex011b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex012b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex013b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex014b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex016b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex017b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex018b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex019b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex020b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex021b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex022b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex023b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex024b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex025b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex026b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex027b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex028b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex030b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex031b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex032b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex034b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex035b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex036b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex037b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex038b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex039b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex040b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex041b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex042b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex043b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex044b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex045b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex046b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex047b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex048b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex049b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex050b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex051b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex052b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex053b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex054b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex055b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex056b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex058b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex059b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex060b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex061b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex062b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex063b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex064b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex065b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex066b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex067b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex068b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex069b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex070b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex071b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex072b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex073b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex074b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex075b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex076b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex077b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex078b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex079b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex080b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex081b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex082b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex083b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex084b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex085b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex086b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);

/*******************/
/* xml_1_1_newp  */
/*******************/
xml_1_1_t *xml_1_1_newp(marpaWrapperOption_t *marpaWrapperOptionp, xml_common_option_t *xml_common_optionp) {
  xml_1_1_t           *xml_1_1p;
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

  xml_1_1p = malloc(sizeof(xml_1_1_t));
  if (xml_1_1p == NULL) {
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

  xml_1_1p->marpaWrapperp = NULL;
  xml_1_1p->marpaWrapperSymbolArrayp = NULL;
  xml_1_1p->marpaWrapperSymbolArrayLengthi = 0;
  xml_1_1p->marpaWrapperRuleArrayp = NULL;
  xml_1_1p->marpaWrapperRuleArrayLengthi = 0;
  xml_1_1p->marpaWrapperSymbolCallbackArrayp = NULL;
  xml_1_1p->marpaWrapperSymbolCallbackArrayLengthi = 0;

  if (_xml_1_1_buildGrammarb(xml_1_1p, &marpaWrapperOption, xml_common_optionp) == MARPAWRAPPER_BOOL_FALSE) {
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
static C_INLINE marpaWrapperBool_t _xml_1_1_buildGrammarb(xml_1_1_t *xml_1_1p, marpaWrapperOption_t *marpaWrapperOptionp, xml_common_option_t *xml_common_optionp) {

  xml_1_1p->marpaWrapperp = marpaWrapper_newp(marpaWrapperOptionp);
  if (xml_1_1p->marpaWrapperp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (_xml_1_1_buildSymbolsb(xml_1_1p, marpaWrapperOptionp, xml_common_optionp) == MARPAWRAPPER_BOOL_FALSE) {
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
static C_INLINE marpaWrapperBool_t _xml_1_1_buildSymbolsb(xml_1_1_t *xml_1_1p, marpaWrapperOption_t *marpaWrapperOptionp, xml_common_option_t *xml_common_optionp) {
  int                        i;
  marpaWrapperSymbolOption_t marpaWrapperSymbolOption;

  xml_1_1p->marpaWrapperSymbolArrayp = malloc(XML_1_1_SYMBOL_MAX * sizeof(marpaWrapperSymbol_t *));
  if (xml_1_1p->marpaWrapperSymbolArrayp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }
  xml_1_1p->marpaWrapperSymbolCallbackArrayp = malloc(XML_1_1_SYMBOL_MAX * sizeof(xml_1_1_callback_t));
  if (xml_1_1p->marpaWrapperSymbolCallbackArrayp == NULL) {
    free(xml_1_1p->marpaWrapperSymbolArrayp);
    return MARPAWRAPPER_BOOL_FALSE;
  }
 
  xml_1_1p->marpaWrapperSymbolArrayLengthi = XML_1_1_SYMBOL_MAX;
  xml_1_1p->marpaWrapperSymbolCallbackArrayLengthi = XML_1_1_SYMBOL_MAX;

  for (i = 0; i < XML_1_1_SYMBOL_MAX; i++) {

    /* Fill default options */
    if (marpaWrapper_symbolOptionDefaultb(&marpaWrapperSymbolOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }

    /* Opaque data associated to symbol will be the symbol enum */
    xml_1_1p->marpaWrapperSymbolCallbackArrayp[i].xml_1_1p = xml_1_1p;
    xml_1_1p->marpaWrapperSymbolCallbackArrayp[i].xml_1_1_symboli = i;
    marpaWrapperSymbolOption.datavp = (void *) &(xml_1_1p->marpaWrapperSymbolCallbackArrayp[i]);

    /* Optional, but we can make ourself the terminals */
    marpaWrapperSymbolOption.terminalb = (i <= XML_1_1_TERMINAL_MAX) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;

    /* Start rule ? */
    switch (xml_common_optionp->xml_common_topi) {
      case XML_COMMON_TOP_DOCUMENT:
        marpaWrapperSymbolOption.startb = (i == xml_1_1_document) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
        break;
      case XML_COMMON_TOP_EXTPARSEDENT:
        marpaWrapperSymbolOption.startb = (i == xml_1_1_extParsedEnt) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
        break;
      case XML_COMMON_TOP_EXTSUBSET:
        marpaWrapperSymbolOption.startb = (i == xml_1_1_extSubset) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
        break;
      default:
        marpaWrapper_logExt(marpaWrapperOptionp->logCallbackp,
                            marpaWrapperOptionp->logCallbackDatavp,
                            xml_1_1p->marpaWrapperp,
                            marpaWrapperOptionp->logLevelWantedi,
                            MARPAWRAPPERERRORORIGIN_NA,
                            EINVAL,
                            "Bad top-level symbol()",
                            MARPAWRAPPER_LOGLEVEL_ERROR);
        return MARPAWRAPPER_BOOL_FALSE;
        break;
      }

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
    /* [xml_1_1_start_001] start ::= document  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_document]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_start_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_start];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_start_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_start_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_start_002] start ::= extParsedEnt  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_extParsedEnt]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_start_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_start];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_start_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_start_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_start_003] start ::= extSubset  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_extSubset]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_start_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_start];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_start_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_start_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
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
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Misc_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Misc_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen005_001] _Gen005 ::= prolog element Misc_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_prolog],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_element],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Misc_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen005_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen005];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen005_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen005_001] == NULL) {
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
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Char_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Char_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen007_001] _Gen007 ::= Char_any RestrictedChar Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Char_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_RestrictedChar],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen007_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen007];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen007_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen007_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen008_001] _Gen008 ::= _Exclusion001  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Exclusion001]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen008_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen008];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen008_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen008_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_document_001] document ::= _Gen008  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen008]
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
    /* [xml_1_1__Lex003_many_001] _Lex003_many ::= _Lex003 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex003]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Lex003_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex003_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 1;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Lex003_many_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Lex003_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_S_001] S ::= _Lex003_many  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex003_many]
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
    /* [xml_1_1_NameChar_002] NameChar ::= _Lex005  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex005]
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
    /* [xml_1_1__Gen017_001] _Gen017 ::= NameChar  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen017_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen017];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen017_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen017_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen017_any_001] _Gen017_any ::= _Gen017 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen017]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen017_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen017_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen017_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen017_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Name_001] Name ::= NameStartChar _Gen017_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameStartChar],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen017_any]
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
    /* [xml_1_1__Gen020_001] _Gen020 ::= _Lex006 Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex006],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen020_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen020];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen020_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen020_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen020_any_001] _Gen020_any ::= _Gen020 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen020]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen020_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen020_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen020_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen020_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Names_001] Names ::= Name _Gen020_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen020_any]
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
    /* [xml_1_1__Gen023_001] _Gen023 ::= NameChar  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NameChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen023_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen023];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen023_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen023_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen023_many_001] _Gen023_many ::= _Gen023 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen023]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen023_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen023_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 1;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen023_many_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen023_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Nmtoken_001] Nmtoken ::= _Gen023_many  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen023_many]
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
    /* [xml_1_1__Gen026_001] _Gen026 ::= _Lex006 Nmtoken  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex006],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Nmtoken]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen026_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen026];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen026_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen026_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen026_any_001] _Gen026_any ::= _Gen026 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen026]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen026_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen026_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen026_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen026_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Nmtokens_001] Nmtokens ::= Nmtoken _Gen026_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Nmtoken],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen026_any]
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
    /* [xml_1_1__Gen029_001] _Gen029 ::= _Lex008  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex008]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen029_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen029];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen029_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen029_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen029_002] _Gen029 ::= PEReference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PEReference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen029_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen029];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen029_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen029_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen029_003] _Gen029 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen029_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen029];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen029_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen029_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen029_any_001] _Gen029_any ::= _Gen029 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen029]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen029_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen029_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen029_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen029_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen033_001] _Gen033 ::= _Lex010  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex010]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen033_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen033];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen033_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen033_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen033_002] _Gen033 ::= PEReference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PEReference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen033_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen033];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen033_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen033_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen033_003] _Gen033 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen033_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen033];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen033_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen033_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen033_any_001] _Gen033_any ::= _Gen033 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen033]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen033_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen033_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen033_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen033_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_EntityValue_001] EntityValue ::= _Lex007 _Gen029_any _Lex007  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex007],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen029_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex007]
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
    /* [xml_1_1_EntityValue_002] EntityValue ::= _Lex009 _Gen033_any _Lex009  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex009],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen033_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex009]
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
    /* [xml_1_1__Gen039_001] _Gen039 ::= _Lex011  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex011]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen039_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen039];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen039_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen039_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen039_002] _Gen039 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen039_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen039];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen039_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen039_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen039_any_001] _Gen039_any ::= _Gen039 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen039]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen039_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen039_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen039_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen039_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen042_001] _Gen042 ::= _Lex012  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex012]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen042_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen042];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen042_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen042_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen042_002] _Gen042 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen042_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen042];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen042_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen042_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen042_any_001] _Gen042_any ::= _Gen042 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen042]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen042_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen042_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen042_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen042_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_AttValue_001] AttValue ::= _Lex007 _Gen039_any _Lex007  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex007],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen039_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex007]
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
    /* [xml_1_1_AttValue_002] AttValue ::= _Lex009 _Gen042_any _Lex009  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex009],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen042_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex009]
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
    /* [xml_1_1__Lex013_any_001] _Lex013_any ::= _Lex013 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex013]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Lex013_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex013_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Lex013_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Lex013_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen048_001] _Gen048 ::= _Lex007 _Lex013_any _Lex007  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex007],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex013_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex007]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen048_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen048];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen048_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen048_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Lex014_any_001] _Lex014_any ::= _Lex014 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex014]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Lex014_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex014_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Lex014_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Lex014_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen050_001] _Gen050 ::= _Lex009 _Lex014_any _Lex009  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex009],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex014_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex009]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen050_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen050];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen050_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen050_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_SystemLiteral_001] SystemLiteral ::= _Gen048  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen048]
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
    /* [xml_1_1_SystemLiteral_002] SystemLiteral ::= _Gen050  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen050]
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
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PubidChar_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PubidChar_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen054_001] _Gen054 ::= _Exclusion002  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Exclusion002]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen054_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen054];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen054_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen054_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen055_001] _Gen055 ::= _Gen054  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen054]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen055_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen055];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen055_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen055_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen055_any_001] _Gen055_any ::= _Gen055 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen055]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen055_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen055_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen055_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen055_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_PubidLiteral_001] PubidLiteral ::= _Lex007 PubidChar_any _Lex007  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex007],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PubidChar_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex007]
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
    /* [xml_1_1_PubidLiteral_002] PubidLiteral ::= _Lex009 _Gen055_any _Lex009  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex009],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen055_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex009]
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
    /* [xml_1_1__Lex016_many_001] _Lex016_many ::= _Lex016 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex016]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Lex016_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex016_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 1;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Lex016_many_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Lex016_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Lex016_any_001] _Lex016_any ::= _Lex016 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex016]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Lex016_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex016_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Lex016_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Lex016_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen062_001] _Gen062 ::= _Lex016_any _Lex017 _Lex016_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex016_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex017],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex016_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen062_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen062];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen062_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen062_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen063_001] _Gen063 ::= _Exclusion003  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Exclusion003]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen063_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen063];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen063_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen063_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_CharData_001] CharData ::= _Gen063  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen063]
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
    /* [xml_1_1__Gen065_001] _Gen065 ::= _Exclusion004  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Exclusion004]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen065_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen065];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen065_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen065_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen066_001] _Gen066 ::= _Gen065  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen065]
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
    /* [xml_1_1__Gen067_001] _Gen067 ::= _Exclusion004  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Exclusion004]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen067_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen067];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen067_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen067_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen068_001] _Gen068 ::= _Gen067  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen067]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen068_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen068];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen068_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen068_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen069_001] _Gen069 ::= _Lex019 _Gen068  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex019],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen068]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen069_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen069];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen069_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen069_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen070_001] _Gen070 ::= _Gen066  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen066]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen070_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen070];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen070_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen070_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen070_002] _Gen070 ::= _Gen069  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen069]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen070_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen070];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen070_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen070_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen070_any_001] _Gen070_any ::= _Gen070 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen070]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen070_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen070_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen070_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen070_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Comment_001] Comment ::= _Lex018 _Gen070_any _Lex020  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex018],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen070_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex020]
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
    /* [xml_1_1_Char_many_001] Char_many ::= Char + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Char]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_Char_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Char_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 1;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Char_many_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_Char_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen075_001] _Gen075 ::= Char_any _Lex022 Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Char_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex022],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Char_any]
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
    /* [xml_1_1__Gen076_001] _Gen076 ::= _Exclusion005  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Exclusion005]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen076_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen076];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen076_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen076_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen077_001] _Gen077 ::= _Gen076  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen076]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen077_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen077];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen077_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen077_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen078_001] _Gen078 ::= S _Gen077  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen077]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen078_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen078];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen078_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen078_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen078_maybe_001] _Gen078_maybe ::= _Gen078  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen078]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen078_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen078_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen078_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen078_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen078_maybe_002] _Gen078_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen078_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen078_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen078_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen078_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen081_001] _Gen081 ::= S  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S]
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
    /* [xml_1_1__Gen081_maybe_001] _Gen081_maybe ::= _Gen081  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen081]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen081_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen081_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen081_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen081_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen081_maybe_002] _Gen081_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen081_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen081_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen081_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen081_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_PI_001] PI ::= _Lex021 PITarget _Gen078_maybe _Lex022  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex021],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PITarget],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen078_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex022]
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
    /* [xml_1_1_PI_002] PI ::= _Lex021 PITarget _Gen081_maybe _Lex022  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex021],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PITarget],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen081_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex022]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_PI_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PI];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PI_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_PI_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen086_001] _Gen086 ::= _Lex023  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex023]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen086_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen086];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen086_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen086_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen086_002] _Gen086 ::= _Lex024  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex024]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen086_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen086];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen086_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen086_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen088_001] _Gen088 ::= _Lex025  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex025]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen088_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen088];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen088_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen088_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen088_002] _Gen088 ::= _Lex026  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex026]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen088_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen088];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen088_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen088_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen090_001] _Gen090 ::= _Lex027  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex027]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen090_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen090];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen090_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen090_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen090_002] _Gen090 ::= _Lex028  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex028]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen090_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen090];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen090_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen090_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen092_001] _Gen092 ::= _Gen086 _Gen088 _Gen090  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen086],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen088],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen090]
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
    /* [xml_1_1__Gen093_001] _Gen093 ::= _Exclusion006  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Exclusion006]
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
    /* [xml_1_1_PITarget_001] PITarget ::= _Gen093  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen093]
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
    /* [xml_1_1__Gen097_001] _Gen097 ::= Char_any _Lex017 Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Char_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex017],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen097_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen097];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen097_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen097_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen098_001] _Gen098 ::= _Exclusion007  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Exclusion007]
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
    /* [xml_1_1__Gen098_002] _Gen098 ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen098_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen098];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen098_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen098_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen100_001] _Gen100 ::= _Gen098  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen098]
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
    /* [xml_1_1_CData_001] CData ::= _Gen100  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen100]
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
    /* [xml_1_1_CDEnd_001] CDEnd ::= _Lex017  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex017]
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
    /* [xml_1_1__Gen103_001] _Gen103 ::= doctypedecl Misc_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_doctypedecl],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Misc_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen103_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen103];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen103_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen103_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen103_maybe_001] _Gen103_maybe ::= _Gen103  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen103]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen103_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen103_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen103_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen103_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen103_maybe_002] _Gen103_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen103_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen103_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen103_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen103_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_prolog_001] prolog ::= XMLDecl Misc_any _Gen103_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_XMLDecl],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Misc_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen103_maybe]
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
    /* [xml_1_1_XMLDecl_001] XMLDecl ::= _Lex030 VersionInfo EncodingDecl_maybe SDDecl_maybe S_maybe _Lex022  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex030],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_VersionInfo],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EncodingDecl_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_SDDecl_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex022]
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
    /* [xml_1_1__Gen114_001] _Gen114 ::= _Lex009 VersionNum _Lex009  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex009],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_VersionNum],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex009]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen114_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen114];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen114_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen114_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen114_002] _Gen114 ::= _Lex007 VersionNum _Lex007  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex007],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_VersionNum],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex007]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen114_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen114];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen114_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen114_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_VersionInfo_001] VersionInfo ::= S _Lex031 Eq _Gen114  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex031],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Eq],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen114]
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
    /* [xml_1_1_Eq_001] Eq ::= S_maybe _Lex032 S_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex032],
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
    /* [xml_1_1__Gen122_001] _Gen122 ::= S ExternalID  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_ExternalID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen122_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen122];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen122_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen122_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen122_maybe_001] _Gen122_maybe ::= _Gen122  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen122]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen122_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen122_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen122_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen122_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen122_maybe_002] _Gen122_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen122_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen122_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen122_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen122_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen125_001] _Gen125 ::= _Lex035 intSubset _Lex036 S_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex035],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_intSubset],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex036],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen125_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen125];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen125_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen125_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen125_maybe_001] _Gen125_maybe ::= _Gen125  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen125]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen125_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen125_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen125_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen125_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen125_maybe_002] _Gen125_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen125_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen125_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen125_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen125_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_doctypedecl_001] doctypedecl ::= _Lex034 S Name _Gen122_maybe S_maybe _Gen125_maybe _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex034],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen122_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen125_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex037]
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
    /* [xml_1_1__Gen131_001] _Gen131 ::= markupdecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_markupdecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen131_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen131];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen131_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen131_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen131_002] _Gen131 ::= DeclSep  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_DeclSep]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen131_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen131];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen131_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen131_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen131_any_001] _Gen131_any ::= _Gen131 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen131]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen131_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen131_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen131_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen131_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_intSubset_001] intSubset ::= _Gen131_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen131_any]
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
    /* [xml_1_1__Gen144_001] _Gen144 ::= markupdecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_markupdecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen144_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen144];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen144_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen144_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen144_002] _Gen144 ::= conditionalSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_conditionalSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen144_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen144];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen144_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen144_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen144_003] _Gen144 ::= DeclSep  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_DeclSep]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen144_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen144];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen144_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen144_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen144_any_001] _Gen144_any ::= _Gen144 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen144]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen144_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen144_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen144_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen144_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_extSubsetDecl_001] extSubsetDecl ::= _Gen144_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen144_any]
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
    /* [xml_1_1__Gen149_001] _Gen149 ::= _Lex039  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex039]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen149_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen149];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen149_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen149_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen149_002] _Gen149 ::= _Lex040  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex040]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen149_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen149];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen149_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen149_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen151_001] _Gen151 ::= _Lex009 _Gen149 _Lex009  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex009],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen149],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex009]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen151_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen151];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen151_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen151_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen152_001] _Gen152 ::= _Lex039  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex039]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen152_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen152];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen152_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen152_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen152_002] _Gen152 ::= _Lex040  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex040]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen152_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen152];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen152_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen152_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen154_001] _Gen154 ::= _Lex007 _Gen152 _Lex007  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex007],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen152],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex007]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen154_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen154];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen154_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen154_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen155_001] _Gen155 ::= _Gen151  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen151]
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
    /* [xml_1_1__Gen155_002] _Gen155 ::= _Gen154  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen154]
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
    /* [xml_1_1_SDDecl_001] SDDecl ::= S _Lex038 Eq _Gen155  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex038],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Eq],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen155]
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
    /* [xml_1_1__Gen160_001] _Gen160 ::= S Attribute  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Attribute]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen160_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen160];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen160_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen160_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen160_any_001] _Gen160_any ::= _Gen160 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen160]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen160_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen160_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen160_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen160_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_STag_001] STag ::= _Lex041 Name _Gen160_any S_maybe _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex041],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen160_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex037]
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
    /* [xml_1_1_ETag_001] ETag ::= _Lex042 Name S_maybe _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex042],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex037]
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
    /* [xml_1_1__Gen167_001] _Gen167 ::= element  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_element]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen167_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen167];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen167_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen167_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen167_002] _Gen167 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen167_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen167];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen167_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen167_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen167_003] _Gen167 ::= CDSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_CDSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen167_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen167];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen167_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen167_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen167_004] _Gen167 ::= PI  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PI]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen167_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen167];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen167_004] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen167_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen167_005] _Gen167 ::= Comment  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Comment]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen167_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen167];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen167_005] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen167_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen172_001] _Gen172 ::= _Gen167 CharData_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen167],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_CharData_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen172_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen172];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen172_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen172_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen172_any_001] _Gen172_any ::= _Gen172 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen172]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen172_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen172_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen172_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen172_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_content_001] content ::= CharData_maybe _Gen172_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_CharData_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen172_any]
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
    /* [xml_1_1__Gen175_001] _Gen175 ::= S Attribute  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Attribute]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen175_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen175];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen175_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen175_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen175_any_001] _Gen175_any ::= _Gen175 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen175]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen175_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen175_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen175_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen175_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_EmptyElemTag_001] EmptyElemTag ::= _Lex041 Name _Gen175_any S_maybe _Lex043  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex041],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen175_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex043]
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
    /* [xml_1_1_elementdecl_001] elementdecl ::= _Lex044 S Name S contentspec S_maybe _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex044],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_contentspec],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex037]
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
    /* [xml_1_1_contentspec_001] contentspec ::= _Lex045  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex045]
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
    /* [xml_1_1_contentspec_002] contentspec ::= _Lex046  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex046]
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
    /* [xml_1_1__Gen183_001] _Gen183 ::= choice  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_choice]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen183_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen183];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen183_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen183_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen183_002] _Gen183 ::= seq  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_seq]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen183_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen183];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen183_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen183_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen185_001] _Gen185 ::= _Lex047  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex047]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen185_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen185];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen185_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen185_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen185_002] _Gen185 ::= _Lex048  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex048]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen185_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen185];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen185_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen185_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen185_003] _Gen185 ::= _Lex049  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex049]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen185_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen185];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen185_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen185_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen185_maybe_001] _Gen185_maybe ::= _Gen185  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen185]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen185_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen185_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen185_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen185_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen185_maybe_002] _Gen185_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen185_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen185_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen185_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen185_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_children_001] children ::= _Gen183 _Gen185_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen183],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen185_maybe]
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
    /* [xml_1_1__Gen191_001] _Gen191 ::= Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name]
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
    /* [xml_1_1__Gen191_002] _Gen191 ::= choice  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_choice]
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
    /* [xml_1_1__Gen191_003] _Gen191 ::= seq  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_seq]
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
    /* [xml_1_1__Gen194_001] _Gen194 ::= _Lex047  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex047]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen194_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen194];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen194_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen194_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen194_002] _Gen194 ::= _Lex048  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex048]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen194_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen194];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen194_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen194_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen194_003] _Gen194 ::= _Lex049  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex049]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen194_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen194];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen194_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen194_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen194_maybe_001] _Gen194_maybe ::= _Gen194  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen194]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen194_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen194_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen194_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen194_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen194_maybe_002] _Gen194_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen194_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen194_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen194_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen194_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_cp_001] cp ::= _Gen191 _Gen194_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen191],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen194_maybe]
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
    /* [xml_1_1__Gen200_001] _Gen200 ::= S_maybe _Lex051 S_maybe cp  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex051],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_cp]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen200_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen200];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen200_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen200_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen200_many_001] _Gen200_many ::= _Gen200 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen200]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen200_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen200_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 1;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen200_many_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen200_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_choice_001] choice ::= _Lex050 S_maybe cp _Gen200_many S_maybe _Lex052  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex050],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_cp],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen200_many],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex052]
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
    /* [xml_1_1__Gen203_001] _Gen203 ::= S_maybe _Lex053 S_maybe cp  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex053],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_cp]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen203_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen203];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen203_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen203_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen203_any_001] _Gen203_any ::= _Gen203 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen203]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen203_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen203_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen203_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen203_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_seq_001] seq ::= _Lex050 S_maybe cp _Gen203_any S_maybe _Lex052  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex050],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_cp],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen203_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex052]
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
    /* [xml_1_1__Gen206_001] _Gen206 ::= S_maybe _Lex051 S_maybe Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex051],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen206_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen206];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen206_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen206_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen206_any_001] _Gen206_any ::= _Gen206 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen206]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen206_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen206_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen206_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen206_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Mixed_001] Mixed ::= _Lex050 S_maybe _Lex054 _Gen206_any S_maybe _Lex055  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex050],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex054],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen206_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex055]
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
    /* [xml_1_1_Mixed_002] Mixed ::= _Lex050 S_maybe _Lex054 S_maybe _Lex052  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex050],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex054],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex052]
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
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_AttDef_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_AttDef_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_AttlistDecl_001] AttlistDecl ::= _Lex056 S Name AttDef_any S_maybe _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex056],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_AttDef_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex037]
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
    /* [xml_1_1_TokenizedType_001] TokenizedType ::= _Lex058  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex058]
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
    /* [xml_1_1_TokenizedType_002] TokenizedType ::= _Lex059  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex059]
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
    /* [xml_1_1_TokenizedType_003] TokenizedType ::= _Lex060  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex060]
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
    /* [xml_1_1_TokenizedType_004] TokenizedType ::= _Lex061  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex061]
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
    /* [xml_1_1_TokenizedType_005] TokenizedType ::= _Lex062  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex062]
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
    /* [xml_1_1_TokenizedType_006] TokenizedType ::= _Lex063  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex063]
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
    /* [xml_1_1_TokenizedType_007] TokenizedType ::= _Lex064  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex064]
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
    /* [xml_1_1__Gen226_001] _Gen226 ::= S_maybe _Lex051 S_maybe Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex051],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen226_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen226];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen226_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen226_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen226_any_001] _Gen226_any ::= _Gen226 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen226]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen226_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen226_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen226_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen226_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NotationType_001] NotationType ::= _Lex065 S _Lex050 S_maybe Name _Gen226_any S_maybe _Lex052  */
    marpaWrapperSymbol_t *rhsSymbolpp[8] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex065],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex050],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen226_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex052]
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
    /* [xml_1_1__Gen229_001] _Gen229 ::= S_maybe _Lex051 S_maybe Nmtoken  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex051],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Nmtoken]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen229_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen229];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen229_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen229_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen229_any_001] _Gen229_any ::= _Gen229 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen229]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen229_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen229_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen229_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen229_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Enumeration_001] Enumeration ::= _Lex050 S_maybe Nmtoken _Gen229_any S_maybe _Lex052  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex050],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Nmtoken],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen229_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex052]
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
    /* [xml_1_1__Gen232_001] _Gen232 ::= _Lex068 S  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex068],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen232_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen232];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen232_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen232_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen232_maybe_001] _Gen232_maybe ::= _Gen232  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen232]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen232_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen232_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen232_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen232_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen232_maybe_002] _Gen232_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen232_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen232_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen232_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen232_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen235_001] _Gen235 ::= _Gen232_maybe AttValue  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen232_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_AttValue]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen235_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen235];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen235_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen235_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_DefaultDecl_001] DefaultDecl ::= _Lex066  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex066]
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
    /* [xml_1_1_DefaultDecl_002] DefaultDecl ::= _Lex067  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex067]
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
    /* [xml_1_1_DefaultDecl_003] DefaultDecl ::= _Gen235  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen235]
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
    /* [xml_1_1_includeSect_001] includeSect ::= _Lex069 S_maybe _Lex070 S_maybe _Lex035 extSubsetDecl _Lex017  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex069],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex070],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex035],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_extSubsetDecl],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex017]
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
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_ignoreSectContents_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_ignoreSectContents_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_ignoreSect_001] ignoreSect ::= _Lex069 S_maybe _Lex071 S_maybe _Lex035 ignoreSectContents_any _Lex017  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex069],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex071],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex035],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_ignoreSectContents_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex017]
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
    /* [xml_1_1_ignoreSect_002] ignoreSect ::= _Lex069 S_maybe _Lex071 S_maybe _Lex035 _Lex017  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex069],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex071],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex035],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex017]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_ignoreSect_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_ignoreSect];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_ignoreSect_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_ignoreSect_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen245_001] _Gen245 ::= _Lex069 ignoreSectContents _Lex017 Ignore  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex069],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_ignoreSectContents],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex017],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Ignore]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen245_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen245];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen245_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen245_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen245_any_001] _Gen245_any ::= _Gen245 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen245]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen245_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen245_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen245_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen245_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen247_001] _Gen247 ::= _Lex069 _Lex017 Ignore  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex069],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex017],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Ignore]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen247_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen247];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen247_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen247_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen247_any_001] _Gen247_any ::= _Gen247 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen247]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen247_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen247_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen247_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen247_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_ignoreSectContents_001] ignoreSectContents ::= Ignore _Gen245_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Ignore],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen245_any]
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
    /* [xml_1_1_ignoreSectContents_002] ignoreSectContents ::= Ignore _Gen247_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Ignore],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen247_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1_ignoreSectContents_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_ignoreSectContents];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_ignoreSectContents_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1_ignoreSectContents_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen251_001] _Gen251 ::= _Lex069  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex069]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen251_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen251];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen251_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen251_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen251_002] _Gen251 ::= _Lex017  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex017]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen251_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen251];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen251_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen251_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen253_001] _Gen253 ::= Char_any _Gen251 Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Char_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen251],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen253_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen253];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen253_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen253_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen254_001] _Gen254 ::= _Exclusion008  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Exclusion008]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen254_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen254];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen254_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen254_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_Ignore_001] Ignore ::= _Gen254  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen254]
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
    /* [xml_1_1__Lex073_many_001] _Lex073_many ::= _Lex073 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex073]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Lex073_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex073_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 1;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Lex073_many_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Lex073_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Lex076_many_001] _Lex076_many ::= _Lex076 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex076]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Lex076_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex076_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 1;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Lex076_many_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Lex076_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_CharRef_001] CharRef ::= _Lex072 _Lex073_many _Lex074  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex072],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex073_many],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex074]
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
    /* [xml_1_1_CharRef_002] CharRef ::= _Lex075 _Lex076_many _Lex074  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex075],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex076_many],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex074]
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
    /* [xml_1_1_EntityRef_001] EntityRef ::= _Lex077 Name _Lex074  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex077],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex074]
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
    /* [xml_1_1_PEReference_001] PEReference ::= _Lex078 Name _Lex074  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex078],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex074]
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
    /* [xml_1_1_GEDecl_001] GEDecl ::= _Lex079 S Name S EntityDef S_maybe _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex079],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EntityDef],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex037]
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
    /* [xml_1_1_PEDecl_001] PEDecl ::= _Lex079 S _Lex078 S Name S PEDef S_maybe _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[9] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex079],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex078],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PEDef],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex037]
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
    /* [xml_1_1__Gen270_001] _Gen270 ::= ExternalID NDataDecl_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_ExternalID],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_NDataDecl_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen270_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen270];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen270_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen270_001] == NULL) {
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
    /* [xml_1_1_EntityDef_002] EntityDef ::= _Gen270  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen270]
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
    /* [xml_1_1_ExternalID_001] ExternalID ::= _Lex080 S SystemLiteral  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex080],
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
    /* [xml_1_1_ExternalID_002] ExternalID ::= _Lex081 S PubidLiteral S SystemLiteral  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex081],
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
    /* [xml_1_1_NDataDecl_001] NDataDecl ::= S _Lex082 S Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex082],
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
    /* [xml_1_1_TextDecl_001] TextDecl ::= _Lex030 VersionInfo_maybe EncodingDecl S_maybe _Lex022  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex030],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_VersionInfo_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EncodingDecl],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex022]
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
    /* [xml_1_1__Gen281_001] _Gen281 ::= TextDecl_maybe content  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_TextDecl_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_content]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen281_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen281];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen281_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen281_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen282_001] _Gen282 ::= Char_any RestrictedChar Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Char_any],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_RestrictedChar],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen282_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen282];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen282_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen282_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen283_001] _Gen283 ::= _Exclusion009  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Exclusion009]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen283_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen283];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen283_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen283_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_extParsedEnt_001] extParsedEnt ::= _Gen283  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen283]
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
    /* [xml_1_1__Gen285_001] _Gen285 ::= _Lex007 EncName _Lex007  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex007],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EncName],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex007]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen285_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen285];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen285_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen285_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen285_002] _Gen285 ::= _Lex009 EncName _Lex009  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex009],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_EncName],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex009]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen285_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen285];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen285_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen285_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_EncodingDecl_001] EncodingDecl ::= S _Lex083 Eq _Gen285  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex083],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Eq],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen285]
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
    /* [xml_1_1__Gen288_001] _Gen288 ::= _Lex085  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex085]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen288_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen288];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen288_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen288_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen288_002] _Gen288 ::= _Lex019  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex019]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen288_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen288];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen288_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen288_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen288_any_001] _Gen288_any ::= _Gen288 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen288]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen288_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen288_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    marpaWrapperRuleOption.sequenceb = MARPAWRAPPER_BOOL_TRUE;
    marpaWrapperRuleOption.minimumi = 0;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen288_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen288_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_EncName_001] EncName ::= _Lex084 _Gen288_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex084],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen288_any]
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
    /* [xml_1_1__Gen292_001] _Gen292 ::= ExternalID  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_ExternalID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen292_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen292];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen292_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen292_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1__Gen292_002] _Gen292 ::= PublicID  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_PublicID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) xml_1_1__Gen292_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen292];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen292_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[xml_1_1__Gen292_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [xml_1_1_NotationDecl_001] NotationDecl ::= _Lex086 S Name S _Gen292 S_maybe _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex086],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_Name],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Gen292],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1_S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex037]
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
    /* [xml_1_1_PublicID_001] PublicID ::= _Lex081 S PubidLiteral  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[xml_1_1__Lex081],
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
/* _xml_1_1_isLexemeb */
/************************/

static C_INLINE marpaWrapperBool_t _xml_1_1_isLexemeb(void *p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  marpaWrapperBool_t rcb;
  xml_1_1_callback_t *xml_1_1_callbackp = (xml_1_1_callback_t *) p;

  switch (xml_1_1_callbackp->xml_1_1_symboli) {
    case xml_1_1_CDStart:
      rcb = _xml_1_1_CDStartb(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1_Char:
      rcb = _xml_1_1_Charb(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1_NameStartChar:
      rcb = _xml_1_1_NameStartCharb(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1_PubidChar:
      rcb = _xml_1_1_PubidCharb(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1_RestrictedChar:
      rcb = _xml_1_1_RestrictedCharb(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1_StringType:
      rcb = _xml_1_1_StringTypeb(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1_VersionNum:
      rcb = _xml_1_1_VersionNumb(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Exclusion001:
      rcb = _xml_1_1__Exclusion001b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Exclusion002:
      rcb = _xml_1_1__Exclusion002b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Exclusion003:
      rcb = _xml_1_1__Exclusion003b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Exclusion004:
      rcb = _xml_1_1__Exclusion004b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Exclusion005:
      rcb = _xml_1_1__Exclusion005b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Exclusion006:
      rcb = _xml_1_1__Exclusion006b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Exclusion007:
      rcb = _xml_1_1__Exclusion007b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Exclusion008:
      rcb = _xml_1_1__Exclusion008b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Exclusion009:
      rcb = _xml_1_1__Exclusion009b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex003:
      rcb = _xml_1_1__Lex003b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex005:
      rcb = _xml_1_1__Lex005b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex006:
      rcb = _xml_1_1__Lex006b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex007:
      rcb = _xml_1_1__Lex007b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex008:
      rcb = _xml_1_1__Lex008b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex009:
      rcb = _xml_1_1__Lex009b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex010:
      rcb = _xml_1_1__Lex010b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex011:
      rcb = _xml_1_1__Lex011b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex012:
      rcb = _xml_1_1__Lex012b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex013:
      rcb = _xml_1_1__Lex013b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex014:
      rcb = _xml_1_1__Lex014b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex016:
      rcb = _xml_1_1__Lex016b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex017:
      rcb = _xml_1_1__Lex017b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex018:
      rcb = _xml_1_1__Lex018b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex019:
      rcb = _xml_1_1__Lex019b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex020:
      rcb = _xml_1_1__Lex020b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex021:
      rcb = _xml_1_1__Lex021b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex022:
      rcb = _xml_1_1__Lex022b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex023:
      rcb = _xml_1_1__Lex023b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex024:
      rcb = _xml_1_1__Lex024b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex025:
      rcb = _xml_1_1__Lex025b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex026:
      rcb = _xml_1_1__Lex026b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex027:
      rcb = _xml_1_1__Lex027b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex028:
      rcb = _xml_1_1__Lex028b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex030:
      rcb = _xml_1_1__Lex030b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex031:
      rcb = _xml_1_1__Lex031b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex032:
      rcb = _xml_1_1__Lex032b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex034:
      rcb = _xml_1_1__Lex034b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex035:
      rcb = _xml_1_1__Lex035b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex036:
      rcb = _xml_1_1__Lex036b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex037:
      rcb = _xml_1_1__Lex037b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex038:
      rcb = _xml_1_1__Lex038b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex039:
      rcb = _xml_1_1__Lex039b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex040:
      rcb = _xml_1_1__Lex040b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex041:
      rcb = _xml_1_1__Lex041b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex042:
      rcb = _xml_1_1__Lex042b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex043:
      rcb = _xml_1_1__Lex043b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex044:
      rcb = _xml_1_1__Lex044b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex045:
      rcb = _xml_1_1__Lex045b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex046:
      rcb = _xml_1_1__Lex046b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex047:
      rcb = _xml_1_1__Lex047b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex048:
      rcb = _xml_1_1__Lex048b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex049:
      rcb = _xml_1_1__Lex049b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex050:
      rcb = _xml_1_1__Lex050b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex051:
      rcb = _xml_1_1__Lex051b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex052:
      rcb = _xml_1_1__Lex052b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex053:
      rcb = _xml_1_1__Lex053b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex054:
      rcb = _xml_1_1__Lex054b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex055:
      rcb = _xml_1_1__Lex055b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex056:
      rcb = _xml_1_1__Lex056b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex058:
      rcb = _xml_1_1__Lex058b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex059:
      rcb = _xml_1_1__Lex059b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex060:
      rcb = _xml_1_1__Lex060b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex061:
      rcb = _xml_1_1__Lex061b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex062:
      rcb = _xml_1_1__Lex062b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex063:
      rcb = _xml_1_1__Lex063b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex064:
      rcb = _xml_1_1__Lex064b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex065:
      rcb = _xml_1_1__Lex065b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex066:
      rcb = _xml_1_1__Lex066b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex067:
      rcb = _xml_1_1__Lex067b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex068:
      rcb = _xml_1_1__Lex068b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex069:
      rcb = _xml_1_1__Lex069b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex070:
      rcb = _xml_1_1__Lex070b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex071:
      rcb = _xml_1_1__Lex071b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex072:
      rcb = _xml_1_1__Lex072b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex073:
      rcb = _xml_1_1__Lex073b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex074:
      rcb = _xml_1_1__Lex074b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex075:
      rcb = _xml_1_1__Lex075b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex076:
      rcb = _xml_1_1__Lex076b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex077:
      rcb = _xml_1_1__Lex077b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex078:
      rcb = _xml_1_1__Lex078b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex079:
      rcb = _xml_1_1__Lex079b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex080:
      rcb = _xml_1_1__Lex080b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex081:
      rcb = _xml_1_1__Lex081b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex082:
      rcb = _xml_1_1__Lex082b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex083:
      rcb = _xml_1_1__Lex083b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex084:
      rcb = _xml_1_1__Lex084b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex085:
      rcb = _xml_1_1__Lex085b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
      break;
    case xml_1_1__Lex086:
      rcb = _xml_1_1__Lex086b(xml_1_1_callbackp->xml_1_1p, currenti, streamInp, sizelp);
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
static C_INLINE marpaWrapperBool_t _xml_1_1_CDStartb(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 9 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 9);
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
  Char ~ [\x{1}-\x{d7ff}\x{e000}-\x{fffd}\x{10000}-\x{10ffff}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1_Charb(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if ((currenti >= 0x1 && currenti <= 0xd7ff) /* [#x1-#xd7ff] */ ||
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
static C_INLINE marpaWrapperBool_t _xml_1_1_NameStartCharb(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
static C_INLINE marpaWrapperBool_t _xml_1_1_PubidCharb(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
  RestrictedChar ~ [\x{1}-\x{8}\x{b}-\x{c}\x{e}-\x{1f}\x{7f}-\x{84}\x{86}-\x{9f}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1_RestrictedCharb(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if ((currenti >= 0x1 && currenti <= 0x8) /* [#x1-#x8] */ ||
      (currenti >= 0xb && currenti <= 0xc) /* [#xb-#xc] */ ||
      (currenti >= 0xe && currenti <= 0x1f) /* [#xe-#x1f] */ ||
      (currenti >= 0x7f && currenti <= 0x84) /* [#x7f-#x84] */ ||
      (currenti >= 0x86 && currenti <= 0x9f) /* [#x86-#x9f] */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  StringType ~ 'CDATA'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1_StringTypeb(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 5 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 5);
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
  VersionNum ~ '1.1'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1_VersionNumb(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 3 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 3);
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
  _Exclusion001 ~ '_Gen005 - _Gen007'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion001b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Exclusion002 ~ 'PubidChar - _Lex009'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion002b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Exclusion003 ~ '_Lex016_many - _Gen062'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion003b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Exclusion004 ~ 'Char - _Lex019'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion004b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Exclusion005 ~ 'Char_many - _Gen075'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion005b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Exclusion006 ~ 'Name - _Gen092'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion006b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Exclusion007 ~ 'Char_any - _Gen097'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion007b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Exclusion008 ~ 'Char_many - _Gen253'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion008b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Exclusion009 ~ '_Gen281 - _Gen282'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Exclusion009b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  /* Writen by hand */
  return MARPAWRAPPER_BOOL_FALSE;
}

/************************************************
  _Lex003 ~ [\x{20}\x{9}\x{d}\x{a}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex003b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
  _Lex005 ~ [-.0-9\x{b7}\x{300}-\x{36f}\x{203f}-\x{2040}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex005b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
  _Lex006 ~ [\x{20}]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex006b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x20 /* #x20 */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex007 ~ '"'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex007b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x22 /* " */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex008 ~ [^%&"]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex008b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
  _Lex009 ~ [']
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex009b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x27 /* ' */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex010 ~ [^%&']
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex010b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
  _Lex011 ~ [^<&"]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex011b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
  _Lex012 ~ [^<&']
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex012b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
  _Lex013 ~ [^"]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex013b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x22 /* " */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_FALSE;
  } else {
    return MARPAWRAPPER_BOOL_TRUE;
  }
}
/************************************************
  _Lex014 ~ [^']
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex014b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x27 /* ' */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_FALSE;
  } else {
    return MARPAWRAPPER_BOOL_TRUE;
  }
}
/************************************************
  _Lex016 ~ [^<&]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex016b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if ((currenti == 0x3c) /* < */ ||
      (currenti == 0x26) /* & */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_FALSE;
  } else {
    return MARPAWRAPPER_BOOL_TRUE;
  }
}
/************************************************
  _Lex017 ~ ']]>'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex017b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 3 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 3);
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
  _Lex018 ~ '<!--'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex018b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 4 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 4);
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
  _Lex019 ~ '-'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex019b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x2d /* - */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex020 ~ '-->'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex020b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 3 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 3);
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
  _Lex021 ~ '<?'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex021b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 2 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 2);
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
  _Lex022 ~ '?>'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex022b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 2 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 2);
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
  _Lex023 ~ 'X'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex023b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x58 /* X */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex024 ~ 'x'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex024b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x78 /* x */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex025 ~ 'M'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex025b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x4d /* M */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex026 ~ 'm'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex026b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x6d /* m */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex027 ~ 'L'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex027b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x4c /* L */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex028 ~ 'l'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex028b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x6c /* l */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex030 ~ '<?xml'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex030b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 5 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 5);
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
  _Lex031 ~ 'version'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex031b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 7 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 7);
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
  _Lex032 ~ '='
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex032b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x3d /* = */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex034 ~ '<!DOCTYPE'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex034b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 9 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 9);
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
  _Lex035 ~ '['
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex035b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x5b /* [ */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex036 ~ ']'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex036b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x5d /* ] */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex037 ~ '>'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex037b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x3e /* > */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex038 ~ 'standalone'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex038b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 10 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 10);
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
  _Lex039 ~ 'yes'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex039b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 3 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 3);
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
  _Lex040 ~ 'no'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex040b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 2 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 2);
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
  _Lex041 ~ '<'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex041b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x3c /* < */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex042 ~ '</'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex042b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 2 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 2);
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
  _Lex043 ~ '/>'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex043b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 2 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 2);
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
  _Lex044 ~ '<!ELEMENT'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex044b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 9 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 9);
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
  _Lex045 ~ 'EMPTY'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex045b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 5 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 5);
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
  _Lex046 ~ 'ANY'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex046b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 3 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 3);
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
  _Lex047 ~ '?'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex047b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x3f /* ? */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex048 ~ '*'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex048b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x2a /* * */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex049 ~ '+'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex049b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x2b /* + */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex050 ~ '('
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex050b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x28 /* ( */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex051 ~ '|'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex051b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x7c /* | */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex052 ~ ')'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex052b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x29 /* ) */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex053 ~ ','
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex053b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x2c /* , */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex054 ~ '#PCDATA'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex054b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 7 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 7);
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
  _Lex055 ~ ')*'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex055b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 2 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 2);
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
  _Lex056 ~ '<!ATTLIST'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex056b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 9 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 9);
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
  _Lex058 ~ 'ID'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex058b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 2 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 2);
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
  _Lex059 ~ 'IDREF'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex059b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 5 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 5);
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
  _Lex060 ~ 'IDREFS'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex060b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 6 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 6);
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
  _Lex061 ~ 'ENTITY'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex061b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 6 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 6);
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
  _Lex062 ~ 'ENTITIES'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex062b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 8 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 8);
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
  _Lex063 ~ 'NMTOKEN'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex063b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 7 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 7);
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
  _Lex064 ~ 'NMTOKENS'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex064b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 8 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 8);
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
  _Lex065 ~ 'NOTATION'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex065b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 8 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 8);
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
  _Lex066 ~ '#REQUIRED'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex066b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 9 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 9);
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
  _Lex067 ~ '#IMPLIED'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex067b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 8 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 8);
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
  _Lex068 ~ '#FIXED'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex068b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 6 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 6);
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
  _Lex069 ~ '<!['
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex069b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 3 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 3);
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
  _Lex070 ~ 'INCLUDE'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex070b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 7 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 7);
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
  _Lex071 ~ 'IGNORE'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex071b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 6 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 6);
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
  _Lex072 ~ '&#'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex072b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 2 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 2);
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
  _Lex073 ~ [0-9]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex073b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti >= 0x30 && currenti <= 0x39 /* [0-9] */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex074 ~ ';'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex074b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x3b /* ; */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex075 ~ '&#x'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex075b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 3 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 3);
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
  _Lex076 ~ [0-9a-fA-F]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex076b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
  _Lex077 ~ '&'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex077b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x26 /* & */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex078 ~ '%'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex078b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (currenti == 0x25 /* % */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex079 ~ '<!ENTITY'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex079b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 8 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 8);
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
  _Lex080 ~ 'SYSTEM'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex080b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 6 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 6);
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
  _Lex081 ~ 'PUBLIC'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex081b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 6 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 6);
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
  _Lex082 ~ 'NDATA'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex082b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 5 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 5);
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
  _Lex083 ~ 'encoding'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex083b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 8 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 8);
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
  _Lex084 ~ [A-Za-z]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex084b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if ((currenti >= 0x41 && currenti <= 0x5a) /* [A-Z] */ ||
      (currenti >= 0x61 && currenti <= 0x7a) /* [a-z] */) {
    *sizelp = 1;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
/************************************************
  _Lex085 ~ [A-Za-z0-9._]
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex085b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
  _Lex086 ~ '<!NOTATION'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__Lex086b(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
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
      if (++i < 10 && streamInUtf8_nexti(streamInp, &got) == STREAMIN_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } while (i < 10);
    if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
	rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = 10;
  }

  return rcb;
}
