// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: msg_login.proto

#ifndef PROTOBUF_msg_5flogin_2eproto__INCLUDED
#define PROTOBUF_msg_5flogin_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2004001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
// @@protoc_insertion_point(includes)

namespace protocol {
namespace login {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_msg_5flogin_2eproto();
void protobuf_AssignDesc_msg_5flogin_2eproto();
void protobuf_ShutdownFile_msg_5flogin_2eproto();

class smsg_auth_challenge;
class cmsg_auth_session;

// ===================================================================

class smsg_auth_challenge : public ::google::protobuf::Message {
 public:
  smsg_auth_challenge();
  virtual ~smsg_auth_challenge();
  
  smsg_auth_challenge(const smsg_auth_challenge& from);
  
  inline smsg_auth_challenge& operator=(const smsg_auth_challenge& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const smsg_auth_challenge& default_instance();
  
  void Swap(smsg_auth_challenge* other);
  
  // implements Message ----------------------------------------------
  
  smsg_auth_challenge* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const smsg_auth_challenge& from);
  void MergeFrom(const smsg_auth_challenge& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required bytes svrSeed = 1;
  inline bool has_svrseed() const;
  inline void clear_svrseed();
  static const int kSvrSeedFieldNumber = 1;
  inline const ::std::string& svrseed() const;
  inline void set_svrseed(const ::std::string& value);
  inline void set_svrseed(const char* value);
  inline void set_svrseed(const void* value, size_t size);
  inline ::std::string* mutable_svrseed();
  inline ::std::string* release_svrseed();
  
  // optional uint32 svrTime = 2;
  inline bool has_svrtime() const;
  inline void clear_svrtime();
  static const int kSvrTimeFieldNumber = 2;
  inline ::google::protobuf::uint32 svrtime() const;
  inline void set_svrtime(::google::protobuf::uint32 value);
  
  // @@protoc_insertion_point(class_scope:protocol.login.smsg_auth_challenge)
 private:
  inline void set_has_svrseed();
  inline void clear_has_svrseed();
  inline void set_has_svrtime();
  inline void clear_has_svrtime();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::std::string* svrseed_;
  ::google::protobuf::uint32 svrtime_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];
  
  friend void  protobuf_AddDesc_msg_5flogin_2eproto();
  friend void protobuf_AssignDesc_msg_5flogin_2eproto();
  friend void protobuf_ShutdownFile_msg_5flogin_2eproto();
  
  void InitAsDefaultInstance();
  static smsg_auth_challenge* default_instance_;
};
// -------------------------------------------------------------------

class cmsg_auth_session : public ::google::protobuf::Message {
 public:
  cmsg_auth_session();
  virtual ~cmsg_auth_session();
  
  cmsg_auth_session(const cmsg_auth_session& from);
  
  inline cmsg_auth_session& operator=(const cmsg_auth_session& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const cmsg_auth_session& default_instance();
  
  void Swap(cmsg_auth_session* other);
  
  // implements Message ----------------------------------------------
  
  cmsg_auth_session* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const cmsg_auth_session& from);
  void MergeFrom(const cmsg_auth_session& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required uint32 clientBuid = 1;
  inline bool has_clientbuid() const;
  inline void clear_clientbuid();
  static const int kClientBuidFieldNumber = 1;
  inline ::google::protobuf::uint32 clientbuid() const;
  inline void set_clientbuid(::google::protobuf::uint32 value);
  
  // required bytes clientSeed = 2;
  inline bool has_clientseed() const;
  inline void clear_clientseed();
  static const int kClientSeedFieldNumber = 2;
  inline const ::std::string& clientseed() const;
  inline void set_clientseed(const ::std::string& value);
  inline void set_clientseed(const char* value);
  inline void set_clientseed(const void* value, size_t size);
  inline ::std::string* mutable_clientseed();
  inline ::std::string* release_clientseed();
  
  // optional uint32 clientTime = 3;
  inline bool has_clienttime() const;
  inline void clear_clienttime();
  static const int kClientTimeFieldNumber = 3;
  inline ::google::protobuf::uint32 clienttime() const;
  inline void set_clienttime(::google::protobuf::uint32 value);
  
  // required bytes account = 4;
  inline bool has_account() const;
  inline void clear_account();
  static const int kAccountFieldNumber = 4;
  inline const ::std::string& account() const;
  inline void set_account(const ::std::string& value);
  inline void set_account(const char* value);
  inline void set_account(const void* value, size_t size);
  inline ::std::string* mutable_account();
  inline ::std::string* release_account();
  
  // @@protoc_insertion_point(class_scope:protocol.login.cmsg_auth_session)
 private:
  inline void set_has_clientbuid();
  inline void clear_has_clientbuid();
  inline void set_has_clientseed();
  inline void clear_has_clientseed();
  inline void set_has_clienttime();
  inline void clear_has_clienttime();
  inline void set_has_account();
  inline void clear_has_account();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::std::string* clientseed_;
  ::google::protobuf::uint32 clientbuid_;
  ::google::protobuf::uint32 clienttime_;
  ::std::string* account_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];
  
  friend void  protobuf_AddDesc_msg_5flogin_2eproto();
  friend void protobuf_AssignDesc_msg_5flogin_2eproto();
  friend void protobuf_ShutdownFile_msg_5flogin_2eproto();
  
  void InitAsDefaultInstance();
  static cmsg_auth_session* default_instance_;
};
// ===================================================================


// ===================================================================

// smsg_auth_challenge

// required bytes svrSeed = 1;
inline bool smsg_auth_challenge::has_svrseed() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void smsg_auth_challenge::set_has_svrseed() {
  _has_bits_[0] |= 0x00000001u;
}
inline void smsg_auth_challenge::clear_has_svrseed() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void smsg_auth_challenge::clear_svrseed() {
  if (svrseed_ != &::google::protobuf::internal::kEmptyString) {
    svrseed_->clear();
  }
  clear_has_svrseed();
}
inline const ::std::string& smsg_auth_challenge::svrseed() const {
  return *svrseed_;
}
inline void smsg_auth_challenge::set_svrseed(const ::std::string& value) {
  set_has_svrseed();
  if (svrseed_ == &::google::protobuf::internal::kEmptyString) {
    svrseed_ = new ::std::string;
  }
  svrseed_->assign(value);
}
inline void smsg_auth_challenge::set_svrseed(const char* value) {
  set_has_svrseed();
  if (svrseed_ == &::google::protobuf::internal::kEmptyString) {
    svrseed_ = new ::std::string;
  }
  svrseed_->assign(value);
}
inline void smsg_auth_challenge::set_svrseed(const void* value, size_t size) {
  set_has_svrseed();
  if (svrseed_ == &::google::protobuf::internal::kEmptyString) {
    svrseed_ = new ::std::string;
  }
  svrseed_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* smsg_auth_challenge::mutable_svrseed() {
  set_has_svrseed();
  if (svrseed_ == &::google::protobuf::internal::kEmptyString) {
    svrseed_ = new ::std::string;
  }
  return svrseed_;
}
inline ::std::string* smsg_auth_challenge::release_svrseed() {
  clear_has_svrseed();
  if (svrseed_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = svrseed_;
    svrseed_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional uint32 svrTime = 2;
inline bool smsg_auth_challenge::has_svrtime() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void smsg_auth_challenge::set_has_svrtime() {
  _has_bits_[0] |= 0x00000002u;
}
inline void smsg_auth_challenge::clear_has_svrtime() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void smsg_auth_challenge::clear_svrtime() {
  svrtime_ = 0u;
  clear_has_svrtime();
}
inline ::google::protobuf::uint32 smsg_auth_challenge::svrtime() const {
  return svrtime_;
}
inline void smsg_auth_challenge::set_svrtime(::google::protobuf::uint32 value) {
  set_has_svrtime();
  svrtime_ = value;
}

// -------------------------------------------------------------------

// cmsg_auth_session

// required uint32 clientBuid = 1;
inline bool cmsg_auth_session::has_clientbuid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void cmsg_auth_session::set_has_clientbuid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void cmsg_auth_session::clear_has_clientbuid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void cmsg_auth_session::clear_clientbuid() {
  clientbuid_ = 0u;
  clear_has_clientbuid();
}
inline ::google::protobuf::uint32 cmsg_auth_session::clientbuid() const {
  return clientbuid_;
}
inline void cmsg_auth_session::set_clientbuid(::google::protobuf::uint32 value) {
  set_has_clientbuid();
  clientbuid_ = value;
}

// required bytes clientSeed = 2;
inline bool cmsg_auth_session::has_clientseed() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void cmsg_auth_session::set_has_clientseed() {
  _has_bits_[0] |= 0x00000002u;
}
inline void cmsg_auth_session::clear_has_clientseed() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void cmsg_auth_session::clear_clientseed() {
  if (clientseed_ != &::google::protobuf::internal::kEmptyString) {
    clientseed_->clear();
  }
  clear_has_clientseed();
}
inline const ::std::string& cmsg_auth_session::clientseed() const {
  return *clientseed_;
}
inline void cmsg_auth_session::set_clientseed(const ::std::string& value) {
  set_has_clientseed();
  if (clientseed_ == &::google::protobuf::internal::kEmptyString) {
    clientseed_ = new ::std::string;
  }
  clientseed_->assign(value);
}
inline void cmsg_auth_session::set_clientseed(const char* value) {
  set_has_clientseed();
  if (clientseed_ == &::google::protobuf::internal::kEmptyString) {
    clientseed_ = new ::std::string;
  }
  clientseed_->assign(value);
}
inline void cmsg_auth_session::set_clientseed(const void* value, size_t size) {
  set_has_clientseed();
  if (clientseed_ == &::google::protobuf::internal::kEmptyString) {
    clientseed_ = new ::std::string;
  }
  clientseed_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* cmsg_auth_session::mutable_clientseed() {
  set_has_clientseed();
  if (clientseed_ == &::google::protobuf::internal::kEmptyString) {
    clientseed_ = new ::std::string;
  }
  return clientseed_;
}
inline ::std::string* cmsg_auth_session::release_clientseed() {
  clear_has_clientseed();
  if (clientseed_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = clientseed_;
    clientseed_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional uint32 clientTime = 3;
inline bool cmsg_auth_session::has_clienttime() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void cmsg_auth_session::set_has_clienttime() {
  _has_bits_[0] |= 0x00000004u;
}
inline void cmsg_auth_session::clear_has_clienttime() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void cmsg_auth_session::clear_clienttime() {
  clienttime_ = 0u;
  clear_has_clienttime();
}
inline ::google::protobuf::uint32 cmsg_auth_session::clienttime() const {
  return clienttime_;
}
inline void cmsg_auth_session::set_clienttime(::google::protobuf::uint32 value) {
  set_has_clienttime();
  clienttime_ = value;
}

// required bytes account = 4;
inline bool cmsg_auth_session::has_account() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void cmsg_auth_session::set_has_account() {
  _has_bits_[0] |= 0x00000008u;
}
inline void cmsg_auth_session::clear_has_account() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void cmsg_auth_session::clear_account() {
  if (account_ != &::google::protobuf::internal::kEmptyString) {
    account_->clear();
  }
  clear_has_account();
}
inline const ::std::string& cmsg_auth_session::account() const {
  return *account_;
}
inline void cmsg_auth_session::set_account(const ::std::string& value) {
  set_has_account();
  if (account_ == &::google::protobuf::internal::kEmptyString) {
    account_ = new ::std::string;
  }
  account_->assign(value);
}
inline void cmsg_auth_session::set_account(const char* value) {
  set_has_account();
  if (account_ == &::google::protobuf::internal::kEmptyString) {
    account_ = new ::std::string;
  }
  account_->assign(value);
}
inline void cmsg_auth_session::set_account(const void* value, size_t size) {
  set_has_account();
  if (account_ == &::google::protobuf::internal::kEmptyString) {
    account_ = new ::std::string;
  }
  account_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* cmsg_auth_session::mutable_account() {
  set_has_account();
  if (account_ == &::google::protobuf::internal::kEmptyString) {
    account_ = new ::std::string;
  }
  return account_;
}
inline ::std::string* cmsg_auth_session::release_account() {
  clear_has_account();
  if (account_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = account_;
    account_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace login
}  // namespace protocol

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_msg_5flogin_2eproto__INCLUDED
