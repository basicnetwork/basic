#include <basiclib/basic.hpp>
#include <basiclib/db.hpp>

namespace proxy {
   struct PACKED( Config ) {
      Config( AccountName o = AccountName() ):owner(o){}
      const uint64_t     key = N(config);
      AccountName        owner;
   };

   using Configs = Table<N(proxy),N(proxy),N(configs),Config,uint64_t>;

} /// namespace proxy

