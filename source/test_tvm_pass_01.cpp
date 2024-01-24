#include <tvm/ir/module.h>
#include <tvm/relay/expr.h>
#include <tvm/relay/transform.h>
#include <tvm/runtime/memory.h>
#include <tvm/runtime/object.h>
#include <tvm/runtime/registry.h>
#include <tvm/support/with.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace tvm;
using namespace tvm::relay;
using namespace tvm::relay::transform;
using namespace tvm::runtime;

int main(int argc, char** argv) {
    // Pass context gen functioon
    const tvm::runtime::PackedFunc* pass_ctx_gen = tvm::runtime::Registry::Get("transform.PassContext");
    if (!pass_ctx_gen) {
        std::cerr << "transform.PassContext not found" << std::endl;
        return -1;
    }

    // Enter pass context
    const tvm::runtime::PackedFunc* enter_pass_ctx = tvm::runtime::Registry::Get("transform.EnterPassContext");
    if (!enter_pass_ctx) {
        std::cerr << "transform.EnterPassContext not found" << std::endl;
        return -1;
    }

    // Exit pass context
    const tvm::runtime::PackedFunc* exit_pass_ctx = tvm::runtime::Registry::Get("transform.ExitPassContext");
    if (!exit_pass_ctx) {
        std::cerr << "transform.ExitPassContext not found" << std::endl;
        return -1;
    }

    // generate the pass context

    // the optimizataion level
    int opt_level = 1;
    // the list of required passes
    tvm::runtime::Array<tvm::String> required;
    // the list of disabled passes
    tvm::runtime::Array<tvm::String> disabled;
    // a list of pass instrument implementations
    tvm::runtime::Array<tvm::instrument::PassInstrument> instruments;
    // pass specific configurations
    tvm::runtime::Optional<Map<String, ObjectRef>> configs;

    PassContext pass_ctx = (*pass_ctx_gen)(opt_level, required, disabled, instruments, configs);

    tvm::With<PassContext> scope(pass_ctx);

    

    return 0;
}