#include <basiclib/basic.hpp>

#include "test_api.hpp"

unsigned int test_types::types_size() {
   
   WASM_ASSERT( sizeof(int64_t) == 8, "int64_t size != 8");
   WASM_ASSERT( sizeof(uint64_t) ==  8, "uint64_t size != 8");
   WASM_ASSERT( sizeof(uint32_t) ==  4, "uint32_t size != 4");
   WASM_ASSERT( sizeof(int32_t) ==  4, "int32_t size != 4");
   WASM_ASSERT( sizeof(uint128_t) == 16, "uint128_t size != 16");
   WASM_ASSERT( sizeof(int128_t) == 16, "int128_t size != 16");
   WASM_ASSERT( sizeof(uint8_t) ==  1, "uint8_t size != 1");
   
   WASM_ASSERT( sizeof(AccountName) ==  8, "AccountName size !=  8");
   WASM_ASSERT( sizeof(TokenName) ==  8, "TokenName size !=  8");
   WASM_ASSERT( sizeof(TableName) ==  8, "TableName size !=  8");
   WASM_ASSERT( sizeof(Time) ==  4, "Time size !=  4");
   WASM_ASSERT( sizeof(uint256) == 32, "uint256 != 32" );

   return WASM_TEST_PASS;
}

unsigned int test_types::char_to_symbol() {
   
   WASM_ASSERT( basic::char_to_symbol('a') ==  1, "basic::char_to_symbol('a') !=  1");
   WASM_ASSERT( basic::char_to_symbol('b') ==  2, "basic::char_to_symbol('b') !=  2");
   WASM_ASSERT( basic::char_to_symbol('c') ==  3, "basic::char_to_symbol('c') !=  3");
   WASM_ASSERT( basic::char_to_symbol('d') ==  4, "basic::char_to_symbol('d') !=  4");
   WASM_ASSERT( basic::char_to_symbol('e') ==  5, "basic::char_to_symbol('e') !=  5");
   WASM_ASSERT( basic::char_to_symbol('f') ==  6, "basic::char_to_symbol('f') !=  6");
   WASM_ASSERT( basic::char_to_symbol('g') ==  7, "basic::char_to_symbol('g') !=  7");
   WASM_ASSERT( basic::char_to_symbol('h') ==  8, "basic::char_to_symbol('h') !=  8");
   WASM_ASSERT( basic::char_to_symbol('i') ==  9, "basic::char_to_symbol('i') !=  9");
   WASM_ASSERT( basic::char_to_symbol('j') == 10, "basic::char_to_symbol('j') != 10");
   WASM_ASSERT( basic::char_to_symbol('k') == 11, "basic::char_to_symbol('k') != 11");
   WASM_ASSERT( basic::char_to_symbol('l') == 12, "basic::char_to_symbol('l') != 12");
   WASM_ASSERT( basic::char_to_symbol('m') == 13, "basic::char_to_symbol('m') != 13");
   WASM_ASSERT( basic::char_to_symbol('n') == 14, "basic::char_to_symbol('n') != 14");
   WASM_ASSERT( basic::char_to_symbol('o') == 15, "basic::char_to_symbol('o') != 15");
   WASM_ASSERT( basic::char_to_symbol('p') == 16, "basic::char_to_symbol('p') != 16");
   WASM_ASSERT( basic::char_to_symbol('q') == 17, "basic::char_to_symbol('q') != 17");
   WASM_ASSERT( basic::char_to_symbol('r') == 18, "basic::char_to_symbol('r') != 18");
   WASM_ASSERT( basic::char_to_symbol('s') == 19, "basic::char_to_symbol('s') != 19");
   WASM_ASSERT( basic::char_to_symbol('t') == 20, "basic::char_to_symbol('t') != 20");
   WASM_ASSERT( basic::char_to_symbol('u') == 21, "basic::char_to_symbol('u') != 21");
   WASM_ASSERT( basic::char_to_symbol('v') == 22, "basic::char_to_symbol('v') != 22");
   WASM_ASSERT( basic::char_to_symbol('w') == 23, "basic::char_to_symbol('w') != 23");
   WASM_ASSERT( basic::char_to_symbol('x') == 24, "basic::char_to_symbol('x') != 24");
   WASM_ASSERT( basic::char_to_symbol('y') == 25, "basic::char_to_symbol('y') != 25");
   WASM_ASSERT( basic::char_to_symbol('z') == 26, "basic::char_to_symbol('z') != 26");
   WASM_ASSERT( basic::char_to_symbol('1') == 27, "basic::char_to_symbol('1') != 27");
   WASM_ASSERT( basic::char_to_symbol('2') == 28, "basic::char_to_symbol('2') != 28");
   WASM_ASSERT( basic::char_to_symbol('3') == 29, "basic::char_to_symbol('3') != 29");
   WASM_ASSERT( basic::char_to_symbol('4') == 30, "basic::char_to_symbol('4') != 30");
   WASM_ASSERT( basic::char_to_symbol('5') == 31, "basic::char_to_symbol('5') != 31");
 
   for(unsigned char i = 0; i<255; i++) {
      if((i >= 'a' && i <= 'z') || (i >= '1' || i <= '5')) continue;
      WASM_ASSERT( basic::char_to_symbol(i) == 0, "basic::char_to_symbol() != 0");
   }

   return WASM_TEST_PASS;  
}

unsigned int test_types::string_to_name() {

   WASM_ASSERT( basic::string_to_name("a") == N(a) , "basic::string_to_name(a)" );
   WASM_ASSERT( basic::string_to_name("ba") == N(ba) , "basic::string_to_name(ba)" );
   WASM_ASSERT( basic::string_to_name("cba") == N(cba) , "basic::string_to_name(cba)" );
   WASM_ASSERT( basic::string_to_name("dcba") == N(dcba) , "basic::string_to_name(dcba)" );
   WASM_ASSERT( basic::string_to_name("edcba") == N(edcba) , "basic::string_to_name(edcba)" );
   WASM_ASSERT( basic::string_to_name("fedcba") == N(fedcba) , "basic::string_to_name(fedcba)" );
   WASM_ASSERT( basic::string_to_name("gfedcba") == N(gfedcba) , "basic::string_to_name(gfedcba)" );
   WASM_ASSERT( basic::string_to_name("hgfedcba") == N(hgfedcba) , "basic::string_to_name(hgfedcba)" );
   WASM_ASSERT( basic::string_to_name("ihgfedcba") == N(ihgfedcba) , "basic::string_to_name(ihgfedcba)" );
   WASM_ASSERT( basic::string_to_name("jihgfedcba") == N(jihgfedcba) , "basic::string_to_name(jihgfedcba)" );
   WASM_ASSERT( basic::string_to_name("kjihgfedcba") == N(kjihgfedcba) , "basic::string_to_name(kjihgfedcba)" );
   WASM_ASSERT( basic::string_to_name("lkjihgfedcba") == N(lkjihgfedcba) , "basic::string_to_name(lkjihgfedcba)" );
   WASM_ASSERT( basic::string_to_name("mlkjihgfedcba") == N(mlkjihgfedcba) , "basic::string_to_name(mlkjihgfedcba)" );
   WASM_ASSERT( basic::string_to_name("mlkjihgfedcba1") == N(mlkjihgfedcba2) , "basic::string_to_name(mlkjihgfedcba2)" );
   WASM_ASSERT( basic::string_to_name("mlkjihgfedcba55") == N(mlkjihgfedcba14) , "basic::string_to_name(mlkjihgfedcba14)" );
   
   WASM_ASSERT( basic::string_to_name("azAA34") == N(azBB34) , "basic::string_to_name N(azBB34)" );
   WASM_ASSERT( basic::string_to_name("AZaz12Bc34") == N(AZaz12Bc34) , "basic::string_to_name AZaz12Bc34" );
   WASM_ASSERT( basic::string_to_name("AAAAAAAAAAAAAAA") == basic::string_to_name("BBBBBBBBBBBBBDDDDDFFFGG") , "basic::string_to_name BBBBBBBBBBBBBDDDDDFFFGG" );
   
   return WASM_TEST_PASS;
}

unsigned int test_types::name_class() {

   WASM_ASSERT ( basic::Name(basic::string_to_name("azAA34")).value == N(azAA34), "basic::Name != N(azAA34)" );
   WASM_ASSERT ( basic::Name(basic::string_to_name("AABBCC")).value == 0, "basic::Name != N(0)" );
   WASM_ASSERT ( basic::Name(basic::string_to_name("AA11")).value == N(AA11), "basic::Name != N(AA11)" );
   WASM_ASSERT ( basic::Name(basic::string_to_name("11AA")).value == N(11), "basic::Name != N(11)" );
   WASM_ASSERT ( basic::Name(basic::string_to_name("22BBCCXXAA")).value == N(22), "basic::Name != N(22)" );
   WASM_ASSERT ( basic::Name(basic::string_to_name("AAAbbcccdd")) == basic::Name(basic::string_to_name("AAAbbcccdd")), "basic::Name == basic::Name" );

   uint64_t tmp = basic::Name(basic::string_to_name("11bbcccdd"));
   WASM_ASSERT(N(11bbcccdd) == tmp, "N(11bbcccdd) == tmp");

   return WASM_TEST_PASS;  
}

