#include "tensorflow/core/framework/op.h"
#include "tensorflow/core/framework/shape_inference.h"

using namespace tensorflow;

// Register op that generates initial state
REGISTER_OP("InitialState")
    .Attr("T: {complex64, complex128}")
    .Input("in: T")
    .Output("out: T")
    .SetShapeFn([](::tensorflow::shape_inference::InferenceContext* c) {
      c->set_output(0, c->input(0));
      return Status::OK();
    });

// Register one-qubit gate op with gate matrix
#define REGISTER_GATE1_OP(NAME)                                               \
  REGISTER_OP(NAME)                                                           \
      .Attr("T: {complex64, complex128}")                                     \
      .Input("state: T")                                                      \
      .Input("gate: T")                                                       \
      .Input("controls: int32")                                               \
      .Attr("nqubits: int")                                                   \
      .Attr("target: int")                                                    \
      .Output("out: T")                                                       \
      .SetShapeFn([](::tensorflow::shape_inference::InferenceContext* c) {    \
        c->set_output(0, c->input(0));                                        \
        return Status::OK();                                                  \
      });

// Register one-qubit gate op without gate matrix
#define REGISTER_GATE1_NOMATRIX_OP(NAME)                                      \
  REGISTER_OP(NAME)                                                           \
      .Attr("T: {complex64, complex128}")                                     \
      .Input("state: T")                                                      \
      .Input("controls: int32")                                               \
      .Attr("nqubits: int")                                                   \
      .Attr("target: int")                                                    \
      .Output("out: T")                                                       \
      .SetShapeFn([](::tensorflow::shape_inference::InferenceContext* c) {    \
        c->set_output(0, c->input(0));                                        \
        return Status::OK();                                                  \
      });

// Register two-qubit gate op with gate matrix
#define REGISTER_GATE2_OP(NAME)                                               \
  REGISTER_OP(NAME)                                                           \
      .Attr("T: {complex64, complex128}")                                     \
      .Input("state: T")                                                      \
      .Input("gate: T")                                                       \
      .Input("controls: int32")                                               \
      .Attr("nqubits: int")                                                   \
      .Attr("target1: int")                                                   \
      .Attr("target2: int")                                                   \
      .Output("out: T")                                                       \
      .SetShapeFn([](::tensorflow::shape_inference::InferenceContext* c) {    \
        c->set_output(0, c->input(0));                                        \
        return Status::OK();                                                  \
      });

// Register two-qubit gate op without gate matrix
#define REGISTER_GATE2_NOMATRIX_OP(NAME)                                      \
  REGISTER_OP(NAME)                                                           \
      .Attr("T: {complex64, complex128}")                                     \
      .Input("state: T")                                                      \
      .Input("controls: int32")                                               \
      .Attr("nqubits: int")                                                   \
      .Attr("target1: int")                                                   \
      .Attr("target2: int")                                                   \
      .Output("out: T")                                                       \
      .SetShapeFn([](::tensorflow::shape_inference::InferenceContext* c) {    \
        c->set_output(0, c->input(0));                                        \
        return Status::OK();                                                  \
      });

REGISTER_GATE1_OP("ApplyGate")
REGISTER_GATE1_OP("ApplyZPow")
REGISTER_GATE1_NOMATRIX_OP("ApplyX")
REGISTER_GATE1_NOMATRIX_OP("ApplyY")
REGISTER_GATE1_NOMATRIX_OP("ApplyZ")

REGISTER_GATE2_OP("ApplyTwoQubitGate")
REGISTER_GATE2_OP("ApplyFsim")
REGISTER_GATE2_NOMATRIX_OP("ApplySwap")
