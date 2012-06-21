// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "echo.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace echo {

namespace {

const ::google::protobuf::Descriptor* EchoRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  EchoRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* EchoResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  EchoResponse_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_echo_2eproto() {
  protobuf_AddDesc_echo_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "echo.proto");
  GOOGLE_CHECK(file != NULL);
  EchoRequest_descriptor_ = file->message_type(0);
  static const int EchoRequest_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EchoRequest, message_),
  };
  EchoRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      EchoRequest_descriptor_,
      EchoRequest::default_instance_,
      EchoRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EchoRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EchoRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(EchoRequest));
  EchoResponse_descriptor_ = file->message_type(1);
  static const int EchoResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EchoResponse, response_),
  };
  EchoResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      EchoResponse_descriptor_,
      EchoResponse::default_instance_,
      EchoResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EchoResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(EchoResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(EchoResponse));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_echo_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    EchoRequest_descriptor_, &EchoRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    EchoResponse_descriptor_, &EchoResponse::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_echo_2eproto() {
  delete EchoRequest::default_instance_;
  delete EchoRequest_reflection_;
  delete EchoResponse::default_instance_;
  delete EchoResponse_reflection_;
}

void protobuf_AddDesc_echo_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\necho.proto\022\004echo\"\036\n\013EchoRequest\022\017\n\007mes"
    "sage\030\001 \002(\t\" \n\014EchoResponse\022\020\n\010response\030\001"
    " \002(\tB\002H\002", 88);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "echo.proto", &protobuf_RegisterTypes);
  EchoRequest::default_instance_ = new EchoRequest();
  EchoResponse::default_instance_ = new EchoResponse();
  EchoRequest::default_instance_->InitAsDefaultInstance();
  EchoResponse::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_echo_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_echo_2eproto {
  StaticDescriptorInitializer_echo_2eproto() {
    protobuf_AddDesc_echo_2eproto();
  }
} static_descriptor_initializer_echo_2eproto_;


// ===================================================================

#ifndef _MSC_VER
const int EchoRequest::kMessageFieldNumber;
#endif  // !_MSC_VER

EchoRequest::EchoRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void EchoRequest::InitAsDefaultInstance() {
}

EchoRequest::EchoRequest(const EchoRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void EchoRequest::SharedCtor() {
  _cached_size_ = 0;
  message_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

EchoRequest::~EchoRequest() {
  SharedDtor();
}

void EchoRequest::SharedDtor() {
  if (message_ != &::google::protobuf::internal::kEmptyString) {
    delete message_;
  }
  if (this != default_instance_) {
  }
}

void EchoRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* EchoRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return EchoRequest_descriptor_;
}

const EchoRequest& EchoRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_echo_2eproto();  return *default_instance_;
}

EchoRequest* EchoRequest::default_instance_ = NULL;

EchoRequest* EchoRequest::New() const {
  return new EchoRequest;
}

void EchoRequest::Swap(EchoRequest* other) {
  if (other != this) {
    GetReflection()->Swap(this, other);}
}

::google::protobuf::Metadata EchoRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = EchoRequest_descriptor_;
  metadata.reflection = EchoRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int EchoResponse::kResponseFieldNumber;
#endif  // !_MSC_VER

EchoResponse::EchoResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void EchoResponse::InitAsDefaultInstance() {
}

EchoResponse::EchoResponse(const EchoResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void EchoResponse::SharedCtor() {
  _cached_size_ = 0;
  response_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

EchoResponse::~EchoResponse() {
  SharedDtor();
}

void EchoResponse::SharedDtor() {
  if (response_ != &::google::protobuf::internal::kEmptyString) {
    delete response_;
  }
  if (this != default_instance_) {
  }
}

void EchoResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* EchoResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return EchoResponse_descriptor_;
}

const EchoResponse& EchoResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_echo_2eproto();  return *default_instance_;
}

EchoResponse* EchoResponse::default_instance_ = NULL;

EchoResponse* EchoResponse::New() const {
  return new EchoResponse;
}

void EchoResponse::Swap(EchoResponse* other) {
  if (other != this) {
    GetReflection()->Swap(this, other);}
}

::google::protobuf::Metadata EchoResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = EchoResponse_descriptor_;
  metadata.reflection = EchoResponse_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace echo

// @@protoc_insertion_point(global_scope)
