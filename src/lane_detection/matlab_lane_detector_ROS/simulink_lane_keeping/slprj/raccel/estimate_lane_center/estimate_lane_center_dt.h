#include "__cf_estimate_lane_center.h"
#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } } ; static uint_T rtDataTypeSizes [ ] = {
sizeof ( real_T ) , sizeof ( real32_T ) , sizeof ( int8_T ) , sizeof (
uint8_T ) , sizeof ( int16_T ) , sizeof ( uint16_T ) , sizeof ( int32_T ) ,
sizeof ( uint32_T ) , sizeof ( boolean_T ) , sizeof ( fcn_call_T ) , sizeof (
int_T ) , sizeof ( pointer_T ) , sizeof ( action_T ) , 2 * sizeof ( uint32_T
) } ; static const char_T * rtDataTypeNames [ ] = { "real_T" , "real32_T" ,
"int8_T" , "uint8_T" , "int16_T" , "uint16_T" , "int32_T" , "uint32_T" ,
"boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" , "action_T" ,
"timer_uint32_pair_T" } ; static DataTypeTransition rtBTransitions [ ] = { {
( char_T * ) ( & rtB . dqp3ofd3v44 . jjdqfkhq4b ) , 0 , 0 , 16 } , { ( char_T
* ) ( & rtDW . hga0xjow5k . LoggedData [ 0 ] ) , 11 , 0 , 7 } , { ( char_T *
) ( & rtDW . dqp3ofd3v44 . hugbkegs0r ) , 0 , 0 , 4 } , { ( char_T * ) ( &
rtDW . dqp3ofd3v44 . iq513e4hqe ) , 2 , 0 , 4 } } ; static
DataTypeTransitionTable rtBTransTable = { 4U , rtBTransitions } ; static
DataTypeTransition rtPTransitions [ ] = { { ( char_T * ) ( & rtP .
Constant_Value ) , 0 , 0 , 11 } , { ( char_T * ) ( & rtP . dqp3ofd3v44 .
Gain_Gain ) , 0 , 0 , 27 } } ; static DataTypeTransitionTable rtPTransTable =
{ 2U , rtPTransitions } ;
