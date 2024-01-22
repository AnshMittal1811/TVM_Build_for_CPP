#ifndef _H_TVM_CPP_ONNX_OP_GLOBAL_AVG_POOL_PARSER_H_
#define _H_TVM_CPP_ONNX_OP_GLOBAL_AVG_POOL_PARSER_H_

#include "onnx_op/op_parser.h"

namespace tvm_cpp {
namespace onnx_op {

// https://github.com/onnx/onnx/blob/main/docs/Operators.md#GlobalAveragePool
class GlobalAveragePoolParser : public IOnnxOpParser {
public:
    GlobalAveragePoolParser() = default;
    virtual ~GlobalAveragePoolParser() = default;

    virtual std::string get_name() override;
    virtual Status parse_op(const onnx::NodeProto& proto_node,
                            std::unordered_map<std::string, tvm::relay::Expr>& expressions,
                            tvm::relay::Expr& relay) override;
};

}    // namespace onnx_op
}    // namespace tvm_cpp

#endif