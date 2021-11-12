#include "ast/passes/node_counter.h"

#include "ast/visitors.h"
#include "bpftrace.h"
#include "log.h"

namespace bpftrace {
namespace ast {

Pass CreateCounterPass()
{
  auto fn = [](Node &n, PassContext &ctx) {
    NodeCounter c;
    c.Visit(n);
    auto node_count = c.get_count();
    auto max = ctx.b.ast_max_nodes_;
    if (bt_verbose)
    {
      LOG(INFO) << "node count: " << node_count;
    }
    if (node_count >= max)
    {
      LOG(ERROR) << "node count (" << node_count << ") exceeds the limit ("
                 << max << ")";
      return PassResult::Error("NodeCounter", "node count exceeded");
    }
    return PassResult::Success();
  };
  return Pass("NodeCounter", fn);
}

} // namespace ast
} // namespace bpftrace
