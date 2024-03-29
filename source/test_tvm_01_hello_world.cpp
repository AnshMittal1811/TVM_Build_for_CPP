#include <tvm/runtime/memory.h>
#include <tvm/runtime/object.h>
#include <tvm/runtime/registry.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace tvm;
using namespace tvm::runtime;

//Register your global function
TVM_REGISTER_GLOBAL("TVM-Print").set_body([](TVMArgs args, TVMRetValue* rv) {
    std::cout << "Hello TVM, welcome !" << std::endl;
});

int main(int argc, char** argv) {
    const std::string func_name = "TVM-Print";
    const tvm::runtime::PackedFunc* fp = tvm::runtime::Registry::Get(func_name);
    if (fp) {
        (*fp)();
    }

    return 0;
}